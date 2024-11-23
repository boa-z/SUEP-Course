#ifndef _USER_H
#define _USER_H
//==============================================================================
// USER.H
//==============================================================================
//
#include "vType.h"
#include "vVector.h"
#include "vAnyTypeSharedData.h"
#include "vISetSharedData.h"
#include "ISiteMgrPub.h"
#include "sc_status.h"

#define CSC_SITEBASE (1)

extern int g_pid;
//{ BEGIN BOARDS_INIT_FROM_LIST_PROPERTIES
// Regenerating source code will change the code between here and END BOARDS_INIT_FROM_LIST_PROPERTIES}
// Use the List Properties dialog to drive the changes to this code.

void board_ptr_init(void);
void board_hardware_init(void);

extern Ov2* ov2_1;
extern Tmu* tmu_6;
extern Dvi* dvi_9;
extern Dvi* dvi_11;
extern Dvi* dvi_13;
extern Mux* mux_20;

// END BOARDS_INIT_FROM_LIST_PROPERTIES}
















//*************************
//Legacy VATE compatibility
//*************************
//ATE REV

//Windows NT
//----------
//define if using Vate Ver. < 5.2.2 (or comment out for 5.2.2 <= Vate < 5.3.1)
//#define LegacyVATE522

//define if using 5.2.2 <= Vate Ver. < 5.3.1 (or comment out for Vate >= 5.3.1)
#define LegacyVATE531	

//Windows XP
//----------
//define if using Vate Ver. < 6.1.1 (or comment out for Vate >= 6.1.1)
//#define	LegacyVATE611	

//BOARD REV

#define WINVER_SXHB	0x0501
#define BoardRev_SXHB 261
//*************************
//Legacy VATE compatibility
//*************************
#include "vType.h"
#include "sc_status.h"

void close_relay(void);
void open_relay(void);
void power_down(void);

//instrument multisite definitions
#include "./Programs/multisite/Multisite_lib.h"

//smath definition file
#include "./programs/multisite/smath.h"

//multisite pin definition file
#include "./Programs/multisite/TLV70233.map.res"


#endif _USER_H
