#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

#include <Arduino.h>

/**********************************************************************************************************************************/
// Define MQTT-Topics
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
#define MQTT_CHECK_INTERVAL 10000 // 10 seconds

struct NetworkTime
{
    uint8_t networkhour;
    uint8_t networkminute;
    uint8_t networkseconds;
};

struct NetworkDate
{
    uint8_t networkyear;
    uint8_t networkmonth;
    uint8_t networkday;
};

// default 42 see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_HOUR;
// default 42 see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_MINUTE;
// default 42 to see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_SECOND;
// default 42 to see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_YEAR;
// default 42 to see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_MONTH;
// default 42 to see the first change. works for hour,month,day als logical indicator
extern uint8_t NETWORK_DAY;

extern bool NETWORK_TIME_GLOBAL;

/**********************************************************************************************************************************/
extern String firmwareVersion;
extern String serialNumber;
extern String mqttMessage;
extern String payload;
extern bool Ignore;

/**********************************************************************************************************************************/
// Get the current time
extern unsigned long currentMillis;
// Define a variable to store the last time the MQTT connection was checked
extern unsigned long lastMQTTCheckTime;
extern unsigned long previousMillis;
// Define a variable to store the last time Sensor data was sent
extern unsigned long lastSensorValSentTime;

/**********************************************************************************************************************************/
// Define your sensor variables here
extern int energy;
extern float current;

#endif
