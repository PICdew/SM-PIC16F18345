/**
  CWG2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cwg2.c

  @Summary
    This is the generated driver implementation file for the CWG2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides implementations for driver APIs for CWG2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F18345
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
*/

#include <xc.h>
#include "cwg2.h"

/**
  Section: CWG2 APIs
*/

void CWG2_Initialize(void)
{
    // Set the CWG2 to the options selected in MPLAB(c) Code Configurator

    // Writing to CWGxCON0, CWGxCON1, CWGxCON2, CWGxDBR & CWGxDBF registers

    // CWG2IN 0; CWG2POLA non inverted; CWG2POLC non inverted; CWG2POLB inverted; CWG2POLD non inverted; 
    CWG2CON1 = 0x02;

    // CWG2DBR 0; 
    CWG2DBR = 0x00;

    // CWG2DBF 0; 
    CWG2DBF = 0x00;

    // CWG2SHUTDOWN No Auto-shutdown; CWG2REN disabled; CWG2LSBD inactive; CWG2LSAC inactive; 
    CWG2AS0 = 0x00;

    // AS3E disabled; AS4E disabled; AS0E disabled; AS2E disabled; AS1E disabled; 
    CWG2AS1 = 0x00;

    // CWG2CS FOSC; 
    CWG2CLKCON = 0x00;

    // CWG2STRD disabled; CWG2STRB enabled; CWG2STRC disabled; CWG2STRA enabled; CWG2OVRD low; CWG2OVRA high; CWG2OVRB high; CWG2OVRC low; 
    CWG2STR = 0x33;

    // IS PWM6_OUT; 
    CWG2DAT = 0x08;
    
    // CWG2LD Buffer_not_loaded; CWG2EN enabled; CWG2MODE Steering mode; 
    CWG2CON0 = 0x80;
}


void CWG2_AutoShutdownEventSet()
{
    // Setting the SHUTDOWN bit of CWGxAS0 register
    CWG2AS0bits.CWG2SHUTDOWN = 1;
}

void CWG2_AutoShutdownEventClear()
{
    // Clearing the SHUTDOWN bit of CWGxAS0 register
    CWG2AS0bits.CWG2SHUTDOWN = 0;
}

/**
 End of File
*/
