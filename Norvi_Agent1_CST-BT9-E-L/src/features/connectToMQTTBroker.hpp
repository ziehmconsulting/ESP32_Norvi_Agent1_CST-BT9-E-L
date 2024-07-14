#include <string>
#include <Arduino.h>
#include "global_variables.hpp"
#include "credentials.hpp"

void connectToMQTTBroker(const String &server, const String &user, int port, const String &password, const String &clientId);

