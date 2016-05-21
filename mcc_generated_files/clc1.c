#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "clc1.h"

/**
  Section: CLC1 APIs
*/

void CLC1_Initialize(void)
{
    // Set the CLC1 to the options selected in the User Interface

    // LC1G1POL not_inverted; LC1G2POL not_inverted; LC1G3POL not_inverted; LC1G4POL not_inverted; LC1POL inverted; 
    CLC1POL = 0x80;

    // LC1D1S CCP1 output; 
    CLC1SEL0 = 0x0C;

    // LC1D2S CLCIN0 (CLCIN0PPS); 
    CLC1SEL1 = 0x00;

    // LC1D3S CLCIN0 (CLCIN0PPS); 
    CLC1SEL2 = 0x00;

    // LC1D4S CLCIN0 (CLCIN0PPS); 
    CLC1SEL3 = 0x00;

    // LC1G1D3N disabled; LC1G1D2N disabled; LC1G1D4N disabled; LC1G1D1T enabled; LC1G1D3T disabled; LC1G1D2T disabled; LC1G1D4T disabled; LC1G1D1N disabled; 
    CLC1GLS0 = 0x02;

    // LC1G2D2N disabled; LC1G2D1N disabled; LC1G2D4N disabled; LC1G2D3N disabled; LC1G2D2T disabled; LC1G2D1T enabled; LC1G2D4T disabled; LC1G2D3T disabled; 
    CLC1GLS1 = 0x02;

    // LC1G3D1N enabled; LC1G3D2N disabled; LC1G3D3N disabled; LC1G3D4N disabled; LC1G3D1T disabled; LC1G3D2T disabled; LC1G3D3T disabled; LC1G3D4T disabled; 
    CLC1GLS2 = 0x01;

    // LC1G4D1N enabled; LC1G4D2N disabled; LC1G4D3N disabled; LC1G4D4N disabled; LC1G4D1T disabled; LC1G4D2T disabled; LC1G4D3T disabled; LC1G4D4T disabled; 
    CLC1GLS3 = 0x01;

    // LC1EN enabled; INTN disabled; INTP disabled; MODE SR latch; 
    CLC1CON = 0x83;

}

bool CLC1_OutputStatusGet(void)
{
    return(CLC1CONbits.LC1OUT);

}
/**
 End of File
*/
