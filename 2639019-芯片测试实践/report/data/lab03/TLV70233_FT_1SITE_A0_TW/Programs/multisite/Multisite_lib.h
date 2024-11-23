/**************************************************************************
           S X H B    M U L T I S I T E    L I B R A R Y     
		   T 8 6 1    t e s t e r s    
           REVISION   2 1 6          
 **************************************************************************/
extern BOOL device_passed[256];
#ifndef Multisite_lib_h
#define Multisite_lib_h


// #define V86x235_LOCAL_PROGRAM

#ifndef CSC_MAX_SITES
#define CSC_MAX_SITES 255
#endif

#ifdef	LegacyVATE522
#define	LegacyVATE531
#endif

extern unsigned short CSC_LAST_SITE;



	#ifdef LegacyVATE620
//		#define LegacyXerxes
	#endif



#if WINVER_SXHB == 0x0501
	
	#ifdef LegacyVATE531
		#undef LegacyVATE531
	#endif

	#ifdef LegacyVATE522
		#undef LegacyVATE522
	#endif

	#ifdef LegacyVATE611
		#define LegacyVATE531
//		#define LegacyXerxes
	#endif
#else

#endif



#ifndef PI
  #define PI 3.14159265358979
#endif	 


typedef unsigned short sushort[CSC_MAX_SITES];
typedef unsigned long sulong[CSC_MAX_SITES];
typedef unsigned int suint[CSC_MAX_SITES];
typedef int sint[CSC_MAX_SITES];
typedef bool sbool[CSC_MAX_SITES];
typedef float sfloat[CSC_MAX_SITES];
typedef float* sfloat_wf[CSC_MAX_SITES];
typedef double sdouble[CSC_MAX_SITES];
typedef double* sdouble_wf[CSC_MAX_SITES];
typedef STRING sstring[CSC_MAX_SITES];
typedef char schar[CSC_MAX_SITES][1000];
typedef enum {PIN_UNDEF, PIN_OUT, PIN_IN_POS, PIN_IN_NEG, PIN_RMS, PIN_LOAD, PIN_EXT_DRV1, PIN_EXT_DRV2} PinClassType;	
typedef enum {LOAD_INT_REF, LOAD_EXT_REF} LoadRefType;	
typedef enum {AUTO_SELECT, FAST_SIN, WAVE_SIN, WAVE_TRI, WAVE_SQR, WAVE_CPR, WAVE_CNR, WAVE_USR} AcsWaveType; 
typedef enum {ACS_START, ACS_STOP, ACS_SCALE_FREQUENCY} AcsActionType; 
#ifndef LegacyXerxes
typedef enum {XVI_TRIG_IMMEDIATE, XVI_EXT_TRIG_POS, XVI_EXT_TRIG_NEG} XviTrigType; 
typedef enum {XVI_SET_PERIOD, XVI_SET_FREQUENCY} XviSamplingModeType; 
typedef enum {XVI_DISABLE_FILTER, XVI_ENABLE_FILTER} XviFilteringModeType; 
typedef enum {XVI_INT_CLOCK, XVI_EXT_CLOCK} XviClockModeType; 

#endif



enum
{
	DVI,
	OVI,
	MUX,
	TMU,
	HVS,
	OFS,
	MVS,
	PVI,
	CBIT,
	LZB,
	OAL,
	ACS,
	DDD,	
	NONE,
#ifndef	LegacyXerxes
	XVI,	
#endif
	OVI_S,	
	OV2,
	QTMU1,
	CBT,
	QAL,
};


enum 
{


	ACS_KEEP_OFFSET			=2,
	ACS_CLEAR_OFFSET		=3,
	ACS_FREQ_MUL_BY_2		=4,
	ACS_FREQ_MUL_BY_4		=5,
	ACS_FREQ_MUL_BY_8		=6,
	ACS_FREQ_MUL_BY_16		=7,
	ACS_FREQ_MUL_BY_32		=8,
	ACS_FREQ_MUL_BY_64		=9,
	ACS_FREQ_MUL_BY_128		=10,
	ACS_FREQ_MUL_BY_256		=11,
	ACS_FREQ_MUL_BY_512		=12,
	ACS_FREQ_MUL_BY_1024	=13,
	ACS_FREQ_MUL_BY_2048	=14,
	ACS_FREQ_MUL_BY_4096	=15,
	ACS_FREQ_MUL_BY_8192	=16,
	ACS_FREQ_MUL_BY_16384	=17,
	ACS_FREQ_DIV_BY_2		=18,
	ACS_FREQ_DIV_BY_4		=19,
	ACS_FREQ_DIV_BY_8		=20,
	ACS_FREQ_DIV_BY_16		=21,
	ACS_FREQ_DIV_BY_32		=22,
	ACS_FREQ_DIV_BY_64		=23,
	ACS_FREQ_DIV_BY_128		=24,
	ACS_FREQ_DIV_BY_256		=25,
	ACS_FREQ_DIV_BY_512		=26,
	ACS_FREQ_DIV_BY_1024	=27,
	ACS_FREQ_DIV_BY_2048	=28,
	ACS_FREQ_DIV_BY_4096	=29,
	ACS_FREQ_DIV_BY_8192	=30,
	ACS_FREQ_DIV_BY_16384	=31,
	ACS_DEFAULT_PARAM		=32
}; 

#define SITE1 0
#define SITE2 1
#define SITE3 2
#define SITE4 3
#define SITE5 4
#define SITE6 5
#define SITE7 6
#define SITE8 7
#define ALL_SITES 999

extern BOOL active_site[];
#define SITE_1_ACTIVE active_site[SITE1]
#define SITE_2_ACTIVE active_site[SITE2]
#define SITE_3_ACTIVE active_site[SITE3]
#define SITE_4_ACTIVE active_site[SITE4]
#define SITE_5_ACTIVE active_site[SITE5]
#define SITE_6_ACTIVE active_site[SITE6]
#define SITE_7_ACTIVE active_site[SITE7]
#define SITE_8_ACTIVE active_site[SITE8]

#define MAX_PIN_USED 500			
#define LASTPIN MAX_PIN_USED-1		
#define MAX_GROUP_USED   100			
#define AUTORANGE			600		
#define NO_DIFF_RANGE		AUTORANGE-1 

enum
{
	FORCE_VOLTAGE,
	FORCE_CURRENT,
};

enum
{
	AWG_SINGLE,	    	   
	AWG_LOOP,	    	  
};

enum
{
	AWG_VOLTAGE,
	AWG_CURRENT,
	AWG_ALL_TYPES,
};

enum
{
	MEAS_NORMAL,
	MEAS_AWG,
};

enum
{
	MEAS_AVG,
	MEAS_MAX,
	MEAS_MIN,
	MEAS_TRG
};

enum
{
	TRG_NEG_SLOPE,
	TRG_POS_SLOPE,
};

enum
{
	AWG_VOLTAGE_BUSY=0x0001,
	AWG_CURRENT_BUSY=0x0002,
};

enum
{
	MEAS_ADC_BUSY=0x0001,
	MEAS_TRG_BUSY=0x0002,
};

enum 
{
	SELF_ARM_IMMEDIATE,
	SELF_ARM_EXT,
	SELF_ARM_START,
	SELF_ARM_STOP,
};

