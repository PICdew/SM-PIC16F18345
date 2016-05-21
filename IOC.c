#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "IOC.h"




void initIOC (void)
{
	IOCAFbits.IOCAF5 = 0;
	PIE0bits.IOCIE = 1;

}



void IOC_ISR (void)
{
	IOCAFbits.IOCAF5 = 0;
	
	
}





