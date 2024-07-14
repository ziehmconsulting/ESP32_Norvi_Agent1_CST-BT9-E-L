#include <ArduinoJson.h>
#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "handleMQTTTopic1.hpp"
#include "publishMQTTMessage.hpp"
#include "global_variables.hpp"

/**************************************************HANDLE SAVE FROM WEB FUNCTION*************************************************/
// Function to handle messages received on MQTT_TOPIC_1
void handleMQTTTopic1(const String &payload)
{
  // Parse the JSON payload
  DynamicJsonDocument doc(512); // Adjust the capacity as needed
  DeserializationError error = deserializeJson(doc, payload);
  // Check for parsing errors
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  // Check if the JSON object contains the "method" field
  if (doc.containsKey("method"))
  {
    // Get the value of the "method" field
    String method = doc["method"];
    // Check if the method is "reboot"
    if (method == "reboot")
    {
      // Perform reboot operation
      // Example: Code to reboot the device
      Serial.println("-----------------------------------------------------------------------------------------------------------");
      Serial.println("");
      Serial.println("");
      Serial.print("Rebooting device");
      // Publish the response payload to the MQTT server
      // Create a JSON document to hold the message
      DynamicJsonDocument jsonDoc(512); // Adjust the capacity as needed
      jsonDoc["message"] = "Rebooting device";
      // Publish the JSON document to MQTT topic MQTT_TOPIC_1
      publishMQTTMessage(jsonDoc, MQTT_TOPIC_1);
      Ignore = true;
      delay(1000);
      ESP.restart(); // Perform a device reboot
      // rebootModem();
    }
    else
    {
      // If the method is not recognized, you can log an error or perform other actions as needed
      Serial.println("Unknown method in MQTT_TOPIC_1 payload");
    }
  }
  else
  {
    Serial.println("No 'method' field found in MQTT_TOPIC_1 payload");
  }
}
