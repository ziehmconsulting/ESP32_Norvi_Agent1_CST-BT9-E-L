#include "global_variables.hpp"
#include "publishMQTTData.hpp"
#include "publishSensorValues.hpp"
#include "ACS712_Features.hpp"
#ifndef SENSOR_SEND_INTERVAL
#define SENSOR_SEND_INTERVAL 20000


//Grap all data to send it with  function publishMQTTMessage
void publishMQTTData(){
    // Check if it's time to send sensor data again
  if (millis() - lastSensorValSentTime >= SENSOR_SEND_INTERVAL)
  {
    // Update the last sensor value sent time
    lastSensorValSentTime = millis();
    current = getCurrent();
    energy = NETWORK_SECOND;
    publishSensorValues(energy, current); // Assuming ENERGY_VALUE and CURRENT_VALUE are variables holding the sensor values
  }
}

#endif
