

 

 

 


 

 









 

 
 

 
 
 
 

 
 

 




            

 

 

 











  


 
 
 


 





 



















 











#pragma warning (disable : 4244)
#pragma warning (disable : 4800)

#ifndef ASL1K_NO_CBIT

#include ".\programs\multisite\CBits.h"	
CBits cbits;	
#endif


#include "Multisite_lib.h"

#define MAX_SITES 256		
#define MAX_SCOPE_SAMPLE	1000	



























struct OAL_Card
	{
	bool		   OAL_in_pin_map;		

	unsigned short	OAL_ia_os_dac_ch0[4];	
	int				OAL_ia_os_pol_ch0[4];	
	unsigned short	OAL_ia_os_rng_ch0[4];	
	float			OAL_ia_os_err_ch0[4];	
	bool			OAL_ia_os_cal_ch0[4];	
	unsigned short	OAL_ia_os_dac_ch1[4];	
	int				OAL_ia_os_pol_ch1[4];	
	unsigned short	OAL_ia_os_rng_ch1[4];	
	float			OAL_ia_os_err_ch1[4];	
	bool			OAL_ia_os_cal_ch1[4];	
	Oal				*card_ptr;				
	};

struct OAL_Card  OAL_Card_Used[21];

struct QAL_Card
	{
	bool		   QAL_in_pin_map;		

	unsigned short	QAL_ia_os_dac_ch0[4];
	int				QAL_ia_os_pol_ch0[4];	
	unsigned short	QAL_ia_os_rng_ch0[4];
	float			QAL_ia_os_err_ch0[4];	
	bool			QAL_ia_os_cal_ch0[4];
	unsigned short	QAL_ia_os_dac_ch1[4];
	int				QAL_ia_os_pol_ch1[4];
	unsigned short	QAL_ia_os_rng_ch1[4];	
	float			QAL_ia_os_err_ch1[4];	
	bool			QAL_ia_os_cal_ch1[4];	
	unsigned short	QAL_ia_os_dac_ch2[4];	
	int				QAL_ia_os_pol_ch2[4];	
	unsigned short	QAL_ia_os_rng_ch2[4];	
	float			QAL_ia_os_err_ch2[4];	
	bool			QAL_ia_os_cal_ch2[4];	
	unsigned short	QAL_ia_os_dac_ch3[4];
	int				QAL_ia_os_pol_ch3[4];	
	unsigned short	QAL_ia_os_rng_ch3[4];
	float			QAL_ia_os_err_ch3[4];
	bool			QAL_ia_os_cal_ch3[4];
	Qal				*card_ptr;			
	};

struct QAL_Card  QAL_Card_Used[21];















bool	debug_ddd_msl_offline=false;
bool	debug_xvi_msl_offline=false;

struct DDD_Card
{
	float			Vih;					
	float			Vil;					
	float			Vref;					
	float			tg1[8];						
	float			tg2[8];						
	float			clock_freq;				
	char			vector_string[9];		
	unsigned int	card_receive_mask;		
	unsigned int	card_read_back;				
	Ddd				*card_ptr;				
	bool			enable;					
	bool			flag;						
	bool			timings_program_due;	
	int				ddd_pat_end_loop_address;
};

DDD_Card  DDD_Card_Used[21];

struct ACS_Card
{
	float	Vpeak;
	float	Voffset;
	int		ClkDivider;
	Acs		*card_ptr;
};

struct ACS_Card  ACS_Card_Used[21];

struct DVI_Card
{
	bool	block_programming;
	Dvi		*card_ptr;
	UINT16  awg_channel_mask;
};

struct DVI_Card  DVI_Card_Used[21];








#ifndef	LegacyXerxes
struct XVI_Card

{
	UINT16		arm_mask;		
	bool		card_arm_due;			
	bool		card_armed;				
	bool		bank_0_enabled;		
	bool		bank_1_enabled;		
	Xvi			*card_ptr;				
	bool		sw_trigger;				
	float		time_stamp_sw_trig;		
	float		measurement_duration;	
	double		samples[14][2048];	
		
	UINT16		force_mask;			
	UINT16		connect_mask;		
	bool		init_due;				
	float		block_current;		
	float		block_voltage;		
	double		block_irng;			
	double		block_vrng;				
	bool		block_programming;	
	bool		block_initialized;	
	bool		fv_due;					
};

struct XVI_Card  XVI_Card_Used[21];

struct OV2_Card
{
	bool	block_programming[2];
	Ov2		*card_ptr;			
	UINT16  awg_channel_mask;
	BYTE    original_measure_index;
};

struct OV2_Card  OV2_Card_Used[21];

struct HVS_Card
{
	bool	block_programming;
	Hvs		*card_ptr;		
	UINT16  awg_channel_mask;
};

struct HVS_Card  HVS_Card_Used[21];

struct OFS_Card
{
	bool	block_programming;
	Ofs		*card_ptr;		
	UINT16  awg_channel_mask;
};

struct OFS_Card  OFS_Card_Used[21];

struct PVI_Card
{
	bool	block_programming;
	Pv3		*card_ptr;		
	UINT16  awg_channel_mask;
};

struct PVI_Card  PVI_Card_Used[21];

struct OVI_Card
{
	bool	block_programming;
	Ovi		*card_ptr;				
};

struct OVI_Card  OVI_Card_Used[21];

CMicroTimer XVI_Timer;

#endif




void initialize_cal_data(void)
{
	int slot;

	for (slot=0;slot>21;slot++)
	{
		int range;
		OAL_Card_Used[21].OAL_in_pin_map=false;	
		for(range=0;range<4;range++)
		{
			OAL_Card_Used[slot].OAL_ia_os_dac_ch0[range]=0;
			OAL_Card_Used[slot].OAL_ia_os_pol_ch0[range]=1;
			OAL_Card_Used[slot].OAL_ia_os_rng_ch0[range]=RANGE_10_MV;
			OAL_Card_Used[slot].OAL_ia_os_err_ch0[range]=0;
			OAL_Card_Used[slot].OAL_ia_os_cal_ch0[range]=false;
			OAL_Card_Used[slot].OAL_ia_os_dac_ch1[range]=0;
			OAL_Card_Used[slot].OAL_ia_os_pol_ch1[range]=1;
			OAL_Card_Used[slot].OAL_ia_os_rng_ch1[range]=RANGE_10_MV;
			OAL_Card_Used[slot].OAL_ia_os_err_ch1[range]=0;
			OAL_Card_Used[slot].OAL_ia_os_cal_ch1[range]=false;
		}
		
	
	}

	for (slot=0;slot>21;slot++)
	{
		int range;
		QAL_Card_Used[21].QAL_in_pin_map=false;	
		for(range=0;range<4;range++)
		{
			QAL_Card_Used[slot].QAL_ia_os_dac_ch0[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_pol_ch0[range]=1;
			QAL_Card_Used[slot].QAL_ia_os_rng_ch0[range]=RANGE_10_MV;
			QAL_Card_Used[slot].QAL_ia_os_err_ch0[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_cal_ch0[range]=false;
			QAL_Card_Used[slot].QAL_ia_os_dac_ch1[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_pol_ch1[range]=1;
			QAL_Card_Used[slot].QAL_ia_os_rng_ch1[range]=RANGE_10_MV;
			QAL_Card_Used[slot].QAL_ia_os_err_ch1[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_cal_ch1[range]=false;
			QAL_Card_Used[slot].QAL_ia_os_dac_ch2[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_pol_ch2[range]=1;
			QAL_Card_Used[slot].QAL_ia_os_rng_ch2[range]=RANGE_10_MV;
			QAL_Card_Used[slot].QAL_ia_os_err_ch2[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_cal_ch2[range]=false;
			QAL_Card_Used[slot].QAL_ia_os_dac_ch3[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_pol_ch3[range]=1;
			QAL_Card_Used[slot].QAL_ia_os_rng_ch3[range]=RANGE_10_MV;
			QAL_Card_Used[slot].QAL_ia_os_err_ch3[range]=0;
			QAL_Card_Used[slot].QAL_ia_os_cal_ch3[range]=false;
		}
		
		
	}
}



struct DVI_Pin
	{
	bool is_filter;
	Dvi *DVI_slot;
	unsigned short DVI_channel;
	DVI_CH_ID_e	DVI_channel_ID;
	};

struct OVI_Pin
	{
	Ovi *OVI_slot;
	unsigned short OVI_channel;
	};

struct HVS_Pin
	{
	Hvs *HVS_slot;
	unsigned short HVS_channel;
	};

struct OFS_Pin
	{
	Ofs *OFS_slot;
	unsigned short OFS_channel;
	};

struct MVS_Pin
	{
	Mvs *MVS_slot;
	unsigned short MVS_channel;
	};

struct PVI_Pin
	{
	Pv3 *PVI_slot;
	unsigned short PVI_channel;
	};
unsigned short PVI_channel_idx;
unsigned short PVI_channel_high_force[] =  { PV3_HIGH_FORCE_1, PV3_HIGH_FORCE_2, PV3_HIGH_FORCE_3, 
												PV3_HIGH_FORCE_4, PV3_HIGH_FORCE_5};

unsigned short PVI_channel_high_sense[] =  { PV3_HIGH_SENSE_1, PV3_HIGH_SENSE_2, PV3_HIGH_SENSE_3, 
												PV3_HIGH_SENSE_4, PV3_HIGH_SENSE_5};

unsigned short PVI_channel_low_force[] =  { PV3_LOW_FORCE_1, PV3_LOW_FORCE_2, PV3_LOW_FORCE_3, 
												PV3_LOW_FORCE_4, PV3_LOW_FORCE_5};

unsigned short PVI_channel_low_sense[] =  { PV3_LOW_SENSE_1, PV3_LOW_SENSE_2, PV3_LOW_SENSE_3, 
												PV3_LOW_SENSE_4, PV3_LOW_SENSE_5};

struct MUX_Pin
	{
	Mux *MUX_slot;
	unsigned short MUX_channel;
	};

struct CBT_Pin
	{
	CBit *CBT_slot;
	unsigned short CBT_unit;
	char *CBT_channel_str;
	};

struct CBIT_Pin	
	{
	unsigned short CBIT_channel;
	};

struct TMU_Pin
	{
	Tmu *TMU_slot;
	unsigned short TMU_channel;
	};

struct QTMU1_Pin
	{
	QTmu1 *QTMU1_slot;
	unsigned short QTMU1_unit;
	unsigned short QTMU1_channel;
	};

struct LZB_Pin
	{
	Lzb *LZB_slot;
	unsigned short LZB_channel;
	unsigned short LZB_channel_2;
	};

struct OAL_Pin
	{
	Oal *OAL_slot;
	unsigned short OAL_channel;			

	











	};

struct Oal_Load{
	float			val;
	unsigned short	load_rly;
	};

struct Oal_Load Oal_Load_Used[64];
bool	Oal_Load_Calc_Due=true;

struct QAL_Pin
	{
	Qal *QAL_slot;
	unsigned short QAL_channel;			

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	};

struct Qal_Load{
	float			val;
	unsigned short	load_rly;
	};

struct Qal_Load Qal_Load_Used[64];
bool	Qal_Load_Calc_Due=true;

struct ACS_Pin
	{
	Acs *ACS_slot;
	unsigned short ACS_channel;
	};

struct DDD_Pin
	{
	Ddd *DDD_slot;
	unsigned short DDD_channel;
	};	

#ifndef	LegacyXerxes
struct XVI_Pin
	{
	Xvi				*XVI_slot;
	XVI_CH_ID_e		XVI_channel;
	unsigned short	XVI_ch_index;
	};	
#endif

struct OV2_Pin
	{
	bool is_filter;
	Ov2 *OV2_slot;
	unsigned short OV2_channel;
	OV2_CH_ID_e	OV2_channel_ID;
	};


#ifndef POWER_FREQ_60Hz
	const float CSC_POWER_FREQ=50.0;
#else
	const float CSC_POWER_FREQ=60.0
#endif

#define UNUSED_LZB_MUX_PIN 999
#define LZB_RELAY_SETUP_DELAY	2

struct Pin_Type
	{
	unsigned short Pin_Ref;
	char	 	   Pin_Name[50];
	char           Channel_Name[20];
	unsigned short Site_Num;
	unsigned short Board_Ref;
	unsigned short Slot;
	unsigned short Unit; 
	unsigned short Channel; 
	unsigned short Channel_2; 
	char           Channel_str[10]; 
	PinClassType   PinClass;  
	};




#define DYN_GROUP_LIST		struct group_info


 struct group_info
	{
	int grouppin;
	DYN_GROUP_LIST *nextptr;
	};


DYN_GROUP_LIST *reserve_ptr()
{
	DYN_GROUP_LIST *ptr;

	ptr = (DYN_GROUP_LIST*) malloc(sizeof(DYN_GROUP_LIST));
	if (ptr == NULL)
		MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	return (ptr);
}


void attach_element(DYN_GROUP_LIST **headptr,int a_pin)
{
	DYN_GROUP_LIST *dummyptr;

	dummyptr = reserve_ptr();
	dummyptr->grouppin = a_pin;
	dummyptr->nextptr = *headptr;
	*headptr=dummyptr;
}


void copy_list(DYN_GROUP_LIST **targetptr,DYN_GROUP_LIST *sourceptr)
{
	if (sourceptr != NULL) {
		do
		{
			attach_element(targetptr,sourceptr->grouppin);
			sourceptr = sourceptr->nextptr;
		} while (sourceptr != NULL);
	}
}


void free_list(DYN_GROUP_LIST **headptr)
{
	DYN_GROUP_LIST *dummyptr;

	if (*headptr != NULL) {
		do
		{
			dummyptr = (*headptr)->nextptr;
			free(*headptr);
			*headptr = dummyptr;
		} while (*headptr != NULL);
	}
}


int sizeof_list(DYN_GROUP_LIST *headptr)
{
	int counter = 0;

	while (headptr != NULL) {
		headptr = headptr->nextptr;
		counter++;
	}
	return (counter);
}


struct Group_Type
	{
	unsigned short Group_Ref;
	char	 	   Group_Name[50];

	DYN_GROUP_LIST *Pins_belong_to_Group;
	};



struct DVI_Pin  DVI_Used[MAX_SITES]={
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
};
struct OVI_Pin  OVI_Used[MAX_SITES];
struct HVS_Pin  HVS_Used[MAX_SITES];
struct OFS_Pin  OFS_Used[MAX_SITES];
struct MVS_Pin  MVS_Used[MAX_SITES];
struct PVI_Pin  PVI_Used[MAX_SITES];
struct MUX_Pin  MUX_Used[MAX_SITES];
struct CBT_Pin  CBT_Used[MAX_SITES];
struct CBIT_Pin CBIT_Used[MAX_SITES];
struct TMU_Pin  TMU_Used[MAX_SITES];
struct QTMU1_Pin  QTMU1_Used[MAX_SITES];
struct LZB_Pin  LZB_Used[MAX_SITES];	
struct OAL_Pin  OAL_Used[MAX_SITES];
struct QAL_Pin  QAL_Used[MAX_SITES];	
struct ACS_Pin  ACS_Used[MAX_SITES];	
struct DDD_Pin  DDD_Used[MAX_SITES];
#ifndef	LegacyXerxes
struct XVI_Pin  XVI_Used[MAX_SITES];	
#endif
struct OV2_Pin  OV2_Used[MAX_SITES]={
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
	{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},{true},
};	
DYN_GROUP_LIST *lzb_zener_list;		
DYN_GROUP_LIST *lzb_fuse_list[MAX_SITES];	

struct Pin_Type Pin_Type_Used[MAX_PIN_USED][MAX_SITES];

short  List_all_pin[MAX_PIN_USED];
Group_Type List_all_group[MAX_GROUP_USED];

DYN_GROUP_LIST *single_pin;

void  dvi_setup(short pin_sel,int site, FILE *file_debug, FILE *file_debug_relay,char *notes=" ");
void  ovi_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");
void  mux_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");
void  cbt_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");
void  tmu_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");
void  qtmu1_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");
void  cbit_setup(short pin_sel,int site, FILE *file_debug,char *notes=" "); 
void  hvs_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");  
void  ofs_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");  
void  mvs_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");  
void  pvi_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");  
void  oal_setup(short pin_sel,int site, FILE *file_debug, FILE *file_debug_relay, char *notes=" "); 
void  qal_setup(short pin_sel,int site, FILE *file_debug, FILE *file_debug_relay, char *notes=" "); 
void  acs_setup(short pin_sel,int site, FILE *file_debug, char *notes=" ");  
void  lzb_setup(short pin_sel,int site, FILE *file_debug, char *notes=" ");  
#ifndef	LegacyXerxes
void xvi_setup(short pin_sel,int site,FILE *file_debug, char *notes=" ");  
#endif
void  ov2_setup(short pin_sel,int site, FILE *file_debug,char *notes=" ");

unsigned short max_sites=0;			
unsigned short pinmap_max_sites=0;
unsigned short CSC_LAST_SITE=0;		
bool debugger_on_flag;			
bool continue_on_fail_flag=false;	

short pin_selection_(short pin_name, int site,short *pin_sel);
short pin_selection(short pin, int site);

DYN_GROUP_LIST *group_selection(short group_name);
BOOL device_passed[MAX_SITES];	
BOOL active_site[MAX_SITES];
BOOL store_active_site[MAX_SITES];	  
BOOL current_active_site[MAX_SITES]; 

STRING file_path;
STRING &GetUserString( char * strname ); 

Text_box mytext;
int pin_inserted;
int group_inserted;

int int_serial_num_old = -1;






void dc_connect(short pin, short mode)
{
	int					i;
	short				Source_type;


	DYN_GROUP_LIST		*pin_ptr;
	DYN_GROUP_LIST		*start_pin_ptr;	
	
#ifndef	LegacyXerxes

	int					slot;
	bool				xvi_any_cards_used			= false;	
	char				ErrorMessage[100];
	XVI_ERROR_CODE_e	XviRetError					= XVI_EC_NO_ERROR_INFO;
	BOOL				status_relay_s, 
						status_relay_f, 
						status_relay_ds0, 
						status_relay_ds1, 
						status_relay_sb;


	for(slot=0; slot<21;slot++)
	{
		XVI_Card_Used[slot].connect_mask		= 0x0;
		XVI_Card_Used[slot].block_programming	= true;
	}

#endif





	start_pin_ptr = group_selection(pin);
	pin_ptr = start_pin_ptr;


#ifndef	LegacyXerxes


	do
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
				if	(
					(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)&&
						(
						(mode==CLOSE)||
						(mode==CLOSE_M)||
						(mode==CLOSE_GND_SNS)||
						(mode==OPEN)||
						(mode==OPEN_M)||
						(mode==OPEN_GND_SNS)
						)
					)
				
				{
					
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].connect_mask|=(UINT16)XVI_Used[i].XVI_channel;

					if(!xvi_any_cards_used)
						xvi_any_cards_used=true;
				}
				else
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				break;
			}
		}

	}
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);

	
	if(xvi_any_cards_used)
	for(slot=0; slot<21;slot++)	if((XVI_Card_Used[slot].connect_mask!=0x0)&&(XVI_Card_Used[slot].block_programming))
	{
		switch (mode)
		{
		case CLOSE:
if(!debug_xvi_msl_offline)	
			XVI_Card_Used[slot].card_ptr->connect_channels(XVI_Card_Used[slot].connect_mask);
			break;
		case CLOSE_M:
if(!debug_xvi_msl_offline)	
			XVI_Card_Used[slot].card_ptr->enable_voltmeter_mode_mask(XVI_Card_Used[slot].connect_mask);	
			break;
		case CLOSE_GND_SNS:
			status_relay_ds0	= ((XVI_Card_Used[slot].card_ptr->card.xvi_image_dut_sense_relay)>>14)&0x1;
			status_relay_ds1	= ((XVI_Card_Used[slot].card_ptr->card.xvi_image_dut_sense_relay)>>15)&0x1;
			if((XVI_Card_Used[slot].connect_mask & 0x007F)!=0)
				if(!status_relay_ds0)
if(!debug_xvi_msl_offline)	
					XVI_Card_Used[slot].card_ptr->connect_dut_sense0();
			if((XVI_Card_Used[slot].connect_mask & 0x3F80)!=0)	
				if(!status_relay_ds1)
if(!debug_xvi_msl_offline)	
					XVI_Card_Used[slot].card_ptr->connect_dut_sense1();
			break;
		case OPEN:
if(!debug_xvi_msl_offline)	
			XVI_Card_Used[slot].card_ptr->disconnect_channels(XVI_Card_Used[slot].connect_mask);
			break;
		case OPEN_M:
if(!debug_xvi_msl_offline)	
			XVI_Card_Used[slot].card_ptr->disable_voltmeter_mode_mask(XVI_Card_Used[slot].connect_mask);	
			break;
		case OPEN_GND_SNS:
			status_relay_ds0	= ((XVI_Card_Used[slot].card_ptr->card.xvi_image_dut_sense_relay)>>14)&0x1;
			status_relay_ds1	= ((XVI_Card_Used[slot].card_ptr->card.xvi_image_dut_sense_relay)>>15)&0x1;
			if((XVI_Card_Used[slot].connect_mask & 0x007F)!=0)	
				if(status_relay_ds0)
if(!debug_xvi_msl_offline)	
					XVI_Card_Used[slot].card_ptr->disconnect_dut_sense0();
			if((XVI_Card_Used[slot].connect_mask & 0x3F80)!=0)	
				if(status_relay_ds1)
if(!debug_xvi_msl_offline)	
					XVI_Card_Used[slot].card_ptr->disconnect_dut_sense1();
			break;
		default:
			{
			sprintf(ErrorMessage, "dc_connect() - You should never get here!\n");
			printf(ErrorMessage);
			mytext.text_in_box(40,10,ErrorMessage);
			}
		}
	} 

	pin_ptr = start_pin_ptr;

#endif

	do
	{


	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case DVI:
				if (DVI_Used[i].DVI_channel==DVI_CHANNEL_0)
				{
					switch (mode)
					{
					case CLOSE:
						DVI_Used[i].DVI_slot->close_relay(CONN_SENSE0);
						DVI_Used[i].DVI_slot->close_relay(CONN_FORCE0);
						break;
					case CLOSE_S:
						DVI_Used[i].DVI_slot->close_relay(CONN_SENSE0);
						break;
					case CLOSE_F:
						DVI_Used[i].DVI_slot->close_relay(CONN_FORCE0);
						break;
					case CLOSE_M:
						DVI_Used[i].DVI_slot->close_relay(CONN_MEAS0);
						break;
					case CLOSE_G:
						DVI_Used[i].DVI_slot->close_relay(GUARD_0);
						break;
					case CLOSE_BUS:
						DVI_Used[i].DVI_slot->close_relay(BUS_SENSE0);
						DVI_Used[i].DVI_slot->close_relay(BUS_FORCE0);
						break;
					case CLOSE_BUS_F:	
						DVI_Used[i].DVI_slot->close_relay(BUS_FORCE0);
						break;
					case CLOSE_BUS_S:		
						DVI_Used[i].DVI_slot->close_relay(BUS_SENSE0);
						break;
#ifndef	LegacyVATE522
					case CLOSE_BUS_M:	
						if(DVI_Used[i].DVI_slot->nvram_info.revision[0]=='H')
							DVI_Used[i].DVI_slot->close_relay(BUS_MEAS0);
						else
							mytext.text_in_box(40,10,"CLOSE_BUS_M valid for DVI2000 only!");
						break;
#endif
					case CLOSE_CH_SHORT:
						DVI_Used[i].DVI_slot->close_relay(CHANNEL_SHORT);
						break;
					case CLOSE_MOD		:
						DVI_Used[i].DVI_slot->close_relay(MOD_CHAN0);
						break;
					case CLOSE_FS_RES:
						DVI_Used[i].DVI_slot->close_relay(DVI_RES_FS0);
						break;
					case OPEN:
						DVI_Used[i].DVI_slot->open_relay(CONN_FORCE0);
						DVI_Used[i].DVI_slot->open_relay(CONN_SENSE0);
						break;
					case OPEN_S:
						DVI_Used[i].DVI_slot->open_relay(CONN_SENSE0);
						break;
					case OPEN_F:
						DVI_Used[i].DVI_slot->open_relay(CONN_FORCE0);
						break;
					case OPEN_M:
						DVI_Used[i].DVI_slot->open_relay(CONN_MEAS0);
						break;
					case OPEN_G:
						DVI_Used[i].DVI_slot->open_relay(GUARD_0);	
						break;
					case OPEN_CH_SHORT:
						DVI_Used[i].DVI_slot->open_relay(CHANNEL_SHORT);
						break;
					case OPEN_BUS:
						DVI_Used[i].DVI_slot->open_relay(BUS_FORCE0);
						DVI_Used[i].DVI_slot->open_relay(BUS_SENSE0);
						break;
					case OPEN_BUS_F:		
						DVI_Used[i].DVI_slot->open_relay(BUS_FORCE0);
						break;
					case OPEN_BUS_S:		
						DVI_Used[i].DVI_slot->open_relay(BUS_SENSE0);
						break;
#ifndef	LegacyVATE522
					case OPEN_BUS_M:	
						if(DVI_Used[i].DVI_slot->nvram_info.revision[0]=='H')
							DVI_Used[i].DVI_slot->open_relay(BUS_MEAS0);
						else
							mytext.text_in_box(40,10,"OPEN_BUS_M valid for DVI2000 only!");
						break;
#endif
					case OPEN_MOD		:
						DVI_Used[i].DVI_slot->open_relay(MOD_CHAN0);
						break;
					case OPEN_FS_RES:
						DVI_Used[i].DVI_slot->open_relay(DVI_RES_FS0);
						break;
					default:
						mytext.text_in_box(40,10,"Unknown DVI mode");
						exit(0);
					}
				}
				else
				{
					switch (mode)
					{
					case CLOSE:
						DVI_Used[i].DVI_slot->close_relay(CONN_SENSE1);
						DVI_Used[i].DVI_slot->close_relay(CONN_FORCE1);
						break;
					case CLOSE_S:
						DVI_Used[i].DVI_slot->close_relay(CONN_SENSE1);
						break;
					case CLOSE_F:
						DVI_Used[i].DVI_slot->close_relay(CONN_FORCE1);
						break;
					case CLOSE_M:
						DVI_Used[i].DVI_slot->close_relay(CONN_MEAS1);
						break;
					case CLOSE_G:
						DVI_Used[i].DVI_slot->close_relay(GUARD_1);		
						break;
					case CLOSE_BUS:
						DVI_Used[i].DVI_slot->close_relay(BUS_SENSE1);
						DVI_Used[i].DVI_slot->close_relay(BUS_FORCE1);
						break;
					case CLOSE_BUS_F:	
						DVI_Used[i].DVI_slot->close_relay(BUS_FORCE1);
						break;
					case CLOSE_BUS_S:	
						DVI_Used[i].DVI_slot->close_relay(BUS_SENSE1);
						break;
#ifndef	LegacyVATE522
					case CLOSE_BUS_M:	
						if(DVI_Used[i].DVI_slot->nvram_info.revision[0]=='H')
							DVI_Used[i].DVI_slot->close_relay(BUS_MEAS1);
						else
							mytext.text_in_box(40,10,"CLOSE_BUS_M valid for DVI2000 only!");
						break;
#endif
					case CLOSE_CH_SHORT:
						DVI_Used[i].DVI_slot->close_relay(CHANNEL_SHORT);
						break;
					case CLOSE_MOD		:
						DVI_Used[i].DVI_slot->close_relay(MOD_CHAN1);
						break;
					case CLOSE_FS_RES:
						DVI_Used[i].DVI_slot->close_relay(DVI_RES_FS1);
						break;
					case OPEN:
						DVI_Used[i].DVI_slot->open_relay(CONN_FORCE1);
						DVI_Used[i].DVI_slot->open_relay(CONN_SENSE1);
						break;
					case OPEN_S:
						DVI_Used[i].DVI_slot->open_relay(CONN_SENSE1);
						break;
					case OPEN_F:
						DVI_Used[i].DVI_slot->open_relay(CONN_FORCE1);
						break;
					case OPEN_M:
						DVI_Used[i].DVI_slot->open_relay(CONN_MEAS1);
						break;
					case OPEN_G:
						DVI_Used[i].DVI_slot->open_relay(GUARD_1);	
						break;
					case OPEN_CH_SHORT:
						DVI_Used[i].DVI_slot->open_relay(CHANNEL_SHORT);
						break;
					case OPEN_BUS:
						DVI_Used[i].DVI_slot->open_relay(BUS_FORCE1);
						DVI_Used[i].DVI_slot->open_relay(BUS_SENSE1);
						break;
					case OPEN_BUS_F:		
						DVI_Used[i].DVI_slot->open_relay(BUS_FORCE1);
						break;
					case OPEN_BUS_S:		
						DVI_Used[i].DVI_slot->open_relay(BUS_SENSE1);
						break;
#ifndef	LegacyVATE522
					case OPEN_BUS_M:		
						if(DVI_Used[i].DVI_slot->nvram_info.revision[0]=='H')
							DVI_Used[i].DVI_slot->open_relay(BUS_MEAS1);
						else
							mytext.text_in_box(40,10,"OPEN_BUS_M valid for DVI2000 only!");
						break;
#endif
					case OPEN_MOD		:	
						DVI_Used[i].DVI_slot->open_relay(MOD_CHAN1);
						break;
					case OPEN_FS_RES:
						DVI_Used[i].DVI_slot->open_relay(DVI_RES_FS1);
						break;
					default:
						mytext.text_in_box(40,10,"Unknown DVI mode");
						exit(0);
					}
				}

			break;
						

			case OVI:
			case OVI_S:
					switch (mode)
					{
					case CLOSE:
							OVI_Used[i].OVI_slot->connect(OVI_Used[i].OVI_channel);	
							break;
					case OPEN:
							OVI_Used[i].OVI_slot->disconnect(OVI_Used[i].OVI_channel);	
							break;
					default:
						mytext.text_in_box(40,10,"Unknown OVI mode");
						exit(0);
					}
			break;

#ifndef	LegacyXerxes
			case XVI:


		
				
					
				
					
					

				if(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==false)
				{
					status_relay_f		= ((XVI_Used[i].XVI_slot->card.xvi_image_force_relay)>>XVI_Used[i].XVI_ch_index)&0x1;
					status_relay_s		= ((XVI_Used[i].XVI_slot->card.xvi_image_sense_relay)>>XVI_Used[i].XVI_ch_index)&0x1;
					status_relay_ds0	= ((XVI_Used[i].XVI_slot->card.xvi_image_dut_sense_relay)>>14)&0x1;
					status_relay_ds1	= ((XVI_Used[i].XVI_slot->card.xvi_image_dut_sense_relay)>>15)&0x1;
					status_relay_sb		= ((XVI_Used[i].XVI_slot->card.xvi_image_sense_buffer_relay)>>XVI_Used[i].XVI_ch_index)&0x1;

					switch (mode)
					{
		
		
			
				
			


				
						
					


			
						case CLOSE_S:
							if(!status_relay_s)
if(!debug_xvi_msl_offline)	
								XVI_Used[i].XVI_slot->connect_sense(XVI_Used[i].XVI_channel);	
							break;
						case CLOSE_F:
							if(!status_relay_f)
if(!debug_xvi_msl_offline)	
								XVI_Used[i].XVI_slot->connect_force(XVI_Used[i].XVI_channel);	
							break;
						case CLOSE_BUF:
							if(!status_relay_f)
if(!debug_xvi_msl_offline)	
								XVI_Used[i].XVI_slot->connect_sense_buffer(XVI_Used[i].XVI_channel);	
							break;
				
	

						

						
				
			
				
		
					

	
				
				
				



			



	

		
	
						case OPEN_S:
if(!debug_xvi_msl_offline)	
							if(status_relay_s)
								XVI_Used[i].XVI_slot->disconnect_sense(XVI_Used[i].XVI_channel);	
							break;
						case OPEN_F:
							if(status_relay_f)
if(!debug_xvi_msl_offline)	
								XVI_Used[i].XVI_slot->disconnect_force(XVI_Used[i].XVI_channel);	
							break;
						case OPEN_BUF:
							if(status_relay_f)
if(!debug_xvi_msl_offline)	
								XVI_Used[i].XVI_slot->disconnect_sense_buffer(XVI_Used[i].XVI_channel);	
							break;
					
		
				
			

					
			
			
				
			



	
	
	



				
			
		
						default:
							mytext.text_in_box(40,10,"Unknown XVI mode");
							exit(0);
					}	
				}
			break;
#endif
						

			case HVS:			
					if ((mode == CLOSE)			|| 
						(mode == CLOSE_REF)		|| 
						(mode == CLOSE_REF1)	|| 
						(mode == CLOSE_REF2))
					{
						HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_POS_FS);
						HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_NEG_FS);
						if ((HVS_Used[i].HVS_channel == HVS_FORCE_POS) ||	
							(HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_COM))		
						{
							if (HVS_Used[i].HVS_channel != HVS_OUT_COM) 
								HVS_Used[i].HVS_slot->close_relay(HVS_Used[i].HVS_channel);

							if (HVS_Used[i].HVS_channel != HVS_FORCE_POS) 
								HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel");
							exit(0);
						}
						switch (mode)
						{
							case CLOSE:
								HVS_Used[i].HVS_slot->close_relay(HVS_NEG_FORCE);break;
							case CLOSE_REF:
								HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF1:
								HVS_Used[i].HVS_slot->close_relay(HVS_REF_1);
								HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF2:
								HVS_Used[i].HVS_slot->close_relay(HVS_REF_2);
								HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_REF_COM);break;
						}
					}
					else 

					if (mode == CLOSE_OUT_MUX) 
					{
						if ((HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_COM)||		
							(HVS_Used[i].HVS_channel == HVS_REF_1) ||		
							(HVS_Used[i].HVS_channel == HVS_REF_2))			
						{
							if (HVS_Used[i].HVS_channel != HVS_OUT_COM) 
								HVS_Used[i].HVS_slot->close_relay(HVS_Used[i].HVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel");
							exit(0);
						}
					}

					else
					if ((mode == CLOSE_KELVIN)		|| 		
						(mode == CLOSE_KELVIN1)		|| 
						(mode == CLOSE_KELVIN2))
					{
						if ((HVS_Used[i].HVS_channel == HVS_FORCE_POS) ||	
							(HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8))			
						{
							HVS_Used[i].HVS_slot->close_relay(HVS_FORCE_POS);
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_POS_OUT_COM);
							HVS_Used[i].HVS_slot->close_relay(HVS_NEG_FORCE);
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_REF_COM);
							if (HVS_Used[i].HVS_channel != HVS_FORCE_POS) 
								HVS_Used[i].HVS_slot->close_relay(HVS_Used[i].HVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case CLOSE_KELVIN1:
								HVS_Used[i].HVS_slot->close_relay(HVS_REF_1);break;
							case CLOSE_KELVIN2:
								HVS_Used[i].HVS_slot->close_relay(HVS_REF_2);break;
						}
					}
					else 
					if ((mode == OPEN)			|| 
						(mode == OPEN_REF)		|| 
						(mode == OPEN_REF1)	|| 
						(mode == OPEN_REF2))
					{
						HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_POS_FS);
						HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_NEG_FS);
						if ((HVS_Used[i].HVS_channel == HVS_FORCE_POS) ||	
							(HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_COM))		
						{
							if (HVS_Used[i].HVS_channel != HVS_OUT_COM) 
								HVS_Used[i].HVS_slot->open_relay(HVS_Used[i].HVS_channel);

							if (HVS_Used[i].HVS_channel != HVS_FORCE_POS) 
								HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel");
							exit(0);
						}
						switch (mode)
						{
							case OPEN:
								HVS_Used[i].HVS_slot->open_relay(HVS_NEG_FORCE);break;
							case OPEN_REF:
								HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_REF_COM);break;
							case OPEN_REF1:
								HVS_Used[i].HVS_slot->open_relay(HVS_REF_1);
								HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_REF_COM);break;
							case OPEN_REF2:
								HVS_Used[i].HVS_slot->open_relay(HVS_REF_2);
								HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_REF_COM);break;
						}
					}
					else 
					if ((mode == OPEN_KELVIN)		|| 		
						(mode == OPEN_KELVIN1)		|| 
						(mode == OPEN_KELVIN2))
					{
						if ((HVS_Used[i].HVS_channel == HVS_FORCE_POS) ||	
							(HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8))			
						{
							HVS_Used[i].HVS_slot->open_relay(HVS_FORCE_POS);
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_POS_OUT_COM);
							HVS_Used[i].HVS_slot->open_relay(HVS_NEG_FORCE);
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_REF_COM);
							if (HVS_Used[i].HVS_channel != HVS_FORCE_POS) 
								HVS_Used[i].HVS_slot->open_relay(HVS_Used[i].HVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case OPEN_KELVIN1:
								HVS_Used[i].HVS_slot->open_relay(HVS_REF_1);break;
							case OPEN_KELVIN2:
								HVS_Used[i].HVS_slot->open_relay(HVS_REF_2);break;
						}
					}

					else
					if (mode == OPEN_OUT_MUX) 
					{
						if ((HVS_Used[i].HVS_channel == HVS_OUT_1) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_2) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_3) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_4) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_5) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_6) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_7) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_8) ||		
							(HVS_Used[i].HVS_channel == HVS_OUT_COM)||		
							(HVS_Used[i].HVS_channel == HVS_REF_1) ||		
							(HVS_Used[i].HVS_channel == HVS_REF_2))			
						{
							if (HVS_Used[i].HVS_channel != HVS_OUT_COM) 
								HVS_Used[i].HVS_slot->open_relay(HVS_Used[i].HVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid HVS channel");
							exit(0);
						}
					}

					else 
					{
						switch (mode)
						{
						case CLOSE_FS:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_POS_FS);
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_NEG_FS);break;
						
						case OPEN_FS:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_POS_FS);
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_NEG_FS);break;
						
						case CLOSE_FS_POS:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_POS_FS);break;
						
						case CLOSE_FS_NEG:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_NEG_FS);break;
						
						case OPEN_FS_POS:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_POS_FS);break;
						
						case OPEN_FS_NEG:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_NEG_FS);break;
						
						case CLOSE_GND_POS:
							HVS_Used[i].HVS_slot->close_relay(HVS_GND_POS_SENSE);break;
						
						case OPEN_GND_POS:
							HVS_Used[i].HVS_slot->open_relay(HVS_GND_POS_SENSE);break;
						
						case CLOSE_GND_NEG:
							HVS_Used[i].HVS_slot->close_relay(HVS_GND_NEG_SENSE);break;
						
						case OPEN_GND_NEG:
							HVS_Used[i].HVS_slot->open_relay(HVS_GND_NEG_SENSE);break;



						case CLOSE_REF1_MUX:		
							HVS_Used[i].HVS_slot->close_relay(HVS_REF_1);break;

						case OPEN_REF1_MUX:
							HVS_Used[i].HVS_slot->open_relay(HVS_REF_1);break;

						case CLOSE_REF2_MUX:
							HVS_Used[i].HVS_slot->close_relay(HVS_REF_2);break;

						case OPEN_REF2_MUX:
							HVS_Used[i].HVS_slot->open_relay(HVS_REF_2);break;

						case CLOSE_NEG_MUX:
							HVS_Used[i].HVS_slot->close_relay(HVS_NEG_FORCE);break;

						case OPEN_NEG_MUX:			
							HVS_Used[i].HVS_slot->open_relay(HVS_NEG_FORCE);break;

						case CLOSE_SENSE_POS_OUT_COM:
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_POS_OUT_COM);break;
						
						case OPEN_SENSE_POS_OUT_COM:
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_POS_OUT_COM);break;

						case CLOSE_SENSE_NEG_OUT_COM:
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_OUT_COM);break;
						
						case OPEN_SENSE_NEG_OUT_COM:
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_OUT_COM);break;

						case CLOSE_SENSE_POS_REF_COM:
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_POS_REF_COM);break;
						
						case OPEN_SENSE_POS_REF_COM:
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_POS_REF_COM);break;

						case CLOSE_SENSE_NEG_REF_COM:
							HVS_Used[i].HVS_slot->close_relay(HVS_SENSE_NEG_REF_COM);break;
						
						case OPEN_SENSE_NEG_REF_COM:
							HVS_Used[i].HVS_slot->open_relay(HVS_SENSE_NEG_REF_COM);break;

						case CLOSE_FS_10K:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_10K_FS);break;

						case OPEN_FS_10K:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_10K_FS);break;

						case CLOSE_FS_100K:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_100K_FS);break;
							
						case OPEN_FS_100K:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_100K_FS);break;
						
						case CLOSE_FS_200K:
							HVS_Used[i].HVS_slot->close_relay(HVS_SHORT_200K_FS);break;
							
						case OPEN_FS_200K:
							HVS_Used[i].HVS_slot->open_relay(HVS_SHORT_200K_FS);break;

						case CLOSE_POS_MUX:
							HVS_Used[i].HVS_slot->close_relay(HVS_FORCE_POS);break;

						case OPEN_POS_MUX:
							HVS_Used[i].HVS_slot->open_relay(HVS_FORCE_POS);break;

						case CLOSE_OUT_1:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_1);break;

						case OPEN_OUT_1:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_1);break;

						case CLOSE_OUT_2:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_2);break;

						case OPEN_OUT_2:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_2);break;

						case CLOSE_OUT_3:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_3);break;

						case OPEN_OUT_3:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_3);break;

						case CLOSE_OUT_4:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_4);break;

						case OPEN_OUT_4:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_4);break;

						case CLOSE_OUT_5:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_5);break;

						case OPEN_OUT_5:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_5);break;

						case CLOSE_OUT_6:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_6);break;

						case OPEN_OUT_6:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_6);break;

						case CLOSE_OUT_7:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_7);break;

						case OPEN_OUT_7:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_7);break;

						case CLOSE_OUT_8:
							HVS_Used[i].HVS_slot->close_relay(HVS_OUT_8);break;

						case OPEN_OUT_8:
							HVS_Used[i].HVS_slot->open_relay(HVS_OUT_8);break;

						default:
							mytext.text_in_box(40,10,"Unknown HVS mode");exit(0);
						}
					}
			break;	

			case OFS:		
					if ((mode == CLOSE)			|| 
						(mode == CLOSE_REF)		|| 
						(mode == CLOSE_REF1)	|| 
						(mode == CLOSE_REF2))
					{
						OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_POS_FS);
						OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_NEG_FS);
						if ((OFS_Used[i].OFS_channel == OFS_FORCE_POS) ||	
							(OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_COM))		
						{
							if (OFS_Used[i].OFS_channel != OFS_OUT_COM) 
								OFS_Used[i].OFS_slot->close_relay(OFS_Used[i].OFS_channel);

							if (OFS_Used[i].OFS_channel != OFS_FORCE_POS) 
								OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel");
							exit(0);
						}
						switch (mode)
						{
							case CLOSE:
								OFS_Used[i].OFS_slot->close_relay(OFS_NEG_FORCE);break;
							case CLOSE_REF:
								OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF1:
								OFS_Used[i].OFS_slot->close_relay(OFS_REF_1);
								OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF2:
								OFS_Used[i].OFS_slot->close_relay(OFS_REF_2);
								OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_REF_COM);break;
						}
					}
					else 

					if (mode == CLOSE_OUT_MUX) 
					{
						if ((OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_COM)||		
							(OFS_Used[i].OFS_channel == OFS_REF_1) ||		
							(OFS_Used[i].OFS_channel == OFS_REF_2))			
						{
							if (OFS_Used[i].OFS_channel != OFS_OUT_COM) 
								OFS_Used[i].OFS_slot->close_relay(OFS_Used[i].OFS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel");
							exit(0);
						}
					}

					else
					if ((mode == CLOSE_KELVIN)		|| 		
						(mode == CLOSE_KELVIN1)		|| 
						(mode == CLOSE_KELVIN2))
					{
						if ((OFS_Used[i].OFS_channel == OFS_FORCE_POS) ||	
							(OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8))			
						{
							OFS_Used[i].OFS_slot->close_relay(OFS_FORCE_POS);
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_POS_OUT_COM);
							OFS_Used[i].OFS_slot->close_relay(OFS_NEG_FORCE);
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_REF_COM);
							if (OFS_Used[i].OFS_channel != OFS_FORCE_POS) 
								OFS_Used[i].OFS_slot->close_relay(OFS_Used[i].OFS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case CLOSE_KELVIN1:
								OFS_Used[i].OFS_slot->close_relay(OFS_REF_1);break;
							case CLOSE_KELVIN2:
								OFS_Used[i].OFS_slot->close_relay(OFS_REF_2);break;
						}
					}
					else 
					if ((mode == OPEN)			|| 
						(mode == OPEN_REF)		|| 
						(mode == OPEN_REF1)	|| 
						(mode == OPEN_REF2))
					{
						OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_POS_FS);
						OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_NEG_FS);
						if ((OFS_Used[i].OFS_channel == OFS_FORCE_POS) ||	
							(OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_COM))		
						{
							if (OFS_Used[i].OFS_channel != OFS_OUT_COM) 
								OFS_Used[i].OFS_slot->open_relay(OFS_Used[i].OFS_channel);

							if (OFS_Used[i].OFS_channel != OFS_FORCE_POS) 
								OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel");
							exit(0);
						}
						switch (mode)
						{
							case OPEN:
								OFS_Used[i].OFS_slot->open_relay(OFS_NEG_FORCE);break;
							case OPEN_REF:
								OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_REF_COM);break;
							case OPEN_REF1:
								OFS_Used[i].OFS_slot->open_relay(OFS_REF_1);
								OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_REF_COM);break;
							case OPEN_REF2:
								OFS_Used[i].OFS_slot->open_relay(OFS_REF_2);
								OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_REF_COM);break;
						}
					}
					else 
					if ((mode == OPEN_KELVIN)		|| 		
						(mode == OPEN_KELVIN1)		|| 
						(mode == OPEN_KELVIN2))
					{
						if ((OFS_Used[i].OFS_channel == OFS_FORCE_POS) ||	
							(OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8))			
						{
							OFS_Used[i].OFS_slot->open_relay(OFS_FORCE_POS);
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_POS_OUT_COM);
							OFS_Used[i].OFS_slot->open_relay(OFS_NEG_FORCE);
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_REF_COM);
							if (OFS_Used[i].OFS_channel != OFS_FORCE_POS) 
								OFS_Used[i].OFS_slot->open_relay(OFS_Used[i].OFS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case OPEN_KELVIN1:
								OFS_Used[i].OFS_slot->open_relay(OFS_REF_1);break;
							case OPEN_KELVIN2:
								OFS_Used[i].OFS_slot->open_relay(OFS_REF_2);break;
						}
					}

					else
					if (mode == OPEN_OUT_MUX) 
					{
						if ((OFS_Used[i].OFS_channel == OFS_OUT_1) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_2) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_3) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_4) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_5) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_6) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_7) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_8) ||		
							(OFS_Used[i].OFS_channel == OFS_OUT_COM)||		
							(OFS_Used[i].OFS_channel == OFS_REF_1) ||		
							(OFS_Used[i].OFS_channel == OFS_REF_2))			
						{
							if (OFS_Used[i].OFS_channel != OFS_OUT_COM) 
								OFS_Used[i].OFS_slot->open_relay(OFS_Used[i].OFS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid OFS channel");
							exit(0);
						}
					}

					else 
					{
						switch (mode)
						{
						case CLOSE_FS:
							OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_POS_FS);
							OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_NEG_FS);break;
						
						case OPEN_FS:
							OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_POS_FS);
							OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_NEG_FS);break;
						
						case CLOSE_FS_POS:
							OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_POS_FS);break;
						
						case CLOSE_FS_NEG:
							OFS_Used[i].OFS_slot->close_relay(OFS_SHORT_NEG_FS);break;
						
						case OPEN_FS_POS:
							OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_POS_FS);break;
						
						case OPEN_FS_NEG:
							OFS_Used[i].OFS_slot->open_relay(OFS_SHORT_NEG_FS);break;
						
						case CLOSE_GND_POS:
							OFS_Used[i].OFS_slot->close_relay(OFS_GND_POS_SENSE);break;
						
						case OPEN_GND_POS:
							OFS_Used[i].OFS_slot->open_relay(OFS_GND_POS_SENSE);break;
						
						case CLOSE_GND_NEG:
							OFS_Used[i].OFS_slot->close_relay(OFS_GND_NEG_SENSE);break;
						
						case OPEN_GND_NEG:
							OFS_Used[i].OFS_slot->open_relay(OFS_GND_NEG_SENSE);break;



						case CLOSE_REF1_MUX:		
							OFS_Used[i].OFS_slot->close_relay(OFS_REF_1);break;

						case OPEN_REF1_MUX:
							OFS_Used[i].OFS_slot->open_relay(OFS_REF_1);break;

						case CLOSE_REF2_MUX:
							OFS_Used[i].OFS_slot->close_relay(OFS_REF_2);break;

						case OPEN_REF2_MUX:
							OFS_Used[i].OFS_slot->open_relay(OFS_REF_2);break;

						case CLOSE_NEG_MUX:
							OFS_Used[i].OFS_slot->close_relay(OFS_NEG_FORCE);break;

						case OPEN_NEG_MUX:			
							OFS_Used[i].OFS_slot->open_relay(OFS_NEG_FORCE);break;


						case CLOSE_SENSE_POS_OUT_COM:
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_POS_OUT_COM);break;
						
						case OPEN_SENSE_POS_OUT_COM:
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_POS_OUT_COM);break;

						case CLOSE_SENSE_NEG_OUT_COM:
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_OUT_COM);break;
						
						case OPEN_SENSE_NEG_OUT_COM:
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_OUT_COM);break;

						case CLOSE_SENSE_POS_REF_COM:
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_POS_REF_COM);break;
						
						case OPEN_SENSE_POS_REF_COM:
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_POS_REF_COM);break;

						case CLOSE_SENSE_NEG_REF_COM:
							OFS_Used[i].OFS_slot->close_relay(OFS_SENSE_NEG_REF_COM);break;
						
						case OPEN_SENSE_NEG_REF_COM:
							OFS_Used[i].OFS_slot->open_relay(OFS_SENSE_NEG_REF_COM);break;


						
						default:
							mytext.text_in_box(40,10,"Unknown OFS mode");exit(0);
						}
					}
			break;	

			case MVS:		
					if ((mode == CLOSE)			|| 
						(mode == CLOSE_REF)		|| 
						(mode == CLOSE_REF1)	|| 
						(mode == CLOSE_REF2))
					{
						MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_POS_FS);
						MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_NEG_FS);
						if ((MVS_Used[i].MVS_channel == MVS_FORCE_POS) ||	
							(MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_COM))		
						{
							if (MVS_Used[i].MVS_channel != MVS_OUT_COM) 
								MVS_Used[i].MVS_slot->close_relay(MVS_Used[i].MVS_channel);

							if (MVS_Used[i].MVS_channel != MVS_FORCE_POS) 
								MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel");
							exit(0);
						}
						switch (mode)
						{
							case CLOSE:
								MVS_Used[i].MVS_slot->close_relay(MVS_NEG_FORCE);break;
							case CLOSE_REF:
								MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF1:
								MVS_Used[i].MVS_slot->close_relay(MVS_REF_1);
								MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_REF_COM);break;
							case CLOSE_REF2:
								MVS_Used[i].MVS_slot->close_relay(MVS_REF_2);
								MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_REF_COM);break;
						}
					}
					else 

					if (mode == CLOSE_OUT_MUX) 
					{
						if ((MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_COM)||		
							(MVS_Used[i].MVS_channel == MVS_REF_1) ||		
							(MVS_Used[i].MVS_channel == MVS_REF_2))			
						{
							if (MVS_Used[i].MVS_channel != MVS_OUT_COM) 
								MVS_Used[i].MVS_slot->close_relay(MVS_Used[i].MVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel");
							exit(0);
						}
					}

					else
					if ((mode == CLOSE_KELVIN)		|| 		
						(mode == CLOSE_KELVIN1)		|| 
						(mode == CLOSE_KELVIN2))
					{
						if ((MVS_Used[i].MVS_channel == MVS_FORCE_POS) ||	
							(MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8))			
						{
							MVS_Used[i].MVS_slot->close_relay(MVS_FORCE_POS);
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_POS_OUT_COM);
							MVS_Used[i].MVS_slot->close_relay(MVS_NEG_FORCE);
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_REF_COM);
							if (MVS_Used[i].MVS_channel != MVS_FORCE_POS) 
								MVS_Used[i].MVS_slot->close_relay(MVS_Used[i].MVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case CLOSE_KELVIN1:
								MVS_Used[i].MVS_slot->close_relay(MVS_REF_1);break;
							case CLOSE_KELVIN2:
								MVS_Used[i].MVS_slot->close_relay(MVS_REF_2);break;
						}
					}
					else 
					if ((mode == OPEN)			|| 
						(mode == OPEN_REF)		|| 
						(mode == OPEN_REF1)	|| 
						(mode == OPEN_REF2))
					{
						MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_POS_FS);
						MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_NEG_FS);
						if ((MVS_Used[i].MVS_channel == MVS_FORCE_POS) ||	
							(MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_COM))		
						{
							if (MVS_Used[i].MVS_channel != MVS_OUT_COM) 
								MVS_Used[i].MVS_slot->open_relay(MVS_Used[i].MVS_channel);

							if (MVS_Used[i].MVS_channel != MVS_FORCE_POS) 
								MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_POS_OUT_COM);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel");
							exit(0);
						}
						switch (mode)
						{
							case OPEN:
								MVS_Used[i].MVS_slot->open_relay(MVS_NEG_FORCE);break;
							case OPEN_REF:
								MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_REF_COM);break;
							case OPEN_REF1:
								MVS_Used[i].MVS_slot->open_relay(MVS_REF_1);
								MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_REF_COM);break;
							case OPEN_REF2:
								MVS_Used[i].MVS_slot->open_relay(MVS_REF_2);
								MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_REF_COM);break;
						}
					}
					else 
					if ((mode == OPEN_KELVIN)		|| 		
						(mode == OPEN_KELVIN1)		|| 
						(mode == OPEN_KELVIN2))
					{
						if ((MVS_Used[i].MVS_channel == MVS_FORCE_POS) ||	
							(MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8))			
						{
							MVS_Used[i].MVS_slot->open_relay(MVS_FORCE_POS);
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_POS_OUT_COM);
							MVS_Used[i].MVS_slot->open_relay(MVS_NEG_FORCE);
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_REF_COM);
							if (MVS_Used[i].MVS_channel != MVS_FORCE_POS) 
								MVS_Used[i].MVS_slot->open_relay(MVS_Used[i].MVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel for Kelvin contact");
							exit(0);
						}

						switch (mode)
						{
							case OPEN_KELVIN1:
								MVS_Used[i].MVS_slot->open_relay(MVS_REF_1);break;
							case OPEN_KELVIN2:
								MVS_Used[i].MVS_slot->open_relay(MVS_REF_2);break;
						}
					}

					else
					if (mode == OPEN_OUT_MUX) 
					{
						if ((MVS_Used[i].MVS_channel == MVS_OUT_1) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_2) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_3) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_4) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_5) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_6) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_7) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_8) ||		
							(MVS_Used[i].MVS_channel == MVS_OUT_COM)||		
							(MVS_Used[i].MVS_channel == MVS_REF_1) ||		
							(MVS_Used[i].MVS_channel == MVS_REF_2))			
						{
							if (MVS_Used[i].MVS_channel != MVS_OUT_COM) 
								MVS_Used[i].MVS_slot->open_relay(MVS_Used[i].MVS_channel);
						}
						else
						{
							mytext.text_in_box(40,10,"invalid MVS channel");
							exit(0);
						}
					}

					else 
					{
						switch (mode)
						{
						case CLOSE_FS:
							MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_POS_FS);
							MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_NEG_FS);break;
						
						case OPEN_FS:
							MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_POS_FS);
							MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_NEG_FS);break;
						
						case CLOSE_FS_POS:
							MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_POS_FS);break;
						
						case CLOSE_FS_NEG:
							MVS_Used[i].MVS_slot->close_relay(MVS_SHORT_NEG_FS);break;
						
						case OPEN_FS_POS:
							MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_POS_FS);break;
						
						case OPEN_FS_NEG:
							MVS_Used[i].MVS_slot->open_relay(MVS_SHORT_NEG_FS);break;
						
						case CLOSE_GND_POS:
							MVS_Used[i].MVS_slot->close_relay(MVS_GND_POS_SENSE);break;
						
						case OPEN_GND_POS:
							MVS_Used[i].MVS_slot->open_relay(MVS_GND_POS_SENSE);break;
						
						case CLOSE_GND_NEG:
							MVS_Used[i].MVS_slot->close_relay(MVS_GND_NEG_SENSE);break;
						
						case OPEN_GND_NEG:
							MVS_Used[i].MVS_slot->open_relay(MVS_GND_NEG_SENSE);break;



						case CLOSE_REF1_MUX:		
							MVS_Used[i].MVS_slot->close_relay(MVS_REF_1);break;

						case OPEN_REF1_MUX:
							MVS_Used[i].MVS_slot->open_relay(MVS_REF_1);break;

						case CLOSE_REF2_MUX:
							MVS_Used[i].MVS_slot->close_relay(MVS_REF_2);break;

						case OPEN_REF2_MUX:
							MVS_Used[i].MVS_slot->open_relay(MVS_REF_2);break;

						case CLOSE_NEG_MUX:
							MVS_Used[i].MVS_slot->close_relay(MVS_NEG_FORCE);break;

						case OPEN_NEG_MUX:			
							MVS_Used[i].MVS_slot->open_relay(MVS_NEG_FORCE);break;

						case CLOSE_SENSE_POS_OUT_COM:
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_POS_OUT_COM);break;
						
						case OPEN_SENSE_POS_OUT_COM:
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_POS_OUT_COM);break;

						case CLOSE_SENSE_NEG_OUT_COM:
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_OUT_COM);break;
						
						case OPEN_SENSE_NEG_OUT_COM:
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_OUT_COM);break;

						case CLOSE_SENSE_POS_REF_COM:
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_POS_REF_COM);break;
						
						case OPEN_SENSE_POS_REF_COM:
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_POS_REF_COM);break;

						case CLOSE_SENSE_NEG_REF_COM:
							MVS_Used[i].MVS_slot->close_relay(MVS_SENSE_NEG_REF_COM);break;
						
						case OPEN_SENSE_NEG_REF_COM:
							MVS_Used[i].MVS_slot->open_relay(MVS_SENSE_NEG_REF_COM);break;


						
						default:
							mytext.text_in_box(40,10,"Unknown MVS mode");exit(0);
						}
					}
			break;	

			case PVI:	

				PVI_channel_idx=PVI_Used[i].PVI_channel;
				if (mode == CLOSE_HIGH)
				{	
					PVI_Used[i].PVI_slot->close_switch(PVI_channel_high_force[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->close_switch(PVI_channel_high_sense[PVI_channel_idx]); 

				} else
				if (mode == CLOSE_LOW)
				{
					PVI_Used[i].PVI_slot->close_switch(PVI_channel_low_force[PVI_channel_idx]);
					PVI_Used[i].PVI_slot->close_switch(PVI_channel_low_sense[PVI_channel_idx]);
						
				} else
				if (mode == OPEN)	
				{
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_high_force[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_high_sense[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_low_force[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_low_sense[PVI_channel_idx]); 
					
				} else
				if (mode == OPEN_HIGH)	
				{
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_high_force[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_high_sense[PVI_channel_idx]); 
					
				} else
				if (mode == OPEN_LOW)
				{
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_low_force[PVI_channel_idx]); 
					PVI_Used[i].PVI_slot->open_switch(PVI_channel_low_sense[PVI_channel_idx]); 
				}
				else	
				{
					mytext.text_in_box(40,10,"Unknown PVI mode");exit(0);
				}
			break;

			case LZB:			
				if (mode == OPEN)	
				{
					LZB_Used[i].LZB_slot->open_relay(LZB_CONN_GND);
					LZB_Used[i].LZB_slot->open_relay(LZB_CONN_OUT);				
				} else
				if (mode == CLOSE)	
				{
					LZB_Used[i].LZB_slot->close_relay(LZB_CONN_GND);
					LZB_Used[i].LZB_slot->close_relay(LZB_CONN_OUT);				
				} else
				{
					mytext.text_in_box(40,10,"dc_connect() - Unknown LZB mode");exit(0);
				}
			break;	

			case OAL:		
				if (mode == CLOSE)
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->close_relay(DUT_OUT_OUT);
						else
							OAL_Used[i].OAL_slot->close_relay(CH1_OUT_OUT);
						break;
					case PIN_IN_POS:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->close_relay(DUT_POS_OUT); 
						else
							OAL_Used[i].OAL_slot->close_relay(CH1_POS_OUT); 
						break;
					case PIN_IN_NEG:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->close_relay(DUT_NEG_OUT); 
						else
							OAL_Used[i].OAL_slot->close_relay(CH1_NEG_OUT); 
						break;
					case PIN_RMS:
						OAL_Used[i].OAL_slot->close_relay(OAL_Used[i].OAL_channel);
						break;
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Pin %s not recognized",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					} else
				if (mode == OPEN)
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->open_relay(DUT_OUT_OUT);
						else
							OAL_Used[i].OAL_slot->open_relay(CH1_OUT_OUT);
						break;
					case PIN_IN_POS:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->open_relay(DUT_POS_OUT); 
						else
							OAL_Used[i].OAL_slot->open_relay(CH1_POS_OUT); 
						break;
					case PIN_IN_NEG:
						if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->open_relay(DUT_NEG_OUT); 
						else
							OAL_Used[i].OAL_slot->open_relay(CH1_NEG_OUT); 
						break;
					case PIN_RMS:
						OAL_Used[i].OAL_slot->open_relay(OAL_Used[i].OAL_channel);
						break;
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Pin %s not recognized",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					} else
		
				if (mode == CLOSE_SERVO_LOOP)
				{
					OAL_Used[i].OAL_slot->open_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->close_switch(INT_CONN);
					OAL_Used[i].OAL_slot->close_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
					OAL_Used[i].OAL_slot->close_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->open_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == OPEN_SERVO_LOOP)
				{
					OAL_Used[i].OAL_slot->open_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->close_switch(INT_CONN);
					OAL_Used[i].OAL_slot->close_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->open_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == CLOSE_DAC_TO_INPUT)
				{
					OAL_Used[i].OAL_slot->close_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->open_switch(INT_CONN);
					OAL_Used[i].OAL_slot->close_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
					OAL_Used[i].OAL_slot->close_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->open_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->open_relay(HV_BUF_CONN);
				} else
				if (mode == OPEN_DAC_TO_INPUT)
				{
					OAL_Used[i].OAL_slot->open_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->close_switch(INT_CONN);
					OAL_Used[i].OAL_slot->close_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->open_switch(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->open_switch(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == CLOSE_LOCAL_LOOP)
				{
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_switch(CLS_LOOP_IV);
					OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
					OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
					OAL_Used[i].OAL_slot->close_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->close_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == OPEN_LOCAL_LOOP)
				{
					OAL_Used[i].OAL_slot->open_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == CLOSE_LOCAL_LOOP_10K)
				{
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_switch(CLS_LOOP_IV);
					OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
					OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
					OAL_Used[i].OAL_slot->close_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == OPEN_LOCAL_LOOP_10K)
				{
					OAL_Used[i].OAL_slot->open_relay(FEEDBACK_TO_OUT);
					OAL_Used[i].OAL_slot->open_relay(SHORT_FEEDBACK_RES);
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);
				} else
				if (mode == CLOSE_GND_POS_IN)
				{
					OAL_Used[i].OAL_slot->close_switch(IA_POS_IN);
					OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
				} else
				if (mode == OPEN_GND_POS_IN)
				{
					OAL_Used[i].OAL_slot->open_switch(IA_POS_IN);
					OAL_Used[i].OAL_slot->open_relay(DUT_POS_ISOL);
				} else
				if (mode == CLOSE_MEAS_V_IN_DIFF)
				{
					OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->close_switch(IA_NEG_IN);
					OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
					OAL_Used[i].OAL_slot->close_switch(IA_POS_IN);
				
					if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
					else
						OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
				} else
				if (mode == OPEN_MEAS_V_IN_DIFF)
				{
					OAL_Used[i].OAL_slot->open_switch(IA_NEG_IN);
					OAL_Used[i].OAL_slot->open_switch(IA_POS_IN);
				} else
				if (mode == CLOSE_MEAS_V_OUT)
				{
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);	
				} else
				if (mode == OPEN_MEAS_V_OUT)
				{
					OAL_Used[i].OAL_slot->open_relay(HV_BUF_CONN);	
				} else
				if (mode == CLOSE_MEAS_I_IN)
				{
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_IN_POS:
						OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
						OAL_Used[i].OAL_slot->close_switch(MLG_CON_POS);
						OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
						OAL_Used[i].OAL_slot->close_switch(POS_LKG_X10);
						OAL_Used[i].OAL_slot->open_switch(IA_POS_IN);
					
						OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
						OAL_Used[i].OAL_slot->close_switch(DRV_1);
						OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);
						if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->select_adc_mux(MLG_POS);
						else
							OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_POS);
						break;
					case PIN_IN_NEG:
						OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
						OAL_Used[i].OAL_slot->close_switch(MLG_CON_NEG);
						OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
						OAL_Used[i].OAL_slot->close_switch(NEG_LKG_X10);
						OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
						OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
			
						OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
						OAL_Used[i].OAL_slot->close_switch(DRV_1);
						OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);
						if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->select_adc_mux(MLG_NEG);
						else
							OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_NEG);
						break;
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Not possible to connect current meter to Pin %s",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					}

				} else
				if (mode == OPEN_MEAS_I_IN)
				{
					if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)
					{
						OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10);
						OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
						OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
				
						OAL_Used[i].OAL_slot->close_switch(CLOSE_LOOP);
						OAL_Used[i].OAL_slot->open_switch(CLS_LOOP_IV);
					}
					else
					{
						OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10);
						OAL_Used[i].OAL_slot->open_switch(MLG_CON_POS);
						OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
					}
					
				
					OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
					OAL_Used[i].OAL_slot->close_switch(DRV_1);
					OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);
				} else
				
				if (mode == CLOSE_LCB_PRECHARGE)
				{
					OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
					OAL_Used[i].OAL_slot->close_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_switch(CLS_LOOP_IV);
					OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
					OAL_Used[i].OAL_slot->close_switch(IA_POS_IN);
					OAL_Used[i].OAL_slot->close_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->open_switch(INT_CONN);
					OAL_Used[i].OAL_slot->close_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
				} else

				if (mode == OPEN_LCB_PRECHARGE)		
				{
					OAL_Used[i].OAL_slot->open_relay(EXT_RLY_DRV);
					OAL_Used[i].OAL_slot->open_switch(DAC_OUT);
					OAL_Used[i].OAL_slot->close_switch(INT_CONN);
					OAL_Used[i].OAL_slot->open_switch(INT_RESET);
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN);
					OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
					wait.delay_10_us(10);
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
					OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL);
					OAL_Used[i].OAL_slot->open_relay(DUT_POS_ISOL);
					OAL_Used[i].OAL_slot->open_switch(IA_POS_IN);
				} else

			
				if (mode == CLOSE_OUT_POL)
					OAL_Used[i].OAL_slot->close_switch(OUT_POL); else
				if (mode == OPEN_OUT_POL)
					OAL_Used[i].OAL_slot->open_switch(OUT_POL); else
				if (mode == CLOSE_OUT_RNG_X4)
					OAL_Used[i].OAL_slot->close_switch(OUT_RNG_X4); else
				if (mode == OPEN_OUT_RNG_X4)
					OAL_Used[i].OAL_slot->open_switch(OUT_RNG_X4); else
				if (mode == CLOSE_DAC_OUT)
					OAL_Used[i].OAL_slot->close_switch(DAC_OUT); else
				if (mode == OPEN_DAC_OUT)
					OAL_Used[i].OAL_slot->open_switch(DAC_OUT); else
				if (mode == CLOSE_INT_CONN)
					OAL_Used[i].OAL_slot->close_switch(INT_CONN); else
				if (mode == OPEN_INT_CONN)
					OAL_Used[i].OAL_slot->open_switch(INT_CONN); else
				if (mode == CLOSE_INT_RESET)
					OAL_Used[i].OAL_slot->close_switch(INT_RESET); else
				if (mode == OPEN_INT_RESET)
					OAL_Used[i].OAL_slot->open_switch(INT_RESET); else
				if (mode == CLOSE_INT_SLOW)
					OAL_Used[i].OAL_slot->close_switch(INT_SLOW); else
				if (mode == OPEN_INT_SLOW)
					OAL_Used[i].OAL_slot->open_switch(INT_SLOW); else
				if (mode == CLOSE_DC_GAIN)
					OAL_Used[i].OAL_slot->close_switch(DC_GAIN); else
				if (mode == OPEN_DC_GAIN)
					OAL_Used[i].OAL_slot->open_switch(DC_GAIN); else
				if (mode == CLOSE_CLOSE_LOOP)
					OAL_Used[i].OAL_slot->close_switch(CLOSE_LOOP); else
				if (mode == OPEN_CLOSE_LOOP)
					OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP); else
				if (mode == CLOSE_CLS_LOOP_IV)
					OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV); else
				if (mode == OPEN_CLS_LOOP_IV)
					OAL_Used[i].OAL_slot->open_switch(CLS_LOOP_IV); else
				if (mode == CLOSE_MLG_CON_POS)
					OAL_Used[i].OAL_slot->close_switch(MLG_CON_POS); else
				if (mode == OPEN_MLG_CON_POS)
					OAL_Used[i].OAL_slot->open_switch(MLG_CON_POS); else
				if (mode == CLOSE_LLG_CON_POS)
					OAL_Used[i].OAL_slot->close_switch(LLG_CON_POS); else
				if (mode == OPEN_LLG_CON_POS)
					OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS); else
				if (mode == CLOSE_POS_LKG_X10)
					OAL_Used[i].OAL_slot->close_switch(POS_LKG_X10); else
				if (mode == OPEN_POS_LKG_X10)
					OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10); else
				if (mode == CLOSE_MLG_CON_NEG)
					OAL_Used[i].OAL_slot->close_switch(MLG_CON_NEG); else
				if (mode == OPEN_MLG_CON_NEG)
					OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG); else
				if (mode == CLOSE_LLG_CON_NEG)
					OAL_Used[i].OAL_slot->close_switch(LLG_CON_NEG); else
				if (mode == OPEN_LLG_CON_NEG)
					OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG); else
				if (mode == CLOSE_NEG_LKG_X10)
					OAL_Used[i].OAL_slot->close_switch(NEG_LKG_X10); else
				if (mode == OPEN_NEG_LKG_X10)
					OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10); else
				if (mode == CLOSE_IA_POS_IN)
					OAL_Used[i].OAL_slot->close_switch(IA_POS_IN); else
				if (mode == OPEN_IA_POS_IN)
					OAL_Used[i].OAL_slot->open_switch(IA_POS_IN); else
				if (mode == CLOSE_IA_NEG_IN)
					OAL_Used[i].OAL_slot->close_switch(IA_NEG_IN); else
				if (mode == OPEN_IA_NEG_IN)
					OAL_Used[i].OAL_slot->open_switch(IA_NEG_IN); else
				if (mode == CLOSE_IA_OFF_100_MV)
					OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV); else
				if (mode == OPEN_IA_OFF_100_MV)
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV); else
				if (mode == CLOSE_DUT_POS_ISOL)
					OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL); else
				if (mode == OPEN_DUT_POS_ISOL)
					OAL_Used[i].OAL_slot->open_relay(DUT_POS_ISOL); else
				if (mode == CLOSE_DUT_NEG_ISOL)
					OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL); else
				if (mode == OPEN_DUT_NEG_ISOL)
					OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL); else
				if (mode == CLOSE_DUT_INP_SHORT)
					OAL_Used[i].OAL_slot->close_relay(DUT_INP_SHORT); else
				if (mode == OPEN_DUT_INP_SHORT)
					OAL_Used[i].OAL_slot->open_relay(DUT_INP_SHORT); else
				if (mode == CLOSE_SHORT_FEEDBACK_RES)
					OAL_Used[i].OAL_slot->close_switch(SHORT_FEEDBACK_RES); else
				if (mode == OPEN_SHORT_FEEDBACK_RES)
					OAL_Used[i].OAL_slot->open_switch(SHORT_FEEDBACK_RES); else
				if (mode == CLOSE_FEEDBACK_TO_OUT)
					OAL_Used[i].OAL_slot->close_switch(FEEDBACK_TO_OUT); else
				if (mode == OPEN_FEEDBACK_TO_OUT)
					OAL_Used[i].OAL_slot->open_switch(FEEDBACK_TO_OUT); else
				if (mode == CLOSE_HV_BUF_CONN)
					OAL_Used[i].OAL_slot->close_relay(HV_BUF_CONN);	else 
				if (mode == OPEN_HV_BUF_CONN)
					OAL_Used[i].OAL_slot->open_relay(HV_BUF_CONN); else

		
				if (mode == CLOSE_IA_OFF_POL)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == OPEN_IA_OFF_POL)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == CLOSE_DUT_POS_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->close_relay(DUT_POS_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->close_relay(CH1_POS_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == OPEN_DUT_POS_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->open_relay(DUT_POS_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->open_relay(CH1_POS_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == CLOSE_DUT_NEG_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->close_relay(DUT_NEG_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->close_relay(CH1_NEG_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == OPEN_DUT_NEG_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->open_relay(DUT_NEG_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->open_relay(CH1_NEG_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == CLOSE_DUT_TO_RMS)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->close_relay(OUT_TO_RMS);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->close_relay(CH1_RMS_METER);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == OPEN_DUT_TO_RMS)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->open_relay(OUT_TO_RMS);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->open_relay(CH1_RMS_METER);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else
				if (mode == CLOSE_DUT_OUT_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->close_relay(DUT_OUT_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->close_relay(CH1_OUT_OUT);
					else
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");exit(0);
				} else
				if (mode == OPEN_DUT_OUT_OUT)
				{
					if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->open_relay(DUT_OUT_OUT);
					else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->open_relay(CH1_OUT_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid OAL channel");
						exit(0);
					}
				} else

				{
					mytext.text_in_box(40,10,"dc_connect() - Unknown OAL mode");exit(0);
				}
			break;	

			case QAL:			
				if (mode == CLOSE)
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
							QAL_Used[i].QAL_slot->close_relay(QAL_DUT_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
							QAL_Used[i].QAL_slot->close_relay(QAL_CH1_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
							QAL_Used[i].QAL_slot->close_relay(QAL_CH2_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
							QAL_Used[i].QAL_slot->close_relay(QAL_CH3_OUT_OUT);
						break;























					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Pin %s not recognized",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					} else
				if (mode == OPEN)
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
							QAL_Used[i].QAL_slot->open_relay(QAL_DUT_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
							QAL_Used[i].QAL_slot->open_relay(QAL_CH1_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
							QAL_Used[i].QAL_slot->open_relay(QAL_CH2_OUT_OUT);
						else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
							QAL_Used[i].QAL_slot->open_relay(QAL_CH3_OUT_OUT);
						break;























					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Pin %s not recognized",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					} else
			
				if (mode == CLOSE_SERVO_LOOP)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
					QAL_Used[i].QAL_slot->close_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == OPEN_SERVO_LOOP)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL);


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == CLOSE_DAC_TO_INPUT)
				{
					QAL_Used[i].QAL_slot->close_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
					QAL_Used[i].QAL_slot->close_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);


					QAL_Used[i].QAL_slot->open_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == OPEN_DAC_TO_INPUT)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL);


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == CLOSE_LOCAL_LOOP)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLS_LOOP_IV);
					QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
					QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == OPEN_LOCAL_LOOP)
				{


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == CLOSE_LOCAL_LOOP_10K)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLS_LOOP_IV);
					QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
					QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == OPEN_LOCAL_LOOP_10K)
				{


					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);
				} else
				if (mode == CLOSE_GND_POS_IN)
				{
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
				} else
				if (mode == OPEN_GND_POS_IN)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_POS_IN);
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_POS_ISOL);
				} else
				if (mode == CLOSE_MEAS_V_IN_DIFF)
				{
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_NEG_IN);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN);
					
					if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
					else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
					else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
					else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
				} else
				if (mode == OPEN_MEAS_V_IN_DIFF)
				{
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_NEG_IN);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_POS_IN);
				} else
				if (mode == CLOSE_MEAS_V_OUT)
				{
					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);	
				} else
				if (mode == OPEN_MEAS_V_OUT)
				{
					QAL_Used[i].QAL_slot->open_relay(QAL_HV_BUF_CONN);	
				} else
				if (mode == CLOSE_MEAS_I_IN)
				{
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_IN_POS:
						QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
						QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_POS);
						QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
						QAL_Used[i].QAL_slot->close_switch(QAL_POS_LKG_X10);
						QAL_Used[i].QAL_slot->open_switch(QAL_IA_POS_IN);
						
						QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
						QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);

						if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_POS);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_POS);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_POS);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_POS);
						break;
					case PIN_IN_NEG:
						QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);
						QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_NEG);
						QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
						QAL_Used[i].QAL_slot->close_switch(QAL_NEG_LKG_X10);
						QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
						QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
						
						QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
						QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);

						if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_NEG);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_NEG);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_NEG);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_NEG);
						break;
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_connect() - Not possible to connect current meter to Pin %s",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					}

				} else
				if (mode == OPEN_MEAS_I_IN)
				{
					if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10);
						QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
						QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
					
						QAL_Used[i].QAL_slot->close_switch(QAL_CLOSE_LOOP);
						QAL_Used[i].QAL_slot->open_switch(QAL_CLS_LOOP_IV);
					}
					else
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10);
						QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_POS);
						QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
					}
					
				
					QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
					QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);

				} else
				
				if (mode == CLOSE_LCB_PRECHARGE)	
				{
					QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
					QAL_Used[i].QAL_slot->close_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLS_LOOP_IV);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN);
					QAL_Used[i].QAL_slot->close_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
				} else

				if (mode == OPEN_LCB_PRECHARGE)		
				{
					QAL_Used[i].QAL_slot->open_relay(QAL_EXT_RLY_DRV);
					QAL_Used[i].QAL_slot->open_switch(QAL_DAC_OUT);
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_CONN);
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_RESET);
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN);
					QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
					wait.delay_10_us(10);
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL);
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_POS_ISOL);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_POS_IN);
				} else

			
				if (mode == CLOSE_OUT_POL)
					QAL_Used[i].QAL_slot->close_switch(QAL_OUT_POL); else
				if (mode == OPEN_OUT_POL)
					QAL_Used[i].QAL_slot->open_switch(QAL_OUT_POL); else
				if (mode == CLOSE_OUT_RNG_X4)
					QAL_Used[i].QAL_slot->close_switch(QAL_OUT_RNG_X4); else
				if (mode == OPEN_OUT_RNG_X4)
					QAL_Used[i].QAL_slot->open_switch(QAL_OUT_RNG_X4); else
				if (mode == CLOSE_DAC_OUT)
					QAL_Used[i].QAL_slot->close_switch(QAL_DAC_OUT); else
				if (mode == OPEN_DAC_OUT)
					QAL_Used[i].QAL_slot->open_switch(QAL_DAC_OUT); else
				if (mode == CLOSE_INT_CONN)
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_CONN); else
				if (mode == OPEN_INT_CONN)
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_CONN); else
				if (mode == CLOSE_INT_RESET)
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_RESET); else
				if (mode == OPEN_INT_RESET)
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_RESET); else
				if (mode == CLOSE_INT_SLOW)
					QAL_Used[i].QAL_slot->close_switch(QAL_INT_SLOW); else
				if (mode == OPEN_INT_SLOW)
					QAL_Used[i].QAL_slot->open_switch(QAL_INT_SLOW); else
				if (mode == CLOSE_DC_GAIN)
					QAL_Used[i].QAL_slot->close_switch(QAL_DC_GAIN); else
				if (mode == OPEN_DC_GAIN)
					QAL_Used[i].QAL_slot->open_switch(QAL_DC_GAIN); else
				if (mode == CLOSE_CLOSE_LOOP)
					QAL_Used[i].QAL_slot->close_switch(QAL_CLOSE_LOOP); else
				if (mode == OPEN_CLOSE_LOOP)
					QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP); else
				if (mode == CLOSE_CLS_LOOP_IV)
					QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV); else
				if (mode == OPEN_CLS_LOOP_IV)
					QAL_Used[i].QAL_slot->open_switch(QAL_CLS_LOOP_IV); else
				if (mode == CLOSE_MLG_CON_POS)
					QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_POS); else
				if (mode == OPEN_MLG_CON_POS)
					QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_POS); else
				if (mode == CLOSE_LLG_CON_POS)
					QAL_Used[i].QAL_slot->close_switch(QAL_LLG_CON_POS); else
				if (mode == OPEN_LLG_CON_POS)
					QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS); else
				if (mode == CLOSE_POS_LKG_X10)
					QAL_Used[i].QAL_slot->close_switch(QAL_POS_LKG_X10); else
				if (mode == OPEN_POS_LKG_X10)
					QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10); else
				if (mode == CLOSE_MLG_CON_NEG)
					QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_NEG); else
				if (mode == OPEN_MLG_CON_NEG)
					QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG); else
				if (mode == CLOSE_LLG_CON_NEG)
					QAL_Used[i].QAL_slot->close_switch(QAL_LLG_CON_NEG); else
				if (mode == OPEN_LLG_CON_NEG)
					QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG); else
				if (mode == CLOSE_NEG_LKG_X10)
					QAL_Used[i].QAL_slot->close_switch(QAL_NEG_LKG_X10); else
				if (mode == OPEN_NEG_LKG_X10)
					QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10); else
				if (mode == CLOSE_IA_POS_IN)
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN); else
				if (mode == OPEN_IA_POS_IN)
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_POS_IN); else
				if (mode == CLOSE_IA_NEG_IN)
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_NEG_IN); else
				if (mode == OPEN_IA_NEG_IN)
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_NEG_IN); else
				if (mode == CLOSE_IA_OFF_100_MV)
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV); else
				if (mode == OPEN_IA_OFF_100_MV)
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV); else
				if (mode == CLOSE_DUT_POS_ISOL)
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL); else
				if (mode == OPEN_DUT_POS_ISOL)
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_POS_ISOL); else
				if (mode == CLOSE_DUT_NEG_ISOL)
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL); else
				if (mode == OPEN_DUT_NEG_ISOL)
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL); else
				if (mode == CLOSE_DUT_INP_SHORT)
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_INP_SHORT); else
				if (mode == OPEN_DUT_INP_SHORT)
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_INP_SHORT); else








				if (mode == CLOSE_HV_BUF_CONN)
					QAL_Used[i].QAL_slot->close_relay(QAL_HV_BUF_CONN);	else 
				if (mode == OPEN_HV_BUF_CONN)
					QAL_Used[i].QAL_slot->open_relay(QAL_HV_BUF_CONN); else	

			
				if (mode == CLOSE_IA_OFF_POL)
				{
					if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH2_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid QAL channel");
						exit(0);
					}
				} else
				if (mode == OPEN_IA_OFF_POL)
				{
					if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid QAL channel");
						exit(0);
					}
				} else
































































































				if (mode == CLOSE_DUT_OUT_OUT)
				{
					if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->close_relay(QAL_DUT_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->close_relay(QAL_CH1_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->close_relay(QAL_CH2_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->close_relay(QAL_CH3_OUT_OUT);
					else
						mytext.text_in_box(40,10,"dc_connect() - Invalid QAL channel");exit(0);
				} else
				if (mode == OPEN_DUT_OUT_OUT)
				{
					if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->open_relay(QAL_DUT_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->open_relay(QAL_CH1_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->open_relay(QAL_CH2_OUT_OUT);
					else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->open_relay(QAL_CH3_OUT_OUT);
					else
					{
						mytext.text_in_box(40,10,"dc_connect() - Invalid QAL channel");
						exit(0);
					}
				} else

				{
					mytext.text_in_box(40,10,"dc_connect() - Unknown QAL mode");exit(0);
				}
			break;	
			
            case ACS:
				if (mode==CLOSE)
					ACS_Used[i].ACS_slot->close_relay(ACS_Used[i].ACS_channel);
				else
					ACS_Used[i].ACS_slot->open_relay(ACS_Used[i].ACS_channel);
			break;

			case OV2:
					switch (mode)
					{
					case CLOSE:
						OV2_Used[i].OV2_slot->connect(OV2_Used[i].OV2_channel);	
						break;
					case CLOSE_S:
						OV2_Used[i].OV2_slot->close_relay(OV2_Used[i].OV2_channel+OV2_CONN_SENSE0);
						break;
					case CLOSE_F:
						OV2_Used[i].OV2_slot->close_relay(OV2_Used[i].OV2_channel+OV2_CONN_FORCE0);
						break;
					case CLOSE_M:
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_FORCE0);
						OV2_Used[i].OV2_slot->close_relay(OV2_Used[i].OV2_channel+OV2_CONN_SENSE0);
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_FEEDBACK0);
						break;
					case OPEN:
						OV2_Used[i].OV2_slot->disconnect(OV2_Used[i].OV2_channel);	
						break;
					case OPEN_S:
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_SENSE0);
						break;
					case OPEN_F:
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_FORCE0);
						break;
					case OPEN_M:
						OV2_Used[i].OV2_slot->close_relay(OV2_Used[i].OV2_channel+OV2_CONN_FEEDBACK0);
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_FORCE0);
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_SENSE0);
						break;
					case CLOSE_FS_RES:
						OV2_Used[i].OV2_slot->close_relay(OV2_Used[i].OV2_channel+OV2_CONN_FEEDBACK0);
						break;
					case OPEN_FS_RES:
						OV2_Used[i].OV2_slot->open_relay(OV2_Used[i].OV2_channel+OV2_CONN_FEEDBACK0);
						break;
					default:
						mytext.text_in_box(40,10,"Unknown OVI2 mode");
						exit(0);
					}
			break;

			default:
				mytext.text_in_box(40,10,"dc_connect() not executable for a relay pin");
				exit(0);
			}
		}
	} 
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}



void dc_force(short pin_list, sfloat *current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_force(pin, current[list_depth-1-n], voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, float current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list);


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr;
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_force(pin, current, voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, double current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list);


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_force(pin, current, voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, sfloat *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_force(pin, current[list_depth-1-n], voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin_list, sfloat *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_force(pin, current[list_depth-1-n], voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void dc_force(short pin, float current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	dc_force(pin, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, double current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=(float)current;
			s_voltage[i]=(float)voltage;
		}

	dc_force(pin, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, double current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	dc_force(pin, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, float current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	dc_force(pin, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, float current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=current;

	dc_force(pin, s_current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, double current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=(float)current;

	dc_force(pin, s_current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, float *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=voltage;

	dc_force(pin, current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, float *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=(float)voltage;

	dc_force(pin, current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void dc_force(short pin, float *current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	

	bool			FastRangeDelay=false;
	bool			EnableCurrentDelay=false;
	bool			dvi_half_current=ihalf;
	unsigned char	dvi_compensation=compensation;
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
	char			dvi_current_auto_range;
	char			dvi_voltage_auto_range;
	bool			dvi_status_relay_f, dvi_status_relay_s;
	char			ovi_current_range, ovi_current_auto_range;
	char			ovi_voltage_range, ovi_voltage_auto_range;
	float			ovi_current_value, ovi_voltage_value;
	char			ov2_current_auto_range;
	char			ov2_voltage_auto_range;
#endif
#endif


	
	
	
	
	

#ifndef	LegacyXerxes

	int					slot;
	bool				xvi_any_cards_used			= false;	
	char				ErrorMessage[100];
	XVI_ERROR_CODE_e	XviRetError					= XVI_EC_NO_ERROR_INFO;
	double				v_rng, i_rng;
	bool				high_voltage_flag			= false;
	bool				hv_delay_flag				= false;

	for(slot=0; slot<21;slot++)
	{
		XVI_Card_Used[slot].force_mask			= 0x0;
		XVI_Card_Used[slot].block_programming	= true;
		XVI_Card_Used[slot].block_initialized	= false;
	}
	double				xvi_vjustifier, xvi_ijustifier;							
#endif

	start_pin_ptr = group_selection(pin); 
	pin_ptr = start_pin_ptr;



	do
	{
	pin = pin_ptr->grouppin;

 	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:	
				break;
#ifndef	LegacyXerxes
			case XVI:
				
				XviRetError = XVI_EC_NO_ERROR_INFO;
				v_rng		= -10000.0;
				i_rng		= -10000.0;	

			
				if ((c_range != AUTORANGE)||(v_range != AUTORANGE))
				{
					
					switch(v_range)
					{
					case RANGE_1_V:		v_rng=1.0;	break;	
					case RANGE_2_V:							
					case RANGE_3_V:		v_rng=3.0;	break;	
					case RANGE_5_V:		v_rng=5.0;	break;
					case RANGE_10_V:	v_rng=10.0;	break;
					case RANGE_20_V:					
					case RANGE_30_V:	v_rng=30.0;	break;	
					default:			v_rng=-10000.0;
					}

					switch(c_range)
					{
					case RANGE_2_UA:							
					case RANGE_3_UA:	i_rng=3.0e-6;	break;	
					case RANGE_20_UA:							
					case RANGE_30_UA:	i_rng=30.0e-6;	break;	
					case RANGE_200_UA:						
					case RANGE_300_UA:	i_rng=300.0e-6;	break;	
					case RANGE_2_MA:							
					case RANGE_3_MA:							
					case RANGE_10_MA:	i_rng=10.0e-3;	break;	
					case RANGE_20_MA:							
					case RANGE_30_MA:						
					case RANGE_100_MA:	i_rng=((double)current[i] > 100.0e-3 ? 150.0e-3 : 100.0e-3);	break;	
					default:			i_rng=-10000.0;	
					}
				}
				
				
				
				if(
					(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask==0x0)&&
					(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)&&
					(!XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_initialized)	
				  )
				{
				
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage=voltage[i];
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current=current[i];
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_irng=i_rng;
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_vrng=v_rng;
					xvi_vjustifier=pow(10.0,7.0-(floor(0.5+log10(fabs(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage)))));	
					
					xvi_ijustifier=pow(10.0,(fabs(current[i]) > (float)(300.0e-6) ? 7.0 : 6.0 )-(floor(0.5+log10(fabs(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current)))));		
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_initialized=true;
				}
				

				if	((c_range == AUTORANGE)&&(v_range == AUTORANGE))
				{
			
					if	(	
						(voltage[i]==XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage)&&
						(current[i]==XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current)&&
						(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)
						)
					{
				
if(!debug_xvi_msl_offline)	
						if	(
							(current[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
							(voltage[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))
							)
						{
							
							XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask|=(UINT16)XVI_Used[i].XVI_channel;
				
							if(!xvi_any_cards_used)
								xvi_any_cards_used=true;
						}
					}
					else
					
				
						XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else 
				{
					
					if	(	
						(voltage[i]	== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage)&&
						(current[i]	== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current)&&
						(i_rng		== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_irng)&&
						(v_rng		== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_vrng)&&
						(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)
						)
					{
					
if(!debug_xvi_msl_offline)
						if	(
							(current[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
							(voltage[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))||
							(i_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_current_range[XVI_Used[i].XVI_ch_index])||
							(v_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_voltage_range[XVI_Used[i].XVI_ch_index])
							)
						{
							
							XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask|=(UINT16)XVI_Used[i].XVI_channel;
						
							if(!xvi_any_cards_used)
								xvi_any_cards_used=true;
						}
					}
					else
					
						XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}

			
		
				if(
					(
					(voltage[i]>10.0)&&
					(XVI_Used[i].XVI_slot->card.xvi_image_force_voltage_mode!=XVI_FVM_POS_HIGH_VOLTAGE)&&
					(XVI_Used[i].XVI_slot->card.xvi_image_force_voltage_mode!=XVI_FVM_HIGH_VOLTAGE)
					)||
					(
					(voltage[i]<-10.0)&&
					(XVI_Used[i].XVI_slot->card.xvi_image_force_voltage_mode!=XVI_FVM_NEG_HIGH_VOLTAGE)&&
					(XVI_Used[i].XVI_slot->card.xvi_image_force_voltage_mode!=XVI_FVM_HIGH_VOLTAGE)
					)
				   )
				{
				
					if(!high_voltage_flag)
						high_voltage_flag=true;
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].fv_due=true;
				}
				break;
#endif
			case DVI:

				#ifndef	LegacyVATE531
					FastRangeDelay=!(DVI_Used[i].DVI_slot->get_current_range_delay());
				#else
					FastRangeDelay=!DVI_Used[i].DVI_slot->use_set_current_range_delay;
				#endif

				if (c_range == AUTORANGE)
				{
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
				
					switch(DVI_Used[i].DVI_slot->nvram_info.revision[0])
					{
					case 'F':
				
						if(current[i]>100.0e-3f)	{dvi_current_auto_range=RANGE_200_MA;	dvi_half_current=false;}	else	
						if(current[i]>20.0e-3f)		{dvi_current_auto_range=RANGE_200_MA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-3f)		{dvi_current_auto_range=RANGE_20_MA;	dvi_half_current=false;}	else	
						if(current[i]>2.0e-3f)		{dvi_current_auto_range=RANGE_20_MA;	dvi_half_current=true;}		else	
						if(current[i]>1.0e-3f)		{dvi_current_auto_range=RANGE_2_MA;		dvi_half_current=false;}	else	
						if(current[i]>200.0e-6f)	{dvi_current_auto_range=RANGE_2_MA;		dvi_half_current=true;}		else	
						if(current[i]>100.0e-6f)	{dvi_current_auto_range=RANGE_200_UA;	dvi_half_current=false;}	else	
						if(current[i]>20.0e-6f)		{dvi_current_auto_range=RANGE_200_UA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-6f)		{dvi_current_auto_range=RANGE_20_UA;	dvi_half_current=false;}	else	
													{dvi_current_auto_range=RANGE_20_UA;	dvi_half_current=true;}				
						break;
					case 'G':
				
						if(current[i]>100.0e-3f)	{dvi_current_auto_range=RANGE_300_MA;	dvi_half_current=false;}	else	
						if(current[i]>30.0e-3f)		{dvi_current_auto_range=RANGE_300_MA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-3f)		{dvi_current_auto_range=RANGE_30_MA;	dvi_half_current=false;}	else	
						if(current[i]>3.0e-3f)		{dvi_current_auto_range=RANGE_30_MA;	dvi_half_current=true;}		else	
						if(current[i]>1.0e-3f)		{dvi_current_auto_range=RANGE_3_MA;		dvi_half_current=false;}	else	
						if(current[i]>300.0e-6f)	{dvi_current_auto_range=RANGE_3_MA;		dvi_half_current=true;}		else	
						if(current[i]>100.0e-6f)	{dvi_current_auto_range=RANGE_300_UA;	dvi_half_current=false;}	else	
						if(current[i]>30.0e-6f)		{dvi_current_auto_range=RANGE_300_UA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-6f)		{dvi_current_auto_range=RANGE_30_UA;	dvi_half_current=false;}	else	
													{dvi_current_auto_range=RANGE_30_UA;	dvi_half_current=true;}				
						break;
					case 'H':
					
						if(current[i]>1.0f)			{dvi_current_auto_range=RANGE_2_A;		dvi_half_current=false;}	else	
						if(current[i]>200.0e-3f)	{dvi_current_auto_range=RANGE_2_A;		dvi_half_current=true;}		else	
						if(current[i]>100.0e-3f)	{dvi_current_auto_range=RANGE_200_MA;	dvi_half_current=false;}	else	
						if(current[i]>20.0e-3f)		{dvi_current_auto_range=RANGE_200_MA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-3f)		{dvi_current_auto_range=RANGE_20_MA;	dvi_half_current=false;}	else	
						if(current[i]>2.0e-3f)		{dvi_current_auto_range=RANGE_20_MA;	dvi_half_current=true;}		else	
						if(current[i]>1.0e-3f)		{dvi_current_auto_range=RANGE_2_MA;		dvi_half_current=false;}	else	
						if(current[i]>200.0e-6f)	{dvi_current_auto_range=RANGE_2_MA;		dvi_half_current=true;}		else	
						if(current[i]>100.0e-6f)	{dvi_current_auto_range=RANGE_200_UA;	dvi_half_current=false;}	else	
						if(current[i]>20.0e-6f)		{dvi_current_auto_range=RANGE_200_UA;	dvi_half_current=true;}		else	
						if(current[i]>10.0e-6f)		{dvi_current_auto_range=RANGE_20_UA;	dvi_half_current=false;}	else	
						if(current[i]>2.0e-6f)		{dvi_current_auto_range=RANGE_20_UA;	dvi_half_current=true;}		else	
						if(current[i]>1.0e-6f)		{dvi_current_auto_range=RANGE_2_UA;		dvi_half_current=false;}	else	
													{dvi_current_auto_range=RANGE_2_UA;		dvi_half_current=true;}				
						break;
					}
					
				if( (DVI_Used[i].DVI_slot->debug_current_out[DVI_Used[i].DVI_channel]	!= current[i])||
					(DVI_Used[i].DVI_slot->debug_current_range[DVI_Used[i].DVI_channel]	!= dvi_current_auto_range)||
					(DVI_Used[i].DVI_slot->debug_half_current[DVI_Used[i].DVI_channel]	!= (BOOL)dvi_half_current))
#endif
#endif
				{
					DVI_Used[i].DVI_slot->set_current(DVI_Used[i].DVI_channel,current[i]);
		
					if(FastRangeDelay)
						EnableCurrentDelay=true;	
				}
				} else
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
			
				if( (DVI_Used[i].DVI_slot->debug_current_out[DVI_Used[i].DVI_channel]	!= current[i])||
					(DVI_Used[i].DVI_slot->debug_current_range[DVI_Used[i].DVI_channel]	!= c_range)||
					(DVI_Used[i].DVI_slot->debug_half_current[DVI_Used[i].DVI_channel]	!= (BOOL)ihalf))
#endif
#endif
				{
					DVI_Used[i].DVI_slot->set_current(DVI_Used[i].DVI_channel,current[i],c_range,ihalf);
				
					if(FastRangeDelay)
						EnableCurrentDelay=true;
				}

		
			
			
				break;
			case OVI:
			case OVI_S:
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
				OVI_Used[i].OVI_slot->get_current_range (OVI_Used[i].OVI_channel, ovi_current_range);
				ovi_current_value= OVI_Used[i].OVI_slot->get_current_setting (OVI_Used[i].OVI_channel);
#endif
#endif
				if (c_range == AUTORANGE)
				{
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
					
					switch(OVI_Used[i].OVI_slot->nvram_info.revision[0])
					{
					case 'C':
						
						if(current[i]>3.0e-3f)		ovi_current_auto_range=RANGE_30_MA;		else
						if(current[i]>300.0e-6f)	ovi_current_auto_range=RANGE_3_MA;		else	
						if(current[i]>30.0e-6f)		ovi_current_auto_range=RANGE_300_UA;	else
													ovi_current_auto_range=RANGE_30_UA;				
						break;
					default:
						
						if(current[i]>2.0e-3f)		ovi_current_auto_range=RANGE_20_MA;		else
						if(current[i]>200.0e-6f)	ovi_current_auto_range=RANGE_2_MA;		else
						if(current[i]>20.0e-6f)		ovi_current_auto_range=RANGE_200_UA;	else
													ovi_current_auto_range=RANGE_20_UA;			
						break;
					}
					if(	(ovi_current_value		!= current[i])||
						(ovi_current_range		!= ovi_current_auto_range))
#endif
#endif
					OVI_Used[i].OVI_slot->set_current(OVI_Used[i].OVI_channel,current[i]);
					}
				else
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
					
					if(	(ovi_current_value		!= current[i])||
						(ovi_current_range		!= c_range))
#endif
#endif
					OVI_Used[i].OVI_slot->set_current(OVI_Used[i].OVI_channel,current[i],c_range);
				break;
			case OV2:
				if (c_range == AUTORANGE)
				{
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
					
					if(fabs(current[i])>50.0e-3f)   {ov2_current_auto_range=RANGE_500_MA;}  else	
					if(fabs(current[i])>5.0e-3f)    {ov2_current_auto_range=RANGE_50_MA;}   else	
					if(fabs(current[i])>500.0e-6f)  {ov2_current_auto_range=RANGE_5_MA;}    else	
					if(fabs(current[i])>50.0e-6f)   {ov2_current_auto_range=RANGE_500_UA;}  else	
					if(fabs(current[i])>5.0e-6f)    {ov2_current_auto_range=RANGE_50_UA;}   else	
					{ov2_current_auto_range=RANGE_5_UA;}				
					if( (OV2_Used[i].OV2_slot->debug_curr_out[OV2_Used[i].OV2_channel]	 != current[i])||
						(OV2_Used[i].OV2_slot->debug_curr_range[OV2_Used[i].OV2_channel] != ov2_current_auto_range))
#endif
#endif
					{
						OV2_Used[i].OV2_slot->set_current(OV2_Used[i].OV2_channel,current[i]);
					}
				}else
				{
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
					
					if( (OV2_Used[i].OV2_slot->debug_curr_out[OV2_Used[i].OV2_channel]	 != current[i])||
						(OV2_Used[i].OV2_slot->debug_curr_range[OV2_Used[i].OV2_channel] != c_range))
#endif
#endif
					{
						OV2_Used[i].OV2_slot->set_current(OV2_Used[i].OV2_channel,current[i],c_range);
					}
				}
				break;
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

#ifndef	LegacyXerxes


	if(high_voltage_flag)
		for(slot=0; slot<21;slot++)	if(XVI_Card_Used[slot].fv_due)
		{
			XviRetError=XVI_Card_Used[slot].card_ptr->select_force_voltage_mode(XVI_FVM_HIGH_VOLTAGE);	
			
			XVI_Card_Used[slot].fv_due= false;
			
			if(!hv_delay_flag)
				hv_delay_flag=true;
		}
	if(hv_delay_flag)
		delay(70);

	
	
	if(xvi_any_cards_used)
		for(slot=0; slot<21;slot++)	if((XVI_Card_Used[slot].block_programming)&&(XVI_Card_Used[slot].force_mask!=0x0))
		{
			if ((c_range == AUTORANGE)&&(v_range == AUTORANGE))
			{
if(!debug_xvi_msl_offline)	
				
				XviRetError=XVI_Card_Used[slot].card_ptr->force(XVI_Card_Used[slot].force_mask,(double)((int)(XVI_Card_Used[slot].block_voltage*xvi_vjustifier))/xvi_vjustifier,(double)((int)(XVI_Card_Used[slot].block_current*xvi_ijustifier))/xvi_ijustifier);	
				
			}
			else
			{
if(!debug_xvi_msl_offline)	
				
				XviRetError=XVI_Card_Used[slot].card_ptr->force(XVI_Card_Used[slot].force_mask,(double)((int)(XVI_Card_Used[slot].block_voltage*xvi_vjustifier))/xvi_vjustifier,XVI_Card_Used[slot].block_vrng,(double)((int)(XVI_Card_Used[slot].block_current*xvi_ijustifier))/xvi_ijustifier,XVI_Card_Used[slot].block_irng);	
				
			}
			if(XviRetError!=XVI_EC_NO_ERROR_INFO)
			{
				sprintf(ErrorMessage,"dc_force() error with XVI%i",slot);
				MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
				printf("\n");
			}
	
			XVI_Card_Used[slot].force_mask=0x0;
		}

#endif


	if(EnableCurrentDelay)
		wait.delay_10_us(20);


	pin_ptr = start_pin_ptr;
		
	do
	{


	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
				case NONE: break;

				case DVI:


	

	





					if (v_range == AUTORANGE)
					{
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
						
						if(voltage[i]>20.0f)	dvi_voltage_auto_range=VOLT_50_RANGE;	else	
						if(voltage[i]>10.0f)	dvi_voltage_auto_range=VOLT_20_RANGE;	else	
						if(voltage[i]>5.0f)		dvi_voltage_auto_range=VOLT_10_RANGE;	else	
						if(voltage[i]>2.0f)		dvi_voltage_auto_range=VOLT_5_RANGE;	else	
						if(voltage[i]>1.0f)		dvi_voltage_auto_range=VOLT_2_RANGE;	else	
												dvi_voltage_auto_range=VOLT_1_RANGE;			

						if (DVI_Used[i].DVI_channel==DVI_CHANNEL_0)
						{
							dvi_status_relay_f= DVI_Used[i].DVI_slot->relay_is_open (CONN_FORCE0);
							dvi_status_relay_s= DVI_Used[i].DVI_slot->relay_is_open (CONN_SENSE0);
						}
						else if (DVI_Used[i].DVI_channel==DVI_CHANNEL_1)
						{
							dvi_status_relay_f= DVI_Used[i].DVI_slot->relay_is_open (CONN_FORCE1);
							dvi_status_relay_s= DVI_Used[i].DVI_slot->relay_is_open (CONN_SENSE1);
						}

						if( (DVI_Used[i].DVI_slot->debug_voltage_out[DVI_Used[i].DVI_channel]			!= voltage[i])||
							(DVI_Used[i].DVI_slot->debug_voltage_range[DVI_Used[i].DVI_channel]			!= dvi_voltage_auto_range)||
							(DVI_Used[i].DVI_slot->debug_voltage_compensation[DVI_Used[i].DVI_channel]	!= FAST_VOLTAGE_MODE)||
							dvi_status_relay_f||dvi_status_relay_s)
#endif
#endif
						DVI_Used[i].DVI_slot->set_voltage(DVI_Used[i].DVI_channel,voltage[i],-1,compensation,is_ext_ref);
					}
					else
					{
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
						
						switch(v_range)
						{
						case RANGE_50_V:	dvi_voltage_auto_range=VOLT_50_RANGE;	break;	
						case RANGE_20_V:	dvi_voltage_auto_range=VOLT_20_RANGE;	break;	
						case RANGE_10_V:	dvi_voltage_auto_range=VOLT_10_RANGE;	break;	
						case RANGE_5_V:		dvi_voltage_auto_range=VOLT_5_RANGE;	break;	
						case RANGE_2_V:		dvi_voltage_auto_range=VOLT_2_RANGE;	break;	
						case RANGE_1_V:		dvi_voltage_auto_range=VOLT_1_RANGE;			
						}

						if( (DVI_Used[i].DVI_slot->debug_voltage_out[DVI_Used[i].DVI_channel]			!= voltage[i])||
							(DVI_Used[i].DVI_slot->debug_voltage_range[DVI_Used[i].DVI_channel]			!= dvi_voltage_auto_range)||
							(DVI_Used[i].DVI_slot->debug_voltage_compensation[DVI_Used[i].DVI_channel]	!= compensation)||
							(DVI_Used[i].DVI_slot->card.ext_ref_enabled[DVI_Used[i].DVI_channel]    	!= is_ext_ref))
#endif
#endif
 						DVI_Used[i].DVI_slot->set_voltage(DVI_Used[i].DVI_channel,voltage[i],v_range,compensation,is_ext_ref);
 					}
				break;

				case OVI_S:
				case OVI:
		

		
			
			
			

				
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
					OVI_Used[i].OVI_slot->get_voltage_range (OVI_Used[i].OVI_channel, ovi_voltage_range);
					ovi_voltage_value= OVI_Used[i].OVI_slot->get_voltage_setting (OVI_Used[i].OVI_channel);
#endif
#endif
					if (v_range == AUTORANGE)
					{
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
					
						if(voltage[i]>10.0f)	ovi_voltage_auto_range=RANGE_20_V;	else	
						if(voltage[i]>5.0f)		ovi_voltage_auto_range=RANGE_10_V;	else	
						if(voltage[i]>2.0f)		ovi_voltage_auto_range=RANGE_5_V;	else	
						if(voltage[i]>1.0f)		ovi_voltage_auto_range=RANGE_2_V;	else	
												ovi_voltage_auto_range=RANGE_1_V;			

						if( (ovi_voltage_value		!= voltage[i])||
							(ovi_voltage_range		!= ovi_voltage_auto_range))
#endif
#endif
						OVI_Used[i].OVI_slot->set_voltage(OVI_Used[i].OVI_channel,voltage[i]);
					}
					else
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
					
						if( (ovi_voltage_value		!= voltage[i])||
							(ovi_voltage_range		!= v_range))
#endif
#endif
						OVI_Used[i].OVI_slot->set_voltage(OVI_Used[i].OVI_channel,voltage[i],v_range);
				break;

#ifndef	LegacyXerxes
				case XVI:
					XviRetError = XVI_EC_NO_ERROR_INFO;	
					if(!(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming))	
					{
					xvi_vjustifier=pow(10.0,7.0-(floor(0.5+log10(fabs(voltage[i])))));	
	
					xvi_ijustifier=pow(10.0,(fabs(current[i]) > (float)(300.0e-6) ? 7.0 : 6.0 )-(floor(0.5+log10(fabs(current[i])))));	
if(!debug_xvi_msl_offline)	
				
					if ((c_range == AUTORANGE)&&(v_range == AUTORANGE))
					{
						
						if(	
							
							(	
								(current[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
								(voltage[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))
							)
						  )	
						{
							
if(!debug_xvi_msl_offline)	
							
							
							XviRetError=XVI_Used[i].XVI_slot->force(XVI_Used[i].XVI_channel,(double)((int)(voltage[i]*xvi_vjustifier))/xvi_vjustifier,(double)((int)(current[i]*xvi_ijustifier))/xvi_ijustifier);	
							
						}
					}
				
					else
					{
					
					
						double v_rng, i_rng;
						switch(v_range)
						{
						case RANGE_1_V:		v_rng=1.0;	break;	
						case RANGE_2_V:							
						case RANGE_3_V:		v_rng=3.0;	break;	
						case RANGE_5_V:		v_rng=5.0;	break;	
						case RANGE_10_V:	v_rng=10.0;	break;	
						case RANGE_20_V:						
						case RANGE_30_V:	v_rng=30.0;	break;	
					
						default:			v_rng=-10000.0;
						}

						switch(c_range)
						{
						case RANGE_2_UA:						
						case RANGE_3_UA:	i_rng=3.0e-6;	break;	
						case RANGE_20_UA:							
						case RANGE_30_UA:	i_rng=30.0e-6;	break;	
						case RANGE_200_UA:							
						case RANGE_300_UA:	i_rng=300.0e-6;	break;	
						case RANGE_2_MA:							
						case RANGE_3_MA:							
						case RANGE_10_MA:	i_rng=10.0e-3;	break;	
						case RANGE_20_MA:							
						case RANGE_30_MA:							
					
						case RANGE_100_MA:	i_rng=((double)current[i] > 100.0e-3 ? 150.0e-3 : 100.0e-3);	break;	
			
						default:			i_rng=-10000.0;	
						}

						
						if(	

							(	
								(current[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
								(voltage[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))||
								(i_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_current_range[XVI_Used[i].XVI_ch_index])||
								(v_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_voltage_range[XVI_Used[i].XVI_ch_index])
							)
						  )	
if(!debug_xvi_msl_offline)	
							
							

							XviRetError=XVI_Used[i].XVI_slot->force(XVI_Used[i].XVI_channel,(double)((int)(voltage[i]*xvi_vjustifier))/xvi_vjustifier,v_rng,(double)((int)(current[i]*xvi_ijustifier))/xvi_ijustifier,i_rng);
					
					}
					}

	


		
						
					
				
				
				
					


			

						

	
		
			

					

				

					







		




			


			




					if(XviRetError!=XVI_EC_NO_ERROR_INFO)	
					{
						sprintf(ErrorMessage,"dc_force() error with XVI%i",slot);
						MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
						printf(ErrorMessage);
					}
					break;
#endif

				case HVS:
					
					if (c_range == AUTORANGE)
					 HVS_Used[i].HVS_slot->set_current(current[i]);
					else
					

				#ifndef	LegacyVATE522
					{
						unsigned int hot_switch=HVS_Used[i].HVS_slot->m_hot_switch_on_current_setting;
						HVS_Used[i].HVS_slot->set_current(current[i],c_range,hot_switch);
					}
				#else
					HVS_Used[i].HVS_slot->set_current(current[i],c_range);
				#endif


				
					if (v_range == AUTORANGE)
					 HVS_Used[i].HVS_slot->set_voltage(voltage[i]);
					else


				#ifndef	LegacyVATE522
					{
						unsigned int hot_switch=HVS_Used[i].HVS_slot->m_hot_switch_on_voltage_setting;
						HVS_Used[i].HVS_slot->set_voltage(voltage[i],v_range,hot_switch);
					}
				#else
					 HVS_Used[i].HVS_slot->set_voltage(voltage[i],v_range);
				#endif

				break;

				case OFS:
					
					if (c_range == AUTORANGE)
					 OFS_Used[i].OFS_slot->set_current(current[i]);
					else
					 OFS_Used[i].OFS_slot->set_current(current[i],c_range);










		
					if (v_range == AUTORANGE)
					 OFS_Used[i].OFS_slot->set_voltage(voltage[i]);
					else
					 OFS_Used[i].OFS_slot->set_voltage(voltage[i],v_range);










				break;

				case MVS:
			
					if (c_range == AUTORANGE)
					 MVS_Used[i].MVS_slot->set_current(current[i]);
					else
					

				#ifndef	LegacyVATE522
					{
						unsigned int hot_switch=MVS_Used[i].MVS_slot->m_hot_switch_on_current_setting;	
						MVS_Used[i].MVS_slot->set_current(current[i],c_range,hot_switch);
					}
				#else
					MVS_Used[i].MVS_slot->set_current(current[i],c_range);
				#endif



				
					if (v_range == AUTORANGE)
					 MVS_Used[i].MVS_slot->set_voltage(voltage[i]);
					else


				#ifndef	LegacyVATE522
					{
						unsigned int hot_switch=MVS_Used[i].MVS_slot->m_hot_switch_on_voltage_setting;	
						MVS_Used[i].MVS_slot->set_voltage(voltage[i],v_range,hot_switch);
					}
				#else
					 MVS_Used[i].MVS_slot->set_voltage(voltage[i],v_range);
				#endif

				break;

				case PVI:
					
					if (c_range == AUTORANGE)
					 PVI_Used[i].PVI_slot->set_current(current[i]);
					else
					 PVI_Used[i].PVI_slot->set_current(current[i],c_range);

					
					if (v_range == AUTORANGE)
					 PVI_Used[i].PVI_slot->set_voltage(voltage[i]);
					else
					 PVI_Used[i].PVI_slot->set_voltage(voltage[i],v_range);


				break;

				case LZB:			
				
					if (c_range == AUTORANGE)
						LZB_Used[i].LZB_slot->set_current(current[i]);
					else
						LZB_Used[i].LZB_slot->set_current(current[i],c_range);
					 LZB_Used[i].LZB_slot->set_voltage(voltage[i]);
				break;

				case OAL:			
			
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						
						if(voltage[i]>(float)(40 V)) voltage[i]=(float)(40 V);
						if(voltage[i]<(float)(-40 V)) voltage[i]=(float)(-40 V);
						OAL_Used[i].OAL_slot->set_output_voltage(voltage[i]);
						break;
					case PIN_IN_NEG:
						
						if(voltage[i]>(float)(10 V)) voltage[i]=(float)(10 V);
						if(voltage[i]<(float)(-10 V)) voltage[i]=(float)(-10 V);
						OAL_Used[i].OAL_slot->set_output_voltage(-voltage[i]);
						break;
					case PIN_IN_POS:
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_force() - Not possible to force a voltage on Pin %s",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					}
				break;

				case QAL:			
					
					switch(Pin_Type_Used[pin][i].PinClass)
					{
					case PIN_OUT:
						
						if(voltage[i]>(float)(40 V)) voltage[i]=(float)(40 V);
						if(voltage[i]<(float)(-40 V)) voltage[i]=(float)(-40 V);
						QAL_Used[i].QAL_slot->set_output_voltage(voltage[i]);
						break;
					case PIN_IN_NEG:
						
						if(voltage[i]>(float)(10 V)) voltage[i]=(float)(10 V);
						if(voltage[i]<(float)(-10 V)) voltage[i]=(float)(-10 V);
						QAL_Used[i].QAL_slot->set_output_voltage(-voltage[i]);
						break;
					case PIN_IN_POS:
					default:
						{
						char err_message[100];
						sprintf(err_message, "dc_force() - Not possible to force a voltage on Pin %s",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						}
					}
				break;

				case OV2:
					if (c_range == AUTORANGE)
					{
#if WINVER_SXHB == 0x0501
#ifndef LegacyVATE611
						
						if(fabs(voltage[i])>25.0f)  {ov2_voltage_auto_range=RANGE_50_V;}  else	
						if(fabs(voltage[i])>10.0f)  {ov2_voltage_auto_range=RANGE_25_V;}  else	
						if(fabs(voltage[i])>5.0f)   {ov2_voltage_auto_range=RANGE_10_V;}  else	
						if(fabs(voltage[i])>2.0f)   {ov2_voltage_auto_range=RANGE_5_V;}   else	
						{ov2_voltage_auto_range=RANGE_2_V;}				
						if( (OV2_Used[i].OV2_slot->debug_volt_out[OV2_Used[i].OV2_channel]	 != voltage[i])||
							(OV2_Used[i].OV2_slot->debug_volt_range[OV2_Used[i].OV2_channel] != ov2_voltage_auto_range))
#endif
#endif
						{
							OV2_Used[i].OV2_slot->set_voltage(OV2_Used[i].OV2_channel,voltage[i]);
						}
					}else
					{
#if WINVER_SXHB == 0x0501	
#ifndef LegacyVATE611
						
						if( (OV2_Used[i].OV2_slot->debug_volt_out[OV2_Used[i].OV2_channel]	 != voltage[i])||
							(OV2_Used[i].OV2_slot->debug_volt_range[OV2_Used[i].OV2_channel] != v_range))
#endif
#endif
						{
							OV2_Used[i].OV2_slot->set_voltage(OV2_Used[i].OV2_channel,voltage[i],v_range);
						}
					}
				break;

				default:
					mytext.text_in_box(40,10,"dc_force() not executable for a relay pin");
					exit(0);
				}
		}

	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

}

void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		cap_force(pin, force_mode, transition_time, current[list_depth-1-n], voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list,short force_mode,float transition_time, float current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list);


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr;
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		cap_force(pin, force_mode, transition_time, current, voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list,short force_mode,float transition_time, double current, sfloat *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list);


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		cap_force(pin, force_mode, transition_time, current, voltage[list_depth-1-n], c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		cap_force(pin, force_mode, transition_time, current[list_depth-1-n], voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin_list,short force_mode,float transition_time, sfloat *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{

	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		cap_force(pin, force_mode, transition_time, current[list_depth-1-n], voltage, c_range, v_range, ihalf, compensation,is_ext_ref);

		pin_ptr = pin_ptr->nextptr;
	}
}

void  cap_force(short pin,short force_mode,float transition_time, float current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	cap_force(pin, force_mode, transition_time, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, double current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=(float)current;
			s_voltage[i]=(float)voltage;
		}

	cap_force(pin, force_mode, transition_time, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, double current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	cap_force(pin, force_mode, transition_time, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, float current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	cap_force(pin, force_mode, transition_time, s_current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, float current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=current;

	cap_force(pin, force_mode, transition_time, s_current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, double current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=(float)current;

	cap_force(pin, force_mode, transition_time, s_current, voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, float *current, float voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=voltage;

	cap_force(pin, force_mode, transition_time, current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, float *current, double voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	sfloat s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=(float)voltage;

	cap_force(pin, force_mode, transition_time, current, s_voltage, c_range, v_range, ihalf, compensation,is_ext_ref);
}

void  cap_force(short pin,short force_mode,float transition_time, float *current, float *voltage, short c_range, short v_range, bool ihalf, unsigned char compensation ,unsigned char is_ext_ref)
{
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	float value_init[CSC_MAX_SITES],value_end[CSC_MAX_SITES],value_current[CSC_MAX_SITES],value_current_temp[CSC_MAX_SITES];

	start_pin_ptr = group_selection(pin); 
	pin_ptr = start_pin_ptr;

	do
	{

	pin = pin_ptr->grouppin;

 	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:	
				break;

			case XVI:
				if (force_mode == FORCE_VOLTAGE) value_init[i]=XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index];else
				if (force_mode == FORCE_CURRENT) value_init[i]=XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index];
				break;

			case DVI:					
				if (force_mode == FORCE_VOLTAGE) value_init[i]=DVI_Used[i].DVI_slot->debug_voltage_out[DVI_Used[i].DVI_channel];else
				if (force_mode == FORCE_CURRENT) value_init[i]=DVI_Used[i].DVI_slot->debug_current_out[DVI_Used[i].DVI_channel];
				break;

			case OVI:
			case OVI_S:
				if (force_mode == FORCE_VOLTAGE) value_init[i]=OVI_Used[i].OVI_slot->m_voltage_setting[OVI_Used[i].OVI_channel];else
				if (force_mode == FORCE_CURRENT) value_init[i]=OVI_Used[i].OVI_slot->m_current_setting[OVI_Used[i].OVI_channel];
				break;	
				
			case OV2:
				if (force_mode == FORCE_VOLTAGE) value_init[i]=OV2_Used[i].OV2_slot->debug_volt_out[OV2_Used[i].OV2_channel];else
				if (force_mode == FORCE_CURRENT) value_init[i]=OV2_Used[i].OV2_slot->debug_curr_out[OV2_Used[i].OV2_channel];
				break;
				
			case HVS:
				if (force_mode == FORCE_VOLTAGE) value_init[i]=HVS_Used[i].HVS_slot->get_voltage_setting();else
				if (force_mode == FORCE_CURRENT) value_init[i]=HVS_Used[i].HVS_slot->get_current_setting();
				break;	
				
			case OFS:
				if (force_mode == FORCE_VOLTAGE) value_init[i]=OFS_Used[i].OFS_slot->get_voltage_setting();else
				if (force_mode == FORCE_CURRENT) value_init[i]=OFS_Used[i].OFS_slot->get_current_setting();
				break;
				
			default:
				mytext.text_in_box(40,10,"dc_force() not executable for a relay pin");
				exit(0);
			}
			if ( fabs(value_init[i]-(-1000.0))<0.001 )
			{
				mytext.text_in_box(40,10,"cap_force can't use after awg");
				exit(0);
			}
			value_current_temp[i]=value_init[i];
			if ( force_mode == FORCE_VOLTAGE )
			{
				value_end[i]=voltage[i];
			}
			else
			{
				value_end[i]=current[i];
			}
		}		
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
	//////////////////////////////////////////////////////////////////////////
	for ( i=0; i<100; i++ )
	{
		for( int j = 0; j < max_sites ; j++ )
		{
			if(active_site[j])
			{
				value_current_temp[j]=value_current_temp[j]+(value_end[j]-value_current_temp[j])/19.47;
				value_current[j]=value_current_temp[j]+(value_end[j]-value_init[j])*0.51297286430197175/100.0;
			}
		}
		if (i==99)
		{
			value_current[j]=value_end[i];
		}
		if ( force_mode == FORCE_VOLTAGE )
		{
			dc_force(pin,current,value_current,c_range,v_range,ihalf,compensation,is_ext_ref);
		}
		else
		{
			dc_force(pin,value_current,voltage,c_range,v_range,ihalf,compensation,is_ext_ref);
		}
		delay_us(transition_time*1000.0/100.0);//延时要调整过，不同板卡，不同force，不同site都有关系
	}

}

void awg_load_voltage(short pin,  unsigned int start_addr, unsigned int stop_addr, double *awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int i;
	sdouble_wf s_awg_data;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_awg_data[i]=awg_data;
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_load_voltage(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,is_ext_ref);
}

void awg_load_voltage(short pin,  unsigned int *s_start_addr, unsigned int *s_stop_addr, double *awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int i;
	sdouble_wf s_awg_data;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_awg_data[i]=awg_data;

	awg_load_voltage(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,is_ext_ref);
}

void awg_load_voltage(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf s_awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int i;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_load_voltage(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,is_ext_ref);
}

void awg_load_voltage(short pin, unsigned int *s_start_addr, unsigned int *s_stop_addr, sdouble_wf s_awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				if (polarity==-1)
				{
					if (DVI_Used[i].DVI_channel_ID==DVI_CH_0)
					{
						polarity = DVI_Used[i].DVI_slot->debug_voltage_polarity[0];
					}
					else
					{
						polarity = DVI_Used[i].DVI_slot->debug_voltage_polarity[1];
					}
				}
				DVI_Used[i].DVI_slot->dvi_awg_load_voltage(DVI_Used[i].DVI_channel_ID,range,polarity,is_ext_ref,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OV2:
				OV2_Used[i].OV2_slot->ov2_awg_load_voltage(OV2_Used[i].OV2_channel_ID,range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case HVS:
				HVS_Used[i].HVS_slot->hvs_awg_load_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OFS:
				OFS_Used[i].OFS_slot->ofs_awg_load_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				PVI_Used[i].PVI_slot->pv3_awg_load_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;
#endif
			}
		}
		
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);
}

void awg_read_voltage(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf s_awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int i;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_read_voltage(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,is_ext_ref);
}

void awg_read_voltage(short pin, unsigned int *s_start_addr, unsigned int *s_stop_addr, sdouble_wf s_awg_data, unsigned short range, char polarity,unsigned char is_ext_ref)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				DVI_Used[i].DVI_slot->dvi_awg_read_voltage(DVI_Used[i].DVI_channel_ID,range,polarity,is_ext_ref,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OV2:
				OV2_Used[i].OV2_slot->ov2_awg_read_voltage(OV2_Used[i].OV2_channel_ID,range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case HVS:
				HVS_Used[i].HVS_slot->hvs_awg_read_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OFS:
				OFS_Used[i].OFS_slot->ofs_awg_read_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;
				
#if BoardRev_SXHB >= 261
			case PVI:
				PVI_Used[i].PVI_slot->pv3_awg_read_voltage(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void awg_select_voltage(short pin,unsigned int start_addr, unsigned int stop_addr, unsigned int loopback_addr, double awg_interval, unsigned char awg_mode, unsigned short range, char polarity, unsigned char is_ext_ref)
{
	int i;
	suint s_start_addr,s_stop_addr,s_loopback_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
			s_loopback_addr[i]=loopback_addr;
		}
	}

	awg_select_voltage(pin,s_start_addr,s_stop_addr,s_loopback_addr,awg_interval,awg_mode,range,polarity,is_ext_ref);
}

void awg_select_voltage(short pin,unsigned int *s_start_addr, unsigned int *s_stop_addr, unsigned int *s_loopback_addr, double awg_interval, unsigned char awg_mode, unsigned short range, char polarity, unsigned char is_ext_ref)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				DVI_AWG_MODE_e dvi_awg_mode;

				switch(awg_mode)
				{
				case AWG_SINGLE:dvi_awg_mode = DVI_AWG_SINGLE;
					break;
				case AWG_LOOP:dvi_awg_mode = DVI_AWG_LOOP;
					break;
				}

				if (polarity==-1)
				{
					if (DVI_Used[i].DVI_channel_ID==DVI_CH_0)
					{
						polarity = DVI_Used[i].DVI_slot->debug_voltage_polarity[0];
					}
					else
					{
						polarity = DVI_Used[i].DVI_slot->debug_voltage_polarity[1];
					}
				}

				DVI_Used[i].DVI_slot->dvi_awg_select_voltage(DVI_Used[i].DVI_channel_ID,range,polarity,is_ext_ref,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,dvi_awg_mode);
				break;

			case OV2:
				OV2_AWG_MODE_e ov2_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:ov2_awg_mode = OV2_AWG_SINGLE;
					break;
				case AWG_LOOP:ov2_awg_mode = OV2_AWG_LOOP;
					break;
				}
				OV2_Used[i].OV2_slot->ov2_awg_select_voltage(OV2_Used[i].OV2_channel_ID,range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,ov2_awg_mode);
				break;

			case HVS:
				HVS_AWG_MODE_e hvs_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:hvs_awg_mode = HVS_AWG_SINGLE;
					break;
				case AWG_LOOP:hvs_awg_mode = HVS_AWG_LOOP;
					break;
				}
				HVS_Used[i].HVS_slot->hvs_awg_select_voltage(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,hvs_awg_mode);
				break;

			case OFS:
				OFS_AWG_MODE_e ofs_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:ofs_awg_mode = OFS_AWG_SINGLE;
					break;
				case AWG_LOOP:ofs_awg_mode = OFS_AWG_LOOP;
					break;
				}
				OFS_Used[i].OFS_slot->ofs_awg_select_voltage(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,ofs_awg_mode);
				break;

#if BoardRev_SXHB >= 261
				case PVI:
				PV3_AWG_MODE_e pvi_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:pvi_awg_mode = PV3_AWG_SINGLE;
					break;
				case AWG_LOOP:pvi_awg_mode = PV3_AWG_LOOP;
					break;
				}
				PVI_Used[i].PVI_slot->pv3_awg_select_voltage(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,pvi_awg_mode);
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void awg_load_current(short pin, unsigned int start_addr, unsigned int stop_addr, double *awg_data, unsigned short range,  char polarity, unsigned char i_half)
{
	int i;
	sdouble_wf s_awg_data;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_awg_data[i]=awg_data;
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_load_current(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,i_half);
}

void awg_load_current(short pin,  unsigned int *s_start_addr, unsigned int *s_stop_addr, double *awg_data, unsigned short range,  char polarity, unsigned char i_half)
{
	int i;
	sdouble_wf s_awg_data;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_awg_data[i]=awg_data;

	awg_load_current(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,i_half);
}

void awg_load_current(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf s_awg_data, unsigned short range,  char polarity, unsigned char i_half)
{
	int i;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_load_current(pin,s_start_addr,s_stop_addr,s_awg_data,range,polarity,i_half);
}

void awg_load_current(short pin, unsigned int *s_start_addr, unsigned int *s_stop_addr, sdouble_wf s_awg_data, unsigned short range, char polarity, unsigned char i_half)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				DVI_Used[i].DVI_slot->dvi_awg_load_current(DVI_Used[i].DVI_channel_ID,range,i_half,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OV2:
				OV2_Used[i].OV2_slot->ov2_awg_load_current(OV2_Used[i].OV2_channel_ID,range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case HVS:
				HVS_Used[i].HVS_slot->hvs_awg_load_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OFS:
				OFS_Used[i].OFS_slot->ofs_awg_load_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				PVI_Used[i].PVI_slot->pv3_awg_load_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void awg_read_current(short pin, unsigned int start_addr, unsigned int stop_addr, sdouble_wf s_awg_data,  unsigned short range, char polarity, unsigned char i_half)
{
	int i;
	suint s_start_addr,s_stop_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
		}
	}

	awg_read_current(pin,start_addr,stop_addr,s_awg_data,range,polarity,i_half);
}

void awg_read_current(short pin, unsigned int *s_start_addr, unsigned int *s_stop_addr, sdouble_wf s_awg_data, unsigned short range,  char polarity, unsigned char i_half)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				DVI_Used[i].DVI_slot->dvi_awg_read_current(DVI_Used[i].DVI_channel_ID,range,i_half,polarity,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OV2:
				OV2_Used[i].OV2_slot->ov2_awg_read_current(OV2_Used[i].OV2_channel_ID,range,polarity,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case HVS:
				HVS_Used[i].HVS_slot->hvs_awg_read_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

			case OFS:
				OFS_Used[i].OFS_slot->ofs_awg_read_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				PVI_Used[i].PVI_slot->pv3_awg_read_current(range,s_start_addr[i],s_stop_addr[i],s_awg_data[i]);
				break;
#endif	
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void awg_select_current(short pin,unsigned int start_addr, unsigned int stop_addr, unsigned int loopback_addr, double awg_interval, unsigned char awg_mode, unsigned short range, unsigned char i_half)
{
	int i;
	suint s_start_addr,s_stop_addr,s_loopback_addr;

	for(i = 0; i < max_sites ; i++ )
	{
		if(active_site[i]) 
		{
			s_start_addr[i]=start_addr;
			s_stop_addr[i]=stop_addr;
			s_loopback_addr[i]=loopback_addr;
		}
	}

	awg_select_current(pin,s_start_addr,s_stop_addr,s_loopback_addr,awg_interval,awg_mode,range,i_half);
}

void awg_select_current(short pin,unsigned int *s_start_addr, unsigned int *s_stop_addr, unsigned int *s_loopback_addr, double awg_interval, unsigned char awg_mode, unsigned short range, unsigned char i_half)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				DVI_AWG_MODE_e dvi_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:dvi_awg_mode = DVI_AWG_SINGLE;
					break;
				case AWG_LOOP:dvi_awg_mode = DVI_AWG_LOOP;
					break;
				}
				DVI_Used[i].DVI_slot->dvi_awg_select_current(DVI_Used[i].DVI_channel_ID,range,i_half,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,dvi_awg_mode);
				break;

			case OV2:
				OV2_AWG_MODE_e ov2_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:ov2_awg_mode = OV2_AWG_SINGLE;
					break;
				case AWG_LOOP:ov2_awg_mode = OV2_AWG_LOOP;
					break;
				}
				OV2_Used[i].OV2_slot->ov2_awg_select_current(OV2_Used[i].OV2_channel_ID,range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,ov2_awg_mode);
				break;

			case HVS:
				HVS_AWG_MODE_e hvs_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:hvs_awg_mode = HVS_AWG_SINGLE;
					break;
				case AWG_LOOP:hvs_awg_mode = HVS_AWG_LOOP;
					break;
				}
				HVS_Used[i].HVS_slot->hvs_awg_select_current(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,hvs_awg_mode);
				break;

			case OFS:
				OFS_AWG_MODE_e ofs_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:ofs_awg_mode = OFS_AWG_SINGLE;
					break;
				case AWG_LOOP:ofs_awg_mode = OFS_AWG_LOOP;
					break;
				}
				OFS_Used[i].OFS_slot->ofs_awg_select_current(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,ofs_awg_mode);
				break;

#if BoardRev_SXHB >= 261
				case PVI:
				PV3_AWG_MODE_e pvi_awg_mode;
				switch(awg_mode)
				{
				case AWG_SINGLE:pvi_awg_mode = PV3_AWG_SINGLE;
					break;
				case AWG_LOOP:pvi_awg_mode = PV3_AWG_LOOP;
					break;
				}
				PVI_Used[i].PVI_slot->pv3_awg_select_current(range,s_start_addr[i],s_stop_addr[i],s_loopback_addr[i],awg_interval,pvi_awg_mode);
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);
}

extern void  awg_arm(short pin0, unsigned char awg_type0, double awg_interval0, sdouble_wf awg_data0, unsigned int awg_num0, unsigned short range0, unsigned char is_ext0,unsigned char awg_mode0, 
					 short pin1, unsigned char awg_type1, double awg_interval1, sdouble_wf awg_data1, unsigned int awg_num1, unsigned short range1, unsigned char is_ext1,unsigned char awg_mode1, 
					 short pin2, unsigned char awg_type2, double awg_interval2, sdouble_wf awg_data2, unsigned int awg_num2, unsigned short range2, unsigned char is_ext2,unsigned char awg_mode2, 
					 short pin3, unsigned char awg_type3, double awg_interval3, sdouble_wf awg_data3, unsigned int awg_num3, unsigned short range3, unsigned char is_ext3,unsigned char awg_mode3,
					 short pin4, unsigned char awg_type4, double awg_interval4, sdouble_wf awg_data4, unsigned int awg_num4, unsigned short range4, unsigned char is_ext4,unsigned char awg_mode4,
					 short pin5, unsigned char awg_type5, double awg_interval5, sdouble_wf awg_data5, unsigned int awg_num5, unsigned short range5, unsigned char is_ext5,unsigned char awg_mode5)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	int addr_buf[21]={0};
	suint s_start_addr0,s_stop_addr0,s_loopback_addr0;
	suint s_start_addr1,s_stop_addr1,s_loopback_addr1;
	suint s_start_addr2,s_stop_addr2,s_loopback_addr2;
	suint s_start_addr3,s_stop_addr3,s_loopback_addr3;
	suint s_start_addr4,s_stop_addr4,s_loopback_addr4;
	suint s_start_addr5,s_stop_addr5,s_loopback_addr5;
	
	if (pin0!=-1)
	{
		pin_ptr = group_selection(pin0);
		
		do
		{
			pin0 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin0,i);
					
					s_start_addr0[i]=addr_buf[Pin_Type_Used[pin0][i].Slot-1];
					s_stop_addr0[i]=addr_buf[Pin_Type_Used[pin0][i].Slot-1]+awg_num0;
					s_loopback_addr0[i]=s_stop_addr0[i];
					addr_buf[Pin_Type_Used[pin0][i].Slot-1]=s_stop_addr0[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}
	if (pin1!=-1)
	{
		pin_ptr = group_selection(pin1);
		
		do
		{
			pin1 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin1,i);
					
					s_start_addr1[i]=addr_buf[Pin_Type_Used[pin1][i].Slot-1];
					s_stop_addr1[i]=addr_buf[Pin_Type_Used[pin1][i].Slot-1]+awg_num1;
					s_loopback_addr1[i]=s_stop_addr1[i];
					addr_buf[Pin_Type_Used[pin1][i].Slot-1]=s_stop_addr1[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}

	if (pin2!=-1)
	{
		pin_ptr = group_selection(pin2);
		
		do
		{
			pin2 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin2,i);
					
					s_start_addr2[i]=addr_buf[Pin_Type_Used[pin2][i].Slot-1];
					s_stop_addr2[i]=addr_buf[Pin_Type_Used[pin2][i].Slot-1]+awg_num2;
					s_loopback_addr2[i]=s_stop_addr2[i];
					addr_buf[Pin_Type_Used[pin2][i].Slot-1]=s_stop_addr2[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}

	if (pin3!=-1)
	{
		pin_ptr = group_selection(pin3);
		
		do
		{
			pin3 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin3,i);
					
					s_start_addr3[i]=addr_buf[Pin_Type_Used[pin3][i].Slot-1];
					s_stop_addr3[i]=addr_buf[Pin_Type_Used[pin3][i].Slot-1]+awg_num3;
					s_loopback_addr3[i]=s_stop_addr3[i];
					addr_buf[Pin_Type_Used[pin3][i].Slot-1]=s_stop_addr3[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}
	
	if (pin4!=-1)
	{
		pin_ptr = group_selection(pin4);
		
		do
		{
			pin4 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin4,i);
					
					s_start_addr4[i]=addr_buf[Pin_Type_Used[pin4][i].Slot-1];
					s_stop_addr4[i]=addr_buf[Pin_Type_Used[pin4][i].Slot-1]+awg_num4;
					s_loopback_addr4[i]=s_stop_addr4[i];
					addr_buf[Pin_Type_Used[pin4][i].Slot-1]=s_stop_addr4[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}
	
	if (pin5!=-1)
	{
		pin_ptr = group_selection(pin5);
		
		do
		{
			pin5 = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin5,i);
					
					s_start_addr5[i]=addr_buf[Pin_Type_Used[pin5][i].Slot-1];
					s_stop_addr5[i]=addr_buf[Pin_Type_Used[pin5][i].Slot-1]+awg_num5;
					s_loopback_addr5[i]=s_stop_addr5[i];
					addr_buf[Pin_Type_Used[pin5][i].Slot-1]=s_stop_addr5[i]+1;
				}
			}  
			pin_ptr = pin_ptr->nextptr;
		}  while (pin_ptr != NULL);	
	}	
	
	if(pin0!=-1)
	{
		if (awg_type0==AWG_VOLTAGE)
		{
			awg_load_voltage(pin0,s_start_addr0,s_stop_addr0,awg_data0,range0,-1,is_ext0);
			awg_select_voltage(pin0,s_start_addr0,s_stop_addr0,s_loopback_addr0, awg_interval0, awg_mode0, range0,-1,is_ext0);
		}
		else
		{
			awg_load_current(pin0,s_start_addr0,s_stop_addr0,awg_data0,range0,-1,is_ext0);
			awg_select_current(pin0,s_start_addr0,s_stop_addr0,s_loopback_addr0, awg_interval0, awg_mode0, range0,is_ext0);
		}
	}
	
	if(pin1!=-1)
	{
		if (awg_type1==AWG_VOLTAGE)
		{
			awg_load_voltage(pin1,s_start_addr1,s_stop_addr1,awg_data1,range1,-1,is_ext1);
			awg_select_voltage(pin1,s_start_addr1,s_stop_addr1,s_loopback_addr1, awg_interval1, awg_mode1, range1,-1,is_ext1);
		}
		else
		{
			awg_load_current(pin1,s_start_addr1,s_stop_addr1,awg_data1,range1,-1,is_ext1);
			awg_select_current(pin1,s_start_addr1,s_stop_addr1,s_loopback_addr1, awg_interval1, awg_mode1, range1,is_ext1);
		}
	}
	if(pin2!=-1)
	{
		if (awg_type2==AWG_VOLTAGE)
		{
			awg_load_voltage(pin2,s_start_addr2,s_stop_addr2,awg_data2,range2,-1,is_ext2);
			awg_select_voltage(pin2,s_start_addr2,s_stop_addr2,s_loopback_addr2, awg_interval2, awg_mode2, range2,-1,is_ext2);
		}
		else
		{
			awg_load_current(pin2,s_start_addr2,s_stop_addr2,awg_data2,range2,-1,is_ext2);
			awg_select_current(pin2,s_start_addr2,s_stop_addr2,s_loopback_addr2, awg_interval2, awg_mode2, range2,is_ext2);
		}
	}
	if(pin3!=-1)
	{
		if (awg_type3==AWG_VOLTAGE)
		{
			awg_load_voltage(pin3,s_start_addr3,s_stop_addr3,awg_data3,range3,-1,is_ext3);
			awg_select_voltage(pin3,s_start_addr3,s_stop_addr3,s_loopback_addr3, awg_interval3, awg_mode3, range3,-1,is_ext3);
		}
		else
		{
			awg_load_current(pin3,s_start_addr3,s_stop_addr3,awg_data3,range3,-1,is_ext3);
			awg_select_current(pin3,s_start_addr3,s_stop_addr3,s_loopback_addr3, awg_interval3, awg_mode3, range3,is_ext3);
		}
	}
	if(pin4!=-1)
	{
		if (awg_type4==AWG_VOLTAGE)
		{
			awg_load_voltage(pin4,s_start_addr4,s_stop_addr4,awg_data4,range4,-1,is_ext4);
			awg_select_voltage(pin4,s_start_addr4,s_stop_addr4,s_loopback_addr4, awg_interval4, awg_mode4, range4,-1,is_ext4);
		}
		else
		{
			awg_load_current(pin4,s_start_addr4,s_stop_addr4,awg_data4,range4,-1,is_ext4);
			awg_select_current(pin4,s_start_addr4,s_stop_addr4,s_loopback_addr4, awg_interval4, awg_mode4, range4,is_ext4);
		}
	}	
	if(pin5!=-1)
	{
		if (awg_type5==AWG_VOLTAGE)
		{
			awg_load_voltage(pin5,s_start_addr5,s_stop_addr5,awg_data5,range5,-1,is_ext5);
			awg_select_voltage(pin5,s_start_addr5,s_stop_addr5,s_loopback_addr5, awg_interval5, awg_mode5, range5,-1,is_ext5);
		}
		else
		{
			awg_load_current(pin5,s_start_addr5,s_stop_addr5,awg_data5,range5,-1,is_ext5);
			awg_select_current(pin5,s_start_addr5,s_stop_addr5,s_loopback_addr5, awg_interval5, awg_mode5, range5,is_ext5);
		}
	}
}

void awg_enable(short pin, unsigned int awg_delay)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	int	slot;
	bool dvi_any_cards_used	= false;
	bool ov2_any_cards_used	= false;
	bool hvs_any_cards_used	= false;
	bool ofs_any_cards_used	= false;
	bool pvi_any_cards_used	= false;

	for(slot=0; slot<21;slot++)
	{
		DVI_Card_Used[slot].block_programming = false;
		OV2_Card_Used[slot].block_programming[0] = false;
		HVS_Card_Used[slot].block_programming = false;
		OFS_Card_Used[slot].block_programming = false;
		PVI_Card_Used[slot].block_programming = false;
	}

	pin_ptr = group_selection(pin);

	do
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
					if(!dvi_any_cards_used)
						dvi_any_cards_used=true;
					DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;
				break;

			case OV2:
					if(!ov2_any_cards_used)
						ov2_any_cards_used=true;
					OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[0]=true;
				break;

			case HVS:
					if(!hvs_any_cards_used)
						hvs_any_cards_used=true;
					HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;
				break;

			case OFS:
					if(!ofs_any_cards_used)
						ofs_any_cards_used=true;
					OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;
				break;

			case PVI:
					if(!pvi_any_cards_used)
						pvi_any_cards_used=true;
					PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;
				break;
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
	
	if(dvi_any_cards_used)
	for(slot=0; slot<21;slot++)	if(DVI_Card_Used[slot].block_programming==true)
	{
		DVI_Card_Used[slot].card_ptr->dvi_awg_enable(awg_delay);
	} 

	if(ov2_any_cards_used)
	for(slot=0; slot<21;slot++)	if(OV2_Card_Used[slot].block_programming[0]==true)
	{
		OV2_Card_Used[slot].card_ptr->ov2_awg_enable(awg_delay);
	} 

	if(hvs_any_cards_used)
	for(slot=0; slot<21;slot++)	if(HVS_Card_Used[slot].block_programming==true)
	{
		HVS_Card_Used[slot].card_ptr->hvs_awg_enable(awg_delay);
	} 

	if(ofs_any_cards_used)
	for(slot=0; slot<21;slot++)	if(OFS_Card_Used[slot].block_programming==true)
	{
		OFS_Card_Used[slot].card_ptr->ofs_awg_enable(awg_delay);
	} 

#if BoardRev_SXHB >= 261
	if(pvi_any_cards_used)
	for(slot=0; slot<21;slot++)	if(PVI_Card_Used[slot].block_programming==true)
	{
		PVI_Card_Used[slot].card_ptr->pv3_awg_enable(awg_delay);
	} 
#endif
}

void awg_start(short pin, UINT32 delay_time)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;	
	int	slot,channel;	
	unsigned short awg_board_no[21];

	for ( slot = 0; slot< 21; slot++ )
	{
		awg_board_no[slot] = 0xffff;
	}

	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				awg_board_no[DVI_Used[i].DVI_slot->board_no]=DVI_Used[i].DVI_slot->board_no;
				for (channel=0;channel<2;channel++)
				{
					if ( (DVI_Used[i].DVI_slot->card.dvi_awg_ready>>(channel*2+1))&0x0001==0x0001 )
					{
						DVI_Used[i].DVI_slot->debug_voltage_out[channel] = -1000;//不定数
					}
					if ( (DVI_Used[i].DVI_slot->card.dvi_awg_ready>>(channel*2))&0x0001==0x0001 )
					{
						DVI_Used[i].DVI_slot->debug_current_out[channel] = -1000;//不定数
					}
				}				
				break;

			case OV2:
				awg_board_no[OV2_Used[i].OV2_slot->board_no]=OV2_Used[i].OV2_slot->board_no;
				for (channel=0;channel<8;channel++)
				{
					if ( (OV2_Used[i].OV2_slot->card.ov2_awg_ready>>(channel*2))&0x0001==0x0001 )
					{
						OV2_Used[i].OV2_slot->debug_volt_out[channel] = -1000;//不定数
					}
					if ( (OV2_Used[i].OV2_slot->card.ov2_awg_ready>>(channel*2+1))&0x0001==0x0001 )
					{
						OV2_Used[i].OV2_slot->debug_curr_out[channel] = -1000;//不定数
					}
				}
				break;

			case HVS:
				awg_board_no[HVS_Used[i].HVS_slot->board_no]=HVS_Used[i].HVS_slot->board_no;
//				if ( (HVS_Used[i].HVS_slot->card.hvs_awg_ready>>1)==0x0001 )
//				{
//					HVS_Used[i].HVS_slot->m_voltage_setting = -1000;//不定数
//				}
//				if ( (HVS_Used[i].HVS_slot->card.hvs_awg_ready>>0)==0x0001 )
//				{
//					HVS_Used[i].HVS_slot->m_current_setting = -1000;//不定数
//				}
				break;

			case OFS:
				awg_board_no[OFS_Used[i].OFS_slot->board_no]=OFS_Used[i].OFS_slot->board_no;
//				if ( (OFS_Used[i].OFS_slot->card.ofs_awg_ready>>1)==0x0001 )
//				{
//					OFS_Used[i].OFS_slot->m_voltage_setting = -1000;//不定数
//				}
//				if ( (OFS_Used[i].OFS_slot->card.ofs_awg_ready>>0)==0x0001 )
//				{
//					OFS_Used[i].OFS_slot->m_current_setting = -1000;//不定数
//				}
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				awg_board_no[PVI_Used[i].PVI_slot->board_no]=PVI_Used[i].PVI_slot->board_no;
//				if ( (PVI_Used[i].PVI_slot->card.pv3_awg_ready>>0)==0x0001 )
//				{
//					PVI_Used[i].PVI_slot->m_voltage_setting = -1000;//不定数
//				}
//				if ( (PVI_Used[i].PVI_slot->card.pv3_awg_ready>>1)==0x0001 )
//				{
//					PVI_Used[i].PVI_slot->m_current_setting = -1000;//不定数
//				}
				break;
#endif

			case OVI:
				awg_board_no[OVI_Used[i].OVI_slot->board_no]=OVI_Used[i].OVI_slot->board_no;
				break;
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

	system_awg_sync_enable(awg_board_no[0],awg_board_no[1],awg_board_no[2],
		awg_board_no[3],awg_board_no[4],awg_board_no[5],
		awg_board_no[6],awg_board_no[7],awg_board_no[8],
		awg_board_no[9],awg_board_no[10],awg_board_no[11],
		awg_board_no[12],awg_board_no[13],awg_board_no[14],
		awg_board_no[15],awg_board_no[16],awg_board_no[17],
		awg_board_no[18],awg_board_no[19],awg_board_no[20]);
	
	system_awg_start(delay_time);
}

void  awg_run(short pin, unsigned int awg_delay, UINT32 delay_time)
{
	awg_enable(pin,awg_delay);
	awg_start(pin,delay_time);
}

void awg_stop(short pin, unsigned char awg_type, unsigned int stop_size, double stop_interval, double *stop_data)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int	slot;
	bool dvi_any_cards_used	= false;
	bool ov2_any_cards_used	= false;
	bool hvs_any_cards_used	= false;
	bool ofs_any_cards_used	= false;
	bool pvi_any_cards_used	= false;

	for(slot=0; slot<21;slot++)
	{
		DVI_Card_Used[slot].awg_channel_mask = 0x0;
		OV2_Card_Used[slot].awg_channel_mask = 0x0;
		HVS_Card_Used[slot].awg_channel_mask = 0x0;
		OFS_Card_Used[slot].awg_channel_mask = 0x0;
		PVI_Card_Used[slot].awg_channel_mask = 0x0;
	}

	pin_ptr = group_selection(pin);

	do
	{	
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				if(!dvi_any_cards_used)
					dvi_any_cards_used=true;
				DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].awg_channel_mask|=DVI_Used[i].DVI_channel_ID;
				break;	

			case OV2:
				if(!ov2_any_cards_used)
					ov2_any_cards_used=true;
				OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].awg_channel_mask|=OV2_Used[i].OV2_channel_ID;
				break;
				
			case HVS:
				if(!hvs_any_cards_used)
					hvs_any_cards_used=true;
				HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].awg_channel_mask|=0x0001;
				break;
				
			case OFS:
				if(!ofs_any_cards_used)
					ofs_any_cards_used=true;
				OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].awg_channel_mask|=0x0001;
				break;
				
#if BoardRev_SXHB >= 261
			case PVI:
				if(!pvi_any_cards_used)
					pvi_any_cards_used=true;
				PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].awg_channel_mask|=0x0001;
				break;	
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

	if(dvi_any_cards_used)
	for(slot=0; slot<21;slot++)	if((DVI_Card_Used[slot].awg_channel_mask!=0x0))
	{
		DVI_Card_Used[slot].card_ptr->dvi_awg_stop(DVI_Card_Used[slot].awg_channel_mask,(DVI_AWG_TYPE)awg_type,stop_size,stop_interval,stop_data);
	} 

	if(ov2_any_cards_used)
	for(slot=0; slot<21;slot++)	if((OV2_Card_Used[slot].awg_channel_mask!=0x0))
	{
		OV2_Card_Used[slot].card_ptr->ov2_awg_stop(OV2_Card_Used[slot].awg_channel_mask,(OV2_AWG_TYPE)awg_type,stop_size,stop_interval,stop_data);
	} 

	if(hvs_any_cards_used)
	for(slot=0; slot<21;slot++)	if((HVS_Card_Used[slot].awg_channel_mask!=0x0))
	{
		HVS_Card_Used[slot].card_ptr->hvs_awg_stop((HVS_AWG_TYPE)awg_type,stop_size,stop_interval,stop_data);
	} 

	if(ofs_any_cards_used)
	for(slot=0; slot<21;slot++)	if((OFS_Card_Used[slot].awg_channel_mask!=0x0))
	{
		OFS_Card_Used[slot].card_ptr->ofs_awg_stop((OFS_AWG_TYPE)awg_type,stop_size,stop_interval,stop_data);
	} 

#if BoardRev_SXHB >= 261
	if(pvi_any_cards_used)
	for(slot=0; slot<21;slot++)	if((PVI_Card_Used[slot].awg_channel_mask!=0x0))
	{
		PVI_Card_Used[slot].card_ptr->pv3_awg_stop((PV3_AWG_TYPE)awg_type,stop_size,stop_interval,stop_data);
	} 
#endif
}

void awg_measure(short pin, unsigned int num_samples, double p_sample, sdouble_wf sample, unsigned char meas_mode, unsigned int meas_time1, unsigned int meas_time2, unsigned int meas_time3, unsigned int meas_time4, UINT32 delay_time)
{
	int	i,j,slot;

	short Source_type;

	bool dvi_any_cards_used	= false;
	bool ov2_any_cards_used	= false;
	bool hvs_any_cards_used	= false;
	bool ofs_any_cards_used	= false;
	bool pvi_any_cards_used	= false;

	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin);

#if BoardRev_SXHB >= 270
	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				if (p_sample==0)
				{
					p_sample=4;
				}
				
				if (sample==NULL)
				{
					DVI_Used[i].DVI_slot->dvi_measure(num_samples,p_sample,NULL,(DVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4,delay_time);
				}
				else
				{
					DVI_Used[i].DVI_slot->dvi_measure(num_samples,p_sample,sample[i],(DVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4,delay_time);
				}
				break;

			case OV2:
				OV2_MEAS_ID_e OV2_meas_index;
				for(j=0;j<OV2_MEAS_NUMBER;j++)
				{
					if( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[j] )
					{
						if(j==0)
						{
							OV2_meas_index=OV2_MEAS_0; 
							break;
						}
						else
						{
							OV2_meas_index=OV2_MEAS_1;
							break;
						}
					}
				}

				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OV2_Used[i].OV2_slot->ov2_measure(OV2_meas_index,num_samples,p_sample,NULL,(OV2_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4,delay_time);
				}
				else
				{
					OV2_Used[i].OV2_slot->ov2_measure(OV2_meas_index,num_samples,p_sample,sample[i],(OV2_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4,delay_time);
				}
				break;

			case HVS:
				if (p_sample==0)
				{
					p_sample=4;
				}
				
				if (sample==NULL)
				{
					HVS_Used[i].HVS_slot->hvs_measure(num_samples,p_sample,NULL,(HVS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					HVS_Used[i].HVS_slot->hvs_measure(num_samples,p_sample,sample[i],(HVS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

			case OFS:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OFS_Used[i].OFS_slot->ofs_measure(num_samples,p_sample,NULL,(OFS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					OFS_Used[i].OFS_slot->ofs_measure(num_samples,p_sample,sample[i],(OFS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					PVI_Used[i].PVI_slot->pv3_measure(num_samples,p_sample,NULL,(PV3_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					PVI_Used[i].PVI_slot->pv3_measure(num_samples,p_sample,sample[i],(PV3_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}			
				break;
#endif
			case OVI:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OVI_Used[i].OVI_slot->ovi_measure(num_samples,p_sample,NULL,(OVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					OVI_Used[i].OVI_slot->ovi_measure(num_samples,p_sample,sample[i],(OVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;
				
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;
	
	}  while (pin_ptr != NULL);	
#else
	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				if (p_sample==0)
				{
					p_sample=4;
				}
				
				if (sample==NULL)
				{
					DVI_Used[i].DVI_slot->dvi_measure(num_samples,p_sample,NULL,(DVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					DVI_Used[i].DVI_slot->dvi_measure(num_samples,p_sample,sample[i],(DVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

			case OV2:
				OV2_MEAS_ID_e OV2_meas_index;
				for(j=0;j<OV2_MEAS_NUMBER;j++)
				{
					if( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[j] )
					{
						if(j==0)
						{
							OV2_meas_index=OV2_MEAS_0; 
							break;
						}
						else
						{
							OV2_meas_index=OV2_MEAS_1;
							break;
						}
					}
				}

				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OV2_Used[i].OV2_slot->ov2_measure(OV2_meas_index,num_samples,p_sample,NULL,(OV2_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					OV2_Used[i].OV2_slot->ov2_measure(OV2_meas_index,num_samples,p_sample,sample[i],(OV2_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

			case HVS:
				if (p_sample==0)
				{
					p_sample=4;
				}
				
				if (sample==NULL)
				{
					HVS_Used[i].HVS_slot->hvs_measure(num_samples,p_sample,NULL,(HVS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					HVS_Used[i].HVS_slot->hvs_measure(num_samples,p_sample,sample[i],(HVS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

			case OFS:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OFS_Used[i].OFS_slot->ofs_measure(num_samples,p_sample,NULL,(OFS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					OFS_Used[i].OFS_slot->ofs_measure(num_samples,p_sample,sample[i],(OFS_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					PVI_Used[i].PVI_slot->pv3_measure(num_samples,p_sample,NULL,(PV3_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					PVI_Used[i].PVI_slot->pv3_measure(num_samples,p_sample,sample[i],(PV3_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}			
				break;
#endif
			case OVI:
				if (p_sample==0)
				{
					p_sample=4;
				}

				if (sample==NULL)
				{
					OVI_Used[i].OVI_slot->ovi_measure(num_samples,p_sample,NULL,(OVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				else
				{
					OVI_Used[i].OVI_slot->ovi_measure(num_samples,p_sample,sample[i],(OVI_MEAS_MODE_e)meas_mode,meas_time1,meas_time2,meas_time3,meas_time4);
				}
				break;
				
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;
	
	}  while (pin_ptr != NULL);	
#endif

	if (meas_mode==MEAS_NORMAL)
	{
		for(slot=0; slot<21;slot++)
		{
			DVI_Card_Used[slot].block_programming = false;
			OV2_Card_Used[slot].block_programming[0] = false;
			HVS_Card_Used[slot].block_programming = false;
			OFS_Card_Used[slot].block_programming = false;
			PVI_Card_Used[slot].block_programming = false;
		}
		
		pin_ptr = group_selection(pin);
		
		do
		{
			
			pin = pin_ptr->grouppin;
			
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin,i);
					switch(Source_type)
					{
					case NONE:
						break;
						
					case DVI:
						if(!dvi_any_cards_used)
							dvi_any_cards_used=true;
						DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;						
						break;
						
					case OV2:
						if(!ov2_any_cards_used)
							ov2_any_cards_used=true;
						OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[0]=true;						
						break;
						
					case HVS:
						if(!hvs_any_cards_used)
							hvs_any_cards_used=true;
						HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;						
						break;
						
					case OFS:
						if(!ofs_any_cards_used)
							ofs_any_cards_used=true;
						OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;						
						break;
						
					case PVI:
						if(!pvi_any_cards_used)
							pvi_any_cards_used=true;
						PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=true;						
						break;						
					}
				}
			}  
			
			pin_ptr = pin_ptr->nextptr;
			
		}  while (pin_ptr != NULL);	

		for (i=0;i<1.0e6;i++)
		{
			if ( (dvi_any_cards_used|ov2_any_cards_used|hvs_any_cards_used|ofs_any_cards_used|pvi_any_cards_used)==false )
			{
				break;
			}
			else
			{
				dvi_any_cards_used = false;
				for(slot=0; slot<21;slot++)
				{
					dvi_any_cards_used = dvi_any_cards_used|DVI_Card_Used[slot].block_programming;
				} 
				
				ov2_any_cards_used = false;
				for(slot=0; slot<21;slot++)
				{
					ov2_any_cards_used = ov2_any_cards_used|OV2_Card_Used[slot].block_programming[0];
				} 
				
				hvs_any_cards_used = false;
				for(slot=0; slot<21;slot++)
				{
					hvs_any_cards_used = hvs_any_cards_used|HVS_Card_Used[slot].block_programming;
				} 
				
				ofs_any_cards_used = false;
				for(slot=0; slot<21;slot++)
				{
					ofs_any_cards_used = ofs_any_cards_used|OFS_Card_Used[slot].block_programming;
				} 
				
				pvi_any_cards_used = false;
				for(slot=0; slot<21;slot++)
				{
					pvi_any_cards_used = pvi_any_cards_used|PVI_Card_Used[slot].block_programming;
				} 
			}
			
			if(dvi_any_cards_used)
				for(slot=0; slot<21;slot++)	if(DVI_Card_Used[slot].block_programming==true)
				{
					if ( (DVI_Card_Used[slot].card_ptr->dvi_get_meas_status()&DVI_MEAS_ADC_BUSY)!=DVI_MEAS_ADC_BUSY )
					{
						DVI_Card_Used[slot].block_programming=false;
					}
				}
				
			if(ov2_any_cards_used)
				for(slot=0; slot<21;slot++)	if(OV2_Card_Used[slot].block_programming[0]==true)
				{
					if ( ((OV2_Card_Used[slot].card_ptr->ov2_get_meas_status()&OV2_MEAS_ADC0_BUSY)!=OV2_MEAS_ADC0_BUSY)&&
						((OV2_Card_Used[slot].card_ptr->ov2_get_meas_status()&OV2_MEAS_ADC1_BUSY)!=OV2_MEAS_ADC1_BUSY))
					{
							OV2_Card_Used[slot].block_programming[0]=false;
					}
				} 
					
			if(hvs_any_cards_used)
				for(slot=0; slot<21;slot++)	if(HVS_Card_Used[slot].block_programming==true)
				{
					if ( (HVS_Card_Used[slot].card_ptr->hvs_get_meas_status()&HVS_MEAS_ADC_BUSY)!=HVS_MEAS_ADC_BUSY )
					{
						HVS_Card_Used[slot].block_programming=false;
					}
				} 
						
			if(ofs_any_cards_used)
				for(slot=0; slot<21;slot++)	if(OFS_Card_Used[slot].block_programming==true)
				{
					if ( (OFS_Card_Used[slot].card_ptr->ofs_get_meas_status()&OFS_MEAS_ADC_BUSY)!=OFS_MEAS_ADC_BUSY )
					{
						OFS_Card_Used[slot].block_programming=false;
					}
				} 
							
#if BoardRev_SXHB >= 261
			if(pvi_any_cards_used)
				for(slot=0; slot<21;slot++)	if(PVI_Card_Used[slot].block_programming==true)
				{
					if ( (PVI_Card_Used[slot].card_ptr->pv3_get_meas_status()&PV3_MEAS_ADC_BUSY)!=PV3_MEAS_ADC_BUSY )
					{
						PVI_Card_Used[slot].block_programming=false;
					}
				} 
#endif
		}
	}
}

void  awg_get_measure_result(short pin, double *result, unsigned char meas_type, unsigned int start_addr, unsigned int stop_addr)
{
	int i,j,slot;

	short Source_type;
	
	DYN_GROUP_LIST *pin_ptr;
	
	BYTE current_measure_index;

	for(slot=0; slot<21;slot++)
	{
		DVI_Card_Used[slot].block_programming = true;
		OV2_Card_Used[slot].block_programming[0] = true;
		OV2_Card_Used[slot].block_programming[1] = true;
		HVS_Card_Used[slot].block_programming = true;
		OFS_Card_Used[slot].block_programming = true;
		PVI_Card_Used[slot].block_programming = true;
		OVI_Card_Used[slot].block_programming = true;
	}

	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				if (DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				
				if (result==NULL)
				{
					DVI_Used[i].DVI_slot->dvi_get_measure_result((DVI_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=DVI_Used[i].DVI_slot->dvi_get_measure_result((DVI_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				break;

			case OV2:
				OV2_MEAS_ID_e OV2_meas_index;
				for(j=0;j<OV2_MEAS_NUMBER;j++)
				{
					if( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[j] )
					{
						if(j==0)
						{
							OV2_meas_index=OV2_MEAS_0; 
							break;
						}
						else
						{
							OV2_meas_index=OV2_MEAS_1;
							break;
						}
					}
				}

				if (OV2_meas_index==OV2_MEAS_0)
				{
					current_measure_index=0;
				}
				else
				{
					current_measure_index=1;
				}

				if (OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[current_measure_index]==TRUE)
				{
					OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[current_measure_index]=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				
				if (result==NULL)
				{
					OV2_Used[i].OV2_slot->ov2_get_measure_result(OV2_meas_index,(OV2_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=OV2_Used[i].OV2_slot->ov2_get_measure_result(OV2_meas_index,(OV2_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				break;

			case HVS:
				if (HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}

				if (result==NULL)
				{
					HVS_Used[i].HVS_slot->hvs_get_measure_result((HVS_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=HVS_Used[i].HVS_slot->hvs_get_measure_result((HVS_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				break;

			case OFS:
				if (OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}

				if (result==NULL)
				{
					OFS_Used[i].OFS_slot->ofs_get_measure_result((OFS_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=OFS_Used[i].OFS_slot->ofs_get_measure_result((OFS_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				break;
				
#if BoardRev_SXHB >= 261
			case PVI:
				if (PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}

				if (result==NULL)
				{
					PVI_Used[i].PVI_slot->pv3_get_measure_result((PV3_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=PVI_Used[i].PVI_slot->pv3_get_measure_result((PV3_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}				
				break;
#endif
				
			case OVI:
				if (OVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					OVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}

				if (result==NULL)
				{
					OVI_Used[i].OVI_slot->ovi_get_measure_result((OVI_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				else
				{
					result[i]=OVI_Used[i].OVI_slot->ovi_get_measure_result((OVI_MEAS_TYPE)meas_type,start_addr,stop_addr);
				}
				break;
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;
	
	}  while (pin_ptr != NULL);	
}

void awg_set_meas_trigger(short pin,double trigger_value,unsigned char slope)
{
	int i;
	sdouble s_trigger_value;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_trigger_value[i]=trigger_value;

	awg_set_meas_trigger(pin,s_trigger_value,slope);
}

void awg_set_meas_trigger(short pin,double *s_trigger_value,unsigned char slope)
{
	int i, j, slot;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	BYTE current_measure_index;

	for(slot=0; slot<21;slot++)
	{
		DVI_Card_Used[slot].block_programming = true;
		OV2_Card_Used[slot].block_programming[0] = true;
		OV2_Card_Used[slot].block_programming[1] = true;
		HVS_Card_Used[slot].block_programming = true;
		OFS_Card_Used[slot].block_programming = true;
		PVI_Card_Used[slot].block_programming = true;
	}

	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;
			case DVI:
				if (DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					DVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				DVI_Used[i].DVI_slot->dvi_set_meas_trigger(s_trigger_value[i],(DVI_TRG_SLOPE_e)slope);
				break;
			case OV2:
				OV2_MEAS_ID_e OV2_meas_index;
				for(j=0;j<OV2_MEAS_NUMBER;j++)
				{
					if( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[j] )
					{
						if(j==0)
						{
							OV2_meas_index=OV2_MEAS_0; 
							break;
						}
						else
						{
							OV2_meas_index=OV2_MEAS_1;
							break;
						}
					}
				}
				if (OV2_meas_index==OV2_MEAS_0)
				{
					current_measure_index=0;
				}
				else
				{
					current_measure_index=1;
				}
				if (OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[current_measure_index]==TRUE)
				{
					OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming[current_measure_index]=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				OV2_Used[i].OV2_slot->ov2_set_meas_trigger(OV2_meas_index,s_trigger_value[i],(OV2_TRG_SLOPE_e)slope);
				break;
			case HVS:
				if (HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					HVS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				HVS_Used[i].HVS_slot->hvs_set_meas_trigger(s_trigger_value[i],(HVS_TRG_SLOPE_e)slope);
				break;
			case OFS:
				if (OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					OFS_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				OFS_Used[i].OFS_slot->ofs_set_meas_trigger(s_trigger_value[i],(OFS_TRG_SLOPE_e)slope);
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				if (PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming==TRUE)
				{
					PVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else
				{
					MessageBox (NULL,NULL,"you should use different card ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
				}
				PVI_Used[i].PVI_slot->pv3_set_meas_trigger(s_trigger_value[i],(PV3_TRG_SLOPE_e)slope);
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);
}

void  awg_get_awg_status(short pin, unsigned short *res_ptr)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	unsigned short awg_status;
	
	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		*(res_ptr + i)=0;

		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;

			case DVI:
				awg_status=DVI_Used[i].DVI_slot->dvi_get_awg_status();
				if ( (awg_status>>DVI_Used[i].DVI_channel)&DVI_AWG_VOLTAGE0_BUSY==DVI_AWG_VOLTAGE0_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_VOLTAGE_BUSY; 
				}
				else if ( (awg_status>>DVI_Used[i].DVI_channel)&DVI_AWG_CURRENT0_BUSY==DVI_AWG_CURRENT0_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_CURRENT_BUSY; 
				}
				break;

			case OV2:
				*(res_ptr + i)=OV2_Used[i].OV2_slot->ov2_get_awg_status();
				if ( (awg_status>>OV2_Used[i].OV2_channel)&OV2_AWG_VOLTAGE0_BUSY==OV2_AWG_VOLTAGE0_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_VOLTAGE_BUSY; 
				}
				else if ( (awg_status>>OV2_Used[i].OV2_channel)&OV2_AWG_CURRENT0_BUSY==OV2_AWG_CURRENT0_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_CURRENT_BUSY; 
				}
				break;

			case HVS:
				*(res_ptr + i)=HVS_Used[i].HVS_slot->hvs_get_awg_status();
				if ( (awg_status)&HVS_AWG_VOLTAGE_BUSY==HVS_AWG_VOLTAGE_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_VOLTAGE_BUSY; 
				}
				else if ( (awg_status)&HVS_AWG_CURRENT_BUSY==HVS_AWG_CURRENT_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_CURRENT_BUSY; 
				}
				break;

			case OFS:
				*(res_ptr + i)=OFS_Used[i].OFS_slot->ofs_get_awg_status();
				if ( (awg_status)&OFS_AWG_VOLTAGE_BUSY==OFS_AWG_VOLTAGE_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_VOLTAGE_BUSY; 
				}
				else if ( (awg_status)&OFS_AWG_CURRENT_BUSY==OFS_AWG_CURRENT_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_CURRENT_BUSY; 
				}
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				*(res_ptr + i)=PVI_Used[i].PVI_slot->pv3_get_awg_status();
				if ( (awg_status)&PV3_AWG_VOLTAGE_BUSY==PV3_AWG_VOLTAGE_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_VOLTAGE_BUSY; 
				}
				else if ( (awg_status)&PV3_AWG_CURRENT_BUSY==PV3_AWG_CURRENT_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|AWG_CURRENT_BUSY; 
				}
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void  awg_get_meas_status(short pin, unsigned short *res_ptr)
{
	int	i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	unsigned short meas_status;

	pin_ptr = group_selection(pin);

	do
	{
		
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{

		if(active_site[i])
		{
			*(res_ptr + i)=0;//初始化
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;
				
			case DVI:
				meas_status=DVI_Used[i].DVI_slot->dvi_get_meas_status();
				if ( (meas_status&DVI_MEAS_ADC_BUSY)==DVI_MEAS_ADC_BUSY )
				{
					if ( DVI_Used[i].DVI_channel==DVI_Used[i].DVI_slot->card.meas_channel )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
					}
				}
				if ( (meas_status&DVI_MEAS_TRG_BUSY)==DVI_MEAS_TRG_BUSY )
				{
					if ( DVI_Used[i].DVI_channel==DVI_Used[i].DVI_slot->card.meas_channel )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
					}
				}
				break;

			case OV2:
				meas_status=OV2_Used[i].OV2_slot->ov2_get_meas_status();
				if ( (meas_status&OV2_MEAS_ADC0_BUSY)==OV2_MEAS_ADC0_BUSY )
				{
					if ( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[0] )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
					}
				}
				if ( (meas_status&OV2_MEAS_ADC1_BUSY)==OV2_MEAS_ADC1_BUSY )
				{
					if ( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[1] )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
					}
				}
				if ( (meas_status&OV2_MEAS_TRG0_BUSY)==OV2_MEAS_TRG0_BUSY )
				{
					if ( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[0] )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
					}
				}
				if ( (meas_status&OV2_MEAS_TRG1_BUSY)==OV2_MEAS_TRG1_BUSY )
				{
					if ( OV2_Used[i].OV2_channel==OV2_Used[i].OV2_slot->card.meas_channel[1] )
					{
						*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
					}
				}
				break;

			case HVS:
				meas_status=HVS_Used[i].HVS_slot->hvs_get_meas_status();
				if ( (meas_status&HVS_MEAS_ADC_BUSY)==HVS_MEAS_ADC_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
				}
				if ( (meas_status&HVS_MEAS_TRG_BUSY)==HVS_MEAS_TRG_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
				}
				break;

			case OFS:
				meas_status=OFS_Used[i].OFS_slot->ofs_get_meas_status();
				if ( (meas_status&OFS_MEAS_ADC_BUSY)==OFS_MEAS_ADC_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
				}
				if ( (meas_status&OFS_MEAS_TRG_BUSY)==OFS_MEAS_TRG_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
				}
				break;

#if BoardRev_SXHB >= 261
			case PVI:
				meas_status=PVI_Used[i].PVI_slot->pv3_get_meas_status();
				if ( (meas_status&PV3_MEAS_ADC_BUSY)==PV3_MEAS_ADC_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_ADC_BUSY; 
				}
				if ( (meas_status&PV3_MEAS_TRG_BUSY)==PV3_MEAS_TRG_BUSY )
				{
					*(res_ptr + i)=*(res_ptr + i)|MEAS_TRG_BUSY; 
				}
				break;
#endif
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);
}


void dc_measure_setup(short pin, short mode ,short d_range)
{
	sfloat dummy={0.0};
	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do 
	{

	pin = pin_ptr->grouppin;

	dc_measure(pin, mode, dummy, 0, d_range);

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);
	
}

void dc_measure_filter_setup(short pin_list, short mode ,short d_range , bool is_filter)
{
	int site;
	short pin;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;
	char	ErrorMessage[100];
	
	XVI_ERROR_CODE_e XviRetError=XVI_EC_NO_ERROR_INFO;
	
	
	pin_ptr = group_selection(pin_list); 
	
	do
	{
		pin = pin_ptr->grouppin;
		
		for( site = 0; site < max_sites ; site++ )
		{
			if(active_site[site])
			{
				Source_type=pin_selection(pin,site);
				switch(Source_type)
				{
				case NONE:
					break;
					
				case XVI:
					
					if(!debug_xvi_msl_offline)	
					{
						if((is_filter==true)&&(XVI_Used[site].XVI_slot->card.xvi_image_low_pass_filter[XVI_Used[site].XVI_ch_index])==false)
							XviRetError=XVI_Used[site].XVI_slot->enable_measure_filter(XVI_Used[site].XVI_channel);
						else if((is_filter==false)&&(XVI_Used[site].XVI_slot->card.xvi_image_low_pass_filter[XVI_Used[site].XVI_ch_index])==true)
							XviRetError=XVI_Used[site].XVI_slot->disable_measure_filter(XVI_Used[site].XVI_channel);
					}
					
					if(XviRetError!=XVI_EC_NO_ERROR_INFO)
					{
						sprintf(ErrorMessage,"xvi_measure_filter failed while setting filter on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
						MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
						printf(ErrorMessage);
					}
					break;

				case DVI:
					DVI_Used[site].is_filter = is_filter;
					break;

				case OV2:
					OV2_Used[site].is_filter = is_filter;
					break;

				default:
					sprintf(ErrorMessage,"dc_measure_filter_setup executable for XVI,OV2,DVI2000 pins");
					MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
			}	
		}  
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
	
	dc_measure_setup(pin_list,mode,d_range);

}

void dc_measure(short pin, short mode ,SFLOAT *res_ptr_SFLOAT ,short ave_num, short d_range, short wait_us)
{
	sfloat res_ptr_float;
	dc_measure(pin, mode ,res_ptr_float ,ave_num, d_range, wait_us);

	(*res_ptr_SFLOAT).set_to(res_ptr_float);
}

void dc_measure(short pin_list, short mode ,double *res_list_ptr ,short ave_num, short d_range, short wait_us)
{
	int i;
	sfloat res_ptr_float;

	dc_measure(pin_list, mode ,res_ptr_float ,ave_num, d_range, wait_us);

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			res_list_ptr[i]=res_ptr_float[i];
}

void dc_measure(short pin_list, short mode ,sfloat *res_list_ptr ,short ave_num, short d_range, short wait_us)
{
	
	
	
	short pin;
	sfloat single_pin_result;

	int list_depth=0;
	int i, n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 


	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		dc_measure(pin, mode, single_pin_result, ave_num, d_range, wait_us);

	
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			res_list_ptr[list_depth-1-n][i]=single_pin_result[i];

		pin_ptr = pin_ptr->nextptr;
	}

}

void dc_measure(short pin, short mode ,float *res_ptr ,short ave_num, short d_range, short usr_wait_us)
{

	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;

	short	wait_us;

	short	dvi_default_wait_us=350,	
			ovi_default_wait_us=200,	
			xvi_default_wait_us=200,	
			hvs_default_wait_us=200,	
			ofs_default_wait_us=200,	
			mvs_default_wait_us=200,	
			pvi_default_wait_us=200,	
			lzb_default_wait_us=200,	
			oal_default_wait_us=200,
			qal_default_wait_us=200,
			ov2_default_wait_us=350;

	STRING  measure_mode, prg_name;



	char	ovi_vrange=NULL;	




	pin_ptr = group_selection(pin); 
	
	DYN_GROUP_LIST *anker_ptr = pin_ptr;


	bool SetMeasDue=true;

#ifndef	LegacyXerxes
	sdouble single_xvi_pin_result;
	bool XviPin=false;
	bool XviSetMeasDue=false;
	BOOL save_active_site[CSC_MAX_SITES];

#endif

	BYTE current_measure_index;
	BYTE original_measure_index;	

	do
	{


	pin = pin_ptr->grouppin;

#ifndef	LegacyXerxes


	for( i = 0; i < max_sites ; i++ )
		save_active_site[i]=active_site[i];
	

	XviSetMeasDue=false;
	XviPin=false;


	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{


			case XVI:
			{
				double	xvi_meas_range;

				if(mode == MEASURE_VOLTAGE)
				{
					switch(d_range)
					{
						case RANGE_1_V:		xvi_meas_range=(double)(1 V); break;
						case RANGE_3_V:		xvi_meas_range=(double)(3 V); break;
						case RANGE_5_V:		xvi_meas_range=(double)(5 V); break;
						case RANGE_10_V:	xvi_meas_range=(double)(10 V); break;
						case RANGE_30_V:	xvi_meas_range=(double)(30 V); break;
						case NO_DIFF_RANGE:
						default:			
if(!debug_xvi_msl_offline)	
							xvi_meas_range=XVI_Used[i].XVI_slot->card.xvi_image_voltage_range[XVI_Used[i].XVI_ch_index];
						
						
					}
				
if(!debug_xvi_msl_offline)
{
					if(!((XVI_Used[i].XVI_slot->card.xvi_imageISE_meas_mode[XVI_Used[i].XVI_ch_index]==XVI_MEAS_VOLTAGE)&&
					   (XVI_Used[i].XVI_slot->card.xvi_imageISE_meas_range[XVI_Used[i].XVI_ch_index]==xvi_meas_range)))
					{
						XviSetMeasDue=true;
						XVI_Used[i].XVI_slot->set_measure_mode_voltage(XVI_Used[i].XVI_channel,xvi_meas_range);
					}
}
				}

				if(mode == MEASURE_DIFF_VOLTAGE)
				{
					switch(d_range)
					{
					
					case RANGE_10_MV:											
					case RANGE_20_MV:	xvi_meas_range=(double)(20 mV); break;	
					case RANGE_30_MV:										
					case RANGE_50_MV:											
					case RANGE_100_MV:										
					case RANGE_200_MV:	xvi_meas_range=(double)(200 mV); break;	
					case RANGE_300_MV:										
					case RANGE_1_V:												
					case RANGE_2_V:		xvi_meas_range=(double)(2 V); break;
					case RANGE_3_V:											
					case RANGE_5_V:											
					case RANGE_10_V:	xvi_meas_range=(double)(10 V); break;	
					case NO_DIFF_RANGE:
						default:			
							MessageBox(NULL,"Invalid range for differential voltage measurement\nSetting range to 10V","XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							xvi_meas_range=(double)(10 V); break;
					}
if(!debug_xvi_msl_offline)	
{
					if(!((XVI_Used[i].XVI_slot->card.xvi_imageISE_meas_mode[XVI_Used[i].XVI_ch_index]==XVI_MEAS_DIFF_VOLTAGE)&&
					   (XVI_Used[i].XVI_slot->card.xvi_imageISE_meas_range[XVI_Used[i].XVI_ch_index]==xvi_meas_range)))
					{
						XviSetMeasDue=true;
						XVI_Used[i].XVI_slot->set_measure_mode_diff_voltage(XVI_Used[i].XVI_channel,xvi_meas_range);
					}
}
				}
				if(mode == MEASURE_CURRENT)
				{
if(!debug_xvi_msl_offline)	
{
					if(!(XVI_Used[i].XVI_slot->card.xvi_imageISE_meas_mode[XVI_Used[i].XVI_ch_index]==XVI_MEAS_CURRENT))
					{
						XviSetMeasDue=true;
						XVI_Used[i].XVI_slot->set_measure_mode_current(XVI_Used[i].XVI_channel);
					}
}
				}
				XviPin=true;
			}
			break;
			default:	
				active_site[i]=0;
			}
		}
	}

	if(ave_num>1)
	{
		

		xvi_sampling_setup(pin, ave_num,(double)(20 uS));	


		if(usr_wait_us==-1.0f)
			wait_us=xvi_default_wait_us;
		else
			wait_us=usr_wait_us;
				
		
		if(XviSetMeasDue)
			wait.delay_10_us(int(wait_us/10));

	
	
		xvi_arm(pin, XVI_TRIG_IMMEDIATE, 0, false);
	}	
	else
		
		xvi_sampling_setup(pin, 1, (double)(5.0 uS));



	for( i = 0; i < max_sites ; i++ )
		active_site[i]=save_active_site[i];
#endif


	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case OV2:
				if(usr_wait_us==-1.0f)
					wait_us=ov2_default_wait_us;
				else
					wait_us=usr_wait_us;

				current_measure_index = 0xff;
				original_measure_index = OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index;
				if(mode == MEASURE_VOLTAGE)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[original_measure_index])==OV2_MEASURE_VOLTAGE)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[original_measure_index])==OV2_Used[i].OV2_channel))
					{
						current_measure_index=original_measure_index;
					}					
				}
				else if(mode == MEASURE_CURRENT)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[original_measure_index])==OV2_MEASURE_CURRENT)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[original_measure_index])==OV2_Used[i].OV2_channel))
					{
						current_measure_index=original_measure_index;
					}
				}

				if ( current_measure_index==0xff )
				{
					if ( (OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index!=0)||
						(mode == MEASURE_DIFF_VOLTAGE) )
					{
						current_measure_index=0;
					}	
					else
					{
						current_measure_index=1;
					}	
				}
				if(mode == MEASURE_VOLTAGE)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[current_measure_index])==OV2_MEASURE_VOLTAGE)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[current_measure_index])==OV2_Used[i].OV2_channel))
					SetMeasDue=false;

					if (current_measure_index==0)
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_VOLTAGE);
					}
					else
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure2_filter();
						else OV2_Used[i].OV2_slot->enable_measure2_filter();
						OV2_Used[i].OV2_slot->set_meas2_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_VOLTAGE);
					}
				}
				if(mode == MEASURE_CURRENT)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[current_measure_index])==OV2_MEASURE_CURRENT)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[current_measure_index])==OV2_Used[i].OV2_channel))
					SetMeasDue=false;

					if (current_measure_index==0)
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_CURRENT);
					}
					else
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure2_filter();
						else OV2_Used[i].OV2_slot->enable_measure2_filter();
						OV2_Used[i].OV2_slot->set_meas2_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_CURRENT);
					}
				}
				if(mode == MEASURE_DIFF_VOLTAGE)
				{
					if (OV2_Used[i].OV2_channel==OV2_CHANNEL_7)
					{
						if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[OV2_MEASURE_0])==OV2_MEASURE_DIFF)&&
							((int)(OV2_Used[i].OV2_slot->card.meas_channel[OV2_MEASURE_0])==OV2_Used[i].OV2_channel)&&
							((int)(OV2_Used[i].OV2_slot->card.meas_channel[OV2_MEASURE_1])==OV2_CHANNEL_0&&
							(int)(OV2_Used[i].OV2_slot->debug_diff_range)==d_range))
							SetMeasDue=false;
						
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel,OV2_CHANNEL_0,OV2_MEASURE_DIFF,d_range);
					}
					else
					{
						
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel,OV2_Used[i].OV2_channel+1,OV2_MEASURE_DIFF,d_range);
					}

				}
			
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));
				
				if (current_measure_index==0)
				{
					if(ave_num > 1)
						*(res_ptr + i) = OV2_Used[i].OV2_slot->measure_average(ave_num);
				
					else if(ave_num > 0)
						*(res_ptr + i) = OV2_Used[i].OV2_slot->measure();
				}
				else
				{
					if(ave_num > 1)
						*(res_ptr + i) = OV2_Used[i].OV2_slot->measure2_average(ave_num);
					
					else if(ave_num > 0)
						*(res_ptr + i) = OV2_Used[i].OV2_slot->measure2();					
				}

				SetMeasDue=true;
				OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index=current_measure_index;
				break;

			case DVI:

	
				if(usr_wait_us==-1.0f)
					wait_us=dvi_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(DVI_Used[i].DVI_slot->dvi_rev!=DVI_REVF&&DVI_Used[i].DVI_slot->dvi_rev!=DVI_REVG)
				{
					if (DVI_Used[i].is_filter == false) DVI_Used[i].DVI_slot->disable_measure_filter();
					else DVI_Used[i].DVI_slot->enable_measure_filter();
				}
				if(mode == MEASURE_VOLTAGE)
				{
				#ifndef	LegacyVATE522
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==0)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
						SetMeasDue=false;
					else
				#endif
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_VOLTAGE);
				}

				if(mode == MEASURE_DIFF_VOLTAGE)
				{
				#ifndef	LegacyVATE522
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==3)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_diff_range)==d_range))
						SetMeasDue=false;
					else
				#endif
					{
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_DIFF);
			
						if (d_range != NO_DIFF_RANGE)
							DVI_Used[i].DVI_slot->set_diff_range(d_range);
					}
				}
				if(mode == MEASURE_CURRENT)
				{
				#ifndef	LegacyVATE522
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==1)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
						SetMeasDue=false;
					else
				#endif
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_CURRENT);
				}

				if(mode == MEASURE_EXT_REF)
				{
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==DVI_MEASURE_EXT_REF)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
						SetMeasDue=false;
					else
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_EXT_REF);
				}
		
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));
				
				if(ave_num > 1)
					*(res_ptr + i) = DVI_Used[i].DVI_slot->measure_average(ave_num);
		
				else if(ave_num > 0)
					*(res_ptr + i) = DVI_Used[i].DVI_slot->measure();

				SetMeasDue=true;
				break;

			case OVI:
			case OVI_S:	

		
				if(usr_wait_us==-1.0f)
					wait_us=ovi_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
				{
				#ifndef	LegacyVATE522
					OVI_Used[i].OVI_slot->get_voltage_range(OVI_Used[i].OVI_channel, ovi_vrange);	
					
					if(((int)(OVI_Used[i].OVI_slot->m_active_meas_mode)==0)&&
			
				
					    ((int)(OVI_Used[i].OVI_slot->m_active_channelSC)==OVI_Used[i].OVI_channel)&&
						((mode == MEASURE_CURRENT)||((mode == MEASURE_VOLTAGE)&&(int(ovi_vrange)==OVI_Used[i].OVI_slot->m_active_rangeSC)&&((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE)||(d_range==OVI_Used[i].OVI_slot->m_active_rangeSC)))))
						SetMeasDue=false;
					else
				#endif
					
					{
						
						if ((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE))
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE);
						else
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE, d_range);
					}
				}

				if(mode == MEASURE_CURRENT)
				{
				#ifndef	LegacyVATE522
					if(((int)(OVI_Used[i].OVI_slot->m_active_meas_mode)==1)&&
					    
					    ((int)(OVI_Used[i].OVI_slot->m_active_channelSC)==OVI_Used[i].OVI_channel))
						SetMeasDue=false;
					else
				#endif
						OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_CURRENT);
				}

		
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num > 1)
					
				{
				
					if ((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE))
						*(res_ptr + i) = OVI_Used[i].OVI_slot->measure_average(ave_num);
					else
						*(res_ptr + i) = OVI_Used[i].OVI_slot->measure_average(ave_num, d_range);
				}
			
				else if(ave_num > 0)
					
				{
					
					if ((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE))
						*(res_ptr + i) = OVI_Used[i].OVI_slot->measure();
					else
						*(res_ptr + i) = OVI_Used[i].OVI_slot->measure(d_range);
				}
				SetMeasDue=true;
				break;

#ifndef	LegacyXerxes
			case XVI: break;
#endif
						
			case HVS:

			
				if(usr_wait_us==-1.0f)
					wait_us=hvs_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
				#ifndef	LegacyVATE522
					if(HVS_Used[i].HVS_slot->m_active_meas_mode==1024)
						SetMeasDue=false;
					else
				#endif
						HVS_Used[i].HVS_slot->set_meas_mode(HVS_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)
				#ifndef	LegacyVATE522
					if(HVS_Used[i].HVS_slot->m_active_meas_mode==8192)
						SetMeasDue=false;
					else
				#endif
						HVS_Used[i].HVS_slot->set_meas_mode(HVS_MEASURE_CURRENT);

				
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num > 1)
					*(res_ptr + i) = HVS_Used[i].HVS_slot->measure_average(ave_num);
	
				else if(ave_num > 0)
					*(res_ptr + i) = HVS_Used[i].HVS_slot->measure();

				SetMeasDue=true;	
				break;

			case OFS:

	
				if(usr_wait_us==-1.0f)
					wait_us=ofs_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)


	



					OFS_Used[i].OFS_slot->set_meas_mode(OFS_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)



	


					OFS_Used[i].OFS_slot->set_meas_mode(OFS_MEASURE_CURRENT);

				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num > 1)
					*(res_ptr + i) = OFS_Used[i].OFS_slot->measure_average(ave_num);
			
				else if(ave_num > 0)
					*(res_ptr + i) = OFS_Used[i].OFS_slot->measure();

				break;

			case MVS:

		
				if(usr_wait_us==-1.0f)
					wait_us=mvs_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)

				
	
	

					MVS_Used[i].MVS_slot->set_meas_mode(MVS_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)

		
			
		
		

					MVS_Used[i].MVS_slot->set_meas_mode(MVS_MEASURE_CURRENT);

				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num > 1)
					*(res_ptr + i) = MVS_Used[i].MVS_slot->measure_average(ave_num);
		
				else if(ave_num > 0)
					*(res_ptr + i) = MVS_Used[i].MVS_slot->measure();

				break;

			case PVI:

		
				if(usr_wait_us==-1.0f)
					wait_us=pvi_default_wait_us;
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
				#ifndef	LegacyVATE522
					if(PVI_Used[i].PVI_slot->measure_mode==0)
						SetMeasDue=false;
					else
				#endif
						PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)
				#ifndef	LegacyVATE522
					if(PVI_Used[i].PVI_slot->measure_mode==1)
						SetMeasDue=false;
					else
				#endif
						PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_CURRENT);

			
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num > 1)
					*(res_ptr + i) = PVI_Used[i].PVI_slot->measure_average(ave_num);
			
				else if(ave_num > 0)
					*(res_ptr + i) = PVI_Used[i].PVI_slot->measure();

				SetMeasDue=true;	
				break;

			case LZB:

			
				if(usr_wait_us==-1.0f)
					wait_us=lzb_default_wait_us;
				else
					wait_us=usr_wait_us;

				switch(mode)
				{
					case MEASURE_CURRENT:
					case LZB_OUTPUT_CURRENT:
					#ifndef	LegacyVATE522
						if(LZB_Used[i].LZB_slot->current_meas_mode==LZB_OUTPUT_CURRENT)
							SetMeasDue=false;
						else
					#endif
							LZB_Used[i].LZB_slot->set_meas_mode(LZB_OUTPUT_CURRENT);
						break;

					case MEASURE_VOLTAGE:
					case LZB_OUTPUT_VOLTAGE:
					#ifndef	LegacyVATE522
						if(LZB_Used[i].LZB_slot->current_meas_mode==LZB_OUTPUT_VOLTAGE)
							SetMeasDue=false;
						else
					#endif
							LZB_Used[i].LZB_slot->set_meas_mode(LZB_OUTPUT_VOLTAGE);
						break;

					case LZB_CAP_VOLTAGE:
					#ifndef	LegacyVATE522
						if(LZB_Used[i].LZB_slot->current_meas_mode==LZB_CAP_VOLTAGE)
							SetMeasDue=false;
						else
					#endif
							LZB_Used[i].LZB_slot->set_meas_mode(LZB_CAP_VOLTAGE);
						break;

					default:
						mytext.text_in_box(40,10,"dc_measure(LZB): invalid meas mode");
						exit(0);
				}

				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				if(ave_num>0)
					*(res_ptr + i) = LZB_Used[i].LZB_slot->measure();

				SetMeasDue=true;	
				break;

			case OAL:
			{
				unsigned short status_relay_bank_1=OAL_Used[i].OAL_slot->card.relay_bank_1;
				unsigned short status_relay_bank_2=OAL_Used[i].OAL_slot->card.relay_bank_2;
				unsigned short status_switch_bank_1=OAL_Used[i].OAL_slot->card.switch_bank_1;
				unsigned short status_switch_bank_2=OAL_Used[i].OAL_slot->card.switch_bank_2;
				unsigned short status_switch_bank_3=OAL_Used[i].OAL_slot->card.switch_bank_3;
				unsigned short status_adc_mux=OAL_Used[i].OAL_slot->card.adc_mux;
	
				bool status_EXT_RLY_DRV=0x1&(status_relay_bank_2>>(EXT_RLY_DRV%16));
				bool status_CH1_EXT_DRV=0x1&(status_relay_bank_2>>(CH1_EXT_DRV%16));
				bool status_DRV_1=0x1&(status_switch_bank_2>>(DRV_1%16));
				bool status_DRV_2=0x1&(status_switch_bank_2>>(DRV_2%16));

				bool status_DUT_NEG_ISOL=0x1&(status_relay_bank_1>>(DUT_NEG_ISOL%16));	
				bool status_DUT_POS_ISOL=0x1&(status_relay_bank_1>>(DUT_POS_ISOL%16));

				bool status_IA_1MV=0x1&(status_switch_bank_1>>(IA_1MV%16));
				bool status_IA_10MV=0x1&(status_switch_bank_1>>(IA_10MV%16));
				bool status_IA_100MV=0x1&(status_switch_bank_1>>(IA_100MV%16));

				bool status_MLG_CON_POS=0x1&(status_switch_bank_1>>(MLG_CON_POS%16));
				bool status_LLG_CON_POS=0x1&(status_switch_bank_1>>(LLG_CON_POS%16));
				bool status_POS_LKG_X10=0x1&(status_switch_bank_1>>(POS_LKG_X10%16));

				bool status_MLG_CON_NEG=0x1&(status_switch_bank_1>>(MLG_CON_NEG%16));
				bool status_LLG_CON_NEG=0x1&(status_switch_bank_1>>(LLG_CON_NEG%16));
				bool status_NEG_LKG_X10=0x1&(status_switch_bank_1>>(NEG_LKG_X10%16));

				bool status_CH0_MEAS=0x1&(status_switch_bank_2>>(CH0_MEAS%16));
				bool status_CH1_MEAS=0x1&(status_switch_bank_2>>(CH1_MEAS%16));

				bool status_CLOSE_LOOP=0x1&(status_switch_bank_1>>(CLOSE_LOOP%16));
				bool status_CLS_LOOP_IV=0x1&(status_switch_bank_1>>(CLS_LOOP_IV%16));

				float ADC_scale=1.0;
				int	sample;
				float Req;

				
				if(usr_wait_us==-1.0f)
					wait_us=oal_default_wait_us;
				else
					wait_us=usr_wait_us;

				switch(mode)
				{
					case MEASURE_CURRENT:
						switch(Pin_Type_Used[pin][i].PinClass)
						{
						case PIN_IN_POS:
							switch(d_range)
							{
							case RANGE_100_PA:
								if(
									(status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(!status_DUT_POS_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
									(status_CH1_EXT_DRV)&&
									(
									  ((status_adc_mux==EXT_PICO_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
									SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10);
									OAL_Used[i].OAL_slot->open_relay(DUT_POS_ISOL);	
									OAL_Used[i].OAL_slot->open_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->open_switch(DRV_1);
									OAL_Used[i].OAL_slot->close_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(EXT_PICO_POS);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_EXT_PICO_POS);
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f+100e3f/1.1e3f);
								ADC_scale=((float)(10 V)/Req)/32768;
								break;
							case RANGE_1_NA:
								if(
									(status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(!status_DUT_POS_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
									(!status_CH1_EXT_DRV)&&
									(
									  ((status_adc_mux==EXT_PICO_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
									SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10);
									OAL_Used[i].OAL_slot->open_relay(DUT_POS_ISOL);	
									OAL_Used[i].OAL_slot->open_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->open_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(EXT_PICO_POS);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_EXT_PICO_POS);
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f);
								ADC_scale=((float)(10 V)/Req)/32768;
								break;
							case RANGE_10_NA:
								if(
									(status_MLG_CON_POS)&&
									(!status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==LLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_LLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
									SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_POS);
									OAL_Used[i].OAL_slot->close_switch(LLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10);
									OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(LLG_POS);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_LLG_POS);
								}
								ADC_scale=(float)(10 nA)/32768;
								break;
							case RANGE_1_UA:
								if(
									(!status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(status_POS_LKG_X10)&&
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==MLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_MLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
									SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->close_switch(MLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(POS_LKG_X10);
									OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(MLG_POS);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_POS);
								}
								ADC_scale=(float)(1 uA)/32768;
								break;
							default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - wrong current meter range\nRange set to 10UA for PIN %s",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								}
							case RANGE_10_UA:
								if(
									(!status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(!status_POS_LKG_X10)&&
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==MLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_MLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->close_switch(MLG_CON_POS);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_POS);
									OAL_Used[i].OAL_slot->close_switch(POS_LKG_X10);
									OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(MLG_POS);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_POS);
								}
								ADC_scale=(float)(10 uA)/32768;
							}break;
						case PIN_IN_NEG:
							switch(d_range)
							{
							case RANGE_100_PA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_DUT_NEG_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
									(status_CH1_EXT_DRV)&&
									(
									  ((status_adc_mux==EXT_PICO_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10);
									OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
									OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
									OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL);	
									OAL_Used[i].OAL_slot->open_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->open_switch(DRV_1);
									OAL_Used[i].OAL_slot->close_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(EXT_PICO_NEG);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_EXT_PICO_NEG);
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f+100e3f/1.1e3f);
								ADC_scale=((float)(10 V)/Req)/32768;

								break;
							case RANGE_1_NA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_DUT_NEG_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
									(!status_CH1_EXT_DRV)&&
									(
									  ((status_adc_mux==EXT_PICO_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10);
									OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
									OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
									OAL_Used[i].OAL_slot->open_relay(DUT_NEG_ISOL);	
									OAL_Used[i].OAL_slot->open_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->open_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(EXT_PICO_NEG);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_EXT_PICO_NEG);
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f);
								ADC_scale=((float)(10 V)/Req)/32768;

								break;
							case RANGE_10_NA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(!status_LLG_CON_NEG)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==LLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_LLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->open_switch(MLG_CON_NEG);
									OAL_Used[i].OAL_slot->close_switch(LLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10);
									OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
									OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
									OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(LLG_NEG);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_LLG_NEG);
								}
								ADC_scale=(float)(10 nA)/32768;
								break;
							case RANGE_1_UA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(!status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(status_NEG_LKG_X10)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==MLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_MLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->close_switch(MLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(NEG_LKG_X10);
									OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
									OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
									OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(MLG_NEG);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_NEG);
								}
								ADC_scale=(float)(1 uA)/32768;
								break;
							default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - wrong current meter range\nRange set to 10UA for PIN %s",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								}
							case RANGE_10_UA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(!status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_NEG_LKG_X10)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==MLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_MLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
									)
								  )
								   SetMeasDue=false;	
								else
								{
									OAL_Used[i].OAL_slot->close_switch(MLG_CON_NEG);
									OAL_Used[i].OAL_slot->open_switch(LLG_CON_NEG);
									OAL_Used[i].OAL_slot->close_switch(NEG_LKG_X10);
									OAL_Used[i].OAL_slot->close_switch(CLS_LOOP_IV);
									OAL_Used[i].OAL_slot->open_switch(CLOSE_LOOP);
									OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);	
									OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
									OAL_Used[i].OAL_slot->close_switch(DRV_1);
									OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);	
									if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
										OAL_Used[i].OAL_slot->select_adc_mux(MLG_NEG);
									else
										OAL_Used[i].OAL_slot->select_adc_mux(CH1_MLG_NEG);
								}
								ADC_scale=(float)(10 uA)/32768;
							}break;
						default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								return;
								}
						}
					break;		

				case MEASURE_VOLTAGE:
					if(Pin_Type_Used[pin][i].PinClass!=PIN_OUT)
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Output for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}
					if(((status_adc_mux==HV_BUF%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
					   ((status_adc_mux==CH1_HV_BUF%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1)))
						SetMeasDue=false;	
					else
					{
						if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
							OAL_Used[i].OAL_slot->select_adc_mux(HV_BUF);
						else
							OAL_Used[i].OAL_slot->select_adc_mux(CH1_HV_BUF);
					}
					ADC_scale*=(float)(40 V)/32768;
					break;
				case MEASURE_DIFF_VOLTAGE:
					if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}
					if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
						ADC_scale=-1.0f;
					else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
						ADC_scale=1.0f;		
					else
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}

					switch(d_range)
					{
						case RANGE_100_UV:
							if(
								(status_IA_1MV)&&	
								(status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
								  ((status_adc_mux==CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
									OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
								else
									OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
								OAL_Used[i].OAL_slot->open_switch(IA_1MV);
								OAL_Used[i].OAL_slot->open_switch(IA_10MV);
								OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							}
							ADC_scale*=(float)(100 uV)/32768;
							break;
						case RANGE_1_MV:
							if(
								(!status_IA_1MV)&&	
								(status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
								  ((status_adc_mux==CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
									OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
								else
									OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
								OAL_Used[i].OAL_slot->close_switch(IA_1MV);
								OAL_Used[i].OAL_slot->open_switch(IA_10MV);
								OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							}
							ADC_scale*=(float)(1 mV)/32768;
							break;
						case RANGE_10_MV:
							if(
								(status_IA_1MV)&&	
								(!status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
								  ((status_adc_mux==CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
									OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
								else
									OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
								OAL_Used[i].OAL_slot->open_switch(IA_1MV);
								OAL_Used[i].OAL_slot->close_switch(IA_10MV);
								OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							}
							ADC_scale*=(float)(10 mV)/32768;
							break;
						case RANGE_100_MV:
							if(
								(status_IA_1MV)&&	
								(status_IA_10MV)&&
								(!status_IA_100MV)&&
								(
								  ((status_adc_mux==IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0))||
								  ((status_adc_mux==CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_1))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==OAL_CHANNEL_0)
									OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
								else
									OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
								OAL_Used[i].OAL_slot->open_switch(IA_1MV);
								OAL_Used[i].OAL_slot->open_switch(IA_10MV);
								OAL_Used[i].OAL_slot->close_switch(IA_100MV);
							}
							ADC_scale*=(float)(100 mV)/32768;
							break;
						default:
							{
							char err_message[100];
							sprintf(err_message, "dc_measure() - wrong IA range\nRange set to 100MV for PIN %s",Pin_Type_Used[pin][i].Pin_Name);	
							mytext.text_in_box(40,10,err_message);
							}
						}
					break;	

				default:
					{
					char err_message[100];
					sprintf(err_message, "dc_measure() - Invalid Measure mode for DOAL - pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return;
					}
				} 

				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				float VioComp=*(res_ptr + i);

				*(res_ptr + i) = 0.0f;
				if (ave_num>0)
				{
					for(sample=0;sample<ave_num;sample++)
						*(res_ptr + i) += OAL_Used[i].OAL_slot->convert_read_adc();

					*(res_ptr + i)/=ave_num;					
					*(res_ptr + i)-=32768;					
					*(res_ptr + i)*=ADC_scale;					
				}
				
				SetMeasDue=true;

			} break; 

			case QAL:
			{
				unsigned short status_relay_bank_1=QAL_Used[i].QAL_slot->card.relay_bank_1;
				unsigned short status_relay_bank_2=QAL_Used[i].QAL_slot->card.relay_bank_2;
				unsigned short status_switch_bank_1=QAL_Used[i].QAL_slot->card.switch_bank_1;
				unsigned short status_switch_bank_2=QAL_Used[i].QAL_slot->card.switch_bank_2;
				unsigned short status_switch_bank_3=QAL_Used[i].QAL_slot->card.switch_bank_3;
				unsigned short status_switch_bank_4=QAL_Used[i].QAL_slot->card.switch_bank_4;
				unsigned short status_adc_mux=QAL_Used[i].QAL_slot->card.adc_mux;
	
				bool status_EXT_RLY_DRV=0x1&(status_relay_bank_2>>(QAL_EXT_RLY_DRV%16));

				bool status_DRV_1=0x1&(status_switch_bank_2>>(QAL_DRV_1%16));


				bool status_DUT_NEG_ISOL=0x1&(status_relay_bank_1>>(QAL_DUT_NEG_ISOL%16));	
				bool status_DUT_POS_ISOL=0x1&(status_relay_bank_1>>(QAL_DUT_POS_ISOL%16));	

				bool status_IA_1MV=0x1&(status_switch_bank_1>>(QAL_IA_1MV%16));
				bool status_IA_10MV=0x1&(status_switch_bank_1>>(QAL_IA_10MV%16));
				bool status_IA_100MV=0x1&(status_switch_bank_1>>(QAL_IA_100MV%16));

				bool status_MLG_CON_POS=0x1&(status_switch_bank_1>>(QAL_MLG_CON_POS%16));
				bool status_LLG_CON_POS=0x1&(status_switch_bank_1>>(QAL_LLG_CON_POS%16));
				bool status_POS_LKG_X10=0x1&(status_switch_bank_1>>(QAL_POS_LKG_X10%16));

				bool status_MLG_CON_NEG=0x1&(status_switch_bank_1>>(QAL_MLG_CON_NEG%16));
				bool status_LLG_CON_NEG=0x1&(status_switch_bank_1>>(QAL_LLG_CON_NEG%16));
				bool status_NEG_LKG_X10=0x1&(status_switch_bank_1>>(QAL_NEG_LKG_X10%16));

				bool status_CH0_MEAS=0x1&(status_switch_bank_2>>(QAL_CH0_MEAS%16));
				bool status_CH1_MEAS=0x1&(status_switch_bank_2>>(QAL_CH1_MEAS%16));
				bool status_CH2_MEAS=0x1&(status_switch_bank_4>>(QAL_CH2_MEAS%16));
				bool status_CH3_MEAS=0x1&(status_switch_bank_4>>(QAL_CH3_MEAS%16));

				bool status_CLOSE_LOOP=0x1&(status_switch_bank_1>>(QAL_CLOSE_LOOP%16));
				bool status_CLS_LOOP_IV=0x1&(status_switch_bank_1>>(QAL_CLS_LOOP_IV%16));

				float ADC_scale=1.0;
				int	sample;
				float Req;

		
				if(usr_wait_us==-1.0f)
					wait_us=qal_default_wait_us;
				else
					wait_us=usr_wait_us;

				switch(mode)
				{
					case MEASURE_CURRENT:
						switch(Pin_Type_Used[pin][i].PinClass)
						{
						case PIN_IN_POS:
							switch(d_range)
							{
							case RANGE_100_PA:
								if(
									(status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(!status_DUT_POS_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&

									(
									  ((status_adc_mux==QAL_EXT_PICO_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_EXT_PICO_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))


									)
								  )
									SetMeasDue=false;	
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10);
									QAL_Used[i].QAL_slot->open_relay(QAL_DUT_POS_ISOL);	
									QAL_Used[i].QAL_slot->open_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->open_switch(QAL_DRV_1);
						
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_EXT_PICO_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_EXT_PICO_POS);
								
							
							
								
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f+100e3f/1.1e3f);
								ADC_scale=((float)(10 V)/Req)/32768;
								break;
							case RANGE_1_NA:
								if(
									(status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(!status_DUT_POS_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
						
									(
									  ((status_adc_mux==QAL_EXT_PICO_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_EXT_PICO_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))
								
							
									)
								  )
									SetMeasDue=false;	
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10);
									QAL_Used[i].QAL_slot->open_relay(QAL_DUT_POS_ISOL);	
									QAL_Used[i].QAL_slot->open_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->open_switch(QAL_DRV_1);
								
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_EXT_PICO_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_EXT_PICO_POS);
								
							
							
								
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f);
								ADC_scale=((float)(10 V)/Req)/32768;
								break;
							case RANGE_10_NA:
								if(
									(status_MLG_CON_POS)&&
									(!status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_LLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_LLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_LLG_POS%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_LLG_POS%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
									SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_POS);
									QAL_Used[i].QAL_slot->close_switch(QAL_LLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
							
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_LLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_LLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_LLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_LLG_POS);
								}
								ADC_scale=(float)(10 nA)/32768;
								break;
							case RANGE_1_UA:
								if(
									(!status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(status_POS_LKG_X10)&&
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_MLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_MLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_MLG_POS%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_MLG_POS%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
									SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_POS_LKG_X10);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
							
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_POS);
								}
								ADC_scale=(float)(1 uA)/32768;
								break;
							default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - wrong current meter range\nRange set to 10UA for PIN %s",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								}
							case RANGE_10_UA:
								if(
									(!status_MLG_CON_POS)&&
									(status_LLG_CON_POS)&&
									(status_DUT_POS_ISOL)&&		
									(!status_POS_LKG_X10)&&
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_MLG_POS%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_MLG_POS%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_MLG_POS%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_MLG_POS%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_POS);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_POS);
									QAL_Used[i].QAL_slot->close_switch(QAL_POS_LKG_X10);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
							
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_POS);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_POS);
								}
								ADC_scale=(float)(10 uA)/32768;
							}break;
						case PIN_IN_NEG:
							switch(d_range)
							{
							case RANGE_100_PA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_DUT_NEG_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
						
									(
									  ((status_adc_mux==EXT_PICO_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))
								
								
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10);
									QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
									QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
									QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL);	
									QAL_Used[i].QAL_slot->open_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->open_switch(QAL_DRV_1);
					
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_EXT_PICO_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_EXT_PICO_NEG);
								
								
								
								
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f+100e3f/1.1e3f);
								ADC_scale=((float)(10 V)/Req)/32768;

								break;
							case RANGE_1_NA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_DUT_NEG_ISOL)&&		
									(!status_EXT_RLY_DRV)&&
									(status_DRV_1)&&
							
									(
									  ((status_adc_mux==EXT_PICO_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==CH1_EXT_PICO_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))
							
								
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10);
									QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
									QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
									QAL_Used[i].QAL_slot->open_relay(QAL_DUT_NEG_ISOL);	
									QAL_Used[i].QAL_slot->open_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->open_switch(QAL_DRV_1);
							
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_EXT_PICO_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_EXT_PICO_NEG);
								
									
							
								
								}
								Req=1e9f*(1+100e3f/1e9f+100e3f/10e3f);
								ADC_scale=((float)(10 V)/Req)/32768;

								break;
							case RANGE_10_NA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(status_MLG_CON_NEG)&&
									(!status_LLG_CON_NEG)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_LLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_LLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_LLG_NEG%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_LLG_NEG%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->open_switch(QAL_MLG_CON_NEG);
									QAL_Used[i].QAL_slot->close_switch(QAL_LLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10);
									QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
									QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
						
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_LLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_LLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_LLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_LLG_NEG);
								}
								ADC_scale=(float)(10 nA)/32768;
								break;
							case RANGE_1_UA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(!status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(status_NEG_LKG_X10)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_MLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_MLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_MLG_NEG%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_MLG_NEG%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_NEG_LKG_X10);
									QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
									QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
							
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_NEG);
								}
								ADC_scale=(float)(1 uA)/32768;
								break;
							default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - wrong current meter range\nRange set to 10UA for PIN %s",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								}
							case RANGE_10_UA:
								if(
									(status_CLOSE_LOOP)&&
									(!status_CLS_LOOP_IV)&&
									(!status_MLG_CON_NEG)&&
									(status_LLG_CON_NEG)&&
									(!status_NEG_LKG_X10)&&
									(status_DUT_NEG_ISOL)&&		
									(status_EXT_RLY_DRV)&&
									(!status_DRV_1)&&
									(
									  ((status_adc_mux==QAL_MLG_NEG%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
									  ((status_adc_mux==QAL_CH1_MLG_NEG%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
									  ((status_adc_mux==QAL_CH2_MLG_NEG%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
									  ((status_adc_mux==QAL_CH3_MLG_NEG%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
									)
								  )
								   SetMeasDue=false;
								else
								{
									QAL_Used[i].QAL_slot->close_switch(QAL_MLG_CON_NEG);
									QAL_Used[i].QAL_slot->open_switch(QAL_LLG_CON_NEG);
									QAL_Used[i].QAL_slot->close_switch(QAL_NEG_LKG_X10);
									QAL_Used[i].QAL_slot->close_switch(QAL_CLS_LOOP_IV);
									QAL_Used[i].QAL_slot->open_switch(QAL_CLOSE_LOOP);
									QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);	
									QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
									QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);
					
									if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_MLG_NEG);
									else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
										QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_MLG_NEG);
								}
								ADC_scale=(float)(10 uA)/32768;
							}break;
						default:
								{
								char err_message[100];
								sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
								mytext.text_in_box(40,10,err_message);
								return;
								}
						}
					break;		

				case MEASURE_VOLTAGE:
					if(Pin_Type_Used[pin][i].PinClass!=PIN_OUT)
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Output for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}
					if(((status_adc_mux==QAL_HV_BUF%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
					   ((status_adc_mux==QAL_CH1_HV_BUF%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
					   ((status_adc_mux==QAL_CH2_HV_BUF%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
					   ((status_adc_mux==QAL_CH3_HV_BUF%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)))
						SetMeasDue=false;
					else
					{
						if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_HV_BUF);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_HV_BUF);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_HV_BUF);
						else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_HV_BUF);
					}
					ADC_scale*=(float)(40 V)/32768;
					break;
				case MEASURE_DIFF_VOLTAGE:
					if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}
					if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
						ADC_scale=-1.0f;	
					else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
						ADC_scale=1.0f;	
					else
						{
						char err_message[100];
						sprintf(err_message, "dc_measure() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
						}

					switch(d_range)
					{
						case RANGE_100_UV:
							if(
								(status_IA_1MV)&&	
								(status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==QAL_IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
								  ((status_adc_mux==QAL_CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
								  ((status_adc_mux==QAL_CH2_IA_AMP%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
								  ((status_adc_mux==QAL_CH3_IA_AMP%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
								)
							  )
								SetMeasDue=false;
							else
							{
								if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							}
							ADC_scale*=(float)(100 uV)/32768;
							break;
						case RANGE_1_MV:
							if(
								(!status_IA_1MV)&&	
								(status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==QAL_IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
								  ((status_adc_mux==QAL_CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
								  ((status_adc_mux==QAL_CH2_IA_AMP%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
								  ((status_adc_mux==QAL_CH3_IA_AMP%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
								QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							}
							ADC_scale*=(float)(1 mV)/32768;
							break;
						case RANGE_10_MV:
							if(
								(status_IA_1MV)&&	
								(!status_IA_10MV)&&
								(status_IA_100MV)&&
								(
								  ((status_adc_mux==QAL_IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
								  ((status_adc_mux==QAL_CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
								  ((status_adc_mux==QAL_CH2_IA_AMP%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
								  ((status_adc_mux==QAL_CH3_IA_AMP%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
								)
							  )
								SetMeasDue=false;	
							else
							{
								if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
								QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							}
							ADC_scale*=(float)(10 mV)/32768;
							break;
						case RANGE_100_MV:
							if(
								(status_IA_1MV)&&	
								(status_IA_10MV)&&
								(!status_IA_100MV)&&
								(
								  ((status_adc_mux==QAL_IA_AMP%8)&&status_CH0_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0))||
								  ((status_adc_mux==QAL_CH1_IA_AMP%8)&&status_CH1_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1))||
								  ((status_adc_mux==QAL_CH2_IA_AMP%8)&&status_CH2_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2))||
								  ((status_adc_mux==QAL_CH3_IA_AMP%8)&&status_CH3_MEAS&&(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3))
								)
							  )
								SetMeasDue=false;
							else
							{
								if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_0)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_1)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_2)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
								else if(Pin_Type_Used[pin][i].Channel==QAL_CHANNEL_3)
									QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
								QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
								QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
							}
							ADC_scale*=(float)(100 mV)/32768;
							break;
						default:
							{
							char err_message[100];
							sprintf(err_message, "dc_measure() - wrong IA range\nRange set to 100MV for PIN %s",Pin_Type_Used[pin][i].Pin_Name);	
							mytext.text_in_box(40,10,err_message);
							}
						}
					break;	

				default:
					{
					char err_message[100];
					sprintf(err_message, "dc_measure() - Invalid Measure mode for QOAL - pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return;
					}
				} 

				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));

				float VioComp=*(res_ptr + i);

				*(res_ptr + i) = 0.0f;
				if (ave_num>0)
				{
					for(sample=0;sample<ave_num;sample++)
						*(res_ptr + i) += QAL_Used[i].QAL_slot->convert_read_adc();

					*(res_ptr + i)/=ave_num;					
					*(res_ptr + i)-=32768;					
					*(res_ptr + i)*=ADC_scale;				
				}
				
				SetMeasDue=true;	

			} break; 

			default:
				mytext.text_in_box(40,10,"dc_measure() not executable for a relay pin");
				exit(0);
			}
		}	
	
	}  

#ifndef LegacyXerxes
	if(XviPin)
	{
		if(ave_num > 1)
		{
		
			for( i = 0; i < max_sites ; i++ )
				save_active_site[i]=active_site[i];

		
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				if(pin_selection(pin,i)!=XVI)
					active_site[i]=0;

	
			xvi_read_average(pin,single_xvi_pin_result);

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				res_ptr[i]=(float)(single_xvi_pin_result[i]);

		
			for( i = 0; i < max_sites ; i++ )
				save_active_site[i]=active_site[i];
		} else
		
		if(ave_num == 1)
		{
			if(usr_wait_us==-1.0f)
				wait_us=xvi_default_wait_us;
			else
				wait_us=usr_wait_us;

		
			if(XviSetMeasDue)
				wait.delay_10_us(int(wait_us/10));

			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{
					Source_type=pin_selection(pin,i);
					switch(Source_type)
					{
					case XVI:
if(!debug_xvi_msl_offline)	
{
						XVI_Used[i].XVI_slot->measure(XVI_Used[i].XVI_channel,single_xvi_pin_result[i]);
}
						*(res_ptr + i) = (float)(single_xvi_pin_result[i]);

						break;
					default:
						break;
					}	
				}	
			}
		} 
	}
#endif


	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void dc_mvi(short pin, short mode ,double *res_ptr ,short ave_num, short d_range, short usr_wait_us, double fre_sample, sdouble_wf meas_array)
{
	int i;

	short Source_type;

	DYN_GROUP_LIST *pin_ptr;

	short	wait_us=0;

	short	dvi_default_wait_us=350,	
			ovi_default_wait_us=200,	
			hvs_default_wait_us=200,	
			ofs_default_wait_us=200,	
			pvi_default_wait_us=200,	
			ov2_default_wait_us=350;

	STRING  measure_mode, prg_name;

	char	ovi_vrange=NULL;	

	pin_ptr = group_selection(pin); 
	
	DYN_GROUP_LIST *anker_ptr = pin_ptr;

	bool SetMeasDue=false;

	BYTE current_measure_index;
	BYTE original_measure_index;	

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: 
				break;	

			case OV2:
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<ov2_default_wait_us)
					{
						wait_us=ov2_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				current_measure_index = 0xff;
				original_measure_index = OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index;

				if(mode == MEASURE_VOLTAGE)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[original_measure_index])==OV2_MEASURE_VOLTAGE)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[original_measure_index])==OV2_Used[i].OV2_channel))
					{
						current_measure_index=original_measure_index;
					}					
				}
				else if(mode == MEASURE_CURRENT)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[original_measure_index])==OV2_MEASURE_CURRENT)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[original_measure_index])==OV2_Used[i].OV2_channel))
					{
						current_measure_index=original_measure_index;
					}
				}
				if ( current_measure_index==0xff )
				{
					if ( (OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index!=0)||
						(mode == MEASURE_DIFF_VOLTAGE) )
					{
						current_measure_index=0;
					}	
					else
					{
						current_measure_index=1;
					}	
				}
				
				if(mode == MEASURE_VOLTAGE)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[current_measure_index])==OV2_MEASURE_VOLTAGE)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[current_measure_index])==OV2_Used[i].OV2_channel))
					{
					}
					else
					{
						SetMeasDue=true;
					}

					if (current_measure_index==0)
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_VOLTAGE);
					}
					else
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure2_filter();
						else OV2_Used[i].OV2_slot->enable_measure2_filter();
						OV2_Used[i].OV2_slot->set_meas2_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_VOLTAGE);
					}
				}
				if(mode == MEASURE_CURRENT)
				{
					if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[current_measure_index])==OV2_MEASURE_CURRENT)&&
					((int)(OV2_Used[i].OV2_slot->card.meas_channel[current_measure_index])==OV2_Used[i].OV2_channel))
					{
					}
					else
					{
						SetMeasDue=true;
					}

					if (current_measure_index==0)
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_CURRENT);
					}
					else
					{
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure2_filter();
						else OV2_Used[i].OV2_slot->enable_measure2_filter();
						OV2_Used[i].OV2_slot->set_meas2_mode(OV2_Used[i].OV2_channel, OV2_MEASURE_CURRENT);
					}
				}
				if(mode == MEASURE_DIFF_VOLTAGE)
				{
					if (OV2_Used[i].OV2_channel==OV2_CHANNEL_7)
					{
						if(((int)(OV2_Used[i].OV2_slot->card.meas_mode[OV2_MEASURE_0])==OV2_MEASURE_DIFF)&&
							((int)(OV2_Used[i].OV2_slot->card.meas_channel[OV2_MEASURE_0])==OV2_Used[i].OV2_channel)&&
							((int)(OV2_Used[i].OV2_slot->card.meas_channel[OV2_MEASURE_1])==OV2_CHANNEL_0&&
							(int)(OV2_Used[i].OV2_slot->debug_diff_range)==d_range))
						{
						}
						else
						{
							SetMeasDue=true;
						}
						
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel,OV2_CHANNEL_0,OV2_MEASURE_DIFF,d_range);
					}
					else
					{						
						if (OV2_Used[i].is_filter == false) OV2_Used[i].OV2_slot->disable_measure_filter();
						else OV2_Used[i].OV2_slot->enable_measure_filter();
						OV2_Used[i].OV2_slot->set_meas_mode(OV2_Used[i].OV2_channel,OV2_Used[i].OV2_channel+1,OV2_MEASURE_DIFF,d_range);
					}
				}
			
				OV2_Card_Used[Pin_Type_Used[pin][i].Slot-1].original_measure_index=current_measure_index;

				break;

			case DVI:
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<dvi_default_wait_us)
					{
						wait_us=dvi_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				if(DVI_Used[i].DVI_slot->dvi_rev!=DVI_REVF&&DVI_Used[i].DVI_slot->dvi_rev!=DVI_REVG)
				{
					if (DVI_Used[i].is_filter == false) DVI_Used[i].DVI_slot->disable_measure_filter();
					else DVI_Used[i].DVI_slot->enable_measure_filter();
				}

				if(mode == MEASURE_VOLTAGE)
				{
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==0)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
					{
					}
					else
					{
						SetMeasDue=true;
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_VOLTAGE);
					}
				}
				if(mode == MEASURE_DIFF_VOLTAGE)
				{
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==3)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_diff_range)==d_range))
					{
					}
					else
					{
						SetMeasDue=true;
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_DIFF);
			
						if (d_range != NO_DIFF_RANGE)
							DVI_Used[i].DVI_slot->set_diff_range(d_range);
					}
				}
				if(mode == MEASURE_CURRENT)
				{
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==1)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
					{
					}
					else
					{
						SetMeasDue=true;
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_CURRENT);
					}
				}
				if(mode == MEASURE_EXT_REF)
				{
					if(((int)(DVI_Used[i].DVI_slot->debug_meassure_mode[DVI_Used[i].DVI_channel])==DVI_MEASURE_EXT_REF)&&
					    ((int)(DVI_Used[i].DVI_slot->debug_current_channel)==DVI_Used[i].DVI_channel))
						SetMeasDue=false;
					else
						DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_EXT_REF);
				}
		
				break;

			case OVI:
			case OVI_S:	
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<ovi_default_wait_us)
					{
						wait_us=ovi_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
				{
					OVI_Used[i].OVI_slot->get_voltage_range(OVI_Used[i].OVI_channel, ovi_vrange);	
					
					if(((int)(OVI_Used[i].OVI_slot->m_active_meas_mode)==0)&&				
					    ((int)(OVI_Used[i].OVI_slot->m_active_channelSC)==OVI_Used[i].OVI_channel)&&
						((mode == MEASURE_CURRENT)||((mode == MEASURE_VOLTAGE)&&(int(ovi_vrange)==OVI_Used[i].OVI_slot->m_active_rangeSC)&&((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE)||(d_range==OVI_Used[i].OVI_slot->m_active_rangeSC)))))
					{
					}
					else
					{
						SetMeasDue=true;
						if ((d_range==NULL)||(d_range==AUTORANGE)||(d_range==NO_DIFF_RANGE))
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE);
						else
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE, d_range);
					}
				}
				if(mode == MEASURE_CURRENT)
				{
					if(((int)(OVI_Used[i].OVI_slot->m_active_meas_mode)==1)&&
					    
					    ((int)(OVI_Used[i].OVI_slot->m_active_channelSC)==OVI_Used[i].OVI_channel))
						{
					}
					else
					{
						SetMeasDue=true;
						OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_CURRENT);
					}
				}
		
				break;
						
			case HVS:
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<hvs_default_wait_us)
					{
						wait_us=hvs_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
					if(HVS_Used[i].HVS_slot->m_active_meas_mode==1024)
					{
					}
					else
					{
						SetMeasDue=true;
						HVS_Used[i].HVS_slot->set_meas_mode(HVS_MEASURE_VOLTAGE);
					}
				if(mode == MEASURE_CURRENT)
					if(HVS_Used[i].HVS_slot->m_active_meas_mode==8192)
					{
					}
					else
					{
						SetMeasDue=true;
						HVS_Used[i].HVS_slot->set_meas_mode(HVS_MEASURE_CURRENT);
					}
		
				break;

			case OFS:
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<ofs_default_wait_us)
					{
						wait_us=ofs_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				SetMeasDue=true;

				if(mode == MEASURE_VOLTAGE)
					OFS_Used[i].OFS_slot->set_meas_mode(OFS_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)
					OFS_Used[i].OFS_slot->set_meas_mode(OFS_MEASURE_CURRENT);

				break;

			case PVI:
				if(usr_wait_us==-1.0f)
				{
					if(wait_us<pvi_default_wait_us)
					{
						wait_us=pvi_default_wait_us;
					}
				}
				else
					wait_us=usr_wait_us;

				if(mode == MEASURE_VOLTAGE)
					if(PVI_Used[i].PVI_slot->measure_mode==0)
					{
					}
					else
					{
						SetMeasDue=true;
						PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_VOLTAGE);
					}
				if(mode == MEASURE_CURRENT)
					if(PVI_Used[i].PVI_slot->measure_mode==1)
					{
					}
					else
					{
						SetMeasDue=true;
						PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_CURRENT);
					}

				break;

			default:
				mytext.text_in_box(40,10,"dc_measure() not executable for a relay pin");
				exit(0);
			}
		}		
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

	if(usr_wait_us!=-1.0f)
	{
		wait_us=usr_wait_us;
	}
		
	if(SetMeasDue&&(ave_num>0))
		wait.delay_10_us(int(wait_us/10));

	awg_measure(pin, ave_num, fre_sample, meas_array, MEAS_NORMAL, 0, 0, 0, 0, 0);

	awg_get_measure_result(pin, res_ptr, MEAS_AVG, 0, ave_num-1);
}

float relay_connect(short relay, short mode, float load_var, LoadRefType LoadRef)
{
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	int i;

	float act_val=0.0f;

	
	pin_ptr = group_selection(relay); 

	do
	{
	relay = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(relay,i);
		
		if((Source_type==OAL)&&(Pin_Type_Used[relay][i].PinClass==PIN_OUT))
			act_val=oal_connect_load(relay, mode, load_var, LoadRef);
		else if((Source_type==QAL)&&(Pin_Type_Used[relay][i].PinClass==PIN_OUT))
			act_val=qal_connect_load(relay, mode, load_var, LoadRef);
		else
			relay_connect(relay, mode);
	}
	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	return act_val;
}


void  relay_connect(short relay, short mode)
{
	int i;
	short Relay_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(relay); 

	do
	{


	relay = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Relay_type=pin_selection(relay,i);

			switch(Relay_type)
			{

			case NONE:	break;	

			case MUX:
				if (mode==CLOSE)
					MUX_Used[i].MUX_slot->close_relay(MUX_Used[i].MUX_channel);
				else
					MUX_Used[i].MUX_slot->open_relay(MUX_Used[i].MUX_channel);
			break;
	
			case CBT:
				if (mode==CLOSE)
					CBT_Used[i].CBT_slot->set_drive_on(CBT_Used[i].CBT_channel_str);
				else
					CBT_Used[i].CBT_slot->set_drive_off(CBT_Used[i].CBT_channel_str);
			break;
				
			case DVI:
				if (mode==CLOSE)
					DVI_Used[i].DVI_slot->close_relay(DVI_Used[i].DVI_channel);
				else
					DVI_Used[i].DVI_slot->open_relay(DVI_Used[i].DVI_channel);
			break;
				
			case TMU:
				if (mode==CLOSE)
					TMU_Used[i].TMU_slot->close_relay(TMU_Used[i].TMU_channel);
				else
					TMU_Used[i].TMU_slot->open_relay(TMU_Used[i].TMU_channel);
			break;
				
			case QTMU1:
				if (mode==CLOSE)
					QTMU1_Used[i].QTMU1_slot->qtmu1_close_relay(QTMU1_Used[i].QTMU1_unit,QTMU1_Used[i].QTMU1_channel);
				else
					QTMU1_Used[i].QTMU1_slot->qtmu1_open_relay(QTMU1_Used[i].QTMU1_unit,QTMU1_Used[i].QTMU1_channel);
			break;

			case LZB:
				if (mode==CLOSE) {
					if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
						LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel);		
					if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
						LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel_2);	
				}
				else {
					if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)				
						LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel);	
					if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
						LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel_2);
				}

			break;

#ifndef ASL1K_NO_CBIT
			case CBIT:	
				if (mode==CLOSE)
					cbits.SetCbit(CBIT_Used[i].CBIT_channel,true);	
				else
					cbits.SetCbit(CBIT_Used[i].CBIT_channel,false);
			break;
#endif
			case OAL:	
				switch(Pin_Type_Used[relay][i].PinClass)
				{
				case PIN_OUT:
		


				
					
			
			
			

			
	
			

			
		
		
		
					if (mode==CLOSE_LOAD) 
						oal_connect_load(relay,CLOSE_LOAD);	else
					if (mode==OPEN_LOAD)
						oal_connect_load(relay,OPEN_LOAD); else
					if (mode == CLOSE_CONNECT_LOADS)
						OAL_Used[i].OAL_slot->close_relay(CONNECT_LOADS); else
					if (mode == OPEN_CONNECT_LOADS)
						OAL_Used[i].OAL_slot->open_relay(CONNECT_LOADS); else
					if (mode == CLOSE_LOAD_SHORT)
						OAL_Used[i].OAL_slot->close_relay(LOAD_SHORT); else
					if (mode == OPEN_LOAD_SHORT)
						OAL_Used[i].OAL_slot->open_relay(LOAD_SHORT); else
					if (mode == CLOSE_LOAD_600)
						OAL_Used[i].OAL_slot->close_relay(LOAD_600); else
					if (mode == OPEN_LOAD_600)
						OAL_Used[i].OAL_slot->open_relay(LOAD_600); else
					if (mode == CLOSE_LOAD_1K)
						OAL_Used[i].OAL_slot->close_relay(LOAD_1K); else
					if (mode == OPEN_LOAD_1K)
						OAL_Used[i].OAL_slot->open_relay(LOAD_1K); else
					if (mode == CLOSE_LOAD_2K)
						OAL_Used[i].OAL_slot->close_relay(LOAD_2K); else
					if (mode == OPEN_LOAD_2K)
						OAL_Used[i].OAL_slot->open_relay(LOAD_2K); else
					if (mode == CLOSE_LOAD_4K7)
						OAL_Used[i].OAL_slot->close_relay(LOAD_4K7); else
					if (mode == OPEN_LOAD_4K7)
						OAL_Used[i].OAL_slot->open_relay(LOAD_4K7); else
					if (mode == CLOSE_LOAD_10K)
						OAL_Used[i].OAL_slot->close_relay(LOAD_10K); else
					if (mode == OPEN_LOAD_10K)
						OAL_Used[i].OAL_slot->open_relay(LOAD_10K); else
					if (mode == CLOSE_LOAD_100K)
						OAL_Used[i].OAL_slot->close_relay(LOAD_100K); else
					if (mode == OPEN_LOAD_100K)
						OAL_Used[i].OAL_slot->open_relay(LOAD_100K); else
					if (mode == OPEN_LOAD_REF_GND)
						OAL_Used[i].OAL_slot->close_relay(LOAD_REF_GND); else
					if (mode == CLOSE_LOAD_REF_GND)
						OAL_Used[i].OAL_slot->open_relay(LOAD_REF_GND); else
					if (mode == OPEN_LOAD_REF_EXT)
						OAL_Used[i].OAL_slot->close_relay(LOAD_REF_EXT); else
					if (mode == CLOSE_LOAD_REF_EXT)
						OAL_Used[i].OAL_slot->open_relay(LOAD_REF_EXT); else
					if (mode == CLOSE_EXT_LOAD_CONN)
						OAL_Used[i].OAL_slot->close_relay(EXT_LOAD_CONN); else
					if (mode == OPEN_EXT_LOAD_CONN)
						OAL_Used[i].OAL_slot->open_relay(EXT_LOAD_CONN);				
					else
					{
						char err_message[100];
						sprintf(err_message, "relay_connect() - mode non recognized for pin %s",Pin_Type_Used[relay][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;
			
			
			
		
		
						
			
		
	


		
	
					
					
						
		
		


	

	

	

		
		
	
						
						
			
					
			

			
	
					
					

		
	

	
		
			


	
		
	

				case PIN_EXT_DRV1:
					if (mode==CLOSE)
						OAL_Used[i].OAL_slot->close_relay(OAL_Used[i].OAL_channel);
					else
						OAL_Used[i].OAL_slot->open_relay(OAL_Used[i].OAL_channel);
					break;
				case PIN_EXT_DRV2:
					if (mode==CLOSE)
						OAL_Used[i].OAL_slot->open_switch(OAL_Used[i].OAL_channel);
					else
						OAL_Used[i].OAL_slot->close_switch(OAL_Used[i].OAL_channel);
					break;


				case PIN_LOAD:
					if (mode == CLOSE)
						OAL_Used[i].OAL_slot->close_relay(OAL_Used[i].OAL_channel); else
					if (mode == OPEN)
						OAL_Used[i].OAL_slot->open_relay(OAL_Used[i].OAL_channel);
					else
					{
						char err_message[100];
						sprintf(err_message, "relay_connect() - mode non recognized for pin %s",Pin_Type_Used[relay][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;
				default:
					mytext.text_in_box(40,10,"relay_connect() not executable for a doal in/out pin");
					exit(0);
				}

			break;

			case QAL:	
				switch(Pin_Type_Used[relay][i].PinClass)
				{
				case PIN_OUT:
			
		
	
	
						

				
					
	
					
			
	



			
				

					
				
						
			
				
	

					if (mode==CLOSE_LOAD) 
						qal_connect_load(relay,CLOSE_LOAD);	else
					if (mode==OPEN_LOAD)
						qal_connect_load(relay,OPEN_LOAD); else
					if (mode == CLOSE_CONNECT_LOADS)
						QAL_Used[i].QAL_slot->close_relay(QAL_CONNECT_LOADS); else
					if (mode == OPEN_CONNECT_LOADS)
						QAL_Used[i].QAL_slot->open_relay(QAL_CONNECT_LOADS); else
					if (mode == CLOSE_LOAD_SHORT)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_SHORT); else
					if (mode == OPEN_LOAD_SHORT)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_SHORT); else
					if (mode == CLOSE_LOAD_600)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_600); else
					if (mode == OPEN_LOAD_600)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_600); else
					if (mode == CLOSE_LOAD_1K)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_1K); else
					if (mode == OPEN_LOAD_1K)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_1K); else
					if (mode == CLOSE_LOAD_2K)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_2K); else
					if (mode == OPEN_LOAD_2K)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_2K); else
					if (mode == CLOSE_LOAD_4K7)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_4K7); else
					if (mode == OPEN_LOAD_4K7)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_4K7); else
					if (mode == CLOSE_LOAD_10K)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_10K); else
					if (mode == OPEN_LOAD_10K)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_10K); else
					if (mode == CLOSE_LOAD_100K)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_100K); else
					if (mode == OPEN_LOAD_100K)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_100K); else
					if (mode == OPEN_LOAD_REF_GND)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_REF_GND); else
					if (mode == CLOSE_LOAD_REF_GND)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_REF_GND); else
					if (mode == OPEN_LOAD_REF_EXT)
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_REF_EXT); else
					if (mode == CLOSE_LOAD_REF_EXT)
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_REF_EXT); else
					if (mode == CLOSE_EXT_LOAD_CONN)
						QAL_Used[i].QAL_slot->close_relay(QAL_EXT_LOAD_CONN); else
					if (mode == OPEN_EXT_LOAD_CONN)
						QAL_Used[i].QAL_slot->open_relay(QAL_EXT_LOAD_CONN);				
					else
					{
						char err_message[100];
						sprintf(err_message, "relay_connect() - mode non recognized for pin %s",Pin_Type_Used[relay][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;
				
			
		
			
						
						 
					
				
					
						 
					

		


			
		
				
				
				
		
 
					
			
		
			
			
					

	

		


	


				
					 
		
				
				
				
					
						
				

				
			
						
						 
						
						
					
					 
				
						
			
			
			
					
						
					
			
		
		

				
				case PIN_EXT_DRV1:
					if (mode==CLOSE)
						QAL_Used[i].QAL_slot->close_relay(QAL_Used[i].QAL_channel);
					else
						QAL_Used[i].QAL_slot->open_relay(QAL_Used[i].QAL_channel);
					break;
				case PIN_EXT_DRV2:
					if (mode==CLOSE)
						QAL_Used[i].QAL_slot->open_switch(QAL_Used[i].QAL_channel);
					else
						QAL_Used[i].QAL_slot->close_switch(QAL_Used[i].QAL_channel);
					break;

				
				case PIN_LOAD:
					if (mode == CLOSE)
						QAL_Used[i].QAL_slot->close_relay(QAL_Used[i].QAL_channel); else
					if (mode == OPEN)
						QAL_Used[i].QAL_slot->open_relay(QAL_Used[i].QAL_channel);
					else
					{
						char err_message[100];
						sprintf(err_message, "relay_connect() - mode non recognized for pin %s",Pin_Type_Used[relay][i].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;
				default:
					mytext.text_in_box(40,10,"relay_connect() not executable for a doal in/out pin");
					exit(0);
				}

			break;
			
			
			
			case HVS:
				if (mode==CLOSE)
					HVS_Used[i].HVS_slot->close_relay(HVS_Used[i].HVS_channel);
				else
					HVS_Used[i].HVS_slot->open_relay(HVS_Used[i].HVS_channel);
			break;
				
			case MVS:
				if (mode==CLOSE)
					MVS_Used[i].MVS_slot->close_relay(MVS_Used[i].MVS_channel);
				else
					MVS_Used[i].MVS_slot->open_relay(MVS_Used[i].MVS_channel);
			break;

			case OFS:
				if (mode==CLOSE)
					OFS_Used[i].OFS_slot->close_relay(OFS_Used[i].OFS_channel);
				else
					OFS_Used[i].OFS_slot->open_relay(OFS_Used[i].OFS_channel);
			break;

			default:
				mytext.text_in_box(40,10,"relay_connect() not executable for a vi pin");
				exit(0);

			}
		}
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}



void  set_driver_state(short relay, short mode)
{
	int i;
	short Relay_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(relay); 

	do
	{


	relay = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Relay_type=pin_selection(relay,i);

			switch(Relay_type)
			{
	
			case CBT:
				if (mode==CLOSE)
					CBT_Used[i].CBT_slot->set_drive_on(CBT_Used[i].CBT_channel_str);
				else
					CBT_Used[i].CBT_slot->set_drive_off(CBT_Used[i].CBT_channel_str);
			break;

			default:
				mytext.text_in_box(40,10,"relay_connect() not executable for a vi pin");
				exit(0);

			}
		}
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}



void  get_driver_state(short relay, char **err_pin, int *err_num)
{
	int i;
	short Relay_type;
	unsigned int status;
	int j=0;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(relay); 

	do
	{


	relay = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Relay_type=pin_selection(relay,i);

			switch(Relay_type)
			{
	
			case CBT:
				status = 0;
				CBT_Used[i].CBT_slot->get_driver_state(CBT_Used[i].CBT_channel_str,&status);
				if (status==0)
				{
					*(err_pin+j) = CBT_Used[i].CBT_channel_str;
					j++;
				}
			break;

			default:
				mytext.text_in_box(40,10,"relay_connect() not executable for a vi pin");
				exit(0);

			}
		}
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

	*err_num = j;
}



DYN_GROUP_LIST *group_selection(short group_name)
{
	int j;
	bool find_group;

	if (group_name == ALL_PINS)	
	{

		if (List_all_group[group_inserted+1].Pins_belong_to_Group == NULL) {
			for (j=0; j<pin_inserted; j++)

				attach_element(&List_all_group[group_inserted+1].Pins_belong_to_Group,j);
		}

		return(List_all_group[group_inserted+1].Pins_belong_to_Group);
	} else
	if (group_inserted== -1)	
	{



		single_pin->grouppin = group_name;
		return(single_pin); 
	} else
	{
		j=0;
		find_group=false;
		do {
			if (group_name==List_all_group[j].Group_Ref)
				find_group=true;
			else
				j++;
		} while((!find_group)&&(j<=group_inserted));
		if (find_group)

			return(List_all_group[j].Pins_belong_to_Group);	
		else
		{



			single_pin->grouppin = group_name;
			return(single_pin); 	
		}
	}
}




short pin_selection(short pin_name, int site)
{
	short pin_sel;
	return (pin_selection_(pin_name, site, &pin_sel));
}

short pin_selection_(short pin_name, int site,short *pin_sel)
	{
	int j,find_pin,flag;

	j=0;
	find_pin=0;
	flag = -1;
	do {
			if (pin_name==Pin_Type_Used[j][site].Pin_Ref)
				find_pin=1;
			else
				j++;
			}		
	while((find_pin==0)&&(j<pin_inserted));

	if (find_pin==0)
	{
			mytext.text_in_box(40,10,"Error in multisite function 'pin_selection':\n!! Invalid pin found !!\n");
			exit(0);
	} else
		*pin_sel = j;
			
	if (Pin_Type_Used[j][site].Board_Ref==DVI)
		{
			DVI_Used[site].DVI_slot= &dvi_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			DVI_Used[site].DVI_channel=Pin_Type_Used[j][site].Channel;
			DVI_Used[site].DVI_channel_ID=(DVI_CH_ID_e)(Pin_Type_Used[j][site].Channel_2);
			flag=DVI;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==OVI)
		{
			OVI_Used[site].OVI_slot= &ovi_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			OVI_Used[site].OVI_channel=Pin_Type_Used[j][site].Channel;
			flag=OVI;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==OVI_S)
		{
			OVI_Used[site].OVI_slot= &ovi_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			OVI_Used[site].OVI_channel=Pin_Type_Used[j][site].Channel;
			flag=OVI_S;
		}
#ifndef LegacyXerxes
	else if (Pin_Type_Used[j][site].Board_Ref==XVI)
		{
			XVI_Used[site].XVI_slot= &xvi_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			XVI_Used[site].XVI_channel=(XVI_CH_ID_e)(Pin_Type_Used[j][site].Channel);
			XVI_Used[site].XVI_ch_index=Pin_Type_Used[j][site].Channel_2;
			flag=XVI;
		}
#endif
	else if (Pin_Type_Used[j][site].Board_Ref==HVS)
		{
			HVS_Used[site].HVS_slot= &hvs_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			HVS_Used[site].HVS_channel=Pin_Type_Used[j][site].Channel;
			flag=HVS;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==OFS) 
		{
			OFS_Used[site].OFS_slot= &ofs_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			OFS_Used[site].OFS_channel=Pin_Type_Used[j][site].Channel;
			flag=OFS;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==MVS) 
		{
			MVS_Used[site].MVS_slot= &mvs_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			MVS_Used[site].MVS_channel=Pin_Type_Used[j][site].Channel;
			flag=MVS;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==PVI)	
		{
			PVI_Used[site].PVI_slot= &pv3_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			PVI_Used[site].PVI_channel=Pin_Type_Used[j][site].Channel;


			flag=PVI;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==MUX)
		{
			MUX_Used[site].MUX_slot= &mux_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			MUX_Used[site].MUX_channel=Pin_Type_Used[j][site].Channel;
			flag=MUX;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==CBT)
		{
			CBT_Used[site].CBT_slot= &cbt_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			CBT_Used[site].CBT_channel_str=Pin_Type_Used[j][site].Channel_str;
			CBT_Used[site].CBT_unit=Pin_Type_Used[j][site].Unit;
			flag=CBT;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==TMU)
		{
			TMU_Used[site].TMU_slot= &tmu_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			TMU_Used[site].TMU_channel=Pin_Type_Used[j][site].Channel;
			flag=TMU;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==QTMU1)
		{
			QTMU1_Used[site].QTMU1_slot= &qtmu1_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			QTMU1_Used[site].QTMU1_unit=Pin_Type_Used[j][site].Unit;
			QTMU1_Used[site].QTMU1_channel=Pin_Type_Used[j][site].Channel;
			flag=QTMU1;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==CBIT)	
		{
			CBIT_Used[site].CBIT_channel=Pin_Type_Used[j][site].Channel;
			flag=CBIT;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==LZB)	
		{
			LZB_Used[site].LZB_slot= &lzb_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			LZB_Used[site].LZB_channel = Pin_Type_Used[j][site].Channel;
			LZB_Used[site].LZB_channel_2 = Pin_Type_Used[j][site].Channel_2;
			flag=LZB;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==OAL)	 
		{
			OAL_Used[site].OAL_slot= &oal_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			OAL_Used[site].OAL_channel = Pin_Type_Used[j][site].Channel;
			flag=OAL;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==QAL)	 
		{
			QAL_Used[site].QAL_slot= &qal_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			QAL_Used[site].QAL_channel = Pin_Type_Used[j][site].Channel;
			flag=QAL;
		}
	else if (Pin_Type_Used[j][site].Board_Ref==ACS)	 
		{
			ACS_Used[site].ACS_slot= &acs_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			ACS_Used[site].ACS_channel = Pin_Type_Used[j][site].Channel;
			flag=ACS;
		}

	else if (Pin_Type_Used[j][site].Board_Ref==DDD)	 
		{
			DDD_Used[site].DDD_slot= &ddd_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			DDD_Used[site].DDD_channel = Pin_Type_Used[j][site].Channel;
			flag=DDD;
		}

	else if (Pin_Type_Used[j][site].Board_Ref==OV2)	 
		{
			OV2_Used[site].OV2_slot= &ov2_cards[board_ptr[Pin_Type_Used[j][site].Slot-1]];
			OV2_Used[site].OV2_channel = Pin_Type_Used[j][site].Channel;
			OV2_Used[site].OV2_channel_ID=(OV2_CH_ID_e)(Pin_Type_Used[j][site].Channel_2);
			flag=OV2;
		}

	else if (Pin_Type_Used[j][site].Board_Ref==NONE)	 
		{
			flag=NONE;
		}

	if (flag == -1)
	{
			mytext.text_in_box(40,10,"Error in multisite function 'pin_selection':\n!! Invalid source found !!\n");
			exit(0);
	}
	return flag;
	}



void display_error(char *text1,char *text2)
{
	char errormsg[255];
	strcpy(errormsg,text1);
	strcat(errormsg,": ");
	strcat(errormsg,text2);
	strcat(errormsg,"\nPlease check your Multisite MAP file\n");
	mytext.text_in_box(40,10,errormsg);
}


void read_pinmap_data (STRING pathname, STRING filename)
{
#define MAXPINNAMELENGTH	50
#define MAXSTRINGLENGTH		1000	

	char file_name[255];
	FILE *pinmapfp;
	char *token1, *numptr;
	char line[MAXSTRINGLENGTH];
	char buf[MAXSTRINGLENGTH];
	char seps[] = " ,:\t\n";
	bool is_pinname = false;
	bool is_resource = false;
	bool is_comment = false;
	bool is_groupname = false;
	int store_OVI_slot;	
	short sitenum =0;
	short pinnumber = 0;
	char pinname[MAXPINNAMELENGTH];
	char resourcename[MAXPINNAMELENGTH];
	int resourcetype;
	int channel_unit;
	int channel_num;
	char *cbt_channel_str;
	char mux_channel;
	char lzb_channel_str[2];
	int j;
	unsigned short	channel_id;


	initialize_cal_data();


	system_status_off();


	if (pathname.HasLen())
		file_path = pathname;
	else
		file_path = GetUserString( "MULTISITE" );
	strcpy(file_name,file_path);


	if (filename.HasLen())
		strcat(file_name,filename);
	else
		strcat(file_name,"multi_pin_map.txt");

	if ((pinmapfp = fopen(file_name,"r"))==NULL)
	{	
		strcat(file_name,": cannot open file\n");
		mytext.text_in_box(40,10,file_name);exit(0); 
	}

	pin_inserted=0; 
	group_inserted=-1;


	single_pin = NULL;
	attach_element(&single_pin,0);	
	lzb_zener_list = NULL;

	while( !feof( pinmapfp ) )
	{      
		fgets(line,MAXSTRINGLENGTH,pinmapfp);
	
		token1 = strtok( line, seps );   
		is_pinname = false;
		is_resource = false;
		is_comment = false;
		is_groupname = false;
		store_OVI_slot = 0;	
		pinnumber = 0;
		sitenum =0;


		if ((token1 != NULL) && (strlen(token1)>0))
		{
			strcpy(buf,token1);
			for(unsigned int i=0;i<strlen(buf);i++) 
				buf[i]=tolower(buf[i]);
			if(!strcmp(buf,"site"))
			{
				char *token2=strtok(NULL, seps);
				int token2_len=strlen(token2);
				int	ascii_zero=48;	

				for(int d=0;d<token2_len;d++) 
					if(isdigit(token2[d]))
						pinmap_max_sites+=((int)token2[d]-ascii_zero)*(int)(0.5+pow(10.0,(double)(token2_len-1-d)));
					else
					{
						pinmap_max_sites=0;
						display_error("PINMAP","Invalid number of sites");
					}
				}
		}

		if ((token1 != NULL) && (strlen(token1)>0) && (token1[0]=='#'))
		{	

			token1 = token1 + 1;
			is_groupname = true;
			group_inserted++;
		} 
		if ((token1 != NULL) && (strlen(token1)>0) && ((token1[0]=='0') || (atoi(token1) !=0)))
		{
			pinnumber = atoi(token1);
#ifdef DEBUG_MULTISITE
			printf( "number %d: ", pinnumber);
#endif
			is_pinname = true;
			token1 = strtok( NULL, seps );    
			sitenum = 1;

			while( (token1 != NULL) && (is_comment == false))
			{ 
				if ((strlen(token1)>1) && (strncmp(token1,"//",2) ==0))
				{	
#ifdef DEBUG_MULTISITE
					printf( "ignore %s (%d)\n", token1, strlen(token1) );
#endif
					is_comment = true;
				} else
				if (is_pinname)
				{
					if (pinnumber == 1000)
						is_comment = true;
					else
					{
						if (strlen(token1) > MAXPINNAMELENGTH)
						{	
							display_error(token1,"pin name exceeds maximum length");exit(0); 
						}

						strcpy(pinname,token1);

#ifdef DEBUG_MULTISITE
						printf( "%s ", pinname);
#endif
						if (is_groupname)
						{
							List_all_group[group_inserted].Group_Ref=pinnumber;
							strcpy(List_all_group[group_inserted].Group_Name,pinname);

							List_all_group[group_inserted].Pins_belong_to_Group = NULL;
						} else
						{
							List_all_pin[pin_inserted++]=pinnumber;
							is_resource = true;
						}

						is_pinname = false;
					}
				} else
				if (is_groupname)
				{  
					j = 0;
					bool find_pin = false;
					do {
						if (strcmp(token1,Pin_Type_Used[j][0].Pin_Name) == 0)
							find_pin = true;
						else
							j++;
					} while((!find_pin)&&(j<pin_inserted));
					if (!find_pin)
					{
						j = 0;
						bool find_pin = false;
						do {
							if (strcmp(token1,List_all_group[j].Group_Name) == 0)
								find_pin = true;
							else
								j++;
						} while((!find_pin)&&(j<group_inserted));
						if (find_pin)
						{
							pinnumber = j; 
						
							
								
							copy_list(&List_all_group[group_inserted].Pins_belong_to_Group,
										List_all_group[pinnumber].Pins_belong_to_Group);
						} else
						{
							display_error(token1,"unknown pin name in pin group");exit(0); 
						}
					} else
					{
						pinnumber = Pin_Type_Used[j][0].Pin_Ref;
						attach_element(&List_all_group[group_inserted].Pins_belong_to_Group,pinnumber);
					}
				} else
				if (is_resource)
				{
					if (strlen(token1) < 4)	
					{	
						display_error(token1,"resource name too short");exit(0); 
					}
					strcpy(resourcename,token1); 
#ifdef DEBUG_MULTISITE
					printf( "%s ", resourcename);
#endif
					Pin_Type_Used[pin_inserted-1][sitenum-1].Pin_Ref  = pinnumber;
					Pin_Type_Used[pin_inserted-1][sitenum-1].Site_Num = sitenum-1;
					Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_UNDEF;	
					strcpy(Pin_Type_Used[pin_inserted-1][sitenum-1].Pin_Name, pinname); 
					strcpy(Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_Name, resourcename); 


					if (strncmp(resourcename,"DVI",3)==0)
							resourcetype=DVI;
					else if (strncmp(resourcename,"OVI",3)==0) 
							resourcetype=OVI;
					else if (strncmp(resourcename,"HVS",3)==0) 
							resourcetype=HVS;
					else if (strncmp(resourcename,"OFS",3)==0) 
							resourcetype=OFS;
					else if (strncmp(resourcename,"MVS",3)==0) 
							resourcetype=MVS;
					else if (strncmp(resourcename,"PVI",3)==0) 
							resourcetype=PVI;
					else if (strncmp(resourcename,"MUX",3)==0) 
							resourcetype=MUX;
					else if (strncmp(resourcename,"CBT",3)==0) 
							resourcetype=CBT;
					else if (strncmp(resourcename,"TMU",3)==0) 
							resourcetype=TMU;
					else if (strncmp(resourcename,"QTMU1",5)==0) 
							resourcetype=QTMU1;
					else if (strncmp(resourcename,"CBIT",4)==0)	
							resourcetype=CBIT;
					else if (strncmp(resourcename,"LZB",3)==0)	
							resourcetype=LZB;
					else if (strncmp(resourcename,"OAL",3)==0)	
							resourcetype=OAL;
					else if (strncmp(resourcename,"QAL",3)==0)	
							resourcetype=QAL;
					else if (strncmp(resourcename,"ACS",3)==0)	
							resourcetype=ACS;
					else if (strncmp(resourcename,"DDD",3)==0)	
							resourcetype=DDD;
					else if (strncmp(resourcename,"OV2",3)==0)	
							resourcetype=OV2;
					else if (strncmp(resourcename,"NONE",4)==0)	
							resourcetype=NONE;
#ifndef	LegacyXerxes
					else if (strncmp(resourcename,"XVI",3)==0)	
							resourcetype=XVI;
					else
						{ 
							display_error(resourcename,"Invalid keyword\n(keywords: MUX OVI DVI XVI TMU HVS OFS MVS PVI CBIT LZB OAL ACS DDD NONE)");exit(0); 						}
#else
					else
						{ 
							display_error(resourcename,"Invalid keyword\n(keywords: MUX OVI DVI TMU HVS OFS MVS PVI CBIT LZB OAL ACS DDD NONE)");exit(0); 						}
#endif

					Pin_Type_Used[pin_inserted-1][sitenum-1].Board_Ref=resourcetype;

		
					if(resourcetype==NONE)	
						Pin_Type_Used[pin_inserted-1][sitenum-1].Slot=0;
					else
					{
						numptr = strstr( resourcename, "_" );
						if ((numptr == 0) || (numptr++ == 0))
						{	
							display_error(resourcename,"Invalid or missing slot number");exit(0); 
						}
						Pin_Type_Used[pin_inserted-1][sitenum-1].Slot=atoi(numptr);
					}

					
					if (resourcetype == OVI) {
						if (store_OVI_slot == 0) {	
							store_OVI_slot = Pin_Type_Used[pin_inserted-1][sitenum-1].Slot;
						} else {				
							if (store_OVI_slot == Pin_Type_Used[pin_inserted-1][sitenum-1].Slot)
							{
								Pin_Type_Used[pin_inserted-1][0].Board_Ref = OVI_S;
								Pin_Type_Used[pin_inserted-1][sitenum-1].Board_Ref = OVI_S;
							}
						}
					}

					
					if ((resourcetype != CBIT)&&(resourcetype!=NONE))	
					{		
						numptr = strstr( numptr, "_" );
						if ((numptr == 0) || (numptr++ == 0)) 
						{	
							display_error(resourcename,"Invalid or missing channel number");exit(0); 
						}
					}

					switch (resourcetype)
					{
						case NONE:	
							channel_unit=NULL;
							channel_num=NULL;
							break;
						case CBIT:	
							channel_num = atoi(numptr);	
							break;

						case DVI:
							if (numptr[0] == 'E')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=DVI_EXT_DRV1;
								else if (atoi(numptr) == 2)
										channel_num=DVI_EXT_DRV2;
								else
								{	
									display_error(resourcename,"Invalid DVI external driver");exit(0); 
								}
							}									
							else
							{
								
								switch(numptr[0])	
								{
								case '0': channel_num=DVI_CHANNEL_0; channel_id=DVI_CH_0;break;
								case '1': channel_num=DVI_CHANNEL_1; channel_id=DVI_CH_1;break;
								default : 
										display_error(resourcename,"Invalid DVI channel");
										exit(0); break;			
								}
							} 
							Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = channel_id;					
							break;
				
						case OVI:
						case OVI_S:
							switch(numptr[0])	
							{
							case '0': channel_num=OVI_CHANNEL_0; break;
							case '1': channel_num=OVI_CHANNEL_1; break;
							case '2': channel_num=OVI_CHANNEL_2; break;
							case '3': channel_num=OVI_CHANNEL_3; break;
							case '4': channel_num=OVI_CHANNEL_4; break;
							case '5': channel_num=OVI_CHANNEL_5; break;
							case '6': channel_num=OVI_CHANNEL_6; break;
							case '7': channel_num=OVI_CHANNEL_7; break;
							default : 
									display_error(resourcename,"Invalid OVI channel");
								    exit(0); break;			
							} break;

#ifndef	LegacyXerxes
						case XVI:	
							unsigned short	channel_index;

							switch(numptr[0])	
							{
							case '0': channel_num=XVI_CHANNEL_0; channel_index=0; break;
							case '1':
								switch(numptr[1])	
								{
									case '\0': channel_num=XVI_CHANNEL_1; channel_index=1;  break;
									case '0':  channel_num=XVI_CHANNEL_10; channel_index=10;  break;
									case '1':  channel_num=XVI_CHANNEL_11; channel_index=11;  break;
									case '2':  channel_num=XVI_CHANNEL_12; channel_index=12;  break;
									case '3':  channel_num=XVI_CHANNEL_13; channel_index=13;  break;
									default : 
										display_error(resourcename,"Invalid XVI channel");
										exit(0); break;			
								} break;
							case '2': channel_num=XVI_CHANNEL_2; channel_index=2;  break;
							case '3': channel_num=XVI_CHANNEL_3; channel_index=3;  break;
							case '4': channel_num=XVI_CHANNEL_4; channel_index=4;  break;
							case '5': channel_num=XVI_CHANNEL_5; channel_index=5;  break;
							case '6': channel_num=XVI_CHANNEL_6; channel_index=6;  break;
							case '7': channel_num=XVI_CHANNEL_7; channel_index=7;  break;
							case '8': channel_num=XVI_CHANNEL_8; channel_index=8;  break;
							case '9': channel_num=XVI_CHANNEL_9; channel_index=9;  break;
							default : 
									display_error(resourcename,"Invalid XVI channel");
								    exit(0); break;		

							
							
							}
							Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = channel_index;							
							break;
#endif

						case HVS:
							switch(numptr[0])	
							{
							case '0': channel_num=HVS_FORCE_POS;	break;
							case '1': channel_num=HVS_OUT_1;		break;
							case '2': channel_num=HVS_OUT_2;		break;
							case '3': channel_num=HVS_OUT_3;		break;
							case '4': channel_num=HVS_OUT_4;		break;
							case '5': channel_num=HVS_OUT_5;		break;
							case '6': channel_num=HVS_OUT_6;		break;
							case '7': channel_num=HVS_OUT_7;		break;
							case '8': channel_num=HVS_OUT_8;		break;
							case 'C':	
							case '9': channel_num=HVS_OUT_COM;		break;	
							case 'R':	
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid HVS channel");exit(0); 
								}
								switch(numptr[0])	
								{
									case '1':  channel_num=HVS_REF_1; break;
									case '2':  channel_num=HVS_REF_2; break;
									default : 
										display_error(resourcename,"Invalid HVS channel");
										exit(0); break;			
								} break;
							case 'A': channel_num=HVS_REF_1;		break;	
							case 'B': channel_num=HVS_REF_2;		break;	
							default : 
									display_error(resourcename,"Invalid HVS channel");
								    exit(0); break;			
							} break;

						case OFS:	
							switch(numptr[0])	
							{
							case '0': channel_num=OFS_FORCE_POS;	break;
							case '1': channel_num=OFS_OUT_1;		break;
							case '2': channel_num=OFS_OUT_2;		break;
							case '3': channel_num=OFS_OUT_3;		break;
							case '4': channel_num=OFS_OUT_4;		break;
							case '5': channel_num=OFS_OUT_5;		break;
							case '6': channel_num=OFS_OUT_6;		break;
							case '7': channel_num=OFS_OUT_7;		break;
							case '8': channel_num=OFS_OUT_8;		break;
							case 'C':	
							case '9': channel_num=OFS_OUT_COM;		break;	
							case 'R':	
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid OFS channel");exit(0); 
								}
								switch(numptr[0])	
								{
									case '1':  channel_num=OFS_REF_1; break;
									case '2':  channel_num=OFS_REF_2; break;
									default : 
										display_error(resourcename,"Invalid OFS channel");
										exit(0); break;			
								} break;
							case 'A': channel_num=OFS_REF_1;		break;	
							case 'B': channel_num=OFS_REF_2;		break;		
							default : 
									display_error(resourcename,"Invalid OFS channel");
								    exit(0); break;			
							} break;

						case MVS:	
							switch(numptr[0])	
							{
							case '0': channel_num=MVS_FORCE_POS;	break;
							case '1': channel_num=MVS_OUT_1;		break;
							case '2': channel_num=MVS_OUT_2;		break;
							case '3': channel_num=MVS_OUT_3;		break;
							case '4': channel_num=MVS_OUT_4;		break;
							case '5': channel_num=MVS_OUT_5;		break;
							case '6': channel_num=MVS_OUT_6;		break;
							case '7': channel_num=MVS_OUT_7;		break;
							case '8': channel_num=MVS_OUT_8;		break;
							case 'C':	
							case '9': channel_num=MVS_OUT_COM;		break;	
							case 'R':	
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid MVS channel");exit(0); 
								}
								switch(numptr[0])	
								{
									case '1':  channel_num=MVS_REF_1; break;
									case '2':  channel_num=MVS_REF_2; break;
									default : 
										display_error(resourcename,"Invalid MVS channel");
										exit(0); break;			
								} break;							
							case 'A': channel_num=MVS_REF_1;		break;	
							case 'B': channel_num=MVS_REF_2;		break;	
							default : 
									display_error(resourcename,"Invalid MVS channel");
								    exit(0); break;			
							} break;

						case PVI:
							switch(numptr[0])	
							{
							case '1': channel_num = 0; break;
							case '2': channel_num = 1; break;
							case '3': channel_num = 2; break;
							case '4': channel_num = 3; break;
							case '5': channel_num = 4; break;
							default : 
									display_error(resourcename,"Invalid PVI channel");
								    exit(0); break;			
							} break;

						case MUX:
							mux_channel = numptr[0];
							numptr = strstr( numptr, "_" );
							if ((numptr == 0) || (numptr++ == 0)) 
							{	
								display_error(resourcename,"Invalid MUX channel");exit(0); 
							}
							switch(mux_channel)	
							{
							case '1': 
								if		(numptr[0] =='1') channel_num=MUX_1_1; 
								else if (numptr[0] =='2') channel_num=MUX_1_2; 
								else if (numptr[0] =='3') channel_num=MUX_1_3; 
								else if (numptr[0] =='4') channel_num=MUX_1_4; 
								else if (numptr[0] =='B') channel_num=MUX_1_BUS9; 
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '2': 
								if		(numptr[0] =='1') channel_num=MUX_2_1; 
								else if (numptr[0] =='2') channel_num=MUX_2_2; 
								else if (numptr[0] =='3') channel_num=MUX_2_3; 
								else if (numptr[0] =='4') channel_num=MUX_2_4; 
								else if (numptr[0] =='B') channel_num=MUX_2_BUS2; 
								else if (numptr[0] =='G') channel_num=MUX_2_GND; 
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '3': 
								if		(numptr[0] =='1') channel_num=MUX_3_1; 
								else if (numptr[0] =='2') channel_num=MUX_3_2; 
								else if (numptr[0] =='3') channel_num=MUX_3_3; 
								else if (numptr[0] =='4') channel_num=MUX_3_4; 
								else if (numptr[0] =='B') channel_num=MUX_3_BUS3; 
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '4': 
								if		(numptr[0] =='1') channel_num=MUX_4_1; 
								else if (numptr[0] =='2') channel_num=MUX_4_2; 
								else if (numptr[0] =='3') channel_num=MUX_4_3; 
								else if (numptr[0] =='4') channel_num=MUX_4_4; 
								else if (numptr[0] =='B') channel_num=MUX_4_BUS4; 
								else if (numptr[0] =='G') channel_num=MUX_4_GND; 
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '5': 
								if		(numptr[0] =='1') channel_num=MUX_5_1; 
								else if (numptr[0] =='2') channel_num=MUX_5_2; 
								else if (numptr[0] =='3') channel_num=MUX_5_3; 
								else if (numptr[0] =='4') channel_num=MUX_5_4; 
								else if (numptr[0] =='B') channel_num=MUX_5_BUS10;
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '6': 
								if		(numptr[0]=='1') channel_num=MUX_6_1; 
								else if (numptr[0]=='2') channel_num=MUX_6_2; 
								else if (numptr[0]=='3') channel_num=MUX_6_3; 
								else if (numptr[0]=='4') channel_num=MUX_6_4; 
								else if (numptr[0]=='B') channel_num=MUX_6_BUS6; 
								else if (numptr[0]=='G') channel_num=MUX_6_GND;  
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '7': 
								if		(numptr[0]=='1') channel_num=MUX_7_1; 
								else if (numptr[0]=='2') channel_num=MUX_7_2; 
								else if (numptr[0]=='3') channel_num=MUX_7_3; 
								else if (numptr[0]=='4') channel_num=MUX_7_4; 
								else if (numptr[0]=='B') channel_num=MUX_7_BUS7; 
								else if (numptr[0]=='G') channel_num=MUX_7_GND;  
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case '8': 
								if		(numptr[0]=='1') channel_num=MUX_8_1; 
								else if (numptr[0]=='2') channel_num=MUX_8_2; 
								else if (numptr[0]=='3') channel_num=MUX_8_3; 
								else if (numptr[0]=='4') channel_num=MUX_8_4; 
								else if (numptr[0]=='B') channel_num=MUX_8_BUS8; 
								else if (numptr[0]=='G') channel_num=MUX_8_GND; 
								else {
									display_error(resourcename,"Invalid MUX channel");exit(0);
								} break;

							case 'N': 
								if		(numptr[0]=='1') channel_num=MUX_NULL1; 
								else if (numptr[0]=='2') channel_num=MUX_NULL2; 
								else if (numptr[0]=='3') channel_num=MUX_NULL3; 
								else if (numptr[0]=='4') channel_num=MUX_NULL4; 
								else if (numptr[0]=='5') channel_num=MUX_NULL5; 
								else if (numptr[0]=='6') channel_num=MUX_NULL6; 
								else if (numptr[0]=='7') channel_num=MUX_NULL7; 
								else if (numptr[0]=='8') channel_num=MUX_NULL8; 
								else {
									display_error(resourcename,"Invalid MUX NULL channel");exit(0);
								} break;

							case 'B': 
								if		(numptr[0]=='1') channel_num=MUX_BANK_1_2; 
								else if (numptr[0]=='2') channel_num=MUX_BANK_2_3; 
								else if (numptr[0]=='3') channel_num=MUX_BANK_3_4; 
								else if (numptr[0]=='4') channel_num=MUX_BANK_4_5; 
								else if (numptr[0]=='5') channel_num=MUX_BANK_5_6; 
								else if (numptr[0]=='6') channel_num=MUX_BANK_6_7; 
								else if (numptr[0]=='7') channel_num=MUX_BANK_7_8; 
								else if (numptr[0]=='8') channel_num=MUX_BANK_8_1; 
								else {
									display_error(resourcename,"Invalid MUX BANK channel");exit(0);
								} break;

							default : 
									display_error(resourcename,"Invalid MUX channel");
								    exit(0); break;			
							} break;

						case CBT:
							cbt_channel_str = numptr;

							numptr = strstr( numptr, "c" );
							if (numptr != 0)
							{
								if (numptr++ == 0) 
								{	
									display_error(resourcename,"Invalid CBT channel");exit(0); 
								}
								numptr = strstr( numptr, "b" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid CBT channel");exit(0); 
								}
								channel_num = atoi(numptr);
								if (channel_num>=0&&channel_num<=7)
								{
									channel_unit = 0;
								}
								else if (channel_num>=10&&channel_num<=17)
								{
									channel_unit = 1;
								}
								else if (channel_num>=20&&channel_num<=27)
								{
									channel_unit = 2;
								}
								else if (channel_num>=30&&channel_num<=37)
								{
									channel_unit = 3;
								}
								else
								{
									display_error(resourcename,"Invalid CBT channel");exit(0); 		
								}
								strncpy (Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_str,cbt_channel_str,10);
							}
							else
							{
								numptr = cbt_channel_str;
								mux_channel = numptr[0];
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid CBT channel");exit(0); 
								}
								switch(mux_channel)	
								{
								case '1':
									channel_unit = 0;
									if		(numptr[0] =='1') channel_num=0; 
									else if (numptr[0] =='2') channel_num=1; 
									else if (numptr[0] =='3') channel_num=2; 
									else if (numptr[0] =='4') channel_num=3; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '2': 
									channel_unit = 0;
									if		(numptr[0] =='1') channel_num=4; 
									else if (numptr[0] =='2') channel_num=5; 
									else if (numptr[0] =='3') channel_num=6; 
									else if (numptr[0] =='4') channel_num=7; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '3': 
									channel_unit = 1;
									if		(numptr[0] =='1') channel_num=10; 
									else if (numptr[0] =='2') channel_num=11; 
									else if (numptr[0] =='3') channel_num=12; 
									else if (numptr[0] =='4') channel_num=13; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '4': 
									channel_unit = 1;
									if		(numptr[0] =='1') channel_num=14; 
									else if (numptr[0] =='2') channel_num=15; 
									else if (numptr[0] =='3') channel_num=16; 
									else if (numptr[0] =='4') channel_num=17; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '5': 
									channel_unit = 2;
									if		(numptr[0] =='1') channel_num=20; 
									else if (numptr[0] =='2') channel_num=21; 
									else if (numptr[0] =='3') channel_num=22; 
									else if (numptr[0] =='4') channel_num=23; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '6': 
									channel_unit = 2;
									if		(numptr[0]=='1') channel_num=24; 
									else if (numptr[0]=='2') channel_num=25; 
									else if (numptr[0]=='3') channel_num=26; 
									else if (numptr[0]=='4') channel_num=27; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '7': 
									channel_unit = 3;
									if		(numptr[0]=='1') channel_num=30; 
									else if (numptr[0]=='2') channel_num=31; 
									else if (numptr[0]=='3') channel_num=32; 
									else if (numptr[0]=='4') channel_num=33; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
									
								case '8': 
									channel_unit = 3;
									if		(numptr[0]=='1') channel_num=34; 
									else if (numptr[0]=='2') channel_num=35; 
									else if (numptr[0]=='3') channel_num=36; 
									else if (numptr[0]=='4') channel_num=37; 
									else {
										display_error(resourcename,"Invalid CBT channel");exit(0);
									} break;
																		
								default : 
									display_error(resourcename,"Invalid CBT channel");
									exit(0); break;	 		
							}
							sprintf(cbt_channel_str,"cb%i",channel_num);
							strncpy (Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_str,cbt_channel_str,10);

						} break;	
							
						case TMU:
							if (numptr[0] == 'E')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=TMU_EXT_DRV1;
								else if (atoi(numptr) == 2)
										channel_num=TMU_EXT_DRV2;
								else if (atoi(numptr) == 3)
										channel_num=TMU_EXT_DRV3;
								else
								{	
									display_error(resourcename,"Invalid TMU external driver");exit(0); 
								}
							} else
							if (numptr[0] == 'H')
							{

								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=TMU_HIZ_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=TMU_HIZ_DUT2;
								else if (atoi(numptr) == 3)
										channel_num=TMU_HIZ_DUT3;
								else if (atoi(numptr) == 4)
										channel_num=TMU_HIZ_DUT4;
								else
								{	
									display_error(resourcename,"Invalid TMU HIZ channel");exit(0); 
								}
							} else
							if (numptr[0] == 'A')
							{
						
						
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (numptr[0] == 'B')
										channel_num=TMU_CHAN_A_BUS;
								else if (atoi(numptr) == 1)
										channel_num=TMU_CHAN_A_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=TMU_CHAN_A_DUT2;
								else
								{	
									display_error(resourcename,"Invalid TMU channel A");exit(0); 
								}
							} else
							if (numptr[0] == 'B')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=TMU_CHAN_B_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=TMU_CHAN_B_DUT2;
								else
								{	
									display_error(resourcename,"Invalid TMU channel B");exit(0); 
								}
							} else
							if (numptr[0] == 'M')
							{
						
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (numptr[0] == 'B')
									channel_num=TMU_MEAS_BUS;
								else
								{	
									display_error(resourcename,"Invalid TMU meas bus");exit(0); 
								}
							} else
							if (numptr[0] == 'D')	
							{
				
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing TMU channel number");exit(0); 
								}
								if (numptr[0] == '1')
									channel_num=TMU_IO1;
								else if (numptr[0] == '2')
									channel_num=TMU_IO2;
								else
								{	
									display_error(resourcename,"Invalid TMU IO");exit(0); 
								}
							} else
							{	
								display_error(resourcename,"Invalid TMU resource");exit(0); 
							} break;

						case QTMU1:
							
							if (numptr[0] == '0')
							{
								channel_unit = QTMU1_UNIT_0;
							}
							if (numptr[0] == '1')
							{
								channel_unit = QTMU1_UNIT_1;
							}
							if (numptr[0] == '2')
							{
								channel_unit = QTMU1_UNIT_2;
							}
							if (numptr[0] == '3')
							{
								channel_unit = QTMU1_UNIT_3;
							}
							numptr = strstr( numptr, "_" );
							if ((numptr == 0) || (numptr++ == 0)) 
							{	
								display_error(resourcename,"Invalid or missing channel number");exit(0); 
							}

							if (numptr[0] == 'E')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=QTMU1_EXT_DRV1;
								else if (atoi(numptr) == 2)
										channel_num=QTMU1_EXT_DRV2;
								else if (atoi(numptr) == 3)
										channel_num=QTMU1_EXT_DRV3;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 external driver");exit(0); 
								}
							} else
							if (numptr[0] == 'H')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=QTMU1_HIZ_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=QTMU1_HIZ_DUT2;
								else if (atoi(numptr) == 3)
										channel_num=QTMU1_HIZ_DUT3;
								else if (atoi(numptr) == 4)
										channel_num=QTMU1_HIZ_DUT4;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 HIZ channel");exit(0); 
								}
							} else
							if (numptr[0] == 'A')
							{
								
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (numptr[0] == 'B')
										channel_num=QTMU1_CHAN_A_BUS;
								else if (atoi(numptr) == 1)
										channel_num=QTMU1_CHAN_A_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=QTMU1_CHAN_A_DUT2;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 channel A");exit(0); 
								}
							} else
							if (numptr[0] == 'B')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=QTMU1_CHAN_B_DUT1;
								else if (atoi(numptr) == 2)
										channel_num=QTMU1_CHAN_B_DUT2;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 channel B");exit(0); 
								}
							} else
							if (numptr[0] == 'M')
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (numptr[0] == 'B')
									channel_num=QTMU1_MEAS_BUS;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 meas bus");exit(0); 
								}
							} else
							if (numptr[0] == 'D')	
							{
								
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing QTMU1 channel number");exit(0); 
								}
								if (numptr[0] == '1')
									channel_num=QTMU1_IO1;
								else if (numptr[0] == '2')
									channel_num=QTMU1_IO2;
								else
								{	
									display_error(resourcename,"Invalid QTMU1 IO");exit(0); 
								}
							} else
							{	
								display_error(resourcename,"Invalid QTMU1 resource");exit(0); 
							} break;

						case LZB:
							lzb_channel_str[0] = numptr[0];
							lzb_channel_str[1] = numptr[1];
							numptr = strstr( numptr, "_" );
							if ((numptr == 0) || (numptr++ == 0)) 
							{	
								display_error(resourcename,"Missing LZB channel");exit(0); 
							}
							
							Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = UNUSED_LZB_MUX_PIN;

							switch(lzb_channel_str[0])	
							{
							case 'O':		
								channel_num = atoi(numptr);
								if ((channel_num >= 1) && (channel_num <= 28))
									channel_num = channel_num - 1 + LZB_MUX_OUT_1; 
								else {
									display_error(resourcename,"Invalid LZB OUT channel");exit(0);
								} break;

							case 'G':		
								channel_num = atoi(numptr);
								if ((channel_num >= 1) && (channel_num <= 28))
									channel_num = channel_num - 1 + LZB_MUX_GND_1; 
								else {
									display_error(resourcename,"Invalid LZB GND channel");exit(0);
								} break;

							case 'C': 
								if		(numptr[0] =='O') channel_num=LZB_CONN_OUT; 
								else if (numptr[0] =='G') channel_num=LZB_CONN_GND; 
								else if (numptr[0] =='C') channel_num=LZB_CONN_CLAMP; 
								else {
									display_error(resourcename,"Invalid LZB CONN channel");exit(0);
								} break;

							case 'R': 
								if		(numptr[0] =='1') channel_num=LZB_RANGE_1; 
								else if (numptr[0] =='2') channel_num=LZB_RANGE_2; 
								else {
									display_error(resourcename,"Invalid LZB RANGE channel");exit(0);
								} break;

							case 'X': 
								channel_num = UNUSED_LZB_MUX_PIN;	
								if		((atoi(numptr) >= 1) && (atoi(numptr) <= 28))
								{			
									Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = atoi(numptr) - 1 + LZB_MUX_GND_1; 
								}
								else
								{
									display_error(resourcename,"Invalid LZB MUX channel");exit(0); 
								}
								break;			

							default : 
								channel_num = atoi(lzb_channel_str);	
								if ((channel_num >= 1) && (channel_num <= 28)) {
									if (sitenum == 1) {	
		
										if (lzb_zener_list == NULL) {   
											for (j=0;j<MAX_SITES;j++)	
												lzb_fuse_list[j] = NULL;
										}
										attach_element(&lzb_zener_list,pinnumber);	
									}

									channel_num = channel_num - 1 + LZB_MUX_OUT_1; 
									
									if (numptr[0] == 'X') 
										Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = UNUSED_LZB_MUX_PIN;
									else {
										if ((atoi(numptr) >= 1) && (atoi(numptr) <= 28)){			
											Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 =
														atoi(numptr) - 1 + LZB_MUX_GND_1; 
										} else {
											display_error(resourcename,"Invalid LZB MUX channel");
										    exit(0); break;			
										}
									}
								} else
								{
									display_error(resourcename,"Invalid LZB MUX channel");
								    exit(0); break;			
								}
							} break;

						case OAL:	
								OAL_Card_Used[Pin_Type_Used[pin_inserted-1][sitenum-1].Slot-1].OAL_in_pin_map=true;	
								switch(numptr[0])	
								{
									case '0': channel_num=OAL_CHANNEL_0; break;
									case '1': channel_num=OAL_CHANNEL_1; break;
									default : 
										display_error(resourcename,"Invalid OAL channel");
										exit(0); break;			
								};

								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid OAL channel");exit(0); 
								}
								switch(numptr[0])
								{
									case 'O': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_OUT; break;
									case 'P': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_IN_POS; break;
									case 'N': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_IN_NEG; break;
									case 'R': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_RMS;
										if(channel_num==OAL_CHANNEL_0)
											channel_num=OUT_TO_RMS;
										else
											channel_num=CH1_RMS_METER;
										break;
									case 'L': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_LOAD;
										channel_num=EXT_LOAD_CONN; 
										break;
									case 'X': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_LOAD; 
										channel_num=LOAD_REF_EXT; 
										break;
									case 'E': 
										numptr = strstr( numptr, "_" );
										if ((numptr == 0) || (numptr++ == 0)) 
										{	
											display_error(resourcename,"Invalid OAL channel");exit(0); 
										}
												
										switch(numptr[0])
										{
										case '1':
											Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_EXT_DRV1; 
											if(channel_num==OAL_CHANNEL_0)
												channel_num=EXT_RLY_DRV;
											else
												channel_num=CH1_EXT_DRV;
											break;
										case '2':
											Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_EXT_DRV2; 
											if(channel_num==OAL_CHANNEL_0)
												channel_num=DRV_1;
											else
												channel_num=DRV_2;
											break;
										default:
											display_error(resourcename,"Invalid OAL channel");
											exit(0);
										}

										break;
									default:
										display_error(resourcename,"Invalid OAL channel");
										exit(0);
								}
							break;

					    case QAL:	
								QAL_Card_Used[Pin_Type_Used[pin_inserted-1][sitenum-1].Slot-1].QAL_in_pin_map=true;	
								switch(numptr[0])	
								{
									case '0': channel_num=QAL_CHANNEL_0; break;
									case '1': channel_num=QAL_CHANNEL_1; break;
									case '2': channel_num=QAL_CHANNEL_2; break;
									case '3': channel_num=QAL_CHANNEL_3; break;
									default : 
										display_error(resourcename,"Invalid QAL channel");
										exit(0); break;			
								};

								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid QAL channel");exit(0); 
								}
								switch(numptr[0])
								{
									case 'O': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_OUT; break;
									case 'P': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_IN_POS; break;
									case 'N': Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_IN_NEG; break;
									case 'R': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_RMS;








										break;
									case 'L': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_LOAD;
										channel_num=QAL_EXT_LOAD_CONN; 
										break;
									case 'X': 
										Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_LOAD; 
										channel_num=QAL_LOAD_REF_EXT; 
										break;
									case 'E': 
										numptr = strstr( numptr, "_" );
										if ((numptr == 0) || (numptr++ == 0)) 
										{	
											display_error(resourcename,"Invalid QAL channel");exit(0); 
										}
												
										switch(numptr[0])
										{
										case '1':
											Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_EXT_DRV1; 
											if(channel_num==QAL_CHANNEL_0)
												channel_num=QAL_EXT_RLY_DRV;


											break;
										case '2':
											Pin_Type_Used[pin_inserted-1][sitenum-1].PinClass = PIN_EXT_DRV2; 
											if(channel_num==QAL_CHANNEL_1)
												channel_num=QAL_DRV_1;
											else

											break;














										default:
											display_error(resourcename,"Invalid QAL channel");
											exit(0);
										}

										break;
									default:
										display_error(resourcename,"Invalid QAL channel");
										exit(0);
								}
							break;

						case ACS:
							if (numptr[0] == 'O') channel_num=D_SIG_OUT; else
							if (numptr[0] == 'C') channel_num=D_CLK; else		
							if (numptr[0] == 'R')								
							{
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing ACS channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=D_RMS_CH1;
								else if (atoi(numptr) == 2)
										channel_num=D_RMS_CH2;
								else if (atoi(numptr) == 3)
										channel_num=D_RMS_CH3;
								else if (atoi(numptr) == 4)
										channel_num=D_RMS_CH4;
								else
								{	
									display_error(resourcename,"Invalid ACS RMS channel");exit(0); 
								}
							} else
							if (numptr[0] == 'D')								
							{
								numptr = strstr( numptr, "_" );
								if ((numptr == 0) || (numptr++ == 0)) 
								{	
									display_error(resourcename,"Invalid or missing ACS channel number");exit(0); 
								}
								if (atoi(numptr) == 1)
										channel_num=D_R_BIT1;
								else if (atoi(numptr) == 2)
										channel_num=D_R_BIT2;
								else if (atoi(numptr) == 3)
										channel_num=D_R_BIT3;
								else
								{	
									display_error(resourcename,"Invalid ACS sync bit");exit(0); 
								}
							} else
							{
								display_error(resourcename,"Invalid ACS channel");
								exit(0);			
							}
						break;

						case DDD:	
							switch(numptr[0])	
							{
							case '1': channel_num=1; break;
							case '2': channel_num=2; break;
							case '3': channel_num=3; break;
							case '4': channel_num=4; break;
							case '5': channel_num=5; break;
							case '6': channel_num=6; break;
							case '7': channel_num=7; break;
							case '8': channel_num=8; break;
							default : 
									display_error(resourcename,"Invalid DDD channel");
								    exit(0);
							}
						break;

						case OV2:
							switch(numptr[0])	
							{
							case '0': channel_num=OV2_CHANNEL_0; channel_id=OV2_CH_0;break;
							case '1': channel_num=OV2_CHANNEL_1; channel_id=OV2_CH_1;break;
							case '2': channel_num=OV2_CHANNEL_2; channel_id=OV2_CH_2;break;
							case '3': channel_num=OV2_CHANNEL_3; channel_id=OV2_CH_3;break;
							case '4': channel_num=OV2_CHANNEL_4; channel_id=OV2_CH_4;break;
							case '5': channel_num=OV2_CHANNEL_5; channel_id=OV2_CH_5;break;
							case '6': channel_num=OV2_CHANNEL_6; channel_id=OV2_CH_6;break;
							case '7': channel_num=OV2_CHANNEL_7; channel_id=OV2_CH_7;break;
							default : 
									display_error(resourcename,"Invalid OV2 channel");
								    exit(0); break;			
							} 
							Pin_Type_Used[pin_inserted-1][sitenum-1].Channel_2 = channel_id;							
							break;
					} 

					Pin_Type_Used[pin_inserted-1][sitenum-1].Unit=channel_unit;
					Pin_Type_Used[pin_inserted-1][sitenum-1].Channel=channel_num;

					sitenum++;
				} 
				token1 = strtok( NULL, seps );       
			}
#ifdef DEBUG_MULTISITE
			printf( "\n");
#endif
		}
#ifdef DEBUG_MULTISITE
		else
			printf( "IGNORE: %s (%d)\n", token1, strlen(token1) );
#endif
	}
	fclose(pinmapfp);


	List_all_group[group_inserted+1].Pins_belong_to_Group = NULL;



	int	slot;
	int brd_type;

	for (slot=0; slot<21 ; slot++)
	{
		brd_type= GetDetectedBoardType (slot);
		
		if(brd_type!=0x7f)
		{
			switch (brd_type)
			{
#ifndef	LegacyXerxes
			case XVI_CARD:	XVI_Card_Used[slot].card_ptr	= &xvi_cards[board_ptr[slot]]; break;
#endif
			case ACS_CARD:	ACS_Card_Used[slot].card_ptr	= &acs_cards[board_ptr[slot]]; break;
			case DDD_CARD:	DDD_Card_Used[slot].card_ptr	= &ddd_cards[board_ptr[slot]]; break;
			case DVI_CARD:	DVI_Card_Used[slot].card_ptr	= &dvi_cards[board_ptr[slot]]; break;
			case OAL_CARD:	OAL_Card_Used[slot].card_ptr	= &oal_cards[board_ptr[slot]]; break;
			case QAL_CARD:	QAL_Card_Used[slot].card_ptr	= &qal_cards[board_ptr[slot]]; break;
			case OV2_CARD:	OV2_Card_Used[slot].card_ptr	= &ov2_cards[board_ptr[slot]]; break;
			case HVS_CARD:	HVS_Card_Used[slot].card_ptr	= &hvs_cards[board_ptr[slot]]; break;
			case OFS_CARD:	OFS_Card_Used[slot].card_ptr	= &ofs_cards[board_ptr[slot]]; break;
			case PV3_CARD:	PVI_Card_Used[slot].card_ptr	= &pv3_cards[board_ptr[slot]]; break;
			}
		}
	}
}




void 	system_status(short pin_group, char *notes,bool append_overwrite)
	{
	if (debugger_on_flag)
	{
		FILE *file_debug_relay;
		FILE *file_debug_dc;

		short Source_type;
		char dev_num_string[10],file_name[100];
		bool display_allpins = false;


		DYN_GROUP_LIST *pin_ptr;
		short pin;
		short pin_sel;
		char append_overwrite_char[3];
		int site,int_serial_num;
		STRING dev_num; 

		GetSerialNum(dev_num);  
		strcpy(dev_num_string, dev_num); 
		int_serial_num=atoi(dev_num_string);

	
		strcpy(file_name,file_path);	
		strcat(file_name,"Debug_Info_DC.txt");

		if (append_overwrite == true)		
			strcpy(append_overwrite_char,"a");	
		else
			strcpy(append_overwrite_char,"w");

		if ((file_debug_dc = fopen(file_name,append_overwrite_char))==NULL)
		{
			strcat(file_name,": cannot open file\n");
			mytext.text_in_box(40,10,file_name);
			exit(0); 
		}

		strcpy(file_name,file_path);	
		strcat(file_name,"Debug_Info_Relay.txt");

		if ((file_debug_relay = fopen(file_name,append_overwrite_char))==NULL)
		{
			strcat(file_name,": cannot open file\n");
			mytext.text_in_box(40,10,file_name);
			exit(0); 
		}

		if (int_serial_num_old!=int_serial_num)
			{
			fprintf(file_debug_dc,"\nDevice Num= %s       **************************************************************************************************\n",dev_num_string);
			fprintf(file_debug_dc,"PinName    Site   Channel      Con_F   Con_S   V_SetUp      V_Rng V_Measure    I_SetUp      I_Rng   I_Measure    Supply  ADC\n"); 
			fprintf(file_debug_dc,"*** %s \n",notes);

			fprintf(file_debug_relay,"\nDevice Num= %s       ************\n",dev_num_string);
			fprintf(file_debug_relay,"PinName         Site   Channel         Relay\n");
			fprintf(file_debug_relay,"*** %s \n",notes);

			int_serial_num_old=int_serial_num;

			printf("\nDevice Num= %s       **************************************************************************************************\n",dev_num_string);
			printf("PinName    Site   Channel      Con_F   Con_S   V_SetUp      V_Rng V_Measure    I_SetUp      I_Rng   I_Measure    Supply  ADC\n"); 
			printf("*** %s \n",notes);

			}
		else
		{
			fprintf(file_debug_dc,"\n*** %s \n",notes);
    		fprintf(file_debug_relay,"\n*** %s \n",notes);
			printf("\n*** %s \n",notes);

		}

		


		pin_ptr = group_selection(pin_group); 

		do
		{
			
			pin = pin_ptr->grouppin;

			for( site = 0; site < max_sites ; site++ )
			{					
				if(active_site[site])
				{
					Source_type=pin_selection_(pin,site,&pin_sel);

					switch(Source_type)
					{ 
						case NONE:	
						break;

						case DVI:
							dvi_setup(pin_sel,site,file_debug_dc,file_debug_relay,notes);
						break;

						case OVI:
						case OVI_S:
							ovi_setup(pin_sel,site,file_debug_dc,notes);
							break;
							
#ifndef LegacyXerxes
						case XVI:	
							xvi_setup(pin_sel,site,file_debug_dc,notes);
							break;
#endif

						case MUX:
							mux_setup(pin_sel,site,file_debug_relay,notes);
							break;

						case CBT:
							cbt_setup(pin_sel,site,file_debug_relay,notes);
							break;
							
						case TMU:
							tmu_setup(pin_sel,site,file_debug_relay,notes);
							break;

						case QTMU1:
							qtmu1_setup(pin_sel,site,file_debug_relay,notes);
							break;
							
						case CBIT:
							cbit_setup(pin_sel,site,file_debug_relay,notes);
							break;

						case HVS:
							hvs_setup(pin_sel,site,file_debug_dc,notes);
							break;

						case OFS:
							ofs_setup(pin_sel,site,file_debug_dc,notes);
							break;

						case MVS:
							mvs_setup(pin_sel,site,file_debug_dc,notes);
							break;

						case PVI:
							pvi_setup(pin_sel,site,file_debug_dc,notes);
							break;
						
						case OAL:
							oal_setup(pin_sel,site,file_debug_dc,file_debug_relay,notes);
							break;

						case QAL:
							qal_setup(pin_sel,site,file_debug_dc,file_debug_relay,notes);
							break;

						case ACS:
							acs_setup(pin_sel,site,file_debug_relay,notes);
							break;

						case LZB:
							lzb_setup(pin_sel,site,file_debug_relay,notes);
							break;

						case OV2:
							ov2_setup(pin_sel,site,file_debug_dc,notes);
							break;
					}
				}
			} 

		pin_ptr = pin_ptr->nextptr;

		}  while (pin_ptr != NULL);	

		fclose(file_debug_dc);
		fclose(file_debug_relay);

	}

}


void system_status_on(void)
{
	debugger_on_flag = true;
}


void system_status_off(void)
{
	debugger_on_flag = false;
}


bool debugger_on(void)		   
{
	return (debugger_on_flag);
}



void set_max_sites(unsigned short max_site_driver, unsigned short max_site_prg)
{
	char text_str[1000];








	if (max_site_driver > MAX_SITES) {
		sprintf(text_str,"Your driver uses to much sites (%d) for the multisite library (%d)\n",max_site_driver,MAX_SITES);
		mytext.text_in_box(40,10,text_str);
		exit(0);
	}



	if(max_site_driver<pinmap_max_sites)
		CSC_LAST_SITE=max_sites = max_site_driver;
	else
		CSC_LAST_SITE=max_sites = pinmap_max_sites;



	if (max_site_prg == 1)
		continue_on_fail_flag = true;
}




void get_active_sites(unsigned char *active_sites, unsigned short max_site_prg)
{
	unsigned short i;
	char text_str[1000];
	bool found_active_site = false;	
	for(i=0; i<max_sites; i++)
	{
		device_passed[i] = true;
		active_site[i] = active_sites[i];
		if (active_site[i])
		{
			found_active_site = true;
			if (i > max_site_prg-1)
			{
				sprintf(text_str,"!!! Your driver wants to activate site %d !!!\nYour application is ready for %d sites only.\n",i+1,max_site_prg);
				mytext.text_in_box(40,10,text_str);
				exit(0);
			}
		}

		store_active_site[i] = active_sites[i];
	}
	if ((!found_active_site) && (!EOW))
	{
		sprintf(text_str,"!!! Your driver activated NO site!!!\nPlease check the selected robot driver\n");
		mytext.text_in_box(40,10,text_str);
		exit(0);
	}
}




void reset_active_sites()
{
	unsigned int i;
	for(i=0; i<max_sites; i++)
		active_site[i] = store_active_site[i];
}



void store_site_status(sint usr_active_site)
{
	unsigned int i;
	for(i=0; i<max_sites; i++)

		if(usr_active_site!=NULL)
			usr_active_site[i] = active_site[i];
		else

			current_active_site[i] = active_site[i];
}



void restore_site_status(sint usr_active_site)	
{
	unsigned int i;
	for(i=0; i<max_sites; i++)

		if(usr_active_site!=NULL)
			active_site[i] = usr_active_site[i];
		else

			active_site[i] = current_active_site[i];
}


void activate_one_site(int site)
{
	
	for (int i=0;i < max_sites;i++)
		if (i != site)
			active_site[i] = false;
}



void relay_setup(short pin_sel,int site,FILE *file_debug,BOOL status_relay,char *rly_name="")	
{
	char	status_relay_s[20],Pin_name_s[15];

	if (status_relay==TRUE)
			strcpy(status_relay_s, "OPEN ");
	else
			strcpy(status_relay_s, "CLOSE");
	if (rly_name[0]!=0)	
	{
		strcat(status_relay_s," ");
		strcat(status_relay_s,rly_name);
	}

	strncpy (Pin_name_s,Pin_Type_Used[pin_sel][site].Pin_Name,13);
	Pin_name_s[13]='\0';

	
	fprintf(file_debug,"%-15.15s S%-5d %-15.15s %-25.25s\n"
			,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name,status_relay_s); 
	printf("%-15.15s S%-5d %-15.15s %-25.25s\n"
			,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name,status_relay_s); 

}



void vi_setup(short pin_sel,int site,FILE *file_debug,char *status_relay_f_s,char *status_relay_s_s,
			float voltage_value,char *range_v_s, float real_voltage,
			float current_value,char *range_i_s, float real_current,
			char *status_board, char mode_fl, BYTE measure_channel)
{
	char Pin_name_s[10];

	strncpy (Pin_name_s,Pin_Type_Used[pin_sel][site].Pin_Name,9);
	Pin_name_s[9]='\0';

	fprintf(file_debug,"%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
			,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
			,status_relay_f_s,status_relay_s_s
			,voltage_value,range_v_s,real_voltage
			,current_value,range_i_s,real_current
			,status_board,mode_fl,measure_channel
); 

	printf("%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
			,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
			,status_relay_f_s,status_relay_s_s
			,voltage_value,range_v_s,real_voltage
			,current_value,range_i_s,real_current
			,status_board,mode_fl,measure_channel); 
}



void dvi_setup(short pin_sel,int site,FILE *file_debug_dc, FILE *file_debug_relay , char *notes)
	{

	int h;
	BOOL		status_relay_s,status_relay_f,status_relay_drv;
	STRING  polarity_v,range_v,compensation_v, range_i,i_half_i;
	char		range_v_s[15],range_i_s[15];
	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;
	BYTE    measure_channel;
	char    measure_mode_channel; 


	char  mode_fl,measure_mode_s[30];	




	
	if (DVI_Used[site].DVI_channel==DVI_CHANNEL_0)
	{
		status_relay_f= DVI_Used[site].DVI_slot->relay_is_open (CONN_FORCE0);
		status_relay_s= DVI_Used[site].DVI_slot->relay_is_open (CONN_SENSE0);
		status_relay_drv=-1;
	}
	else if (DVI_Used[site].DVI_channel==DVI_CHANNEL_1)
	{
		status_relay_f= DVI_Used[site].DVI_slot->relay_is_open (CONN_FORCE1);
		status_relay_s= DVI_Used[site].DVI_slot->relay_is_open (CONN_SENSE1);
		status_relay_drv=-1;
	}
				
	else if (DVI_Used[site].DVI_channel==DVI_EXT_DRV1)
	{
		status_relay_drv= DVI_Used[site].DVI_slot->relay_is_open (DVI_EXT_DRV1);
	}
	else if (DVI_Used[site].DVI_channel==DVI_EXT_DRV2)
	{
		status_relay_drv= DVI_Used[site].DVI_slot->relay_is_open (DVI_EXT_DRV2);
	}
	else
	{
			mytext.text_in_box(40,10,"debugger: wrong dvi channel \n");
			exit(0);
	}
				
	if (status_relay_drv!=-1)
	{
		relay_setup(pin_sel,site,file_debug_relay,status_relay_drv);
	}
	else
	{
		if (status_relay_s==TRUE)
			strcpy(status_relay_s_s, "OPEN ");
		else
			strcpy(status_relay_s_s, "CLOSE");
					
		if (status_relay_f==TRUE)
			strcpy(status_relay_f_s, "OPEN ");
		else
			strcpy(status_relay_f_s, "CLOSE");
	
		
		DVI_Used[site].DVI_slot->get_voltage_range (DVI_Used[site].DVI_channel, polarity_v, range_v, compensation_v);
		voltage_value= DVI_Used[site].DVI_slot->get_voltage_setting (DVI_Used[site].DVI_channel);
		strcpy(range_v_s, range_v); 
					
		DVI_Used[site].DVI_slot->get_current_range (DVI_Used[site].DVI_channel, range_i, i_half_i);
		current_value= DVI_Used[site].DVI_slot->get_current_setting (DVI_Used[site].DVI_channel);
		strcpy(range_i_s, range_i); 
		

		if (!strncmp(range_i_s,"MICRO_2_AMP",10))
			strcpy(range_i_s, "RANGE_2_UA"); 
		else if (!strncmp(range_i_s,"MICRO_20_AMP",10))
			strcpy(range_i_s, "RANGE_20_UA"); 
		else if (!strncmp(range_i_s,"MICRO_200_AMP",10))
			strcpy(range_i_s, "RANGE_200_UA"); 
		else if (!strncmp(range_i_s,"MILLI_2_AMP",10))
			strcpy(range_i_s, "RANGE_2_MA"); 
		else if (!strncmp(range_i_s,"MILLI_20_AMP",10))
			strcpy(range_i_s, "RANGE_20_MA"); 
		else if (!strncmp(range_i_s,"MILLI_200_AMP",10))
			strcpy(range_i_s, "RANGE_200_MA"); 
		else if (!strncmp(range_i_s,"AMP_2",4))
			strcpy(range_i_s, "RANGE_2_A"); 
		else if (!strncmp(range_i_s,"AMP_20",5))
			strcpy(range_i_s, "RANGE_20_A"); 
		
		for (h=0;h<15;h++)
			range_i_s[h]=range_i_s[h+6];
		for (h=0;h<15;h++)
			range_v_s[h]=range_v_s[h+6];
					
		
		
		measure_mode=DVI_Used[site].DVI_slot->get_meas_mode (measure_channel, measure_mode_channel);
		strcpy(measure_mode_s, measure_mode);
		mode_fl=measure_mode_s[12];
					
		DVI_Used[site].DVI_slot->save_measure_status();
		DVI_Used[site].DVI_slot->set_meas_mode(DVI_Used[site].DVI_channel,DVI_MEASURE_VOLTAGE);
		wait.delay_10_us(20);
		real_voltage=DVI_Used[site].DVI_slot->measure();
					
					
		DVI_Used[site].DVI_slot->set_meas_mode(DVI_Used[site].DVI_channel,DVI_MEASURE_CURRENT);
		wait.delay_10_us(20);
		real_current=DVI_Used[site].DVI_slot->measure();
					
		if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_s==FALSE)&& (status_relay_f==FALSE))
			strcpy(status_board, "V_MODE");
		else if (fabs(real_current)>(current_value*0.98-0.1) && fabs(current_value)<(current_value*1.02+0.1) && (status_relay_s==FALSE) && (status_relay_f==FALSE))
		{
			if ((real_current>0.0f) )
				strcpy(status_board, "I_SRC");
			else
				strcpy(status_board, "I_SINK");
		}
		else
			strcpy(status_board, "UNDEF");
					
		DVI_Used[site].DVI_slot->restore_measure_status();
		vi_setup(pin_sel,site,file_debug_dc,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,status_board,mode_fl,measure_channel);
		}
	}




void tmu_setup(short pin_sel,int site,FILE *file_debug, char *notes)
{
	BOOL	status_relay;

	status_relay= TMU_Used[site].TMU_slot->relay_is_open(TMU_Used[site].TMU_channel);
	relay_setup(pin_sel,site,file_debug,status_relay);
}

void qtmu1_setup(short pin_sel,int site,FILE *file_debug, char *notes)
{
	BOOL	status_relay;

	status_relay= QTMU1_Used[site].QTMU1_slot->relay_is_open((QTMU1_UNIT_ID_e)QTMU1_Used[site].QTMU1_unit,QTMU1_Used[site].QTMU1_channel);
	relay_setup(pin_sel,site,file_debug,status_relay);
}



void mux_setup(short pin_sel,int site,FILE *file_debug, char *notes)
{
	BOOL	status_relay;

	status_relay= MUX_Used[site].MUX_slot->is_relay_open(MUX_Used[site].MUX_channel);
	relay_setup(pin_sel,site,file_debug,status_relay);
}

void cbt_setup(short pin_sel,int site,FILE *file_debug, char *notes)
{
	unsigned int status_relay;

	CBT_Used[site].CBT_slot->get_driver_state(CBT_Used[site].CBT_channel_str,&status_relay);
	relay_setup(pin_sel,site,file_debug,status_relay);
}



void ovi_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL		status_relay;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];

	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;

	BYTE    measure_active_channel;
	BYTE    measure_active_meas_mode;

	char  mode_fl;	

		
		if (OVI_Used[site].OVI_channel==OVI_CHANNEL_0)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_0);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_1)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_1);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_2)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_2);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_3)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_3);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_4)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_4);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_5)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_5);
		else if (OVI_Used[site].OVI_channel==OVI_CHANNEL_6)
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_6);
		else 
			status_relay= OVI_Used[site].OVI_slot->is_connected (OVI_CHANNEL_7);
		if (status_relay==FALSE)
		{
			strcpy(status_relay_f_s, "OPEN ");
			strcpy(status_relay_s_s, "OPEN ");
		}
		else
		{
			strcpy(status_relay_f_s, "CLOSE");
			strcpy(status_relay_s_s, "CLOSE");
		}

		

		range_v_str=OVI_Used[site].OVI_slot->get_voltage_range (OVI_Used[site].OVI_channel, range_v);
		voltage_value= OVI_Used[site].OVI_slot->get_voltage_setting (OVI_Used[site].OVI_channel);
		strcpy(range_v_s, range_v_str); 

		range_i_str=OVI_Used[site].OVI_slot->get_current_range (OVI_Used[site].OVI_channel, range_i);
		current_value= OVI_Used[site].OVI_slot->get_current_setting (OVI_Used[site].OVI_channel);
		strcpy(range_i_s, range_i_str); 
		for (h=0;h<15;h++)
			range_i_s[h]=range_i_s[h+6];
		for (h=0;h<15;h++)
			range_v_s[h]=range_v_s[h+6];

		

		measure_active_channel	  =OVI_Used[site].OVI_slot->m_active_channel;
		measure_active_meas_mode	=OVI_Used[site].OVI_slot->m_active_meas_mode;
				
		if (measure_active_meas_mode==OVI_MEASURE_VOLTAGE)
			mode_fl='V';
		else 
			mode_fl='C';

		OVI_Used[site].OVI_slot->save_measure_status();

		OVI_Used[site].OVI_slot->set_meas_mode(OVI_Used[site].OVI_channel,OVI_MEASURE_VOLTAGE);
		wait.delay_10_us(20);
		real_voltage=OVI_Used[site].OVI_slot->measure();


		OVI_Used[site].OVI_slot->set_meas_mode(OVI_Used[site].OVI_channel,OVI_MEASURE_CURRENT);
		wait.delay_10_us(20);
		real_current=OVI_Used[site].OVI_slot->measure();


		if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay==TRUE))
			strcpy(status_board, "V_MODE");
		else if (fabs(real_current)>(current_value*0.98) && fabs(current_value)<(current_value*1.02) && (status_relay==TRUE))
		{
			if ((real_current>0.0f) )
				strcpy(status_board, "I_SRC");
			else
				strcpy(status_board, "I_SNK");
		}
		else
			strcpy(status_board, "UNDEF");
				
		OVI_Used[site].OVI_slot->restore_measure_status();
		vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
			status_board,mode_fl,measure_active_channel);
	}

void ov2_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL	status_relay_s,status_relay_f,status_relay_drv;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];
	
	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	
	unsigned short measure_mode;
	
	BYTE    measure_active_channel;
	BYTE    measure_active_meas_mode;
	
	char  mode_fl;	
	
	
	
	if (OV2_Used[site].OV2_channel<=OV2_CHANNEL_7)
	{
		status_relay_f= OV2_Used[site].OV2_slot->relay_is_open (OV2_CONN_FORCE0 + OV2_Used[site].OV2_channel);
		status_relay_s= OV2_Used[site].OV2_slot->relay_is_open (OV2_CONN_SENSE0 + OV2_Used[site].OV2_channel);
	}
	else
	{
		mytext.text_in_box(40,10,"debugger: wrong ov2 channel \n");
		exit(0);
	}
	if (status_relay_s==TRUE)
		strcpy(status_relay_s_s, "OPEN ");
	else
		strcpy(status_relay_s_s, "CLOSE");
	
	if (status_relay_f==TRUE)
		strcpy(status_relay_f_s, "OPEN ");
	else
		strcpy(status_relay_f_s, "CLOSE");
	
	
	
	range_v_str=OV2_Used[site].OV2_slot->get_voltage_range (OV2_Used[site].OV2_channel, range_v);
	voltage_value= OV2_Used[site].OV2_slot->get_voltage_setting (OV2_Used[site].OV2_channel);
	strcpy(range_v_s, range_v_str); 
	
	range_i_str=OV2_Used[site].OV2_slot->get_current_range (OV2_Used[site].OV2_channel, range_i);
	current_value= OV2_Used[site].OV2_slot->get_current_setting (OV2_Used[site].OV2_channel);
	strcpy(range_i_s, range_i_str); 
	for (h=0;h<15;h++)
		range_i_s[h]=range_i_s[h+6];
	for (h=0;h<15;h++)
		range_v_s[h]=range_v_s[h+6];
	
	
	
	measure_active_channel	  =OV2_Used[site].OV2_slot->card.meas_channel[OV2_MEASURE_0];
	measure_active_meas_mode	=OV2_Used[site].OV2_slot->card.meas_mode[OV2_MEASURE_0];
				
	switch(measure_mode)
	{
	case 	OV2_MEASURE_VOLTAGE:mode_fl='V'; break;
	case 	OV2_MEASURE_DIFF:	mode_fl='D'; break;
	case 	OV2_MEASURE_CURRENT:mode_fl='C'; break;
	case 	OV2_MEASURE_AC:	    mode_fl='A'; break;
	default:					mode_fl='U';
	}
	
	OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_VOLTAGE);
	wait.delay_10_us(20);
	real_voltage=OV2_Used[site].OV2_slot->measure();
	
	OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_CURRENT);
	wait.delay_10_us(20);
	real_current=OV2_Used[site].OV2_slot->measure();
				
	switch(mode_fl)
	{
	case 'V':
		OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_VOLTAGE);
		break;
	case 'D':
		OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_DIFF);
		break;
	case 'C':
		OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_CURRENT);
		break;
	case 'A':
		OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_AC);
		break;

	default:
		OV2_Used[site].OV2_slot->set_meas_mode(OV2_Used[site].OV2_channel,OV2_MEASURE_VOLTAGE);
		break;
	}

	if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_s==TRUE)&& (status_relay_f==TRUE))
		strcpy(status_board, "V_MODE");
	else if (fabs(real_current)>(current_value*0.98-0.1) && fabs(current_value)<(current_value*1.02+0.1) && (status_relay_s==TRUE) && (status_relay_f==TRUE))
	{
		if ((real_current>0.0f) )
			strcpy(status_board, "I_SRC");
		else
			strcpy(status_board, "I_SINK");
	}
	else
		strcpy(status_board, "UNDEF");
				
	vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
		voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
		status_board,mode_fl,measure_active_channel);
	}
	

#ifndef LegacyXerxes

void xvi_setup(short pin_sel,int site,FILE *file_debug_dc, char *notes)	
	{

	BOOL		status_relay_s,status_relay_f;
	char		range_v_s[15],range_i_s[15];
	char		status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	double		voltage_value,current_value,real_voltage,real_current,range_v,range_i;
	
	unsigned short measure_mode;
	float		measure_range;
	BYTE		measure_channel=0;
	int			xvi_image_sample_count;

	char		mode_fl;	
	
	
if(!debug_xvi_msl_offline)	
{
	status_relay_f= ((XVI_Used[site].XVI_slot->card.xvi_image_force_relay)>>XVI_Used[site].XVI_ch_index)&0x1;
	status_relay_s= ((XVI_Used[site].XVI_slot->card.xvi_image_sense_relay)>>XVI_Used[site].XVI_ch_index)&0x1;
}

	if (status_relay_s==FALSE)
		strcpy(status_relay_s_s, "OPEN ");
	else
		strcpy(status_relay_s_s, "CLOSE");
				
	if (status_relay_f==FALSE)
		strcpy(status_relay_f_s, "OPEN ");
	else
		strcpy(status_relay_f_s, "CLOSE");

	
if(!debug_xvi_msl_offline)	
{
	range_v=XVI_Used[site].XVI_slot->card.xvi_image_voltage_range[XVI_Used[site].XVI_ch_index];
	voltage_value= XVI_Used[site].XVI_slot->card.xvi_image_voltage[XVI_Used[site].XVI_ch_index];
}

	if((range_v>0.9)&&(range_v<1.1)) strcpy(range_v_s, "1_V"); else
	if((range_v>2.9)&&(range_v<3.1)) strcpy(range_v_s, "3_V"); else
	if((range_v>4.9)&&(range_v<5.1)) strcpy(range_v_s, "5_V"); else
	if((range_v>9.9)&&(range_v<10.1)) strcpy(range_v_s, "10_V"); else
	if((range_v>29.9)&&(range_v<30.1)) strcpy(range_v_s, "30_V"); else
	strcpy(range_v_s, "0_V"); 

if(!debug_xvi_msl_offline)	
{
	range_i=XVI_Used[site].XVI_slot->card.xvi_image_current_range[XVI_Used[site].XVI_ch_index];
	current_value= XVI_Used[site].XVI_slot->card.xvi_image_current[XVI_Used[site].XVI_ch_index];
}

	if((range_i>2.9e-6)&&(range_i<3.1e-6)) strcpy(range_i_s, "3_UA"); else
	if((range_i>29.0e-6)&&(range_i<31.0e-6)) strcpy(range_i_s, "30_UA"); else
	if((range_i>290.0e-6)&&(range_i<310.0e-6)) strcpy(range_i_s, "300_UA"); else
	if((range_i>2.9e-3)&&(range_i<3.1e-3)) strcpy(range_i_s, "3_MA"); else
	if((range_i>9.9e-3)&&(range_i<10.1e-3)) strcpy(range_i_s, "10_MA"); else
	if((range_i>29.0e-3)&&(range_i<31.0e-3)) strcpy(range_i_s, "30_MA"); else
	if((range_i>149.0e-3)&&(range_i<151.0e-3)) strcpy(range_i_s, "150_MA"); else
	strcpy(range_i_s, "0_A"); 
										
	
if(!debug_xvi_msl_offline)	
	measure_mode=XVI_Used[site].XVI_slot->card.xvi_imageISE_meas_mode[XVI_Used[site].XVI_ch_index];
	switch(measure_mode)
	{
		case 	XVI_MEAS_VOLTAGE:		mode_fl='V'; break;
		case 	XVI_MEAS_DIFF_VOLTAGE:	mode_fl='D'; break;
		case 	XVI_MEAS_CURRENT:		mode_fl='C'; break;
		case 	XVI_MEAS_TEMPERATURE:	mode_fl='T'; break;
		default:						mode_fl='U';
	}
					
if(!debug_xvi_msl_offline)	
{
	measure_range=XVI_Used[site].XVI_slot->card.xvi_imageISE_meas_range[XVI_Used[site].XVI_ch_index];
	xvi_image_sample_count=XVI_Used[site].XVI_slot->card.xvi_image_sample_count;
	XVI_Used[site].XVI_slot->set_sample_count(1);

	XVI_Used[site].XVI_slot->set_measure_mode_current(XVI_Used[site].XVI_channel);
	wait.delay_10_us(20);
	XVI_Used[site].XVI_slot->measure_average(XVI_Used[site].XVI_channel,real_current);
				
	XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,30.0);
	wait.delay_10_us(20);
	
	XVI_Used[site].XVI_slot->measure_average(XVI_Used[site].XVI_channel,real_voltage);
	
	if(fabs(real_voltage)<10.0)
	{
		if((fabs(real_voltage)>=5.0)&&(fabs(real_voltage)<10.0))
			XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,10.0);
		else if((fabs(real_voltage)>=3.0)&&(fabs(real_voltage)<5.0))
			XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,5.0);
		else if((fabs(real_voltage)>=1.0)&&(fabs(real_voltage)<3.0))
			XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,3.0);
		else
			XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,1.0);
		wait.delay_10_us(20);
		XVI_Used[site].XVI_slot->measure_average(XVI_Used[site].XVI_channel,real_voltage);
		if(xvi_image_sample_count>0)
			XVI_Used[site].XVI_slot->set_sample_count(xvi_image_sample_count);
	}
}				
	switch(mode_fl)
	{
	case 'I':
if(!debug_xvi_msl_offline)	
		XVI_Used[site].XVI_slot->set_measure_mode_current(XVI_Used[site].XVI_channel);
		break;
	case 'D':
if(!debug_xvi_msl_offline)	
		XVI_Used[site].XVI_slot->set_measure_mode_diff_voltage(XVI_Used[site].XVI_channel,measure_range);
		break;
	case 'V':
	default:
if(!debug_xvi_msl_offline)	
		XVI_Used[site].XVI_slot->set_measure_mode_voltage(XVI_Used[site].XVI_channel,measure_range);
		break;
	}

	if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_s==TRUE)&& (status_relay_f==TRUE))
		strcpy(status_board, "V_MODE");
	else if (fabs(real_current)>(current_value*0.98-0.1) && fabs(current_value)<(current_value*1.02+0.1) && (status_relay_s==TRUE) && (status_relay_f==TRUE))
	{
		if ((real_current>0.0f) )
			strcpy(status_board, "I_SRC");
		else
			strcpy(status_board, "I_SINK");
	}
	else
		strcpy(status_board, "UNDEF");
				
	vi_setup(pin_sel,site,file_debug_dc,status_relay_f_s,status_relay_s_s,
		voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,status_board,mode_fl,measure_channel);
	}
#endif



void cbit_setup(short pin_sel,int site,FILE *file_debug, char *notes)	
{
#ifndef ASL1K_NO_CBIT
	BOOL	status_relay;

	status_relay= !cbits.GetCbit(CBIT_Used[site].CBIT_channel);
	relay_setup(pin_sel,site,file_debug,status_relay);
#endif
}



void hvs_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL status_relay_f, status_relay_s;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];

	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;

	BYTE    measure_active_channel;


	char  mode_fl;	
	
	bool HVS_restore;

	
	switch (HVS_Used[site].HVS_channel)
	{
		case HVS_FORCE_POS:
			status_relay_f = HVS_Used[site].HVS_slot->relay_is_open(HVS_FORCE_POS);
			status_relay_s = status_relay_f;
			break;

		case HVS_OUT_1:
		case HVS_OUT_2:
		case HVS_OUT_3:
		case HVS_OUT_4:
		case HVS_OUT_5:
		case HVS_OUT_6:
		case HVS_OUT_7:
		case HVS_OUT_8:
			status_relay_f = HVS_Used[site].HVS_slot->relay_is_open(HVS_Used[site].HVS_channel);
			status_relay_s = HVS_Used[site].HVS_slot->relay_is_open(HVS_SENSE_POS_OUT_COM);
			break;
		case HVS_OUT_COM:
			status_relay_f = HVS_Used[site].HVS_slot->relay_is_open(HVS_SENSE_POS_OUT_COM);
			status_relay_s = status_relay_f;
			break;
		default:
			MessageBox (NULL,NULL,"invalid HVS channel ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
			exit(0);
	}

		if (status_relay_f == TRUE)
			strcpy(status_relay_f_s, "OPEN ");
		else
			strcpy(status_relay_f_s, "CLOSE");
		if (status_relay_s == TRUE)
			strcpy(status_relay_s_s, "OPEN ");
		else
			strcpy(status_relay_s_s, "CLOSE");

		
		range_v_str=HVS_Used[site].HVS_slot->get_voltage_range (range_v);
		voltage_value= HVS_Used[site].HVS_slot->get_voltage_setting ();
		strcpy(range_v_s, range_v_str); 

		range_i_str=HVS_Used[site].HVS_slot->get_current_range (range_i);
		current_value= HVS_Used[site].HVS_slot->get_current_setting ();
		strcpy(range_i_s, range_i_str); 
		for (h=0;h<15;h++)
			range_i_s[h]=range_i_s[h+6];
		for (h=0;h<15;h++)
			range_v_s[h]=range_v_s[h+6];

		

		switch (HVS_Used[site].HVS_channel)
		{
		case HVS_FORCE_POS:measure_active_channel = 0;break;
		case HVS_OUT_1:measure_active_channel = 1;break;
		case HVS_OUT_2:measure_active_channel = 2;break;
		case HVS_OUT_3:measure_active_channel = 3;break;
		case HVS_OUT_4:measure_active_channel = 4;break;
		case HVS_OUT_5:measure_active_channel = 5;break;
		case HVS_OUT_6:measure_active_channel = 6;break;
		case HVS_OUT_7:measure_active_channel = 7;break;
		case HVS_OUT_8:measure_active_channel = 8;break;
		case HVS_OUT_COM:measure_active_channel = 9;break;
		}





		mode_fl='X';

#ifndef	LegacyVATE522
		if (HVS_Used[site].HVS_slot->m_active_meas_mode == 9999)
#else
		if (true)
#endif
			HVS_restore = false;
		else
		{
			HVS_restore = true;
			HVS_Used[site].HVS_slot->save_measure_status();
		}

		HVS_Used[site].HVS_slot->set_meas_mode(HVS_MEASURE_VOLTAGE);
		wait.delay_10_us(20);
		real_voltage=HVS_Used[site].HVS_slot->measure();


		HVS_Used[site].HVS_slot->set_meas_mode(HVS_MEASURE_CURRENT);
		wait.delay_10_us(20);
		real_current=HVS_Used[site].HVS_slot->measure();

		if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_f==FALSE))
			strcpy(status_board, "V_MODE");
		else if (fabs(real_current)>(current_value*0.98) && fabs(current_value)<(current_value*1.02) && (status_relay_f==FALSE))
		{
			if ((real_current>0.0f) )
				strcpy(status_board, "I_SRC");
			else
				strcpy(status_board, "I_SNK");
		}
		else
			strcpy(status_board, "UNDEF");
				
		if (HVS_restore)
			HVS_Used[site].HVS_slot->restore_measure_status();

		vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
			status_board,mode_fl,measure_active_channel);
	}



void ofs_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL status_relay_f, status_relay_s;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];

	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;

	BYTE    measure_active_channel;


	char  mode_fl;	


	switch (OFS_Used[site].OFS_channel)
	{
		case OFS_FORCE_POS:
			status_relay_f = OFS_Used[site].OFS_slot->relay_is_open(OFS_FORCE_POS);
			status_relay_s = status_relay_f;
			break;

		case OFS_OUT_1:
		case OFS_OUT_2:
		case OFS_OUT_3:
		case OFS_OUT_4:
		case OFS_OUT_5:
		case OFS_OUT_6:
		case OFS_OUT_7:
		case OFS_OUT_8:
			status_relay_f = OFS_Used[site].OFS_slot->relay_is_open(OFS_Used[site].OFS_channel);
			status_relay_s = OFS_Used[site].OFS_slot->relay_is_open(OFS_SENSE_POS_OUT_COM);
			break;
		case OFS_OUT_COM:
			status_relay_f = OFS_Used[site].OFS_slot->relay_is_open(OFS_SENSE_POS_OUT_COM);
			status_relay_s = status_relay_f;
			break;
		default:
			MessageBox (NULL,NULL,"invalid OFS channel ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
			exit(0);
	}

		if (status_relay_f == TRUE)
			strcpy(status_relay_f_s, "OPEN ");
		else
			strcpy(status_relay_f_s, "CLOSE");
		if (status_relay_s == TRUE)
			strcpy(status_relay_s_s, "OPEN ");
		else
			strcpy(status_relay_s_s, "CLOSE");

		
		range_v_str=OFS_Used[site].OFS_slot->get_voltage_range (range_v);
		voltage_value= OFS_Used[site].OFS_slot->get_voltage_setting ();
		strcpy(range_v_s, range_v_str); 

		range_i_str=OFS_Used[site].OFS_slot->get_current_range (range_i);
		current_value= OFS_Used[site].OFS_slot->get_current_setting ();
		strcpy(range_i_s, range_i_str); 
		for (h=0;h<15;h++)
			range_i_s[h]=range_i_s[h+6];
		for (h=0;h<15;h++)
			range_v_s[h]=range_v_s[h+6];

		

		switch (OFS_Used[site].OFS_channel)
		{
		case OFS_FORCE_POS:measure_active_channel = 0;break;
		case OFS_OUT_1:measure_active_channel = 1;break;
		case OFS_OUT_2:measure_active_channel = 2;break;
		case OFS_OUT_3:measure_active_channel = 3;break;
		case OFS_OUT_4:measure_active_channel = 4;break;
		case OFS_OUT_5:measure_active_channel = 5;break;
		case OFS_OUT_6:measure_active_channel = 6;break;
		case OFS_OUT_7:measure_active_channel = 7;break;
		case OFS_OUT_8:measure_active_channel = 8;break;
		case OFS_OUT_COM:measure_active_channel = 9;break;
		}





		mode_fl='X';

		OFS_Used[site].OFS_slot->save_measure_status();

		OFS_Used[site].OFS_slot->set_meas_mode(OFS_MEASURE_VOLTAGE);
		wait.delay_10_us(20);
		real_voltage=OFS_Used[site].OFS_slot->measure();


		OFS_Used[site].OFS_slot->set_meas_mode(OFS_MEASURE_CURRENT);
		wait.delay_10_us(20);
		real_current=OFS_Used[site].OFS_slot->measure();

		if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_f==FALSE))
			strcpy(status_board, "V_MODE");
		else if (fabs(real_current)>(current_value*0.98) && fabs(current_value)<(current_value*1.02) && (status_relay_f==FALSE))
		{
			if ((real_current>0.0f) )
				strcpy(status_board, "I_SRC");
			else
				strcpy(status_board, "I_SNK");
		}
		else
			strcpy(status_board, "UNDEF");
				
		OFS_Used[site].OFS_slot->restore_measure_status();

		vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
			status_board,mode_fl,measure_active_channel);
	}



void mvs_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL status_relay_f, status_relay_s;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];

	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;

	BYTE    measure_active_channel;


	char  mode_fl;	


	switch (MVS_Used[site].MVS_channel)
	{
		case MVS_FORCE_POS:
			status_relay_f = MVS_Used[site].MVS_slot->relay_is_open(MVS_FORCE_POS);
			status_relay_s = status_relay_f;
			break;

		case MVS_OUT_1:
		case MVS_OUT_2:
		case MVS_OUT_3:
		case MVS_OUT_4:
		case MVS_OUT_5:
		case MVS_OUT_6:
		case MVS_OUT_7:
		case MVS_OUT_8:
			status_relay_f = MVS_Used[site].MVS_slot->relay_is_open(MVS_Used[site].MVS_channel);
			status_relay_s = MVS_Used[site].MVS_slot->relay_is_open(MVS_SENSE_POS_OUT_COM);
			break;
		case MVS_OUT_COM:
			status_relay_f = MVS_Used[site].MVS_slot->relay_is_open(MVS_SENSE_POS_OUT_COM);
			status_relay_s = status_relay_f;
			break;
		default:
			MessageBox (NULL,NULL,"invalid MVS channel ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
			exit(0);
	}

		if (status_relay_f == TRUE)
			strcpy(status_relay_f_s, "OPEN ");
		else
			strcpy(status_relay_f_s, "CLOSE");
		if (status_relay_s == TRUE)
			strcpy(status_relay_s_s, "OPEN ");
		else
			strcpy(status_relay_s_s, "CLOSE");

		
		range_v_str=MVS_Used[site].MVS_slot->get_voltage_range (range_v);
		voltage_value= MVS_Used[site].MVS_slot->get_voltage_setting ();
		strcpy(range_v_s, range_v_str); 

		range_i_str=MVS_Used[site].MVS_slot->get_current_range (range_i);
		current_value= MVS_Used[site].MVS_slot->get_current_setting ();
		strcpy(range_i_s, range_i_str); 
		for (h=0;h<15;h++)
			range_i_s[h]=range_i_s[h+6];
		for (h=0;h<15;h++)
			range_v_s[h]=range_v_s[h+6];

		

		switch (MVS_Used[site].MVS_channel)
		{
		case MVS_FORCE_POS:measure_active_channel = 0;break;
		case MVS_OUT_1:measure_active_channel = 1;break;
		case MVS_OUT_2:measure_active_channel = 2;break;
		case MVS_OUT_3:measure_active_channel = 3;break;
		case MVS_OUT_4:measure_active_channel = 4;break;
		case MVS_OUT_5:measure_active_channel = 5;break;
		case MVS_OUT_6:measure_active_channel = 6;break;
		case MVS_OUT_7:measure_active_channel = 7;break;
		case MVS_OUT_8:measure_active_channel = 8;break;
		case MVS_OUT_COM:measure_active_channel = 9;break;
		}





		mode_fl='X';

		MVS_Used[site].MVS_slot->save_measure_status();

		MVS_Used[site].MVS_slot->set_meas_mode(MVS_MEASURE_VOLTAGE);
		wait.delay_10_us(20);
		real_voltage=MVS_Used[site].MVS_slot->measure();


		MVS_Used[site].MVS_slot->set_meas_mode(MVS_MEASURE_CURRENT);
		wait.delay_10_us(20);
		real_current=MVS_Used[site].MVS_slot->measure();

		if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_f==FALSE))
			strcpy(status_board, "V_MODE");
		else if (fabs(real_current)>(current_value*0.98) && fabs(current_value)<(current_value*1.02) && (status_relay_f==FALSE))
		{
			if ((real_current>0.0f) )
				strcpy(status_board, "I_SRC");
			else
				strcpy(status_board, "I_SNK");
		}
		else
			strcpy(status_board, "UNDEF");
				
		MVS_Used[site].MVS_slot->restore_measure_status();

		vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
			status_board,mode_fl,measure_active_channel);
	}



void pvi_setup(short pin_sel,int site,FILE *file_debug ,char *notes)
	{

	
	int h;
	BOOL status_relay_f, status_relay_s;
	char    range_v,range_i;
	STRING  range_v_str,range_i_str;
	char		range_v_s[15],range_i_s[15];

	char	  status_relay_s_s[6],status_relay_f_s[6];					
	char		status_board[10];
	float   voltage_value,current_value,real_voltage,real_current;
	STRING  measure_mode, prg_name;

	BYTE    measure_active_channel;
	unsigned short  measure_active_meas_mode;

	char  mode_fl;	


	status_relay_f = PVI_Used[site].PVI_slot->switch_is_open (PVI_channel_high_force[PVI_Used[site].PVI_channel]);
	status_relay_s = PVI_Used[site].PVI_slot->switch_is_open (PVI_channel_high_sense[PVI_Used[site].PVI_channel]);

	if (status_relay_f == TRUE)
		strcpy(status_relay_f_s, "OPEN ");
	else
		strcpy(status_relay_f_s, "CLOSE");
	if (status_relay_s == TRUE)
		strcpy(status_relay_s_s, "OPEN ");
	else
		strcpy(status_relay_s_s, "CLOSE");

	
	range_v_str=PVI_Used[site].PVI_slot->get_voltage_range (range_v);
	voltage_value= PVI_Used[site].PVI_slot->get_voltage_setting ();
	strcpy(range_v_s, range_v_str); 

	range_i_str=PVI_Used[site].PVI_slot->get_current_range (range_i);
	current_value= PVI_Used[site].PVI_slot->get_current_setting ();
	strcpy(range_i_s, range_i_str); 
	for (h=0;h<15;h++)
		range_i_s[h]=range_i_s[h+6];
	for (h=0;h<15;h++)
		range_v_s[h]=range_v_s[h+6];

	

	measure_active_channel = PVI_Used[site].PVI_channel;	

	PVI_Used[site].PVI_slot->get_meas_mode(measure_active_meas_mode);
	if (measure_active_meas_mode == PV3_MEASURE_VOLTAGE)
		mode_fl='V';
	else 
		mode_fl='C';

	PVI_Used[site].PVI_slot->save_measure_status();

	PVI_Used[site].PVI_slot->set_meas_mode(PV3_MEASURE_VOLTAGE);
	wait.delay_10_us(20);
	real_voltage=PVI_Used[site].PVI_slot->measure();


	PVI_Used[site].PVI_slot->set_meas_mode(PV3_MEASURE_CURRENT);
	wait.delay_10_us(20);
	real_current=PVI_Used[site].PVI_slot->measure();

	if (real_voltage>((voltage_value*0.98-0.1)) && (real_voltage<(voltage_value*1.02+0.1)) && (status_relay_f==FALSE))
		strcpy(status_board, "V_MODE");
	else if (fabs(real_current)>(current_value*0.98) && fabs(current_value)<(current_value*1.02) && (status_relay_f==FALSE))
	{
		if ((real_current>0.0f) )
			strcpy(status_board, "I_SRC");
		else
			strcpy(status_board, "I_SNK");
	}
	else
		strcpy(status_board, "UNDEF");
			
	PVI_Used[site].PVI_slot->restore_measure_status();
	vi_setup(pin_sel,site,file_debug,status_relay_f_s,status_relay_s_s,
			voltage_value,range_v_s,real_voltage,current_value,range_i_s,real_current,
			status_board,mode_fl,measure_active_channel);
	}

void oal_setup(short pin_sel,int site,FILE *file_debug_dc, FILE *file_debug_relay , char *notes)
	{
	unsigned short
		status_relay_bank_1,
		status_relay_bank_2,
		status_switch_bank_1,
		status_switch_bank_2,
		status_switch_bank_3,
		status_adc_mux;


	status_relay_bank_1=OAL_Used[site].OAL_slot->card.relay_bank_1;
	status_relay_bank_2=OAL_Used[site].OAL_slot->card.relay_bank_2;
	status_switch_bank_1=OAL_Used[site].OAL_slot->card.switch_bank_1;
	status_switch_bank_2=OAL_Used[site].OAL_slot->card.switch_bank_2;
	status_switch_bank_3=OAL_Used[site].OAL_slot->card.switch_bank_3;
	status_adc_mux=OAL_Used[site].OAL_slot->card.adc_mux;
	
	if(
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_EXT_DRV1)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_EXT_DRV2)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_RMS)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_LOAD)
	  )


	{
		bool status_EXT_RLY_DRV=!(0x1&(status_relay_bank_2>>(EXT_RLY_DRV%16)));
		bool status_CH1_EXT_DRV=!(0x1&(status_relay_bank_2>>(CH1_EXT_DRV%16)));
		bool status_DRV_1=0x1&(status_switch_bank_2>>(DRV_1%16));
		bool status_DRV_2=0x1&(status_switch_bank_2>>(DRV_2%16));
		bool status_LOAD_REF_EXT=!(0x1&(status_relay_bank_1>>(LOAD_REF_EXT%16)));
		bool status_EXT_LOAD_CONN=!(0x1&(status_relay_bank_2>>(EXT_LOAD_CONN%16)));
		bool status_OUT_TO_RMS=!(0x1&(status_relay_bank_1>>(OUT_TO_RMS%16)));
		bool status_CH1_RMS_METER=!(0x1&(status_relay_bank_2>>(CH1_RMS_METER%16)));
	
		switch(Pin_Type_Used[pin_sel][site].Channel)
		{
		case EXT_RLY_DRV:	relay_setup(pin_sel,site,file_debug_relay,status_EXT_RLY_DRV,"EXT_RLY_DRV");		break;
		case CH1_EXT_DRV:	relay_setup(pin_sel,site,file_debug_relay,status_CH1_EXT_DRV,"CH1_EXT_DRV");		break;
		case DRV_1:			relay_setup(pin_sel,site,file_debug_relay,!status_DRV_1,"DRV_1");					break;	
		case DRV_2:			relay_setup(pin_sel,site,file_debug_relay,!status_DRV_2,"DRV_2");					break;	
		case LOAD_REF_EXT:	relay_setup(pin_sel,site,file_debug_relay,status_LOAD_REF_EXT,"LOAD_REF_EXT");		break;
		case EXT_LOAD_CONN:	relay_setup(pin_sel,site,file_debug_relay,status_EXT_LOAD_CONN,"EXT_LOAD_CONN");	break;
		case OUT_TO_RMS:	relay_setup(pin_sel,site,file_debug_relay,status_OUT_TO_RMS,"OUT_TO_RMS");			break;
		case CH1_RMS_METER:	relay_setup(pin_sel,site,file_debug_relay,status_CH1_RMS_METER,"CH1_RMS_METER");	break;
		default:
			{
				char err_message[100];
				sprintf(err_message, "system_status()\nUnrecognized channel for DOAL %s",Pin_Type_Used[pin_sel][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
			}
		}
	}
	else if(!(Pin_Type_Used[pin_sel][site].PinClass==PIN_UNDEF))
	 
	{

		
		float DAC_voltage_value=999.0f;
		#ifndef	LegacyVATE522
			DAC_voltage_value=OAL_Used[site].OAL_slot->m_voltage_value;
		#endif	

		
		char IA_V_Range[10],IA_I_Range[10];
		char Pin_name_s[10];
		char ADC_mode;
		int measure_channel=9;
		bool status_CH0_MEAS=0x1&(status_switch_bank_2>>(CH0_MEAS%16));
		bool status_CH1_MEAS=0x1&(status_switch_bank_2>>(CH1_MEAS%16));

		strncpy (Pin_name_s,Pin_Type_Used[pin_sel][site].Pin_Name,9);
		Pin_name_s[9]='\0';

		bool status_IA_1MV=0x1&(status_switch_bank_1>>(IA_1MV%16));
		bool status_IA_10MV=0x1&(status_switch_bank_1>>(IA_10MV%16));
		bool status_IA_100MV=0x1&(status_switch_bank_1>>(IA_100MV%16));

		if(status_IA_1MV&&status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","100UV");
		else if(!status_IA_1MV&&status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","1MV");
		else if(status_IA_1MV&&!status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","10MV");
		else if(status_IA_1MV&&status_IA_10MV&&!status_IA_100MV) sprintf(IA_V_Range,"%s","100MV");
		else sprintf(IA_V_Range,"%s","ERR");

		bool status_MLG_CON_NEG=0x1&(status_switch_bank_1>>(MLG_CON_NEG%16));
		bool status_LLG_CON_NEG=0x1&(status_switch_bank_1>>(LLG_CON_NEG%16));
		bool status_NEG_LKG_X10=0x1&(status_switch_bank_1>>(NEG_LKG_X10%16));

		if(!status_MLG_CON_NEG&&status_LLG_CON_NEG&&status_NEG_LKG_X10) sprintf(IA_I_Range,"%s","IA_1UA");
		else if(!status_MLG_CON_NEG&&status_LLG_CON_NEG&&!status_NEG_LKG_X10) sprintf(IA_I_Range,"%s","IA_10UA");
		else if(status_MLG_CON_NEG&&!status_LLG_CON_NEG) sprintf(IA_I_Range,"%s","IA_10NA");
		else sprintf(IA_I_Range,"%s","ERR");

		
		if ((status_adc_mux==(IA_AMP%8))||
			(status_adc_mux==(HV_BUF%8))||
			(status_adc_mux==(CH1_IA_AMP%8))||
			(status_adc_mux==(CH1_HV_BUF%8)))
				ADC_mode='V';
		else 
		if ((status_adc_mux==(MLG_NEG%8))||
			(status_adc_mux==(LLG_NEG%8))||
			(status_adc_mux==(EXT_PICO_POS%8))||
			(status_adc_mux==(EXT_PICO_NEG%8))||
			(status_adc_mux==(MLG_POS%8))||
			(status_adc_mux==(LLG_POS%8))||
			(status_adc_mux==(CH1_MLG_NEG%8))||
			(status_adc_mux==(CH1_LLG_NEG%8))||
			(status_adc_mux==(CH1_EXT_PICO_POS%8))||
			(status_adc_mux==(CH1_EXT_PICO_NEG%8))||
			(status_adc_mux==(CH1_MLG_POS%8))||
			(status_adc_mux==(CH1_LLG_POS%8)))
				ADC_mode='I';

	
		if(status_CH0_MEAS&&!status_CH1_MEAS)
			measure_channel=0;
		else if(!status_CH0_MEAS&&status_CH1_MEAS)
			measure_channel=1;

		
		fprintf(file_debug_dc,"%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
				,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
				,"NA","NA"
				,DAC_voltage_value,IA_V_Range,0.0f
				,0.0f,IA_I_Range,0.0f
				,"V_MODE",ADC_mode,measure_channel);

		printf("PinName    Site   Channel      Con_F   Con_S   V_SetUp      V_Rng V_Measure    I_SetUp      I_Rng   I_Measure    Supply  ADC\n***\n"); 
		printf("%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
				,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
				,"NA","NA"
				,DAC_voltage_value,IA_V_Range,0.0f
				,0.0f,IA_I_Range,0.0f
				,"V_MODE",ADC_mode,measure_channel);

	
		printf("\nPinName         Site   Channel         Relay\n***\n");
		if (OAL_Used[site].OAL_channel==OAL_CHANNEL_0)
		{
    		fprintf(file_debug_relay,"%s \n","DOAL CHANNEL 0");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_NEG_OUT%16))),	"DUT_NEG_OUT");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_POS_OUT%16))),	"DUT_POS_OUT");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(OUT_TO_RMS%16))),	"DUT_TO_RMS");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_OUT_OUT%16))),	"DUT_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(IA_OFF_POL%16)),	"IA_OFF_POL");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(EXT_RLY_DRV%16))),	"EXT_RLY_DRV");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(DRV_1%16)),			"DRV_1");
    		fprintf(file_debug_relay,"\n");
		}
		if (OAL_Used[site].OAL_channel==OAL_CHANNEL_1)
		{
    		fprintf(file_debug_relay,"%s \n","DOAL CHANNEL 1");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(CH1_NEG_OUT%16))),	"CH1_NEG_OUT");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(CH1_POS_OUT%16))),	"CH1_POS_OUT");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(CH1_RMS_METER%16))),	"CH1_RMS_METER");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(CH1_OUT_OUT%16))),	"CH1_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(CH1_OFF_POL%16)),	"CH1_OFF_POL");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(CH1_EXT_DRV%16))),	"CH1_EXT_DRV");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(DRV_2%16)),			"DRV_2");
    		fprintf(file_debug_relay,"\n");
		}

		fprintf(file_debug_relay,"%s \n","DOAL COMMON - SERVO LOOP");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(OUT_POL%16)),			"OUT_POL");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(OUT_RNG_X4%16)),		"OUT_RNG_X4");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(DAC_OUT%16)),			"DAC_OUT");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(INT_CONN%16)),			"INT_CONN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(INT_RESET%16)),			"INT_RESET");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_3>>(INT_SLOW%16)),			"INT_SLOW");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(DC_GAIN%16)),			"DC_GAIN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(CLOSE_LOOP%16)),		"CLOSE_LOOP");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_NEG_ISOL%16))),		"DUT_NEG_ISOL");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_POS_ISOL%16))),		"DUT_POS_ISOL");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(DUT_INP_SHORT%16))),		"DUT_INP_SHORT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(SHORT_FEEDBACK_RES%16))),"SHORT_FB_RES");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(FEEDBACK_TO_OUT%16))),	"FB_TO_OUT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(HV_BUF_CONN%16))),		"HV_BUF_CONN");
    
		fprintf(file_debug_relay,"%s \n","DOAL COMMON - MEASURE VOLTAGE PATH");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(IA_NEG_IN%16)),			"IA_NEG_IN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(IA_POS_IN%16)),			"IA_POS_IN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(IA_1MV%16)),			"IA_1MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(IA_10MV%16)),			"IA_10MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(IA_100MV%16)),			"IA_100MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(IA_OFF_100_MV%16)),		"IA_OFF_100_MV");

		fprintf(file_debug_relay,"%s \n","DOAL COMMON - MEASURE CURRENT PATH");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(CLS_LOOP_IV%16)),		"CLS_LOOP_IV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(MLG_CON_NEG%16)),		"MLG_CON_NEG");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(LLG_CON_NEG%16)),		"LLG_CON_NEG");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(NEG_LKG_X10%16)),		"NEG_LKG_X10");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(MLG_CON_POS%16)),		"MLG_CON_POS");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(LLG_CON_POS%16)),		"LLG_CON_POS");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(POS_LKG_X10%16)),		"POS_LKG_X10");

		fprintf(file_debug_relay,"%s \n","DOAL COMMON - LOAD PATH");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(CONNECT_LOADS%16))),		"CONNECT_LOADS");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(LOAD_SHORT%16))),		"LOAD_SHORT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(LOAD_600%16))),			"LOAD_600");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(LOAD_1K%16))),			"LOAD_1K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(LOAD_2K%16))),			"LOAD_2K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(LOAD_4K7%16))),			"LOAD_4K7");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(LOAD_10K%16))),			"LOAD_10K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(LOAD_100K%16))),			"LOAD_100K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(LOAD_REF_EXT%16))),		"LOAD_REF_EXT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(LOAD_REF_GND%16))),		"LOAD_REF_GND");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(EXT_LOAD_CONN%16))),		"EXT_LOAD_CONN");
	}
	else
	{
		char err_message[100];
		sprintf(err_message, "system_status()\nUndefined pin for DOAL %s",Pin_Type_Used[pin_sel][site].Pin_Name);
		mytext.text_in_box(40,10,err_message);
	}		

}

void qal_setup(short pin_sel,int site,FILE *file_debug_dc, FILE *file_debug_relay , char *notes)
	{
	unsigned short
		status_relay_bank_1,
		status_relay_bank_2,
		status_switch_bank_1,
		status_switch_bank_2,
		status_switch_bank_3,
		status_adc_mux;


	status_relay_bank_1=QAL_Used[site].QAL_slot->card.relay_bank_1;
	status_relay_bank_2=QAL_Used[site].QAL_slot->card.relay_bank_2;
	status_switch_bank_1=QAL_Used[site].QAL_slot->card.switch_bank_1;
	status_switch_bank_2=QAL_Used[site].QAL_slot->card.switch_bank_2;
	status_switch_bank_3=QAL_Used[site].QAL_slot->card.switch_bank_3;
	status_adc_mux=QAL_Used[site].QAL_slot->card.adc_mux;
	
	if(
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_EXT_DRV1)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_EXT_DRV2)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_RMS)||
		(Pin_Type_Used[pin_sel][site].PinClass==PIN_LOAD)
	  )


	{
		bool status_EXT_RLY_DRV=!(0x1&(status_relay_bank_2>>(QAL_EXT_RLY_DRV%16)));

		bool status_DRV_1=0x1&(status_switch_bank_2>>(QAL_DRV_1%16));

		bool status_LOAD_REF_EXT=!(0x1&(status_relay_bank_1>>(QAL_LOAD_REF_EXT%16)));
		bool status_EXT_LOAD_CONN=!(0x1&(status_relay_bank_2>>(QAL_EXT_LOAD_CONN%16)));


	
		switch(Pin_Type_Used[pin_sel][site].Channel)
		{
		case QAL_EXT_RLY_DRV:	relay_setup(pin_sel,site,file_debug_relay,status_EXT_RLY_DRV,"QAL_EXT_RLY_DRV");		break;

		case QAL_DRV_1:			relay_setup(pin_sel,site,file_debug_relay,!status_DRV_1,"QAL_DRV_1");					break;	

		case QAL_LOAD_REF_EXT:	relay_setup(pin_sel,site,file_debug_relay,status_LOAD_REF_EXT,"QAL_LOAD_REF_EXT");		break;
		case QAL_EXT_LOAD_CONN:	relay_setup(pin_sel,site,file_debug_relay,status_EXT_LOAD_CONN,"QAL_EXT_LOAD_CONN");	break;


		default:
			{
				char err_message[100];
				sprintf(err_message, "system_status()\nUnrecognized channel for QOAL %s",Pin_Type_Used[pin_sel][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
			}
		}
	}
	else if(!(Pin_Type_Used[pin_sel][site].PinClass==PIN_UNDEF))

	{


		float DAC_voltage_value=999.0f;
		#ifndef	LegacyVATE522
			DAC_voltage_value=QAL_Used[site].QAL_slot->m_voltage_value;
		#endif


		char IA_V_Range[10],IA_I_Range[10];
		char Pin_name_s[10];
		char ADC_mode;
		int measure_channel=9;
		bool status_CH0_MEAS=0x1&(status_switch_bank_2>>(QAL_CH0_MEAS%16));
		bool status_CH1_MEAS=0x1&(status_switch_bank_2>>(QAL_CH1_MEAS%16));
		bool status_CH2_MEAS=0x1&(status_switch_bank_2>>(QAL_CH2_MEAS%16));
		bool status_CH3_MEAS=0x1&(status_switch_bank_2>>(QAL_CH3_MEAS%16));

		strncpy (Pin_name_s,Pin_Type_Used[pin_sel][site].Pin_Name,9);
		Pin_name_s[9]='\0';

		bool status_IA_1MV=0x1&(status_switch_bank_1>>(QAL_IA_1MV%16));
		bool status_IA_10MV=0x1&(status_switch_bank_1>>(QAL_IA_10MV%16));
		bool status_IA_100MV=0x1&(status_switch_bank_1>>(QAL_IA_100MV%16));

		if(status_IA_1MV&&status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","100UV");
		else if(!status_IA_1MV&&status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","1MV");
		else if(status_IA_1MV&&!status_IA_10MV&&status_IA_100MV) sprintf(IA_V_Range,"%s","10MV");
		else if(status_IA_1MV&&status_IA_10MV&&!status_IA_100MV) sprintf(IA_V_Range,"%s","100MV");
		else sprintf(IA_V_Range,"%s","ERR");

		bool status_MLG_CON_NEG=0x1&(status_switch_bank_1>>(QAL_MLG_CON_NEG%16));
		bool status_LLG_CON_NEG=0x1&(status_switch_bank_1>>(QAL_LLG_CON_NEG%16));
		bool status_NEG_LKG_X10=0x1&(status_switch_bank_1>>(QAL_NEG_LKG_X10%16));

		if(!status_MLG_CON_NEG&&status_LLG_CON_NEG&&status_NEG_LKG_X10) sprintf(IA_I_Range,"%s","IA_1UA");
		else if(!status_MLG_CON_NEG&&status_LLG_CON_NEG&&!status_NEG_LKG_X10) sprintf(IA_I_Range,"%s","IA_10UA");
		else if(status_MLG_CON_NEG&&!status_LLG_CON_NEG) sprintf(IA_I_Range,"%s","IA_10NA");
		else sprintf(IA_I_Range,"%s","ERR");


		if ((status_adc_mux==(QAL_IA_AMP%8))||
			(status_adc_mux==(QAL_HV_BUF%8))||
			(status_adc_mux==(QAL_CH1_IA_AMP%8))||
			(status_adc_mux==(QAL_CH1_HV_BUF%8))||
			(status_adc_mux==(QAL_CH2_IA_AMP%8))||
			(status_adc_mux==(QAL_CH2_HV_BUF%8))||
			(status_adc_mux==(QAL_CH3_IA_AMP%8))||
			(status_adc_mux==(QAL_CH3_HV_BUF%8))
			)
				ADC_mode='V';
		else 
		if ((status_adc_mux==(QAL_MLG_NEG%8))||
			(status_adc_mux==(QAL_LLG_NEG%8))||
			(status_adc_mux==(QAL_EXT_PICO_POS%8))||
			(status_adc_mux==(QAL_EXT_PICO_NEG%8))||
			(status_adc_mux==(QAL_MLG_POS%8))||
			(status_adc_mux==(QAL_LLG_POS%8))||
			(status_adc_mux==(QAL_CH1_MLG_NEG%8))||
			(status_adc_mux==(QAL_CH1_LLG_NEG%8))||
			(status_adc_mux==(QAL_CH1_EXT_PICO_POS%8))||
			(status_adc_mux==(QAL_CH1_EXT_PICO_NEG%8))||
			(status_adc_mux==(QAL_CH1_MLG_POS%8))||
			(status_adc_mux==(QAL_CH1_LLG_POS%8))












            )
				ADC_mode='I';


		if(status_CH0_MEAS&&!status_CH1_MEAS&&!status_CH2_MEAS&&!status_CH2_MEAS)
			measure_channel=0;
		else if(!status_CH0_MEAS&&status_CH1_MEAS&&!status_CH2_MEAS&&!status_CH3_MEAS)
			measure_channel=1;
		else if(!status_CH0_MEAS&&!status_CH1_MEAS&&status_CH2_MEAS&&!status_CH3_MEAS)
			measure_channel=2;
		else if(!status_CH0_MEAS&&!status_CH1_MEAS&&!status_CH2_MEAS&&status_CH3_MEAS)
			measure_channel=3;


		fprintf(file_debug_dc,"%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
				,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
				,"NA","NA"
				,DAC_voltage_value,IA_V_Range,0.0f
				,0.0f,IA_I_Range,0.0f
				,"V_MODE",ADC_mode,measure_channel);

		printf("PinName    Site   Channel      Con_F   Con_S   V_SetUp      V_Rng V_Measure    I_SetUp      I_Rng   I_Measure    Supply  ADC\n***\n"); 
		printf("%-10.10s S%-5d %-12.12s %-7.7s %-7.7s %-12.6f %-5.5s %-12.6f %-12.6f %-7.7s %-12.6f %-7.7s %c_%d\n"
				,Pin_name_s,site+1,Pin_Type_Used[pin_sel][site].Channel_Name
				,"NA","NA"
				,DAC_voltage_value,IA_V_Range,0.0f
				,0.0f,IA_I_Range,0.0f
				,"V_MODE",ADC_mode,measure_channel);


		printf("\nPinName         Site   Channel         Relay\n***\n");
		if (QAL_Used[site].QAL_channel==QAL_CHANNEL_0)
		{
    		fprintf(file_debug_relay,"%s \n","QOAL CHANNEL 0");



			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_DUT_OUT_OUT%16))),	"QAL_DUT_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_IA_OFF_POL%16)),	"QAL_IA_OFF_POL");
			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_EXT_RLY_DRV%16))),	"QAL_EXT_RLY_DRV");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_DRV_1%16)),			"QAL_DRV_1");
    		fprintf(file_debug_relay,"\n");
		}
		if (QAL_Used[site].QAL_channel==QAL_CHANNEL_1)
		{
    		fprintf(file_debug_relay,"%s \n","QOAL CHANNEL 1");



			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_CH1_OUT_OUT%16))),	"QAL_CH1_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_CH1_OFF_POL%16)),	"QAL_CH1_OFF_POL");


    		fprintf(file_debug_relay,"\n");
		}
		if (QAL_Used[site].QAL_channel==QAL_CHANNEL_2)
		{
    		fprintf(file_debug_relay,"%s \n","QOAL CHANNEL 2");



			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_CH2_OUT_OUT%16))),	"QAL_CH2_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_CH2_OFF_POL%16)),	"QAL_CH2_OFF_POL");


    		fprintf(file_debug_relay,"\n");
		}
		if (QAL_Used[site].QAL_channel==QAL_CHANNEL_3)
		{
    		fprintf(file_debug_relay,"%s \n","QOAL CHANNEL 3");



			relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_CH3_OUT_OUT%16))),	"QAL_CH3_OUT_OUT");
			relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_CH3_OFF_POL%16)),	"QAL_CH3_OFF_POL");


    		fprintf(file_debug_relay,"\n");
		}

		fprintf(file_debug_relay,"%s \n","QOAL COMMON - SERVO LOOP");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_OUT_POL%16)),			"QAL_OUT_POL");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_OUT_RNG_X4%16)),		"QAL_OUT_RNG_X4");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_DAC_OUT%16)),			"QAL_DAC_OUT");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_INT_CONN%16)),			"QAL_INT_CONN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_INT_RESET%16)),			"QAL_INT_RESET");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_3>>(QAL_INT_SLOW%16)),			"QAL_INT_SLOW");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_DC_GAIN%16)),			"QAL_DC_GAIN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_CLOSE_LOOP%16)),		"QAL_CLOSE_LOOP");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_DUT_NEG_ISOL%16))),		"QAL_DUT_NEG_ISOL");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_DUT_POS_ISOL%16))),		"QAL_DUT_POS_ISOL");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_DUT_INP_SHORT%16))),		"QAL_DUT_INP_SHORT");


		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_HV_BUF_CONN%16))),		"QAL_HV_BUF_CONN");
    
		fprintf(file_debug_relay,"%s \n","QOAL COMMON - MEASURE VOLTAGE PATH");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_IA_NEG_IN%16)),			"QAL_IA_NEG_IN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_2>>(QAL_IA_POS_IN%16)),			"QAL_IA_POS_IN");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_IA_1MV%16)),			"QAL_IA_1MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_IA_10MV%16)),			"QAL_IA_10MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_IA_100MV%16)),			"QAL_IA_100MV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_IA_OFF_100_MV%16)),		"QAL_IA_OFF_100_MV");

		fprintf(file_debug_relay,"%s \n","QOAL COMMON - MEASURE CURRENT PATH");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_CLS_LOOP_IV%16)),		"QAL_CLS_LOOP_IV");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_MLG_CON_NEG%16)),		"QAL_MLG_CON_NEG");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_LLG_CON_NEG%16)),		"QAL_LLG_CON_NEG");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_NEG_LKG_X10%16)),		"QAL_NEG_LKG_X10");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_MLG_CON_POS%16)),		"QAL_MLG_CON_POS");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_LLG_CON_POS%16)),		"QAL_LLG_CON_POS");
		relay_setup(pin_sel,site,file_debug_relay,  0x1&(status_switch_bank_1>>(QAL_POS_LKG_X10%16)),		"QAL_POS_LKG_X10");

		fprintf(file_debug_relay,"%s \n","QOAL COMMON - LOAD PATH");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_CONNECT_LOADS%16))),		"QAL_CONNECT_LOADS");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_LOAD_SHORT%16))),		"QAL_LOAD_SHORT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_LOAD_600%16))),			"QAL_LOAD_600");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_LOAD_1K%16))),			"QAL_LOAD_1K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_LOAD_2K%16))),			"QAL_LOAD_2K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_LOAD_4K7%16))),			"QAL_LOAD_4K7");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_LOAD_10K%16))),			"QAL_LOAD_10K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_LOAD_100K%16))),			"QAL_LOAD_100K");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_LOAD_REF_EXT%16))),		"QAL_LOAD_REF_EXT");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_1>>(QAL_LOAD_REF_GND%16))),		"QAL_LOAD_REF_GND");
		relay_setup(pin_sel,site,file_debug_relay,!(0x1&(status_relay_bank_2>>(QAL_EXT_LOAD_CONN%16))),		"QAL_EXT_LOAD_CONN");
	}
	else
	{
		char err_message[100];
		sprintf(err_message, "system_status()\nUndefined pin for QOAL %s",Pin_Type_Used[pin_sel][site].Pin_Name);
		mytext.text_in_box(40,10,err_message);
	}		

}

void  acs_setup(short pin_sel,int site, FILE *file_debug, char *notes)  
{
	BOOL	status_relay;

	status_relay= ACS_Used[site].ACS_slot->relay_is_open(ACS_Used[site].ACS_channel);
	relay_setup(pin_sel,site,file_debug,status_relay);
}

void  lzb_setup(short pin_sel,int site, FILE *file_debug, char *notes)  
{
	BOOL	status_relay;

	if((LZB_Used[site].LZB_channel>=LZB_MUX_OUT_1)&&(LZB_Used[site].LZB_channel<=LZB_MUX_OUT_16))
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[4]>>LZB_Used[site].LZB_channel)&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay);
	} else
	if((LZB_Used[site].LZB_channel>=LZB_MUX_OUT_17)&&(LZB_Used[site].LZB_channel<=LZB_MUX_GND_4))
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[5]>>(LZB_Used[site].LZB_channel-LZB_MUX_OUT_17))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay);
	} else
	if((LZB_Used[site].LZB_channel>=LZB_MUX_GND_5)&&(LZB_Used[site].LZB_channel<=LZB_MUX_GND_20))
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[6]>>(LZB_Used[site].LZB_channel-LZB_MUX_GND_5))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay);
	} else
	if((LZB_Used[site].LZB_channel>=LZB_MUX_GND_21)&&(LZB_Used[site].LZB_channel<=LZB_MUX_GND_28))
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[7]>>(LZB_Used[site].LZB_channel-LZB_MUX_GND_21))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay);
	}

	if (LZB_Used[site].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
	{
		if((LZB_Used[site].LZB_channel_2>=LZB_MUX_OUT_1)&&(LZB_Used[site].LZB_channel_2<=LZB_MUX_OUT_16))
		{
			status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[4]>>LZB_Used[site].LZB_channel_2)&0x1;
			relay_setup(pin_sel,site,file_debug,!status_relay);
		} else
		if((LZB_Used[site].LZB_channel_2>=LZB_MUX_OUT_17)&&(LZB_Used[site].LZB_channel_2<=LZB_MUX_GND_4))
		{
			status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[5]>>(LZB_Used[site].LZB_channel_2-LZB_MUX_OUT_17))&0x1;
			relay_setup(pin_sel,site,file_debug,!status_relay);
		} else
		if((LZB_Used[site].LZB_channel_2>=LZB_MUX_GND_5)&&(LZB_Used[site].LZB_channel_2<=LZB_MUX_GND_20))
		{
			status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[6]>>(LZB_Used[site].LZB_channel_2-LZB_MUX_GND_5))&0x1;
			relay_setup(pin_sel,site,file_debug,!status_relay);
		} else
		if((LZB_Used[site].LZB_channel_2>=LZB_MUX_GND_21)&&(LZB_Used[site].LZB_channel_2<=LZB_MUX_GND_28))
		{
			status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[7]>>(LZB_Used[site].LZB_channel_2-LZB_MUX_GND_21))&0x1;
			relay_setup(pin_sel,site,file_debug,!status_relay);
		}
	}
	
	if((LZB_Used[site].LZB_channel==LZB_CONN_OUT)||(LZB_Used[site].LZB_channel==LZB_CONN_GND))
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[7]>>(LZB_CONN_OUT-LZB_MUX_GND_21))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay, "LZB_CONN_OUT");
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[7]>>(LZB_CONN_GND-LZB_MUX_GND_21))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay, "LZB_CONN_GND");
	} else
	if(LZB_Used[site].LZB_channel==LZB_CONN_CLAMP)
	{
		status_relay=(LZB_Used[site].LZB_slot->card.lzb_image[7]>>(LZB_CONN_GND-LZB_MUX_GND_21))&0x1;
		relay_setup(pin_sel,site,file_debug,!status_relay, "LZB_CONN_CLAMP");
	}
}



void  dc_scope(short pin, short mode , short range, short num_sample, double fre_sample, short site, float *meas_array)
{
	short	fre_sample_10us;

	if(fre_sample>0)
		fre_sample_10us=(int)(0.5+(fre_sample/(10 uS)));
	else
		return;

	dc_scope(pin, mode , range, num_sample, fre_sample_10us, site, meas_array);
}

void  dc_scope(short pin, short mode , short range, short num_sample, short fre_sample_10us, short site, float *meas_array)
{

	int x;
	short Source_type;
	float result_strobe[MAX_SCOPE_SAMPLE];

	if (num_sample>MAX_SCOPE_SAMPLE)
	{
			MessageBox (NULL,NULL,"DC Scope Error ",MB_OK | MB_ICONERROR | MB_SETFOREGROUND); 
			exit(0);
	}

	Source_type=pin_selection(pin,0);

			switch(Source_type)
			{
			case DVI:

				if(mode == MEASURE_VOLTAGE)
				{	
					DVI_Used[site].DVI_slot->set_meas_mode(DVI_Used[site].DVI_channel, DVI_MEASURE_VOLTAGE);
					DVI_Used[site].DVI_slot->set_voltage_range(DVI_Used[site].DVI_channel, POSITIVE_V_OUT,range,FAST_VOLTAGE_MODE);

				}
				if(mode == MEASURE_DIFF_VOLTAGE)
					{
						DVI_Used[site].DVI_slot->set_meas_mode(DVI_Used[site].DVI_channel, DVI_MEASURE_DIFF);
						DVI_Used[site].DVI_slot->set_diff_range(range);
					}
				if(mode == MEASURE_CURRENT)
				{
					DVI_Used[site].DVI_slot->set_meas_mode(DVI_Used[site].DVI_channel, DVI_MEASURE_CURRENT);
					DVI_Used[site].DVI_slot->set_current_range(DVI_Used[site].DVI_channel,range);

				}
				wait.delay_10_us(50); 

				for (x=0;x<num_sample;x++)
				{
					result_strobe[x]= DVI_Used[site].DVI_slot->measure();
					wait.delay_10_us(fre_sample_10us);
				}

			break;


			case OVI:
			case OVI_S:
				if(mode == MEASURE_VOLTAGE)
				{
					OVI_Used[site].OVI_slot->set_meas_mode(OVI_Used[site].OVI_channel, OVI_MEASURE_VOLTAGE, range);

				}
				if(mode == MEASURE_CURRENT)
				{
					OVI_Used[site].OVI_slot->set_meas_mode(OVI_Used[site].OVI_channel, OVI_MEASURE_CURRENT);
				}
				wait.delay_10_us(10); 
				for (x=0;x<num_sample;x++)
				{
					result_strobe[x]= OVI_Used[site].OVI_slot->measure();
					wait.delay_10_us(fre_sample_10us);
				}


			break;
			default:
				mytext.text_in_box(40,10,"Scope available for DVI / OVI only");
				exit(0);
			}

		
		if(meas_array!=NULL)
			for (x=0;x<num_sample;x++)
				meas_array[x]=result_strobe[x];
}





void  data_log(test_function& func, short test_no, class SFLOAT test_val_SFLOAT,  short power, unsigned short fail_bin,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = test_val_SFLOAT.get_value(site_no);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short fail_bin,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short *fail_bin_site,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short fail_bin,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short *fail_bin_site,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short fail_bin,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short *fail_bin_site,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short fail_bin,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short *fail_bin_site,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short fail_bin,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short *fail_bin_site,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short fail_bin,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short *fail_bin_site,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short fail_bin,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short *fail_bin_site,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short fail_bin,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short *fail_bin_site,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short fail_bin,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_double[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short *fail_bin_site,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_double[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short fail_bin,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_double[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short *fail_bin_site,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_double[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short fail_bin,  char *notes)
{
	sushort fail_bin_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			fail_bin_site[site_no] = fail_bin;
	data_log(func, test_no, test_val, power, fail_bin_site, notes);
}	


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short fail_bin,  schar notes)
{
	sushort fail_bin_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			fail_bin_site[site_no] = fail_bin;
	data_log(func, test_no, test_val, power, fail_bin_site, notes);
}	


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short *fail_bin,  char *notes)
{
	schar comment_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no]) {
			if (notes == NULL)
				strcpy(comment_site[site_no], "");
			else
				strcpy(comment_site[site_no], notes);
		}
	data_log(func, test_no, test_val, power, fail_bin, comment_site);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short fail_bin,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short *fail_bin_site,  char *notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short fail_bin,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short *fail_bin_site,  schar notes)	
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


#ifndef LegacyVATE522
void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short fail_bin,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short *fail_bin_site,  char *notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short fail_bin,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short *fail_bin_site,  schar notes)
{
	sfloat test_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, notes);
}
#endif



void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short *fail_bin,  schar notes)
{
	for(int site_no = 0; site_no < max_sites ; site_no++ ) {
		if(active_site[site_no])
		{
				func.dlog->set_test_no(test_no + 1, site_no + 1);
				func.dlog->power=(char)power;
				func.dlog->test_val(test_val[site_no]);
				if(func.dlog->tests[test_no].passed_fail == FAILED_TEST)
				{
					device_passed[site_no] = false;	
					if (continue_on_fail_flag == false)
					{
#ifdef POWERDOWN
						store_site_status();	
						activate_one_site(site_no);	
						power_down(site_no);	
						restore_site_status();	
#endif
						active_site[site_no] = false;
					}
					func.dlog->set_bin(fail_bin[site_no]);
				}

				if (notes) func.dlog->datalog_notes(notes[site_no]);

				if(func.dlog->tests[test_no].display_results)    
					func.dlog->display_results();
			}
	}				
}



void  data_log(test_function& func, short test_no, class SFLOAT test_val_SFLOAT,  short power, unsigned short fail_bin,SFLOAT min_val_SFLOAT,SFLOAT max_val_SFLOAT,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = test_val_SFLOAT.get_value(site_no);
			min_val_float[site_no]  =  min_val_SFLOAT.get_value(site_no);
			max_val_float[site_no]  = max_val_SFLOAT.get_value(site_no);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short fail_bin,unsigned int *min_val_integer,unsigned int *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no]  = (float)(min_val_integer[site_no]);
			max_val_float[site_no]  = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned int *min_val_integer,unsigned int *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no]  = (float)(min_val_integer[site_no]);			
			max_val_float[site_no]  = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short fail_bin,unsigned int *min_val_integer,unsigned int *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			test_val_float[site_no] = (float)(min_val_integer[site_no]);
			test_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin ,min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned int *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned int *min_val_integer,unsigned int *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short fail_bin,unsigned short *min_val_integer,unsigned short *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned short *min_val_integer,unsigned short *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short fail_bin,unsigned short *min_val_integer,unsigned short *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned short *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned short *min_val_integer,unsigned short *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short fail_bin,unsigned long *min_val_integer,unsigned long *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned long *min_val_integer,unsigned long *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short fail_bin,unsigned long *min_val_integer,unsigned long *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, unsigned long *test_val_integer,  short power, unsigned short *fail_bin_site,unsigned long *min_val_integer,unsigned long *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short fail_bin,int *min_val_integer,int *max_val_integer,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short *fail_bin_site,int *min_val_integer,int *max_val_integer,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short fail_bin,int *min_val_integer,int *max_val_integer,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, int *test_val_integer,  short power, unsigned short *fail_bin_site,int *min_val_integer,int *max_val_integer,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short fail_bin,double *min_val_double,double *max_val_double,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_double[site_no]);
			min_val_float[site_no] = (float)(min_val_float[site_no]);
			max_val_float[site_no] = (float)(max_val_float[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short *fail_bin_site,double *min_val_double,double *max_val_double,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_double[site_no]);
			min_val_float[site_no] = (float)(min_val_double[site_no]);
			max_val_float[site_no] = (float)(max_val_double[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short fail_bin,double *min_val_double,double *max_val_double,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_double[site_no]);
			min_val_float[site_no] = (float)(min_val_double[site_no]);
			max_val_float[site_no] = (float)(max_val_double[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, double *test_val_double,  short power, unsigned short *fail_bin_site,double *min_val_double,double *max_val_double,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_double[site_no]);
			min_val_float[site_no] = (float)(min_val_double[site_no]);
			max_val_float[site_no] = (float)(max_val_double[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short fail_bin,float *min_val,float *max_val,  char *notes)
{
	sushort fail_bin_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			fail_bin_site[site_no] = fail_bin;
	data_log(func, test_no, test_val, power, fail_bin_site, min_val, max_val, notes);
}	


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short fail_bin,float *min_val,float *max_val,  schar notes)
{
	sushort fail_bin_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			fail_bin_site[site_no] = fail_bin;
	data_log(func, test_no, test_val, power, fail_bin_site, min_val, max_val, notes);
}	


void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short *fail_bin,float *min_val,float *max_val,  char *notes)
{
	schar comment_site;

	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no]) {
			if (notes == NULL)
				strcpy(comment_site[site_no], "");
			else
				strcpy(comment_site[site_no], notes);
		}
	data_log(func, test_no, test_val, power, fail_bin, min_val, max_val, comment_site);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short fail_bin,bool *min_val_integer,bool *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_float[site_no]);
			max_val_float[site_no] = (float)(max_val_float[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short *fail_bin_site,bool *min_val_integer,bool *max_val_integer,  char *notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_float[site_no]);
			max_val_float[site_no] = (float)(max_val_float[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short fail_bin,bool *min_val_integer,bool *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_float[site_no]);
			max_val_float[site_no] = (float)(max_val_float[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, bool *test_val_integer,  short power, unsigned short *fail_bin_site,bool *min_val_integer,bool *max_val_integer,  schar notes)	
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_integer[site_no]);
			min_val_float[site_no] = (float)(min_val_integer[site_no]);
			max_val_float[site_no] = (float)(max_val_integer[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


#ifndef LegacyVATE522
void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short fail_bin,sDouble *min_val_sDouble,sDouble *max_val_sDouble,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short *fail_bin_site,sDouble min_val_sDouble,sDouble max_val_sDouble,  char *notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
		{
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
			min_val_float[site_no] = (float)(min_val_sDouble[site_no]);
			max_val_float[site_no] = (float)(max_val_sDouble[site_no]);
		}
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short fail_bin,sDouble min_val_sDouble,sDouble max_val_sDouble,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin, min_val_float, max_val_float, notes);
}


void  data_log(test_function& func, short test_no, sDouble test_val_sDouble,  short power, unsigned short *fail_bin_site,sDouble min_val_sDouble,sDouble max_val_sDouble,  schar notes)
{
	sfloat test_val_float;
	sfloat min_val_float;
	sfloat max_val_float;
	
	for(int site_no = 0; site_no < max_sites ; site_no++ )
		if(active_site[site_no])
			test_val_float[site_no] = (float)(test_val_sDouble[site_no]);
	data_log(func, test_no, test_val_float, power, fail_bin_site, min_val_float, max_val_float, notes);
}
#endif



void  data_log(test_function& func, short test_no, float *test_val,  short power, unsigned short *fail_bin,float *min_val,float *max_val,  schar notes)
{
	for(int site_no = 0; site_no < max_sites ; site_no++ ) {
		if(active_site[site_no])
		{
				func.dlog->set_test_no(test_no + 1, site_no + 1);
				func.dlog->power=(char)power;
				if (min_val[site_no]!=max_val[site_no])
				{
					func.dlog->set_min_active();
					func.dlog->min_limit(min_val[site_no]);
					func.dlog->set_max_active();
					func.dlog->max_limit(max_val[site_no]);
				}
				func.dlog->test_val(test_val[site_no]);
				if(func.dlog->tests[test_no].passed_fail == FAILED_TEST)
				{
					device_passed[site_no] = false;	
					if (continue_on_fail_flag == false)
					{
#ifdef POWERDOWN
						store_site_status();	
						activate_one_site(site_no);	
						power_down(site_no);	
						restore_site_status();	
#endif
						active_site[site_no] = false;
					}
					func.dlog->set_bin(fail_bin[site_no]);
				}

				if (notes) func.dlog->datalog_notes(notes[site_no]);

				if(func.dlog->tests[test_no].display_results)    
					func.dlog->display_results();
			}
	}				
}


STRING &GetUserString( char * strname )
{
        static STRING str;
        STRING dummy_str;

        user_strings us;
        
        GetUserStringsStruct( &us );

        str.Clear();
        for( int idx=0; idx<10; idx++ )
        {
                if( !strcmp( us.string[idx], strname ) )
                {
                        dummy_str.LoadFromBuffer( us.desc[idx] );
						str += dummy_str;	
                }
        }

        return str;
}


void continue_on_fail(void)
{
	continue_on_fail_flag = true;
}



void stop_on_fail(void)
{
	continue_on_fail_flag = false;
}


void stop_on_fail_PPflag(void)
{
	Program_load *p = (Program_load*) g_program;
	unsigned short cof_flag = p->operator_setup.cont_on_fail; 
	if (!p->operator_setup.cont_on_fail)	
		stop_on_fail();	
}


void continue_on_fail_PPflag(void)
{
	Program_load *p = (Program_load*) g_program;
	if (p->operator_setup.cont_on_fail)		
		continue_on_fail();	
}


void deactivate_fail_site(void)
{

	








	int i;



	if (continue_on_fail_flag == false)
#ifdef POWERDOWN
	{
		bool current_active_site[MAX_SITES];
		bool site_to_power_down[MAX_SITES];	

		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{
	
			current_active_site[i]=active_site[i];
			
			
			if((device_passed[i] == FALSE) && (active_site[i] == TRUE))
				site_to_power_down[i]=true;
			else
				site_to_power_down[i]=false;


			active_site[i] = false;
		}

		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{
			
			if(site_to_power_down[i] == true)
			{
				active_site[i] = true;
			

				power_down(i);


				active_site[i] = false;
			}
			
		}


		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{
			if(site_to_power_down[i] == false)
				active_site[i] = current_active_site[i];
		}
	}	
#else



	for( i = 0; i < max_sites ; i++ )
	{
		if(device_passed[i] == false)
				active_site[i] = false;
	}

#endif	

}


void deactivate_fail_site_PPflag(void)
{









	int i;
#ifdef POWERDOWN	
	bool current_active_site[MAX_SITES];
	bool site_to_power_down[MAX_SITES];	
#endif	

	Program_load *p = (Program_load*) g_program;
	if (!p->operator_setup.cont_on_fail)		


#ifdef POWERDOWN
	{
		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{

			current_active_site[i]=active_site[i];
			

			if((device_passed[i] == FALSE) && (active_site[i] == TRUE))
				site_to_power_down[i]=true;
			else
				site_to_power_down[i]=false;

		
			active_site[i] = false;
		}

		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{
		
			if(site_to_power_down[i] == true)
			{
				active_site[i] = true;
			
			
				power_down(i);


				active_site[i] = false;
			}
			
		}


		for( i = 0; i < CSC_LAST_SITE ; i++ )
		{
			if(site_to_power_down[i] == false)
				active_site[i] = current_active_site[i];
		}
	}	
#else


	
	for( i = 0; i < max_sites ; i++ )
		{
			if(device_passed[i] == false)
					active_site[i] = false;
		}
#endif

}


bool no_site_active(void)
{
	int i;
	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
				return false;
	}
	return true;
}


void  dc_charge_pvi(short pin,double voltage_limit, long int timeout)
{
	dc_charge_pvi(pin, float(voltage_limit), timeout);
}

void  dc_charge_pvi(short pin,float voltage_limit, long int timeout)
{
	int i;
	short Source_type;
	long int timecnt;
	float charge;
	
	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
		
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					PVI_Used[i].PVI_slot->charge_on();
					PVI_Used[i].PVI_slot->set_meas_mode(PV3_CHARGE_S);
					delay(1);
					timecnt = 0;
					charge = PVI_Used[i].PVI_slot->measure();
					while ((charge < voltage_limit) && (timecnt < timeout))
					{
						delay(1);
						timecnt++;
						charge = PVI_Used[i].PVI_slot->measure();
					}
					PVI_Used[i].PVI_slot->charge_off();
					if (timecnt >= timeout)
					{
						mytext.text_in_box(40,10,"'dc_charge()' PVI timeout reached");
						exit(0);
					}
					break;
				default:
					mytext.text_in_box(40,10,"'dc_charge()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  

		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void  dc_charge_on_pvi(short pin)
{
	int i;
	short Source_type;

	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
		
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					PVI_Used[i].PVI_slot->charge_on();
					break;
				default:
					mytext.text_in_box(40,10,"'dc_charge_on()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  

		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void  dc_charge_off_pvi(short pin)
{
	int i;
	short Source_type;

	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
		
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					PVI_Used[i].PVI_slot->charge_off();
					break;
				default:
					mytext.text_in_box(40,10,"'dc_charge_off()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  

		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void  dc_drive_off_pvi(short pin)
{
	int i;
	short Source_type;

	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
		
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					PVI_Used[i].PVI_slot->drive_off();
					break;
				default:
					mytext.text_in_box(40,10,"'pvi_drive_off()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  
		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void  dc_drive_on_pvi(short pin)
{
	int i;
	short Source_type;

	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					PVI_Used[i].PVI_slot->drive_on();
					break;
				default:
					mytext.text_in_box(40,10,"'pvi_drive_on()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  
		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void dc_control_loop_pvi(short pin, short control_path,short mode)
{
	int i;
	short Source_type;

	
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)	
				{
				case NONE: break;	

				case PVI:
					switch (control_path)
					{
						case PV3_CURRENT:
							switch (mode)
							{
								case NORMAL:	PVI_Used[i].PVI_slot->current_normal();break;
								case FAST:		PVI_Used[i].PVI_slot->current_fast();break;
								default:
									mytext.text_in_box(40,10,"Unknown PVI CURRENT control loop mode");
									exit(0);
							}break;

						case PV3_VOLTAGE: 
							switch (mode)
							{
								case NORMAL:	PVI_Used[i].PVI_slot->voltage_normal();break;
								case FAST:		PVI_Used[i].PVI_slot->voltage_fast();break;
								default:
									mytext.text_in_box(40,10,"Unknown PVI VOLTAGE control loop mode");
									exit(0);
							}break;

						case PV3_COMPENSATE:
							switch (mode)
							{
								case SLOW:		PVI_Used[i].PVI_slot->slow_comp();break;
								case NORMAL:	PVI_Used[i].PVI_slot->normal_comp();break;
								case FAST:		PVI_Used[i].PVI_slot->fast_comp();break;
								default:
									mytext.text_in_box(40,10,"Unknown PVI COMPENSATE control loop mode");
									exit(0);
							}break;
						default:
							mytext.text_in_box(40,10,"Unknown PVI control loop path");
							exit(0);
					}
				break;
				default:
					mytext.text_in_box(40,10,"'dc_control_loop_pvi()' calls only valid for PVI pins");
					exit(0);
				}
			}
		}  
		
		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}



void dc_meas_mode_pvi(short pin, short mode, short wait_us)
{

	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case PVI:

				if(mode == MEASURE_VOLTAGE)
					PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_VOLTAGE);
				if(mode == MEASURE_CURRENT)
					PVI_Used[i].PVI_slot->set_meas_mode(PV3_MEASURE_CURRENT);


				wait.delay_10_us(int(wait_us/10));	
				break;
			default:
				mytext.text_in_box(40,10,"dc_meas_mode_pvi() only executable for PVI pins");
				exit(0);
			}
		}	
	
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void tmu_start_trigger_setup(short pin, double ref_level, char slope, char range)	
{
	tmu_start_trigger_setup(pin, float(ref_level), slope, range);
}

void tmu_start_trigger_setup(short pin, float ref_level, char slope, char range)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				switch (TMU_Used[i].TMU_channel)
				{
				case TMU_HIZ_DUT1:
				case TMU_HIZ_DUT2:
				case TMU_HIZ_DUT3:
				case TMU_HIZ_DUT4:
						TMU_Used[i].TMU_slot->start_trigger_setup(ref_level, slope, TMU_HIZ, range);
						break;
				case TMU_CHAN_A_DUT1:
				case TMU_CHAN_A_DUT2:
						TMU_Used[i].TMU_slot->start_trigger_setup(ref_level, slope, TMU_CHAN_A, range);
						break;
				case TMU_CHAN_B_DUT1:
				case TMU_CHAN_B_DUT2:
						TMU_Used[i].TMU_slot->start_trigger_setup(ref_level, slope, TMU_CHAN_B, range);
						break;
				}

			break;

			case QTMU1:
				switch (QTMU1_Used[i].QTMU1_channel)
				{
				case QTMU1_HIZ_DUT1:
				case QTMU1_HIZ_DUT2:
				case QTMU1_HIZ_DUT3:
				case QTMU1_HIZ_DUT4:
						QTMU1_Used[i].QTMU1_slot->qtmu1_start_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_HIZ, range);
						break;
				case QTMU1_CHAN_A_DUT1:
				case QTMU1_CHAN_A_DUT2:
						QTMU1_Used[i].QTMU1_slot->qtmu1_start_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_CHAN_A, range);
						break;
				case QTMU1_CHAN_B_DUT1:
				case QTMU1_CHAN_B_DUT2:
						QTMU1_Used[i].QTMU1_slot->qtmu1_start_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_CHAN_B, range);
						break;
				}

			break;

			default:
				mytext.text_in_box(40,10,"tmu_start_trigger_setup() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void tmu_stop_trigger_setup(short pin, double ref_level, char slope, char range)	
{
	tmu_stop_trigger_setup(pin, float(ref_level), slope, range);
}

void tmu_stop_trigger_setup(short pin, float ref_level, char slope, char range)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				switch (TMU_Used[i].TMU_channel)
				{
				case TMU_HIZ_DUT1:
				case TMU_HIZ_DUT2:
				case TMU_HIZ_DUT3:
				case TMU_HIZ_DUT4:
						TMU_Used[i].TMU_slot->stop_trigger_setup(ref_level, slope, TMU_HIZ, range);
						break;
				case TMU_CHAN_A_DUT1:
				case TMU_CHAN_A_DUT2:
						TMU_Used[i].TMU_slot->stop_trigger_setup(ref_level, slope, TMU_CHAN_A, range);
						break;
				case TMU_CHAN_B_DUT1:
				case TMU_CHAN_B_DUT2:
						TMU_Used[i].TMU_slot->stop_trigger_setup(ref_level, slope, TMU_CHAN_B, range);
						break;
				}

				break;

			case QTMU1:
				switch (QTMU1_Used[i].QTMU1_channel)
				{
				case QTMU1_HIZ_DUT1:
				case QTMU1_HIZ_DUT2:
				case QTMU1_HIZ_DUT3:
				case QTMU1_HIZ_DUT4:
						QTMU1_Used[i].QTMU1_slot->qtmu1_stop_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_HIZ, range);
						break;
				case QTMU1_CHAN_A_DUT1:
				case QTMU1_CHAN_A_DUT2:
						QTMU1_Used[i].QTMU1_slot->qtmu1_stop_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_CHAN_A, range);
						break;
				case QTMU1_CHAN_B_DUT1:
				case QTMU1_CHAN_B_DUT2:
						QTMU1_Used[i].QTMU1_slot->qtmu1_stop_trigger_setup(QTMU1_Used[i].QTMU1_unit,ref_level, slope, QTMU1_CHAN_B, range);
						break;
				}

				break;

			default:
				mytext.text_in_box(40,10,"tmu_stop_trigger_setup() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void tmu_arm(short pin,unsigned char ext_en, unsigned char ext_slope, unsigned char counter_reset)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				if (ext_en)		
					TMU_Used[i].TMU_slot->arm(ext_en, ext_slope, counter_reset);
				else
					TMU_Used[i].TMU_slot->arm();
				break;

			case QTMU1:
				if (ext_en)	
					QTMU1_Used[i].QTMU1_slot->qtmu1_arm(QTMU1_Used[i].QTMU1_unit,ext_en, ext_slope, counter_reset);
				else
					QTMU1_Used[i].QTMU1_slot->qtmu1_arm(QTMU1_Used[i].QTMU1_unit);
				break;

			default:
				mytext.text_in_box(40,10,"tmu_arm() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);
}

void tmu_arm_external(short pin,char slope, double threshold, unsigned char counter_reset)
{
	

	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				if (threshold > 0)
					TMU_Used[i].TMU_slot->open_switch(ARM_REF_POSITIVE);
				else
					TMU_Used[i].TMU_slot->close_switch(ARM_REF_POSITIVE);
				threshold = fabs(threshold);
			
				if(threshold>(float)(10 V)) threshold=(float)(10 V);	
				
				
			
				
			
	
				TMU_Used[i].TMU_slot->write_register(TMU_ARM_REF, (int)(0.5+fabs(threshold)/(float)(10 V)*4096*16)); 

			
	
			
			
				if (slope == POS_SLOPE) 
					TMU_Used[i].TMU_slot->arm(TRUE,TRUE,counter_reset);
				else
					if (slope == NEG_SLOPE)
						TMU_Used[i].TMU_slot->arm(TRUE,FALSE,counter_reset);
					else
					{
						mytext.text_in_box(40,10,"invalid slope for tmu_arm_external() command");
						exit(0);
					}
				break;

			case QTMU1:
				if (threshold >= 0)
					threshold = threshold + 0.5;
			
				else
					threshold = threshold - 0.5;
			
				threshold = fabs(threshold);
			

				
			
			
				
				
			

				QTMU1_Used[i].QTMU1_slot->qtmu1_set_arm_ref(QTMU1_Used[i].QTMU1_unit,threshold);


			
		
				

				if (slope == QTMU1_POS_SLOPE) 
					QTMU1_Used[i].QTMU1_slot->qtmu1_arm(QTMU1_Used[i].QTMU1_unit,TRUE,TRUE,counter_reset);
				else
					if (slope == QTMU1_NEG_SLOPE)
						QTMU1_Used[i].QTMU1_slot->qtmu1_arm(QTMU1_Used[i].QTMU1_unit,TRUE,FALSE,counter_reset);
					else
					{
						mytext.text_in_box(40,10,"invalid slope for tmu_arm_external() command");
						exit(0);
					}
				break;

			default:
				mytext.text_in_box(40,10,"tmu_arm_external() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void tmu_self_arm(short pin, short mode, unsigned char sigle, unsigned char ext_positive)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QTMU1:
				QTMU1_Used[i].QTMU1_slot->qtmu1_self_arm(QTMU1_Used[i].QTMU1_unit,(QTMU1_SELF_ARM_MODE_e)mode, sigle, ext_positive);
				break;

			default:
				mytext.text_in_box(40,10,"qtmu1_arm() only executable for QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);
}


void tmu_read(short pin, float *res_ptr , double timeout)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				res_ptr[i] = TMU_Used[i].TMU_slot->read(timeout);
				break;

			case QTMU1:
				res_ptr[i] = QTMU1_Used[i].QTMU1_slot->qtmu1_read((QTMU1_UNIT_ID_e)QTMU1_Used[i].QTMU1_unit,timeout);
				break;

			default:
				mytext.text_in_box(40,10,"tmu_read() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void tmu_self_arm_read(short pin, float *res_ptr , double timeout)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QTMU1:
				QTMU1_Used[i].QTMU1_slot->qtmu1_self_arm_read((QTMU1_UNIT_ID_e)QTMU1_Used[i].QTMU1_unit,res_ptr[i],timeout);
				break;

			default:
				mytext.text_in_box(40,10,"qtmu1_read() only executable for QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}


void tmu_self_arm_read(short pin, sfloat_wf res_ptr, int *size)
{
	int i;
	short Source_type;


	DYN_GROUP_LIST *pin_ptr;
	
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QTMU1:
				QTMU1_Used[i].QTMU1_slot->qtmu1_self_arm_read((QTMU1_UNIT_ID_e)QTMU1_Used[i].QTMU1_unit,res_ptr[i],size[i]);
				break;

			default:
				mytext.text_in_box(40,10,"qtmu1_read() only executable for QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	
	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void tmu_time_holdoff(short pin, double stop_ho, double start_ho)	
{
	tmu_time_holdoff(pin, float(stop_ho), float(start_ho));
}

void tmu_time_holdoff(short pin, float stop_ho, float start_ho)	
{




	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	char ErrorMessage[100];
	
	if(stop_ho==0)			
		start_ho=0.0f;		
	else
	{
		if(start_ho<(float)(800 nS)) 
		{
			start_ho=(float)(800 nS);					
			sprintf(ErrorMessage,"Invalid Start Holdoff time\nStart Holdoff set to min=800ns");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		if(start_ho>(float)(655.840 uS)) 
		{
			start_ho=(float)(655.840 uS);				
			sprintf(ErrorMessage,"Invalid Start Holdoff time\nStart Holdoff set to max=655.840us");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}
		
		if(stop_ho<fabs(start_ho)+(float)(800 nS)) 
		{
			stop_ho=fabs(start_ho)+(float)(800 nS);		
			sprintf(ErrorMessage,"Invalid Stop Holdoff time\nStop Holdoff set to min=%e", stop_ho);
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		if(stop_ho>fabs(start_ho)+(float)(655.840 uS)) 
		{
			stop_ho=fabs(start_ho)+(float)(655.840 uS);	
			sprintf(ErrorMessage,"Invalid Stop Holdoff time\nStop Holdoff set to max=%e", stop_ho);
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		stop_ho=fabs(stop_ho)-fabs(start_ho);
	}

	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				TMU_Used[i].TMU_slot->start_holdoff(fabs(start_ho),false);
				TMU_Used[i].TMU_slot->stop_holdoff(fabs(stop_ho),false);
				break;

			case QTMU1:
				QTMU1_Used[i].QTMU1_slot->qtmu1_start_holdoff(QTMU1_Used[i].QTMU1_unit,fabs(start_ho),false);
				QTMU1_Used[i].QTMU1_slot->qtmu1_stop_holdoff(QTMU1_Used[i].QTMU1_unit,fabs(stop_ho),false);
				break;

			default:
				mytext.text_in_box(40,10,"qtmu1_time_holdoff() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void tmu_event_holdoff(short pin, unsigned short stop_ho, unsigned short start_ho)	
{
	
	
	
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	char ErrorMessage[100];
	
	if(stop_ho==0)		
		start_ho=0;		
	else
	{
		if(start_ho<5) 
		{
			start_ho=5;		
			sprintf(ErrorMessage,"Invalid Start Holdoff time\nStart Holdoff set to min=5");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		if(start_ho>4099) 
		{
			start_ho=4099;	
			sprintf(ErrorMessage,"Invalid Start Holdoff time\nStart Holdoff set to max=4099");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		if(stop_ho<5) 
		{
			stop_ho=5;		
			sprintf(ErrorMessage,"Invalid Stop Holdoff time\nStop Holdoff set to min=5");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		if(stop_ho>4099) 
		{
			stop_ho=4099;	
			sprintf(ErrorMessage,"Invalid Stop Holdoff time\nStop Holdoff set to max=4099");
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}
	}

	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				if(stop_ho>0)
				{
					TMU_Used[i].TMU_slot->start_holdoff(start_ho,true);
					TMU_Used[i].TMU_slot->stop_holdoff(stop_ho,true);
				}
				else
				{
					TMU_Used[i].TMU_slot->start_holdoff(0,false);	
					TMU_Used[i].TMU_slot->stop_holdoff(0,false);
				}
				break;

			case QTMU1:
				if(stop_ho>0)
				{
					QTMU1_Used[i].QTMU1_slot->qtmu1_start_holdoff(QTMU1_Used[i].QTMU1_unit,start_ho,true);
					QTMU1_Used[i].QTMU1_slot->qtmu1_stop_holdoff(QTMU1_Used[i].QTMU1_unit,stop_ho,true);
				}
				else
				{
					QTMU1_Used[i].QTMU1_slot->qtmu1_start_holdoff(QTMU1_Used[i].QTMU1_unit,0,false);	
					QTMU1_Used[i].QTMU1_slot->qtmu1_stop_holdoff(QTMU1_Used[i].QTMU1_unit,0,false);
				}
				break;

			default:
				mytext.text_in_box(40,10,"qtmu1_event_holdoff() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void tmu_clear_holdoff(short pin)	
{
	

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	

	
	
	pin_ptr = group_selection(pin); 

	do
	{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
				case NONE: break;	

				case TMU:
					
					
					
					
					
					
					TMU_Used[i].TMU_slot->start_holdoff(0,false);	
					TMU_Used[i].TMU_slot->stop_holdoff(0,false);
					break;

				case QTMU1:
					
					
					
					
					
					
					QTMU1_Used[i].QTMU1_slot->qtmu1_start_holdoff(QTMU1_Used[i].QTMU1_unit,0,false);	
					QTMU1_Used[i].QTMU1_slot->qtmu1_stop_holdoff(QTMU1_Used[i].QTMU1_unit,0,false);
					break;

				default:
					mytext.text_in_box(40,10,"tmu_clear_holdoff() only executable for TMU or QTMU1 pins");
					exit(0);
				}
			}			
		}  
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void tmu_set_bit(short pin, bool logic_value)	
{
	int i;
	sbool s_logic_value;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) s_logic_value[i]=logic_value;

	tmu_set_bit(pin, s_logic_value);
}

void tmu_set_bit(short pin, sbool logic_value)	
{
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])	
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				if(TMU_Used[i].TMU_channel == TMU_IO1)
				{
					
					TMU_Used[i].TMU_slot->set_control(TMU_OUT_IO);
					
					if(logic_value[i]) 
						TMU_Used[i].TMU_slot->set_control(TMU_SET_IO1);
					else
						TMU_Used[i].TMU_slot->clear_control(TMU_SET_IO1);
				}
				else if(TMU_Used[i].TMU_channel == TMU_IO2)
				{
					
					TMU_Used[i].TMU_slot->set_control(TMU_OUT_IO);
					
					if(logic_value[i]) 
						TMU_Used[i].TMU_slot->set_control(TMU_SET_IO2);
					else
						TMU_Used[i].TMU_slot->clear_control(TMU_SET_IO2);
				}
				else
				{
					mytext.text_in_box(40,10,"Invalid TMU channel");
					exit(0);
				}
				break;

			case QTMU1:
				if(QTMU1_Used[i].QTMU1_channel == QTMU1_IO1)
				{
					
					QTMU1_Used[i].QTMU1_slot->qtmu1_set_control(QTMU1_Used[i].QTMU1_unit,QTMU1_OUT_IO);
					
					if(logic_value[i]) 
						QTMU1_Used[i].QTMU1_slot->qtmu1_set_control(QTMU1_Used[i].QTMU1_unit,QTMU1_SET_IO1);
					else
						QTMU1_Used[i].QTMU1_slot->qtmu1_clear_control(QTMU1_Used[i].QTMU1_unit,QTMU1_SET_IO1);
				}
				else if(QTMU1_Used[i].QTMU1_channel == QTMU1_IO2)
				{
					
					QTMU1_Used[i].QTMU1_slot->qtmu1_set_control(QTMU1_Used[i].QTMU1_unit,QTMU1_OUT_IO);
					
					if(logic_value[i]) 
						QTMU1_Used[i].QTMU1_slot->qtmu1_set_control(QTMU1_Used[i].QTMU1_unit,QTMU1_SET_IO2);
					else
						QTMU1_Used[i].QTMU1_slot->qtmu1_clear_control(QTMU1_Used[i].QTMU1_unit,QTMU1_SET_IO2);
				}
				else
				{
					mytext.text_in_box(40,10,"Invalid QTMU1 channel");
					exit(0);
				}
				break;
			
			default:
				mytext.text_in_box(40,10,"tmu_set_bit() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}
				 
void tmu_get_bit(short pin, bool *res_ptr)	
{
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])	
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				if(TMU_Used[i].TMU_channel == TMU_IO1)
				{
					
					TMU_Used[i].TMU_slot->clear_control(TMU_OUT_IO);
					
					*(res_ptr+i)=(bool)(TMU_Used[i].TMU_slot->get_status()&TMU_IO1);
				}
				else if(TMU_Used[i].TMU_channel == TMU_IO2)
				{
					
					TMU_Used[i].TMU_slot->clear_control(TMU_OUT_IO);
					
					*(res_ptr+i)=(bool)(TMU_Used[i].TMU_slot->get_status()&TMU_IO2);
				}
				else
				{
					mytext.text_in_box(40,10,"Invalid TMU channel");
					exit(0);
				}
				break;

			case QTMU1:
				if(QTMU1_Used[i].QTMU1_channel == QTMU1_IO1)
				{
					
					QTMU1_Used[i].QTMU1_slot->qtmu1_clear_control(QTMU1_Used[i].QTMU1_unit,QTMU1_OUT_IO);
					
					*(res_ptr+i)=(bool)(QTMU1_Used[i].QTMU1_slot->qtmu1_get_status((QTMU1_UNIT_ID_e)QTMU1_Used[i].QTMU1_unit)&QTMU1_IO1);
				}
				else if(QTMU1_Used[i].QTMU1_channel == QTMU1_IO2)
				{
					
					QTMU1_Used[i].QTMU1_slot->qtmu1_clear_control(QTMU1_Used[i].QTMU1_unit,QTMU1_OUT_IO);
					
					*(res_ptr+i)=(bool)(QTMU1_Used[i].QTMU1_slot->qtmu1_get_status((QTMU1_UNIT_ID_e)QTMU1_Used[i].QTMU1_unit)&QTMU1_IO2);
				}
				else
				{
					mytext.text_in_box(40,10,"Invalid QTMU1 channel");
					exit(0);
				}
				break;

			default:
				mytext.text_in_box(40,10,"tmu_get_bit() only executable for TMU or QTMU1 pins");
				exit(0);
			}
		}	
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}
				 

int dc_charge_lzb(short pin, float voltage_limit, long int timeout)
{
	
	

	int i;
	short Source_type;
	long int timecnt;
	float charge;
	DYN_GROUP_LIST *pin_ptr;
	int err=0;
	
	
	pin_ptr = group_selection(pin); 

	do
	{
		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
					case NONE: break;	

					case LZB:	
						LZB_Used[i].LZB_slot->set_meas_mode(LZB_CAP_VOLTAGE);
						delay(1);
						timecnt = 0;
						charge = LZB_Used[i].LZB_slot->measure();

						while ((charge < voltage_limit) && (timecnt < timeout))
						{
							delay(1);
							timecnt++;
							charge = LZB_Used[i].LZB_slot->measure();
						}
						if (timecnt >= timeout)
						{
							mytext.text_in_box(40,10,"'dc_charge_lzb()' LZB not charged");
							err=1;
							return err;
						}
		
						
						
					
				
					break;
					default:
						mytext.text_in_box(40,10,"dc_charge_lzb() only executable for LZB pins");
						exit(0);
				} 
			}	
		}  
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
	return err;
}

void assign_zener_lzb(short zener_pin, unsigned short bit)
{
	DYN_GROUP_LIST *lzb_zener_ptr;

	lzb_zener_ptr = lzb_zener_list;

	unsigned short size = sizeof_list(lzb_zener_ptr);	
	if (bit >= size) {
		mytext.text_in_box(40,10,"assign_zener_lzb() cannot set bit value");
		exit(0);
	}
	while (size != bit+1) {
		lzb_zener_ptr = lzb_zener_ptr->nextptr;
		size--;
	}
	lzb_zener_ptr->grouppin = zener_pin;
}

void tag_zener_lzb(unsigned int dec_value, int site)
{
	DYN_GROUP_LIST *lzb_zener_ptr;
	unsigned int bit;

	if (site > MAX_SITES) {
		mytext.text_in_box(40,10,"tag_zener_lzb(): site value exceeds limit");
		exit(0);
	}

	lzb_zener_ptr = lzb_zener_list;

	unsigned int size = sizeof_list(lzb_zener_ptr);
	if (dec_value >= (unsigned int)(1 << size)) {
		mytext.text_in_box(40,10,"tag_zener_lzb(): decimal value exceeds limit");
		exit(0);
	}
	
	free_list(&lzb_fuse_list[site]); 

	bit=size;
	do {
		bit--;
		if ((dec_value & (1 << bit)) == (unsigned int)(1 << bit))
			attach_element(&lzb_fuse_list[site],lzb_zener_ptr->grouppin);
		lzb_zener_ptr = lzb_zener_ptr->nextptr;
	} while (bit != 0);
}

void set_clamp_lzb(short pin, float clamp_voltage, short mode)
{
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	
	pin_ptr = group_selection(pin); 

	do
	{
		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
					case NONE: break;	
	
					case LZB:
						switch (mode) {
							case CLOSE:
								LZB_Used[i].LZB_slot->close_relay(LZB_CONN_CLAMP);
								LZB_Used[i].LZB_slot->set_clamp(clamp_voltage);
								break;
							case OPEN: 
								LZB_Used[i].LZB_slot->set_clamp(0.0);
								LZB_Used[i].LZB_slot->open_relay(LZB_CONN_CLAMP);
								break;
							default:
								mytext.text_in_box(40,10,"set_clamp_lzb() unknown mode");
								exit(0);
								break;
						}
					break;
					default:
						mytext.text_in_box(40,10,"set_clamp_lzb() only executable for LZB pins");
						exit(0);
				} 
			}	
		}  
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void dc_force_lzb(short pin, float current, float voltage, unsigned short pulse_time ,short mode , float *res_ptr, int site)
{
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	
	if (mode == MEASURE_VOLTAGE)
		mode = LZB_OUTPUT_VOLTAGE;
	if (mode == MEASURE_CURRENT)
		mode = LZB_OUTPUT_CURRENT;
	
	
	pin_ptr = group_selection(pin); 

	do
	{
		pin = pin_ptr->grouppin;
		for( i = 0; i < max_sites ; i++ )
		{
			if ((active_site[i]) && ((site == -1) || (i==site)))
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
					case NONE: break;	
	
					case LZB:
						LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
						LZB_Used[i].LZB_slot->set_current(current);
						if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
							LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel);		
						if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
							LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel_2);	
						LZB_Used[i].LZB_slot->set_meas_mode(mode);
						delay(LZB_RELAY_SETUP_DELAY);
						LZB_Used[i].LZB_slot->set_voltage(voltage);		
						wait.delay_10_us(pulse_time/10);				 
						res_ptr[i] = LZB_Used[i].LZB_slot->measure();	
						LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
						if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
							LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel);		
						if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
							LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel_2);	
						break;
					default:
						mytext.text_in_box(40,10,"dc_force_lzb() only executable for LZB pins");
						exit(0);
				} 
			}	
		}  
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}


void do_zapping_lzb(float current, float voltage, unsigned short pulse_time ,short mode , sfloat *res_ptr)
{
	int i;

	DYN_GROUP_LIST *pin_ptr;
	
	
	if (mode == MEASURE_VOLTAGE)
		mode = LZB_OUTPUT_VOLTAGE;
	if (mode == MEASURE_CURRENT)
		mode = LZB_OUTPUT_CURRENT;
	
	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{

			for (int zap_iter = 0; zap_iter < sizeof_list(lzb_fuse_list[i]); zap_iter++) {
				pin_ptr = lzb_fuse_list[i];
				pin_selection(pin_ptr[i].grouppin, i); 
			
				LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
				LZB_Used[i].LZB_slot->set_current(current);
	
				if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
					LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel);		
				if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
					LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel_2);	
				LZB_Used[i].LZB_slot->set_meas_mode(mode);
				delay(LZB_RELAY_SETUP_DELAY);
				LZB_Used[i].LZB_slot->set_voltage(voltage);		
				wait.delay_10_us(pulse_time/10);				 
				res_ptr[zap_iter][i] = LZB_Used[i].LZB_slot->measure();	
				LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
				if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
					LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel);		
				if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
					LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel_2);	
				pin_ptr = pin_ptr->nextptr;
			}
		}	
	}  
}

int dc_zap_lzb(short pin, float current, float voltage, float pulse_time, suint tag_list, short mode , bool err_if_is_greater_than, float par_limit)  
{
	DYN_GROUP_LIST *pin_ptr;
	int zener_list_size=0;
	int	failing_sites=0;
	sfloat *result;

	
	pin_ptr = group_selection(pin); 
	zener_list_size=sizeof_list(pin_ptr);
	result=(sfloat *)malloc(zener_list_size*sizeof(sfloat));

	failing_sites=dc_zap_lzb(pin, current, voltage, pulse_time, tag_list, mode, err_if_is_greater_than, par_limit, result, NULL, NULL);  
	free(result);

	return failing_sites;
}

int dc_zap_lzb(short pin, float current, float voltage, float pulse_time, suint tag_list, short mode , bool err_if_is_greater_than, float par_limit, sfloat *result, sfloat *result2, sfloat *zap_time)  
{
	int i=0;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *local_pin_ptr;
	DYN_GROUP_LIST *zener_list=NULL;
	DYN_GROUP_LIST *fuse_list[MAX_SITES]={0};
	sfloat *res1,*res2=NULL,*z_time=NULL;
	unsigned int fuse_index=0;
	unsigned int zener_index=0;
	int zener_list_size=0;
	unsigned int bit;

	int	failing_sites=0;
	CMicroTimer LocalTimer;
	bool not_yet_blown=true;
	float ElapsedTime;

	
	pin_ptr = group_selection(pin); 
	zener_list_size=sizeof_list(pin_ptr);

	res1=(sfloat *)malloc(zener_list_size*sizeof(sfloat));
	if(result2 != NULL)
		res2=(sfloat *)malloc(zener_list_size*sizeof(sfloat));	
	if(zap_time != NULL)
		z_time=(sfloat *)malloc(zener_list_size*sizeof(sfloat));
	

	local_pin_ptr = pin_ptr;
	do
	{
		pin = local_pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
					case NONE: break;	

					case LZB:
					
					break;
					default:
						mytext.text_in_box(40,10,"dc_zap_lzb () only executable for LZB pins");
						exit(0);
				} 
			}	
		}  
		local_pin_ptr = local_pin_ptr->nextptr;
	}  while (local_pin_ptr != NULL);	
	
	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		if (tag_list[i] >= pow(2.0,(double)zener_list_size))	
		{
			mytext.text_in_box(40,10,"dc_zap_lzb (): tag list exeeds limit");
			exit(0);
		}

		local_pin_ptr = pin_ptr;
		bit=zener_list_size;

		
		fuse_list[i]=NULL;  

		do 
		{
			bit--;
			if ((tag_list[i]&(0x1<<bit))==(unsigned int)(0x1<<bit))	
				attach_element(&fuse_list[i],local_pin_ptr->grouppin);
			local_pin_ptr = local_pin_ptr->nextptr;
		} while (bit != 0);
	}

	
	
	if (mode == MEASURE_VOLTAGE)
		mode = LZB_OUTPUT_VOLTAGE;
	if (mode == MEASURE_CURRENT)
		mode = LZB_OUTPUT_CURRENT;
	

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			local_pin_ptr = fuse_list[i];	

			for (fuse_index = 0; fuse_index < (unsigned int)sizeof_list(fuse_list[i]); fuse_index++) 
			{
				pin_selection(local_pin_ptr->grouppin, i); 
			
				LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
				LZB_Used[i].LZB_slot->set_current(current);
			
				if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
					LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel);		
				if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
					LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel_2);	
				LZB_Used[i].LZB_slot->set_meas_mode(mode);
				delay(LZB_RELAY_SETUP_DELAY);
				LZB_Used[i].LZB_slot->set_voltage(voltage);		
			
				not_yet_blown=true;
				ElapsedTime=0;
				LocalTimer.Start();
				while(not_yet_blown && (ElapsedTime<pulse_time))
				{
				
				
					wait.delay_10_us(10);				
					res1[fuse_index][i] = LZB_Used[i].LZB_slot->measure();	
					if( 
					   (( err_if_is_greater_than)&&(res1[fuse_index][i]<=par_limit)) ||
					   ((!err_if_is_greater_than)&&(res1[fuse_index][i]>=par_limit))
					  )
						 not_yet_blown=false;
					ElapsedTime=LocalTimer.GetElapsedTime()*(float)(1 uS);
				}

				if(res2!=NULL)	
				{				
					if (mode == LZB_OUTPUT_VOLTAGE)
						LZB_Used[i].LZB_slot->set_meas_mode(LZB_OUTPUT_CURRENT);
					if (mode == LZB_OUTPUT_CURRENT)
						LZB_Used[i].LZB_slot->set_meas_mode(LZB_OUTPUT_VOLTAGE);
		
					delay(LZB_RELAY_SETUP_DELAY);
					res2[fuse_index][i] = LZB_Used[i].LZB_slot->measure();	
				}

				if(z_time!=NULL)	
				{				
					z_time[fuse_index][i] = ElapsedTime;						
				}

				LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
				if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)					
					LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel);		
				if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
					LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel_2);	
				local_pin_ptr = local_pin_ptr->nextptr;
		}	
	}  


	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		fuse_index=0;
		for (zener_index=0; zener_index< (unsigned int)zener_list_size; zener_index++) if((tag_list[i]>>zener_index)&0x1) 
		{
			
			result[zener_index][i]=res1[fuse_index][i];
			if(result2 != NULL)
				result2[zener_index][i]=res2[fuse_index][i];

			if(zap_time != NULL)
				zap_time[zener_index][i]=z_time[fuse_index][i];
			

			if (mode == LZB_OUTPUT_VOLTAGE)
			{
				if(err_if_is_greater_than)
				{
					if(res1[fuse_index][i]>par_limit)
					{
						failing_sites=failing_sites|(0x1<<i);	
						printf("Site %i Bit %i - Post-zap voltage over limit\n", i, zener_index);
					}
				} else
				{
					if(res1[fuse_index][i]<par_limit)
					{
						failing_sites=failing_sites|(0x1<<i);	
						printf("Site %i Bit %i - Post-zap voltage under limit\n", i, zener_index);
					}
				}
			} else
			if (mode == LZB_OUTPUT_CURRENT)
			{
				if(err_if_is_greater_than)
				{
					if(res1[fuse_index][i]>par_limit)
					{
						failing_sites=failing_sites|(0x1<<i);	
						printf("Site %i Bit %i - Post-zap current over limit\n", i, zener_index);
					}
				} else
				{
					if(res1[fuse_index][i]<par_limit)
					{
						failing_sites=failing_sites|(0x1<<i);	
						printf("Site %i Bit %i - Post-zap current under limit\n", i, zener_index);
					}
				}
			}

			fuse_index++;
		}
	}


	free(res1);
	if(res2 != NULL)
		free(res2);
	if(z_time != NULL)
		free(z_time);
	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		free_list(&fuse_list[i]);  

	return failing_sites;
}

void dc_check_lzb(short pin, float current, float voltage, float meas_delay, short mode, sfloat *result)
{
	int i=0;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *local_pin_ptr;
	DYN_GROUP_LIST *zener_list=NULL;
	DYN_GROUP_LIST *fuse_list[MAX_SITES]={0};
	unsigned int fuse_index=0;
	unsigned int zener_index=0;
	int zener_list_size=0;
	unsigned int bit;
	int tag_list=0;


	
	pin_ptr = group_selection(pin); 
	zener_list_size=sizeof_list(pin_ptr);
	

	for(bit=0;bit<(unsigned int)zener_list_size; bit++)
		tag_list=(tag_list<<1)+1;

	
	local_pin_ptr = pin_ptr;
	do
	{
		pin = local_pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
					case NONE: break;	

					case LZB:
					
					break;
					default:
						mytext.text_in_box(40,10,"dc_check_lzb () only executable for LZB pins");
						exit(0);
				} 
			}	
		}  
		local_pin_ptr = local_pin_ptr->nextptr;
	}  while (local_pin_ptr != NULL);		
	
	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		local_pin_ptr = pin_ptr;

		
		fuse_list[i]=NULL;  

		
		for(bit=zener_list_size; bit>0; bit--)
		{
			attach_element(&fuse_list[i],local_pin_ptr->grouppin);
			local_pin_ptr = local_pin_ptr->nextptr;
		}
	}
	
	
	if (mode == MEASURE_VOLTAGE)
		mode = LZB_OUTPUT_VOLTAGE;
	if (mode == MEASURE_CURRENT)
		mode = LZB_OUTPUT_CURRENT;
	
	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		local_pin_ptr = fuse_list[i];
	
		for (fuse_index = 0; fuse_index < (unsigned int)sizeof_list(fuse_list[i]); fuse_index++)
		{
			pin_selection(local_pin_ptr->grouppin, i); 

			LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
			LZB_Used[i].LZB_slot->set_current(current);
		
			if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)
				LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel);		
			if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
				LZB_Used[i].LZB_slot->close_relay(LZB_Used[i].LZB_channel_2);
			LZB_Used[i].LZB_slot->set_meas_mode(mode);
			delay(LZB_RELAY_SETUP_DELAY);
			LZB_Used[i].LZB_slot->set_voltage(voltage);		
			wait.delay_10_us((int)(0.5+1.0e6*fabs(meas_delay)/10));			
			result[fuse_index][i] = LZB_Used[i].LZB_slot->measure();		
			LZB_Used[i].LZB_slot->set_voltage((float)(0.0));
			if (LZB_Used[i].LZB_channel != UNUSED_LZB_MUX_PIN)
				LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel);	
			if (LZB_Used[i].LZB_channel_2 != UNUSED_LZB_MUX_PIN)
				LZB_Used[i].LZB_slot->open_relay(LZB_Used[i].LZB_channel_2);
			local_pin_ptr = local_pin_ptr->nextptr;
		}	
	}  

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		free_list(&fuse_list[i]);  

}

void zap_word_select_lzb(sfloat trim_value, suint zap_word, float *weight_list, unsigned int *word_list, int list_lenght, unsigned int *idx)
{
	int site;
	int	i;

	
	for(site=0; site<CSC_LAST_SITE; site++) if (IS_SITE_ACTIVE)
	{
		i=0;
		while(i<(list_lenght-1)&&(-trim_value[site]>(weight_list[i]+weight_list[i+1])/2))
			i++;

		zap_word[site]=word_list[i];
		
		if(idx!=NULL)	
			idx[site]=i;
	}
}


void set_hvs_hotswitch(short pin, bool current_hs, bool voltage_hs)	
{


#ifndef	LegacyVATE522
	int i;
	short Source_type;
#endif
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

#ifndef	LegacyVATE522
	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case HVS:
				HVS_Used[i].HVS_slot->m_hot_switch_on_current_setting=current_hs;
				HVS_Used[i].HVS_slot->m_hot_switch_on_voltage_setting=voltage_hs;
			break;
			
			default:
				mytext.text_in_box(40,10,"set_hvs_hotswitch() not executable for this pin");
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
#else
	mytext.text_in_box(40,10,"set_hotswitch() not executable in this VATE version");
#endif

}

void set_hotswitch(short pin, bool current_hs, bool voltage_hs)	
{


#ifndef	LegacyVATE522
	int i;
	short Source_type;
#endif
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

#ifndef	LegacyVATE522
	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case HVS:
				HVS_Used[i].HVS_slot->m_hot_switch_on_current_setting=current_hs;
				HVS_Used[i].HVS_slot->m_hot_switch_on_voltage_setting=voltage_hs;
			break;
			
			case MVS:
				MVS_Used[i].MVS_slot->m_hot_switch_on_current_setting=current_hs;
				MVS_Used[i].MVS_slot->m_hot_switch_on_voltage_setting=voltage_hs;
			break;
			
			
			
		
			
			
			default:
				mytext.text_in_box(40,10,"set_hvs_hotswitch() not executable for this pin");
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);
#else
	mytext.text_in_box(40,10,"set_hotswitch() not executable in this VATE version");
#endif

}

void set_dvi_range_fast_switch(short pin, bool range_fast_switch)
{


	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
	
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case DVI:
			#ifndef	LegacyVATE531
				DVI_Used[i].DVI_slot->set_current_range_delay(!range_fast_switch);
			#else
				DVI_Used[i].DVI_slot->use_set_current_range_delay=!range_fast_switch;
			#endif
			break;
			
			default:
				mytext.text_in_box(40,10,"set_dvi_range_fast_switch() not executable for a non DVI pin");
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

}



void dc_init(short pin, float settling_time)	
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	bool	xvi_card_present=false;	
	bool	xvi_settling_time_enable=false;	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

 	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case DVI:
				DVI_Used[i].DVI_slot->init();
				DVI_Used[i].is_filter = true;
					break;

			case OVI:
			case OVI_S:
				OVI_Used[i].OVI_slot->init();
			break;

#ifndef LegacyXerxes
			case XVI:

			
				xvi_card_present=true;		
			
				if(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].card_ptr==NULL)
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].card_ptr=XVI_Used[i].XVI_slot;
				XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].init_due=true;

				
				if(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].card_ptr->card.xvi_image_force_voltage_mode!=XVI_FVM_LOW_VOLTAGE)
					xvi_settling_time_enable=true;
			break;
#endif
			case HVS:
				HVS_Used[i].HVS_slot->init();
			break;

			case OFS:
				OFS_Used[i].OFS_slot->init();
			break;

			case MVS:
				MVS_Used[i].MVS_slot->init();
			break;

			case PVI:
				PVI_Used[i].PVI_slot->init();
			break;

			case LZB:	
				LZB_Used[i].LZB_slot->init();
			break;

			case OAL:	
				oal_init(pin); 
			break;

			case QAL:	
				qal_init(pin); 
			break;

			case TMU:	
				tmu_init(pin); 
			break;

			case QTMU1:	
				tmu_init(pin); 
			break;

			case ACS:	
				acs_init(pin); 
			break;

			case DDD:	
				ddd_init();
			break;

			case OV2:	
				OV2_Used[i].OV2_slot->init();
				OV2_Used[i].is_filter = true;
			break;

			case CBT:	
				CBT_Used[i].CBT_slot->init();
			break;

			default:
				mytext.text_in_box(40,10,"init() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

#ifndef	LegacyXerxes

	int		slot;			
	if(xvi_card_present)	
		for(slot=0; slot<21; slot++) if(XVI_Card_Used[slot].init_due)
		{					
if(!debug_xvi_msl_offline)	
		XVI_Card_Used[slot].card_ptr->init();
		XVI_Card_Used[slot].init_due	= false;


		XVI_Card_Used[slot].arm_mask			= 0x0;
		XVI_Card_Used[slot].card_arm_due		= false;
		XVI_Card_Used[slot].card_armed			= false;
		XVI_Card_Used[slot].bank_0_enabled		= false;
		XVI_Card_Used[slot].bank_1_enabled		= false;
		XVI_Card_Used[slot].sw_trigger			= false;
		XVI_Card_Used[slot].time_stamp_sw_trig	= 0.0;
		XVI_Card_Used[slot].measurement_duration= 0.0;
		XVI_Card_Used[slot].force_mask			= 0;
		XVI_Card_Used[slot].connect_mask		= 0;
		XVI_Card_Used[slot].block_current		= 0.0;
		XVI_Card_Used[slot].block_voltage		= 0.0;
		XVI_Card_Used[slot].block_irng			= -10000.0;
		XVI_Card_Used[slot].block_vrng			= -10000.0;
		XVI_Card_Used[slot].block_programming	= false;
		XVI_Card_Used[slot].fv_due				= false;
		}
	if(xvi_settling_time_enable)
		wait.delay_10_us((int)(0.5+settling_time/10.0e-6f));
#endif
}



void var_init(sfloat variable,float value)	
{

	int site;
	for( site = 0; site < max_sites ; site++ )
		if (active_site[site])
			variable[site] = value;
}

void var_init(sdouble variable,double value)	
{

	int site;
	for( site = 0; site < max_sites ; site++ )
		if (active_site[site])
			variable[site] = value;
}


void tmu_init(short pin)	
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case TMU:
				TMU_Used[i].TMU_slot->init();
			break;

			case QTMU1:
				QTMU1_Used[i].QTMU1_slot->init();
			break;

			default:
				mytext.text_in_box(40,10,"tmu_init() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void acs_init(short pin)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case ACS:
				ACS_Used[i].ACS_slot->init();
				ACS_Used[i].ACS_slot->set_meas_mode(ACS_CHANNEL_1, ACS_1V_RMS_RANGE, ACS_AC_COUPLING);
			break;

			default:
				mytext.text_in_box(40,10,"acs_init() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

	for( i = 0; i < 21 ; i++ )
	{
		ACS_Card_Used[i].ClkDivider=0;
		ACS_Card_Used[i].Voffset=0;
		ACS_Card_Used[i].Vpeak=0;
	}


}


void oal_init(short pin)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case OAL:
				OAL_Used[i].OAL_slot->init();
				OAL_Used[i].OAL_slot->set_ia_offset_dac(0);
				OAL_Used[i].OAL_slot->ch1_ia_offset_dac(0);
				OAL_Used[i].OAL_slot->set_int_dac_ch0 (3000);
				OAL_Used[i].OAL_slot->set_gain_dac_ch0(1000);
				OAL_Used[i].OAL_slot->set_int_dac_ch1 (3000);
				OAL_Used[i].OAL_slot->set_gain_dac_ch1(1000);
				OAL_Used[i].OAL_slot->set_output_voltage(0);

				OAL_Used[i].OAL_slot->close_relay(EXT_RLY_DRV);
				OAL_Used[i].OAL_slot->close_switch(DRV_1);
				OAL_Used[i].OAL_slot->open_relay(CH1_EXT_DRV);
			break;

			default:
				mytext.text_in_box(40,10,"oal_init() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void qal_init(short pin)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QAL:
				QAL_Used[i].QAL_slot->init();
				QAL_Used[i].QAL_slot->set_ia_offset_dac(0);
				QAL_Used[i].QAL_slot->ch1_ia_offset_dac(0);
				QAL_Used[i].QAL_slot->ch2_ia_offset_dac(0);
				QAL_Used[i].QAL_slot->ch3_ia_offset_dac(0);
				QAL_Used[i].QAL_slot->set_int_dac_ch0 (3000);
				QAL_Used[i].QAL_slot->set_gain_dac_ch0(1000);
				QAL_Used[i].QAL_slot->set_int_dac_ch1 (3000);
				QAL_Used[i].QAL_slot->set_gain_dac_ch1(1000);
				QAL_Used[i].QAL_slot->set_int_dac_ch2 (3000);
				QAL_Used[i].QAL_slot->set_gain_dac_ch2(1000);
				QAL_Used[i].QAL_slot->set_int_dac_ch3 (3000);
				QAL_Used[i].QAL_slot->set_gain_dac_ch3(1000);
				QAL_Used[i].QAL_slot->set_output_voltage(0);
		
				QAL_Used[i].QAL_slot->close_relay(QAL_EXT_RLY_DRV);
				QAL_Used[i].QAL_slot->close_switch(QAL_DRV_1);

			break;

			default:
				mytext.text_in_box(40,10,"qal_init() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void oal_set_compensation(short pin, int PoleStab, int ZeroStab)		
{
	int i;
	sint s_polestab;
	sint s_zerostab;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_polestab[i]=PoleStab;
			s_zerostab[i]=ZeroStab;
		}

	oal_set_compensation(pin, s_polestab, s_zerostab);
}

void qal_set_compensation(short pin, int PoleStab, int ZeroStab)		
{
	int i;
	sint s_polestab;
	sint s_zerostab;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_polestab[i]=PoleStab;
			s_zerostab[i]=ZeroStab;
		}

	qal_set_compensation(pin, s_polestab, s_zerostab);
}

void oal_set_compensation(short pin, int *PoleStab, int *ZeroStab)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case OAL:
				if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
				{
					OAL_Used[i].OAL_slot->set_int_dac_ch0 (PoleStab[i]);
					OAL_Used[i].OAL_slot->set_gain_dac_ch0(ZeroStab[i]);
				}
				else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
				{
					OAL_Used[i].OAL_slot->set_int_dac_ch1 (PoleStab[i]);
					OAL_Used[i].OAL_slot->set_gain_dac_ch1(ZeroStab[i]);
				}
				else
				{
					mytext.text_in_box(40,10,"oal_set_compensation() - Invalid OAL channel");
					exit(0);
				}
				OAL_Used[i].OAL_slot->open_switch(INT_RESET);
			break;

			default:
				mytext.text_in_box(40,10,"oal_set_compensation() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void qal_set_compensation(short pin, int *PoleStab, int *ZeroStab)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QAL:
				if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
				{
					QAL_Used[i].QAL_slot->set_int_dac_ch0 (PoleStab[i]);
					QAL_Used[i].QAL_slot->set_gain_dac_ch0(ZeroStab[i]);
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
				{
					QAL_Used[i].QAL_slot->set_int_dac_ch1 (PoleStab[i]);
					QAL_Used[i].QAL_slot->set_gain_dac_ch1(ZeroStab[i]);
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
				{
					QAL_Used[i].QAL_slot->set_int_dac_ch2 (PoleStab[i]);
					QAL_Used[i].QAL_slot->set_gain_dac_ch2(ZeroStab[i]);
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
				{
					QAL_Used[i].QAL_slot->set_int_dac_ch3 (PoleStab[i]);
					QAL_Used[i].QAL_slot->set_gain_dac_ch3(ZeroStab[i]);
				}
				else
				{
					mytext.text_in_box(40,10,"qal_set_compensation() - Invalid QAL channel");
					exit(0);
				}
				QAL_Used[i].QAL_slot->open_switch(QAL_INT_RESET);
			break;

			default:
				mytext.text_in_box(40,10,"qal_set_compensation() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void oal_get_compensation(short pin, int *PoleStab_ptr, int *ZeroStab_ptr)		
{

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case OAL:
				if (OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
				{
					PoleStab_ptr[i]=OAL_Used[i].OAL_slot->card.int_dac_ch0;
					ZeroStab_ptr[i]=OAL_Used[i].OAL_slot->card.gain_dac_ch0;
				}
				else if (OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
				{
					PoleStab_ptr[i]=OAL_Used[i].OAL_slot->card.int_dac_ch1;
					ZeroStab_ptr[i]=OAL_Used[i].OAL_slot->card.gain_dac_ch1;
				}
				else
				{
					mytext.text_in_box(40,10,"oal_get_compensation() - Invalid OAL channel");
					exit(0);
				}
				OAL_Used[i].OAL_slot->open_switch(INT_RESET);
			break;

			default:
				mytext.text_in_box(40,10,"oal_get_compensation() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void qal_get_compensation(short pin, int *PoleStab_ptr, int *ZeroStab_ptr)		
{
	
	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QAL:
				if (QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
				{
					PoleStab_ptr[i]=QAL_Used[i].QAL_slot->card.int_dac_ch0;
					ZeroStab_ptr[i]=QAL_Used[i].QAL_slot->card.gain_dac_ch0;
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
				{
					PoleStab_ptr[i]=QAL_Used[i].QAL_slot->card.int_dac_ch1;
					ZeroStab_ptr[i]=QAL_Used[i].QAL_slot->card.gain_dac_ch1;
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
				{
					PoleStab_ptr[i]=QAL_Used[i].QAL_slot->card.int_dac_ch2;
					ZeroStab_ptr[i]=QAL_Used[i].QAL_slot->card.gain_dac_ch2;
				}
				else if (QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
				{
					PoleStab_ptr[i]=QAL_Used[i].QAL_slot->card.int_dac_ch3;
					ZeroStab_ptr[i]=QAL_Used[i].QAL_slot->card.gain_dac_ch3;
				}
				else
				{
					mytext.text_in_box(40,10,"qal_get_compensation() - Invalid QAL channel");
					exit(0);
				}
				QAL_Used[i].QAL_slot->open_switch(QAL_INT_RESET);
			break;

			default:
				mytext.text_in_box(40,10,"qal_get_compensation() not executable for this pin");
				exit(0);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	
}

void oal_read_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{
	

	
	
	
	
	
	
	
	
	
	
	

	int i;
	sfloat zero_null_single_pin[1]={0.0};

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;	

		case OAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "oal_read_ia_offset() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			if(pin_ptr->nextptr!=NULL) 
			{
				char err_message[100];
				sprintf(err_message, "When oal_read_ia_offset() is called with a list of pins an array of sfloat must be provided");
				mytext.text_in_box(40,10,err_message);
				return;
			}
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "oal_read_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
		}
	}
		
	
	oal_read_ia_offset(pin, ia_range, zero_null_single_pin, use_internal_short_rly, reject_50Hz, nsamples);

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		zero_null[i]=zero_null_single_pin[0][i];

}

void qal_read_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{
	

	
	
	
	
	
	
	
	
	
	
	

	int i;
	sfloat zero_null_single_pin[1]={0.0};

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;	

		case QAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "qal_read_ia_offset() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			if(pin_ptr->nextptr!=NULL) 
			{
				char err_message[100];
				sprintf(err_message, "When qal_read_ia_offset() is called with a list of pins an array of sfloat must be provided");
				mytext.text_in_box(40,10,err_message);
				return;
			}
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "qal_read_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
		}
	}
		
	
	qal_read_ia_offset(pin, ia_range, zero_null_single_pin, use_internal_short_rly, reject_50Hz, nsamples);

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		zero_null[i]=zero_null_single_pin[0][i];

}

void oal_read_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{
	

	
	
	
	
	
	
	
	
	
	
	

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int		doal_cal_rng_index;	
	int i;
	int n;
	float scale_doal_ia_range;
	CMicroTimer LocalTimer20ms;
	float	LocalElapsedTime;
	int		LocalTrailTime_10us;

	pin_ptr = group_selection(pin); 
	start_pin_ptr = pin_ptr;		

	switch (ia_range)
	{
	case RANGE_100_MV:		
		break;
	case RANGE_10_MV:		
		doal_cal_rng_index=2;
		break;
	case RANGE_1_MV:		
		doal_cal_rng_index=1;
		break;
	case RANGE_100_UV:		
		doal_cal_rng_index=0;
		break;
	default:
		mytext.text_in_box(40,10,"oal_read_ia_offset(): not a valid range");
		return;
	}
		
	pin_ptr = start_pin_ptr; 
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{

		Source_type=pin_selection(pin,i);
		
		switch(Source_type)
		{
		case NONE: break;	

		case OAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "oal_read_ia_offset() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			switch (ia_range)
			{
			case RANGE_100_MV:		
				doal_cal_rng_index=3;
				scale_doal_ia_range = float(100 mV)/32768;
				OAL_Used[i].OAL_slot->close_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV);
				break;
			case RANGE_10_MV:		
				doal_cal_rng_index=2;
				scale_doal_ia_range = float(10 mV)/32768;
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->close_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			case RANGE_1_MV:		
				doal_cal_rng_index=1;
				scale_doal_ia_range = float(1 mV)/32768;
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->close_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			case RANGE_100_UV:		
				doal_cal_rng_index=0;
				scale_doal_ia_range = float(100 uV)/32768;
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			default:
				mytext.text_in_box(40,10,"oal_read_ia_offset(): not a valid range");
				return;
			}

			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
			{
				
			
				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])	
				{
					OAL_Used[i].OAL_slot->set_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]);
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]<0)
						OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
					else
						OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
				}
		
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]=0;
			} else

			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
			{
				
				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
				{
					OAL_Used[i].OAL_slot->ch1_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]);
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]<0)
						OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
					else
						OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);
				}
			
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]=0;
			} else

			{
				char err_message[100];
				sprintf(err_message, "oal_read_ia_offset() invlid channel for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}


			OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
			OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
			OAL_Used[i].OAL_slot->close_switch(IA_POS_IN);
			OAL_Used[i].OAL_slot->close_switch(IA_NEG_IN);
			if(use_internal_short_rly)
				OAL_Used[i].OAL_slot->close_relay(DUT_INP_SHORT);
			
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "oal_read_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	delay(2);
	if(ia_range==RANGE_100_UV) delay(5);

	float CheckAvWindow;
	CMicroTimer LocalTimerCheckAvWindow;
	LocalTimerCheckAvWindow.Start();
	if(reject_50Hz)		
		for(n=0; n<nsamples; n++)
		{
			
			LocalTimer20ms.Start();
			
			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;


			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==OAL)	
					if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);			
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
			
			wait.delay_10_us(100);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==OAL)	
					if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

		
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==OAL)	
					if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
			
			wait.delay_10_us(100);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==OAL)	
					if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
			
			LocalElapsedTime=LocalTimer20ms.GetElapsedTime()*(float)(1 uS);

			
			LocalTrailTime_10us=abs((int)(0.5+1.0e6*((1.0f/CSC_POWER_FREQ)/nsamples-LocalElapsedTime)/10));

			
			if(LocalTrailTime_10us<1) LocalTrailTime_10us=1;
			if(LocalTrailTime_10us>1000) LocalTrailTime_10us=1000;
			
			
			wait.delay_10_us(LocalTrailTime_10us-1);

		} 
	else
		{
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
					OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);			
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0) for(n=0; n<nsamples; n++)
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
					OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1) for(n=0; n<nsamples; n++)
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

		} 

	CheckAvWindow=LocalTimerCheckAvWindow.GetElapsedTime()*(float)(1 uS);

	if(reject_50Hz&&((CheckAvWindow<(float)(19 mS))||(CheckAvWindow>(float)(21 mS))))
	{
		char err_message[100];
		sprintf(err_message, "oal_read_ia_offset() impossible to reject 50Hz",Pin_Type_Used[pin][i].Pin_Name);
		mytext.text_in_box(40,10,err_message);
	}		


	pin_ptr = start_pin_ptr; 
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		
		Source_type=pin_selection(pin,i);
		if(Source_type==OAL)
		{
			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]=((float)(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index])/nsamples-32768)*scale_doal_ia_range;
			else
			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]=((float)(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index])/nsamples-32768)*scale_doal_ia_range;

	
			if(use_internal_short_rly)
				OAL_Used[i].OAL_slot->open_relay(DUT_INP_SHORT);
		}
	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);
			
			
	

	
	
	
	int list_depth=0;
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	float ZeroNull_sign=0.0;

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
			{
				if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
					ZeroNull_sign=-1.0f;	
				else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
					ZeroNull_sign=1.0f;		

				
				zero_null[list_depth-1-n][i]=999;
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
					zero_null[list_depth-1-n][i]=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]*ZeroNull_sign;
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
					zero_null[list_depth-1-n][i]=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]*ZeroNull_sign;
			}
		}
		pin_ptr = pin_ptr->nextptr;
	}
}

void qal_read_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, int nsamples, bool reject_50Hz, bool use_internal_short_rly)
{


	











	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int		qoal_cal_rng_index;
	int i;
	int n;
	float scale_qoal_ia_range;
	CMicroTimer LocalTimer20ms;
	float	LocalElapsedTime;
	int		LocalTrailTime_10us;

	pin_ptr = group_selection(pin); 
	start_pin_ptr = pin_ptr;	

	switch (ia_range)
	{
	case RANGE_100_MV:	
		break;
	case RANGE_10_MV:		
		qoal_cal_rng_index=2;
		break;
	case RANGE_1_MV:		
		qoal_cal_rng_index=1;
		break;
	case RANGE_100_UV:		
		qoal_cal_rng_index=0;
		break;
	default:
		mytext.text_in_box(40,10,"qal_read_ia_offset(): not a valid range");
		return;
	}
		
	pin_ptr = start_pin_ptr; 
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		
		Source_type=pin_selection(pin,i);
		
		switch(Source_type)
		{
		case NONE: break;	

		case QAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "qal_read_ia_offset() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			switch (ia_range)
			{
			case RANGE_100_MV:		
				qoal_cal_rng_index=3;
				scale_qoal_ia_range = float(100 mV)/32768;
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_10_MV:		
				qoal_cal_rng_index=2;
				scale_qoal_ia_range = float(10 mV)/32768;
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_1_MV:		
				qoal_cal_rng_index=1;
				scale_qoal_ia_range = float(1 mV)/32768;
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_100_UV:		
				qoal_cal_rng_index=0;
				scale_qoal_ia_range = float(100 uV)/32768;
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			default:
				mytext.text_in_box(40,10,"qal_read_ia_offset(): not a valid range");
				return;
			}

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
			{
				
		
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])	
				{
					QAL_Used[i].QAL_slot->set_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
				}
			
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]=0;
			} else

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
				{
					QAL_Used[i].QAL_slot->ch1_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
				}
		
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]=0;
			} else

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
				{
					QAL_Used[i].QAL_slot->ch2_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH2_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);
				}
		
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]=0;
			} else

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
				{
					QAL_Used[i].QAL_slot->ch3_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
				}
				
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]=0;
			} else

			{
				char err_message[100];
				sprintf(err_message, "qal_read_ia_offset() invlid channel for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}


			QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
			QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);
			QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN);
			QAL_Used[i].QAL_slot->close_switch(QAL_IA_NEG_IN);
			if(use_internal_short_rly)
				QAL_Used[i].QAL_slot->close_relay(QAL_DUT_INP_SHORT);
			
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "qal_read_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	delay(2);
	if(ia_range==RANGE_100_UV) delay(5);

	float CheckAvWindow;
	CMicroTimer LocalTimerCheckAvWindow;
	LocalTimerCheckAvWindow.Start();
	if(reject_50Hz)		
		for(n=0; n<nsamples; n++)
		{
			
			LocalTimer20ms.Start();
			
			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

			
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
	
			wait.delay_10_us(100);


			pin_ptr = start_pin_ptr; 
			do
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);

	
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

		
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);	
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
	
			wait.delay_10_us(100);


			pin_ptr = start_pin_ptr; 
			do
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
			
		
			pin_ptr = start_pin_ptr; 
			do
			{
			pin = pin_ptr->grouppin;

			
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
			
			wait.delay_10_us(100);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;


			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{

				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
		
			
			wait.delay_10_us(100);

			
			pin_ptr = start_pin_ptr; 
			do	
			{
			pin = pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
					if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
			}
			pin_ptr = pin_ptr->nextptr;

			} while (pin_ptr != NULL);
			
			LocalElapsedTime=LocalTimer20ms.GetElapsedTime()*(float)(1 uS);

			
			LocalTrailTime_10us=abs((int)(0.5+1.0e6*((1.0f/CSC_POWER_FREQ)/nsamples-LocalElapsedTime)/10));

			
			if(LocalTrailTime_10us<1) LocalTrailTime_10us=1;
			if(LocalTrailTime_10us>1000) LocalTrailTime_10us=1000;
			
			
			wait.delay_10_us(LocalTrailTime_10us-1);

		} 
	else
		{
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);			
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0) for(n=0; n<nsamples; n++)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1) for(n=0; n<nsamples; n++)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

	
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2) for(n=0; n<nsamples; n++)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
	
		
		wait.delay_10_us(100);

		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3) for(n=0; n<nsamples; n++)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

		} 

	CheckAvWindow=LocalTimerCheckAvWindow.GetElapsedTime()*(float)(1 uS);

	if(reject_50Hz&&((CheckAvWindow<(float)(19 mS))||(CheckAvWindow>(float)(21 mS))))
	{
		char err_message[100];
		sprintf(err_message, "qal_read_ia_offset() impossible to reject 50Hz",Pin_Type_Used[pin][i].Pin_Name);
		mytext.text_in_box(40,10,err_message);
	}		

	
	pin_ptr = start_pin_ptr; 
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		
		Source_type=pin_selection(pin,i);
		if(Source_type==QAL)	
		{
			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]=((float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index])/nsamples-32768)*scale_qoal_ia_range;
			else
			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]=((float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index])/nsamples-32768)*scale_qoal_ia_range;
			else
			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]=((float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index])/nsamples-32768)*scale_qoal_ia_range;
			else
			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]=((float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index])/nsamples-32768)*scale_qoal_ia_range;

			
			if(use_internal_short_rly)
				QAL_Used[i].QAL_slot->open_relay(QAL_DUT_INP_SHORT);
		}
	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);
			
			
	

	
	
	
	int list_depth=0;
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	float ZeroNull_sign=0.0;

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
			{
				if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
					ZeroNull_sign=-1.0f;	
				else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
					ZeroNull_sign=1.0f;		

				
				zero_null[list_depth-1-n][i]=999;
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]*ZeroNull_sign;
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]*ZeroNull_sign;
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]*ZeroNull_sign;
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]*ZeroNull_sign;
			}
		}
		pin_ptr = pin_ptr->nextptr;
	}
}

int oal_cal_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{


	int ret_err;
	int i;
	sfloat zero_null_single_pin[1]={0.0};

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;	

		case OAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "oal_read_ia_offset() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
			if(pin_ptr->nextptr!=NULL) 
			{
				char err_message[100];
				sprintf(err_message, "When oal_cal_ia_offset() is called with a list of pins an array of sfloat must be provided");
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "oal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
		}
	}
		
	
	ret_err=oal_cal_ia_offset(pin, ia_range, zero_null_single_pin, recalibrate, nsamples, reject_50Hz, use_internal_short_rly, start_from_existing_cal);

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		zero_null[i]=zero_null_single_pin[0][i];

	return ret_err;
}

int qal_cal_ia_offset(short pin, unsigned short ia_range, sfloat zero_null, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{


	int ret_err;
	int i;
	sfloat zero_null_single_pin[1]={0.0};

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;	

		case QAL:
			if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
			{
				char err_message[100];
				sprintf(err_message, "qal_read_ia_offset() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
			if(pin_ptr->nextptr!=NULL) 
			{
				char err_message[100];
				sprintf(err_message, "When qal_cal_ia_offset() is called with a list of pins an array of sfloat must be provided");
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "qal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
			}
		}
	}
		
	
	ret_err=qal_cal_ia_offset(pin, ia_range, zero_null_single_pin, recalibrate, nsamples, reject_50Hz, use_internal_short_rly, start_from_existing_cal);

	
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		zero_null[i]=zero_null_single_pin[0][i];

	return ret_err;
}

int oal_cal_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{


























		












	
	int i;
	int n;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int		return_error=0;
	int		doal_cal_rng_index;	

	pin_ptr = group_selection(pin); 
	start_pin_ptr = pin_ptr;		

	if(!recalibrate)	
	{
		switch (ia_range)
		{
		case RANGE_100_MV:		
			doal_cal_rng_index=3;
			break;
		case RANGE_10_MV:		
			doal_cal_rng_index=2;
			break;
		case RANGE_1_MV:		
			doal_cal_rng_index=1;
			break;
		case RANGE_100_UV:		
			doal_cal_rng_index=0;
			break;
		default:
			mytext.text_in_box(40,10,"oal_cal_ia_offset(): not a valid range");
			return 1;
		}
			
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
		
			Source_type=pin_selection(pin,i);
			
			switch(Source_type)
			{
			case NONE: break;	

			case OAL:
				if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
				{
					char err_message[100];
					sprintf(err_message, "oal_read_ia_offset() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return 1;
				}
				
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)	
				{
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							OAL_Used[i].OAL_slot->close_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->close_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->close_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"oal_cal_ia_offset(): not a valid range");
							return 1;
						}


						OAL_Used[i].OAL_slot->set_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]);
						if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]<0)
							OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
						else
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "oal_cal_ia_offset()\nImpossible to retrieve cal data for DOAL %i - channel 0",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}

				
				if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
				{
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])	
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							OAL_Used[i].OAL_slot->close_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->close_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->close_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							OAL_Used[i].OAL_slot->open_switch(IA_100MV);
							OAL_Used[i].OAL_slot->open_switch(IA_10MV);
							OAL_Used[i].OAL_slot->open_switch(IA_1MV);
							OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"oal_cal_ia_offset(): not a valid range");
							return 1;
						}


						OAL_Used[i].OAL_slot->ch1_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]);
						if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]<0)
							OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
						else
							OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "oal_cal_ia_offset()\nImpossible to retrieve cal data for DOAL %i - channel 1",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}

				break;

			default:
				{
				char err_message[100];
				sprintf(err_message, "oal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
				}
			}

		}

		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

	} 

	else	
	{
		
		
		bool	doal_present=false;	
		DYN_GROUP_LIST *local_pin_ptr;
		DYN_GROUP_LIST *lookup_local_pin_ptr;
		DYN_GROUP_LIST *start_local_pin_ptr;
		
		
		local_pin_ptr = (DYN_GROUP_LIST*) malloc(sizeof(DYN_GROUP_LIST));
		if (local_pin_ptr == NULL)
		{
			MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}
		local_pin_ptr->grouppin=pin_ptr->grouppin;
		local_pin_ptr->nextptr=NULL;

		
		start_local_pin_ptr=local_pin_ptr;	
		
		do
		{

		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
				case NONE: break;	

				case OAL:
					doal_present=false;
					lookup_local_pin_ptr=start_local_pin_ptr;

					
					do
					{
						if(Pin_Type_Used[pin][i].Slot==Pin_Type_Used[lookup_local_pin_ptr->grouppin][i].Slot) doal_present=true;
						lookup_local_pin_ptr = lookup_local_pin_ptr->nextptr;
					
					}  while ((!doal_present)&&(lookup_local_pin_ptr != NULL));

					
					if (!doal_present)
					{
						
						
					
						local_pin_ptr->nextptr = (DYN_GROUP_LIST*) malloc(sizeof(DYN_GROUP_LIST));	
						if (local_pin_ptr->nextptr == NULL)
						{
							MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							exit(0);
						}
						local_pin_ptr=local_pin_ptr->nextptr;
						local_pin_ptr->grouppin=pin_ptr->grouppin;
						
						local_pin_ptr->nextptr=NULL;	
					}

				break;

				default:
					{
					char err_message[100];
					sprintf(err_message, "oal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return 1;
					}
				}
			}
		}  
		pin_ptr = pin_ptr->nextptr;

		}  while (pin_ptr != NULL);	



		float	ia_os_scale;					
		float	scale_doal_ia_range;			
		int		cal_timeout=8;					
		float	os_accuracy=0.05f;				
		local_pin_ptr = start_local_pin_ptr;	
		CMicroTimer LocalTimer20ms;
		float	LocalElapsedTime;
		int		LocalTrailTime_10us;
		bool	all_cal;

		do
		{

		pin = local_pin_ptr->grouppin;



		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);

			if(Source_type==OAL)	
			{
		
				switch (ia_range)
				{
				case RANGE_100_MV:		
					OAL_Used[i].OAL_slot->close_switch(IA_100MV);
					OAL_Used[i].OAL_slot->open_switch(IA_10MV);
					OAL_Used[i].OAL_slot->open_switch(IA_1MV);
					OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV);
					ia_os_scale=1;	
					scale_doal_ia_range = float(100 mV)/32768;
					doal_cal_rng_index=3;
					break;
				case RANGE_10_MV:		
					OAL_Used[i].OAL_slot->open_switch(IA_100MV);
					OAL_Used[i].OAL_slot->close_switch(IA_10MV);
					OAL_Used[i].OAL_slot->open_switch(IA_1MV);
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
					ia_os_scale=1;						
					scale_doal_ia_range = float(10 mV)/32768;
					doal_cal_rng_index=2;
					break;
				case RANGE_1_MV:		
					OAL_Used[i].OAL_slot->open_switch(IA_100MV);
					OAL_Used[i].OAL_slot->open_switch(IA_10MV);
					OAL_Used[i].OAL_slot->close_switch(IA_1MV);
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
					ia_os_scale=0.1f;
					scale_doal_ia_range = float(1 mV)/32768;
					doal_cal_rng_index=1;
					break;
				case RANGE_100_UV:		
					OAL_Used[i].OAL_slot->open_switch(IA_100MV);
					OAL_Used[i].OAL_slot->open_switch(IA_10MV);
					OAL_Used[i].OAL_slot->open_switch(IA_1MV);
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
					ia_os_scale=0.01f;
					scale_doal_ia_range = float(100 uV)/32768;   
					doal_cal_rng_index=0;
					break;
				default:
					mytext.text_in_box(40,10,"oal_cal_ia_offset(): not a valid range");
					return 1;
				}

			
				OAL_Used[i].OAL_slot->close_relay(DUT_POS_ISOL);
				OAL_Used[i].OAL_slot->close_relay(DUT_NEG_ISOL);
				OAL_Used[i].OAL_slot->close_switch(IA_POS_IN);
				OAL_Used[i].OAL_slot->close_switch(IA_NEG_IN);
				if(use_internal_short_rly)
					OAL_Used[i].OAL_slot->close_relay(DUT_INP_SHORT);

		
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_rng_ch0[doal_cal_rng_index]=ia_range;
				
		
				if(!start_from_existing_cal)
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index]=false;	

				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
				{
				
					OAL_Used[i].OAL_slot->set_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]);
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]<0)
						OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
					else
						OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
		
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]=0.0f;
				}
				else
				{
		
					OAL_Used[i].OAL_slot->set_ia_offset_dac(0);	
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);

					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]=0;

				
					OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index] = OAL_Used[i].OAL_slot->convert_read_adc())<32768)	
					{
						OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]=-1;
					}
					else
					{
						OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]=1;
					}
				
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]-=32768;
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]*=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index];
				}
			
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index]=false;

			
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_rng_ch1[doal_cal_rng_index]=ia_range;
				
		
				if(!start_from_existing_cal)
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index]=false;	
				
				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
				{
				
					OAL_Used[i].OAL_slot->ch1_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]);
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]<0)
						OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
					else
						OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);

					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]=0.0f;
				}
				else
				{

					OAL_Used[i].OAL_slot->ch1_ia_offset_dac(0);		
					OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);		

					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]=0;

			
					OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index] = OAL_Used[i].OAL_slot->convert_read_adc())<32768)	
					{
						OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]=-1;
					}
					else
					{
						OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]=1;
					}
				
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]-=32768;
					OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]*=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index];
				}
				
				OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index]=false;
		
			}
		}

		local_pin_ptr = local_pin_ptr->nextptr;

		} while (local_pin_ptr != NULL);

		
						
		do	
		{
			local_pin_ptr = start_local_pin_ptr; 
			do	
			{
			pin = local_pin_ptr->grouppin;



			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);

				if(Source_type==OAL)
				{
					if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
					{
					
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]+=(int)(2*ia_os_scale*OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]);
					
						if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]<0) OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]=0; 
					
						OAL_Used[i].OAL_slot->set_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]);
					
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]=0;
					}

					if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
					{
					
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]+=(int)(2*ia_os_scale*OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]);
					
						if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]<0) OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]=0;
					
						OAL_Used[i].OAL_slot->ch1_ia_offset_dac(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]);
					
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]=0;
					}
				}
			}

			local_pin_ptr = local_pin_ptr->nextptr;

			} while (local_pin_ptr != NULL);
			
			delay(2);
			if(ia_range==RANGE_100_UV) delay(8);

	

			float CheckAvWindow;
			CMicroTimer LocalTimerCheckAvWindow;
			LocalTimerCheckAvWindow.Start();
			if(reject_50Hz)		
				for(n=0; n<nsamples; n++)
				{
				
					LocalTimer20ms.Start();
					
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==OAL)	
							if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
								OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					wait.delay_10_us(100);

					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==OAL)	
							if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
								OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					
					
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==OAL)	
							if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
								OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					wait.delay_10_us(100);

					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==OAL)	
							if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
								OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);


					LocalElapsedTime=LocalTimer20ms.GetElapsedTime()*(float)(1 uS);

					
					LocalTrailTime_10us=abs((int)(0.5+1.0e6*((1.0f/CSC_POWER_FREQ)/nsamples-LocalElapsedTime)/10));

					
					if(LocalTrailTime_10us<1) LocalTrailTime_10us=1;
					if(LocalTrailTime_10us>1000) LocalTrailTime_10us=1000;
					
					
					wait.delay_10_us(LocalTrailTime_10us-1);

				} 
			else
			{
				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==OAL)	
						if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
							OAL_Used[i].OAL_slot->select_adc_mux(IA_AMP);		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==OAL)	
						if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index]) for(n=0; n<nsamples; n++)
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				
				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==OAL)	
						if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
							OAL_Used[i].OAL_slot->select_adc_mux(CH1_IA_AMP);		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==OAL)	
						if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index]) for(n=0; n<nsamples; n++)
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]+=OAL_Used[i].OAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);

			} 

			CheckAvWindow=LocalTimerCheckAvWindow.GetElapsedTime()*(float)(1 uS);
		
			if(reject_50Hz&&((CheckAvWindow<(float)(19 mS))||(CheckAvWindow>(float)(21 mS))))
				return_error=1;

			
			all_cal=true;
			local_pin_ptr = start_local_pin_ptr; 
			do	
			{
			pin = local_pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==OAL)	
				{
					if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
					{
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]=(int)(0.5+(float)(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index])/nsamples);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]-=32768;
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]*=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index];
						if(abs(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index])<=(32768*os_accuracy))
						{
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]*=scale_doal_ia_range;
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
					if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
					{
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]=(int)(0.5+(float)(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index])/nsamples);
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]-=32768;
						OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]*=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index];
						if(abs(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index])<=(32768*os_accuracy))
						{
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]*=scale_doal_ia_range;
							OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
				}
			}

			local_pin_ptr = local_pin_ptr->nextptr;

			} while (local_pin_ptr != NULL);

		cal_timeout--;

		} while ((!all_cal)&&(cal_timeout)); 

		if(return_error==1)
			{
			char err_message[100];
			sprintf(err_message, "oal_cal_ia_offset() impossible to reject 50Hz",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			}		

		
		local_pin_ptr = start_local_pin_ptr; 
		do	
		{
		pin = local_pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
				if(use_internal_short_rly)
					OAL_Used[i].OAL_slot->open_relay(DUT_INP_SHORT);
		}
		local_pin_ptr = local_pin_ptr->nextptr;

		} while (local_pin_ptr != NULL);
		
		
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
			{
				if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "oal_cal_ia_offset()\nImpossible to correct IA offset for DOAL %i - channel 0",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}		

				if(!OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "oal_cal_ia_offset()\nImpossible to correct IA offset for DOAL %i - channel 1",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}
			}
		}

		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

		
		do
		{
			local_pin_ptr = start_local_pin_ptr->nextptr;
			free(start_local_pin_ptr);
			start_local_pin_ptr = local_pin_ptr;
		} while (start_local_pin_ptr != NULL);

	}

	

	
	
	
	int list_depth=0;
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL) {
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	float ZeroNull_sign=0.0;

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==OAL)	
			{
				if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
					ZeroNull_sign=-1.0f;	
				else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
					ZeroNull_sign=1.0f;		

				
				zero_null[list_depth-1-n][i]=999;
				if((OAL_Used[i].OAL_channel==OAL_CHANNEL_0)&&(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch0[doal_cal_rng_index]*ZeroNull_sign;
				if((OAL_Used[i].OAL_channel==OAL_CHANNEL_1)&&(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_err_ch1[doal_cal_rng_index]*ZeroNull_sign;
			}
		}
		pin_ptr = pin_ptr->nextptr;
	}


	return return_error;

}

int qal_cal_ia_offset(short pin, unsigned short ia_range, sfloat *zero_null, bool recalibrate, int nsamples, bool reject_50Hz, bool use_internal_short_rly, bool start_from_existing_cal)
{
	















	
	
 
	
 

	

	
	
		

	


	







	
	int i;
	int n;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int		return_error=0;
	int		qoal_cal_rng_index;	

	pin_ptr = group_selection(pin); 
	start_pin_ptr = pin_ptr;		

	if(!recalibrate)
	{
		switch (ia_range)
		{
		case RANGE_100_MV:		
			qoal_cal_rng_index=3;
			break;
		case RANGE_10_MV:		
			qoal_cal_rng_index=2;
			break;
		case RANGE_1_MV:		
			qoal_cal_rng_index=1;
			break;
		case RANGE_100_UV:		
			qoal_cal_rng_index=0;
			break;
		default:
			mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
			return 1;
		}
			
		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			
			switch(Source_type)
			{
			case NONE: break;	

			case QAL:
				if(!((Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)||(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)))
				{
					char err_message[100];
					sprintf(err_message, "qal_read_ia_offset() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return 1;
				}
				
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
				{
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
							return 1;
						}


						QAL_Used[i].QAL_slot->set_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]);
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]<0)
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
						else
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "qal_cal_ia_offset()\nImpossible to retrieve cal data for QOAL %i - channel 0",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}

				
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
				{
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
							return 1;
						}


						QAL_Used[i].QAL_slot->ch1_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]);
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]<0)
							QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
						else
							QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "qal_cal_ia_offset()\nImpossible to retrieve cal data for QOAL %i - channel 1",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}

		
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)	
				{
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
							return 1;
						}


						QAL_Used[i].QAL_slot->ch2_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]);
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]<0)
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
						else
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "qal_cal_ia_offset()\nImpossible to retrieve cal data for QOAL %i - channel 2",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}

			
				if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
				{
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
					{
						switch (ia_range)
						{
						case RANGE_100_MV:		
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_10_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_1_MV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						case RANGE_100_UV:		
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
							QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
							break;
						default:
							mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
							return 1;
						}


						QAL_Used[i].QAL_slot->ch3_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]);
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]<0)
							QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
						else
							QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "qal_cal_ia_offset()\nImpossible to retrieve cal data for QOAL %i - channel 3",Pin_Type_Used[pin][i].Slot);
						mytext.text_in_box(40,10,err_message);
						return_error=2;
					}		
				}
				break;

			default:
				{
				char err_message[100];
				sprintf(err_message, "qal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return 1;
				}
			}

		}

		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

	} 

	else	
	{
		

		bool	qoal_present=false;	
		DYN_GROUP_LIST *local_pin_ptr;
		DYN_GROUP_LIST *lookup_local_pin_ptr;
		DYN_GROUP_LIST *start_local_pin_ptr;
		
		
		local_pin_ptr = (DYN_GROUP_LIST*) malloc(sizeof(DYN_GROUP_LIST));
		if (local_pin_ptr == NULL)
		{
			MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}
		local_pin_ptr->grouppin=pin_ptr->grouppin;
		local_pin_ptr->nextptr=NULL;

		
		start_local_pin_ptr=local_pin_ptr;	
		
		do
		{

		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
				Source_type=pin_selection(pin,i);
				switch(Source_type)
				{
				case NONE: break;	

				case QAL:
					qoal_present=false;
					lookup_local_pin_ptr=start_local_pin_ptr;

					
					do
					{
						if(Pin_Type_Used[pin][i].Slot==Pin_Type_Used[lookup_local_pin_ptr->grouppin][i].Slot) qoal_present=true;
						lookup_local_pin_ptr = lookup_local_pin_ptr->nextptr;
					
					}  while ((!qoal_present)&&(lookup_local_pin_ptr != NULL));

					
					if (!qoal_present)
					{
						
						

						local_pin_ptr->nextptr = (DYN_GROUP_LIST*) malloc(sizeof(DYN_GROUP_LIST));	
						if (local_pin_ptr->nextptr == NULL)
						{
							MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							exit(0);
						}
						local_pin_ptr=local_pin_ptr->nextptr;
						local_pin_ptr->grouppin=pin_ptr->grouppin;
						
						local_pin_ptr->nextptr=NULL;	
					}

				break;

				default:
					{
					char err_message[100];
					sprintf(err_message, "qal_cal_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return 1;
					}
				}
			}
		}  
		pin_ptr = pin_ptr->nextptr;

		}  while (pin_ptr != NULL);

		

		float	ia_os_scale;					
		float	scale_qoal_ia_range;			
		int		cal_timeout=8;					
		float	os_accuracy=0.05f;				
		local_pin_ptr = start_local_pin_ptr;	
		CMicroTimer LocalTimer20ms;
		float	LocalElapsedTime;
		int		LocalTrailTime_10us;
		bool	all_cal;

		do
		{

		pin = local_pin_ptr->grouppin;

		
		
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);

			if(Source_type==QAL)	
			{
				
				switch (ia_range)
				{
				case RANGE_100_MV:		
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
					ia_os_scale=1;		
					scale_qoal_ia_range = float(100 mV)/32768;
					qoal_cal_rng_index=3;
					break;
				case RANGE_10_MV:		
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
					ia_os_scale=1;	
					scale_qoal_ia_range = float(10 mV)/32768;
					qoal_cal_rng_index=2;
					break;
				case RANGE_1_MV:		
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
					ia_os_scale=0.1f;
					scale_qoal_ia_range = float(1 mV)/32768;
					qoal_cal_rng_index=1;
					break;
				case RANGE_100_UV:		
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
					ia_os_scale=0.01f;	
					scale_qoal_ia_range = float(100 uV)/32768;   
					qoal_cal_rng_index=0;
					break;
				default:
					mytext.text_in_box(40,10,"qal_cal_ia_offset(): not a valid range");
					return 1;
				}

				
				QAL_Used[i].QAL_slot->close_relay(QAL_DUT_POS_ISOL);
				QAL_Used[i].QAL_slot->close_relay(QAL_DUT_NEG_ISOL);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_POS_IN);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_NEG_IN);
				if(use_internal_short_rly)
					QAL_Used[i].QAL_slot->close_relay(QAL_DUT_INP_SHORT);

			
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_rng_ch0[qoal_cal_rng_index]=ia_range;
				
				
				if(!start_from_existing_cal)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index]=false;	

				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
				{
					
					QAL_Used[i].QAL_slot->set_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
					
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]=0.0f;
				}
				else
				{
					
					QAL_Used[i].QAL_slot->set_ia_offset_dac(0);		
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);	

					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]=0;

					
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index] = QAL_Used[i].QAL_slot->convert_read_adc())<32768)	
					{
						QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]=-1;
					}
					else
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]=1;
					}
					
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]-=32768;
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index];
				}
			
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index]=false;

				
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_rng_ch1[qoal_cal_rng_index]=ia_range;
				
			
				if(!start_from_existing_cal)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index]=false;	
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
				{
					
					QAL_Used[i].QAL_slot->ch1_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
				
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]=0.0f;
				}
				else
				{
					
					QAL_Used[i].QAL_slot->ch1_ia_offset_dac(0);	
					QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);	

					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]=0;


					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index] = QAL_Used[i].QAL_slot->convert_read_adc())<32768)	
					{
						QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]=-1;
					}
					else
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]=1;
					}

					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]-=32768;
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index];
				}
	
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index]=false;
		
		
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_rng_ch2[qoal_cal_rng_index]=ia_range;
				
		
				if(!start_from_existing_cal)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index]=false;	
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
				{
				
					QAL_Used[i].QAL_slot->ch2_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH2_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);
				
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]=0.0f;
				}
				else
				{
				
					QAL_Used[i].QAL_slot->ch1_ia_offset_dac(0);			
					QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);	

					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]=0;

		
					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index] = QAL_Used[i].QAL_slot->convert_read_adc())<32768)	
					{
						QAL_Used[i].QAL_slot->close_switch(QAL_CH2_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]=-1;
					}
					else
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]=1;
					}
					
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]-=32768;
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index];
				}
				
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index]=false;

			   
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_rng_ch3[qoal_cal_rng_index]=ia_range;
				
			
				if(!start_from_existing_cal)
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index]=false;	
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
				{
				
					QAL_Used[i].QAL_slot->ch3_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]);
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]<0)
						QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
					else
						QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
					
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]=0.0f;
				}
				else
				{
					
					QAL_Used[i].QAL_slot->ch3_ia_offset_dac(0);		
					QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);		

					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]=0;


					QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);
					delay(2);
					if(ia_range==RANGE_100_UV) delay(5);
					if ((QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index] = QAL_Used[i].QAL_slot->convert_read_adc())<32768)	
					{
						QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]=-1;
					}
					else
					{
						QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]=1;
					}
		
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]-=32768;
					QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index];
				}
				
				QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index]=false;
			}
		}

		local_pin_ptr = local_pin_ptr->nextptr;

		} while (local_pin_ptr != NULL);

		
						
		do	
		{
			local_pin_ptr = start_local_pin_ptr; 
			do	
			{
			pin = local_pin_ptr->grouppin;


	
			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);

				if(Source_type==QAL)
				{
					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
					{
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]+=(int)(2*ia_os_scale*QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]);
					
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]<0) QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]=0; 
					
						QAL_Used[i].QAL_slot->set_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]);
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]=0;
					}

					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
					{
				
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]+=(int)(2*ia_os_scale*QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]);
					
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]<0) QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]=0;
					
						QAL_Used[i].QAL_slot->ch1_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]);
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]=0;
					}

					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
					{
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]+=(int)(2*ia_os_scale*QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]);
					
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]<0) QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]=0;
					
						QAL_Used[i].QAL_slot->ch2_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]);
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]=0;
					}

					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
					{
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]+=(int)(2*ia_os_scale*QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]);
					
						if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]<0) QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]=0;
					
						QAL_Used[i].QAL_slot->ch3_ia_offset_dac(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]);
					
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]=0;
					}
				}
			} 

			local_pin_ptr = local_pin_ptr->nextptr;

			} while (local_pin_ptr != NULL);
			
			delay(2);
			if(ia_range==RANGE_100_UV) delay(8);

	

			float CheckAvWindow;
			CMicroTimer LocalTimerCheckAvWindow;
			LocalTimerCheckAvWindow.Start();
			if(reject_50Hz)
				for(n=0; n<nsamples; n++)
				{
				
					LocalTimer20ms.Start();
					
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
								QAL_Used[i].QAL_slot->select_adc_mux(QAL_IA_AMP);		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					wait.delay_10_us(100);

					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
								QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					
					
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
								QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
								QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH2_IA_AMP);		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					wait.delay_10_us(100);

					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
								QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);
				
					
					
					
					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
								QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);	
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);

					
					wait.delay_10_us(100);

					
					local_pin_ptr = start_local_pin_ptr; 
					do	
					{
					pin = local_pin_ptr->grouppin;

					for( i = 0; i < max_sites ; i++ ) if(active_site[i])
					{
						
						Source_type=pin_selection(pin,i);
						if(Source_type==QAL)	
							if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
								QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
					}
					local_pin_ptr = local_pin_ptr->nextptr;

					} while (local_pin_ptr != NULL);


					LocalElapsedTime=LocalTimer20ms.GetElapsedTime()*(float)(1 uS);

					
					LocalTrailTime_10us=abs((int)(0.5+1.0e6*((1.0f/CSC_POWER_FREQ)/nsamples-LocalElapsedTime)/10));

					
					if(LocalTrailTime_10us<1) LocalTrailTime_10us=1;
					if(LocalTrailTime_10us>1000) LocalTrailTime_10us=1000;
					
					
					wait.delay_10_us(LocalTrailTime_10us-1);

				} 
			else
			{
				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
							QAL_Used[i].QAL_slot->select_adc_mux(IA_AMP);		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index]) for(n=0; n<nsamples; n++)
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				
				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH1_IA_AMP);		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index]) for(n=0; n<nsamples; n++)
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);

			
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
							QAL_Used[i].QAL_slot->select_adc_mux(IA_AMP);	
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index]) for(n=0; n<nsamples; n++)
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				
				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
							QAL_Used[i].QAL_slot->select_adc_mux(QAL_CH3_IA_AMP);	
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);
			
				
				wait.delay_10_us(100);

				
				local_pin_ptr = start_local_pin_ptr; 
				do	
				{
				pin = local_pin_ptr->grouppin;

				for( i = 0; i < max_sites ; i++ ) if(active_site[i])
				{
					
					Source_type=pin_selection(pin,i);
					if(Source_type==QAL)	
						if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index]) for(n=0; n<nsamples; n++)
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]+=QAL_Used[i].QAL_slot->convert_read_adc();		
				}
				local_pin_ptr = local_pin_ptr->nextptr;

				} while (local_pin_ptr != NULL);

			} 

			CheckAvWindow=LocalTimerCheckAvWindow.GetElapsedTime()*(float)(1 uS);
		
			if(reject_50Hz&&((CheckAvWindow<(float)(19 mS))||(CheckAvWindow>(float)(21 mS))))
				return_error=1;

			
			all_cal=true;
			local_pin_ptr = start_local_pin_ptr; 
			do	
			{
			pin = local_pin_ptr->grouppin;

			for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			{
				
				Source_type=pin_selection(pin,i);
				if(Source_type==QAL)	
				{
					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
					{
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]=(int)(0.5+(float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index])/nsamples);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]-=32768;
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index];
						if(abs(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index])<=(32768*os_accuracy))
						{
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]*=scale_qoal_ia_range;
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
					{
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]=(int)(0.5+(float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index])/nsamples);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]-=32768;
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index];
						if(abs(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index])<=(32768*os_accuracy))
						{
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]*=scale_qoal_ia_range;
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
					{
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]=(int)(0.5+(float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index])/nsamples);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]-=32768;
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index];
						if(abs(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index])<=(32768*os_accuracy))
						{
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]*=scale_qoal_ia_range;
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
					if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
					{
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]=(int)(0.5+(float)(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index])/nsamples);
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]-=32768;
						QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]*=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index];
						if(abs(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index])<=(32768*os_accuracy))
						{
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]*=scale_qoal_ia_range;
							QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index]=true;
						}
						else
							all_cal=false;
					}
				}
			}

			local_pin_ptr = local_pin_ptr->nextptr;

			} while (local_pin_ptr != NULL);

		cal_timeout--;

		} while ((!all_cal)&&(cal_timeout)); 

		if(return_error==1)
			{
			char err_message[100];
			sprintf(err_message, "qal_cal_ia_offset() impossible to reject 50Hz",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			}		

		
		local_pin_ptr = start_local_pin_ptr; 
		do	
		{
		pin = local_pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
				if(use_internal_short_rly)
					QAL_Used[i].QAL_slot->open_relay(QAL_DUT_INP_SHORT);
		}
		local_pin_ptr = local_pin_ptr->nextptr;

		} while (local_pin_ptr != NULL);
		

		pin_ptr = start_pin_ptr; 
		do	
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
			{
				if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "qal_cal_ia_offset()\nImpossible to correct IA offset for QOAL %i - channel 0",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}		

				if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "qal_cal_ia_offset()\nImpossible to correct IA offset for QOAL %i - channel 1",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}

				if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "qal_cal_ia_offset()\nImpossible to correct IA offset for QOAL %i - channel 2",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}

				if(!QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
					{
					char err_message[100];
					sprintf(err_message, "qal_cal_ia_offset()\nImpossible to correct IA offset for QOAL %i - channel 3",Pin_Type_Used[pin][i].Slot);
					mytext.text_in_box(40,10,err_message);
					return_error=2;
					}
			}
		}

		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);

		
		do
		{
			local_pin_ptr = start_local_pin_ptr->nextptr;
			free(start_local_pin_ptr);
			start_local_pin_ptr = local_pin_ptr;
		} while (start_local_pin_ptr != NULL);

	}

	

	
	
	
	int list_depth=0;
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL) {
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	float ZeroNull_sign=0.0;

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			
			Source_type=pin_selection(pin,i);
			if(Source_type==QAL)	
			{
				if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)		
					ZeroNull_sign=-1.0f;	
				else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)	
					ZeroNull_sign=1.0f;		

				
				zero_null[list_depth-1-n][i]=999;
				if((QAL_Used[i].QAL_channel==QAL_CHANNEL_0)&&(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch0[qoal_cal_rng_index]*ZeroNull_sign;
				if((QAL_Used[i].QAL_channel==QAL_CHANNEL_1)&&(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch1[qoal_cal_rng_index]*ZeroNull_sign;
				if((QAL_Used[i].QAL_channel==QAL_CHANNEL_2)&&(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch2[qoal_cal_rng_index]*ZeroNull_sign;
				if((QAL_Used[i].QAL_channel==QAL_CHANNEL_3)&&(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index]))
					zero_null[list_depth-1-n][i]=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_err_ch3[qoal_cal_rng_index]*ZeroNull_sign;
			}
		}
		pin_ptr = pin_ptr->nextptr;
	}


	return return_error;

}

void oal_set_ia_offset(short pin, unsigned short ia_range, float ia_offset)	
{
	
	
	int i;
	sfloat	s_ia_offset;

	for(i = 0; i < max_sites ; i++ ) if(active_site[i]) 
		s_ia_offset[i]=ia_offset;
	
	oal_set_ia_offset(pin, ia_range, s_ia_offset);

}

void qal_set_ia_offset(short pin, unsigned short ia_range, float ia_offset)	
{
	
	
	int i;
	sfloat	s_ia_offset;

	for(i = 0; i < max_sites ; i++ ) if(active_site[i]) 
		s_ia_offset[i]=ia_offset;
	
	qal_set_ia_offset(pin, ia_range, s_ia_offset);

}

void oal_set_ia_offset(short pin_list, unsigned short ia_range, sfloat *ia_offset)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		oal_set_ia_offset(pin, ia_range, ia_offset[list_depth-1-n]);

		pin_ptr = pin_ptr->nextptr;
	}
}

void qal_set_ia_offset(short pin_list, unsigned short ia_range, sfloat *ia_offset)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		qal_set_ia_offset(pin, ia_range, ia_offset[list_depth-1-n]);

		pin_ptr = pin_ptr->nextptr;
	}
}

void oal_set_ia_offset(short pin, unsigned short ia_range, sfloat ia_offset)
{
	

	




	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int		doal_cal_rng_index;	
	int i;
	float scale_doal_ia_os_dac;
	float zero_os, os_polarity;
	float ia_os_dac_word;

	pin_ptr = group_selection(pin);

	switch (ia_range)
	{
	case RANGE_100_MV:		
		break;
	case RANGE_10_MV:	
		doal_cal_rng_index=2;
		break;
	case RANGE_1_MV:	
		doal_cal_rng_index=1;
		break;
	case RANGE_100_UV:		
		doal_cal_rng_index=0;
		break;
	default:
		mytext.text_in_box(40,10,"oal_set_ia_offset(): not a valid range");
		return;
	}
		
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		
		Source_type=pin_selection(pin,i);
		
		switch(Source_type)
		{
		case NONE: break;	

		case OAL:
			if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)
				os_polarity=-1.0f;	
			else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)
				os_polarity=1.0f;	
			else
				{
				char err_message[100];
				sprintf(err_message, "oal_set_ia_offset() - Pin %s is not defined as Input for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
				}
			switch (ia_range)
			{
			case RANGE_100_MV:
				doal_cal_rng_index=3;
				scale_doal_ia_os_dac = 65535/float(100 mV);
				OAL_Used[i].OAL_slot->close_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->close_switch(IA_OFF_100_MV);
				break;
			case RANGE_10_MV:
				doal_cal_rng_index=2;
				scale_doal_ia_os_dac = 65535/float(10 mV);
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->close_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			case RANGE_1_MV:
				doal_cal_rng_index=1;
				scale_doal_ia_os_dac = 65535/float(10 mV);
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->close_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			case RANGE_100_UV:
				doal_cal_rng_index=0;
				scale_doal_ia_os_dac = 65535/float(10 mV);
				OAL_Used[i].OAL_slot->open_switch(IA_100MV);
				OAL_Used[i].OAL_slot->open_switch(IA_10MV);
				OAL_Used[i].OAL_slot->open_switch(IA_1MV);
				OAL_Used[i].OAL_slot->open_switch(IA_OFF_100_MV);
				break;
			default:
				mytext.text_in_box(40,10,"oal_set_ia_offset(): not a valid range");
				return;
			}

			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_0)
			{
				
				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch0[doal_cal_rng_index])
				{
					zero_os=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch0[doal_cal_rng_index]/scale_doal_ia_os_dac;
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch0[doal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_doal_ia_os_dac;
				if(ia_os_dac_word<0)
					OAL_Used[i].OAL_slot->close_switch(IA_OFF_POL);
				else
					OAL_Used[i].OAL_slot->open_switch(IA_OFF_POL);
				OAL_Used[i].OAL_slot->set_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			} else

			if(OAL_Used[i].OAL_channel==OAL_CHANNEL_1)
			{
				
				if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_cal_ch1[doal_cal_rng_index])
				{
					zero_os=OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_dac_ch1[doal_cal_rng_index]/scale_doal_ia_os_dac;
					if(OAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].OAL_ia_os_pol_ch1[doal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_doal_ia_os_dac;
				if(ia_os_dac_word<0)
					OAL_Used[i].OAL_slot->close_switch(CH1_OFF_POL);
				else
					OAL_Used[i].OAL_slot->open_switch(CH1_OFF_POL);
				OAL_Used[i].OAL_slot->ch1_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			}

			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "oal_set_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);
}

void qal_set_ia_offset(short pin, unsigned short ia_range, sfloat ia_offset)
{







	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int		qoal_cal_rng_index;	
	int i;
	float scale_qoal_ia_os_dac;
	float zero_os, os_polarity;
	float ia_os_dac_word;

	pin_ptr = group_selection(pin); 

	switch (ia_range)
	{
	case RANGE_100_MV:		
		break;
	case RANGE_10_MV:		
		qoal_cal_rng_index=2;
		break;
	case RANGE_1_MV:		
		qoal_cal_rng_index=1;
		break;
	case RANGE_100_UV:		
		qoal_cal_rng_index=0;
		break;
	default:
		mytext.text_in_box(40,10,"qal_set_ia_offset(): not a valid range");
		return;
	}
		
	do	
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		
		Source_type=pin_selection(pin,i);
		
		switch(Source_type)
		{
		case NONE: break;	

		case QAL:
			if(Pin_Type_Used[pin][i].PinClass==PIN_IN_NEG)
				os_polarity=-1.0f;		
			else if(Pin_Type_Used[pin][i].PinClass==PIN_IN_POS)
				os_polarity=1.0f;		
			else
				{
				char err_message[100];
				sprintf(err_message, "qal_set_ia_offset() - Pin %s is not defined as Input for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
				}
			switch (ia_range)
			{
			case RANGE_100_MV:
				qoal_cal_rng_index=3;
				scale_qoal_ia_os_dac = 65535/float(100 mV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_10_MV:
				qoal_cal_rng_index=2;
				scale_qoal_ia_os_dac = 65535/float(10 mV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_1_MV:
				qoal_cal_rng_index=1;
				scale_qoal_ia_os_dac = 65535/float(10 mV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->close_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			case RANGE_100_UV:
				qoal_cal_rng_index=0;
				scale_qoal_ia_os_dac = 65535/float(10 mV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_100MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_10MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_1MV);
				QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_100_MV);
				break;
			default:
				mytext.text_in_box(40,10,"qal_set_ia_offset(): not a valid range");
				return;
			}

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_0)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch0[qoal_cal_rng_index])
				{
					zero_os=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch0[qoal_cal_rng_index]/scale_qoal_ia_os_dac;
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch0[qoal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_qoal_ia_os_dac;
				if(ia_os_dac_word<0)
					QAL_Used[i].QAL_slot->close_switch(QAL_IA_OFF_POL);
				else
					QAL_Used[i].QAL_slot->open_switch(QAL_IA_OFF_POL);
				QAL_Used[i].QAL_slot->set_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			} else

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_1)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch1[qoal_cal_rng_index])
				{
					zero_os=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch1[qoal_cal_rng_index]/scale_qoal_ia_os_dac;
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch1[qoal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_qoal_ia_os_dac;
				if(ia_os_dac_word<0)
					QAL_Used[i].QAL_slot->close_switch(QAL_CH1_OFF_POL);
				else
					QAL_Used[i].QAL_slot->open_switch(QAL_CH1_OFF_POL);
				QAL_Used[i].QAL_slot->ch1_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			}

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_2)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch2[qoal_cal_rng_index])
				{
					zero_os=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch2[qoal_cal_rng_index]/scale_qoal_ia_os_dac;
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch2[qoal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_qoal_ia_os_dac;
				if(ia_os_dac_word<0)
					QAL_Used[i].QAL_slot->close_switch(QAL_CH2_OFF_POL);
				else
					QAL_Used[i].QAL_slot->open_switch(QAL_CH2_OFF_POL);
				QAL_Used[i].QAL_slot->ch2_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			} else

			if(QAL_Used[i].QAL_channel==QAL_CHANNEL_3)
			{
				
				if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_cal_ch3[qoal_cal_rng_index])
				{
					zero_os=QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_dac_ch3[qoal_cal_rng_index]/scale_qoal_ia_os_dac;
					if(QAL_Card_Used[Pin_Type_Used[pin][i].Slot-1].QAL_ia_os_pol_ch3[qoal_cal_rng_index]<0)
						zero_os*=-1.0f;
				}
				else
				
					zero_os=0.0f;

				ia_os_dac_word=(zero_os+os_polarity*ia_offset[i])*scale_qoal_ia_os_dac;
				if(ia_os_dac_word<0)
					QAL_Used[i].QAL_slot->close_switch(QAL_CH3_OFF_POL);
				else
					QAL_Used[i].QAL_slot->open_switch(QAL_CH3_OFF_POL);
				QAL_Used[i].QAL_slot->ch3_ia_offset_dac((int)(0.5+fabs(ia_os_dac_word)));				
			}

			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "qal_set_ia_offset() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);
}

float oal_connect_load(short pin, short mode, float load_var, LoadRefType LoadRef)
{
	



	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	struct Oal_Load Oal_Load_Temp[64];
	
	int l,i,m;
	float	max=0;
	float act_load=-1.0f;

	unsigned short best_rly_status;
	
	pin_ptr = group_selection(pin);

	if(Oal_Load_Calc_Due)

	{
		
		for(l=0;l<64;l++)
		{
			Oal_Load_Temp[l].val=0.0f;
			Oal_Load_Temp[l].load_rly=l;
		}
		
		
		for(l=0;l<64;l++)
		{
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>0))/600.0f;
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>1))/1000.0f;
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>2))/2000.0f;
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>3))/4700.0f;
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>4))/10000.0f;
			Oal_Load_Temp[l].val+=(0x1&(Oal_Load_Temp[l].load_rly>>5))/100000.0f;
			if(Oal_Load_Temp[l].val>0.0f) Oal_Load_Temp[l].val=1/Oal_Load_Temp[l].val;
		}

	
		for(l=63;l>0;l--)
		{
			for(i=0;i<64;i++)
				if(Oal_Load_Temp[i].val>max)
				{
					max=Oal_Load_Temp[i].val;
					m=i;
				}
			Oal_Load_Used[l].val=max;
			Oal_Load_Used[l].load_rly=Oal_Load_Temp[m].load_rly;
			max=Oal_Load_Temp[m].val=0.0f;
		}

		Oal_Load_Calc_Due=false;
	}

	switch (mode)
	{
	case CLOSE_LOAD:
	
		for(l=0;l<63;l++)
			if(load_var<Oal_Load_Used[l].val) break;

		if((fabs(load_var-Oal_Load_Used[l].val)<fabs(load_var-Oal_Load_Used[l-1].val))||(l==1))
		{
			best_rly_status=Oal_Load_Used[l].load_rly;
			act_load=Oal_Load_Used[l].val;
		}
		else
		{
			best_rly_status=Oal_Load_Used[l-1].load_rly;
			act_load=Oal_Load_Used[l-1].val;
		}

	

		do
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case OAL:
				if(Pin_Type_Used[pin][i].PinClass==PIN_OUT)
				{
					OAL_Used[i].OAL_slot->close_relay(CONNECT_LOADS);
					
					if(act_load>0.0f)
					{
						OAL_Used[i].OAL_slot->open_relay(LOAD_SHORT);

					
						if(0x1&best_rly_status>>0) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_600);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_600);

						
						if(0x1&best_rly_status>>1) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_1K);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_1K);

					
						if(0x1&best_rly_status>>2) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_2K);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_2K);

					
						if(0x1&best_rly_status>>3) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_4K7);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_4K7);
						
						
						if(0x1&best_rly_status>>4) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_10K);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_10K);

					
						if(0x1&best_rly_status>>5) 
							OAL_Used[i].OAL_slot->close_relay(LOAD_100K);
						else
							OAL_Used[i].OAL_slot->open_relay(LOAD_100K);
					}
					else
						OAL_Used[i].OAL_slot->close_relay(LOAD_SHORT);


					if(LoadRef==LOAD_INT_REF)
					{
						OAL_Used[i].OAL_slot->open_relay(LOAD_REF_EXT);
						OAL_Used[i].OAL_slot->close_relay(LOAD_REF_GND);
					}
					else
					{
						OAL_Used[i].OAL_slot->close_relay(LOAD_REF_EXT);
						OAL_Used[i].OAL_slot->open_relay(LOAD_REF_GND);
					}
				} else
				{
					char err_message[100];
					sprintf(err_message, "oal_connect_load() - Pin %s is not defined as Output for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
				break;

			default:
				{
					char err_message[100];
					sprintf(err_message, "oal_connect_load() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
			}
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
		break;
	case OPEN_LOAD:
		do
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case OAL:
				if(Pin_Type_Used[pin][i].PinClass==PIN_OUT)
				{
					OAL_Used[i].OAL_slot->open_relay(LOAD_REF_EXT);
					OAL_Used[i].OAL_slot->open_relay(EXT_LOAD_CONN);
					OAL_Used[i].OAL_slot->close_relay(LOAD_REF_GND);
					OAL_Used[i].OAL_slot->open_relay(LOAD_600);
					OAL_Used[i].OAL_slot->open_relay(LOAD_1K);
					OAL_Used[i].OAL_slot->open_relay(LOAD_2K);
					OAL_Used[i].OAL_slot->open_relay(LOAD_4K7);
					OAL_Used[i].OAL_slot->open_relay(LOAD_10K);
					OAL_Used[i].OAL_slot->open_relay(LOAD_100K);
					OAL_Used[i].OAL_slot->open_relay(LOAD_SHORT);
					OAL_Used[i].OAL_slot->close_relay(CONNECT_LOADS);
				} else
				{
					char err_message[100];
					sprintf(err_message, "oal_connect_load() - Pin %s is not defined as Output for DOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
				break;

			default:
				{
					char err_message[100];
					sprintf(err_message, "oal_connect_load() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
			}
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
		break;
	default:
		{
			char err_message[100];
			sprintf(err_message, "oal_connect_load() - Invalid mode for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return -1.0f;
		}
	}
return act_load;
}

float qal_connect_load(short pin, short mode, float load_var, LoadRefType LoadRef)
{
	



	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	
	struct Qal_Load Qal_Load_Temp[64];
	
	int l,i,m;
	float	max=0;
	float act_load=-1.0f;

	unsigned short best_rly_status;
	
	pin_ptr = group_selection(pin); 

	if(Qal_Load_Calc_Due)

	{
	
		for(l=0;l<64;l++)
		{
			Qal_Load_Temp[l].val=0.0f;
			Qal_Load_Temp[l].load_rly=l;
		}
		

		for(l=0;l<64;l++)
		{
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>0))/600.0f;
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>1))/1000.0f;
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>2))/2000.0f;
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>3))/4700.0f;
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>4))/10000.0f;
			Qal_Load_Temp[l].val+=(0x1&(Qal_Load_Temp[l].load_rly>>5))/100000.0f;
			if(Qal_Load_Temp[l].val>0.0f) Qal_Load_Temp[l].val=1/Qal_Load_Temp[l].val;
		}

	
		for(l=63;l>0;l--)
		{
			for(i=0;i<64;i++)
				if(Qal_Load_Temp[i].val>max)
				{
					max=Qal_Load_Temp[i].val;
					m=i;
				}
			Qal_Load_Used[l].val=max;
			Qal_Load_Used[l].load_rly=Qal_Load_Temp[m].load_rly;
			max=Qal_Load_Temp[m].val=0.0f;
		}

		Qal_Load_Calc_Due=false;
	}

	switch (mode)
	{
	case CLOSE_LOAD:

		for(l=0;l<63;l++)
			if(load_var<Qal_Load_Used[l].val) break;

		if((fabs(load_var-Qal_Load_Used[l].val)<fabs(load_var-Qal_Load_Used[l-1].val))||(l==1))
		{
			best_rly_status=Qal_Load_Used[l].load_rly;
			act_load=Qal_Load_Used[l].val;
		}
		else
		{
			best_rly_status=Qal_Load_Used[l-1].load_rly;
			act_load=Qal_Load_Used[l-1].val;
		}



		do
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case QAL:
				if(Pin_Type_Used[pin][i].PinClass==PIN_OUT)
				{
					QAL_Used[i].QAL_slot->close_relay(QAL_CONNECT_LOADS);
					
					if(act_load>0.0f)
					{
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_SHORT);

						
						if(0x1&best_rly_status>>0) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_600);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_600);

				
						if(0x1&best_rly_status>>1) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_1K);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_1K);

					
						if(0x1&best_rly_status>>2) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_2K);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_2K);

					
						if(0x1&best_rly_status>>3) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_4K7);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_4K7);
						
					
						if(0x1&best_rly_status>>4) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_10K);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_10K);

						
						if(0x1&best_rly_status>>5) 
							QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_100K);
						else
							QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_100K);
					}
					else
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_SHORT);


					if(LoadRef==LOAD_INT_REF)
					{
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_REF_EXT);
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_REF_GND);
					}
					else
					{
						QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_REF_EXT);
						QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_REF_GND);
					}
				} else
				{
					char err_message[100];
					sprintf(err_message, "qal_connect_load() - Pin %s is not defined as Output for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
				break;

			default:
				{
					char err_message[100];
					sprintf(err_message, "qal_connect_load() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
			}
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
		break;
	case OPEN_LOAD:
		do
		{
		pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case QAL:
				if(Pin_Type_Used[pin][i].PinClass==PIN_OUT)
				{
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_REF_EXT);
					QAL_Used[i].QAL_slot->open_relay(QAL_EXT_LOAD_CONN);
					QAL_Used[i].QAL_slot->close_relay(QAL_LOAD_REF_GND);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_600);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_1K);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_2K);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_4K7);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_10K);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_100K);
					QAL_Used[i].QAL_slot->open_relay(QAL_LOAD_SHORT);
					QAL_Used[i].QAL_slot->close_relay(QAL_CONNECT_LOADS);
				} else
				{
					char err_message[100];
					sprintf(err_message, "qal_connect_load() - Pin %s is not defined as Output for QOAL: check Pinmap file",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
				break;

			default:
				{
					char err_message[100];
					sprintf(err_message, "qal_connect_load() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return -1.0f;
				}
			}
		}
		pin_ptr = pin_ptr->nextptr;

		} while (pin_ptr != NULL);
		break;
	default:
		{
			char err_message[100];
			sprintf(err_message, "qal_connect_load() - Invalid mode for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return -1.0f;
		}
	}
return act_load;
}







void ac_force_setup(short pin, double Vpeak, double Voffset, AcsWaveType mode, int Ns, float *ACS_buf, short ACS_divider, short ACS_filter, double PFLP_freq, short sync_pin, short sync_trig)	
{
	ac_force_setup(pin, float(Vpeak), float(Voffset), mode, Ns, ACS_buf, ACS_divider, ACS_filter, float(PFLP_freq), sync_pin, sync_trig);
}
void ac_force_setup(short pin, float Vpeak, float Voffset, AcsWaveType mode, int Ns, float *ACS_buf, short ACS_divider, short ACS_filter, float PFLP_freq, short sync_pin, short sync_trig)
{
	

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	short ACS_range=ACS_10_VOLT_RANGE;

	int sync_word=0;
	int i,j;

	if(mode!=WAVE_USR)
	{
		char err_message[100];
		sprintf(err_message, "ac_force_setup() -  standard waveforms require to specify the frequency");
		mytext.text_in_box(40,10,err_message);
		return;
	}

	
	pin_ptr = group_selection(pin); 
	pin = pin_ptr->grouppin;
	if(sync_pin!=NULL)
	{
		pin_ptr = group_selection(sync_pin); 
		sync_pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;	

			case ACS:
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT1) sync_word+=2;
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT2) sync_word+=4;	
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT3) sync_word+=8;	
				break;
			default:	
				{
					char err_message[100];
					sprintf(err_message, "ac_force() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return;
				}
			}
		}
	}
	
	pin_ptr = group_selection(pin);
	pin = pin_ptr->grouppin;
	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);

		switch(Source_type)
		{
		case NONE: break;

		case ACS:
			if((fabs(Vpeak)+fabs(Voffset))<(float)(1 V))
				ACS_range=ACS_1_VOLT_RANGE;
			else
				ACS_range=ACS_10_VOLT_RANGE;
			
			ACS_Used[i].ACS_slot->set_path(ACS_filter, ACS_range);
			
			ACS_Used[i].ACS_slot->set_level(Vpeak, Voffset, ACS_PEAK_LEVEL);
			ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Vpeak=Vpeak;		
			ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Voffset=Voffset;		
			ACS_Used[i].ACS_slot->card.clock=ACS_divider;
			ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].ClkDivider=ACS_Used[i].ACS_slot->card.clock;	
			for (j=0;j<Ns;j++)
				ACS_Used[i].ACS_slot->load_data(j,(int)(2047.5+2047.5*ACS_buf[j])*16+sync_word*(j==sync_trig));
			ACS_Used[i].ACS_slot->load_data(j,2047*16+1);
			break;

		default:
		{
			char err_message[100];
			sprintf(err_message, "ac_force() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
		}
		}
	}
}

int ac_force_setup(short pin, double Vpeak, double Voffset, double Fi, AcsWaveType mode, short ACS_filter, double PFLP_freq, short sync_pin, short sync_trig)	
{
	return ac_force_setup(pin, float(Vpeak), float(Voffset), float(Fi), mode, ACS_filter, float(PFLP_freq), sync_pin, sync_trig);
}
int ac_force_setup(short pin, float Vpeak, float Voffset, float Fi, AcsWaveType mode, short ACS_filter, float PFLP_freq, short sync_pin, short sync_trig)
{
	



	


	

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int i,j;

	int		err=0;	
	short ACS_mem_depth=32767;
	float ACS_mclock=(float)(64 MHz);
	float ACS_buf[32767];
	float ACS_buf_temp[32767];

	float	Fi_target=Fi;	
	float	Fs;		
	int		Ni;		
	int		Ns;			

	int div=2;
	int ACS_divider=CLK_BY_2;
	short ACS_range=ACS_10_VOLT_RANGE;

	int sync_word=0;
	PFLP_freq=fabs(PFLP_freq);


	if (sync_trig<0) sync_trig=0;
	if (sync_trig>32767) sync_trig=32767;


	if(mode==AUTO_SELECT)	
	{
		if(Fi<=(float)(500 Hz))
			

			mode=WAVE_SIN;
		else if(Fi<=(float)(50 kHz))
		
			mode=FAST_SIN;
		else
	
		
			mode=WAVE_SIN;
	}
	
	if(mode==WAVE_USR)
	{
		char err_message[100];
		sprintf(err_message, "ac_force_setup() -  WAVE_USR requires the waveform array");
		mytext.text_in_box(40,10,err_message);
		err=2;
		return err;
	}


	if(sync_pin!=NULL)
	{
		pin_ptr = group_selection(sync_pin); 
		sync_pin = pin_ptr->grouppin;

		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case ACS:
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT1) sync_word+=2;	
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT2) sync_word+=4;	
				if (Pin_Type_Used[sync_pin][i].Channel==D_R_BIT3) sync_word+=8;	
				break;
			default:
			{
				char err_message[100];
				sprintf(err_message, "ac_force() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				err=2;
				return err;
			}
			}
		}
	}
	
	if((mode==WAVE_SIN)||(mode==WAVE_TRI)||(mode==WAVE_SQR)||(mode==WAVE_CPR)||(mode==WAVE_CNR))
	{
		
		j=0;
		while((Fi<(ACS_mclock/div)/ACS_mem_depth)&&j<14)
		{
			div*=2;
			j++;
		}
		
		Fs=ACS_mclock/div;
		ACS_divider=(j+1)*16;
		
	

		
	
		char 
			s1[10]="",
			s2[10]="";
		bool c1, c2;

		sprintf(s1,"%.3e",Fs);
		sprintf(s2,"%.3e",(float)((int)(Fs)));
		c1=strcmp(s1,s2);
		sprintf(s1,"%.3e",Fi);
		sprintf(s2,"%.3e",(float)((int)(Fi)));
		c2=strcmp(s1,s2);

		while((c1||c2)&&(j<10))
		{
			Fs*=1e1;	
			Fi*=1e1;	
			sprintf(s1,"%.7e",Fs);
			sprintf(s2,"%.7e",(float)((int)(Fs)));
			c1=strcmp(s1,s2);
			sprintf(s1,"%.7e",Fi);
			sprintf(s2,"%.7e",(float)((int)(Fi)));
			c2=strcmp(s1,s2);
			j++;
		}

	
		do{
			
			
			int GCD, a, b, t;
			a=Fi;
			b=Fs;
			while (b != 0)
			{
				t = b;
				b = a % b;
				a = t;
			}

			GCD=a;
		

			Ni=Fi/GCD;
			Ns=Fs/GCD;

		
			if (Ns>ACS_mem_depth)
			{
				Fi=(int)(Fi*1e-1+0.5);
				Fs=(int)(Fs*1e-1+0.5);
			}
		}while (Ns>ACS_mem_depth);


		if(Fi!=Fi_target)
		{
			
		
		
			
			
			

	
	
		
		
		

		
			
			
			float Fi_temp=0.0;
			float Fs_temp=0.0;
			int div_temp;
			int Ns_temp;

			Ni=3;

			for(j=0;j<15;j++)
			{
				div_temp=2.0*(int)(pow(2.0,(double)j));
				Fs_temp=ACS_mclock/div_temp;
				Ns_temp=(int)(0.5+Ni*Fs_temp/Fi_target);
				if((Ns_temp>50)&&(Ns_temp<32767))
					Fi_temp=Fs_temp*(float)Ni/(float)Ns_temp;
				if(abs(Fi-Fi_target)>abs(Fi_temp-Fi_target))
				{
					Fi=Fi_temp;
					Fs=Fs_temp;
					div=div_temp;
					Ns=Ns_temp;
					ACS_divider=(j+1)*16;
				}
			}

			err=1;	
		}

	
		for (j=0;j<Ns;j++)
		{
			switch(mode)
			{
			case WAVE_SIN:
				ACS_buf[j]=2047.5*(1+sin(j*2*PI*Ni/Ns));
				break;
			case WAVE_TRI:
				ACS_buf_temp[j]=sin(j*2*PI*Ni/Ns);
				if(j>0)
				{
					if(ACS_buf_temp[j]>=ACS_buf_temp[j-1]) 
						ACS_buf[j]=1;
					else
						ACS_buf[j]=-1;
				
					ACS_buf[j]= ACS_buf[j-1]+ACS_buf[j]*4*2047/(Ns/Ni);
				}
				else
					ACS_buf[j]= 2047;
				break;
			case WAVE_SQR:
				ACS_buf[j]=sin(j*2*PI*Ni/Ns);
				if(ACS_buf[j]>=0) 
					ACS_buf[j]=4095;
				else
					ACS_buf[j]=0;
				break;
			case WAVE_CPR:
				ACS_buf[j]= 2047*(1+j/(float)(Ns/Ni)-(int)(j/(Ns/Ni)));
				break;
			case WAVE_CNR:
				ACS_buf[j]= 2047*(1-j/(float)(Ns/Ni)+(int)(j/(Ns/Ni)));
				break;
			}
		}
	}
	
	pin_ptr = group_selection(pin); 
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);

		switch(Source_type)
		{
		case NONE: break;	

		case ACS:

			if(((fabs(Vpeak)+fabs(Voffset))<(float)(1 V))&&(ACS_filter!=ACS_LC_FILTER))
				ACS_range=ACS_1_VOLT_RANGE;
			else
				ACS_range=ACS_10_VOLT_RANGE;

			
			if(ACS_filter==ACS_FILTER_NULL)
			{
				if((mode==WAVE_SIN)||(mode==FAST_SIN))
				{
					if(Fi<=(float)(50 kHz))
						ACS_filter=ACS_100K_FILTER;
					else 
						ACS_filter=ACS_BASE_FILTER;
				}
				else 
					ACS_filter=ACS_BASE_FILTER;
			}

			if(ACS_filter==ACS_MAIN_FILTER)	
			{
				int code;
				
				if (PFLP_freq==0)
					PFLP_freq=10*Fi;

				
				if(PFLP_freq<(float)(10 kHz))
					PFLP_freq=(float)(10 kHz);
				
				
				if(PFLP_freq>(float)(200 kHz))
					PFLP_freq=(float)(200 kHz);

				
				code=6.7168537e1+1.9678835e-2*PFLP_freq-3.787336e-8*pow((double)PFLP_freq,2.0);
				
				ACS_Used[i].ACS_slot->set_bw_ref(code, code);
			}
			
			ACS_Used[i].ACS_slot->set_path(ACS_filter, ACS_range);
			
			ACS_Used[i].ACS_slot->set_level(Vpeak, Voffset, ACS_PEAK_LEVEL);
			ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Vpeak=Vpeak;			
			ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Voffset=Voffset;	
			switch(mode)
			{
			case WAVE_SIN:
			case WAVE_TRI:
			case WAVE_SQR:
			case WAVE_CPR:
			case WAVE_CNR:
				ACS_Used[i].ACS_slot->card.clock=ACS_divider;
				ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].ClkDivider=ACS_Used[i].ACS_slot->card.clock;	
				for (j=0;j<Ns;j++)
					ACS_Used[i].ACS_slot->load_data(j,(int)(0.5+ACS_buf[j])*16+sync_word*(j==sync_trig));
				ACS_Used[i].ACS_slot->load_data(j,2047*16+1);	
				break;
			case FAST_SIN:
				ACS_Used[i].ACS_slot->ldram(Fi);
				ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].ClkDivider=ACS_Used[i].ACS_slot->card.clock;	
				break;
			}
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "ac_force_setup() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				err=2;
				return err;
			}
		}
	}
	
	return err;
}


void ac_force(short pin, double Vpeak, double Fi, AcsWaveType mode)	
{



	ac_force(pin, (float)(Vpeak), (float)(0 V), (float)(Fi), mode);
}

void ac_force(short pin, float Vpeak, float Fi, AcsWaveType mode)
{



	ac_force(pin, Vpeak, (float)(0 V), Fi, mode);
}

void ac_force(short pin, double Vpeak, double Voffset, double Fi, AcsWaveType mode, short ACS_filter, double PFLP_freq, short sync_pin, short sync_trig)	
{
	ac_force(pin, float(Vpeak), float(Voffset), float(Fi), mode, ACS_filter, float(PFLP_freq), sync_pin, sync_trig);
}
void ac_force(short pin, float Vpeak, float Voffset, float Fi, AcsWaveType mode, short ACS_filter, float PFLP_freq, short sync_pin, short sync_trig)
{

	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int i;

	pin_ptr = group_selection(pin); 

	
	ac_force_setup(pin, Vpeak, Voffset, Fi, mode, ACS_filter, PFLP_freq, sync_pin, sync_trig);
	wait.delay_10_us(50);
	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;

		case ACS:
			ACS_Used[i].ACS_slot->start();
			break;

		default:
			{
				char err_message[100];
				sprintf(err_message, "ac_force() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
		}
	}
}

void ac_force(short pin, AcsActionType Action, short ActionParam)
{











	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int i;
	int ScaleFactor;
	int NewDivider;
	float acs_level;
	float acs_offset;
	STRING acs_scale;

	pin_ptr = group_selection(pin); 
	
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ ) if(active_site[i])
	{
		Source_type=pin_selection(pin,i);
		switch(Source_type)
		{
		case NONE: break;

		case ACS:
			switch (Action)
			{
			case ACS_START:
				if(ActionParam==ACS_DEFAULT_PARAM)	
					ActionParam=ACS_INT_CLK;

				if((ActionParam==ACS_INT_CLK)||(ActionParam==ACS_EXT_CLK))
				{
				
					ACS_Used[i].ACS_slot->get_level (acs_level, acs_offset, acs_scale);
					if(acs_offset!=ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Voffset)
						ACS_Used[i].ACS_slot->set_level(ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Vpeak, ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Vpeak, ACS_PEAK_LEVEL);	
					ACS_Used[i].ACS_slot->start(ActionParam);
				}
				else
				{
					MessageBox(NULL,"ac_force(): wrong parameter for action ACS_START","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					return;
				}
				break;
			case ACS_STOP:
				if(ActionParam==ACS_DEFAULT_PARAM)
					ActionParam=ACS_KEEP_OFFSET;

				switch (ActionParam)
				{
				case ACS_CLEAR_OFFSET:
					ACS_Used[i].ACS_slot->set_level(ACS_Card_Used[Pin_Type_Used[pin][i].Slot-1].Vpeak, 0.0f, ACS_PEAK_LEVEL);	
				case ACS_KEEP_OFFSET:
					ACS_Used[i].ACS_slot->stop();
					break;
				default:
					MessageBox(NULL,"ac_force(): wrong parameter for action ACS_STOP","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					return;
				}
				break;
			case ACS_SCALE_FREQUENCY:
				switch (ActionParam)
				{
					case ACS_FREQ_MUL_BY_2:		ScaleFactor=-0x0010;	break;
					case ACS_FREQ_MUL_BY_4:		ScaleFactor=-0x0020;	break;
					case ACS_FREQ_MUL_BY_8:		ScaleFactor=-0x0030;	break;
					case ACS_FREQ_MUL_BY_16:	ScaleFactor=-0x0040;	break;
					case ACS_FREQ_MUL_BY_32:	ScaleFactor=-0x0050;	break;
					case ACS_FREQ_MUL_BY_64:	ScaleFactor=-0x0060;	break;
					case ACS_FREQ_MUL_BY_128:	ScaleFactor=-0x0070;	break;
					case ACS_FREQ_MUL_BY_256:	ScaleFactor=-0x0080;	break;	
					case ACS_FREQ_MUL_BY_512:	ScaleFactor=-0x0090;	break;	
					case ACS_FREQ_MUL_BY_1024:	ScaleFactor=-0x00A0;	break;
					case ACS_FREQ_MUL_BY_2048:	ScaleFactor=-0x00B0;	break;
					case ACS_FREQ_MUL_BY_4096:	ScaleFactor=-0x00C0;	break;
					case ACS_FREQ_MUL_BY_8192:	ScaleFactor=-0x00D0;	break;
					case ACS_FREQ_MUL_BY_16384:	ScaleFactor=-0x00E0;	break;
					case ACS_FREQ_DIV_BY_2:		ScaleFactor=0x0010;		break;	
					case ACS_FREQ_DIV_BY_4:		ScaleFactor=0x0020;		break;	
					case ACS_FREQ_DIV_BY_8:		ScaleFactor=0x0030;		break;	
					case ACS_FREQ_DIV_BY_16:	ScaleFactor=0x0040;		break;	
					case ACS_FREQ_DIV_BY_32:	ScaleFactor=0x0050;		break;	
					case ACS_FREQ_DIV_BY_64:	ScaleFactor=0x0060;		break;	
					case ACS_FREQ_DIV_BY_128:	ScaleFactor=0x0070;		break;	
					case ACS_FREQ_DIV_BY_256:	ScaleFactor=0x0080;		break;	
					case ACS_FREQ_DIV_BY_512:	ScaleFactor=0x0090;		break;	
					case ACS_FREQ_DIV_BY_1024:	ScaleFactor=0x00A0;		break;
					case ACS_FREQ_DIV_BY_2048:	ScaleFactor=0x00B0;		break;
					case ACS_FREQ_DIV_BY_4096:	ScaleFactor=0x00C0;		break;
					case ACS_FREQ_DIV_BY_8192:	ScaleFactor=0x00D0;		break;
					case ACS_FREQ_DIV_BY_16384:	ScaleFactor=0x00E0;		break;
					default: 
						MessageBox(NULL,"ac_force(): wrong parameter for action ACS_SCALE_FREQUENCY","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
						return;
				}

				NewDivider=(ACS_Used[i].ACS_slot->card.clock+ScaleFactor);
				if((NewDivider<0x0010)||(NewDivider>0x00F0))
				{
					MessageBox(NULL,"ac_force_setup(): wrong clock divider!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					return;
				}
				else
					ACS_Used[i].ACS_slot->card.clock=NewDivider;
					ACS_Used[i].ACS_slot->start(ACS_INT_CLK);
				break;
			default:
				MessageBox(NULL,"ac_force(): action not supported!","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				return;
			}
			break;

		default:
			{
				char error_msg[100];
				sprintf(error_msg, "ac_force() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				return;
			}
		}
	}
}



void ac_measure_setup(short pin, short rms_range, short coupling)
{
	sfloat dummy={0.0};
	
	ac_measure(pin, dummy ,0, rms_range, coupling);	
}

void ac_measure(short pin, float *res_ptr ,short ave_num, short rms_range, short coupling, short wait_us)
{
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;
	int i=0;

	pin_ptr = group_selection(pin); 
	
	bool SetMeasDue=true;	

	unsigned short
		status_reg_4_val,
		status_sel_swt_ad,
		status_m_range;

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
		
			status_reg_4_val=ACS_Used[i].ACS_slot->card.reg_4_val;
			status_sel_swt_ad=ACS_Used[i].ACS_slot->card.sel_swt_ad;
			status_m_range=ACS_Used[i].ACS_slot->card.m_range;

			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case ACS:
				switch(Pin_Type_Used[pin][i].Channel)
				{
				case D_RMS_CH1:
					if(
						((status_reg_4_val&CH1_AC_COUP)==coupling)&&
						(status_sel_swt_ad==SEL_ADC_IN0)&&
						(status_m_range==rms_range)
					  )
						SetMeasDue=false;
					else
						ACS_Used[i].ACS_slot->set_meas_mode(ACS_CHANNEL_1, rms_range, coupling);
					break;

				case D_RMS_CH2:
					if(
						((status_reg_4_val&CH2_AC_COUP)==coupling)&&
						(status_sel_swt_ad==SEL_ADC_IN1)&&
						(status_m_range==rms_range)
					  )
						SetMeasDue=false;
					else
						ACS_Used[i].ACS_slot->set_meas_mode(ACS_CHANNEL_2, rms_range, coupling);
					break;

				case D_RMS_CH3:
					if(
						((status_reg_4_val&CH3_AC_COUP)==coupling)&&
						(status_sel_swt_ad==SEL_ADC_IN2)&&
						(status_m_range==rms_range)
					  )
						SetMeasDue=false;
					else
						ACS_Used[i].ACS_slot->set_meas_mode(ACS_CHANNEL_3, rms_range, coupling);
					break;

				case D_RMS_CH4:
					if(
						((status_reg_4_val&CH4_AC_COUP)==coupling)&&
						(status_sel_swt_ad==SEL_ADC_IN3)&&
						(status_m_range==rms_range)
					  )
						SetMeasDue=false;
					else
						ACS_Used[i].ACS_slot->set_meas_mode(ACS_CHANNEL_4, rms_range, coupling);
					break;

				default:
				{
					char err_message[100];
					sprintf(err_message, "ac_measure() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return;
				}
				}
	
				if(SetMeasDue&&(ave_num>0))
					wait.delay_10_us(int(wait_us/10));
				
				if(ave_num > 0)
					*(res_ptr + i) = ACS_Used[i].ACS_slot->measure(ave_num);

				SetMeasDue=true;
				break;

			default:
			{
				char err_message[100];
				sprintf(err_message, "ac_measure() not executable for pin %s",Pin_Type_Used[pin][i].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			}
		}
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}





void float_to_str(float value, char *string)
  {


  













  

  

  






  
  double oom;		
  char *suffix;		
  char format[100];	
  char sci_string[100];
  char val_string[100];
  int len;				
  int ds_pos;		
  int sd;			
  int dd;			
 

  if(value==0)
    oom=1.0;
  else
    {
    oom=log10(fabs((double)value));
    oom=pow(10.0,(double)(3*(int)(oom/3)-((int)(oom/3)!=(oom/3))*(oom<0)*3));	
    }
    
  suffix="";
  if(oom==1e-12) suffix="p";
  if(oom==1e-9)  suffix="n";
  if(oom==1e-6)  suffix="u";
  if(oom==1e-3)  suffix="m";
  if(oom==1e3)   suffix="k";
  if(oom==1e6)   suffix="M";
  if(oom==1e9)   suffix="G";
  if(oom==1e12)  suffix="T";
 
  sprintf(sci_string,"%.6e\0",value);
  sprintf(val_string,"%f\0",value/oom);


  len=strlen(sci_string);
  for(sd=len-1;sci_string[sd]!='e';sd--);
  for(sd--;sci_string[sd]=='0';sd--);
  for(ds_pos=0;val_string[ds_pos]!='.';ds_pos++);
  dd=sd-ds_pos;
  if(dd<0) dd=0;
  
  if((fabs(value)==0.0)||((1e-12<=fabs(value))&&(fabs(value)<1e15))) 
    {

    sprintf(format,"%%.%if%%s\0",dd);

    sprintf(string,format,value/oom,suffix);
    }
  else
    {

    sprintf(format,"%%.%ie\0",dd);

    sprintf(string,format,value);
    }
}

int CSC_DDD_NON_LOOP_PAT_BASE_ADDR=DDD_MEM_DEPTH;

struct DDD_Pattern_Element
{
	MS_DDD_Pattern		Pattern;
	char				*pat_name;
	DDD_Pattern_Element	*nextptr;
	DDD_Pattern_Element	*prevptr;
} *DDD_Pattern_List=NULL, *DDD_Last_Pattern=NULL;

MS_DDD_Pattern::MS_DDD_Pattern()
{
	int i;
	
	ddd_pat_name=NULL;
	ddd_pat_lenght=0;
	ddd_pat_end_loop_address=DDD_MEM_DEPTH;

	ddd_pat_site_list.ddd_active_sites=0x0;
	ddd_pat_site_list.ddd_pat_start_address=-1;
	ddd_pat_site_list.ddd_master_first_vector_string[0]='\0';
	for (i=0;i<21;i++)
		ddd_pat_site_list.ddd_enable_card[i]=false;
	ddd_pat_site_list.ddd_pat_loopable=false;		
	ddd_pat_site_list.ddd_nextptr=NULL;		
	ddd_pat_site_list.ddd_prevptr=NULL;		

	ddd_pat_name=NULL;

	ddd_pin_list.ddd_pin_name=NULL;
	ddd_pin_list.ddd_pin_ref=NULL;
	ddd_pin_list.ddd_pin_order=0;
	ddd_pin_list.ddd_nextptr=NULL;
	ddd_pin_list.ddd_prevptr=NULL;

	ddd_vect_list.ddd_vect_number=0;
	ddd_vect_list.ddd_vect_string=NULL;
	ddd_vect_list.ddd_compare_vect=false;
	ddd_vect_list.ddd_vect_label=NULL;
	ddd_vect_list.ddd_nextptr=NULL;
	ddd_vect_list.ddd_prevptr=NULL;
	ddd_vect_list.ddd_nexttagptr=NULL;
	ddd_vect_list.ddd_prevtagptr=NULL;
	ddd_vect_list.ddd_nextcompptr=NULL;
	ddd_vect_list.ddd_prevcompptr=NULL;
	ddd_last_vect_ptr=&ddd_vect_list;

	ddd_tag_vect_list=NULL;

	ddd_comp_vect_list=NULL;
	ddd_last_comp_vect_ptr=NULL;	

	ddd_label_to_add=NULL;

	for (i=0;i<21;i++)
		card_receive_mask[i]=0;
}

MS_DDD_Pattern::~MS_DDD_Pattern()	
{

	delete ddd_pat_name;


	ddd_pat_site_address *pat_site_address_ptr;
	pat_site_address_ptr=&ddd_pat_site_list;
	

	while(pat_site_address_ptr->ddd_nextptr)
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;


	while(pat_site_address_ptr->ddd_prevptr)
	{
		pat_site_address_ptr=pat_site_address_ptr->ddd_prevptr;
		free(pat_site_address_ptr->ddd_nextptr);
	}
		

	ddd_pin *pin_list_ptr;
	pin_list_ptr=&ddd_pin_list;	
	

	while(pin_list_ptr->ddd_nextptr)
		pin_list_ptr=pin_list_ptr->ddd_nextptr;


	while(pin_list_ptr->ddd_prevptr)
	{
		pin_list_ptr=pin_list_ptr->ddd_prevptr;
		free(pin_list_ptr->ddd_nextptr);
		delete pin_list_ptr->ddd_pin_name;
	}


	ddd_vect *vect_list_ptr;


	vect_list_ptr=ddd_last_vect_ptr;


	while(vect_list_ptr->ddd_prevptr)
	{
		vect_list_ptr=vect_list_ptr->ddd_prevptr;
		free(vect_list_ptr->ddd_nextptr);
		delete vect_list_ptr->ddd_vect_string;

		if(vect_list_ptr->ddd_vect_label!=NULL)
			delete(vect_list_ptr->ddd_vect_label);
	}

	if(ddd_label_to_add!=NULL)
		delete(ddd_label_to_add);

}


void MS_DDD_Pattern::Set_Pattern_Name(const char *name)
{


	if (name!=NULL)
	{
		delete  ddd_pat_name;
		ddd_pat_name=new char[strlen(name)+1];
		strcpy(ddd_pat_name,name);
	}
}

void MS_DDD_Pattern::Add_Pin_Name(const char *name)
{


	int pin=0;
	int site;
	ddd_pin *pin_list_ptr;

	pin_list_ptr=&ddd_pin_list;	
	
	
	while(pin_list_ptr->ddd_pin_name)
		pin_list_ptr=pin_list_ptr->ddd_nextptr;

	if ((pin=Pin_Name_To_Pin_Ref(name))<0)
	{
		
		char *error_msg;
		error_msg=new char[50+strlen(name)+strlen(ddd_pat_name)];
		sprintf(error_msg,"Pin \"%s\" not found in pinmap; check pattern %s", name, ddd_pat_name);
		MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		delete error_msg;
		exit(0);
	}
	else
	
	{
		
		for( site = 0; site < max_sites ; site++ )
			if(pin_selection(pin,site)==DDD)
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_ptr=DDD_Used[site].DDD_slot;
			else
			{
				char *error_msg;
				error_msg=new char[50+strlen(name)+strlen(ddd_pat_name)];
				sprintf(error_msg,"Pattern %s: pin \"%s\" not connected to DDD in pinmap", ddd_pat_name, name);
				MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				delete error_msg;
				exit(0);
			}
	
		pin_list_ptr->ddd_pin_ref=Pin_Type_Used[pin][0].Pin_Ref;
		pin_list_ptr->ddd_pin_name=new char[strlen(name)+1];
		strcpy(pin_list_ptr->ddd_pin_name,name);
		
		
		pin_list_ptr->ddd_nextptr=(ddd_pin *)malloc(sizeof(ddd_pin));
		if (pin_list_ptr->ddd_nextptr == NULL)
		{
			MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}
		pin_list_ptr->ddd_nextptr->ddd_pin_name=NULL;
		pin_list_ptr->ddd_nextptr->ddd_pin_ref=NULL;
		pin_list_ptr->ddd_nextptr->ddd_pin_order=pin_list_ptr->ddd_pin_order+1;
		pin_list_ptr->ddd_nextptr->ddd_nextptr=NULL;
		pin_list_ptr->ddd_nextptr->ddd_prevptr=pin_list_ptr;

	}
}


void MS_DDD_Pattern::Tag_Vector(char *label)
{
	

	ddd_vect *vect_list_ptr;
	bool found_label=false;
	char *error_msg;

	error_msg=new char[50+strlen(label)+strlen(ddd_pat_name)];

	if(strlen(label)<2)
		{
			sprintf(error_msg,"Invalid label in pattern %s", ddd_pat_name);
			MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}
	
	
	vect_list_ptr=ddd_last_vect_ptr;

	while(vect_list_ptr->ddd_prevtagptr!=NULL)
	{
		if(!strcmp(vect_list_ptr->ddd_prevtagptr->ddd_vect_label,label))
			found_label=true;
		vect_list_ptr=vect_list_ptr->ddd_prevtagptr;
	}
	
	if(found_label)
		{
			sprintf(error_msg,"Duplicate label \"%s\" in pattern %s", label, ddd_pat_name);
			MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}
	else
	{
		ddd_label_to_add=new char[strlen(label)+1];
		strcpy(ddd_label_to_add,label);
	
		
		if(ddd_tag_vect_list==NULL)
			ddd_tag_vect_list=ddd_last_vect_ptr;
	}

	delete(error_msg);

}


void MS_DDD_Pattern::Add_Vector(const char *vect)
{
	

	int i;
	char c;
	
	ddd_last_vect_ptr->ddd_vect_string=new char[strlen(vect)+1];
	strcpy(ddd_last_vect_ptr->ddd_vect_string,vect);

	for(i=0; i<(int)strlen(vect);i++)
	{
		c=tolower(vect[i]);
		if((c==('l'))||(c==('h')))
		{
				
			ddd_last_vect_ptr->ddd_compare_vect=true;

			
			
			if(ddd_last_vect_ptr->ddd_prevcompptr!=NULL)
				ddd_last_vect_ptr->ddd_prevcompptr->ddd_nextcompptr=ddd_last_vect_ptr;
			
		
			if(ddd_comp_vect_list==NULL)
				ddd_comp_vect_list=ddd_last_vect_ptr;

			ddd_last_comp_vect_ptr=ddd_last_vect_ptr;	
		}
	}


	if(ddd_label_to_add!=NULL)
	{

		ddd_last_vect_ptr->ddd_vect_label=new char[strlen(ddd_label_to_add)+1];
		strcpy(ddd_last_vect_ptr->ddd_vect_label,ddd_label_to_add);


		delete(ddd_label_to_add);
		ddd_label_to_add=NULL;

		if(ddd_last_vect_ptr->ddd_prevtagptr!=NULL)
			ddd_last_vect_ptr->ddd_prevtagptr->ddd_nexttagptr=ddd_last_vect_ptr;
	
	}
	
	
	ddd_last_vect_ptr->ddd_nextptr=(ddd_vect *)malloc(sizeof(ddd_vect));
	if (ddd_last_vect_ptr->ddd_nextptr == NULL)
	{
		MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		exit(0);
	}


	ddd_last_vect_ptr->ddd_nextptr->ddd_vect_number=ddd_last_vect_ptr->ddd_vect_number+1;
	ddd_last_vect_ptr->ddd_nextptr->ddd_vect_string=NULL;
	ddd_last_vect_ptr->ddd_nextptr->ddd_compare_vect=false;
	ddd_last_vect_ptr->ddd_nextptr->ddd_vect_label=NULL;
	ddd_last_vect_ptr->ddd_nextptr->ddd_nextptr=NULL;
	ddd_last_vect_ptr->ddd_nextptr->ddd_prevptr=ddd_last_vect_ptr;
	ddd_last_vect_ptr->ddd_nextptr->ddd_nexttagptr=NULL;
	
	if(ddd_last_vect_ptr->ddd_vect_label!=NULL)
	
		ddd_last_vect_ptr->ddd_nextptr->ddd_prevtagptr=ddd_last_vect_ptr;
	else
	
		ddd_last_vect_ptr->ddd_nextptr->ddd_prevtagptr=ddd_last_vect_ptr->ddd_prevtagptr;

	ddd_last_vect_ptr->ddd_nextptr->ddd_nextcompptr=NULL;
	if(ddd_last_vect_ptr->ddd_compare_vect)

		ddd_last_vect_ptr->ddd_nextptr->ddd_prevcompptr=ddd_last_vect_ptr;
	else

		ddd_last_vect_ptr->ddd_nextptr->ddd_prevcompptr=ddd_last_vect_ptr->ddd_prevcompptr;


	ddd_last_vect_ptr=ddd_last_vect_ptr->ddd_nextptr;

	ddd_pat_lenght++;
	
}

int MS_DDD_Pattern::Upload_Pattern(int pattern_address)
{
	

	int			pin=0;				
	int			site=0;				
	int			slot=0;				
	int			vect_count=0;		
	ddd_pin		*pin_list_ptr;
	ddd_vect	*vect_list_ptr;

	ddd_pat_site_address *pat_site_address_ptr;
	pat_site_address_ptr=&ddd_pat_site_list;	
	
	Ddd *DDD_7_ptr=&ddd_cards[board_ptr[BOARD_7]];
	bool slave_boards_present=false;



	while(pat_site_address_ptr->ddd_nextptr)
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;

	
	for( site = 0; site < max_sites ; site++ )
		if(active_site[site]) 
			pat_site_address_ptr->ddd_active_sites|=(0x1)<<site;

	pat_site_address_ptr->ddd_pat_start_address=pattern_address;


	for( slot = 0; slot < 21 ; slot++ )
		pat_site_address_ptr->ddd_enable_card[slot]=false;


	pin_list_ptr=&ddd_pin_list;
	while(pin_list_ptr->ddd_pin_name)
	{	
		pin=pin_list_ptr->ddd_pin_ref;

		for( site = 0; site < max_sites ; site++ ) 
			if((active_site[site])&&(((pat_site_address_ptr->ddd_active_sites)>>site)&0x1))
				pat_site_address_ptr->ddd_enable_card[Pin_Type_Used[pin][site].Slot-1]=true;
	
		pin_list_ptr=pin_list_ptr->ddd_nextptr;
	}


	pat_site_address_ptr->ddd_nextptr=(ddd_pat_site_address *)malloc(sizeof(ddd_pat_site_address));
	if (pat_site_address_ptr->ddd_nextptr == NULL)
	{
		MessageBox(NULL,"Insufficient memory available","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		exit(0);
	}

	pat_site_address_ptr->ddd_nextptr->ddd_active_sites=0x0;
	pat_site_address_ptr->ddd_nextptr->ddd_pat_start_address=-1;
	pat_site_address_ptr->ddd_nextptr->ddd_master_first_vector_string[0]='\0';
	for(slot=0; slot<21;slot++)
		pat_site_address_ptr->ddd_nextptr->ddd_enable_card[slot]=false;
	pat_site_address_ptr->ddd_nextptr->ddd_pat_loopable=false;		
	pat_site_address_ptr->ddd_nextptr->ddd_nextptr=NULL;
	pat_site_address_ptr->ddd_nextptr->ddd_prevptr=pat_site_address_ptr;
		
	

	vect_list_ptr=&ddd_vect_list;	
	while(vect_list_ptr->ddd_nextptr!=NULL)
	{
		for(slot=0;slot<21;slot++) if(DDD_Card_Used[slot].card_ptr!=NULL)
		{
			
			strcpy(DDD_Card_Used[slot].vector_string,"XXXXXXXX");
			
			DDD_Card_Used[slot].ddd_pat_end_loop_address=-1;	
		}


		pin_list_ptr=&ddd_pin_list;
		while(pin_list_ptr->ddd_pin_name)
		{	
			pin=pin_list_ptr->ddd_pin_ref;

			for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
			{
				pin_selection(pin,site);

				switch(vect_list_ptr->ddd_vect_string[pin_list_ptr->ddd_pin_order])
				{
					case '0': 
						DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='0';
						break;
					case '1': 
						DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='1';
						break;
					case 't': 
					case 'T': 
						DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='T';
						break;
					case 'z': 
					case 'Z': 
						DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='Z';
						break;
					case 'l':
					case 'L':
					case 'h':
					case 'H':
					case 'c':
					case 'C':
						card_receive_mask[Pin_Type_Used[pin][site].Slot-1]|=(0x1)<<(Pin_Type_Used[pin][site].Channel-1);
					case 'x':
					case 'X':
					case 's':
					case 'S':
						DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='X';
						break;
					default:
						MessageBox(NULL,"Invalid logic level","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
						exit(0);
				} 
			}

			pin_list_ptr=pin_list_ptr->ddd_nextptr;
		} 

		
		for(slot=0;slot<21;slot++) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
			DDD_Card_Used[slot].card_ptr->ddd_load_pattern(pat_site_address_ptr->ddd_pat_start_address+vect_count,DDD_Card_Used[slot].vector_string);

		
		if(!strcmp(pat_site_address_ptr->ddd_master_first_vector_string,""))
			strcpy(pat_site_address_ptr->ddd_master_first_vector_string,DDD_Card_Used[7-1].vector_string);

		
		vect_list_ptr=vect_list_ptr->ddd_nextptr;
		vect_count++;

	} 

	return(pat_site_address_ptr->ddd_pat_start_address+vect_count);
}


int MS_DDD_Pattern::Make_Pattern_Loopable(ddd_pat_site_address *pat_site_address_ptr)
{
	

	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;

	ddd_pat_site_address	*temp_pat_site_address_ptr;

	
	if(ddd_pat_lenght<CSC_DDD_NON_LOOP_PAT_BASE_ADDR)
	{
		
		while(DDD_Pattern_Ptr!=NULL)
		{
			temp_pat_site_address_ptr=&(DDD_Pattern_Ptr->Pattern.ddd_pat_site_list);
		
			while(temp_pat_site_address_ptr!=NULL)
			{
				temp_pat_site_address_ptr->ddd_pat_loopable=false;

				
				if(temp_pat_site_address_ptr->ddd_pat_start_address==0)
				{
					if(temp_pat_site_address_ptr->ddd_nextptr)
						temp_pat_site_address_ptr->ddd_nextptr->ddd_prevptr=temp_pat_site_address_ptr->ddd_prevptr;
	
					if(temp_pat_site_address_ptr->ddd_prevptr)
						temp_pat_site_address_ptr->ddd_prevptr->ddd_nextptr=temp_pat_site_address_ptr->ddd_nextptr;


					free(temp_pat_site_address_ptr);

					temp_pat_site_address_ptr=NULL;
				} 
				else 
					temp_pat_site_address_ptr=temp_pat_site_address_ptr->ddd_nextptr;
			}

			DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;
		}

		
		
		Upload_Pattern(0);

		pat_site_address_ptr->ddd_pat_loopable=true;
	}
	else
	{
		MessageBox(NULL,"Not enough memory to run this pattern in loop mode","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return 1;
	}

	return 0;
}

void MS_DDD_Pattern::Upload_Dig_Source_Vector(short pin_list, unsigned long write_word, char *entry_label, int displacement)
{
	sulong			s_write_word={0};
	int				site;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		s_write_word[site]=write_word;

	Upload_Dig_Source_Vector(pin_list, s_write_word, entry_label, displacement);
}

void MS_DDD_Pattern::Upload_Dig_Source_Vector(short pin_list, sulong write_word, char *entry_label, int displacement)
{
	
	

	DYN_GROUP_LIST			*pin_ptr;
	DYN_GROUP_LIST			*start_pin_ptr;

	int			pin;					
	int			site=0;				
	int			slot=0;				
	int			vect_count=0;		
	ddd_pin		*pin_list_ptr;
	ddd_vect	*vect_list_ptr;
	ddd_vect	*tag_vect_list_ptr;

	bool		label_found=false;
	char		*label;
	int			d;

	sulong write_word_temp={0};
	sulong write_word_reversed={0};

	ddd_pat_site_address *pat_site_address_ptr;
	pat_site_address_ptr=&ddd_pat_site_list;	
	
	
	unsigned long int active_sites_mask=0x0;
	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		active_sites_mask|=(0x1)<<site;


	while((pat_site_address_ptr)&&(pat_site_address_ptr->ddd_active_sites!=active_sites_mask))
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;

	
	if(pat_site_address_ptr==NULL)
		pat_site_address_ptr=&ddd_pat_site_list;

	
	tag_vect_list_ptr=ddd_tag_vect_list;
	
	if(entry_label!=NULL)
	{
		label=new char[strlen(entry_label)+1];

		for(int c=0; c<(int)strlen(entry_label);c++)
			label[c]=tolower(entry_label[c]);
	
		label[c]='\0';
		
		
		while((tag_vect_list_ptr!=NULL)&&(!label_found))
		{
			if(!strcmp(tag_vect_list_ptr->ddd_vect_label,label))
			{
				label_found=true;
				vect_list_ptr=tag_vect_list_ptr;
			}
			tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
		}
			
		if(!label_found)
		{
			MessageBox(NULL,"Label not found","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}

		delete label;
	}

	
	d=displacement;
	while((d>0)&&(vect_list_ptr!=NULL))
	{
		vect_list_ptr=vect_list_ptr->ddd_nextptr;
		d--;
	}


	for( slot = 0; slot < 21 ; slot++ )
		DDD_Card_Used[slot].flag=false;

	
	start_pin_ptr = group_selection(pin_list);  

	int pin_list_lenght=0;
	
	pin_ptr=start_pin_ptr;
	do
	{
		pin = pin_ptr->grouppin;

		
		pin_list_ptr=&ddd_pin_list;	
		while((pin_list_ptr!=NULL)&&(pin_list_ptr->ddd_pin_ref!=Pin_Type_Used[pin][0].Pin_Ref))
			pin_list_ptr=pin_list_ptr->ddd_nextptr;

		if(pin_list_ptr==NULL)
		{
			char *error_msg;
			error_msg=new char[50+strlen(Pin_Type_Used[pin][0].Pin_Name)+strlen(ddd_pat_name)];
			sprintf(error_msg,"Pin \"%s\" not found in pattern %s", Pin_Type_Used[pin][0].Pin_Name, ddd_pat_name);	
			MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			delete error_msg;
			exit(0);
		}
		else
			
			pin_list_lenght++;

		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

	
	for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
	{
		write_word_temp[site]=write_word[site];	
		for(int i=0;i<pin_list_lenght;i++)
		{
			write_word_reversed[site]<<=1;								
			write_word_reversed[site]|=(write_word_temp[site]&(0x1));	
			write_word_temp[site]>>=1;									
		}
	}
	
	
	for(slot=0;slot<21;slot++) if(DDD_Card_Used[slot].card_ptr!=NULL)
		strcpy(DDD_Card_Used[slot].vector_string,"XXXXXXXX");


	pin_list_ptr=&ddd_pin_list;
	while(pin_list_ptr->ddd_pin_name)
	{	
		pin=pin_list_ptr->ddd_pin_ref;

		for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
		{
			pin_selection(pin,site);

			switch(vect_list_ptr->ddd_vect_string[pin_list_ptr->ddd_pin_order])
			{
				case '0': 
					DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='0';
					break;
				case '1': 
					DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='1';
					break;
				case 't': 
				case 'T': 
					DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='T';
					break;
				case 'z': 
				case 'Z': 
					DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='Z';
					break;
				case 'l':
				case 'L':
				case 'h':
				case 'H':
				case 'c':
				case 'C':
					card_receive_mask[Pin_Type_Used[pin][site].Slot-1]|=(0x1)<<(Pin_Type_Used[pin][site].Channel-1);
				case 'x':
				case 'X':
				case 's':
				case 'S':
					
					write_word_temp[site]=write_word_reversed[site];
					
					
					pin_ptr=start_pin_ptr;
					while(pin_ptr!=NULL)
					{
						if(pin_ptr->grouppin==pin)
						{
							DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].flag=true;
							
							if((write_word_temp[site]&(0x1))==1)
								DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='1';
							else
								DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].vector_string[8-Pin_Type_Used[pin][site].Channel]='0';
						}

						
						write_word_temp[site]>>=1;
						
						pin_ptr=pin_ptr->nextptr;
					}
					break;
				default:
					MessageBox(NULL,"Invalid logic level","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					exit(0);
			} 
		}

		pin_list_ptr=pin_list_ptr->ddd_nextptr;
	} 
	
	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].flag)
	{
if(!debug_ddd_msl_offline)	
		DDD_Card_Used[slot].card_ptr->ddd_load_pattern(pat_site_address_ptr->ddd_pat_start_address+vect_list_ptr->ddd_vect_number,DDD_Card_Used[slot].vector_string);	
		DDD_Card_Used[slot].flag=false;
	}
}

int MS_DDD_Pattern::Get_Num_Pins()
{
	int pin=0;
	ddd_pin *pin_list_ptr;

	pin_list_ptr=&ddd_pin_list;	
	
	
	while(pin_list_ptr->ddd_pin_name)
	{
		pin_list_ptr=pin_list_ptr->ddd_nextptr;
		pin++;
	}

	return pin;
}


void MS_DDD_Pattern::Run_Pattern(unsigned short pattern_mode, int start_displacement, int stop_displacement)	
{








	

	int			pin=0;
	int			site=0;
	int			slot=0;
	int			ch=0;
	ddd_pin		*pin_list_ptr;
	int			start_address, stop_address;	
	char		ErrorMessage[100];	

	bool loop=false;
	bool wait_pattern_end=false;
	switch(pattern_mode)
	{
	case DDD_WAIT_PATTERN_END: 
		loop=false;
		wait_pattern_end=true;
		break;
	case DDD_RETURN_AFTER_PATTERN_START:
		loop=false; 
		wait_pattern_end=false;
		break;
	case DDD_LOOP_PATTERN:
		loop=true; 
		wait_pattern_end=false;
		break;
	default:
		MessageBox(NULL,"Invalid pattern mode","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		exit(0);
	}


	pin_list_ptr=&ddd_pin_list;	
	
	Ddd *DDD_7_ptr=&ddd_cards[board_ptr[BOARD_7]];	
	int ddd_slave_board_counter=0;


	ddd_pat_site_address *pat_site_address_ptr;
	pat_site_address_ptr=&ddd_pat_site_list;
		
	
	for( slot = 0; slot < 21 ; slot++ )
		DDD_Card_Used[slot].enable=false;

	
	unsigned long int active_sites_mask=0x0;
	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		active_sites_mask|=(0x1)<<site;


	while((pat_site_address_ptr)&&(pat_site_address_ptr->ddd_active_sites!=active_sites_mask))
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;
	

	if(pat_site_address_ptr==NULL)
		pat_site_address_ptr=&ddd_pat_site_list;


	if((loop)&&(!pat_site_address_ptr->ddd_pat_loopable)&&(pat_site_address_ptr->ddd_pat_start_address!=0))
		Make_Pattern_Loopable(pat_site_address_ptr);
		

	while(pin_list_ptr->ddd_pin_name)
	{	
		pin=pin_list_ptr->ddd_pin_ref;

		for( site = 0; site < max_sites ; site++ ) 
			if((active_site[site])&&(((pat_site_address_ptr->ddd_active_sites)>>site)&0x1))
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].enable=true;
	
		pin_list_ptr=pin_list_ptr->ddd_nextptr;
	}


	
	if(!((loop)&&((pat_site_address_ptr->ddd_pat_loopable==true))))	
	{
	
		start_address	= pat_site_address_ptr->ddd_pat_start_address + (start_displacement	<0 ? 0					: start_displacement);	
		stop_address	= pat_site_address_ptr->ddd_pat_start_address + (stop_displacement	<0 ? ddd_pat_lenght - 1 : stop_displacement);	
	}

	if(stop_address<(start_address+2))	
	{
		sprintf(ErrorMessage, "Stop Address must be at least two vectors after Start Address");
		printf("%s\n", ErrorMessage);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}

	for( slot = 0; slot < 21 ; slot++ ) if(pat_site_address_ptr->ddd_enable_card[slot])
	{				

		if(DDD_Card_Used[slot].timings_program_due==true)
		{		
			for(ch=1; ch<=8; ch++)
			{
		
				if(DDD_Card_Used[slot].tg2[ch-1]<5.0e-9f)
					DDD_Card_Used[slot].tg2[ch-1]=5.0e-9f;

if(!debug_ddd_msl_offline)		
				DDD_Card_Used[slot].card_ptr->ddd_set_delay(ch, DDD_Card_Used[slot].tg1[ch-1], DDD_Card_Used[slot].tg2[ch-1]);
			}
			DDD_Card_Used[slot].timings_program_due=false;
		}
			
		DDD_Card_Used[slot].card_receive_mask=card_receive_mask[slot];
if(!debug_ddd_msl_offline)	
		DDD_Card_Used[slot].card_ptr->ddd_set_compare_channels(card_receive_mask[slot]);
		
		if((loop)&&((pat_site_address_ptr->ddd_pat_loopable==true)||(pat_site_address_ptr->ddd_pat_start_address==0)))
		
			ddd_pat_end_loop_address=(stop_displacement	<0 ? ddd_pat_lenght : stop_displacement + 1);	
		else
			ddd_pat_end_loop_address=DDD_MEM_DEPTH;

		if(DDD_Card_Used[slot].ddd_pat_end_loop_address!=ddd_pat_end_loop_address)	
		{
if(!debug_ddd_msl_offline)	
			DDD_Card_Used[slot].card_ptr->ddd_end_pattern(ddd_pat_end_loop_address);
			DDD_Card_Used[slot].ddd_pat_end_loop_address=ddd_pat_end_loop_address;	
		}

	
		if(DDD_Card_Used[slot].card_ptr!=DDD_7_ptr)
			ddd_slave_board_counter++;
	}
	
	if(ddd_slave_board_counter>0)

	{
	
		DDD_Card_Used[7-1].card_ptr->ddd_load_pattern(pat_site_address_ptr->ddd_pat_start_address,pat_site_address_ptr->ddd_master_first_vector_string);


		for( slot = 0; slot < 21 ; slot++ ) if(pat_site_address_ptr->ddd_enable_card[slot])
		{
			if(DDD_Card_Used[slot].card_ptr!=DDD_7_ptr)
		
if(!debug_ddd_msl_offline)	
				DDD_Card_Used[slot].card_ptr->ddd_set_slave_pattern();
		}

	
if(!debug_ddd_msl_offline)	
		DDD_7_ptr->ddd_set_master_pattern();

	
		for( slot = 0; slot < 21 ; slot++ ) if(pat_site_address_ptr->ddd_enable_card[slot])
			if(DDD_Card_Used[slot].card_ptr!=DDD_7_ptr)	
			{
				if((loop)&&((pat_site_address_ptr->ddd_pat_loopable==true)||(pat_site_address_ptr->ddd_pat_start_address==0)))
				{
if(!debug_ddd_msl_offline)	
				
					DDD_Card_Used[slot].card_ptr->ddd_run_slave_pattern();
				}
				else
				{
if(!debug_ddd_msl_offline)	
				

					DDD_Card_Used[slot].card_ptr->ddd_run_slave_pattern(start_address, stop_address);	
				}
			}

	
		if((loop)&&((pat_site_address_ptr->ddd_pat_loopable==true)||(pat_site_address_ptr->ddd_pat_start_address==0)))
		{
if(!debug_ddd_msl_offline)	
	
			DDD_7_ptr->ddd_run_master_pattern();
		}
		else
		{
if(!debug_ddd_msl_offline)	


			DDD_7_ptr->ddd_run_master_pattern(start_address, stop_address);	
		}
	}
	else

	{

		if((loop)&&((pat_site_address_ptr->ddd_pat_loopable==true)||(pat_site_address_ptr->ddd_pat_start_address==0)))
		{
if(!debug_ddd_msl_offline)	
	
			DDD_7_ptr->ddd_run_pattern();
		}
		else
		{
if(!debug_ddd_msl_offline)	
	

			DDD_7_ptr->ddd_run_pattern(start_address, stop_address);	
		}
	}

	if((pattern_mode==DDD_WAIT_PATTERN_END)&&(stop_address>=start_address+2))	
	{
		if(DDD_Card_Used[6].clock_freq>0)
		{
		
		
			float pat_duration=(stop_address-start_address+1)/DDD_Card_Used[6].clock_freq+(float)(200 uS);	
			wait.delay_10_us((int)(pat_duration/(float)(10 uS)+0.5));
		}
		else	
		{
			sprintf(ErrorMessage, "Pattern period/frequency not initialized");
			printf("%s\n", ErrorMessage);
			MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		}

	}

}


void MS_DDD_Pattern::Read_Pattern_Result(sint pass_fail, int *first_fail_address, int *first_fail_pin, char *entry_label, char *exit_label, int *fail_count, short pin_name)	
{
	int						pin=0;					
	int						site=0;				
	int						slot=0;				
	int						vect_count=0;		
	ddd_pin					*pin_list_ptr;
	ddd_vect				*comp_vect_list_ptr;
	ddd_vect				*last_comp_vect_list_ptr;	
	ddd_vect				*tag_vect_list_ptr;
	int						base_vector_addr=0;	
	int						last_vector_addr=ddd_pat_lenght;	
	bool					label_found=false;
	char					*label;
	sbool					failing_vector={0};			

	for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
	{

		pass_fail[site]=1;


		if(first_fail_address!=NULL)
			first_fail_address[site]=-1;

	
		if(first_fail_pin!=NULL)
			first_fail_pin[site]=-1;

		if(fail_count!=NULL)		
			fail_count[site]=0;
	}
	
	if(ddd_comp_vect_list!=NULL)
	{
		ddd_pat_site_address *pat_site_address_ptr;
		pat_site_address_ptr=&ddd_pat_site_list;

	
		unsigned long int active_sites_mask=0x0;
		for( site = 0; site < max_sites ; site++ ) if(active_site[site])
			active_sites_mask|=(0x1)<<site;


		while((pat_site_address_ptr)&&(pat_site_address_ptr->ddd_active_sites!=active_sites_mask))
			pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;
		

		if(pat_site_address_ptr==NULL)
			pat_site_address_ptr=&ddd_pat_site_list;
		
		tag_vect_list_ptr=ddd_tag_vect_list;

		if((entry_label!=NULL)&&(tag_vect_list_ptr!=NULL))
		{
			label=new char[strlen(entry_label)+1];

			for(int c=0; c<(int)strlen(entry_label);c++)
				label[c]=tolower(entry_label[c]);
		
			label[c]='\0';

			
			
			while((tag_vect_list_ptr!=NULL)&&(!label_found))
			{
				if(!strcmp(tag_vect_list_ptr->ddd_vect_label,label))
				{
					label_found=true;
					if(tag_vect_list_ptr->ddd_prevcompptr!=NULL)
					
						comp_vect_list_ptr=tag_vect_list_ptr->ddd_prevcompptr->ddd_nextcompptr;
					else
				
						comp_vect_list_ptr=ddd_comp_vect_list;
		
					base_vector_addr=tag_vect_list_ptr->ddd_vect_number;	
				}
				tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
			}
				
			if(!label_found)
				MessageBox(NULL,"Entry Label not found, scanning whole pattern","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);

			delete label;

		}
		else

			comp_vect_list_ptr=ddd_comp_vect_list;

	
		tag_vect_list_ptr=comp_vect_list_ptr;
		label_found=false;
		if((exit_label!=NULL)&&(tag_vect_list_ptr!=NULL))	
		{
			label=new char[strlen(exit_label)+1];

			for(int c=0; c<(int)strlen(exit_label);c++)
				label[c]=tolower(exit_label[c]);
		
			label[c]='\0';
	
			
			while((tag_vect_list_ptr!=NULL)&&(!label_found))
			{
				if(!strcmp(tag_vect_list_ptr->ddd_vect_label,label))
				{
					label_found=true;
					if(tag_vect_list_ptr->ddd_compare_vect==true)
				
						last_comp_vect_list_ptr=tag_vect_list_ptr;
					else
					if(tag_vect_list_ptr->ddd_prevcompptr!=NULL)
		
						last_comp_vect_list_ptr=tag_vect_list_ptr->ddd_prevcompptr;
					else
					{
			
						last_comp_vect_list_ptr=ddd_last_comp_vect_ptr;
						label_found=false;
					}
		
					last_vector_addr=tag_vect_list_ptr->ddd_vect_number;
				}
				tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
			}
				
			if(!label_found)
				MessageBox(NULL,"Exit Label not found","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);

			delete label;

		}
		else
			
			last_comp_vect_list_ptr=ddd_last_comp_vect_ptr;
		

		


		while((comp_vect_list_ptr!=NULL)&&(active_sites_mask!=0x0))	
		{

			for( slot = 0; slot < 21 ; slot++ ) if(pat_site_address_ptr->ddd_enable_card[slot])
			{				
if(!debug_ddd_msl_offline)	
				DDD_Card_Used[slot].card_read_back=DDD_Card_Used[slot].card_ptr->ddd_read_pattern(pat_site_address_ptr->ddd_pat_start_address+comp_vect_list_ptr->ddd_vect_number+2);
			}

			if(fail_count!=NULL)
				for( site = 0; site < max_sites ; site++ ) if(active_site[site])
					failing_vector[site]=false;
	

	
			pin_list_ptr=&ddd_pin_list;
			while(pin_list_ptr->ddd_pin_name)
			{	
				pin=pin_list_ptr->ddd_pin_ref;

				if((pin_name==-1)||(pin_name==pin))	
				{
				
					for( site = 0; site < max_sites ; site++ ) 	
						if(
							((fail_count==NULL)&&((active_sites_mask>>site)&0x1))||
							(fail_count!=NULL)
						  )	
					{
						pin_selection(pin,site);

						switch(comp_vect_list_ptr->ddd_vect_string[pin_list_ptr->ddd_pin_order])
						{
							case '0': 
							case '1': 
							case 't': 
							case 'T': 
							case 'z': 
							case 'Z': 
							case 'x':
							case 'X':
							case 'c':
							case 'C':
							case 's':
							case 'S':
								break;
							case 'l':
							case 'L':
								if((DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_read_back>>(Pin_Type_Used[pin][site].Channel-1))&(0x1))
								{
									if((first_fail_address!=NULL)&&(first_fail_address[site]==-1))
										
										first_fail_address[site]=comp_vect_list_ptr->ddd_vect_number-base_vector_addr;
									
									if((first_fail_pin!=NULL)&&(first_fail_pin[site]==-1))
										first_fail_pin[site]=pin;

									pass_fail[site]=0;

									
									if(fail_count==NULL)
										
										active_sites_mask&=-(site+2);	
									else
										
										failing_vector[site]=true;
									
								}
								break;
							case 'h':
							case 'H':
								if(!((DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_read_back>>(Pin_Type_Used[pin][site].Channel-1))&(0x1)))
								{
									if((first_fail_address!=NULL)&&(first_fail_address[site]==-1))
										
										first_fail_address[site]=comp_vect_list_ptr->ddd_vect_number-base_vector_addr;
									
									if((first_fail_pin!=NULL)&&(first_fail_pin[site]==-1))
										first_fail_pin[site]=pin;

									pass_fail[site]=0;

									
									if(fail_count==NULL)
										
										active_sites_mask&=-(site+2);	
									else
										
										failing_vector[site]=true;
									
								}
								break;
							default:
								MessageBox(NULL,"Invalid logic level","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
								exit(0);
						} 
					}
				}

				pin_list_ptr=pin_list_ptr->ddd_nextptr;
			} 
			
			
			if(fail_count!=NULL) 	
				for( site = 0; site < max_sites ; site++ ) if(active_site[site])
					if(failing_vector[site])
						fail_count[site]++;
			

			
			if(comp_vect_list_ptr!=last_comp_vect_list_ptr)	
				comp_vect_list_ptr=comp_vect_list_ptr->ddd_nextcompptr;	
			else	
				comp_vect_list_ptr=NULL;			

		}
	}
}


void MS_DDD_Pattern::Read_Dig_Cap_Vector(short pin_list, sulong read_word, char *entry_label, int displacement)
{



	int						pin;					
	int						site;				
	int						slot=0;					
	DYN_GROUP_LIST			*pin_ptr;
	DYN_GROUP_LIST			*start_pin_ptr;

	ddd_pat_site_address	*pat_site_address_ptr;
	pat_site_address_ptr=	&ddd_pat_site_list;	
	ddd_pin					*pin_list_ptr;
	ddd_vect				*vect_list_ptr;
	ddd_vect				*tag_vect_list_ptr;

	bool					label_found=false;
	char					*label;
	int						base_vector_addr=0;
	int						d;


	unsigned long int active_sites_mask=0x0;
	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		active_sites_mask|=(0x1)<<site;


	while((pat_site_address_ptr)&&(pat_site_address_ptr->ddd_active_sites!=active_sites_mask))
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;
	

	if(pat_site_address_ptr==NULL)
		pat_site_address_ptr=&ddd_pat_site_list;


	tag_vect_list_ptr=ddd_tag_vect_list;
	
	if(entry_label!=NULL)
	{
		label=new char[strlen(entry_label)+1];

		for(int c=0; c<(int)strlen(entry_label);c++)
			label[c]=tolower(entry_label[c]);
	
		label[c]='\0';
		
		
		while((tag_vect_list_ptr!=NULL)&&(!label_found))
		{
			if(!strcmp(tag_vect_list_ptr->ddd_vect_label,label))
			{
				label_found=true;
				vect_list_ptr=tag_vect_list_ptr;
	
				base_vector_addr=vect_list_ptr->ddd_vect_number;
			}
			tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
		}
			
		if(!label_found)
		{
			MessageBox(NULL,"Label not found","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			exit(0);
		}

		delete label;
	}


	d=displacement;
	while((d>0)&&(vect_list_ptr!=NULL))
	{
		vect_list_ptr=vect_list_ptr->ddd_nextptr;
		d--;
	}


	for( slot = 0; slot < 21 ; slot++ )
		DDD_Card_Used[slot].flag=false;

	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr=start_pin_ptr;
	do
	{
		pin = pin_ptr->grouppin;

	
		pin_list_ptr=&ddd_pin_list;	
		while((pin_list_ptr!=NULL)&&(pin_list_ptr->ddd_pin_ref!=Pin_Type_Used[pin][0].Pin_Ref))
			pin_list_ptr=pin_list_ptr->ddd_nextptr;

		if(pin_list_ptr==NULL)
		{
			char *error_msg;
			error_msg=new char[50+strlen(Pin_Type_Used[pin][0].Pin_Name)+strlen(ddd_pat_name)];
			sprintf(error_msg,"Pin \"%s\" not found in pattern %s", Pin_Type_Used[pin][0].Pin_Name, ddd_pat_name);	
			MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			delete error_msg;
			exit(0);
		}
			

		for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].flag=true;

		pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

	
	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].flag==true)
	{
if(!debug_ddd_msl_offline)	
		DDD_Card_Used[slot].card_read_back=DDD_Card_Used[slot].card_ptr->ddd_read_pattern(pat_site_address_ptr->ddd_pat_start_address+vect_list_ptr->ddd_vect_number+2);	
		DDD_Card_Used[slot].flag=false;
	}


	for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
		read_word[site]=0x0;

	pin_ptr=start_pin_ptr;
	

	do
	{
	
		pin_list_ptr=&ddd_pin_list;
		while((pin_list_ptr!=NULL)&&(pin_list_ptr->ddd_pin_ref!=pin_ptr->grouppin))
			pin_list_ptr=pin_list_ptr->ddd_nextptr;

		if(pin_list_ptr==NULL)
		{
			char *error_msg;
			error_msg=new char[50+strlen(Pin_Type_Used[pin][0].Pin_Name)+strlen(ddd_pat_name)];
			sprintf(error_msg,"Pin \"%s\" not found in pattern %s", Pin_Type_Used[pin_ptr->grouppin][0].Pin_Name, ddd_pat_name);
			MessageBox(NULL,error_msg,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			delete error_msg;
			exit(0);
		}

	
		pin=pin_list_ptr->ddd_pin_ref;
		
		for( site = 0; site < max_sites ; site++ ) if(active_site[site]) 
		{
			pin_selection(pin,site);

			switch(vect_list_ptr->ddd_vect_string[pin_list_ptr->ddd_pin_order])
				{
				case '0': 
				case '1': 
				case 't': 
				case 'T': 
				case 'z': 
				case 'Z': 
				case 's':
				case 'S':
				case 'l':
				case 'L':
				case 'h':
				case 'H':
				case 'x':
				case 'X':
					break;
				case 'c':
				case 'C':
				
						read_word[site]<<=1;
			
						read_word[site]|=((DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_read_back>>(Pin_Type_Used[pin][site].Channel-1))&(0x1));
					break;
				default:
					MessageBox(NULL,"Invalid logic level","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					exit(0);

			} 

		}
		
		pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
		
}

bool MS_DDD_Pattern::Read_Shmoo_Result(int pin, int s, char *entry_label, int &vector_number, int &ddd_memory_address, char &compare_char)
{
	int						site=0;				
	int						slot=0;					
	int						vect_count=0;			
	ddd_pin					*pin_list_ptr;
	ddd_vect				*comp_vect_list_ptr;
	ddd_vect				*tag_vect_list_ptr;
	int						base_vector_addr=0;	

	bool					label_found=false;
	char					*label;

	bool					pass_fail=true;

	
	ddd_pat_site_address *pat_site_address_ptr;
	pat_site_address_ptr=&ddd_pat_site_list;


	unsigned long int active_sites_mask=0x0;
	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
		active_sites_mask|=(0x1)<<site;


	while((pat_site_address_ptr)&&(pat_site_address_ptr->ddd_active_sites!=active_sites_mask))
		pat_site_address_ptr=pat_site_address_ptr->ddd_nextptr;
	

	if(pat_site_address_ptr==NULL)
		pat_site_address_ptr=&ddd_pat_site_list;
	
	tag_vect_list_ptr=ddd_tag_vect_list;

	if((entry_label!=NULL)&&(tag_vect_list_ptr!=NULL))
	{
		label=new char[strlen(entry_label)+1];

		for(int c=0; c<(int)strlen(entry_label);c++)
			label[c]=tolower(entry_label[c]);
	
		label[c]='\0';

		
		
		while((tag_vect_list_ptr!=NULL)&&(!label_found))
		{
			if(!strcmp(tag_vect_list_ptr->ddd_vect_label,label))
			{
				label_found=true;

				
				comp_vect_list_ptr=tag_vect_list_ptr;
	
				base_vector_addr=comp_vect_list_ptr->ddd_vect_number;
			}
			tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
		}
			
		if(!label_found)	
		{
			char ErrorMessage[200];
			comp_vect_list_ptr=ddd_comp_vect_list;
			if(comp_vect_list_ptr!=NULL)
			{
				sprintf(ErrorMessage,"Label \"%s\" not found, analyzing first compare vector: %i",label,comp_vect_list_ptr->ddd_vect_number);
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);	
			}
			else
			{
				sprintf(ErrorMessage,"Label \"%s\" not found, no compare vectors found",label);
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);	
				delete label;
				return false;
			}
		}

		delete label;

		
		for( slot = 0; slot < 21 ; slot++ ) if(pat_site_address_ptr->ddd_enable_card[slot])
		{	
			ddd_memory_address=pat_site_address_ptr->ddd_pat_start_address+comp_vect_list_ptr->ddd_vect_number;
			vector_number=comp_vect_list_ptr->ddd_vect_number;
if(!debug_ddd_msl_offline)	
			DDD_Card_Used[slot].card_read_back=DDD_Card_Used[slot].card_ptr->ddd_read_pattern(pat_site_address_ptr->ddd_pat_start_address+comp_vect_list_ptr->ddd_vect_number+2);
		}

		site=s;	
		
		if(active_site[site]) 
		{
			pin_selection(pin,site);

			pin_list_ptr=&ddd_pin_list;

			while((pin_list_ptr!=NULL)&&(pin_list_ptr->ddd_pin_ref!=pin))
				pin_list_ptr=pin_list_ptr->ddd_nextptr;

			if(pin_list_ptr==NULL)
			{
				MessageBox(NULL,"Pin not found in Shmoo Plot","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				return false;
			}

			compare_char=comp_vect_list_ptr->ddd_vect_string[pin_list_ptr->ddd_pin_order];
			switch(compare_char)	
			{
				case '0': 
				case '1': 
				case 't': 
				case 'T': 
				case 'z': 
				case 'Z': 
				case 'x':
				case 'X':
				case 's':
				case 'S':
					break;
				case 'l':
				case 'L':
					if((DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_read_back>>(Pin_Type_Used[pin][site].Channel-1))&(0x1))
						pass_fail=false;
					break;
				case 'h':
				case 'H':
				case 'c':
				case 'C':
					if(!((DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_read_back>>(Pin_Type_Used[pin][site].Channel-1))&(0x1)))
						pass_fail=false;
					break;
				default:
					MessageBox(NULL,"Invalid logic level","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					exit(0);
			} 
		}

	}

	return pass_fail;
}

int  MS_DDD_Pattern::GetDisplacement(char *label)	
{
	int			ret						= -1;
	bool		label_found				= false;
	ddd_vect	*tag_vect_list_ptr;
	char		*temp_label;
	char		ErrorMessage[100];

	if((label!=NULL)&&(strlen(label)>0))
	{
		
		tag_vect_list_ptr=ddd_tag_vect_list;

		
		temp_label=new char[strlen(label)+1];
		for(int c=0; c<(int)strlen(label);c++)
			temp_label[c]=tolower(label[c]);
		temp_label[c]='\0';

		
		while((tag_vect_list_ptr!=NULL)&&(!label_found))
		{
			if(!strcmp(tag_vect_list_ptr->ddd_vect_label,temp_label))
			{
				ret=tag_vect_list_ptr->ddd_vect_number;
				label_found=true;
			}
			tag_vect_list_ptr=tag_vect_list_ptr->ddd_nexttagptr;
		}
		delete temp_label;
	}

	if(!label_found)
	{
		sprintf(ErrorMessage, "Label %s not found", label);
		printf("%s\n", ErrorMessage);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	}

	return ret;
}



extern void get_current_prgfile_dir(char *file_name, char *file_dir, int length);


void ddd_init()		
{
	

	int	slot;
	int ch=0;

	int pin=0;
	int site=0;

	Ddd *DDD_7_ptr=&ddd_cards[board_ptr[BOARD_7]];	

	
	for(slot=0; slot<21; slot++)
	{
		DDD_Card_Used[slot].Vih=0.0f;
		DDD_Card_Used[slot].Vil=0.0f;
		DDD_Card_Used[slot].Vref=0.0f;
		for(ch=0; ch<8; ch++)
		{
			DDD_Card_Used[slot].tg1[ch]=0.0f;
			DDD_Card_Used[slot].tg2[ch]=0.0f;
		}
		DDD_Card_Used[slot].clock_freq=0.0f;
		strcpy(DDD_Card_Used[slot].vector_string,"XXXXXXXX");
		DDD_Card_Used[slot].card_receive_mask=0x0;
		DDD_Card_Used[slot].card_read_back=0x0;
		DDD_Card_Used[slot].card_ptr=NULL;
		DDD_Card_Used[slot].enable=false;
		DDD_Card_Used[slot].flag=false;
		DDD_Card_Used[slot].timings_program_due=false;
		DDD_Card_Used[slot].ddd_pat_end_loop_address=-1;	
	}

	
	for(pin=0; pin<pin_inserted; pin++)
		for( site = 0; site < max_sites ; site++ )
			if(pin_selection(pin,site)==DDD)
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_ptr=DDD_Used[site].DDD_slot;

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
			DDD_Card_Used[slot].card_ptr->init();
}

int ddd_load_all_patterns(STRING directory_name, int pattern_address, bool expand_single_sites)
{
	
	

	
	
	char	program_dir[512];
	char	list_file_name[512]="";
	char	sys_command[512];
	char	last_char=directory_name[strlen(directory_name)-1];

	if((last_char=='\\')||(last_char=='/'))
		directory_name.Truncate(strlen(directory_name)-1);

	if(!((directory_name[1]==':')||!strncmp (directory_name,"//",2)||!strncmp (directory_name,"\\\\",2)))
	{
		get_current_prgfile_dir(__FILE__, program_dir, 100);
		char *pdest = strstr( program_dir, "programs");
		if( pdest != NULL )
			*pdest='\0';
		strcat(program_dir, directory_name);
		directory_name=program_dir;
	}


	sprintf(sys_command,"dir/b %s\\*.ddd > %s\\ddd_pattern_list.log", (const char *)(directory_name), (const char *)(directory_name));
	system(sys_command);
	strcpy(list_file_name,directory_name);
	strcat(list_file_name,"\\ddd_pattern_list.log");
	return ddd_load_pattern_list(list_file_name, pattern_address, expand_single_sites);	
}

int ddd_load_all_patterns(int pattern_address, bool expand_single_sites)
{
	
	
	
	
	
	char program_dir[255];
	char sys_command[512];
	
	get_current_prgfile_dir(__FILE__, program_dir, 100);
	strcat(program_dir,"ddd_patterns\\");

	sprintf(sys_command, "dir/b %s*.ddd > %sddd_pattern_list.log", program_dir, program_dir);
	system(sys_command);
	return ddd_load_pattern_list("ddd_pattern_list.log", pattern_address, expand_single_sites);

	
}

int ddd_load_pattern_list(STRING list_filename, int pattern_address, bool expand_single_sites)
{
	
	
	


	char program_dir[255];	
	char	list_file_name[255];
	FILE	*patterfp;
	char	line[MAXSTRINGLENGTH];
	int		addr=pattern_address;
	char	seps[] = " ,;\t\n";
	char	*ddd_pattern_file_name;




		
	






	
	if(!((list_filename[1]==':')||!strncmp (list_filename,"//",2)||!strncmp (list_filename,"\\\\",2)))
	{
		get_current_prgfile_dir(__FILE__, program_dir, 100);
		char *pdest = strstr( program_dir, "programs");
		if( pdest != NULL )
			*pdest='\0';
		
		pdest = (char *)strstr( list_filename, "\\");
		if( pdest == NULL )
			strcat(program_dir,"programs\\multisite\\ddd_patterns\\");

		strcpy(list_file_name,program_dir);
		strcat(list_file_name,list_filename);
	}
	else
		strcpy(list_file_name,list_filename);
	

	if ((patterfp = fopen(list_file_name,"r"))==NULL)
	{	
		strcat(list_file_name,": cannot open file\n");
		mytext.text_in_box(40,10,list_file_name);
		return 1; 
	}
	printf("\nDDD Pattern list file: %s\n", list_file_name);	
	while(!feof( patterfp ))
	{      
		strcpy(line,"");
		fgets(line,MAXSTRINGLENGTH,patterfp);
		ddd_pattern_file_name = strtok( line, seps );  

		if (ddd_pattern_file_name!=NULL)
		{
			printf("Opening file %s...\n", ddd_pattern_file_name);
			addr = ddd_load_pattern (ddd_pattern_file_name, addr, expand_single_sites);
		}
	}

	fclose(patterfp);
	printf("\n");	

	return 0;
}

int ddd_load_pattern (STRING ddd_pattern_file_name, int pattern_address, bool expand_single_sites)
{
	
	
	
	
	
	
	
	
	




	char file_name[255];
	FILE *patterfp;
	char *token1;
	char *token2;
	char line[MAXSTRINGLENGTH];
	char buf[MAXSTRINGLENGTH];
	
	char program_dir[255];	
	char seps[] = " ,;\t\n";
	char vect[33];	
	bool vect_section=false;
	int num_vectors=0;
	bool is_comment=false;
	bool is_label=false;
	int start_pattern_address=pattern_address;
	int rpt=1;	
	int r;		

	enum 
	{
		DDD_PATTERN_FILE_TO_BE_READ,
		DDD_START_PATTERN_FOUND,
		DDD_PATTERN_NAME_FOUND,
		DDD_PIN_ORDER_FOUND,
		DDD_START_VECTOR_DATA_FOUND,
		DDD_END_VECTOR_DATA_FOUND,
		DDD_END_PATTERN_FOUND,
		DDD_FILE_FORMAT_ERROR
	} status=DDD_PATTERN_FILE_TO_BE_READ;

	char ErrorMessage[200];
	
	if(start_pattern_address<0)
	{
		printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
		sprintf(ErrorMessage,"Invalid start address for pattern \"%s\"", (const char *)ddd_pattern_file_name);
		MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return -1;
	}
    
	DDD_Pattern_Element *NewPatternPtr;

	NewPatternPtr= new DDD_Pattern_Element;

	get_current_prgfile_dir(__FILE__, program_dir, 100);
	strcat(program_dir,"ddd_patterns\\");	
		
	strcpy(file_name,program_dir);

	
	if (ddd_pattern_file_name.HasLen())
		strcat(file_name,ddd_pattern_file_name);
	else
		strcat(file_name,"pattern.ddd");

	if ((patterfp = fopen(file_name,"r"))==NULL)
	{	
		strcat(file_name,": cannot open file\n");
		mytext.text_in_box(40,10,file_name);
		exit(0); 
	}

	while((!feof( patterfp ))&&(status!=DDD_END_PATTERN_FOUND)&&(status!=DDD_FILE_FORMAT_ERROR))
	{      
		is_comment = false;
		fgets(line,MAXSTRINGLENGTH,patterfp);
		
		
		token1 = strtok( line, seps );  

		
		while( (token1 != NULL) && (is_comment == false) )
			{   
				if ((strlen(token1)>1) && (strncmp(token1,"//",2) ==0))
					
					is_comment = true;
				else
				{
					strcpy(buf,token1);

					for(unsigned int i=0;i<strlen(buf);i++) 
						buf[i]=tolower(buf[i]);
					
					if(!strcmp(buf, "start"))
					{
						token1 = strtok( NULL, " \t\n" );   
						if((!strcmp(token1, "pattern"))&&(status==DDD_PATTERN_FILE_TO_BE_READ))
						{
							vect_section=false;
							status=DDD_START_PATTERN_FOUND;
						} else
						if((!strcmp(token1, "vector_data"))&&(status==DDD_PIN_ORDER_FOUND))
						{
							vect_section=true;
							status=DDD_START_VECTOR_DATA_FOUND;
						} else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"start\" found in pattern \"%s\"", (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}

					if(!strcmp(buf, "end"))
					{
						token1 = strtok( NULL, " \t\n" );   
						if((!strcmp(token1, "vector_data"))&&(status==DDD_START_VECTOR_DATA_FOUND))
						{
							vect_section=false;
							status=DDD_END_VECTOR_DATA_FOUND;
						} else
						if((!strcmp(token1, "pattern"))&&(status==DDD_END_VECTOR_DATA_FOUND))
						{
							vect_section=false;
							status=DDD_END_PATTERN_FOUND;
						} else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"end\" found in pattern \"%s\"", (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}
					
					
					if(!strcmp(buf, "pattern_name"))
					{
						if(status==DDD_START_PATTERN_FOUND)
						{
							token1 = strtok( NULL, seps );
							NewPatternPtr->Pattern.Set_Pattern_Name(token1);
							status=DDD_PATTERN_NAME_FOUND;
						}else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"pattern_name\" found in pattern \"%s\"", (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}

					
					if(!strcmp(buf, "pin_order"))
					{
						if(status==DDD_PATTERN_NAME_FOUND)
						{
							token1 = strtok( NULL, seps );   
							while( (token1 != NULL) && (is_comment == false))
							{
								  
								if ((strlen(token1)>1) && (strncmp(token1,"//",2) ==0))
									
									is_comment = true;
								else
									NewPatternPtr->Pattern.Add_Pin_Name(token1);
								token1 = strtok( NULL, seps );   
							}
							status=DDD_PIN_ORDER_FOUND;
						}else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"pin_order\" found in pattern \"%s\"", (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}
					
					if(buf[0]==':')
					{
						if(status==DDD_START_VECTOR_DATA_FOUND)
						{
							token2 = strtok( buf, ":" );
							NewPatternPtr->Pattern.Tag_Vector(token2);					
						}else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \":\" found in pattern \"%s\"", (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}

					
					if ((strlen(buf)>1) && (strncmp(buf,"c{load_repeat",13) ==0))
					{
						if(status==DDD_START_VECTOR_DATA_FOUND)
						{
							strcpy(buf,strrchr(token1,'(')+1);
							token2 = strtok( buf, ")" );
							rpt=atoi(token2);
							if(rpt>DDD_MEM_DEPTH)
							{
								printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
								sprintf(ErrorMessage,"Repeat argument exceeded maximum value \"%i\" in pattern \"%s\"", DDD_MEM_DEPTH, (const char *)ddd_pattern_file_name);
								MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
								status=DDD_FILE_FORMAT_ERROR;
								rpt=1;
							}
						}else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"%s\" found in pattern \"%s\"", buf, (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}
					

					if ((strlen(buf)>1) && (strncmp(buf,"d{",2) ==0))
					{
						if(status==DDD_START_VECTOR_DATA_FOUND)
						{
							int nchar=NewPatternPtr->Pattern.Get_Num_Pins();
							
							strncpy(vect,strrchr(token1,'{')+1,nchar);
							vect[nchar]='\0';
							
							for(r=1; r<=rpt; r++)	
								NewPatternPtr->Pattern.Add_Vector(vect);
							rpt=1;	
						}else
						{
							printf("Pattern \"%s\" not loaded!\n", (const char *)ddd_pattern_file_name);
							sprintf(ErrorMessage,"Unexpected keyword \"%s\" found in pattern \"%s\"", buf, (const char *)ddd_pattern_file_name);
							MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
							status=DDD_FILE_FORMAT_ERROR;
						}
					}

					token1 = strtok( NULL, seps );   
				}

		}
	}

	fclose(patterfp);
	

	if(status==DDD_FILE_FORMAT_ERROR)
		return -1;

	
	if(DDD_Pattern_List==NULL)
		DDD_Pattern_List=NewPatternPtr;
    
	NewPatternPtr->pat_name=NewPatternPtr->Pattern.ddd_pat_name;
	NewPatternPtr->nextptr=NULL;
	NewPatternPtr->prevptr=DDD_Last_Pattern;
	if(DDD_Last_Pattern!=NULL)
		DDD_Last_Pattern->nextptr=NewPatternPtr;
	
	DDD_Last_Pattern=NewPatternPtr;


	int i;
	bool local_active_site[MAX_SITES];



	for(i=0; i<max_sites; i++)
		local_active_site[i] = active_site[i];


	for(i=0; i<max_sites; i++)
		active_site[i] = true;




	if(pattern_address<CSC_DDD_NON_LOOP_PAT_BASE_ADDR)
		CSC_DDD_NON_LOOP_PAT_BASE_ADDR=pattern_address;

	pattern_address=NewPatternPtr->Pattern.Upload_Pattern(pattern_address);

	


	

	if(expand_single_sites)
	{
	
		for(i=0; i<max_sites; i++)
			active_site[i] = false;


		for(i=0; i<max_sites; i++)
		{
			active_site[i] = true;
		
			pattern_address=NewPatternPtr->Pattern.Upload_Pattern(pattern_address);
			active_site[i] = false;
		}
	}


	for(i=0; i<max_sites; i++)
		active_site[i] = local_active_site[i];

	
	printf("Loaded Pattern %s at DDD Addr 0x%x - 0x%x\n", NewPatternPtr->Pattern.ddd_pat_name, start_pattern_address, pattern_address-1);	

	return pattern_address;
}


void ddd_run_pattern(char *pattern_name, unsigned short pattern_mode, char *StartLabel, char *StopLabel)	
{










	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;

	int	start_displacement	= -1;
	int	stop_displacement	= -1;



	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
	{
		if(StartLabel!=NULL)	
			start_displacement=DDD_Pattern_Ptr->Pattern.GetDisplacement(StartLabel);

		if(StopLabel!=NULL)		
			stop_displacement=DDD_Pattern_Ptr->Pattern.GetDisplacement(StopLabel);

		
		DDD_Pattern_Ptr->Pattern.Run_Pattern(pattern_mode, start_displacement, stop_displacement);	
	}
}

void ddd_stop_pattern(void)
{


	Ddd *DDD_7_ptr=&ddd_cards[board_ptr[BOARD_7]];
	int slot=0;


	DDD_7_ptr->ddd_stop_pattern();


	for( slot = 0; slot < 21 ; slot++ ) 
		if((DDD_Card_Used[slot].card_ptr!=NULL)&&(DDD_Card_Used[slot].card_ptr!=DDD_7_ptr))
if(!debug_ddd_msl_offline)	
			DDD_Card_Used[slot].card_ptr->ddd_stop_pattern();
}

void ddd_disconnect_drivers(bool disconnect_all)
{
	

	int slot=0;

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
	{
		if(DDD_Card_Used[slot].enable||disconnect_all)
if(!debug_ddd_msl_offline)	
		DDD_Card_Used[slot].card_ptr->ddd_disconnect_drivers();
	}
}


void ddd_read_pattern_result(char *pattern_name, sbool pass_fail, sint first_fail_address, sint first_fail_pin, char *entry_label, char *exit_label, int *fail_count, short pin_name)	
{
	int site=0;
	sint _pass_fail;


	ddd_read_pattern_result(pattern_name, _pass_fail, first_fail_address, first_fail_pin, entry_label, exit_label, fail_count, pin_name);	

	for (site=0; site < max_sites; site++) if(active_site[site])
		pass_fail[site]=(bool)_pass_fail[site];
}


void ddd_read_pattern_result(char *pattern_name, sint pass_fail, sint first_fail_address, sint first_fail_pin, char *entry_label, char *exit_label, int *fail_count, short pin_name)	
{
	




	


	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;

	
	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
		
		DDD_Pattern_Ptr->Pattern.Read_Pattern_Result(pass_fail, first_fail_address, first_fail_pin, entry_label, exit_label, fail_count, pin_name);	
}
void ddd_dig_src(short pin_list, char *pattern_name, sulong src_data, char *entry_label, int displacement)
{
	
	

	
	
	
	
	
	

	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;


	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
		DDD_Pattern_Ptr->Pattern.Upload_Dig_Source_Vector(pin_list, src_data, entry_label, displacement);

}

void ddd_dig_src(short pin_list, char *pattern_name, unsigned long src_data, char *entry_label, int displacement)
{
	
	
	
	
	

	

	

	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;

	
	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
		DDD_Pattern_Ptr->Pattern.Upload_Dig_Source_Vector(pin_list, src_data, entry_label, displacement);

}

void ddd_dig_cap(short pin_list, char *pattern_name, sulong cap_data, char *entry_label, int displacement)
{
	
	
	
	
	
	
	
	
	

	DDD_Pattern_Element *DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;


	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
	else
		DDD_Pattern_Ptr->Pattern.Read_Dig_Cap_Vector(pin_list, cap_data, entry_label, displacement);
}

void ddd_shmoo(char *pattern_name, int site, char *entry_label, int pin1, short par1_type, float par1_start, float par1_stop, int par1_nsteps, int pin2, short par2_type, float par2_start, float par2_stop, int par2_nsteps)
{

	int	i, j;
	float	freq;
	sfloat				
		tg1_1,
		tg1_2,
		tg2_1,
		tg2_2,
		vih_1,
		vih_2,
		vil_1,
		vil_2,
		vref_1,
		vref_2;

	float
		vcc_1,
		vcc_2;
	STRING				
		polarity_v_1,
		polarity_v_2,
		range_v_1,
		range_v_2,
		compensation_v_1,
		compensation_v_2;
	
	float
		par1,
		par2,
		step1,
		step2;

	int		save_active_sites[MAX_SITES]={0};
	short	Card_type;		
	char	c;
	int
		vector_number,
		ddd_memory_address;

	short	RNG, COMP;
	
	bool	*ShmooResult;
	char	compare_char;


	if(par1_nsteps<2)
	{
		MessageBox(NULL,"First parameter must have at least 2 steps","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return;
	}
	
	if(pin2<0)
		par2_nsteps=1;
	else if(par2_nsteps<2)
	{
		MessageBox(NULL,"Second parameter must have at least 2 steps","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return;
	}

	ShmooResult=new bool[par1_nsteps*par2_nsteps];
	

	for(i=0; i<par1_nsteps*par2_nsteps; i++)
		ShmooResult[i]=false;

	DDD_Pattern_Element	*DDD_Pattern_Ptr;
	DDD_Pattern_Ptr=DDD_Pattern_List;

	
	for(i=0; i<max_sites; i++)
	{
		save_active_sites[i]=active_site[i];
		if(i!=site) active_site[i]=0;
	}


	step1=(par1_stop-par1_start)/(par1_nsteps-1);
	if(pin2>=0) step2=(par2_stop-par2_start)/(par2_nsteps-1);

	

	while((DDD_Pattern_Ptr!=NULL)&&(strcmp(pattern_name,DDD_Pattern_Ptr->pat_name)))
		DDD_Pattern_Ptr=DDD_Pattern_Ptr->nextptr;

	if(DDD_Pattern_Ptr==NULL)
	{
		MessageBox(NULL,"Pattern not loaded","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		return;
	}
	

	Card_type=pin_selection(pin1,site);

	switch(Card_type)
	{
	case DDD:

		ddd_get_vih(pin1, vih_1);
		ddd_get_vil(pin1, vil_1);
		ddd_get_vref(pin1, vref_1);
		ddd_get_frequency(&freq);
		ddd_get_timings(pin1, tg1_1, tg2_1);
		break;

	case DVI:

		DVI_Used[site].DVI_slot->get_voltage_range (DVI_Used[site].DVI_channel, polarity_v_1, range_v_1, compensation_v_1);
		vcc_1= DVI_Used[site].DVI_slot->get_voltage_setting (DVI_Used[site].DVI_channel);
		break;

	case OVI:

		range_v_1=OVI_Used[site].OVI_slot->get_voltage_range (OVI_Used[site].OVI_channel, c);
		vcc_1= OVI_Used[site].OVI_slot->get_voltage_setting (OVI_Used[site].OVI_channel);
		break;

	default:
		{
		char err_message[100];
		sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
		mytext.text_in_box(40,10,err_message);
		return;
		}
	}
	

	if(pin2>=0)	
	{
		Card_type=pin_selection(pin2,site);

		switch(Card_type)
		{
		case DDD:

			ddd_get_vih(pin2, vih_2);
			ddd_get_vil(pin2, vil_2);
			ddd_get_vref(pin2, vref_2);
			ddd_get_timings(pin2, tg1_2, tg2_2);
			break;

		case DVI:

			DVI_Used[site].DVI_slot->get_voltage_range (DVI_Used[site].DVI_channel, polarity_v_2, range_v_2, compensation_v_2);
			vcc_2= DVI_Used[site].DVI_slot->get_voltage_setting (DVI_Used[site].DVI_channel);
			break;

		case OVI:
	
			range_v_2=OVI_Used[site].OVI_slot->get_voltage_range (OVI_Used[site].OVI_channel, c);
			vcc_2= OVI_Used[site].OVI_slot->get_voltage_setting (OVI_Used[site].OVI_channel);
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}
	}

	for(i=0;i<par1_nsteps;i++)
	{
		
		par1=par1_start+step1*i;

		Card_type=pin_selection(pin1,site);
		switch(Card_type)
		{
		case DDD:
			if (par1_type==SHMOO_VIH)
				ddd_set_vih(pin1, par1);
			else if (par1_type==SHMOO_VIL)
				ddd_set_vil(pin1, par1);
			else if (par1_type==SHMOO_VREF)
				ddd_set_vref(pin1, par1);
			else if (par1_type==SHMOO_T1)
				ddd_set_timings(pin1, par1, tg2_1[site]);			
			else if (par1_type==SHMOO_T2)
				ddd_set_timings(pin1, tg1_1[site], par1);			
			else if (par1_type==SHMOO_PERIOD)
				ddd_set_period(par1);
			else if (par1_type==SHMOO_FREQ)
				ddd_set_frequency(par1);
			else
			{
				char err_message[100];
				sprintf(err_message, "Shmoo type not executable for DDD pin %s",Pin_Type_Used[pin1][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			break;

		case DVI:
			if (par1_type==SHMOO_VCC)
			{
				DVI_Used[site].DVI_slot->set_voltage(DVI_Used[site].DVI_channel, par1);
				delay(1);
			}
			else
			{
				char err_message[100];
				sprintf(err_message, "Shmoo type not executable for DVI pin %s",Pin_Type_Used[pin1][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			break;

		case OVI:
			if (par1_type==SHMOO_VCC)
			{
				OVI_Used[site].OVI_slot->set_voltage(OVI_Used[site].OVI_channel, par1);
				delay(1);
			}
			else
			{
				char err_message[100];
				sprintf(err_message, "Shmoo type not executable for OVI pin %s",Pin_Type_Used[pin1][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
			}
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

		if(pin2>=0)
			for(j=0;j<par2_nsteps;j++)
			{
				
				par2=par2_start+step2*j;
				
				Card_type=pin_selection(pin2,site);
				switch(Card_type)
				{
				case DDD:
					if (par2_type==SHMOO_VIH)
						ddd_set_vih(pin2, par2);
					else if (par2_type==SHMOO_VIL)
						ddd_set_vil(pin2, par2);
					else if (par2_type==SHMOO_VREF)
						ddd_set_vref(pin2, par2);
					else if (par2_type==SHMOO_T1)
						ddd_set_timings(pin2, par2, tg2_2[site]);			
					else if (par2_type==SHMOO_T2)
						ddd_set_timings(pin2, tg1_2[site], par2);			
					else if (par2_type==SHMOO_PERIOD)
						ddd_set_period(par2);
					else if (par2_type==SHMOO_FREQ)
						ddd_set_frequency(par2);
					else
					{
						char err_message[100];
						sprintf(err_message, "Shmoo type not executable for DDD pin %s",Pin_Type_Used[pin2][site].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;

				case DVI:
					if (par2_type==SHMOO_VCC)
					{
						DVI_Used[site].DVI_slot->set_voltage(DVI_Used[site].DVI_channel, par2);
						delay(1);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "Shmoo type not executable for DVI pin %s",Pin_Type_Used[pin2][site].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;

				case OVI:
					if (par2_type==SHMOO_VCC)
					{
						OVI_Used[site].OVI_slot->set_voltage(OVI_Used[site].OVI_channel, par2);
						delay(1);
					}
					else
					{
						char err_message[100];
						sprintf(err_message, "Shmoo type not executable for OVI pin %s",Pin_Type_Used[pin2][site].Pin_Name);
						mytext.text_in_box(40,10,err_message);
						return;
					}
					break;

				default:
					{
					char err_message[100];
					sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
					mytext.text_in_box(40,10,err_message);
					return;
					}
				}
				
				DDD_Pattern_Ptr->Pattern.Run_Pattern(DDD_WAIT_PATTERN_END);
				ShmooResult[i+j*par1_nsteps]=DDD_Pattern_Ptr->Pattern.Read_Shmoo_Result(pin1, site, entry_label, vector_number, ddd_memory_address, compare_char);	


			}	
	
		else 
		{
			DDD_Pattern_Ptr->Pattern.Run_Pattern(DDD_WAIT_PATTERN_END);
			ShmooResult[i]=DDD_Pattern_Ptr->Pattern.Read_Shmoo_Result(pin1, site, entry_label, vector_number, ddd_memory_address, compare_char);
		}
	}	


	Card_type=pin_selection(pin1,site);

	switch(Card_type)
	{
	case DDD:
		
		ddd_set_levels(pin1, vih_1[site], vil_1[site], vref_1[site]);
		ddd_set_frequency(freq);
		ddd_set_timings(pin1, tg1_1[site], tg2_1[site]);	
		break;

	case DVI:
	
		if(range_v_1=="RANGE_1_V") RNG=RANGE_1_V; else
		if(range_v_1=="RANGE_2_V") RNG=RANGE_2_V; else
		if(range_v_1=="RANGE_5_V") RNG=RANGE_5_V; else
		if(range_v_1=="RANGE_10_V") RNG=RANGE_10_V; else
		if(range_v_1=="RANGE_20_V") RNG=RANGE_20_V; else
		if(range_v_1=="RANGE_50_V") RNG=RANGE_50_V; else
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}

		if(compensation_v_1=="FAST_VOLTAGE_MODE") COMP=FAST_VOLTAGE_MODE; else
		if(compensation_v_1=="SLOW_VOLTAGE_MODE") COMP=SLOW_VOLTAGE_MODE; else
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}

		DVI_Used[site].DVI_slot->set_voltage(DVI_Used[site].DVI_channel, vcc_1, RNG, COMP);
		break;

	case OVI:
		
		if(range_v_1=="RANGE_1_V") RNG=RANGE_1_V; else
		if(range_v_1=="RANGE_2_V") RNG=RANGE_2_V; else
		if(range_v_1=="RANGE_5_V") RNG=RANGE_5_V; else
		if(range_v_1=="RANGE_10_V") RNG=RANGE_10_V; else
		if(range_v_1=="RANGE_20_V") RNG=RANGE_20_V; else
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}

		OVI_Used[site].OVI_slot->set_voltage(OVI_Used[site].OVI_channel, vcc_1, RNG);
		break;

	default:
		{
		char err_message[100];
		sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin1][site].Pin_Name);
		mytext.text_in_box(40,10,err_message);
		return;
		}
	}
	

	if(pin2>=0)	
	{
		Card_type=pin_selection(pin2,site);

		switch(Card_type)
		{
		case DDD:
		
			ddd_set_levels(pin2, vih_2[site], vil_2[site], vref_2[site]);
			ddd_set_frequency(freq);
			ddd_set_timings(pin2, tg1_2[site], tg2_2[site]);	
			break;

		case DVI:
			
			if(range_v_2=="RANGE_1_V") RNG=RANGE_1_V; else
			if(range_v_2=="RANGE_2_V") RNG=RANGE_2_V; else
			if(range_v_2=="RANGE_5_V") RNG=RANGE_5_V; else
			if(range_v_2=="RANGE_10_V") RNG=RANGE_10_V; else
			if(range_v_2=="RANGE_20_V") RNG=RANGE_20_V; else
			if(range_v_2=="RANGE_50_V") RNG=RANGE_50_V; else
				{
				char err_message[100];
				sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
				}

			if(compensation_v_2=="FAST_VOLTAGE_MODE") COMP=FAST_VOLTAGE_MODE; else
			if(compensation_v_2=="SLOW_VOLTAGE_MODE") COMP=SLOW_VOLTAGE_MODE; else
				{
				char err_message[100];
				sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
				}

			DVI_Used[site].DVI_slot->set_voltage(DVI_Used[site].DVI_channel, vcc_2, RNG, COMP);
			delay(1);
			break;

		case OVI:
		
			if(range_v_2=="RANGE_1_V") RNG=RANGE_1_V; else
			if(range_v_2=="RANGE_2_V") RNG=RANGE_2_V; else
			if(range_v_2=="RANGE_5_V") RNG=RANGE_5_V; else
			if(range_v_2=="RANGE_10_V") RNG=RANGE_10_V; else
			if(range_v_2=="RANGE_20_V") RNG=RANGE_20_V; else
				{
				char err_message[100];
				sprintf(err_message, "ddd_shmoo() cannot restore previous settings for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
				mytext.text_in_box(40,10,err_message);
				return;
				}

			OVI_Used[site].OVI_slot->set_voltage(OVI_Used[site].OVI_channel, vcc_2, RNG);
			delay(1);
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_shmoo() not executable for pin %s",Pin_Type_Used[pin2][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}
	}

	
	for(i=0; i<max_sites; i++)
		active_site[i]=save_active_sites[i];


	
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("Shmoo plot for pin %s - Site %i - Compare %c\n",Pin_Type_Used[pin1][site].Pin_Name, site, compare_char);
	printf("Pattern '%s', Label '%s' (Vector #%i, DDD Mem Addr 0x%x)\n", pattern_name, entry_label, vector_number, ddd_memory_address);
	printf("\n");

	char start_buf[20], stop_buf[20], step_buf[20];
	char axis_buf[10];
	char units_buf[10];
	char tag1_buf[10];
	char tag2_buf[10];

	switch(par1_type)
	{
		case SHMOO_VCC: strcpy(axis_buf, "VCC"); strcpy(units_buf, "V"); strcpy(tag1_buf, " VCC"); break;
		case SHMOO_VIH: strcpy(axis_buf, "VIH"); strcpy(units_buf, "V"); strcpy(tag1_buf, " VIH"); break;
		case SHMOO_VIL: strcpy(axis_buf, "VIL"); strcpy(units_buf, "V"); strcpy(tag1_buf, " VIL"); break;
		case SHMOO_VREF: strcpy(axis_buf, "VREF"); strcpy(units_buf, "V"); strcpy(tag1_buf, "VREF"); break;
		case SHMOO_T1: strcpy(axis_buf, "TG1"); strcpy(units_buf, "S"); strcpy(tag1_buf, " TG1"); break;
		case SHMOO_T2: strcpy(axis_buf, "TG2"); strcpy(units_buf, "S"); strcpy(tag1_buf, " TG2"); break;
		case SHMOO_PERIOD: strcpy(axis_buf, "PERIOD"); strcpy(units_buf, "S"); strcpy(tag1_buf, " PER"); break;
		case SHMOO_FREQ: strcpy(axis_buf, "FREQUENCY"); strcpy(units_buf, "Hz"); strcpy(tag1_buf, "FREQ"); break;
	}

	float_to_str(par1_start, start_buf);
	float_to_str(par1_stop, stop_buf);
	float_to_str(step1, step_buf);

	printf("X axis: %s - %s, Min %s%s, Max %s%s, Step %s%s\n", Pin_Type_Used[pin1][site].Channel_Name, axis_buf, start_buf, units_buf, stop_buf, units_buf, step_buf, units_buf);


	if(pin2>=0)
	{
		switch(par2_type)
		{
		case SHMOO_VCC: strcpy(axis_buf, "VCC"); strcpy(units_buf, "V"); strcpy(tag2_buf, " VCC"); break;
		case SHMOO_VIH: strcpy(axis_buf, "VIH"); strcpy(units_buf, "V"); strcpy(tag2_buf, " VIH"); break;
		case SHMOO_VIL: strcpy(axis_buf, "VIL"); strcpy(units_buf, "V"); strcpy(tag2_buf, " VIL"); break;
		case SHMOO_VREF: strcpy(axis_buf, "VREF"); strcpy(units_buf, "V"); strcpy(tag2_buf, "VREF"); break;
		case SHMOO_T1: strcpy(axis_buf, "TG1"); strcpy(units_buf, "S"); strcpy(tag2_buf, " TG1"); break;
		case SHMOO_T2: strcpy(axis_buf, "TG2"); strcpy(units_buf, "S"); strcpy(tag2_buf, " TG2"); break;
		case SHMOO_PERIOD: strcpy(axis_buf, "PERIOD"); strcpy(units_buf, "S"); strcpy(tag2_buf, " PER"); break;
		case SHMOO_FREQ: strcpy(axis_buf, "FREQUENCY"); strcpy(units_buf, "Hz"); strcpy(tag2_buf, "FREQ"); break;
		}
	
		float_to_str(par2_start, start_buf);
		float_to_str(par2_stop, stop_buf);
		float_to_str(step2, step_buf);

		printf("Y axis: %s - %s, Min %s%s, Max %s%s, Step %s%s\n", Pin_Type_Used[pin2][site].Channel_Name, axis_buf, start_buf, units_buf, stop_buf, units_buf, step_buf, units_buf);
		
		printf("\n%s+",tag2_buf);
		for(i=0;i<par1_nsteps;i++)
			((i+1)%5==0) ? printf("+") : printf("-");
		printf("+\n");

		for(j=0;j<par2_nsteps;j++)
		{
			((par2_nsteps-j)%5==0) ? printf("    +") : printf("    |");
			for(i=0;i<par1_nsteps;i++)
			{
				if(ShmooResult[i+par1_nsteps*(par2_nsteps-1-j)]==true)
					printf("*");
				else
					printf(" ");
			}
		((par2_nsteps-j)%5==0) ? printf("+\n") : printf("|\n");
		}
	}
	else
	{
		printf("\n    +");
		for(i=0;i<par1_nsteps;i++)
			((i+1)%5==0) ? printf("+") : printf("-");
		printf("+\n    |");

		for(i=0;i<par1_nsteps;i++)
		{
			if(ShmooResult[i]==true)
				printf("*");
			else
				printf(" ");
		}
		printf("|\n");
	}

	printf("    +");
	for(i=0;i<par1_nsteps;i++)
		((i+1)%5==0) ? printf("+") : printf("-");
	printf("+\n");
	for(i=0;i<par1_nsteps+2;i++) printf(" ");
	printf("%s\n",tag1_buf);
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");

	delete ShmooResult;
}


void ddd_delete_all_patterns(void)
{

	if(DDD_Last_Pattern!=NULL)	
	while(DDD_Last_Pattern->prevptr!=NULL)
	{
		printf("\nPattern %s deleted\n",DDD_Last_Pattern->pat_name);
		DDD_Last_Pattern=DDD_Last_Pattern->prevptr;
		delete DDD_Last_Pattern->nextptr;
	}

	printf("\nPattern %s deleted\n",DDD_Last_Pattern->pat_name);
	if(DDD_Pattern_List!=NULL)
		delete DDD_Pattern_List;

	DDD_Pattern_List=DDD_Last_Pattern=NULL;
}

void ddd_set_vih(short pin, double vih)
{
	ddd_set_vih(pin, float(vih));
}

void ddd_set_vih(short pin, float vih)
{


	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	int				slot;

	pin_ptr = group_selection(pin); 

	do	
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vih=vih;
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_set_vih() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
		if(DDD_Card_Used[slot].card_ptr->ddd_get_high_level()!=DDD_Card_Used[slot].Vih)
			DDD_Card_Used[slot].card_ptr->ddd_set_hi_level(DDD_Card_Used[slot].Vih);

}


void ddd_get_vih(short pin, sfloat vih)
{


	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;

	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
if(!debug_ddd_msl_offline)	
			vih[site]=DDD_Used[site].DDD_slot->ddd_get_high_level();
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vih=vih[site];
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_get_vih() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}


}


void ddd_get_vih(short pin_list, sfloat *vih_list)
{


	short			pin;
	sfloat			single_pin_vih;
	int				list_depth=0;
	int				i, n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vih(pin, single_pin_vih);

	
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			vih_list[list_depth-1-n][i]=single_pin_vih[i];

		pin_ptr = pin_ptr->nextptr;
	}
}

void ddd_set_vil(short pin, double vil)	
{
	ddd_set_vil(pin, float(vil));
}

void ddd_set_vil(short pin, float vil)
{
	

	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	int				slot;

	pin_ptr = group_selection(pin); 

	do	
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vil=vil;
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_set_vil() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
		if(DDD_Card_Used[slot].card_ptr->ddd_get_lo_level()!=DDD_Card_Used[slot].Vil)
			DDD_Card_Used[slot].card_ptr->ddd_set_lo_level(DDD_Card_Used[slot].Vil);

}


void ddd_get_vil(short pin, sfloat vil)
{


	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;

	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
if(!debug_ddd_msl_offline)	
			vil[site]=DDD_Used[site].DDD_slot->ddd_get_lo_level();
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vil=vil[site];
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_get_vil() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

}


void ddd_get_vil(short pin_list, sfloat *vil_list)
{
	

	short			pin;
	sfloat			single_pin_vil;
	int				list_depth=0;
	int				i, n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vil(pin, single_pin_vil);

		
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			vil_list[list_depth-1-n][i]=single_pin_vil[i];

		pin_ptr = pin_ptr->nextptr;
	}
}

void ddd_set_vref(short pin, double vref)
{
	ddd_set_vref(pin, float(vref));
}

void ddd_set_vref(short pin, float vref)
{
	

	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	int				slot;

	pin_ptr = group_selection(pin); 

	do	
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vref=vref;
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_set_vref() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
		if(DDD_Card_Used[slot].card_ptr->ddd_get_voltage_ref()!=DDD_Card_Used[slot].Vref)
			DDD_Card_Used[slot].card_ptr->ddd_set_voltage_ref(DDD_Card_Used[slot].Vref);

}

void ddd_get_vref(short pin, sfloat vref)
{
	

	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;

	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
if(!debug_ddd_msl_offline)	
			vref[site]=DDD_Used[site].DDD_slot->ddd_get_voltage_ref();
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vref=vref[site];
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_get_vref() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

}


void ddd_get_vref(short pin_list, sfloat *vref_list)
{


	short			pin;
	sfloat			single_pin_vref;
	int				list_depth=0;
	int				i, n;

	DYN_GROUP_LIST	*pin_ptr;
	DYN_GROUP_LIST	*start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		ddd_get_vref(pin, single_pin_vref);

	
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			vref_list[list_depth-1-n][i]=single_pin_vref[i];

		pin_ptr = pin_ptr->nextptr;
	}
}
void ddd_set_levels(short pin,  float vih, float vil, double vref)	
{
	ddd_set_levels(pin,  vih, vil, float(vref));
}
void ddd_set_levels(short pin,  float vih, double vil, float vref)	
{
	ddd_set_levels(pin,  vih, float(vil), vref);
}
void ddd_set_levels(short pin,  float vih, double vil, double vref)	
{
	ddd_set_levels(pin,  vih, float(vil), float(vref));
}
void ddd_set_levels(short pin,  double vih, float vil, float vref)	
{
	ddd_set_levels(pin,  float(vih), vil, vref);
}
void ddd_set_levels(short pin,  double vih, float vil, double vref)
{
	ddd_set_levels(pin,  float(vih), vil, float(vref));
}
void ddd_set_levels(short pin,  double vih, double vil, float vref)	
{
	ddd_set_levels(pin,  float(vih), float(vil), vref);
}
void ddd_set_levels(short pin,  double vih, double vil, double vref)
{
	ddd_set_levels(pin,  float(vih), float(vil), float(vref));
}

void ddd_set_levels(short pin,  float vih, float vil, float vref)
{


	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	int				slot;

	pin_ptr = group_selection(pin); 

	do	
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vih=vih;
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vil=vil;
			DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].Vref=vref;
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_set_levels() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);

	for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
{
		if(DDD_Card_Used[slot].card_ptr->ddd_get_high_level()!=DDD_Card_Used[slot].Vih)
			DDD_Card_Used[slot].card_ptr->ddd_set_hi_level(DDD_Card_Used[slot].Vih);
		if(DDD_Card_Used[slot].card_ptr->ddd_get_lo_level()!=DDD_Card_Used[slot].Vil)
			DDD_Card_Used[slot].card_ptr->ddd_set_lo_level(DDD_Card_Used[slot].Vil);
		if(DDD_Card_Used[slot].card_ptr->ddd_get_voltage_ref()!=DDD_Card_Used[slot].Vref)
			DDD_Card_Used[slot].card_ptr->ddd_set_voltage_ref(DDD_Card_Used[slot].Vref);
}
}

void ddd_set_period(double period)
{
	ddd_set_period(float(period));
}

void ddd_set_period(float period)
{

	int				slot;

	if ((period>=71.4287e-9f)&&(period<=3.125e-6f))
	{
		for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
{
			if(DDD_Card_Used[slot].card_ptr->ddd_get_clock_freq()!=1/period)
			{
				DDD_Card_Used[slot].clock_freq=1/period;
				DDD_Card_Used[slot].card_ptr->ddd_set_clock_period(period);
			}
}else DDD_Card_Used[slot].clock_freq=1/period;

	}
	else MessageBox(NULL,"Pattern period must be 71.4287ns to 3.125us","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
}

void ddd_get_period(float *period)
{


	float			frequency=0.0f;

	if(DDD_Card_Used[6].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
		frequency=DDD_Card_Used[6].card_ptr->ddd_get_clock_freq();
	if(frequency>0)
		*period=1/frequency;
}

void ddd_set_frequency(double frequency)	
{
	ddd_set_frequency(float(frequency));
}

void ddd_set_frequency(float frequency)
{

	int				slot;

	if ((frequency>=2.5f)&&(frequency<=14.0e6f))
	{
		for( slot = 0; slot < 21 ; slot++ ) if(DDD_Card_Used[slot].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
{
			if(DDD_Card_Used[slot].card_ptr->ddd_get_clock_freq()!=frequency)
			{
				DDD_Card_Used[slot].clock_freq=frequency;
				DDD_Card_Used[slot].card_ptr->ddd_set_clock_freq(frequency);
			}
}else DDD_Card_Used[slot].clock_freq=frequency;
	}
	else MessageBox(NULL,"Pattern frequency must be 320kHz to 14MHz","Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
}
		
void ddd_get_frequency(float *frequency)
{


	if(DDD_Card_Used[6].card_ptr!=NULL)
if(!debug_ddd_msl_offline)	
		*frequency=DDD_Card_Used[6].card_ptr->ddd_get_clock_freq();
}

void ddd_set_timings(short pin, double tg1, double tg2)	
{
	ddd_set_timings(pin, float(tg1), float(tg2));
}

void ddd_set_timings(short pin, float tg1, double tg2)	
{
	ddd_set_timings(pin, tg1, float(tg2));
}

void ddd_set_timings(short pin, double tg1, float tg2)
{
	ddd_set_timings(pin, float(tg1), tg2);
}

void ddd_set_timings(short pin, float tg1, float tg2)
{
	

	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	float			t1, t2;

	pin_ptr = group_selection(pin); 

	do	
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
if(!debug_ddd_msl_offline)	
			DDD_Used[site].DDD_slot->ddd_get_delays (DDD_Used[site].DDD_channel, t1, t2);
			if((t1!=tg1)||(t2!=tg2))
			{
				
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].timings_program_due=true;
				
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].tg1[DDD_Used[site].DDD_channel-1]=tg1;
				
				DDD_Card_Used[Pin_Type_Used[pin][site].Slot-1].tg2[DDD_Used[site].DDD_channel-1]=tg2;
			}
		break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_set_timings() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

	pin_ptr = pin_ptr->nextptr;

	} while (pin_ptr != NULL);
}

void ddd_get_timings(short pin, sfloat tg1, sfloat tg2)
{
	

	short			Card_type;
	DYN_GROUP_LIST	*pin_ptr;
	int				site;
	float			t1, t2;

	pin_ptr = group_selection(pin); 

	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ ) if(active_site[site])
	{
		
		Card_type=pin_selection(pin,site);

		switch(Card_type)
		{
		case DDD:
if(!debug_ddd_msl_offline)	
			DDD_Used[site].DDD_slot->ddd_get_delays (DDD_Used[site].DDD_channel, t1, t2);
			tg1[site]=t1;
			tg2[site]=t2;
			break;

		default:
			{
			char err_message[100];
			sprintf(err_message, "ddd_get_timings() not executable for pin %s",Pin_Type_Used[pin][site].Pin_Name);
			mytext.text_in_box(40,10,err_message);
			return;
			}
		}

	}

}



void vi_measure(short pin, short mode ,float *res_ptr ,short ave_num, short d_range, short wait_us)
{
	
	

	int i;
	short Source_type;
	DYN_GROUP_LIST *pin_ptr;

	STRING  measure_mode, prg_name;
	
	
	
	pin_ptr = group_selection(pin); 
	
	DYN_GROUP_LIST *anker_ptr = pin_ptr;

	do
	{

	pin = pin_ptr->grouppin;





	i=0;



	for( i = 0; i < max_sites ; i++ )
		if(active_site[i])
			Source_type=pin_selection(pin,i); 

	if (Source_type == OVI_S)	
	{
		for( i = 0; i < max_sites ; i++ )
			if(active_site[i])
			{
				if (wait_us != 0) {
					if(mode == MEASURE_VOLTAGE)
						OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE);
					if(mode == MEASURE_CURRENT)
						OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_CURRENT);

					wait.delay_10_us(int(wait_us/10));
				}

				if(ave_num > 1)
					*(res_ptr + i) = OVI_Used[i].OVI_slot->measure_average(ave_num);
				else
					*(res_ptr + i) = OVI_Used[i].OVI_slot->measure();
			}
	} else
	switch(Source_type)
	{

			case NONE: break;	

			case DVI:
			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{

						if(mode == MEASURE_VOLTAGE)
							DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_VOLTAGE);
						if(mode == MEASURE_DIFF_VOLTAGE)
							{
								DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_DIFF);
							
								if (d_range != NO_DIFF_RANGE)
									DVI_Used[i].DVI_slot->set_diff_range(d_range);
							}
						if(mode == MEASURE_CURRENT)
							DVI_Used[i].DVI_slot->set_meas_mode(DVI_Used[i].DVI_channel, DVI_MEASURE_CURRENT);
				}
			}	

			wait.delay_10_us(int(wait_us/10));

			for( i = 0; i < max_sites ; i++ )
			{
				if(active_site[i])
				{

						if(ave_num > 1)
							*(res_ptr + i) = DVI_Used[i].DVI_slot->measure_average(ave_num);
						else
							*(res_ptr + i) = DVI_Used[i].DVI_slot->measure();
				}
			}			
			break;

		case OVI:
		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{
						if(mode == MEASURE_VOLTAGE)
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_VOLTAGE);
						if(mode == MEASURE_CURRENT)
							OVI_Used[i].OVI_slot->set_meas_mode(OVI_Used[i].OVI_channel, OVI_MEASURE_CURRENT);
			}		
		}

		wait.delay_10_us(int(wait_us/10));

		for( i = 0; i < max_sites ; i++ )
		{
			if(active_site[i])
			{

				if(ave_num > 1)
					*(res_ptr + i) = OVI_Used[i].OVI_slot->measure_average(ave_num);
				else
					*(res_ptr + i) = OVI_Used[i].OVI_slot->measure();
			}
		}
				break;

			default:
				mytext.text_in_box(40,10,"vi_measure() not executable for a relay pin");
				exit(0);
			
	
	}  

	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}


int Pin_Ref_To_Pin_Name(short pin_ref, char *pin_name)
{


	
	int pin=0;

	if(pin_ref<pin_inserted)
	{
		strcpy(pin_name, Pin_Type_Used[pin][0].Pin_Name);
		return 0;
	}
	else return -1;	
}

int Pin_Name_To_Pin_Ref(const char *pin_name)
{


	
	int pin=0;


	while(strcmp(Pin_Type_Used[pin][0].Pin_Name,pin_name)&&(pin<pin_inserted))
		pin++;


	if(pin==pin_inserted)	
		return -1;
	else
		return Pin_Type_Used[pin][0].Pin_Ref;
}












void create_s_wf(sdouble_wf MS_Array, unsigned int size)
{
	if(size>0)
		for(int site=0;site<max_sites;site++)
			MS_Array[site]=new double[size];
}

void create_s_wf(sfloat_wf MS_Array, unsigned int size)
{
	if(size>0)
		for(int site=0;site<max_sites;site++)
			MS_Array[site]=new float[size];
}

void delete_s_wf(sdouble_wf MS_Array)
{
	for(int site=0;site<max_sites;site++)
		delete[] MS_Array[site];
}

void delete_s_wf(sfloat_wf MS_Array)
{
	for(int site=0;site<max_sites;site++)
		delete[] MS_Array[site];
}

#ifndef	LegacyXerxes
void xvi_arm(short pin_list, XviTrigType TrigAction, double TrigLevel, bool capture)

{
	int site, slot;
	short pin;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;
	char	ErrorMessage[100];

	
	pin_ptr = group_selection(pin_list); 
	
	
	for(slot=0; slot<21;slot++)
	{
		XVI_Card_Used[slot].arm_mask				=0x0;
		XVI_Card_Used[slot].card_arm_due			=false;
		XVI_Card_Used[slot].card_armed				=false;	
		XVI_Card_Used[slot].bank_0_enabled			=false;
		XVI_Card_Used[slot].bank_1_enabled			=false;
		XVI_Card_Used[slot].measurement_duration	=0;
		XVI_Card_Used[slot].sw_trigger				=false;
	}


	do
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ )
	{
		if(active_site[site])
		{
			Source_type=pin_selection(pin,site);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
				
				XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].arm_mask=XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].arm_mask|XVI_Used[site].XVI_channel;	
			

				if(capture)
				{
				
if(!debug_xvi_msl_offline)	

					XVI_Used[site].XVI_slot->arm(XVI_Used[site].XVI_channel, XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].samples[XVI_Used[site].XVI_ch_index]);
					XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_armed=true;
				}
				else
					
					XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_arm_due=true;

				if((TrigAction==XVI_EXT_TRIG_POS)||(TrigAction==XVI_EXT_TRIG_NEG))
				{
					
					if((XVI_Used[site].XVI_channel>=XVI_CHANNEL_0)&&(XVI_Used[site].XVI_channel<XVI_CHANNEL_7))
						XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].bank_0_enabled;
					else
						XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].bank_1_enabled;
				}

				
				if(XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_ptr==NULL)
					XVI_Card_Used[Pin_Type_Used[pin][site].Slot-1].card_ptr=XVI_Used[site].XVI_slot;

				
			
			break;
			default:
				sprintf(ErrorMessage,"xvi_arm executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	


	if(!capture)	
		for(slot=0; slot<21; slot++) if(XVI_Card_Used[slot].card_arm_due)
		{					
if(!debug_xvi_msl_offline)	
		XVI_Card_Used[slot].card_ptr->arm(XVI_Card_Used[slot].arm_mask);
		XVI_Card_Used[slot].card_armed=true;	
		}

	
	if(TrigAction==XVI_EXT_TRIG_POS)
	{
		for(slot=0; slot<21; slot++) if((XVI_Card_Used[slot].bank_0_enabled)||(XVI_Card_Used[slot].bank_1_enabled))	
		
		{
			if(XVI_Card_Used[slot].bank_0_enabled)
			{
if(!debug_xvi_msl_offline)
				XVI_Card_Used[slot].card_ptr->set_external_trigger_positive(XVI_EXT_TRG0,TrigLevel);
			}
			if(XVI_Card_Used[slot].bank_1_enabled)
			{
if(!debug_xvi_msl_offline)
				XVI_Card_Used[slot].card_ptr->set_external_trigger_positive(XVI_EXT_TRG1,TrigLevel);
			}
			
if(!debug_xvi_msl_offline)
			XVI_Card_Used[slot].card_ptr->set_measurement_ext_trigger(XVI_Card_Used[slot].arm_mask);	
			
		}
	}else
	if(TrigAction==XVI_EXT_TRIG_NEG)
	{
		for(slot=0; slot<21; slot++) if((XVI_Card_Used[slot].bank_0_enabled)||(XVI_Card_Used[slot].bank_1_enabled))	
		
		{
			if(XVI_Card_Used[slot].bank_0_enabled)
			{
if(!debug_xvi_msl_offline)
				XVI_Card_Used[site].card_ptr->set_external_trigger_negative(XVI_EXT_TRG0,TrigLevel);
			}
			if(XVI_Card_Used[slot].bank_1_enabled)
			{
if(!debug_xvi_msl_offline)
				XVI_Card_Used[site].card_ptr->set_external_trigger_negative(XVI_EXT_TRG1,TrigLevel);
			}
			
if(!debug_xvi_msl_offline)
			XVI_Card_Used[slot].card_ptr->set_measurement_ext_trigger(XVI_Card_Used[slot].arm_mask);	
			
		}
	}else	
	{
		XVI_Timer.Start();
	
		for(slot=0; slot<21; slot++) if(XVI_Card_Used[slot].card_armed)	
		{
if(!debug_xvi_msl_offline)
			XVI_Card_Used[slot].card_ptr->set_measurement_int_trigger(XVI_Card_Used[slot].arm_mask);	
if(!debug_xvi_msl_offline)
			XVI_Card_Used[slot].card_ptr->trigger_immediate(XVI_Card_Used[slot].arm_mask);
			XVI_Card_Used[slot].sw_trigger=true;
if(!debug_xvi_msl_offline)
			XVI_Card_Used[slot].measurement_duration=(XVI_Card_Used[slot].card_ptr->card.xvi_image_sample_count+1)*(XVI_Card_Used[slot].card_ptr->card.xvi_image_sample_period);	
		
		
			XVI_Card_Used[slot].time_stamp_sw_trig=XVI_Timer.GetElapsedTime()*(float)(1 uS);


			XVI_Card_Used[slot].card_armed=false;
		}
	}
}

void xvi_read_average(short pin, sDouble result)
{
	int site;
	sdouble result_array[1];
	
	xvi_read_average(pin, result_array);

	for(site=0; site < max_sites; site++) if (active_site[site])
		result[site] = result_array[0][site];
}

void xvi_read_average(short pin_list, sDouble *res_list_ptr)
{

	
	
	short pin;
	sdouble single_pin_result[1];

	int list_depth=0;
	int i, n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		xvi_read_average(pin, single_pin_result);

	
		for( i = 0; i < max_sites ; i++ ) if(active_site[i])
			res_list_ptr[list_depth-1-n][i]=single_pin_result[0][i];

		pin_ptr = pin_ptr->nextptr;
	}
}

void xvi_read_average(short pin, sdouble result)
{
	int site;
	sdouble result_array[1];
	
	xvi_read_average(pin, result_array);

	for(site=0; site < max_sites; site++) if (active_site[site])
		result[site] = result_array[0][site];
}

void xvi_read_average(short pin_list, sdouble *result_ptr)
{
	int site, slot;
	short pin;
	short index;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;

	XVI_ERROR_CODE_e XviRetError=XVI_EC_NO_ERROR_INFO;
	UINT16	samples_remaining=0;
	double	readback;
	bool	measurement_valid;
	char	ErrorMessage[100];
	float	measurement_duration=0;
	float	measurement_trigger_time=0;
	float	elapsed_meas_time=0;

	
	pin_ptr = group_selection(pin_list); 
	

	for(slot=0; slot<21;slot++)
	{

		if(XVI_Card_Used[slot].measurement_duration>measurement_duration)
			measurement_duration=XVI_Card_Used[slot].measurement_duration;
		
		if((XVI_Card_Used[slot].time_stamp_sw_trig>measurement_trigger_time)&&(XVI_Card_Used[slot].sw_trigger))	
			measurement_trigger_time=XVI_Card_Used[slot].time_stamp_sw_trig;
	}



	
		

	elapsed_meas_time=XVI_Timer.GetElapsedTime()*(float)(1 uS)-measurement_trigger_time; 
	if(elapsed_meas_time<measurement_duration) 
		wait.delay_10_us((int)((measurement_duration-elapsed_meas_time)/(float)(10 uS))); 

	index=0;	

	do
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ )
	{
		if(active_site[site])
		{
			Source_type=pin_selection(pin,site);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
				if(result_ptr!=NULL)
				{
if(!debug_xvi_msl_offline)	
					XviRetError=XVI_Used[site].XVI_slot->read(XVI_Used[site].XVI_channel, 0, &samples_remaining, &readback, &measurement_valid);	
					result_ptr[index][site]=readback;
					if(!measurement_valid)	
					{
						sprintf(ErrorMessage,"Warning! Clipping occurred in xvi_read_average on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
						printf(ErrorMessage);
					}
				}
				else
if(!debug_xvi_msl_offline)	
					XviRetError=XVI_Used[site].XVI_slot->read(XVI_Used[site].XVI_channel, 0, &samples_remaining);
					
				if(XviRetError==XVI_EC_TIMEOUT)
				{
					sprintf(ErrorMessage,"xvi_read_average timeout on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				} else
				
				if(samples_remaining>0)
				{
					sprintf(ErrorMessage,"xvi_read_average capture not complete on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
				break;
			default:
				sprintf(ErrorMessage,"xvi_read_average executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}	
	}  
	pin_ptr = pin_ptr->nextptr;
	index++;	
	}  while (pin_ptr != NULL);	
}

int xvi_read_capture(short pin, sdouble_wf site_capture)
{
	int			site;
	int			num_samples;
	sdouble_wf  site_capture_ptr[1];
	
	num_samples=xvi_read_capture(pin, site_capture_ptr);

	for(site=0; site < max_sites; site++) if (active_site[site])
		site_capture[site] = site_capture_ptr[0][site];

	return num_samples;
}

int xvi_read_capture(short pin_list, sdouble_wf  *site_capture_ptr)
{
	int site, slot, i;
	short pin;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;

	XVI_ERROR_CODE_e XviRetError=XVI_EC_NO_ERROR_INFO;
	UINT16	samples_remaining=0;
	int		num_samples;
	bool	keep_looping=false;
	char	ErrorMessage[100];

	double	avg;
	bool	measurement_valid;	
	float	measurement_duration=0;
	float	measurement_trigger_time=0;	
	float	elapsed_meas_time=0;

	
	pin_ptr = group_selection(pin_list); 
	
	
	for(slot=0; slot<21;slot++)
	{
		
		if(XVI_Card_Used[slot].measurement_duration>measurement_duration)
			measurement_duration=XVI_Card_Used[slot].measurement_duration;
		
		if((XVI_Card_Used[slot].time_stamp_sw_trig>measurement_trigger_time)&&(XVI_Card_Used[slot].sw_trigger))	
			measurement_trigger_time=XVI_Card_Used[slot].time_stamp_sw_trig;
	}

	
	
		
		

	elapsed_meas_time=XVI_Timer.GetElapsedTime()*(float)(1 uS)-measurement_trigger_time; 
	if(elapsed_meas_time<measurement_duration) 
		wait.delay_10_us((int)((measurement_duration-elapsed_meas_time)/(float)(10 uS))); 

	i=0;

	do
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ )
	{
		if(active_site[site])
		{
			Source_type=pin_selection(pin,site);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
if(!debug_xvi_msl_offline)	
{
				slot=XVI_Used[site].XVI_slot->board_no;		
				num_samples=XVI_Used[site].XVI_slot->card.xvi_image_sample_count;
				XviRetError=XVI_Used[site].XVI_slot->read(XVI_Used[site].XVI_channel, 0, &samples_remaining, &avg, &measurement_valid);	
				if(!measurement_valid)	
				{
					sprintf(ErrorMessage,"Warning! Clipping occurred in xvi_read_capture on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					printf(ErrorMessage);
				}
}
				
				site_capture_ptr[i][site]=XVI_Card_Used[slot].samples[XVI_Used[site].XVI_ch_index];

				if(XviRetError==XVI_EC_TIMEOUT)
				{
					sprintf(ErrorMessage,"xvi_read_capture timeout on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				} else
				
				if(samples_remaining>0)
				{
					sprintf(ErrorMessage,"xvi_read_capture capture not complete on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
			break;
			default:
				sprintf(ErrorMessage,"xvi_read_capture executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}
	}  
	pin_ptr = pin_ptr->nextptr;
	i++;
	}  while (pin_ptr != NULL);	

	return	num_samples;
}

void xvi_sampling_setup(short pin_list, short num_samples, double sampling_period_or_freqency, XviSamplingModeType sampling_mode)
{
	xvi_sampling_setup(pin_list, num_samples, XVI_INT_CLOCK, sampling_period_or_freqency, sampling_mode);
}

void xvi_sampling_setup(short pin_list, short num_samples, XviClockModeType clock_mode, double sampling_period_or_freqency, XviSamplingModeType sampling_mode)
{
	int site;
	short pin;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;
	char	ErrorMessage[100];
	double	XviSamplingPeriod, XviSamplingFrequency;

	XVI_ERROR_CODE_e 
		XviRetError1=XVI_EC_NO_ERROR_INFO, 
		XviRetError2=XVI_EC_NO_ERROR_INFO,
		XviRetError3=XVI_EC_NO_ERROR_INFO;
	
	
	pin_ptr = group_selection(pin_list); 

	do
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ )
	{
		if(active_site[site])
		{
			Source_type=pin_selection(pin,site);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
				if(clock_mode==XVI_INT_CLOCK)
				{
					
if(!debug_xvi_msl_offline)	
{
					if (((XVI_Used[site].XVI_channel<XVI_CHANNEL_7)&&(XVI_Used[site].XVI_slot->card.xvi_imageISE_ext_int_trig_ctl[0]==true))||
						((XVI_Used[site].XVI_channel>=XVI_CHANNEL_7)&&(XVI_Used[site].XVI_slot->card.xvi_imageISE_ext_int_trig_ctl[1]==true)))
							XviRetError1=XVI_Used[site].XVI_slot->set_sample_clk_int(XVI_Used[site].XVI_channel);

					XviSamplingPeriod=XVI_Used[site].XVI_slot->card.xvi_image_sample_period;
					XviSamplingFrequency=(XviSamplingPeriod>0 ? 1/XviSamplingPeriod : 0);
}
					
					if(sampling_period_or_freqency<5.0e-6)		
						sampling_period_or_freqency=5.0e-6;

					
					if((sampling_mode==XVI_SET_PERIOD)&&((float)sampling_period_or_freqency!=(float)XviSamplingPeriod))	
					{
if(!debug_xvi_msl_offline)	
						XviRetError2=XVI_Used[site].XVI_slot->set_sample_period (sampling_period_or_freqency);
					} else
					if((sampling_mode==XVI_SET_FREQUENCY)&&(sampling_period_or_freqency!=XviSamplingFrequency))
					{
if(!debug_xvi_msl_offline)	
						XviRetError2=XVI_Used[site].XVI_slot->set_sample_frequency (sampling_period_or_freqency);
					}
				}
				else 
				{
if(!debug_xvi_msl_offline)	
					
					if (((XVI_Used[site].XVI_channel<XVI_CHANNEL_7)&&(XVI_Used[site].XVI_slot->card.xvi_imageISE_ext_int_trig_ctl[0]==false))||
						((XVI_Used[site].XVI_channel>=XVI_CHANNEL_7)&&(XVI_Used[site].XVI_slot->card.xvi_imageISE_ext_int_trig_ctl[1]==false)))
							XviRetError1=XVI_Used[site].XVI_slot->set_sample_clk_ext(XVI_Used[site].XVI_channel);
				}

if(!debug_xvi_msl_offline)	
				if(num_samples!=XVI_Used[site].XVI_slot->card.xvi_image_sample_count)
					XviRetError3=XVI_Used[site].XVI_slot->set_sample_count (num_samples);

				if(XviRetError1!=XVI_EC_NO_ERROR_INFO)
				{
					sprintf(ErrorMessage,"xvi_sampling_setup failed while setting clock source on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
				if(XviRetError2!=XVI_EC_NO_ERROR_INFO)
				{
					sprintf(ErrorMessage,"xvi_sampling_setup failed while setting sampling period/frequency on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
				if(XviRetError3!=XVI_EC_NO_ERROR_INFO)
				{
					sprintf(ErrorMessage,"xvi_sampling_setup failed while setting samples number on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
			break;
			default:
				sprintf(ErrorMessage,"xvi_read_capture executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

}

void xvi_measure_filter(short pin_list, XviFilteringModeType filtering_mode)
{
	int site;
	short pin;
	DYN_GROUP_LIST *pin_ptr;
	short Source_type;
	char	ErrorMessage[100];

	XVI_ERROR_CODE_e XviRetError=XVI_EC_NO_ERROR_INFO;
	
	
	pin_ptr = group_selection(pin_list); 

	do
	{
	pin = pin_ptr->grouppin;

	for( site = 0; site < max_sites ; site++ )
	{
		if(active_site[site])
		{
			Source_type=pin_selection(pin,site);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
				
if(!debug_xvi_msl_offline)	
{
				if((filtering_mode==XVI_ENABLE_FILTER)&&(XVI_Used[site].XVI_slot->card.xvi_image_low_pass_filter[XVI_Used[site].XVI_ch_index])==false)
					XviRetError=XVI_Used[site].XVI_slot->enable_measure_filter(XVI_Used[site].XVI_channel);
				else if((filtering_mode==XVI_DISABLE_FILTER)&&(XVI_Used[site].XVI_slot->card.xvi_image_low_pass_filter[XVI_Used[site].XVI_ch_index])==true)
					XviRetError=XVI_Used[site].XVI_slot->disable_measure_filter(XVI_Used[site].XVI_channel);
}

				if(XviRetError!=XVI_EC_NO_ERROR_INFO)
				{
					sprintf(ErrorMessage,"xvi_measure_filter failed while setting filter on XVI%i Channel %i",Pin_Type_Used[pin][site].Slot, XVI_Used[site].XVI_ch_index);
					MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
					printf(ErrorMessage);
				}
			break;
			default:
				sprintf(ErrorMessage,"xvi_measure_filter executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

void xvi_force_current_pulse(short pin_list, double current, double voltage, double pulse_width, short c_range, short v_range)
{
	

	int i;
	sdouble s_current;
	sdouble s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
		{
			s_current[i]=current;
			s_voltage[i]=voltage;
		}

	xvi_force_current_pulse(pin_list, s_current, s_voltage, pulse_width, c_range, v_range);
}

void xvi_force_current_pulse(short pin_list, double current, sdouble voltage, double pulse_width, short c_range,short v_range)
{


	int i;
	sdouble s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=current;

	xvi_force_current_pulse(pin_list, s_current, voltage, pulse_width, c_range, v_range);
}

void xvi_force_current_pulse(short pin_list, sdouble current, double voltage, double pulse_width, short c_range,short v_range)
{
	

	int i;
	sdouble s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=voltage;

	xvi_force_current_pulse(pin_list, current, s_voltage, pulse_width, c_range, v_range);
}

void xvi_force_current_pulse(short pin_list, sdouble *current, sdouble *voltage, double pulse_width, short c_range, short v_range)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		xvi_force_current_pulse(pin, current[list_depth-1-n], voltage[list_depth-1-n], pulse_width, c_range, v_range);

		pin_ptr = pin_ptr->nextptr;
	}
}

void xvi_force_current_pulse(short pin_list, double current, sdouble *voltage, double pulse_width, short c_range, short v_range)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int i;
	sdouble s_current;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_current[i]=current;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		xvi_force_current_pulse(pin, s_current, voltage[list_depth-1-n], pulse_width, c_range, v_range);

		pin_ptr = pin_ptr->nextptr;
	}
}

void xvi_force_current_pulse(short pin_list, sdouble *current, double voltage, double pulse_width, short c_range, short v_range)
{
	
	
	short pin;
	int list_depth=0;
	int n;
	DYN_GROUP_LIST *pin_ptr;
	DYN_GROUP_LIST *start_pin_ptr;
	int i;
	sdouble s_voltage;

	for(i = 0; i < max_sites ; i++ )
		if(active_site[i]) 
			s_voltage[i]=voltage;
	
	start_pin_ptr = group_selection(pin_list); 

	
	pin_ptr = start_pin_ptr; 
	while (pin_ptr != NULL)
	{
		pin_ptr = pin_ptr->nextptr;
		list_depth++;
	}

	pin_ptr = start_pin_ptr; 
	for(n=0; n<list_depth; n++)
	{	
		pin = pin_ptr->grouppin;

		xvi_force_current_pulse(pin, current[list_depth-1-n], s_voltage, pulse_width, c_range, v_range);

		pin_ptr = pin_ptr->nextptr;
	}
}
#if 0
void xvi_force_current_pulse(short pin_list, sdouble current, sdouble voltage, double pulse_width, short c_range, short v_range)
{
	

	int				i;
	int				slot;
	short			pin;
	short			Source_type;
	DYN_GROUP_LIST	*pin_ptr;
	char			ErrorMessage[100];
	XVI_ERROR_CODE_e XviRetError=XVI_EC_NO_ERROR_INFO;
	
	
	pin_ptr = group_selection(pin_list); 

	
	
	

	do
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
				case NONE:
					break;
				case XVI:
if(!debug_xvi_msl_offline)	
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask=XVI_Card_Used[Pin_Type_Used[pin][i].Slot].force_mask|XVI_Used[i].XVI_channel;
					break;
			default:
				sprintf(ErrorMessage,"xvi_force_current_pulse executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	

	
	for(slot=0; slot<21;slot++)	if(XVI_Card_Used[slot].force_mask!=0x0)
	{
		if ((c_range == AUTORANGE)&&(v_range == AUTORANGE))
		{
if(!debug_xvi_msl_offline)	
			XviRetError=XVI_Used[i].XVI_slot->force_current_pulse(XVI_Card_Used[slot].force_mask, voltage[i], current[i], pulse_width);
		}
		else
		{
if(!debug_xvi_msl_offline)	
			XviRetError=XVI_Used[i].XVI_slot->force_current_pulse(XVI_Card_Used[slot].force_mask, voltage[i], v_range, current[i], c_range, pulse_width);
		}


		

			
		
		
		
	
			
		
		
		
	
			
		
		
		if(XviRetError!=XVI_EC_NO_ERROR_INFO)
		{
			sprintf(ErrorMessage,"xvi_force_current_pulse failed while setting XVI%i",slot);
			MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}

		
		XVI_Card_Used[slot].force_mask=0x0;
	}
}

#endif
void xvi_force_current_pulse(short pin_list, sdouble current, sdouble voltage, double pulse_width, short c_range, short v_range)
{
	
	
	int					i;
	int					slot;
	short				pin;
	short				Source_type;
	DYN_GROUP_LIST		*pin_ptr;
	DYN_GROUP_LIST		*start_pin_ptr;
	char				ErrorMessage[100];
	XVI_ERROR_CODE_e	XviRetError			= XVI_EC_NO_ERROR_INFO;
	bool				xvi_any_cards_used			= false;	
	double				v_rng, i_rng;

	
	for(slot=0; slot<21;slot++)
	{
		XVI_Card_Used[slot].force_mask			= 0x0;
		XVI_Card_Used[slot].block_programming	= true;
	}

	start_pin_ptr = group_selection(pin_list); 
	pin_ptr = start_pin_ptr;

	do
	{
	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE:
				break;
			case XVI:
		
				XviRetError = XVI_EC_NO_ERROR_INFO;	
				v_rng		= -10000.0;	
				i_rng		= -10000.0;	

				if ((c_range != AUTORANGE)||(v_range != AUTORANGE))
				{
					
					switch(v_range)
					{
					case RANGE_1_V:		v_rng=1.0;	break;	
					case RANGE_2_V:							
					case RANGE_3_V:		v_rng=3.0;	break;	
					case RANGE_5_V:		v_rng=5.0;	break;	
					case RANGE_10_V:	v_rng=10.0;	break;	
					case RANGE_20_V:						
					case RANGE_30_V:	v_rng=30.0;	break;	
					default:			v_rng=-10000.0;
					}

					switch(c_range)
					{
					case RANGE_2_UA:							
					case RANGE_3_UA:	i_rng=3.0e-6;	break;	
					case RANGE_20_UA:							
					case RANGE_30_UA:	i_rng=30.0e-6;	break;	
					case RANGE_200_UA:							
					case RANGE_300_UA:	i_rng=300.0e-6;	break;	
					case RANGE_2_MA:							
					case RANGE_3_MA:							
					case RANGE_10_MA:	i_rng=10.0e-3;	break;	
					case RANGE_20_MA:							
					case RANGE_30_MA:							
					case RANGE_100_MA:	i_rng=((double)current[i] > 100.0e-3 ? 150.0e-3 : 100.0e-3);	break;
					default:			i_rng=-10000.0;	
					}
				}

				
				if((XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask==0x0)&&(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming))
				{
					
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage=voltage[i];
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current=current[i];
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_irng=i_rng;
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_vrng=v_rng;
				}
				
		
				if	((c_range == AUTORANGE)&&(v_range == AUTORANGE))
				{
					
					if	(	
						((float)voltage[i]==XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage)&&
						((float)current[i]==XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current)&&
						(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)
						)
					{
						
if(!debug_xvi_msl_offline)	
						if	(
							(current[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
							(voltage[i]!=(float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))
							)
						{
						
							XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask|=(UINT16)XVI_Used[i].XVI_channel;
							
							if(!xvi_any_cards_used)
								xvi_any_cards_used=true;
						}
					}
					else
						
						XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				else 
				{
					
					if	(	
						(voltage[i]	== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_voltage)&&
						(current[i]	== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_current)&&
						(i_rng		== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_irng)&&
						(v_rng		== XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_vrng)&&
						(XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming)
						)
					{
						
if(!debug_xvi_msl_offline)
						if	(
							(current[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_current[XVI_Used[i].XVI_ch_index]))||
							(voltage[i]	!= (float)(XVI_Used[i].XVI_slot->card.xvi_image_voltage[XVI_Used[i].XVI_ch_index]))||
							(i_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_current_range[XVI_Used[i].XVI_ch_index])||
							(v_rng		!= XVI_Used[i].XVI_slot->card.xvi_image_voltage_range[XVI_Used[i].XVI_ch_index])
							)
						{
							
							XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].force_mask|=(UINT16)XVI_Used[i].XVI_channel;
						
							if(!xvi_any_cards_used)
								xvi_any_cards_used=true;
						}
					}
					else
					
						XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].block_programming=false;
				}
				break;
			default:
				sprintf(ErrorMessage,"xvi_force_current_pulse executable for XVI pins only");
				MessageBox(NULL,ErrorMessage,"Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}

	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
	
	
	if(xvi_any_cards_used)
		for(slot=0; slot<21;slot++)	if((XVI_Card_Used[slot].block_programming)&&(XVI_Card_Used[slot].force_mask!=0x0))
		{
			if ((c_range == AUTORANGE)&&(v_range == AUTORANGE))
			{
if(!debug_xvi_msl_offline)	
				XviRetError=XVI_Card_Used[slot].card_ptr->force_current_pulse(XVI_Card_Used[slot].force_mask,(double)((int)(XVI_Card_Used[slot].block_voltage*1.0e8))/1.0e8,(double)((int)(XVI_Card_Used[slot].block_current*1.0e8))/1.0e8, pulse_width);
				
			}
			else
			{
if(!debug_xvi_msl_offline)	
				XviRetError=XVI_Card_Used[slot].card_ptr->force_current_pulse(XVI_Card_Used[slot].force_mask,(double)((int)(XVI_Card_Used[slot].block_voltage*1.0e8))/1.0e8,XVI_Card_Used[slot].block_vrng,(double)((int)(XVI_Card_Used[slot].block_current*1.0e8))/1.0e8,XVI_Card_Used[slot].block_irng, pulse_width);
				
			}
			if(XviRetError!=XVI_EC_NO_ERROR_INFO)
			{
				sprintf(ErrorMessage,"xvi_force_current_pulse() error with XVI%i",slot);
				MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		
			XVI_Card_Used[slot].force_mask=0x0;
		}
}




XVI_ERROR_CODE_e xvi_set_voltage_mode(short pin_list, XVI_FORCE_VOLTAGE_MODE_e fv_mode, float settling_time)	
{
	int					i;
	int					slot;			
	short				pin;
	short				Source_type;
	DYN_GROUP_LIST		*pin_ptr;
	char				ErrorMessage[100];
	XVI_ERROR_CODE_e	XviRetError			= XVI_EC_NO_ERROR_INFO;
	bool				xvi_card_present	= false;

	pin_ptr = group_selection(pin_list); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case XVI:
				xvi_card_present = true;
				

				if(fv_mode!=XVI_Used[i].XVI_slot->card.xvi_image_force_voltage_mode)
					XVI_Card_Used[Pin_Type_Used[pin][i].Slot-1].fv_due=true;
			break;

			default:
				sprintf(ErrorMessage,"xvi_set_voltage_mode() not executable for this pin");
				MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
				printf(ErrorMessage);
			}
		}
	}  

	pin_ptr = pin_ptr->nextptr;

	}  while (pin_ptr != NULL);	

	if(xvi_card_present)
	
	{
		for(slot=0; slot<21; slot++) if(XVI_Card_Used[slot].fv_due)
		{					
if(!debug_xvi_msl_offline)	
		XviRetError=XVI_Card_Used[slot].card_ptr->select_force_voltage_mode(fv_mode);
		XVI_Card_Used[slot].fv_due=false;
		}

		if(XviRetError!=XVI_EC_NO_ERROR_INFO)
		{
			sprintf(ErrorMessage,"xvi_set_voltage_mode() error with XVI%i",slot);
			MessageBox(NULL,ErrorMessage,"XVI Error",MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			printf(ErrorMessage);
		}
		
		wait.delay_10_us(int(0.5+settling_time/(10.0e-6f)));
	}

	return(XviRetError);
}


#endif


void cbt_set_pull_voltage(short pin, unsigned short element)
{
	int i;
	short Source_type;
	char* CBT_group_str;
	DYN_GROUP_LIST *pin_ptr;
	
	
	
	pin_ptr = group_selection(pin); 

	do
	{

	pin = pin_ptr->grouppin;

	for( i = 0; i < max_sites ; i++ )
	{
		if(active_site[i])	
		{
			Source_type=pin_selection(pin,i);
			switch(Source_type)
			{
			case NONE: break;

			case CBT:
				switch(CBT_Used[i].CBT_unit)
				{
				case 0:CBT_group_str = "group_a";
					break;
				case 1:CBT_group_str = "group_b";
					break;
				case 2:CBT_group_str = "group_c";
					break;
				case 3:CBT_group_str = "group_d";
					break;
				}
				CBT_Used[i].CBT_slot->set_pull_voltage(CBT_group_str,element);
				break;

			default:
				mytext.text_in_box(40,10,"cbt_set_pull_voltage() only executable for TMU or QTMU1 or CBT pins");
				exit(0);
			}
		}	
	
	}  
	pin_ptr = pin_ptr->nextptr;
	}  while (pin_ptr != NULL);	
}

bool	MSdelay(double delay)		
{
	
	
	
	
	if(no_site_active())
		return false;
	
	wait.set_delay_time(delay);
	wait.do_delay();

	return true;
}

short get_pin_res_type(short pin, int site)		
{
	return pin_selection(group_selection(pin)->grouppin,site);
}

char	get_pin_res_ver(short pin, int site)		
{
	DYN_GROUP_LIST		*pin_ptr;
	int					slot;
	config_board		cb;

	pin_ptr = group_selection(pin); 
	slot=Pin_Type_Used[pin_ptr->grouppin][site].Slot;
	if(slot>0)
	{
		GetBoardConfig (slot-1, cb);
		return cb.revision[0];
	}
	else
		return '\0';
}
int		site_;					
sint	SerialBlockSiteBuffer;	





















