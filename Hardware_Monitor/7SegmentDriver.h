#include <Arduino.h>

class SevenSegmentDriver {
  private:
    int DigitPin;
//    int *Segments;
//    int *Digits;
//    int Segments[8];
//    int Digits[10][7]  = {
//      {1,1,1,1,1,1,0}, // digit 0
//      {0,1,1,0,0,0,0}, // digit 1
//      {1,1,0,1,1,0,1}, // digit 2
//      {1,1,1,1,0,0,1}, // digit 3
//      {0,1,1,0,0,1,1}, // digit 4
//      {1,0,1,1,0,1,1}, // digit 5
//      {1,0,1,1,1,1,1}, // digit 6
//      {1,1,1,0,0,0,0}, // digit 7
//      {1,1,1,1,1,1,1}, // digit 8
//      {1,1,1,1,0,1,1}  // digit 9
//    };
//    int UpperCase[26][7] = {
//      {1,1,1,0,1,1,1}, // A
//      {1,1,1,1,1,1,1}, // B
//      {1,0,0,1,1,1,0}, // C
//      {1,1,1,1,1,0,0}, // D
//      {1,0,0,1,1,1,1}, // E
//      {1,0,0,0,1,1,1}, // F
//      {1,0,1,1,1,1,0}, // G
//      {0,1,1,0,1,1,1}, // H
//      {0,0,0,0,1,1,0}, // I
//      {0,1,1,1,0,0,0}, // J
//      {1,0,1,0,1,1,1}, // K
//      {0,0,0,1,1,1,0}, // L
//      {1,1,0,1,0,1,0}, // M
//      {1,1,1,0,1,1,0}, // N
//      {1,1,1,1,1,1,0}, // O
//      {1,1,0,0,1,1,1}, // P
//      {1,1,0,1,0,1,1}, // Q
//      {1,1,0,1,1,1,1}, // R
//      {1,0,1,1,0,1,1}, // S
//      {1,0,0,0,1,1,0}, // T
//      {0,1,1,1,1,1,0}, // U
//      {0,1,1,1,0,1,0}, // V
//      {1,0,1,1,1,0,0}, // W
//      {1,0,0,1,0,0,1}, // X
//      {0,1,0,1,0,1,1}, // Y
//      {1,1,0,1,1,0,1}, // Z
//    };
//    int Seg_DP;
//    int Seg_A;
//    int Seg_B;
//    int Seg_C;
//    int Seg_D;
//    int Seg_E;
//    int Seg_F;
//    int Seg_G;
  public:
//    SevenSegmentDriver(int digitPin, int *segments, int *digits);
    SevenSegmentDriver(int digitPin);
    void clearSegments(int segments[]);
    void writeToSegment(int segment, int setToHigh);
//    void displayDigit(int number, bool hasDP);
//    void displaySegments(int segments, bool hasDP);
    void displaySegments(int segments[], int displayCharacter[],  bool hasDP);
};
