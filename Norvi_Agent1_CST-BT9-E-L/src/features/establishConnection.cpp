#include "global_variables.hpp"
#include "credentials.hpp"
#include "establishConnection.hpp"
#include "isConnected.hpp"
#include "registerOnNetwork.hpp"
#include "connectToMQTTBroker.hpp"
#include "subscribeToMQTTTopic.hpp"

void establishConnection()
{
  // Check if it's time to check MQTT connection status
  if (millis() - lastMQTTCheckTime >= MQTT_CHECK_INTERVAL)
  {
    lastMQTTCheckTime = millis();
    if (!isConnected())
    {
      // If not connected, register on the network and connect to MQTT broker
      registerOnNetwork(data.NETWORK_APN);
      connectToMQTTBroker(data.MQTT_SERVER, data.MQTT_USER, data.MQTT_PORT, data.MQTT_PW, data.MQTT_ID);
      subscribeToMQTTTopic(MQTT_TOPIC_1);
      subscribeToMQTTTopic(MQTT_TOPIC_2);
    }
  }
}
