#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "SM.h"

unsigned char const SM_TAB_SC[128]={
0, 1, 3, 4, 6, 7, 9, 10, 12, 14, 15, 17, 18, 20, 21, 23, 
24, 26, 28, 29, 31, 32, 34, 35, 37, 38, 40, 41, 43, 44, 46, 47, 
48, 50, 51, 53, 54, 56, 57, 58, 60, 61, 63, 64, 65, 67, 68, 69, 
71, 72, 73, 74, 76, 77, 78, 79, 81, 82, 83, 84, 85, 87, 88, 89, 
90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 
106, 107, 108, 108, 109, 110, 111, 112, 112, 113, 114, 115, 115, 116, 117, 117, 
118, 118, 119, 119, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 124, 125, 
125, 125, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127
};


stc_sm_pos_t SMpos[SM_COUNT];
stc_sm_control_t SMcontrol[SM_COUNT];
SMstatbits_t SMstatbits;

void InitSM(void) /* set up all neccesary CPU resources  */ 
{
	unsigned char i = 0;
	for (i = 0; i < SM_COUNT; i++)
	{
    	/* initialise low pass filters     */ 
		SMpos[i].sm_inp = 0;                    /* clear target position    */ 
		SMcontrol[i].sm_pt = 0;                    /* clear actual position         */ 
		SMpos[i].sm_new = 0; 
		SMcontrol[i].sm_old = 0;         /* clear actual outputs        */ 
		SMcontrol[i].sm_velo = 0;
		SMcontrol[i].sm_velo_old = 0;
	}
}

void ZeroPosSM(void)
{
	sm__lpf( &SMcontrol[0], &SMpos[0]);
	unsigned char i = 0;
	for (i = 0; i < SM_COUNT; i++)
	{
		SMpos[i].sm_inp = 0;
		SMcontrol[i].sm_pt = 360*256l;	
		SMpos[i].sm_new = 360*256l;
	}
} 

void ClearPosSMC(void)
{
	unsigned char i = 0;
	for (i = 0; i < SM_COUNT; i++)
	{
		SMcontrol[i].sm_pt = 0;
		SMcontrol[i].sm_old = 0;
		SMcontrol[i].sm_velo = 0;
		SMcontrol[i].sm_velo_old = 0;
		SMpos[i].sm_inp = 0;
		SMpos[i].sm_new = 0;
		SMpos[i].PWM1duty = 1020;
		SMpos[i].PWM2duty = 511;
	}
}

void SmParamsForReturn(void)
{
	unsigned char i = 0;
	for (i = 0; i < SM_COUNT; i++)
	{
		SMcontrol[i].sm_dn =    7;           /* set up damping grade       */ 
		SMcontrol[i].sm_amax =  1;                /* set up acceleration limit      */ 	
		SMcontrol[i].sm_vmax =  128;              /* set up velocity limit          */ 
	}
}

void SmNormalParams(void)
{
	unsigned char i = 0;
	for (i = 0; i < SM_COUNT; i++)
	{
		SMcontrol[i].sm_dn =    9;                 /* set up damping grade       */ 
		SMcontrol[i].sm_amax =  1;                /* set up acceleration limit      */ 
		SMcontrol[i].sm_vmax =  128;               /* set up velocity limit          */ 	
	}
}

/*	stc_sm_control_t
    unsigned long 	sm_pt;
    unsigned long	sm_old;
    int				sm_velo;
    int				sm_velo_old;
	
    unsigned char	sm_dn;
    unsigned char	sm_vmax;
    unsigned char	sm_amax;
	
 *	stc_sm_pos_t
	unsigned long	sm_inp;
	unsigned long	sm_new;
    unsigned int	PWM1duty;
    unsigned int	PWM2duty;*/
	
