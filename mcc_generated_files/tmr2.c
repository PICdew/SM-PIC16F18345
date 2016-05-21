#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "tmr2.h"
#include "pwm1.h"
#include "pwm2.h"
#include "pwm3.h"
#include "pwm4.h"
#include "pwm5.h"
#include "pwm6.h"
#include "../SM.h"
/**
  Section: TMR2 APIs
*/

void TMR2_Initialize(void)
{
    // Set TMR2 to the options selected in the User Interface

    // T2CKPS 1:4; T2OUTPS 1:8; TMR2ON on; 
//    T2CON = 0x3D;
	T2CONbits.T2OUTPS = 15;
	T2CONbits.T2CKPS = 0;
	
    // PR2 255; 
    PR2 = 0xFF;

    // TMR2 0; 
    TMR2 = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR2IF = 0;

    // Enabling TMR2 interrupt.
    PIE1bits.TMR2IE = 1;

    // Set Default Interrupt Handler
    TMR2_SetInterruptHandler(TMR2_DefaultInterruptHandler);

    // Start TMR2
    TMR2_StartTimer();
}

void TMR2_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

uint8_t TMR2_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}

void TMR2_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;
}

void TMR2_LoadPeriodRegister(uint8_t periodVal)
{
   PR2 = periodVal;
}

void TMR2_ISR(void)
{

    // clear the TMR2 interrupt flag
    PIR1bits.TMR2IF = 0;

    if(TMR2_InterruptHandler)
    {
        TMR2_InterruptHandler();
    }
}

void TMR2_SetInterruptHandler(void* InterruptHandler){
    TMR2_InterruptHandler = InterruptHandler;
}

void TMR2_DefaultInterruptHandler(void){
    // add your TMR2 interrupt custom code
    // or set custom function using TMR2_SetInterruptHandler()
	if (SMstatbits.del2 == 1)
	{
		PWM1_DutyValueSet(SMpos[SPEEDOMETR].PWM1duty);
		PWM2_DutyValueSet(SMpos[SPEEDOMETR].PWM2duty);
		PWM3_DutyValueSet(SMpos[TAHOMETR].PWM1duty);
		PWM4_DutyValueSet(SMpos[TAHOMETR].PWM2duty);
		PWM5_LoadDutyValue(SMpos[TEMPERATURE].PWM1duty);
		PWM6_LoadDutyValue(SMpos[TEMPERATURE].PWM2duty);

		SMstatbits.del2 = 0;
		SMstatbits.CalcNext = 1;
	}
	else
	{
		SMstatbits.del2 = 1;
	}
}

/**
  End of File
*/