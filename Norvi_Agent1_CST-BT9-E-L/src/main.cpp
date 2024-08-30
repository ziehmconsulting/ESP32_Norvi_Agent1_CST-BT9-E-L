/*H**********************************************************************
 * FILENAME :        main.cpp          DESIGN REF: FMCM00
 * Version:          1.0.0
 * DESCRIPTION :
 *       Connection test for the Norvi AGENT1 CST-BT9-E-L based ESP32 with current messurment.
 *
 * PUBLIC FUNCTIONS :
 *       see #include section
 *
 *
 * NOTES :
 *       The naming of the prefixes of the variables and functions results from the variable type or
 *       the variable type of the return value.
 *       "c" stands for "char", an "s" for "short",
 *       "v" for "void", a "u" for "unsigned" and
 *       "x" for all non-standard types
 *
 *       Copyright Tjark Ziehm 2024
 *
 * AUTHOR :    Tjark Ziehm  & Bhanuka Gamachchige
 * START DATE :    01 Juni 2024
 *
 * CHANGES :
 *
 * Convention:   <major>.<minor>.<patch>
 * REF NO  VERSION DATE        WHO     DETAIL
 * F21/33  A.03.04 20April2024 TZ      add Header
 *
 *H*/

/********************************************************************************************************************NETWORK PAGE VARIABLES****************************************/
#include <ArduinoJson.h>
#include <iostream> // std::cout
#include <string>   // std::string, std::stoi

#include "features/global_variables.hpp"
#include "features/ACS712_Features.hpp"
#include "features/updateRTCbyNetworkTime.hpp"
#include "features/monitorSerial.hpp"
#include "features/publishSensorValues.hpp"
#include "features/publishMQTTData.hpp"
#include "features/publishMQTTMessage.hpp"
#include "features/rebootModem.hpp"
#include "features/establishConnection.hpp"
#include "features/credentials.hpp"
#include "features/registerOnNetwork.hpp"
#include "features/connectToMQTTBroker.hpp"
#include "features/publishDeviceInfo.hpp"
#include "features/handleMQTTTopic1.hpp"
#include "features/transmitPayload.hpp"

/*******************************************************set Serials********************************************************************/
void setSerials()
{
  Serial.begin(BAUD_RATE);
  Serial1.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
}

/*******************************************************SETUP********************************************************************/
void setup()
{
  Serial.println("******************configure Serials Ports!******************");
  setSerials();
  pinMode(GSM_RESET, OUTPUT);
  digitalWrite(GSM_RESET, HIGH);
  pinMode(GSM_ENABLE, OUTPUT);
  digitalWrite(GSM_ENABLE, HIGH); /* Turn ON output*/
  Serial.println("Serial configured");

  Serial.println("******************activate current sensor!******************");
  // setCurrentSensor();
  delay(500);

  Serial.println("******************Starting Setup!******************");
  // Reboot Modem
  rebootModem();
  delay(1000);

  Serial.println("------------------Starting the Registration to Network with APN------------------");
  // Register on the network with APN
  registerOnNetwork(data.NETWORK_APN);

  // Connect to MQTT Broker
  Serial.println("------------------Connecting to MQTT Broker------------------");
  connectToMQTTBroker(data.MQTT_SERVER, data.MQTT_USER, data.MQTT_PORT, data.MQTT_PW, data.MQTT_ID);

  // Subscribe to MQTT topics
  Serial.println("------------------Subscribing to defined Topics------------------");
  // subscribeToMQTTTopic(MQTT_TOPIC_1);
  // subscribeToMQTTTopic(MQTT_TOPIC_2);
  // subscribeToMQTTTopic(MQTT_TOPIC_3);

  // Call the function to publish device info at boot
  Serial.println("------------------Publishing Device Info------------------");
  publishDeviceInfo(firmwareVersion, serialNumber);

  // Call the function to publish sensor values every 60 seconds
  Serial.println("------------------Publishing Sensor Values------------------");
  publishSensorValues(energy, current);

  Serial.println("******************Starting the RTC-Module!******************");
  Serial1.print("ATE0"); // Disable echo !!! Important to avoide overhead of regular calcluation
  //! TODO: add feedback "if ok" function
  delay(500);
  Serial1.print("ATE0");
  // delay(3000);
  setupRTC();
  delay(1000);
  Serial1.print("ATE1");

  Serial.println("******************Setup Successfully executed!******************");
  Serial.println("****************************************************************");
}
/*******************************************************LOOP********************************************************************/
void loop()
{
  /*Serial1.print("ATE0");
  delay(1000);
  updateRTCbyNetworkTime();
  delay(500);
  Serial1.print("ATE1");
  delay(1000);
  */

  // get the data from esp to transmitt via MQTT Network
  publishMQTTData();
  // Network connection
  establishConnection();
  // Monitor Serial1 transactions
  monitorSerial();
  transmitPayload();
}
