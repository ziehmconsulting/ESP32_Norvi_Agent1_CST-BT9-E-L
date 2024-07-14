#include <ArduinoJson.h>
#include "global_variables.hpp"
#include "publishMQTTMessage.hpp"
#include "monitorSerial.hpp"

/************************************************HANDLE SAVE FROM WEB FUNCTION**************************************************/
// Function to publish MQTT message with ArduinoJson payload
void publishMQTTMessage(const JsonDocument &jsonDoc, String topic)
{
  // Serialize the JSON document to a string
  String payload;
  serializeJson(jsonDoc, payload);
  // Calculate payload length
  int payloadLength = payload.length();
  // Prepare the AT command to publish the message with payload length
  String command = "AT+QMTPUB=0,0,0,0,\"" + topic + "\"," + String(payloadLength);
  Serial1.println(command);
  Serial.print(command);
  // Wait for the modem to respond with '>'
  unsigned long previousMillis = millis();
  while (1)
  {
    String response = Serial1.readStringUntil('\n');
    if (response.startsWith(">"))
    {
      monitorSerial();
      break;
    }
    if (millis() - previousMillis > 6000)
    {
      monitorSerial();
      Serial.println("Failed to receive prompt for message input.");
      return;
    }
  }
  // Send the payload
  Serial1.println(payload);
  Serial.println(payload);
  previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
    if (Serial1.find("OK"))
      break;
  };
  previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
    if (Serial1.find("+QMTPUB: 0,0,0"))
      break;
  };
}
