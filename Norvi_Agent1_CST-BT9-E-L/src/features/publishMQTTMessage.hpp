#include <ArduinoJson.h>
#include <iostream> // std::cout
#include <string>   // std::string, std::stoi

void publishMQTTMessage(const JsonDocument &jsonDoc, String topic);
