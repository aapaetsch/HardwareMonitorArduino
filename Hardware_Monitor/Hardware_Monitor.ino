#include "SoftwareI2C.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>

byte zero  = B01111110;
byte one   = B00000110;
byte two   = B11011010;
byte three = B11010110;
byte four  = B10100110;
byte five  = B11110100;
byte six   = B11111100;
byte seven = B01000110;
byte eight = B11111110;
byte nine  = B11110110;
byte decimal = B0000001;
byte number[] = { zero, one, two, three, four, five, six, seven, eight, nine };

byte A = B11101110;
byte b = B11110000;
byte C = B01111000;
byte c = B10011000;
byte d = B10111100;
byte E = B11111000;
byte e = B11110110;
byte F = B11100010;
byte G = B01111100;
byte p = B11101010;
byte u = B00111110;

#define data 12
#define clock 11
#define drainA 6
#define drainB 7
#define drainC 8

#define digitalSck 16
#define digitalSda 15

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void on(int sink) {
  digitalWrite(sink, HIGH);
}
void off(int sink) {
  digitalWrite(sink, LOW);
}
void displayDigit(int digit) {
  switch(digit) {
    case 0:
      off(drainA);
      on(drainB);
      on(drainC);
      break;
    case 1:
      on(drainA);
      off(drainB);
      off(drainC);
      break;
    case 2:
      off(drainA);
      on(drainB);
      off(drainC);
      break;
    case 3:
      on(drainA);
      on(drainB);
      off(drainC);
      break;
    case 4:
      off(drainA);
      off(drainB);
      on(drainC);
      break;
    case 5:
      on(drainA);
      off(drainB);
      on(drainC);
      break;
    default:
      off(drainA);
      off(drainB);
      off(drainC);
      break;
  }
}
void renderDigit(int digit, byte pattern, int delayTime) {
  displayDigit(-1);
  shiftOut(data, clock, LSBFIRST, pattern);
  displayDigit(digit);
  delay(delayTime);
}

// #region I2C Bus
// #endregion I2C Bus

void setup()
{
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output3
  pinMode(drainA, OUTPUT);
  pinMode(drainB, OUTPUT);
  pinMode(drainC, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed Port"));
    for(;;);
  }
  display.clearDisplay();
}
void renderDisplayGroup(byte pattern1, byte pattern2, byte pattern3, int delayTime, bool isFirst = true) {
  if (isFirst) {
    renderDigit(0, pattern1, delayTime);
    renderDigit(1, pattern2, delayTime);
    renderDigit(2, pattern3, delayTime);
  } else {
    renderDigit(3, pattern1, delayTime);
    renderDigit(4, pattern2, delayTime);
    renderDigit(5, pattern3, delayTime);
  }
}
int count = 0;
String inData;

void loop()
{
      renderDisplayGroup(G,p,u,3);
      renderDisplayGroup(C,p,u,3, false);
      if (count % 100 == 0) {
        display.setTextSize(0.5);
        display.setTextColor(WHITE);
//        display.clearDisplay();
//        display.setCursor(0, 0);
//        display.println(F("This GPU Be Sweatting"));
//        display.display();
      }
      if (count %505 == 0) {
        
        while (Serial.available() > 0)
        {
            char recieved = Serial.read();
            inData += recieved; 
            renderDisplayGroup(C,p,u,3, false);
            if (recieved == '*')
            {
              
                inData.remove(inData.length() - 1, 1);
                display.setCursor(0,0);
                display.clearDisplay();
                display.println("GPU Temp.: " + inData + char(223)+"C ");
                inData = ""; 
                
                if(inData == "DIS")
                {   
                  display.clearDisplay();
                  display.setCursor(0,0);
                  display.print("Disconnected!");
                }
            } 
            
            if (recieved == '#')
            {
                inData.remove(inData.length() - 1, 1);
                display.setCursor(0,10);
                display.clearDisplay();
                display.print("CPU Temp.: " + inData + char(223)+"C ");
                inData = ""; 
            }
            display.display();
            renderDisplayGroup(G,p,u,3);
            renderDisplayGroup(C,p,u,3, false);
        }
        count = 0;
      }
     
    count = count + 1;
}
      
