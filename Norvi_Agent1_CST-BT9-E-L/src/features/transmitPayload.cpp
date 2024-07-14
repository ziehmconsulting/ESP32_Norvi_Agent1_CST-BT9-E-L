#include <iostream> // std::cout
#include <string>   // std::string, std::stoi
#include "transmitPayload.hpp"
#include "global_variables.hpp"
#include "handleMQTTTopic1.hpp"


/*******************************************************set Serials********************************************************************/
void transmitPayload(){

  if (Ignore)
  {
    // reset to ignore the sent loop
    payload = "";
    mqttMessage = "";
  };
  // Check if the received message starts with "+QMTRECV"
  if (mqttMessage.startsWith("+QMTRECV"))
  {
    if (Ignore)
    {
      payload = String("No payload!");
      mqttMessage = String("No message!");
    };
    // Print the received message
    Serial.println("-----------------------------------------------------------------------------------------------------------");
    Serial.print("Received Message:");
    Serial.print(mqttMessage);
    Serial.println("");
    Serial.println("----------------------------------------------------------------------------------------------------------");

    // Extract the topic name
    int topicStart = 15; // Find the index of escaped double quotes and add 2 to skip them
    int topicEnd = mqttMessage.indexOf("{", topicStart) - 2;
    String topic = mqttMessage.substring(topicStart, topicEnd);
    Serial.println("-----------------------------------------------------------------------------------------------------------");
    Serial.print("Topic:");
    Serial.print(topic);
    Serial.println("");
    // Extract the payload
    int payloadStart = mqttMessage.indexOf("{", topicEnd);
    payload = mqttMessage.substring(payloadStart);
    Serial.print("Payload:");
    Serial.print(payload);
    Serial.println("");
    Serial.println("-----------------------------------------------------------------------------------------------------------");

    // Check if the received topic matches MQTT_TOPIC_1 or MQTT_TOPIC_2
    if (topic == MQTT_TOPIC_1)
    {
      // Call the function to handle the message for the corresponding topic
      if (topic == MQTT_TOPIC_1)
      {
        Serial.println("MQTT_TOPIC_1");
        handleMQTTTopic1(payload);
        payload = String("No payload!");
        mqttMessage = String("No message!");
      }
    }
  };
  if (Ignore)
  {
    // reset to ignore the sent loop
    payload = "";
    mqttMessage = "";
    Ignore = false;
  };
}
