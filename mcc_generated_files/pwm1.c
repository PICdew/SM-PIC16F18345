#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pwm1.h"

/**
  Section: Macro Declarations
*/

#define PWM1_INITIALIZE_DUTY_VALUE    0

/**
  Section: PWM Module APIs
*/

void PWM1_Initialize(void)
{
    // Set the PWM to the options selected in the MPLAB(c) Code Configurator

    // CCP1MODE PWM; CCP1EN enabled; CCP1FMT right_aligned; 
    CCP1CON = 0x8F;    

    // CCPR1H 0; 
    CCPR1H = 0x00;    

    // CCPR1L 255; 
    CCPR1L = 0x00;    

    // Selecting Timer 2
    CCPTMRSbits.C1TSEL = 0x0;
}

void PWM1_DutyValueSet(uint16_t dutyValue)
{
    dutyValue &= 0x03FF;
    
    // Load duty cycle value
//    if(CCP1CONbits.CCP1FMT)
//    {
//        dutyValue <<= 6;
//        CCPR1H = dutyValue >> 8;
//        CCPR1L = dutyValue;
//    }
//    else
//    {
        CCPR1H = dutyValue >> 8;
        CCPR1L = dutyValue;
//    }
}

bool PWM1_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP1CONbits.CCP1OUT);
}
/**
 End of File
*/

