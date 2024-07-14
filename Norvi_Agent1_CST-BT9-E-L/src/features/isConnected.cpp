#include <Arduino.h>
#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "isConnected.hpp"
#include "global_variables.hpp"
#include "monitorSerial.hpp"


/*******************************************************HANDLE SAVE FROM WEB FUNCTION*********************************************/
// function to check if the devce is still connected
bool isConnected()
{
  // Send the AT command to check MQTT connection status
  String command = "AT+QMTCONN?";
  Serial1.println(command);
  Serial.println(command);

  // Wait for response
  previousMillis = millis();
  while (millis() - previousMillis < 8000)
  {
    monitorSerial();
    if (Serial1.find("+QMTCONN: 0,3"))
    {
      Serial.println("--------------------------------------------------------------------------------------------------------------");
      Serial.println("MQTT Status: Connected!");
      Serial.println("--------------------------------------------------------------------------------------------------------------");
      return true;
    }
    else if (Serial1.find("+QMTCONN: 0,2"))
    {
      Serial.println("--------------------------------------------------------------------------------------------------------------");
      Serial.println("MQTT Status: Being Connected");
      Serial.println("--------------------------------------------------------------------------------------------------------------");
      return true;
    }
    else if (Serial1.find("+QMTCONN: 0,1"))
    {
      Serial.println("-----------------------------------------------------------------------------------------------------------");
      Serial.println("MQTT Status: Initializing");
      Serial.println("-----------------------------------------------------------------------------------------------------------");
      return true;
    }
    else if (Serial1.find("+QMTCONN: 0,4"))
    {
      Serial.println("-----------------------------------------------------------------------------------------------------------");
      Serial.println("MQTT Status: Disconnected");
      Serial.println("-----------------------------------------------------------------------------------------------------------");
      return false;
    }
  }
  // If no response received within timeout, consider it disconnected
  Serial.println("--------------------------------------------------------------------------------------------------------------");
  Serial.println("MQTT Status: Disconnected (Timeout)");
  Serial.println("--------------------------------------------------------------------------------------------------------------");
  return false;
}
