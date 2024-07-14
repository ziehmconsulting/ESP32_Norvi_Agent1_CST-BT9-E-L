#include "global_variables.hpp"
#include <Arduino.h>
/*
int NetworkTime::networkhour;
int NetworkTime::networkminutes;
int NetworkTime::networksenconds;

int NetworkDate::networkyear;
int NetworkDate::networkmonth;
int NetworkDate::networkday;
*/

uint8_t NETWORK_HOUR = 42;
uint8_t NETWORK_MINUTE = 42;
uint8_t NETWORK_SECOND = 42;
uint8_t NETWORK_YEAR = 42;
uint8_t NETWORK_MONTH = 42;
uint8_t NETWORK_DAY = 42;
bool NETWORK_TIME_GLOBAL = false;

/**********************************************************************************************************************************/
// Define your firmware version and serial number here
String firmwareVersion = "1.23";
String serialNumber = "SN-12345";
String mqttMessage = "";
String payload = "";
bool Ignore = false;

/**********************************************************************************************************************************/
// Get the current time
unsigned long currentMillis = 0;
// Define a variable to store the last time the MQTT connection was checked
unsigned long lastMQTTCheckTime = 0;
unsigned long previousMillis = 0;
// Define a variable to store the last time Sensor data was sent
unsigned long lastSensorValSentTime = 0;

/**********************************************************************************************************************************/
// Define your sensor variables here
int energy = 65451;
float current = 12.5;

/**********************************************************************************************************************************/
// Define MQTT topics
#define MQTT_TOPIC_1 "v1/devices/me/rpc/request/1"
#define MQTT_TOPIC_2 "v1/devices/me/rpc/request/2"
#define MQTT_TOPIC_5 "v1/devices/me/rpc/request/3"
#define MQTT_TOPIC_3 "v1/devices/me/attributes"
#define MQTT_TOPIC_4 "v1/devices/me/telemetry"

/***********************************************SCHEDULER PAGE VARIABLES**********************************************************/
// Define starting addresses for each text zone
#define ADDR_UI_NETWORK 0
#define ADDR_UI_SIGNAL 7
#define ADDR_UI_STATUS_MQTT 13
#define ADDR_NETWORK_APN 23
#define ADDR_MQTT_SERVER 33
#define ADDR_MQTT_USER 43
#define ADDR_MQTT_PW 50
#define ADDR_MQTT_DN 60
#define ADDR_MQTT_ID 72
#define ADDR_MQTT_SD 86

/**********************************************************************************************************************************/
// Modem Serial Pins
#define RX_PIN 4       // ESP32 RX pin
#define TX_PIN 2       // ESP32 TX pin
#define BAUD_RATE 9600 // Baud rate for ESP32 UART communication
#define GSM_RESET 19
#define GSM_ENABLE 18

/**********************************************************************************************************************************/
// Define a constant for the interval (in milliseconds)
#define MQTT_CHECK_INTERVAL 10000  // 10 seconds

