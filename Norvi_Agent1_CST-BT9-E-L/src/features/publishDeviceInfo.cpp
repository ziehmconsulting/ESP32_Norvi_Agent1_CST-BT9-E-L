#include <ArduinoJson.h>
#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "global_variables.hpp"
#include "publishMQTTMessage.hpp"
#include "publishDeviceInfo.hpp"

/*************************************************HANDLE SAVE FROM WEB FUNCTION***************************************************/
// Function to publish device information via MQTT with specified firmware version and serial number
void publishDeviceInfo(const String &firmwareVersion, const String &serialNumber)
{
  // Create a JSON document to hold device information
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument jsonDoc(capacity);
  // Add device information to the JSON document
  jsonDoc["firmwareVersion"] = firmwareVersion;
  jsonDoc["serialNumber"] = serialNumber;
  // Publish the JSON document to MQTT topic MQTT_TOPIC_4
  publishMQTTMessage(jsonDoc, MQTT_TOPIC_4);
}
