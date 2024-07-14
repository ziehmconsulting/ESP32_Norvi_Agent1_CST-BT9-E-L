#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "subscribeToMQTTTopic.hpp"
#include "global_variables.hpp"
#include "monitorSerial.hpp"

/*************************************************HANDLE SAVE FROM WEB FUNCTION**************************************************/
// Function to subscribe to MQTT topics one at a time
void subscribeToMQTTTopic(const String &topic)
{
  // Send QMTSUB command
  String qmtsubCmd = "AT+QMTSUB=0,1,\"" + topic + "\",2";
  Serial1.println(qmtsubCmd);
  Serial.println(qmtsubCmd);
  previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
  }
  Serial.println("Subscribed to " + topic + " successfully.");
}
