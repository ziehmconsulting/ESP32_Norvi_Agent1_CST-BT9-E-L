#include "global_variables.hpp"
#include "registerOnNetwork.hpp"
#include "monitorSerial.hpp"
#include "rebootModem.hpp"

/*************************************************HANDLE SAVE FROM WEB FUNCTION***************************************************/
// Function to register on the network with APN
void registerOnNetwork(const String &apn)
{
  int failedAttempts = 0;
  // Send CFUN command
  Serial1.println("AT+CFUN=0");
  Serial.println("AT+CFUN=0");

  while (failedAttempts < 5)
  {
    // Send CFUN command
    Serial1.println("AT+CFUN=1");
    Serial.println("AT+CFUN=1");
    previousMillis = millis();
    while (millis() - previousMillis < 5000)
    {
      monitorSerial();
      if (Serial1.find("OK"))
        break;
    }

    // Send CEREG command
    Serial1.println("AT+CEREG=1");
    Serial.println("AT+CEREG=1");
    previousMillis = millis();
    while (millis() - previousMillis < 5000)
    {
      monitorSerial();
      if (Serial1.find("OK"))
        break;
    }

    // Send CGDCONT command

    String cgdcontCmd = "AT+CGDCONT=1,\"IP\",\"" + apn + "\"";
    Serial1.println(cgdcontCmd);
    Serial.println(cgdcontCmd);

    previousMillis = millis();
    while (millis() - previousMillis < 5000)
    {
      monitorSerial();
      if (Serial1.find("OK"))
        break;
    }

    // Send CGATT command
    Serial1.println("AT+CGATT=1");
    Serial.println("AT+CGATT=1");
    previousMillis = millis();
    while (millis() - previousMillis < 5000)
    {
      monitorSerial();
      if (Serial1.find("OK"))
        break;
    }

    // Wait for registration with the network
    previousMillis = millis();
    bool registrationSuccess = false;
    while (millis() - previousMillis < 20000)
    {
      monitorSerial();
      if (Serial1.find("+CEREG:2"))
      {
        registrationSuccess = true;
        break;
      }
    }

    // Check if registration was successful
    if (registrationSuccess)
    {
      // Wait for final registration status
      previousMillis = millis();
      while (millis() - previousMillis < 20000)
      {
        monitorSerial();
        //+CEREG:1,5
        if (Serial1.find("+CEREG:5"))
        {
          Serial.println("Modem configured and registered on the network.");
          return; // Successful registration, exit function
        }
      }
    }

    // If registration failed, increment the failedAttempts counter
    failedAttempts++;

    // If we've reached 5 failed attempts, reboot the modem and reset the counter
    if (failedAttempts == 5)
    {
      Serial.println("Failed to register on the network after 5 attempts. Rebooting modem...");
      rebootModem();
      failedAttempts = 0; // Reset the counter
    }

    Serial.println("Failed to register on the network. Retrying...");
  }
}