typedef enum CARD_RANGE
{
	DVI_IRANGE_30_UA  	   = MICRO_20_AMP,
	DVI_IRANGE_300_UA  	   = MICRO_200_AMP,
	DVI_IRANGE_3_MA   	   = MILLI_2_AMP,
	DVI_IRANGE_30_MA  	   = MILLI_20_AMP,
	DVI_IRANGE_300_MA  	   = MILLI_200_AMP,
	
	DVI2_IRANGE_2_UA  	   = MICRO_2_AMP,
	DVI2_IRANGE_20_UA  	   = MICRO_20_AMP,
	DVI2_IRANGE_200_UA     = MICRO_200_AMP,
	DVI2_IRANGE_2_MA  	   = MILLI_2_AMP,
	DVI2_IRANGE_20_MA  	   = MILLI_20_AMP,
	DVI2_IRANGE_200_MA     = MILLI_200_AMP,
	DVI2_IRANGE_2_A   	   = AMP_2,
	
	DVI3_IRANGE_2_UA  	   = MICRO_2_AMP,
	DVI3_IRANGE_20_UA  	   = MICRO_20_AMP,
	DVI3_IRANGE_200_UA     = MICRO_200_AMP,
	DVI3_IRANGE_2_MA  	   = MILLI_2_AMP,
	DVI3_IRANGE_20_MA  	   = MILLI_20_AMP,
	DVI3_IRANGE_200_MA     = MILLI_200_AMP,
	DVI3_IRANGE_2_A   	   = AMP_2,
	DVI3_IRANGE_20_A  	   = AMP_20,
	
	OVI_IRANGE_3_UA   	   = RANGE_3_UA,
	OVI_IRANGE_30_UA  	   = RANGE_30_UA,
	OVI_IRANGE_300_UA  	   = RANGE_300_UA,
	OVI_IRANGE_3_MA   	   = RANGE_3_MA,
	OVI_IRANGE_30_MA       = RANGE_30_MA,
	
	OV2_IRANGE_5_UA   	   = RANGE_5_UA,
	OV2_IRANGE_50_UA  	   = RANGE_50_UA,
	OV2_IRANGE_500_UA  	   = RANGE_500_UA,
	OV2_IRANGE_5_MA   	   = RANGE_5_MA,
	OV2_IRANGE_50_MA  	   = RANGE_50_MA,
	OV2_IRANGE_500_MA  	   = RANGE_500_MA,
	
	XVI_IRANGE_3_UA   	   = RANGE_3_UA,
	XVI_IRANGE_30_UA  	   = RANGE_30_UA,
	XVI_IRANGE_300_UA      = RANGE_300_UA,
	XVI_IRANGE_10_MA       = RANGE_10_MA,
	XVI_IRANGE_100_MA  	   = RANGE_100_MA,
	
	HVS_IRANGE_10_UA       = RANGE_10_UA,
	HVS_IRANGE_100_UA      = RANGE_100_UA,
	HVS_IRANGE_1_MA        = RANGE_1_MA,
	HVS_IRANGE_10_MA       = RANGE_10_MA,
	
	HVS2_IRANGE_10_UA      = RANGE_10_UA,
	HVS2_IRANGE_100_UA     = RANGE_100_UA,
	HVS2_IRANGE_1_MA       = RANGE_1_MA,
	HVS2_IRANGE_10_MA      = RANGE_10_MA,
	HVS2_IRANGE_100_MA     = RANGE_100_MA,
	
	OFS_IRANGE_200_UA      = RANGE_200_UA,
	OFS_IRANGE_2_MA        = RANGE_2_MA,
	OFS_IRANGE_20_MA       = RANGE_20_MA,
	OFS_IRANGE_200_MA      = RANGE_200_MA,
	
	PV3_IRANGE_100_MA      = RANGE_100_MA,
	PV3_IRANGE_300_MA      = RANGE_300_MA,
	PV3_IRANGE_1_A         = RANGE_1_A,
	PV3_IRANGE_3_A         = RANGE_3_A,
	PV3_IRANGE_10_A        = RANGE_10_A,
	PV3_IRANGE_30_A        = RANGE_30_A,
	PV3_IRANGE_100_A       = RANGE_100_A,
	
	LZB_IRANGE_40_MA       = LZB_RANGE_40_MA,
	LZB_IRANGE_400_MA      = LZB_RANGE_400_MA,
	LZB_IRANGE_4_A         = LZB_RANGE_4_A,
	

	DVI_VRANGE_1_V  	   = VOLT_1_RANGE,
	DVI_VRANGE_2_V  	   = VOLT_2_RANGE,
	DVI_VRANGE_5_V  	   = VOLT_5_RANGE,
	DVI_VRANGE_10_V   	   = VOLT_10_RANGE,
	DVI_VRANGE_20_V        = VOLT_20_RANGE,
	DVI_VRANGE_50_V   	   = VOLT_50_RANGE,

	DVI2_VRANGE_1_V  	   = VOLT_1_RANGE,
	DVI2_VRANGE_2_V    	   = VOLT_2_RANGE,
	DVI2_VRANGE_5_V   	   = VOLT_5_RANGE,
	DVI2_VRANGE_10_V  	   = VOLT_10_RANGE,
	DVI2_VRANGE_20_V  	   = VOLT_20_RANGE,
	DVI2_VRANGE_50_V  	   = VOLT_50_RANGE,

	DVI3_VRANGE_1_V   	   = VOLT_1_RANGE,
	DVI3_VRANGE_2_V   	   = VOLT_2_RANGE,
	DVI3_VRANGE_5_V   	   = VOLT_5_RANGE,
	DVI3_VRANGE_10_V  	   = VOLT_10_RANGE,
	DVI3_VRANGE_20_V  	   = VOLT_20_RANGE,
	DVI3_VRANGE_50_V  	   = VOLT_50_RANGE,

	OVI_VRANGE_1_V  	   = RANGE_1_V,
	OVI_VRANGE_2_V         = RANGE_2_V,
	OVI_VRANGE_5_V  	   = RANGE_5_V,
	OVI_VRANGE_10_V        = RANGE_10_V,
	OVI_VRANGE_20_V        = RANGE_20_V,
	
	OV2_VRANGE_2_V         = RANGE_2_V,
	OV2_VRANGE_5_V         = RANGE_5_V,
	OV2_VRANGE_10_V        = RANGE_10_V,
	OV2_VRANGE_25_V        = RANGE_25_V,
	OV2_VRANGE_50_V   	   = RANGE_50_V,

	XVI_VRANGE_1_V  	   = RANGE_1_V,
	XVI_VRANGE_3_V  	   = RANGE_3_V,
	XVI_VRANGE_5_V    	   = RANGE_5_V,
	XVI_VRANGE_10_V        = RANGE_10_V,
	XVI_VRANGE_30_V   	   = RANGE_30_V,

	HVS_VRANGE_100_V  	   = RANGE_100_V,
	HVS_VRANGE_200_V   	   = RANGE_200_V,
	HVS_VRANGE_500_V   	   = RANGE_500_V,
	HVS_VRANGE_1KV   	   = RANGE_1_KV,

	HVS2_VRANGE_10_V  	   = RANGE_10_V,
	HVS2_VRANGE_30_V  	   = RANGE_30_V,
	HVS2_VRANGE_100_V  	   = RANGE_100_V,
	HVS2_VRANGE_200_V      = RANGE_200_V,
	HVS2_VRANGE_500_V      = RANGE_500_V,
	HVS2_VRANGE_2KV        = RANGE_1_KV,
	
	OFS_VRANGE_5_V    	   = RANGE_5_V,
	OFS_VRANGE_10_V   	   = RANGE_10_V,
	OFS_VRANGE_20_V   	   = RANGE_20_V,
	OFS_VRANGE_50V   	   = RANGE_50_V,
	
	PV3_VRANGE_1_V         = RANGE_1_V,
	PV3_VRANGE_3_V         = RANGE_3_V,
	PV3_VRANGE_10_V        = RANGE_10_V,
	PV3_VRANGE_30_V        = RANGE_30_V,
	PV3_VRANGE_100_V       = RANGE_100_V,
	
	TMU_VRANGE_CHAB_2_5V   = TMU_IN_2_5V,
	TMU_VRANGE_CHAB_10V    = TMU_IN_10V,
	TMU_VRANGE_HIZ_2_5V    = TMU_IN_2_5V,
	TMU_VRANGE_HIZ_5V      = TMU_IN_5V,
	TMU_VRANGE_HIZ_10V     = TMU_IN_10V,
	TMU_VRANGE_HIZ_25V     = TMU_IN_25V,
	TMU_VRANGE_HIZ_50V     = TMU_IN_50V,
	TMU_VRANGE_HIZ_100V    = TMU_IN_100V,
	TMU_VRANGE_HIZ_250V    = TMU_IN_250V,
	TMU_VRANGE_HIZ_500V    = TMU_IN_500V,
	TMU_VRANGE_HIZ_1000V   = TMU_IN_1000V,

	QTMU1_VRANGE_CHAB_2_5V = QTMU1_IN_2_5V,
	QTMU1_VRANGE_CHAB_10V  = QTMU1_IN_10V,	
	QTMU1_VRANGE_HIZ_2_5V  = QTMU1_IN_2_5V,
	QTMU1_VRANGE_HIZ_5V    = QTMU1_IN_5V,
	QTMU1_VRANGE_HIZ_10V   = QTMU1_IN_10V,
	QTMU1_VRANGE_HIZ_25V   = QTMU1_IN_25V,
	QTMU1_VRANGE_HIZ_50V   = QTMU1_IN_50V,
	QTMU1_VRANGE_HIZ_100V  = QTMU1_IN_100V,
	QTMU1_VRANGE_HIZ_250V  = QTMU1_IN_250V,
	QTMU1_VRANGE_HIZ_500V  = QTMU1_IN_500V,
	QTMU1_VRANGE_HIZ_1000V = QTMU1_IN_1000V,

	ACS_VRANGE_1_V         = ACS_1_VOLT_RANGE,
	ACS_VRANGE_10_V        = ACS_10_VOLT_RANGE,
	ACS_VRMS_1_V           = ACS_1V_RMS_RANGE,
	ACS_VRMS_2_V           = ACS_2V_RMS_RANGE,
	ACS_VRMS_5_V           = ACS_5V_RMS_RANGE,
	ACS_VRMS_10_V          = ACS_10V_RMS_RANGE,
	ACS_VRMS_20_V          = ACS_20V_RMS_RANGE,
	ACS_VRMS_50_V          = ACS_50V_RMS_RANGE,
	ACS_VRMS_100_V         = ACS_100V_RMS_RANGE,

	
	DVI_DRANGE_10_MV  	   = RANGE_10_MV,
	DVI_DRANGE_30_MV  	   = RANGE_30_MV,
	DVI_DRANGE_100_MV  	   = RANGE_100_MV,
	DVI_DRANGE_300_MV  	   = RANGE_300_MV,
	DVI_DRANGE_1_V    	   = RANGE_1_V,
	DVI_DRANGE_3_V    	   = RANGE_3_V,
	DVI_DRANGE_10_V   	   = RANGE_10_V,
	DVI_DRANGE_30_V        = RANGE_30_V,
	DVI_DRANGE_100_V   	   = RANGE_100_V,
	
	DVI2_DRANGE_20_MV  	   = RANGE_20_MV,
	DVI2_DRANGE_50_MV  	   = RANGE_50_MV,
	DVI2_DRANGE_100_MV     = RANGE_100_MV,
	DVI2_DRANGE_200_MV     = RANGE_200_MV,
	DVI2_DRANGE_1_V   	   = RANGE_1_V,
	DVI2_DRANGE_2_V   	   = RANGE_2_V,
	DVI2_DRANGE_5_V   	   = RANGE_5_V,
	DVI2_DRANGE_10_V  	   = RANGE_10_V,
	
	DVI3_DRANGE_20_MV  	   = RANGE_20_MV,
	DVI3_DRANGE_50_MV  	   = RANGE_50_MV,
	DVI3_DRANGE_100_MV     = RANGE_100_MV,
	DVI3_DRANGE_200_MV     = RANGE_200_MV,
	DVI3_DRANGE_1_V   	   = RANGE_1_V,
	DVI3_DRANGE_2_V   	   = RANGE_2_V,
	DVI3_DRANGE_5_V   	   = RANGE_5_V,
	DVI3_DRANGE_10_V  	   = RANGE_10_V,
	
	OV2_DRANGE_100_MV  	   = RANGE_100_MV,
	OV2_DRANGE_200_MV  	   = RANGE_200_MV,
	OV2_DRANGE_500_MV  	   = RANGE_500_MV,
	OV2_DRANGE_1_V    	   = RANGE_1_V,
	OV2_DRANGE_2_V    	   = RANGE_2_V,
	OV2_DRANGE_2_5_V       = RANGE_2_5_V,
	OV2_DRANGE_5_V    	   = RANGE_5_V,
	OV2_DRANGE_10_V        = RANGE_10_V,
	OV2_DRANGE_25_V   	   = RANGE_25_V,
	OV2_DRANGE_50_V   	   = RANGE_50_V,
	
	XVI_DRANGE_10_MV       = RANGE_10_MV,											
	XVI_DRANGE_20_MV       = RANGE_20_MV,
	XVI_DRANGE_30_MV	   = RANGE_30_MV,									
	XVI_DRANGE_50_MV       = RANGE_50_MV,									
	XVI_DRANGE_100_MV	   = RANGE_100_MV,								
	XVI_DRANGE_200_MV	   = RANGE_200_MV,
	XVI_DRANGE_300_MV	   = RANGE_300_MV,								
	XVI_DRANGE_1_V		   = RANGE_1_V,							
	XVI_DRANGE_2_V		   = RANGE_2_V,
	XVI_DRANGE_3_V		   = RANGE_3_V,									
    XVI_DRANGE_5_V		   = RANGE_5_V,									
	XVI_DRANGE_10_V	       = RANGE_10_V,
} CARD_RANGE_e;


