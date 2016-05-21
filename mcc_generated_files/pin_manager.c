#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"
#include <stdbool.h>

void PIN_MANAGER_Initialize(void)
{
    LATA = 0B00000000;
    LATB = 0B00000000;
    LATC = 0B00000000;
    WPUA = 0B00000000;
    WPUB = 0B00000000;
    WPUC = 0B00000000;
    ANSELA = 0B11111111;
    ANSELB = 0B00000000;
    ANSELC = 0B00000000;
    TRISA = 0B11001111;
    TRISB = 0B00001111;
    TRISC = 0B00000010;

    // interrupts-on-change are globally disabled
    PIE0bits.IOCIE = 0;
    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS
	
	RC2PPS = 0x0C;	// Выход CCP1
	RB4PPS = 0x04;	// Выход CLC1
	RB5PPS = 0x0D;	// Выход CCP2
	RB6PPS = 0x05;	// Выход CLC2
	
	RC3PPS = 0x0E;	// Выход CCP3
	RC6PPS = 0x06;	// Выход CLC3
	RC7PPS = 0x0F;	// Выход CCP4
	RB7PPS = 0x07;	// Выход CLC4
	
	RA4PPS = 0x08;	// Выход CWG1A
	RA5PPS = 0x09;	// Выход CWG1B
	RC4PPS = 0x10;	// Выход CWG2A
	RC5PPS = 0x11;	// Выход CWG2B 
/*
    CLCIN0PPSbits.CLCIN0PPS = 0x0002;   //RA2->CLC1:CLCIN0;
    CLCIN1PPSbits.CLCIN1PPS = 0x0013;   //RC3->CLC4:CLCIN1;
    CLCIN2PPSbits.CLCIN2PPS = 0x000C;   //RB4->CLC4:CLCIN2;
    CLCIN3PPSbits.CLCIN3PPS = 0x000D;   //RB5->CLC2:CLCIN3;
*/
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
}

void PIN_MANAGER_IOC(void)
{    
}

/**
 End of File
*/