#include <Arduino.h>
#include "7SegmentArrayDriver.h"
#include <Wire.h>
//#include<map>

/// @brief Driver code for 2x3 groups of individual seven segment displays.
/// - Setting a combination of drain pins will result in 1 of 6 7segment displays to be allowed to drain to GND
/// @param drain1 First of 3 drain pins
/// @param drain2 Second of 3 drain pins
/// @param drain3 Thrid of 3 drain pins
/// @param dataPin The pin used to send the data to the 74HC164 8-bit Shift Register
/// @param clockPin Sets clock for 74HC164
SevenSegmentArrayDriver::SevenSegmentArrayDriver(int drain1, int drain2, int drain3, int dataPin, int clockPin) {
    Drain1 = drain1;
    Drain2 = drain2; 
    Drain3 = drain3;
    DataPin = dataPin;
    ClockPin = clockPin;
    Decimal = B0000001;
    NONE = B00000000;
};

/// @breif Gets the byte representation of an int between 0 and 9 (inclusive)
/// @param number
/// @param hasDecimal
byte SevenSegmentArrayDriver::getNumberPattern(int number, bool hasDecimal) {
    if (number < 0 || number > 9) {
        return NONE;
    }
    byte pattern = NumberPattern[number];
    if (hasDecimal) {
        pattern = pattern + Decimal;
    }
    return pattern;
}
/// @brief Displays the digit, digit index is its order, left to right, top to bottom.
/// @param digit The seven segment display to turn on.
void SevenSegmentArrayDriver::displayDigit(int digit) {
    switch(digit) {
        case 0:
            this->setPinState(Drain1, false);
            this->setPinState(Drain2, true);
            this->setPinState(Drain3, true);
            break;
        case 1:
            this->setPinState(Drain1, true);
            this->setPinState(Drain2, false);
            this->setPinState(Drain3, false);
            break;
        case 2:
            this->setPinState(Drain1, false);
            this->setPinState(Drain2, true);
            this->setPinState(Drain3, false);
            break;
        case 3:
            this->setPinState(Drain1, true);
            this->setPinState(Drain2, true);
            this->setPinState(Drain3, false);
            break;
        case 4:
            this->setPinState(Drain1, false);
            this->setPinState(Drain2, false);
            this->setPinState(Drain3, true);
            break;
        case 5:
            this->setPinState(Drain1, true);
            this->setPinState(Drain2, false);
            this->setPinState(Drain3, true);
            break;
        default:
            this->setPinState(Drain1, false);
            this->setPinState(Drain2, false);
            this->setPinState(Drain3, false);
            break;
    }
}

/// @brief Sets a given pin state to either high or low.
/// @param pinNumber The arduino pin being controlled
/// @param isHigh If true, the pin will be set to high. If false it will be set to low.
void SevenSegmentArrayDriver::setPinState(int pinNumber, bool isHigh) {
    digitalWrite(pinNumber, isHigh ? HIGH : LOW);
    // if (isHigh) {
        
    // } else {
    //     digitalWrite(pinNumber, LOW);
    // }
}


// TODO: Fix delay time to use millis, this will be so that the processor doesn't stop clocks
/// @brief Renders one of the 7 segment display digits.
/// @param digit The index of 7 segment display being rendered
/// @param pattern the byte representation of the character (Note: Will add as needed)
/// @param delayTime How long to display the digit for before moving onto the next one.
void SevenSegmentArrayDriver::renderDigit(int digit, byte pattern, int delayTime) {
    // Turn off the digit
    displayDigit(-1);
    // Push pattern into shift register
    shiftOut(DataPin, ClockPin, LSBFIRST, pattern);
    this->displayDigit(digit);
    // This needs to be replaced by millis as delay pauses all instructions
    delay(delayTime);
}


/// @brief Renders a group of patterns on one of the sets of 7 segment displays
/// @param pattern1 
/// @param pattern2 
/// @param pattern3 
/// @param delayTime 
/// @param isFirst If true, light the first 3 7 segment displays
void SevenSegmentArrayDriver::renderDisplayGroup(byte pattern1, byte pattern2, byte pattern3, int delayTime, bool isFirst) {
    byte patterns[3] = { pattern1, pattern2, pattern3 };
    if (isFirst) {
        for (int i = 0; i < 3; i++) {
            this->renderDigit(i, patterns[i], delayTime);
        }
        // renderDigit(0, pattern1, delayTime);
        // renderDigit(1, pattern2, delayTime);
        // renderDigit(2, pattern3, delayTime);
    } else {
        for (int i = 3; i < 6; i++) {
            this->renderDigit(i, patterns[i-3], delayTime);
        }
    }
}
