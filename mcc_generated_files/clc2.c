#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "clc2.h"

/**
  Section: CLC2 APIs
*/

void CLC2_Initialize(void)
{
    // Set the CLC2 to the options selected in the User Interface

    // LC2G1POL not_inverted; LC2G2POL not_inverted; LC2G3POL not_inverted; LC2G4POL not_inverted; LC2POL inverted; 
    CLC2POL = 0x80;

    // LC2D1S CCP2 output; 
    CLC2SEL0 = 0x0D;

    // LC2D2S CLCIN0 (CLCIN0PPS); 
    CLC2SEL1 = 0x00;

    // LC2D3S CLCIN0 (CLCIN0PPS); 
    CLC2SEL2 = 0x00;

    // LC2D4S CLCIN0 (CLCIN0PPS); 
    CLC2SEL3 = 0x00;

    // LC2G1D3N disabled; LC2G1D2N disabled; LC2G1D4N disabled; LC2G1D1T enabled; LC2G1D3T disabled; LC2G1D2T disabled; LC2G1D4T disabled; LC2G1D1N disabled; 
    CLC2GLS0 = 0x02;

    // LC2G2D2N disabled; LC2G2D1N disabled; LC2G2D4N disabled; LC2G2D3N disabled; LC2G2D2T disabled; LC2G2D1T enabled; LC2G2D4T disabled; LC2G2D3T disabled; 
    CLC2GLS1 = 0x02;

    // LC2G3D1N enabled; LC2G3D2N disabled; LC2G3D3N disabled; LC2G3D4N disabled; LC2G3D1T disabled; LC2G3D2T disabled; LC2G3D3T disabled; LC2G3D4T disabled; 
    CLC2GLS2 = 0x01;

    // LC2G4D1N enabled; LC2G4D2N disabled; LC2G4D3N disabled; LC2G4D4N disabled; LC2G4D1T disabled; LC2G4D2T disabled; LC2G4D3T disabled; LC2G4D4T disabled; 
    CLC2GLS3 = 0x01;

    // LC2EN enabled; INTN disabled; INTP disabled; MODE SR latch; 
    CLC2CON = 0x83;

}

bool CLC2_OutputStatusGet(void)
{
    return(CLC2CONbits.LC2OUT);

}
/**
 End of File
*/