void sm__lpf(stc_sm_control_t *ptr, stc_sm_pos_t *lnk)
{ /* this tiny calculation should be done in a less part of a millisecond  */  
	long sm_clc;
	ptr->sm_old = lnk->sm_new;     /* yesterdays future is passed today */ 
    ptr->sm_velo_old = ptr->sm_velo;
	
	ptr->sm_pt = (((ptr->sm_pt << ptr->sm_dn) - ptr->sm_pt) + lnk->sm_inp) >> ptr->sm_dn;
	if (ptr->sm_pt < lnk->sm_inp)
		ptr->sm_pt ++;
	else
		if (ptr->sm_pt != 0)
			ptr->sm_pt--;
	
	lnk->sm_new = (((lnk->sm_new << ptr->sm_dn) - lnk->sm_new) + ptr->sm_pt) >> ptr->sm_dn;
	if (lnk->sm_new < ptr->sm_pt)
		lnk->sm_new ++;
	else
		if (lnk->sm_new != 0)
			lnk->sm_new--;
	
	ptr->sm_velo = lnk->sm_new - ptr->sm_old;
	sm_clc = ptr->sm_velo - ptr->sm_velo_old;
	
	if (sm_clc > 0)
	{
		if (sm_clc > ptr->sm_amax)
		{
			ptr->sm_velo = ptr->sm_velo_old + ptr->sm_amax;
			if (ptr->sm_velo > ptr->sm_vmax)
				ptr->sm_velo = ptr->sm_vmax;
		}
	}
	else
	{
		if (sm_clc < (-ptr->sm_amax))
		{
			ptr->sm_velo = ptr->sm_velo_old - ptr->sm_amax;	
			if (ptr->sm_velo < (-ptr->sm_vmax))
				ptr->sm_velo = -ptr->sm_vmax;
		}
	}

	lnk->sm_new = ptr->sm_old + ptr->sm_velo;
	if (lnk->sm_new & 0x80000000)	//((long)SMpos[n].sm_new < 0)
		lnk->sm_new = 0;

	unsigned char steps = (unsigned char)lnk->sm_new & 0x7F;
	unsigned int Sin = (unsigned int)SM_TAB_SC[steps]<<2;
	unsigned int Cos = (unsigned int)SM_TAB_SC[127-steps]<<2;
	
	if (lnk->sm_new & 0x00000100)
	{
		if (lnk->sm_new & 0x00000080)
		{
			lnk->PWM1duty = 512+Sin;
			lnk->PWM2duty = 512+Cos;
		}
		else
		{
			lnk->PWM1duty = 512-Cos;
			lnk->PWM2duty = 512+Sin;
		}
	}
	else
	{
		if (lnk->sm_new & 0x00000080)
		{
			lnk->PWM1duty = 512-Sin;
			lnk->PWM2duty = 511-Cos;
		}
		else
		{
			lnk->PWM1duty = 512+Cos;
			lnk->PWM2duty = 512-Sin;
		}
	}
} 






/*

#define  FILTR_OSR  16
#define  FILTR_ORDER 2

long FiltrData(long data)
{
	static unsigned char bufFiltr[FILTR_ORDER][FILTR_OSR],                                                                                                                                                                            nbufFiltr[FILTR_OSR];
	unsigned long iFiltr[FILTR_ORDER];
	unsigned char n, m;
	for(m = 0; m < FILTR_ORDER; m++)
	{
		iFiltr[m] = 0;
		for(n = 0; n < FILTR_OSR; n++)
		{
			iFiltr[m] += bufFiltr[m][n];
		}
		iFiltr[m] = iFiltr[m] / FILTR_OSR;
		if(m == 0)
		{
			bufFiltr[m][nbufFiltr[m]] = data;
		}
		else {bufFiltr[m][nbufFiltr[m]] = iFiltr[m-1];}
		
		if(nbufFiltr[0] == FILTR_OSR)
		{
			nbufFiltr[m] = 0;
		}
		else
		{
			nbufFiltr[m]++;
		}
	}
	return (unsigned char)iFiltr[(FILTR_ORDER - 1)];
}


*/



