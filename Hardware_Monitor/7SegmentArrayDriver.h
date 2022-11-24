#include <Arduino.h>
#include <Wire.h>

class SevenSegmentArrayDriver {
  private:
    int Drain1;
    int Drain2;
    int Drain3;
    int DataPin;
    int ClockPin;
    byte NumberPattern[10] = {
        B01111110,
        B00000110,
        B11011010,
        B11010110,
        B10100110,
        B11110100,
        B11111100,
        B01000110,
        B11111110,
        B11110110,
    };
    byte NONE;
    byte Decimal;
  public:
    SevenSegmentArrayDriver(int drain1, int drain2, int drain3, int dataPin, int clockPin);
    byte getNumberPattern(int number, bool hasDecimal);
    void displayDigit(int digit);
    void setPinState(int pinNumber, bool isHigh);
    void renderDigit(int digit, byte pattern, int delayTime);
    void renderDisplayGroup(byte pattern1, byte pattern2, byte pattern3, int delayTime, bool isFirst);
};
