#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "global_variables.hpp"
#include "credentials.hpp"
#include "connectToMQTTBroker.hpp"
#include "monitorSerial.hpp"

/**************************************************HANDLE SAVE FROM WEB FUNCTION**************************************************/
// Function to connect to MQTT Broker
void connectToMQTTBroker(const String &server, const String &user, int port, const String &password, const String &clientId)
{
// Send QMTOPEN command
OpenMQ:;
  String qmtopenCmd = "AT+QMTOPEN=0,\"" + server + "\"," + String(port);
  Serial1.println(qmtopenCmd);
  Serial.println(qmtopenCmd);
  previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
    if (Serial1.find("OK"))
      break;
    if (Serial1.find("ERROR"))
    {
      Serial.println("Retry MQTT OPEN");
      delay(3000);
      goto OpenMQ;
    };
  }
  previousMillis = millis();
  while (millis() - previousMillis < 15000)
  {
    monitorSerial();
    if (Serial1.find("+QMTOPEN"))
      break;
  }
// Send QMTCONN command
ConnMQ:;
  String qmtconnCmd = "AT+QMTCONN=0,\"" + clientId + "\",\"" + user + "\",\"" + password + "\"";
  Serial1.println(qmtconnCmd);
  Serial.println(qmtconnCmd);
  previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
    if (Serial1.find("OK"))
      break;
    if (Serial1.find("ERROR"))
    {
      Serial.println("Retry MQTT CONN");
      delay(3000);
      goto ConnMQ;
    };
  }
  previousMillis = millis();
  while (millis() - previousMillis < 15000)
  {
    monitorSerial();
    if (Serial1.find("+QMTCONN"))
      break;
  }
  Serial.println("Successfully connected to MQTT broker.");
}
