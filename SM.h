#ifndef SM_H
#define	SM_H

#define SM_COUNT    3 

#define SPEEDOMETR  0
#define TAHOMETR    1
#define TEMPERATURE 2

typedef struct stc_sm_pos
{
	unsigned long	sm_inp;
	unsigned long	sm_new;
    unsigned int	PWM1duty;
    unsigned int	PWM2duty;
} stc_sm_pos_t;
extern stc_sm_pos_t SMpos[SM_COUNT];

typedef struct stc_sm_control
{
    unsigned long 	sm_pt;
    unsigned long	sm_old;
    int				sm_velo;
    int				sm_velo_old;
    unsigned char	sm_dn;
    unsigned char	sm_vmax;
    unsigned char	sm_amax;
} stc_sm_control_t;
static stc_sm_control_t SMcontrol[SM_COUNT];

extern unsigned char SMstat;
typedef union {
    struct {
        unsigned CalcNext   :1;
        unsigned del2       :1;
        unsigned bit2       :1;
        unsigned bit3       :1;
        unsigned bit4       :1;
        unsigned bit5       :1;
        unsigned bit6       :1;
        unsigned bit7       :1;
    };
} SMstatbits_t;
extern SMstatbits_t SMstatbits;

void InitSM(void);
void ZeroPosSM(void);
void ClearPosSMC(void);
void SmParamsForReturn(void);
void SmNormalParams(void);
void sm__lpf(stc_sm_control_t *ptr, stc_sm_pos_t *lnk);

#endif	/* SM_H */

