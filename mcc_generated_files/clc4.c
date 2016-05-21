#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "clc4.h"

/**
  Section: CLC4 APIs
*/

void CLC4_Initialize(void)
{
    // Set the CLC4 to the options selected in the User Interface

    // LC4G1POL not_inverted; LC4G2POL not_inverted; LC4G3POL not_inverted; LC4G4POL not_inverted; LC4POL inverted; 
    CLC4POL = 0x80;

    // LC4D1S CCP4 output; 
    CLC4SEL0 = 0x0F;

    // LC4D2S CLCIN0 (CLCIN0PPS); 
    CLC4SEL1 = 0x00;

    // LC4D3S CLCIN0 (CLCIN0PPS); 
    CLC4SEL2 = 0x00;

    // LC4D4S CLCIN0 (CLCIN0PPS); 
    CLC4SEL3 = 0x00;

    // LC4G1D3N disabled; LC4G1D2N disabled; LC4G1D4N disabled; LC4G1D1T enabled; LC4G1D3T disabled; LC4G1D2T disabled; LC4G1D4T disabled; LC4G1D1N disabled; 
    CLC4GLS0 = 0x02;

    // LC4G2D2N disabled; LC4G2D1N disabled; LC4G2D4N disabled; LC4G2D3N disabled; LC4G2D2T disabled; LC4G2D1T enabled; LC4G2D4T disabled; LC4G2D3T disabled; 
    CLC4GLS1 = 0x02;

    // LC4G3D1N enabled; LC4G3D2N disabled; LC4G3D3N disabled; LC4G3D4N disabled; LC4G3D1T disabled; LC4G3D2T disabled; LC4G3D3T disabled; LC4G3D4T disabled; 
    CLC4GLS2 = 0x01;

    // LC4G4D1N enabled; LC4G4D2N disabled; LC4G4D3N disabled; LC4G4D4N disabled; LC4G4D1T disabled; LC4G4D2T disabled; LC4G4D3T disabled; LC4G4D4T disabled; 
    CLC4GLS3 = 0x01;

    // LC4EN enabled; INTN disabled; INTP disabled; MODE SR latch; 
    CLC4CON = 0x83;

}

bool CLC4_OutputStatusGet(void)
{
    return(CLC4CONbits.LC4OUT);

}
/**
 End of File
*/
