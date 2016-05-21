#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pwm4.h"

/**
  Section: Macro Declarations
*/

#define PWM4_INITIALIZE_DUTY_VALUE    0

/**
  Section: PWM Module APIs
*/

void PWM4_Initialize(void)
{
    // Set the PWM to the options selected in the MPLAB(c) Code Configurator

    // CCP4MODE PWM; CCP4OUT 0; CCP4EN enabled; CCP4FMT right_aligned; 
    CCP4CON = 0x8F;    

    // CCPR4H 0; 
    CCPR4H = 0x00;    

    // CCPR4L 127; 
    CCPR4L = 0x00;    

    // Selecting Timer 2
    CCPTMRSbits.C4TSEL = 0x0;
}

void PWM4_DutyValueSet(uint16_t dutyValue)
{
    dutyValue &= 0x03FF;
    
    // Load duty cycle value
//    if(CCP4CONbits.CCP4FMT)
//    {
//        dutyValue <<= 6;
//        CCPR4H = dutyValue >> 8;
//        CCPR4L = dutyValue;
//    }
//    else
//    {
        CCPR4H = dutyValue >> 8;
        CCPR4L = dutyValue;
//    }
}

bool PWM4_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP4CONbits.CCP4OUT);
}
/**
 End of File
*/