void system_status_on(void);	
void system_status_off(void);	
bool debugger_on(void);		    


void continue_on_fail(void);

void stop_on_fail(void);


void stop_on_fail_PPflag(void);


void continue_on_fail_PPflag(void);


void deactivate_fail_site(void);


void deactivate_fail_site_PPflag(void);



extern void  data_log(test_function& func, short test_no, class SFLOAT test_val, short power, unsigned short fail_bin, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short fail_bin, char *notes = NULL);			
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short fail_bin, char *notes = NULL);			
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short fail_bin, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short fail_bin, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short fail_bin, schar notes);			
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short fail_bin, schar notes);					
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short fail_bin, schar notes);					
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short *fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short *fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short *fail_bin, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short *fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short *fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short *fail_bin, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short *fail_bin, char *notes = NULL);			
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short *fail_bin, char *notes = NULL);			
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short *fail_bin, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short *fail_bin, schar notes);		
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short *fail_bin, schar notes);			
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short *fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short *fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short *fail_bin, schar notes);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short *fail_bin, schar notes);					
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short *fail_bin, schar notes);				
#endif

 

extern void  data_log(test_function& func, short test_no, class SFLOAT test_val, short power, unsigned short fail_bin,SFLOAT min_val,SFLOAT max_val, char *notes = NULL);

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short fail_bin,unsigned int *min_val,unsigned int *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short fail_bin,unsigned short *min_val,unsigned short *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short fail_bin,unsigned long *min_val,unsigned long *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short fail_bin,int *min_val,int *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short fail_bin,float *min_val,float *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short fail_bin,double *min_val,double *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short fail_bin,bool *min_val,bool *max_val, char *notes = NULL);			
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short fail_bin,sDouble min_val,sDouble max_val, char *notes = NULL);			
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short fail_bin,unsigned int *min_val,unsigned int *max_val, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short fail_bin,unsigned short *min_val,unsigned short *max_val, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short fail_bin,unsigned long *min_val,unsigned long *max_val, schar notes);			
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short fail_bin,int *min_val,int *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short fail_bin,float *min_val,float *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short fail_bin,double *min_val,double *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short fail_bin,bool *min_val,bool *max_val, schar notes);					
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short fail_bin,sDouble min_val,sDouble max_val, schar notes);					
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short *fail_bin,unsigned int *min_val,unsigned int *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short *fail_bin,unsigned short *min_val,unsigned short *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short *fail_bin,unsigned long *min_val,unsigned long *max_val, char *notes = NULL);	
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short *fail_bin,int *min_val,int *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short *fail_bin,float *min_val,float *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short *fail_bin,double *min_val,double *max_val, char *notes = NULL);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short *fail_bin,bool *min_val,bool *max_val, char *notes = NULL);			
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short *fail_bin,sDouble min_val,sDouble max_val, char *notes = NULL);			
#endif

extern void  data_log(test_function& func, short test_no, unsigned int *test_val, short power, unsigned short *fail_bin,unsigned int *min_val,unsigned int *max_val, schar notes);			
extern void  data_log(test_function& func, short test_no, unsigned short *test_val, short power, unsigned short *fail_bin,unsigned short *min_val,unsigned short *max_val, schar notes);		
extern void  data_log(test_function& func, short test_no, unsigned long *test_val, short power, unsigned short *fail_bin,unsigned long *min_val,unsigned long *max_val, schar note);			
extern void  data_log(test_function& func, short test_no, int *test_val, short power, unsigned short *fail_bin,int *min_val,int *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, float *test_val, short power, unsigned short *fail_bin,float *min_val,float *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, double *test_val, short power, unsigned short *fail_bin,double *min_val,double *max_val, schar notes);
extern void  data_log(test_function& func, short test_no, bool *test_val, short power, unsigned short *fail_bin,bool *min_val,bool *max_val, schar notes);					
#ifndef LegacyVATE522
extern void  data_log(test_function& func, short test_no, sDouble test_val, short power, unsigned short *fail_bin,sDouble min_val,sDouble max_val, schar notes);				
#endif

extern void  read_pinmap_data(STRING pathname = "", STRING filename = "");
extern void  set_max_sites(unsigned short max_site_driver, unsigned short max_site_prg);
extern void  get_active_sites(unsigned char *active_sites, unsigned short max_site_prg);
extern void  dc_connect(short pin, short mode);

