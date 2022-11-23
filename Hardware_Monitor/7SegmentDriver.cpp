#include "7SegmentDriver.h"
#include <Wire.h>

SevenSegmentDriver::SevenSegmentDriver(int digitPin) {
    DigitPin = digitPin;
//    Segments = segments;
//    Digits = digits;
//    int LowerCase[26][7] = {
//      {}, // a
//      {}, // b
//      {}, // c
//      {}, // d
//      {}, // e
//    }
//    int Punctuation[6]
//    Seg_A = seg_a;
//    Seg_B = seg_b;
//    Seg_C = seg_c;
//    Seg_D = seg_d;
//    Seg_E = seg_e;
//    Seg_F = seg_f;
//    Seg_G = seg_g;
//    Seg_DP = seg_dp;
//    int segments[8] = {Seg_A, Seg_B, Seg_C, Seg_D, Seg_E, Seg_F, Seg_G, Seg_DP};
//    for (const int segment : segments) {
//      Segments[segment] = segments[segment];
//    }
};

void SevenSegmentDriver::clearSegments(int segments[]) {
  for(int i = 0; i < 7; i ++) {
    int pin = segments[i];
    digitalWrite(pin, LOW);
  }
//  for (const int &pin : Segments) {
//    digitalWrite(pin, LOW);
//  }
};

void SevenSegmentDriver::writeToSegment(int segment, int setToHigh) {
  if (setToHigh == 1) {
    digitalWrite(segment, HIGH);
  } else {
    digitalWrite(segment, LOW);
  }
};

//void SevenSegmentDriver::displayDigit(int number, bool hasDP) {
//  for(int i = 0; i < 7; i ++) {
//    this->writeToSegment(*Segments[i], *Digits[number][i]);
//  }
//  this->writeToSegment(*Segments[8], hasDP);
//};
void SevenSegmentDriver::displaySegments(int segments[], int displayCharacter[],  bool hasDP) {
//  for(int i = 0; i < 7; i ++) {
//    this->writeToSegment(segments[i], 1);
//  }
  this->writeToSegment(segments[8], hasDP);
  
}
//void SevenSegmentDriver::displayCharacter(char c, bool hasDP = false) {
//  this->clearSegments();
//  this->writeToSegment(Seg_DP, hasDP);
//  
//};
