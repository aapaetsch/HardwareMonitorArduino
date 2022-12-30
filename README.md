## Rough Overview of the project so far:
- Desktop Hardware Monitor: Contains the PCB Files for the project.
- Hardware_Monitor: Contains the arduino code for an arduino microcontroller, currently this is an ATMEGA328p-pu. 
  - This will be used to drive 6x7 segment displays (common cathode) and (hopefully) 2 i2c 128X64px screens.
  - Drivers for the I2C displays still need to be coded.
  - Some logic from the output pins will need to be offloaded to external IC chips
    - So far 74HC164 8-bit Shift Register, 74LS04 hex inverter, 74LS138 
  - Serial inverters are bulky, maybe V-USB if the chip has enough storage after the program is close to finished in size...
- HardwareMonitorArduino: Contains the code related to a C# program that will run on the host pc. (Incomplete) Will share code with my DesktopHardwareMonitor electron application.


V1 PCB - No Input USB and requires a redesign as it does not fit in the 100mm x 100mm limit for JLPCB 
![image](https://user-images.githubusercontent.com/17328603/209707424-7096c170-6445-47aa-ab08-60545302a16b.png)
![image](https://user-images.githubusercontent.com/17328603/209707455-d6b06ad0-9271-49c7-8f36-b91f36c78ed2.png)

![image](https://user-images.githubusercontent.com/17328603/209707742-dd3dd74a-8d41-40a7-9881-97eeaa1c6d4e.png)
![image](https://user-images.githubusercontent.com/17328603/209707818-6f252a66-b10a-48a6-becb-60d5ec2c0b9e.png)
![image](https://user-images.githubusercontent.com/17328603/209707950-13c5a180-0ea8-41f5-aa3e-6e13878afea6.png)
