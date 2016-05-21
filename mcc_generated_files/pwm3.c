#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pwm3.h"

/**
  Section: Macro Declarations
*/

#define PWM3_INITIALIZE_DUTY_VALUE    0

/**
  Section: PWM Module APIs
*/

void PWM3_Initialize(void)
{
    // Set the PWM to the options selected in the MPLAB(c) Code Configurator

    // CCP3MODE PWM; CCP3EN enabled; CCP3FMT right_aligned; 
    CCP3CON = 0x8F;    

    // CCPR3H 0; 
    CCPR3H = 0x00;    

    // CCPR3L 127; 
    CCPR3L = 0x00;     

    // Selecting Timer 2
    CCPTMRSbits.C3TSEL = 0x0;
}

void PWM3_DutyValueSet(uint16_t dutyValue)
{
//    dutyValue &= 0x03FF;
    
    // Load duty cycle value
//    if(CCP3CONbits.CCP3FMT)
//    {
//        dutyValue <<= 6;
//        CCPR3H = dutyValue >> 8;
//        CCPR3L = dutyValue;
//    }
//    else
//    {
        CCPR3H = dutyValue >> 8;
        CCPR3L = dutyValue;
//    }
}

bool PWM3_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP3CONbits.CCP3OUT);
}
/**
 End of File
*/

