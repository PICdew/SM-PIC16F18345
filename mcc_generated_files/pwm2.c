#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pwm2.h"

/**
  Section: Macro Declarations
*/

#define PWM2_INITIALIZE_DUTY_VALUE    0

/**
  Section: PWM Module APIs
*/

void PWM2_Initialize(void)
{
    // Set the PWM to the options selected in the MPLAB(c) Code Configurator

    // CCP2MODE PWM; CCP2EN enabled; CCP2FMT right_aligned; 
    CCP2CON = 0x8F;    

    // CCPR2H 0; 
    CCPR2H = 0x00;    

    // CCPR2L 127; 
    CCPR2L = 0x00;     

    // Selecting Timer 2
    CCPTMRSbits.C2TSEL = 0x0;
}

void PWM2_DutyValueSet(uint16_t dutyValue)
{
    dutyValue &= 0x03FF;
    
    // Load duty cycle value
//    if(CCP2CONbits.CCP2FMT)
//    {
//        dutyValue <<= 6;
//        CCPR2H = dutyValue >> 8;
//        CCPR2L = dutyValue;
//    }
//    else
//    {
        CCPR2H = dutyValue >> 8;
        CCPR2L = dutyValue;
//    }
}

bool PWM2_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP2CONbits.CCP2OUT);
}
/**
 End of File
*/