extern void  dc_force(short pin,float current, float voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,double current, double voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,double current, float voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,float current, double voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin, float current, float *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin, double current, float *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin, float *current, float voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin, float *current, double voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list, sfloat *current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list, float current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list, double current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list, sfloat *current, float voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin_list, sfloat *current, double voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_force(short pin,float *current, float *voltage, short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  dc_measure(short pin,short mode , SFLOAT *res_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short usr_wait_us = -1);
extern void  dc_measure(short pin_list, short mode ,sfloat *res_list_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short usr_wait_us = -1);
extern void  dc_measure(short pin_list, short mode ,double *res_list_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short usr_wait_us = -1);
extern void  dc_measure(short pin,short mode , float *res_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short usr_wait_us = -1);
extern void  relay_connect(short relay, short mode);
extern float relay_connect(short relay, short mode, float load_var, LoadRefType LoadRef=LOAD_INT_REF);
extern void  set_driver_state(short pin, short value);
extern void  get_driver_state(short pin, char **err_pin, int *err_num);
extern void  system_status(short pin_sel, char *notes= " ", bool append_overwrite = true); 
extern void  dc_scope(short pin, short mode , short range, short num_sample, double fre_sample, short site, float *meas_array=NULL);	
extern void  dc_scope(short pin, short mode , short range, short num_sample, short fre_sample_10us, short site, float *meas_array=NULL);
extern void  dc_measure_setup(short pin, short mode ,short d_range = NO_DIFF_RANGE);
extern void  dc_measure_filter_setup(short pin, short mode ,short d_range = NO_DIFF_RANGE, bool is_filter=TRUE);
extern void  dc_mvi(short pin,short mode , double *res_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short usr_wait_us = -1, double fre_sample = 0, sdouble_wf meas_array = NULL);

extern void  cap_force(short pin,short force_mode,float transition_time,float current, float voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time,double current, double voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time,double current, float voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time,float current, double voltage, short c_range  = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time, float current, float *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time, double current, float *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time, float *current, float voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time, float *current, double voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list,short force_mode,float transition_time, float current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list,short force_mode,float transition_time, double current, sfloat *voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, float voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, double voltage, short c_range = AUTORANGE,short v_range = AUTORANGE, bool ifhalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);
extern void  cap_force(short pin,short force_mode,float transition_time,float *current, float *voltage, short c_range = AUTORANGE, short v_range = AUTORANGE, bool ihalf = false, unsigned char compensation = FAST_VOLTAGE_MODE ,unsigned char is_ext_ref = false);

extern void  awg_load_voltage(short pin, unsigned int start_addr, unsigned int stop_addr, double *awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_load_voltage(short pin, unsigned int *start_addr, unsigned int *stop_addr, double *awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_load_voltage(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_load_voltage(short pin, unsigned int *start_addr, unsigned int *stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_read_voltage(short pin, unsigned int *start_addr, unsigned int *stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_read_voltage(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_V_OUT,unsigned char is_ext_ref = FALSE);
extern void  awg_select_voltage(short pin,unsigned int start_addr, unsigned int stop_addr, unsigned int loopback_addr, double awg_interval, unsigned char awg_mode = AWG_SINGLE, unsigned short range = AUTORANGE, char polarity = POSITIVE_V_OUT, unsigned char is_ext_ref = FALSE);
extern void  awg_select_voltage(short pin,unsigned int *start_addr, unsigned int *stop_addr, unsigned int *loopback_addr, double awg_interval, unsigned char awg_mode = AWG_SINGLE, unsigned short range = AUTORANGE, char polarity = POSITIVE_V_OUT, unsigned char is_ext_ref = FALSE);
extern void  awg_load_current(short pin, unsigned int start_addr, unsigned int stop_addr, double *awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_load_current(short pin, unsigned int *start_addr, unsigned int *stop_addr, double *awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_load_current(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_load_current(short pin, unsigned int *start_addr, unsigned int *stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_read_current(short pin, unsigned int *start_addr, unsigned int *stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_read_current(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf awg_data, unsigned short range, char polarity = POSITIVE_I_OUT, unsigned char i_half = FALSE);
extern void  awg_select_current(short pin,unsigned int start_addr, unsigned int stop_addr, unsigned int loopback_addr, double awg_interval, unsigned char awg_mode = AWG_SINGLE, unsigned short range = AUTORANGE, unsigned char i_half = FALSE);
extern void  awg_select_current(short pin,unsigned int *start_addr, unsigned int *stop_addr, unsigned int *loopback_addr, double awg_interval, unsigned char awg_mode = AWG_SINGLE, unsigned short range = AUTORANGE, unsigned char i_half = FALSE);
extern void  awg_arm(short pin, unsigned char awg_type, double awg_interval, sdouble_wf awg_data, unsigned int awg_num, unsigned short range=AUTORANGE, unsigned char is_ext=FALSE,unsigned char awg_mode = AWG_SINGLE, 
					 short pin1=-1, unsigned char awg_type1=AWG_VOLTAGE, double awg_interval1=0, sdouble_wf awg_data1=NULL, unsigned int awg_num1=0, unsigned short range1=AUTORANGE, unsigned char is_ext1=FALSE,unsigned char awg_mode1 = AWG_SINGLE, 
					 short pin2=-1, unsigned char awg_type2=AWG_VOLTAGE, double awg_interval2=0, sdouble_wf awg_data2=NULL, unsigned int awg_num2=0, unsigned short range2=AUTORANGE, unsigned char is_ext2=FALSE,unsigned char awg_mode2 = AWG_SINGLE, 
					 short pin3=-1, unsigned char awg_type3=AWG_VOLTAGE, double awg_interval3=0, sdouble_wf awg_data3=NULL, unsigned int awg_num3=0, unsigned short range3=AUTORANGE, unsigned char is_ext3=FALSE,unsigned char awg_mode3 = AWG_SINGLE,
					 short pin4=-1, unsigned char awg_type4=AWG_VOLTAGE, double awg_interval4=0, sdouble_wf awg_data4=NULL, unsigned int awg_num4=0, unsigned short range4=AUTORANGE, unsigned char is_ext4=FALSE,unsigned char awg_mode4 = AWG_SINGLE,
					 short pin5=-1, unsigned char awg_type5=AWG_VOLTAGE, double awg_interval5=0, sdouble_wf awg_data5=NULL, unsigned int awg_num5=0, unsigned short range5=AUTORANGE, unsigned char is_ext5=FALSE,unsigned char awg_mode5 = AWG_SINGLE);

extern void  awg_run(short pin, unsigned int awg_delay = 0, UINT32 delay_time = 0xffffffff);
extern void  awg_enable(short pin, unsigned int awg_delay = 0);
extern void  awg_start(short pin, UINT32 delay_time = 0xffffffff);
extern void  awg_stop(short pin, unsigned char awg_type=AWG_ALL_TYPES, unsigned int stop_size=0.0, double stop_interval=0.0, double *stop_data=NULL);
extern void  awg_measure(short pin, unsigned int num_samples=1, double p_sample=0, sdouble_wf sample=NULL, unsigned char meas_mode = MEAS_NORMAL, unsigned int meas_time1 = 0, unsigned int meas_time2 = 0, unsigned int meas_time3 = 0, unsigned int meas_time4 = 0,UINT32 delay_time = 0xffffffff);
extern void  awg_get_measure_result(short pin, double *result=NULL, unsigned char meas_type = MEAS_AVG, unsigned int start_addr = 0, unsigned int stop_addr = 0xffff);
extern void  awg_set_meas_trigger(short pin, double trigger_value,unsigned char slope);
extern void  awg_set_meas_trigger(short pin, double *trigger_value,unsigned char slope);
extern void  awg_get_awg_status(short pin, unsigned short *res_ptr);
extern void  awg_get_meas_status(short pin, unsigned short *res_ptr);

void set_max_sites(unsigned short max_site_driver, unsigned short max_site_prg);
void get_active_sites(unsigned char *active_sites);

void reset_active_sites();



void store_site_status(sint usr_active_site=NULL);		
void restore_site_status(sint usr_active_site=NULL);	
void activate_one_site(int site);
bool no_site_active(void);


extern void  dc_charge_pvi(short pin,double voltage_limit, long int timeout);	
extern void  dc_charge_pvi(short pin,float voltage_limit, long int timeout);
extern void  dc_drive_on_pvi(short pin);
extern void  dc_drive_off_pvi(short pin);
extern void  dc_charge_on_pvi(short pin);
extern void  dc_charge_off_pvi(short pin);
extern void  dc_control_loop_pvi(short pin, short control_path,short mode);
extern void  dc_meas_mode_pvi(short pin, short mode, short wait_us = 200);


extern void tmu_start_trigger_setup(short pin, double ref_level, char slope, char range = -1);	
extern void tmu_start_trigger_setup(short pin, float ref_level, char slope, char range = -1);
extern void tmu_stop_trigger_setup(short pin, double ref_level, char slope, char range = -1);	
extern void tmu_stop_trigger_setup(short pin, float ref_level, char slope, char range = -1);
extern void tmu_arm(short pin,unsigned char ext_en = false, unsigned char ext_slope = true, unsigned char counter_reset = true);
extern void tmu_arm_external(short pin,char slope, double threshold = 5.0, unsigned char counter_reset = true);
extern void tmu_self_arm(short pin, short mode, unsigned char sigle = true, unsigned char ext_positive = true);


extern void tmu_read(short pin, float *res_ptr , double timeout = 10e-3);	
extern void tmu_self_arm_read(short pin, float *res_ptr , double timeout = 10e-3);	
extern void tmu_self_arm_read(short pin, sfloat_wf res_ptr, int *size);	
extern void tmu_time_holdoff(short pin, float stop_ho,	float start_ho=800e-9f);	
extern void tmu_time_holdoff(short pin, double stop_ho,	double start_ho=800e-9);	
extern void tmu_event_holdoff(short pin, unsigned short stop_ho, unsigned short start_ho=5);	
extern void tmu_clear_holdoff(short pin);	
extern void tmu_set_bit(short pin, bool logic_value); 
extern void tmu_set_bit(short pin, sbool logic_value);
extern void tmu_get_bit(short pin, bool *res_ptr);



extern void oal_set_compensation(short pin, int PoleStab, int ZeroStab);			
extern void oal_set_compensation(short pin, int *PoleStab, int *ZeroStab);		
extern void oal_get_compensation(short pin, int *PoleStab_ptr, int *ZeroStab_ptr);
extern void oal_read_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern void oal_read_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern int oal_cal_ia_offset(short pin, unsigned short range, sfloat zero_null, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);	
extern int oal_cal_ia_offset(short pin, unsigned short range, sfloat *zero_null, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);	
extern void oal_set_ia_offset(short pin, unsigned short ia_range, sfloat ia_offset);
extern void oal_set_ia_offset(short pin_list, unsigned short ia_range, sfloat *ia_offset); 
extern void oal_set_ia_offset(short pin_list, unsigned short ia_range, float ia_offset); 
extern void oal_set_ia_offset(short pin_list, unsigned short ia_range, double ia_offset);	

extern float oal_connect_load(short pin, short mode, float load_var=1.0e3f, LoadRefType LoadRef=LOAD_INT_REF);


extern void qal_set_compensation(short pin, int PoleStab, int ZeroStab);			
extern void qal_set_compensation(short pin, int *PoleStab, int *ZeroStab);		
extern void qal_get_compensation(short pin, int *PoleStab_ptr, int *ZeroStab_ptr);
extern void qal_read_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern void qal_read_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true);
extern int qal_cal_ia_offset(short pin, unsigned short range, sfloat zero_null, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);	
extern int qal_cal_ia_offset(short pin, unsigned short range, sfloat *zero_null, bool recalibrate=true, int nsamples=1, bool reject_50Hz=false, bool use_internal_short_rly=true, bool start_from_existing_cal=true);	
extern void qal_set_ia_offset(short pin, unsigned short ia_range, sfloat ia_offset); 
extern void qal_set_ia_offset(short pin_list, unsigned short ia_range, sfloat *ia_offset); 
extern void qal_set_ia_offset(short pin_list, unsigned short ia_range, float ia_offset); 
extern void qal_set_ia_offset(short pin_list, unsigned short ia_range, double ia_offset);	

extern float qal_connect_load(short pin, short mode, float load_var=1.0e3f, LoadRefType LoadRef=LOAD_INT_REF);


extern int  ac_force_setup(short pin, double Vpeak, double Voffset, double Fi, AcsWaveType mode=WAVE_SIN, short ACS_filter= ACS_FILTER_NULL, double PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);	
extern int  ac_force_setup(short pin, float Vpeak, float Voffset, float Fi, AcsWaveType mode=WAVE_SIN, short ACS_filter= ACS_FILTER_NULL, float PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);
extern void ac_force_setup(short pin, double Vpeak, double Voffset, AcsWaveType mode, int Ns, float *ACS_buf, short ACS_divider, short ACS_filter, double PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);	
extern void ac_force_setup(short pin, float Vpeak, float Voffset, AcsWaveType mode, int Ns, float *ACS_buf, short ACS_divider, short ACS_filter, float PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);
extern void ac_force(short pin, double Vpeak, double Fi, AcsWaveType mode=AUTO_SELECT);	
extern void ac_force(short pin, float Vpeak, float Fi, AcsWaveType mode=AUTO_SELECT);
extern void ac_force(short pin, double Vpeak, double Voffset, double Fi, AcsWaveType mode=AUTO_SELECT, short ACS_filter= ACS_FILTER_NULL, double PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);	
extern void ac_force(short pin, float Vpeak, float Voffset, float Fi, AcsWaveType mode=AUTO_SELECT, short ACS_filter= ACS_FILTER_NULL, float PFLP_freq=0, short sync_pin=NULL, short sync_trig=0);
extern void ac_force(short pin, AcsActionType Action, short ActionParam=ACS_DEFAULT_PARAM);


extern void ac_measure_setup(short pin, short rms_range, short coupling);
extern void ac_measure(short pin, float *res_ptr ,short ave_num=1, short rms_range=ACS_1V_RMS_RANGE, short coupling=ACS_AC_COUPLING, short wait_us=200);


extern void dc_init(short pin, float settling_time= 100.0e-3f);	

extern void tmu_init(short pin);
extern void oal_init(short pin);	
extern void qal_init(short pin);	
extern void acs_init(short pin);	
extern void ddd_init();				



extern void var_init(sfloat variable,float value);	

extern void var_init(sdouble variable,double value);	

enum	
{
	OAL_CHANNEL_0,
	OAL_CHANNEL_1,
	LAST_OAL_CHANNEL,
};

enum	
{
	QAL_CHANNEL_0,
	QAL_CHANNEL_1,
	QAL_CHANNEL_2,
	QAL_CHANNEL_3,
	LAST_QAL_CHANNEL,
};

enum
{
	CLOSE,
	CLOSE_S,
	CLOSE_F,
	CLOSE_M,
	CLOSE_BUS,
	OPEN,
	OPEN_S,
	OPEN_F,
	OPEN_M,
	OPEN_BUS,
	MEASURE_VOLTAGE,
	MEASURE_DIFF_VOLTAGE,
	MEASURE_CURRENT,
	CLOSE_REF,		
	OPEN_REF,		
	CLOSE_REF1,	
	OPEN_REF1,	
	CLOSE_REF2,	
	OPEN_REF2,	
	CLOSE_KELVIN,	
	OPEN_KELVIN,	
	CLOSE_KELVIN1,	
	OPEN_KELVIN1,	
	CLOSE_KELVIN2,	
	OPEN_KELVIN2,	
	CLOSE_FS,		
	OPEN_FS,		
	CLOSE_FS_POS,
	OPEN_FS_POS,	
	CLOSE_FS_NEG,
	OPEN_FS_NEG,	
	CLOSE_GND_POS,	
	OPEN_GND_POS,
	CLOSE_GND_NEG,	
	OPEN_GND_NEG,	


	CLOSE_SENSE_POS_OUT_COM,	
	OPEN_SENSE_POS_OUT_COM,		
	CLOSE_SENSE_NEG_OUT_COM,	
	OPEN_SENSE_NEG_OUT_COM,		
	CLOSE_SENSE_POS_REF_COM,	
	OPEN_SENSE_POS_REF_COM,		
	CLOSE_SENSE_NEG_REF_COM,
	OPEN_SENSE_NEG_REF_COM,		
	CLOSE_OUT_MUX,				
	OPEN_OUT_MUX,			


	CLOSE_REF1_MUX,			
	OPEN_REF1_MUX,			
	CLOSE_REF2_MUX,			
	OPEN_REF2_MUX,			
	CLOSE_NEG_MUX,			
	OPEN_NEG_MUX,			

	CLOSE_HIGH,	
	CLOSE_LOW,	
	OPEN_HIGH,		
	OPEN_LOW,		

	CLOSE_CH_SHORT, 
	OPEN_CH_SHORT,  

	CLOSE_MOD,		
	OPEN_MOD,	

	CLOSE_G,		
	OPEN_G,		

	CLOSE_BUS_F,
	CLOSE_BUS_S,	
	CLOSE_BUS_M,	

	OPEN_BUS_F,	
	OPEN_BUS_S,		
	OPEN_BUS_M,		


	CLOSE_SERVO_LOOP,		
	OPEN_SERVO_LOOP,			
	CLOSE_DAC_TO_INPUT,		
	OPEN_DAC_TO_INPUT,		
	CLOSE_LOCAL_LOOP,		
	OPEN_LOCAL_LOOP,		
	CLOSE_LOCAL_LOOP_10K,	
	OPEN_LOCAL_LOOP_10K,	
	CLOSE_GND_POS_IN,		
	OPEN_GND_POS_IN,			
	CLOSE_MEAS_V_IN_DIFF,		
	OPEN_MEAS_V_IN_DIFF,	
	CLOSE_MEAS_V_OUT,		
	OPEN_MEAS_V_OUT,		
	CLOSE_MEAS_I_IN,		
	OPEN_MEAS_I_IN,			
	CLOSE_LCB_PRECHARGE,	
	OPEN_LCB_PRECHARGE,		
	CLOSE_LOAD_SHORT,		
	OPEN_LOAD_SHORT,		
	CLOSE_LOAD_600,			
	OPEN_LOAD_600,			
	CLOSE_LOAD_1K,				
	OPEN_LOAD_1K,				
	CLOSE_LOAD_2K,			
	OPEN_LOAD_2K,			
	CLOSE_LOAD_4K7,			
	OPEN_LOAD_4K7,			
	CLOSE_LOAD_10K,			
	OPEN_LOAD_10K,			
	CLOSE_LOAD_100K,		
	OPEN_LOAD_100K,			
	CLOSE_CONNECT_LOADS,		
	OPEN_CONNECT_LOADS,			
	CLOSE_LOAD_REF_GND,			
	OPEN_LOAD_REF_GND,			
	CLOSE_LOAD_REF_EXT,			
	OPEN_LOAD_REF_EXT,			
	CLOSE_EXT_LOAD_CONN,		
	OPEN_EXT_LOAD_CONN,			

	CLOSE_OUT_POL,				
	OPEN_OUT_POL,				
	CLOSE_OUT_RNG_X4,			
	OPEN_OUT_RNG_X4,			
	CLOSE_DAC_OUT,				
	OPEN_DAC_OUT,				
	CLOSE_INT_CONN,				
	OPEN_INT_CONN,				
	CLOSE_INT_RESET,			
	OPEN_INT_RESET,				
	CLOSE_INT_SLOW,				
	OPEN_INT_SLOW,				
	CLOSE_DC_GAIN,				
	OPEN_DC_GAIN,				
	CLOSE_CLOSE_LOOP,			
	OPEN_CLOSE_LOOP,			
	CLOSE_CLS_LOOP_IV,			
	OPEN_CLS_LOOP_IV,			
	CLOSE_MLG_CON_POS,			
	OPEN_MLG_CON_POS,			
	CLOSE_LLG_CON_POS,			
	OPEN_LLG_CON_POS,			
	CLOSE_POS_LKG_X10,			
	OPEN_POS_LKG_X10,			
	CLOSE_MLG_CON_NEG,			
	OPEN_MLG_CON_NEG,			
	CLOSE_LLG_CON_NEG,			
	OPEN_LLG_CON_NEG,			
	CLOSE_NEG_LKG_X10,			
	OPEN_NEG_LKG_X10,			
	CLOSE_IA_POS_IN,			
	OPEN_IA_POS_IN,				
	CLOSE_IA_NEG_IN,			
	OPEN_IA_NEG_IN,				
	CLOSE_IA_OFF_100_MV,		
	OPEN_IA_OFF_100_MV,			
	CLOSE_DUT_POS_ISOL,			
	OPEN_DUT_POS_ISOL,			
	CLOSE_DUT_NEG_ISOL,			
	OPEN_DUT_NEG_ISOL,			
	CLOSE_DUT_INP_SHORT,		
	OPEN_DUT_INP_SHORT,			
	CLOSE_SHORT_FEEDBACK_RES,	
	OPEN_SHORT_FEEDBACK_RES,	
	CLOSE_FEEDBACK_TO_OUT,		
	OPEN_FEEDBACK_TO_OUT,		
	CLOSE_IA_OFF_POL,			
	OPEN_IA_OFF_POL,			
	CLOSE_DUT_POS_OUT,			
	OPEN_DUT_POS_OUT,			
	CLOSE_DUT_NEG_OUT,			
	OPEN_DUT_NEG_OUT,			
	CLOSE_DUT_TO_RMS,			
	OPEN_DUT_TO_RMS,			
	CLOSE_DUT_OUT_OUT,			
	OPEN_DUT_OUT_OUT,			
	CLOSE_LOAD,					
	OPEN_LOAD,					
	CLOSE_HV_BUF_CONN,			
	OPEN_HV_BUF_CONN,			

	CLOSE_GND_SNS,				
	OPEN_GND_SNS,				
	CLOSE_BUF,                  
	OPEN_BUF,                   

	MEASURE_EXT_REF,      
	CLOSE_FS_RES,
	OPEN_FS_RES,
	
	CLOSE_FS_10K,
	OPEN_FS_10K,
	CLOSE_FS_100K,
	OPEN_FS_100K,
	CLOSE_FS_200K,
	OPEN_FS_200K,
	CLOSE_POS_MUX,
	OPEN_POS_MUX,
	CLOSE_OUT_1,
	OPEN_OUT_1,
	CLOSE_OUT_2,
	OPEN_OUT_2,
	CLOSE_OUT_3,
	OPEN_OUT_3,
	CLOSE_OUT_4,
	OPEN_OUT_4,
	CLOSE_OUT_5,
	OPEN_OUT_5,
	CLOSE_OUT_6,
	OPEN_OUT_6,
	CLOSE_OUT_7,
	OPEN_OUT_7,
	CLOSE_OUT_8,
	OPEN_OUT_8,
};

enum
{
	
	CLOSE_OAL					= CLOSE,
	OPEN_OAL					= OPEN,

	CLOSE_OAL_SERVO_LOOP		= CLOSE_SERVO_LOOP,			
	OPEN_OAL_SERVO_LOOP			= OPEN_SERVO_LOOP,			
	CLOSE_OAL_DAC_TO_INPUT		= CLOSE_DAC_TO_INPUT,			
	OPEN_OAL_DAC_TO_INPUT		= OPEN_DAC_TO_INPUT,			
	CLOSE_OAL_LOCAL_LOOP		= CLOSE_LOCAL_LOOP,			
	OPEN_OAL_LOCAL_LOOP			= OPEN_LOCAL_LOOP,			
	CLOSE_OAL_LOCAL_LOOP_10K	= CLOSE_LOCAL_LOOP_10K,		
	OPEN_OAL_LOCAL_LOOP_10K		= OPEN_LOCAL_LOOP_10K,		
	CLOSE_OAL_GND_POS_IN		= CLOSE_GND_POS_IN,			
	OPEN_OAL_GND_POS_IN			= OPEN_GND_POS_IN,			
	CLOSE_OAL_MEAS_V_IN_DIFF	= CLOSE_MEAS_V_IN_DIFF,		
	OPEN_OAL_MEAS_V_IN_DIFF		= OPEN_MEAS_V_IN_DIFF,		
	CLOSE_OAL_MEAS_V_OUT		= CLOSE_MEAS_V_OUT,			
	OPEN_OAL_MEAS_V_OUT			= OPEN_MEAS_V_OUT,			
	CLOSE_OAL_MEAS_I_IN			= CLOSE_MEAS_I_IN,			
	OPEN_OAL_MEAS_I_IN			= OPEN_MEAS_I_IN,				
	CLOSE_OAL_LCB_PRECHARGE		= CLOSE_LCB_PRECHARGE,		
	OPEN_OAL_LCB_PRECHARGE		= OPEN_LCB_PRECHARGE,			
	CLOSE_OAL_LOAD_SHORT		= CLOSE_LOAD_SHORT,			
	OPEN_OAL_LOAD_SHORT			= OPEN_LOAD_SHORT,			
	CLOSE_OAL_LOAD_600			= CLOSE_LOAD_600,				
	OPEN_OAL_LOAD_600			= OPEN_LOAD_600,				
	CLOSE_OAL_LOAD_1K			= CLOSE_LOAD_1K,				
	OPEN_OAL_LOAD_1K			= OPEN_LOAD_1K,				
	CLOSE_OAL_LOAD_2K			= CLOSE_LOAD_2K,				
	OPEN_OAL_LOAD_2K			= OPEN_LOAD_2K,				
	CLOSE_OAL_LOAD_4K7			= CLOSE_LOAD_4K7,				
	OPEN_OAL_LOAD_4K7			= OPEN_LOAD_4K7,				
	CLOSE_OAL_LOAD_10K			= CLOSE_LOAD_10K,				
	OPEN_OAL_LOAD_10K			= OPEN_LOAD_10K,				
	CLOSE_OAL_LOAD_100K			= CLOSE_LOAD_100K,			
	OPEN_OAL_LOAD_100K			= OPEN_LOAD_100K,				
	CLOSE_OAL_CONNECT_LOADS		= CLOSE_CONNECT_LOADS,		
	OPEN_OAL_CONNECT_LOADS		= OPEN_CONNECT_LOADS,			
	CLOSE_OAL_LOAD_REF_GND		= CLOSE_LOAD_REF_GND,			
	OPEN_OAL_LOAD_REF_GND		= OPEN_LOAD_REF_GND,			
	CLOSE_OAL_LOAD_REF_EXT		= CLOSE_LOAD_REF_EXT,			
	OPEN_OAL_LOAD_REF_EXT		= OPEN_LOAD_REF_EXT,			
	CLOSE_OAL_EXT_LOAD_CONN		= CLOSE_EXT_LOAD_CONN,		
	OPEN_OAL_EXT_LOAD_CONN		= OPEN_EXT_LOAD_CONN,			

	CLOSE_OAL_OUT_POL			= CLOSE_OUT_POL,					
	OPEN_OAL_OUT_POL			= OPEN_OUT_POL,					
	CLOSE_OAL_OUT_RNG_X4		= CLOSE_OUT_RNG_X4,				
	OPEN_OAL_OUT_RNG_X4			= OPEN_OUT_RNG_X4,				
	CLOSE_OAL_DAC_OUT			= CLOSE_DAC_OUT,					
	OPEN_OAL_DAC_OUT			= OPEN_DAC_OUT,					
	CLOSE_OAL_INT_CONN			= CLOSE_INT_CONN,					
	OPEN_OAL_INT_CONN			= OPEN_INT_CONN,					
	CLOSE_OAL_INT_RESET			= CLOSE_INT_RESET,				
	OPEN_OAL_INT_RESET			= OPEN_INT_RESET,					
	CLOSE_OAL_INT_SLOW			= CLOSE_INT_SLOW,					
	OPEN_OAL_INT_SLOW			= OPEN_INT_SLOW,					
	CLOSE_OAL_DC_GAIN			= CLOSE_DC_GAIN,					
	OPEN_OAL_DC_GAIN			= OPEN_DC_GAIN,					
	CLOSE_OAL_CLOSE_LOOP		= CLOSE_CLOSE_LOOP,				
	OPEN_OAL_CLOSE_LOOP			= OPEN_CLOSE_LOOP,				
	CLOSE_OAL_CLS_LOOP_IV		= CLOSE_CLS_LOOP_IV,				
	OPEN_OAL_CLS_LOOP_IV		= OPEN_CLS_LOOP_IV,				
	CLOSE_OAL_MLG_CON_POS		= CLOSE_MLG_CON_POS,				
	OPEN_OAL_MLG_CON_POS		= OPEN_MLG_CON_POS,				
	CLOSE_OAL_LLG_CON_POS		= CLOSE_LLG_CON_POS,				
	OPEN_OAL_LLG_CON_POS		= OPEN_LLG_CON_POS,				
	CLOSE_OAL_POS_LKG_X10		= CLOSE_POS_LKG_X10,				
	OPEN_OAL_POS_LKG_X10		= OPEN_POS_LKG_X10,				
	CLOSE_OAL_MLG_CON_NEG		= CLOSE_MLG_CON_NEG,				
	OPEN_OAL_MLG_CON_NEG		= OPEN_MLG_CON_NEG,				
	CLOSE_OAL_LLG_CON_NEG		= CLOSE_LLG_CON_NEG,				
	OPEN_OAL_LLG_CON_NEG		= OPEN_LLG_CON_NEG,				
	CLOSE_OAL_NEG_LKG_X10		= CLOSE_NEG_LKG_X10,				
	OPEN_OAL_NEG_LKG_X10		= OPEN_NEG_LKG_X10,				
	CLOSE_OAL_IA_POS_IN			= CLOSE_IA_POS_IN,				
	OPEN_OAL_IA_POS_IN			= OPEN_IA_POS_IN,					
	CLOSE_OAL_IA_NEG_IN			= CLOSE_IA_NEG_IN,		
	OPEN_OAL_IA_NEG_IN			= OPEN_IA_NEG_IN,			
	CLOSE_OAL_IA_OFF_100_MV		= CLOSE_IA_OFF_100_MV,	
	OPEN_OAL_IA_OFF_100_MV		= OPEN_IA_OFF_100_MV,		
	CLOSE_OAL_DUT_POS_ISOL		= CLOSE_DUT_POS_ISOL,		
	OPEN_OAL_DUT_POS_ISOL		= OPEN_DUT_POS_ISOL,		
	CLOSE_OAL_DUT_NEG_ISOL		= CLOSE_DUT_NEG_ISOL,		
	OPEN_OAL_DUT_NEG_ISOL		= OPEN_DUT_NEG_ISOL,		
	CLOSE_OAL_DUT_INP_SHORT		= CLOSE_DUT_INP_SHORT,	
	OPEN_OAL_DUT_INP_SHORT		= OPEN_DUT_INP_SHORT,		
	CLOSE_OAL_SHORT_FEEDBACK_RES= CLOSE_SHORT_FEEDBACK_RES,
	OPEN_OAL_SHORT_FEEDBACK_RES	= OPEN_SHORT_FEEDBACK_RES,
	CLOSE_OAL_FEEDBACK_TO_OUT	= CLOSE_FEEDBACK_TO_OUT,	
	OPEN_OAL_FEEDBACK_TO_OUT	= OPEN_FEEDBACK_TO_OUT,	
	CLOSE_OAL_IA_OFF_POL		= CLOSE_IA_OFF_POL,		
	OPEN_OAL_IA_OFF_POL			= OPEN_IA_OFF_POL,		
	CLOSE_OAL_DUT_POS_OUT		= CLOSE_DUT_POS_OUT,		
	OPEN_OAL_DUT_POS_OUT		= OPEN_DUT_POS_OUT,		
	CLOSE_OAL_DUT_NEG_OUT		= CLOSE_DUT_NEG_OUT,		
	OPEN_OAL_DUT_NEG_OUT		= OPEN_DUT_NEG_OUT,		
	CLOSE_OAL_DUT_TO_RMS		= CLOSE_DUT_TO_RMS,		
	OPEN_OAL_DUT_TO_RMS			= OPEN_DUT_TO_RMS,		
	CLOSE_OAL_DUT_OUT_OUT		= CLOSE_DUT_OUT_OUT,		
	OPEN_OAL_DUT_OUT_OUT		= OPEN_DUT_OUT_OUT,		
	CLOSE_OAL_LOAD				= CLOSE_LOAD,				
	OPEN_OAL_LOAD				= OPEN_LOAD,				
	CLOSE_OAL_HV_BUF_CONN		= CLOSE_HV_BUF_CONN,		
	OPEN_OAL_HV_BUF_CONN		= OPEN_HV_BUF_CONN,		
};

enum
{
	PV3_CURRENT,PV3_VOLTAGE,PV3_COMPENSATE,
};

enum
{
	NORMAL,FAST,SLOW,
};


extern int  dc_charge_lzb(short pin, float voltage_limit, long int timeout);
extern void assign_zener_lzb(short zener_pin, unsigned short bit);
extern void tag_zener_lzb(unsigned int dec_value, int site = -1);	
extern void set_clamp_lzb(short pin, float clamp_voltage, short mode = CLOSE);
extern void dc_force_lzb(short pin, float current, float voltage, unsigned short pulse_time ,short mode , float *res_ptr, int site = -1);
extern void do_zapping_lzb(float current, float voltage, unsigned short pulse_time ,short mode , sfloat *res_ptr);
extern int	dc_zap_lzb(short pin, float current, float voltage, float pulse_time, suint tag_list, short mode , bool err_if_is_greater_than, float par_limit); 
extern int	dc_zap_lzb(short pin, float current, float voltage, float pulse_time, suint tag_list, short mode , bool err_if_is_greater_than, float par_limit, sfloat *result, sfloat *result2=NULL, sfloat *zap_time=NULL);  
extern void dc_check_lzb(short pin, float current, float voltage, float meas_delay, short mode, sfloat *result); 
extern void zap_word_select_lzb(sfloat trim_value, suint zap_word, float *weight_list, unsigned int *word_list, int list_lenght, unsigned int *idx=NULL);

#define HVS_OUT_COM		HVS_NULL9


extern void set_hvs_hotswitch(short pin, bool current_hs, bool voltage_hs);	
extern void set_hotswitch(short pin, bool current_hs, bool voltage_hs);	





#define OFS_OUT_COM		OFS_NULL9



#define MVS_OUT_COM		MVS_NULL9



extern void set_dvi_range_fast_switch(short pin, bool delay_selected);






#ifdef DDD_32K
#define DDD_MEM_DEPTH 32767
#else
#ifdef DDD_128K
#define DDD_MEM_DEPTH 131071
#else
#define DDD_MEM_DEPTH 1048576
#endif
#endif

enum
{
	DDD_RETURN_AFTER_PATTERN_START, DDD_WAIT_PATTERN_END, DDD_LOOP_PATTERN
};

enum
{
	SHMOO_VCC, SHMOO_VIH, SHMOO_VIL, SHMOO_VREF, SHMOO_T1, SHMOO_T2, SHMOO_PERIOD, SHMOO_FREQ
};

class MS_DDD_Pattern
{
private:
	
	struct	ddd_pat_site_address
	{
		unsigned int				ddd_active_sites;					
		int							ddd_pat_start_address;				
		char						ddd_master_first_vector_string[9];	
		bool						ddd_enable_card[21];				
		bool						ddd_pat_loopable;					
		struct ddd_pat_site_address	*ddd_nextptr;						
		struct ddd_pat_site_address	*ddd_prevptr;						
	} ddd_pat_site_list;

	int		ddd_pat_lenght;				
	int		ddd_pat_end_loop_address;	

	struct	ddd_pin						
	{
		char			*ddd_pin_name;	
		int				ddd_pin_ref;	
		int				ddd_pin_order;	
		struct ddd_pin	*ddd_nextptr;	
		struct ddd_pin	*ddd_prevptr;	
	} ddd_pin_list;						

	
	
	
	

	struct	ddd_vect						
	{
		int				ddd_vect_number;	
		char			*ddd_vect_string;	
		bool			ddd_compare_vect;	
		char			*ddd_vect_label;	
		struct ddd_vect	*ddd_nextptr;		
		struct ddd_vect	*ddd_prevptr;		
		struct ddd_vect	*ddd_nexttagptr;	
		struct ddd_vect	*ddd_prevtagptr;	
		struct ddd_vect	*ddd_nextcompptr;	
		struct ddd_vect	*ddd_prevcompptr;	

	
	} ddd_vect_list;					

	ddd_vect		*ddd_last_vect_ptr;		

	ddd_vect		*ddd_tag_vect_list;	

	ddd_vect		*ddd_comp_vect_list;		
	ddd_vect		*ddd_last_comp_vect_ptr;

	char			*ddd_label_to_add;		

	unsigned int	card_receive_mask[21];
	
public:
	char *ddd_pat_name;								
	MS_DDD_Pattern();									
	~MS_DDD_Pattern();								
	void Set_Pattern_Name(const char *name);		
	void Add_Pin_Name(const char *name);			
	void Add_Vector(const char *vect);				
	int  Upload_Pattern(int pattern_address);		
	int  Make_Pattern_Loopable(ddd_pat_site_address *pat_site_address_ptr);	
	int  Get_Num_Pins();								
	void Tag_Vector(char *label);						
	void Restore_Pattern_Settings(void);
	
	void Run_Pattern(unsigned short pattern_mode, int start_displacement=-1, int stop_displacement=-1);	
	
	void Read_Pattern_Result(sint pass_fail, int *first_fail_address=NULL, int *first_fail_pin=NULL, char *entry_label=NULL, char *exit_label=NULL, int *fail_count=NULL, short pin_name=-1);	
	void Read_Dig_Cap_Vector(short pin_list, sulong read_word, char *entry_label, int displacement);				
	void Upload_Dig_Source_Vector(short pin_list, sulong write_word, char *entry_label, int displacement=0);		
	void Upload_Dig_Source_Vector(short pin_list, unsigned long write_word, char *entry_label, int displacement=0);	
	bool Read_Shmoo_Result(int pin, int s, char *entry_label, int &vector_number, int &ddd_memory_address, char &compare_char);
	int  GetDisplacement(char *label);	

};

extern int ddd_load_all_patterns(int pattern_address, bool expand_single_sites=false);
extern int ddd_load_all_patterns(STRING directory_name, int pattern_address, bool expand_single_sites=false);	
extern int ddd_load_pattern_list(STRING list_filename, int pattern_address, bool expand_single_sites=false);
extern int ddd_load_pattern (STRING filename, int pattern_address, bool expand_single_sites=false);
extern void ddd_set_levels(short pin, float vih, float vil, float vref);
extern void ddd_set_levels(short pin, float vih, float vil, double vref);	
extern void ddd_set_levels(short pin, float vih, double vil, float vref);	
extern void ddd_set_levels(short pin, float vih, double vil, double vref);	
extern void ddd_set_levels(short pin, double vih, float vil, float vref);	
extern void ddd_set_levels(short pin, double vih, float vil, double vref);	
extern void ddd_set_levels(short pin, double vih, double vil, float vref);	
extern void ddd_set_levels(short pin, double vih, double vil, double vref);	
extern void ddd_set_vih(short pin, float vih);
extern void ddd_set_vih(short pin, double vih);	
extern void ddd_set_vil(short pin, float vil);
extern void ddd_set_vil(short pin, double vil);	
extern void ddd_set_vref(short pin, float vref);
extern void ddd_set_vref(short pin, double vref);	
extern void ddd_get_vih(short pin_list, sfloat *vih_list);
extern void ddd_get_vih(short pin, sfloat vih);
extern void ddd_get_vil(short pin_list, sfloat *vil_list);
extern void ddd_get_vil(short pin, sfloat vil);
extern void ddd_get_vref(short pin, sfloat vref);
extern void ddd_get_vref(short pin_list, sfloat *vref_list);
extern void ddd_set_period(float period);
extern void ddd_set_period(double period);	
extern void ddd_get_period(float *period);
extern void ddd_set_frequency(float frequency);
extern void ddd_set_frequency(float frequency);	
extern void ddd_get_frequency(float *frequency);
extern void ddd_set_timings(short pin, double tg1, double tg2);	
extern void ddd_set_timings(short pin, float tg1, double tg2);	
extern void ddd_set_timings(short pin, double tg1, float tg2);	
extern void ddd_set_timings(short pin, float tg1, float tg2);
extern void ddd_get_timings(short pin, sfloat tg1, sfloat tg2);

extern void ddd_run_pattern(char *pattern_name, unsigned short pattern_mode=DDD_RETURN_AFTER_PATTERN_START, char *StartLabel=NULL, char *StopLabel=NULL);	
extern void ddd_stop_pattern(void);
extern void ddd_disconnect_drivers(bool disconnect_all=false);


extern void ddd_read_pattern_result(char *pattern_name, sbool pass_fail, sint first_fail_address=NULL, sint first_fail_pin=NULL, char *entry_label=NULL, char *exit_label=NULL, int *fail_count=NULL, short pin_name=-1);	
extern void ddd_read_pattern_result(char *pattern_name, sint pass_fail, sint first_fail_address=NULL, sint first_fail_pin=NULL, char *entry_label=NULL, char *exit_label=NULL, int *fail_count=NULL, short pin_name=-1);	
extern void ddd_dig_src(short pin_list, char *pattern_name, sulong src_data, char *entry_label, int displacement=0);		
extern void ddd_dig_src(short pin_list, char *pattern_name, unsigned long src_data, char *entry_label, int displacement=0);	
extern void ddd_dig_cap(short pin_list, char *pattern_name, sulong cap_data, char *entry_label, int displacement=0);		
extern void ddd_delete_all_patterns(void);
extern void ddd_shmoo(char *pattern_name, int site, char *entry_label, int pin1, short par1_type, float par1_start, float par1_stop, int par1_nsteps, int pin2=-1, short par2_type=NULL, float par2_start=NULL, float par2_stop=NULL, int par2_nsteps=NULL);


void vi_measure(short pin, short mode ,float *res_ptr ,short ave_num = 1, short d_range = NO_DIFF_RANGE, short wait_us=200);		


extern int Pin_Name_To_Pin_Ref(const char *pin_name);
extern int Pin_Ref_To_Pin_Name(short pin_ref, char *pin_name);










extern void create_s_wf(sdouble_wf MS_Array, unsigned int size);
extern void delete_s_wf(sdouble_wf MS_Array);












#ifndef LegacyXerxes
extern void xvi_arm(short pin_list, XviTrigType TrigAction=XVI_TRIG_IMMEDIATE, double TrigLevel=0, bool capture=true);	

extern void xvi_read_average(short pin, sdouble result);
extern void xvi_read_average(short pin_list, sdouble *result_ptr);
extern void xvi_read_average(short pin, sDouble result);
extern void xvi_read_average(short pin_list, sDouble *result_ptr);
extern int  xvi_read_capture(short pin, sdouble_wf site_capture);
extern int  xvi_read_capture(short pin_list, sdouble_wf *site_capture);


extern void xvi_sampling_setup(short pin_list, short num_samples, XviClockModeType=XVI_INT_CLOCK, double sampling_period_or_freqency=5.0e-6f, XviSamplingModeType sampling_mode=XVI_SET_PERIOD);

extern void xvi_sampling_setup(short pin_list, short num_samples, double sampling_period_or_freqency, XviSamplingModeType sampling_mode=XVI_SET_PERIOD);
extern void xvi_measure_filter(short pin_list, XviFilteringModeType filtering_mode=XVI_DISABLE_FILTER);

extern void xvi_force_current_pulse(short pin_list, double current, double voltage, double pulse_width=1.0e-3f, short c_range  = AUTORANGE,short v_range = AUTORANGE);	
extern void xvi_force_current_pulse(short pin_list, double current, sdouble voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE,short v_range = AUTORANGE);	
extern void xvi_force_current_pulse(short pin_list, sdouble current, double voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE,short v_range = AUTORANGE);	
extern void xvi_force_current_pulse(short pin_list, sdouble *current, sdouble *voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE,short v_range = AUTORANGE);
extern void xvi_force_current_pulse(short pin_list, double current, sdouble *voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE,short v_range = AUTORANGE);		
extern void xvi_force_current_pulse(short pin_list, sdouble *current, double voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE,short v_range = AUTORANGE);	
extern void xvi_force_current_pulse(short pin_list, sdouble current, sdouble voltage, double pulse_width=1.0e-3f, short c_range = AUTORANGE, short v_range = AUTORANGE);
extern XVI_ERROR_CODE_e xvi_set_voltage_mode(short pin_list, XVI_FORCE_VOLTAGE_MODE_e fv_mode, float settling_time = 70.0e-3f);	
#endif







extern void cbt_set_pull_voltage(short pin, unsigned short element);

#ifdef VISATE_5x
#ifndef CHAR

#define INCLUDE_ASL_UTIL_CPP
#include "../user_common/programs/asl_util.h"
#endif
#endif


extern int load_pinmap_file(STRING pinmapname);


#define EOW					our_handler->current->eow


#define SET_MAX_SITES		set_max_sites(our_handler->current->info->GetNumSites(),CSC_MAX_SITES)
#define GET_ACTIVE_SITES	get_active_sites(our_handler->current->active_sites,CSC_MAX_SITES)
#define RESET_ACTIVE_SITES	reset_active_sites()
#define NO_SITE_ACTIVE		no_site_active()
#define IS_SITE_ACTIVE		(active_site[site])





class SFLOAT {
	sfloat result;
public:
	SFLOAT();
	~SFLOAT();
	SFLOAT operator = (float value);
	SFLOAT operator = (class SFLOAT value);
	SFLOAT operator+=(float value);
	SFLOAT operator+= (class SFLOAT value);
	SFLOAT operator-=(float value);
	SFLOAT operator-= (class SFLOAT value);
	SFLOAT operator*=(float value);
	SFLOAT operator*= (class SFLOAT value);
	SFLOAT operator/=(float value);
	SFLOAT operator/= (class SFLOAT value);

	void init();
	void set_to(float* value);
	void set_to(float value, int site);
	float get_value(int site);
	float* get_value();
	void reciprocal();	
	float* fabs(SFLOAT value);
	float* fabs();
};



void GetSerialNum (STRING &sernumstr,int this_site);





extern	sint SerialBlockSiteBuffer;
extern	int site_;
#define BEGIN_SERIAL_BLOCK {\
store_site_status(SerialBlockSiteBuffer);\
for(site_ = 0; site_ < CSC_LAST_SITE; site_++) \
if(active_site[site_]){activate_one_site(site_);
#define  END_SERIAL_BLOCK  restore_site_status(SerialBlockSiteBuffer);}}
#define SITE site_

bool	MSdelay(double delay);	
short	get_pin_res_type(short pin, int site);		
char	get_pin_res_ver(short pin, int site);		




#define  V *(1.0)
#define mV *(1.0e-3)
#define uV *(1.0e-6)

#define  A *(1.0)
#define mA *(1.0e-3)
#define uA *(1.0e-6)
#define nA *(1.0e-9)
#ifndef pA
	#define pA *(1.0e-12)
#endif

#define  S *(1.0)
#define mS *(1.0e-3)
#define uS *(1.0e-6)
#define nS *(1.0e-9)

#define GHz *(1.0e9)
#define MHz *(1.0e6)
#define KHz *(1.0e3)
#define kHz *(1.0e3)
#define  Hz *(1.0)
#define mHz *(1.0e-3)
#define uHz *(1.0e-6)
#define nHz *(1.0e-9)

#define MW *(1.0e6)
#define KW *(1.0e3)
#define  W *(1.0)
#define mW *(1.0e-3)
#define uW *(1.0e-6)
#define nW *(1.0e-9)

#endif 






















