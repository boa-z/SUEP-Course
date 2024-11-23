//==============================================================================
// T06_TIME.cpp (User function)
// 
//    void T06_TIME_user_init(test_function& func)
//    void T06_TIME(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T06_TIME.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T06_TIME_user_init(test_function& func)
{
	T06_TIME_params *ours;
	ours = (T06_TIME_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T06_TIME(test_function& func)
{
	// The two lines below must be the first two in the function.
	T06_TIME_params *ours;
	ours = (T06_TIME_params *)func.params;

	//define data
	sfloat Tstartup={0};

	//闭合继电器
	
	//初始化资源
	dc_connect(DVI_VIN,CLOSE);
	dc_force(DVI_VIN, 10.0 mA, 0.0 V, RANGE_20_MA, RANGE_10_V);
	dc_connect(OVI_EN,CLOSE);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA , RANGE_5_V);
	dc_connect(DVI_VOUT,CLOSE);
	//dc_force(DVI_VOUT, -1.0 mA, -5.0 V, RANGE_20_MA, RANGE_10_V);
	delay(3);

    //Tstartup
	relay_connect(TMU_EN, CLOSE);
	relay_connect(TMU_VOUT, CLOSE);
	delay(3);

	tmu_start_trigger_setup(TMU_EN, (1.0 V), POS_SLOPE, TMU_IN_10V); 
	tmu_stop_trigger_setup(TMU_VOUT, (1.6 V), POS_SLOPE, TMU_IN_10V);
	delay(1);
	tmu_arm(TMU_EN);
	delay(1);


	dc_force(DVI_VIN, 10.0 mA, 5.0 V, RANGE_20_MA, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA , RANGE_5_V);
	delay(3);

	tmu_read(TMU_EN, Tstartup, 10e-3f);
	relay_connect(TMU_EN, OPEN);
	relay_connect(TMU_VOUT, OPEN);
	delay(3);

	//power down
	power_down();

	//out datalog
	data_log(func, 0, Tstartup, POWER_MICRO, ours->Tstartup_fail);

}
