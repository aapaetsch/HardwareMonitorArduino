#include <Wire.h>
#include <Arduino.h>

class I2C_Scanner {
  private:
    int baud;
    int scanDelay;
  public:
    I2C_Scanner(int baudRate, int delayTime);
    void setupWire();
    void onLoop();
};
