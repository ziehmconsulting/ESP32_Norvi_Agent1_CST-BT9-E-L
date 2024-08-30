
#include <Arduino.h>
/***********************************************NETWORK PAGE VARIABLES************************************************************/
#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP

struct NETWORKDATA
{

    String NETWORK_APN = "wsim";
    // String MQTT_SERVER = "mqtt.thingsboard.cloud";
    //String MQTT_SERVER = "162.55.51.222";
    String MQTT_SERVER = "mqtt.thingsboard-server.de";
    String MQTT_PW = "norvi";
    String MQTT_ID = "norvi";
    String MQTT_USER = "norvi";
    int MQTT_PORT = 1883;
};

inline NETWORKDATA data;

#endif
