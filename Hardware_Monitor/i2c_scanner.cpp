#include "i2c_scanner.h"
#include <Wire.h>

I2C_Scanner::I2C_Scanner(int baudRate, int delayTime) {
  if (baudRate == -1) 
  {
    baud = 19200;
  } 
  else 
  {
    baud = baudRate;  
  }
  if (delayTime == -1) 
  {
    scanDelay = 5000;  
  }
  else
  {
    scanDelay = delayTime;
  }
}

void I2C_Scanner::setupWire() {
  Wire.begin();
  Serial.begin(baud);
  while(!Serial);
  Serial.println("\nI2C Scanner");
}

void I2C_Scanner::onLoop() {
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
      {
        Serial.print("0");
      }  
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
      {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0){
    Serial.println("No I2C devices found\n");
  }
    
  else {
    Serial.println("done\n");
  }
  delay(scanDelay);
}
