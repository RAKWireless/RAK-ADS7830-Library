/**
   @file ADS7830.h
   @author rakwireless.com
   @brief This code is designed to config ADS7830 ADC device and handle the data
   @version 1.0
   @date 2021-08-23

   @copyright Copyright (c) 2021

*/
#ifndef ADS7830_H
#define ADS7830_H

#include "Arduino.h"
#include <Wire.h>

// I2C ADDRESS/BITS
#define ADS7830_DEFAULT_ADDRESS             (0x48)      // 1001 000 (ADDR = GND)
#define ADS7830_VDD_ADDRESS                 (0x49)      // 1001 001 (ADDR = VDD)
#define ADS7830_SDA_ADDRESS                 (0x4A)      // 1001 010 (ADDR = SDA)
#define ADS7830_SCL_ADDRESS                 (0x4B)      // 1001 011 (ADDR = SCL)

#define ADS7830_CONVERSIONDELAY             (100)       //CONVERSION DELAY (in mS)

// COMMAND BYTE REGISTER
#define ADS7830_REG_COMMAND_SD_MASK         (0x80)      // Single-Ended/Differential Inputs
#define ADS7830_REG_COMMAND_SD_DIFF         (0x00)      // Bit = 0, Differential Inputs
#define ADS7830_REG_COMMAND_SD_SINGLE       (0x80)      // Bit = 1, Single-Ended Inputs

#define ADS7830_REG_COMMAND_CH_MASK         (0x70)      // Input multiplexer COMMANDuration
#define ADS7830_REG_COMMAND_CH_DIFF_0_1     (0x00)      // Differential P = CH0, N = CH1
#define ADS7830_REG_COMMAND_CH_DIFF_2_3     (0x10)      // Differential P = CH2, N = CH3
#define ADS7830_REG_COMMAND_CH_DIFF_4_5     (0x20)      // Differential P = CH4, N = CH5
#define ADS7830_REG_COMMAND_CH_DIFF_6_7     (0x30)      // Differential P = CH6, N = CH7
#define ADS7830_REG_COMMAND_CH_DIFF_1_0     (0x40)      // Differential P = CH1, N = CH0
#define ADS7830_REG_COMMAND_CH_DIFF_3_2     (0x50)      // Differential P = CH3, N = CH2
#define ADS7830_REG_COMMAND_CH_DIFF_5_4     (0x60)      // Differential P = CH5, N = CH4
#define ADS7830_REG_COMMAND_CH_DIFF_7_6     (0x70)      // Differential P = CH7, N = CH6

#define ADS7830_REG_COMMAND_CH_SINGLE_0     (0x00)      // Single-ended P = CH0, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_1     (0x40)      // Single-ended P = CH1, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_2     (0x10)      // Single-ended P = CH2, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_3     (0x50)      // Single-ended P = CH3, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_4     (0x20)      // Single-ended P = CH4, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_5     (0x60)      // Single-ended P = CH5, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_6     (0x30)      // Single-ended P = CH6, N = COM
#define ADS7830_REG_COMMAND_CH_SINGLE_7     (0x70)      // Single-ended P = CH7, N = COM

#define ADS7830_REG_COMMAND_PD_MASK         (0x0C)      // Power-Down Selection
#define ADS7830_REG_COMMAND_PD_PDADCONV     (0x00)      // Power Down Between A/D Converter Conversions
#define ADS7830_REG_COMMAND_PD_IROFF_ADON   (0x04)      // Internal Reference OFF and A/D Converter ON
#define ADS7830_REG_COMMAND_PD_IRON_ADOFF   (0x08)      // Internal Reference ON and A/D Converter OFF
#define ADS7830_REG_COMMAND_PD_IRON_ADON    (0x0C)      // Internal Reference ON and A/D Converter ON


typedef enum
{
  SDMODE_DIFF         = ADS7830_REG_COMMAND_SD_DIFF,
  SDMODE_SINGLE       = ADS7830_REG_COMMAND_SD_SINGLE
} ModeSD_t;

typedef enum
{
  PDADCONV            = ADS7830_REG_COMMAND_PD_PDADCONV,
  PDIROFF_ADON        = ADS7830_REG_COMMAND_PD_IROFF_ADON,
  PDIRON_ADOFF        = ADS7830_REG_COMMAND_PD_IRON_ADOFF,
  PDIRON_ADON         = ADS7830_REG_COMMAND_PD_IRON_ADON
} ModePD_t;

class ADS7830
{
  protected:
    // Instance-specific properties
    uint8_t ads_conversionDelay;
    ModeSD_t ads_sdmode;
    ModePD_t ads_pdmode;


  public:
    uint8_t ads7830_Address;
    void getAddr_ADS7830(uint8_t i2cAddress);         //Instantiates a new ADS7830 class with appropriate properties
    void begin(void);                                 //Set up the Hardware
    float Get_SingleEnded_Data(uint8_t channel);      //get data for Single_Ended Mode
    float Get_Differential_Data(uint8_t channel);     //get data for Differential Mode
    int8_t getLastConversionResults();                //gets last conversion data
    void setSDMode(ModeSD_t sdmode);                  //sets the Signle_Ended/Differential Mode
    ModeSD_t getSDMode(void);                         //gets the Signle_Ended/Differential Inputs
    void setPDMode(ModePD_t pdmode);                  //sets the Power_Down Mode
    ModePD_t getPDMode(void);                         //gets the Power_Down Mode
    void AdsBeginTransmission(uint8_t address);       //start iic transmission
    uint8_t AdsEndTransmission(void);                 //stop iic transmission
    void  setVoltageResolution(float value);          //set referencevoltage
    float getVoltageResolution();                     //get referencevoltage
  private:
    float ReferenceVoltage = 3.0;                    //if referencevoltage 3.0V use 3.0
};
#endif
