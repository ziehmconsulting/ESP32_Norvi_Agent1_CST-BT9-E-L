#include "global_variables.hpp"
#include "publishSensorValues.hpp"
#include "publishMQTTMessage.hpp"
#include <ArduinoJson.h>




/*************************************************HANDLE SAVE FROM WEB FUNCTION**************************************************/
// Function to publish sensor values via MQTT with specified energy and current values
void publishSensorValues(int energy, float current)
{
  // Create a JSON document to hold sensor values
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument jsonDoc(capacity);
  // Add sensor values to the JSON document
  jsonDoc["energy"] = energy;
  jsonDoc["current"] = current;
  // Publish the JSON document to MQTT topic MQTT_TOPIC_4
  publishMQTTMessage(jsonDoc, MQTT_TOPIC_4);
}
