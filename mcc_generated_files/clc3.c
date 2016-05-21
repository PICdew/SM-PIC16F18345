#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "clc3.h"

/**
  Section: CLC3 APIs
*/

void CLC3_Initialize(void)
{
    // Set the CLC3 to the options selected in the User Interface

    // LC3G1POL not_inverted; LC3G2POL not_inverted; LC3G3POL not_inverted; LC3G4POL not_inverted; LC3POL inverted; 
    CLC3POL = 0x80;

    // LC3D1S CCP3 output; 
    CLC3SEL0 = 0x0E;

    // LC3D2S CLCIN0 (CLCIN0PPS); 
    CLC3SEL1 = 0x00;

    // LC3D3S CLCIN0 (CLCIN0PPS); 
    CLC3SEL2 = 0x00;

    // LC3D4S CLCIN0 (CLCIN0PPS); 
    CLC3SEL3 = 0x00;

    // LC3G1D3N disabled; LC3G1D2N disabled; LC3G1D4N disabled; LC3G1D1T enabled; LC3G1D3T disabled; LC3G1D2T disabled; LC3G1D4T disabled; LC3G1D1N disabled; 
    CLC3GLS0 = 0x02;

    // LC3G2D2N disabled; LC3G2D1N disabled; LC3G2D4N disabled; LC3G2D3N disabled; LC3G2D2T disabled; LC3G2D1T enabled; LC3G2D4T disabled; LC3G2D3T disabled; 
    CLC3GLS1 = 0x02;

    // LC3G3D1N enabled; LC3G3D2N disabled; LC3G3D3N disabled; LC3G3D4N disabled; LC3G3D1T disabled; LC3G3D2T disabled; LC3G3D3T disabled; LC3G3D4T disabled; 
    CLC3GLS2 = 0x01;

    // LC3G4D1N enabled; LC3G4D2N disabled; LC3G4D3N disabled; LC3G4D4N disabled; LC3G4D1T disabled; LC3G4D2T disabled; LC3G4D3T disabled; LC3G4D4T disabled; 
    CLC3GLS3 = 0x01;

    // LC3EN enabled; INTN disabled; INTP disabled; MODE SR latch; 
    CLC3CON = 0x83;

}

bool CLC3_OutputStatusGet(void)
{
    return(CLC3CONbits.LC3OUT);

}
/**
 End of File
*/
