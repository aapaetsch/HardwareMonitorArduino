## Rough Overview of the project so far:
- Desktop Hardware Monitor: Contains the PCB Files for the project.
- Hardware_Monitor: Contains the arduino code for an arduino microcontroller, currently this is an ATMEGA328p-pu. 
  - This will be used to drive 6X7 segment displays and (hopefully) 2 i2c 128X64px screens.
  - Some logic from the output pins will need to be offloaded to external IC chips
    - So far 74HC164 8-bit Shift Register, 74LS04 hex inverter, 74LS138 
  - Serial inverters are bulky, maybe V-USB if the chip has enough storage after the program is close to finished in size...
- HardwareMonitorArduino: Contains the code related to a C# program that will run on the host pc.
    
