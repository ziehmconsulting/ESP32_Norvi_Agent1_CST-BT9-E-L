#include "monitorSerial.hpp"
#include "features/global_variables.hpp"

/**************************************************HANDLE SAVE FROM WEB FUNCTION**************************************************/
// monitor serial
void monitorSerial()
{
  while (Serial1.available())
  {
    if (Ignore)
    {
      // reset to ignore the sent loop
      payload = String("No payload!");
      mqttMessage = String("No message!");
    }
    else
    {
      mqttMessage = Serial1.readStringUntil('\n');
    };
    Serial.println(mqttMessage);
  }
}
