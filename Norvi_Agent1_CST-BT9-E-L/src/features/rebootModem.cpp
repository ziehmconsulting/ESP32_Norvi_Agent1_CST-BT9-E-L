#include "global_variables.hpp"
#include "rebootModem.hpp"
#include "monitorSerial.hpp"



/***************************************************HANDLE SAVE FROM WEB FUNCTION************************************************/
// Reboot the Modem
void rebootModem()
{
  // Send AT command
  for (int i = 0; i < 3; i++)
  {
    Serial1.println("AT");
    unsigned long previousMillis = millis();
    while (millis() - previousMillis < 1300)
    {
      monitorSerial();
      String command = Serial1.readStringUntil('\n');
      if (command.startsWith("OK"))
        break;
    }
  }

  // Send reboot command
  Serial1.println("AT+NRB");
  unsigned long previousMillis = millis();
  while (millis() - previousMillis < 10000)
  {
    monitorSerial();
  }
}
