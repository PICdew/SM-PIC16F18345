#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "SM.h"

/*
                         Main application
 */
void main(void)
{

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

	
	
	static long i1=0,i2=0,i3=0,k1=3000,k2=4000,k3=5000;	

	InitSM();
	SmParamsForReturn();
	ZeroPosSM();
	PEIE = 1;
	GIE = 1;

	while (SMpos[SPEEDOMETR].sm_new)
	{
		if (SMstatbits.CalcNext == 1)
		{
			SMstatbits.CalcNext = 0;
//			sm__lpf( &SMcontrol[0], &SMpos[0]);
//			sm__lpf(SPEEDOMETR);
//			sm__lpf(TAHOMETR);
//			sm__lpf(TEMPERATURE);
		}
	}
/*	for (i = 0; i<2000;)
	{
		if (SMstatbits.CalcNext == 1)
		{
			i++;
			SMstatbits.CalcNext = 0;
			sm__lpf(SPEEDOMETR);
			sm__lpf(TAHOMETR);
		}
	}*/

	ClearPosSMC();
	SmNormalParams();

//	i=0;
    while (1)
    {
		if (SMstatbits.CalcNext == 1)
		{
			SMstatbits.CalcNext = 0;


//		    GIE = 0;
//			 = ADCchenel2;
//		    GIE = 1;
			
			//i = i*180.17595307917888563049853372434;
//			i = -360*256l;
			
//			i = 360*256l;
		    GIE = 0;
//			SMpos[SPEEDOMETR].sm_inp = i1;
//			SMpos[TAHOMETR].sm_inp = i2;
//			SMpos[TEMPERATURE].sm_inp = i3;
		    GIE = 1;
			
			LATCbits.LATC0 = 1;
//			sm__lpf(SPEEDOMETR);
//			sm__lpf(TAHOMETR);
//			sm__lpf(TEMPERATURE);
			LATCbits.LATC0 = 0;
			
			k1++;
			if (k1 > 3000)
			{
				k1 = 0;
				if (i1 == 5000)
					i1 = 70000;//360*256l;
				else
					i1 = 5000;
			}
			k2++;
			if (k2 > 4000)
			{
				k2 = 0;
				if (i2 == 5000)
					i2 = 70000;//360*256l;
				else
					i2 = 5000;
			}
			k3++;
			if (k3 > 5000)
			{
				k3 = 0;
				if (i3 == 5000)
					i3 = 70000;//360*256l;
				else
					i3 = 5000;
			}
		}
        // Add your application code
    }
}
/**
 End of File
*/