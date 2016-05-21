#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "interrupt_manager.h"
#include "mcc.h"
#include "../IOC.h"

void interrupt INTERRUPT_InterruptManager (void)
{
   // interrupt handler
    if(PIE1bits.ADIE == 1 && PIR1bits.ADIF == 1)
    {
        ADC_ISR();
    }
    else if(PIE1bits.TMR2IE == 1 && PIR1bits.TMR2IF == 1)
    {
        TMR2_ISR();
    }
    else if(PIE0bits.IOCIE == 1 && IOCAFbits.IOCAF5 == 1)
    {
        IOC_ISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/