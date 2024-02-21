/*
Board: Nodemcu-32S
*/
#include <Arduino.h>

#define __DEBUG__

#ifdef __DEBUG__
#define DEBUG(...)                 \
  Serial.println(__VA_ARGS__);     \
  Serial.print(" @ [SRC]:      "); \
  Serial.println(__FILE__);        \
  Serial.print(" @ [LINE]:     "); \
  Serial.println(__LINE__);        \
  Serial.print(" @ [FUNCTION]: "); \
  Serial.println(__func__);
#else
#define DEBUG(...)
#endif

#define RXD2 16
#define TXD2 17

#define rxSIZES (4 * 1024)

char dbgBuf[rxSIZES + 1];

void setup()
{
  Serial.begin(115200);
  DEBUG("Setup ESP32 Start.");
  DEBUG("Enable DEBUG mode.");

  Serial2.begin(115200 * 1, SERIAL_8N1, RXD2, TXD2);
  sprintf(dbgBuf, "Serial2:%d, %d, %d, %d", 115200 * 1, SERIAL_8N1, RXD2, TXD2);
  DEBUG(dbgBuf);
  Serial2.println(dbgBuf);

  DEBUG("Setup ESP32 completed.");
}

void loop()
{
}
