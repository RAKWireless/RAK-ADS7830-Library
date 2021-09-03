| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK-ADS7830-Library/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK-ADS7830-Library/actions) | <center><img src="./assets/RAK16001.png" alt="RAK16001" width=25%></center> |
| -- | -- | -- | -- |

# RAK ADC sensor modules

This library is used with the RAK16001 modules.    
This library provides easy to use functions to setup the RAKwireless ADC sensor modules and read the voltage. This modules use the ADS7830 analog to digital converter with a I2C interface.   
The ADS7830 is an 8-Channel 8-Bit Analog to Digital Converter capable of supporting all standard I2C communications speeds. The ADS7830 is capable of 8-Channel single-ended input mode or 4-Channel differential input mode, making it an ideal choice for a wide range of unipolar and bipolar analog voltage measurement applications. 
This library provides basic support for the ADS7830 ADC.

# Documentation
* [*RAKwireless RAK16001 ADC sensor*]   (https://docs.rakwireless.com/Product-Categories/WisBlock/#wisblock-io)
* [Library Repository](https://github.com/RAKWireless/RAK-ADS7830-Library) - Product repository for the ADS7830 Sensor Modules library.

# Installation
In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK-ADC.    

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK-ADC. 
Or install the library project depend by adding 
```log
lib_deps =
  rakwireless/RAKwireless ADS7830 library
```
into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK-MQx-Library folder into the library directory.    
In Arduino IDE this is usually <arduinosketchfolder>/libraries/
In PlatformIO this is usually <user/.platformio/lib>

# Usage
The library provides an ADS7830 class, which allows to read four differential or eight single-ended voltage from the RAKwireless ADC sensor modules. Check out the examples how to read voltage from an ADC sensor with the RAK16001.

## This class provides the following methods:

**void begin(void);**    
Init the ADS7830 device.

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
|    	    |           |          | 

**void setVoltageResolution(float value);**    
Set the resolution voltage

Parameters:    

| Direction | Name       | Function | 
| --------- | ----       | -------- |
| in        | value      | if use 5.0V supply for ADS7830 sensor to set value 5.0 if use 3.0V supply for ADS7830 sensor to set value 3.0   | 

**float getVoltageResolution();**     
Gets the resolution voltage configuration. 

Parameters:    

| Direction | Name       | Function | 
| --------- | ----       | -------- |
| return        |        | The value of the resolution voltage configuration    | 

**void getAddr_ADS7830(uint8_t i2cAddress);**    
Instantiates a new ADS7830 class with appropriate properties

Parameters:    

| Direction | Name            | Function | 
| --------- | ----            | -------- |
| in        | i2cAddress      |IIC address of the device| 

**float Get_SingleEnded_Data(uint8_t channel); **    
Gets data for Single_Ended input mode 

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| in        | channel   | Select the channel to read, The range is 0 to 8| 
| return    |           | The Single_Ended input mode data    | 

**float Get_Differential_Data(uint8_t channel); **    
Gets data for Differential input mode 

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| in        | channel   | Select the channel to read, The range is 0 to 8| 
| return    |           | The Differential input mode data    | 

**void setSDMode(ModeSD_t sdmode); **     
Sets the Signle_Ended/Differential Mode

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| in        | sdmode    | Select the working mode,The sdmode is SDMODE_DIFF or SDMODE_SINGLE| 

**ModeSD_t ADS7830::getSDMode()**     
Gets the Single-Ended/Differential Mode

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| return    |           | The working mode, return SDMODE_DIFF or SDMODE_SINGLE| 

**void setPDMode(ModePD_t sdmode); **     
Sets the Power_Down Mode

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| in        | sdmode    | Select the Power_Down mode| 

**ModeSD_t ADS7830::getPDMode()**     
Gets the Power_Down Mode

Parameters:    

| Direction | Name      | Function | 
| --------- | ----      | -------- |
| return    |           | The Power_Down Mode| 


**void AdsBeginTransmission(uint8_t address);**     
start iic transmission

Parameters:    

| Direction | Name      	  | Function | 
| --------- | ----      	  | -------- |
| in        | i2cAddress      |IIC address of the device| 

**void AdsEndTransmission(void);**     
stop iic transmission

Parameters:    

| Direction | Name      	  | Function | 
| --------- | ----      	  | -------- |
|  		    | 		      	  | 		 |