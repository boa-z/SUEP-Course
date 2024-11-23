//==============================================================================
// USER.CPP
//==============================================================================
#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "USER.H"

extern "C" __declspec(dllexport) void user_init (void);
extern "C" __declspec(dllexport) void user_load (void);
extern "C" __declspec(dllexport) void user_start_lot (void);
extern "C" __declspec(dllexport) void user_wait_sot (void);
extern "C" __declspec(dllexport) void user_start_test (void);
extern "C" __declspec(dllexport) void user_end_test (void);
extern "C" __declspec(dllexport) void user_next_device (void);
extern "C" __declspec(dllexport) void user_end_lot (void);
extern "C" __declspec(dllexport) void user_exit (void);
extern "C" __declspec(dllexport) void user_F12 (void);

//{ BEGIN BOARDS_INIT_FROM_LIST_PROPERTIES
// Regenerating source code will change the code between here and END BOARDS_INIT_FROM_LIST_PROPERTIES}
// Use the List Properties dialog to drive the changes to this code.

Ov2* ov2_1 = NULL;
Tmu* tmu_6 = NULL;
Dvi* dvi_9 = NULL;
Dvi* dvi_11 = NULL;
Dvi* dvi_13 = NULL;
Mux* mux_20 = NULL;

void board_ptr_init(void)
{
	ov2_1 = &ov2_cards[board_ptr[BOARD_1]];
	tmu_6 = &tmu_cards[board_ptr[BOARD_6]];
	dvi_9 = &dvi_cards[board_ptr[BOARD_9]];
	dvi_11 = &dvi_cards[board_ptr[BOARD_11]];
	dvi_13 = &dvi_cards[board_ptr[BOARD_13]];
	mux_20 = &mux_cards[board_ptr[BOARD_20]];
}

void board_hardware_init(void)
{
	ov2_1->init();
	tmu_6->init();
	dvi_9->init();
	dvi_11->init();
	dvi_13->init();
	mux_20->init();
}
// END BOARDS_INIT_FROM_LIST_PROPERTIES}

















// This file must be present even if no user code is placed below
/* Below are a number of routines that are called by the main program at
various times. If the user needs to initialize any variables, or check for
any situations during these times he may "fill in the blanks".
*/

// **************************************************************************

void user_init(void)
{	//  As TEST.EXE loads, before program name etc.
}

// **************************************************************************

void user_load(void)
{	
	//  After Program Name + LDF + params limits are loaded.
	board_ptr_init();
	board_hardware_init();

	//load Multisite pin mapping file
	if (load_pinmap_file("TLV70233.map"))
		exit(0);
}

// **************************************************************************
void user_start_lot(void)
{ 
	//  after F2(start) or autostart, before look for SOT.

	//START Multisite
	SET_MAX_SITES;
	//END Multisite
}

// **************************************************************************
void user_wait_sot(void)
{	//  called in loop (many times) wait_sot.
}

// **************************************************************************
void user_start_test(void)
{	//  after SOT, before 1st function.

	//START Multisite get_active_sites call
	GET_ACTIVE_SITES;
	//STOP Multisite get_active_sites call
	continue_on_fail_PPflag();
}

// **************************************************************************
void user_end_test(void)
{	//  after last test, before binning device.
}

// **************************************************************************
void user_next_device(void)
{	//  after binning and EOT, before wait_sot
}

// **************************************************************************
void user_end_lot(void)
{	//  after last EOT in lot, before returning control to war(?)
}

// **************************************************************************
void user_exit(void)
{	//  (my guess) on program exit.
}

void user_F12(void)
{	//  User hit F12 from either OPERATOR or ENGINEERING.
}

//instrument multisite definitions
#include "./Programs/multisite/Multisite_lib.cpp"

//smath definition file
#include "./programs/multisite/smath.cpp"

void close_relay(void)
{
	mux_20->close_relay(MUX_2_BUS2);
	mux_20->close_relay(MUX_3_BUS3);
	mux_20->close_relay(MUX_4_BUS4);
	mux_20->close_relay(MUX_5_BUS5);
	mux_20->close_relay(MUX_6_BUS6);
	mux_20->close_relay(MUX_7_BUS7);
	mux_20->close_relay(MUX_8_BUS8);
	mux_20->close_relay(MUX_1_BUS9);
	mux_20->close_relay(MUX_BANK_1_2);
	mux_20->close_relay(MUX_BANK_2_3);
	mux_20->close_relay(MUX_BANK_3_4);
	mux_20->close_relay(MUX_BANK_4_5);
	mux_20->close_relay(MUX_BANK_5_6);
	mux_20->close_relay(MUX_BANK_6_7);
	mux_20->close_relay(MUX_BANK_7_8);
	mux_20->close_relay(MUX_BANK_8_1);
	mux_20->close_relay(MUX_2_GND);
	mux_20->close_relay(MUX_4_GND);
	mux_20->close_relay(MUX_6_GND);
	mux_20->close_relay(MUX_8_GND);
}

void open_relay(void)
{
	mux_20->open_relay(MUX_2_BUS2);
	mux_20->open_relay(MUX_3_BUS3);
	mux_20->open_relay(MUX_4_BUS4);
	mux_20->open_relay(MUX_5_BUS5);
	mux_20->open_relay(MUX_6_BUS6);
	mux_20->open_relay(MUX_7_BUS7);
	mux_20->open_relay(MUX_8_BUS8);
	mux_20->open_relay(MUX_1_BUS9);
	mux_20->open_relay(MUX_BANK_1_2);
	mux_20->open_relay(MUX_BANK_2_3);
	mux_20->open_relay(MUX_BANK_3_4);
	mux_20->open_relay(MUX_BANK_4_5);
	mux_20->open_relay(MUX_BANK_5_6);
	mux_20->open_relay(MUX_BANK_6_7);
	mux_20->open_relay(MUX_BANK_7_8);
	mux_20->open_relay(MUX_BANK_8_1);
	mux_20->open_relay(MUX_2_GND);
	mux_20->open_relay(MUX_4_GND);
	mux_20->open_relay(MUX_6_GND);
	mux_20->open_relay(MUX_8_GND);
}

void power_down(void)
{
	dc_force(DVI_VIN,0.0 uA,0.0 V,RANGE_20_MA,RANGE_10_V);
	delay(5);
	dc_connect(DVI_VOUT,OPEN);//disconnect ch DVI11_0
	delay(3);

	dc_force(DVI_VOUT,0.0 uA,0.0 V,RANGE_20_MA,RANGE_10_V);
	dc_force(OVI_EN,0.0 uA,0.0 V,RANGE_5_MA,RANGE_10_V);
	delay(2);
	dc_connect(DVI_VIN,OPEN);//disconnect ch DVI11_1
	dc_connect(OVI_EN,OPEN);//disconnect ch OVI1_0
	delay(3);

}

