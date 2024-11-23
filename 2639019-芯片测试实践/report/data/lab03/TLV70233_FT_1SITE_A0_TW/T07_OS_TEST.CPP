//==============================================================================
// T07_OS_TEST.cpp (User function)
// 
//    void T07_OS_TEST_user_init(test_function& func)
//    void T07_OS_TEST(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T07_OS_TEST.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T07_OS_TEST_user_init(test_function& func)
{
	T07_OS_TEST_params *ours;
	ours = (T07_OS_TEST_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T07_OS_TEST(test_function& func)
{
	// The two lines below must be the first two in the function.
	T07_OS_TEST_params *ours;
	ours = (T07_OS_TEST_params *)func.params;

   //定义变量
	sfloat vin={0}, en={0}, vout={0};

	//闭合继电器
	relay_connect(Relay_20BankGnd,CLOSE);
	relay_connect(KCvin,CLOSE);
	relay_connect(KCvout,CLOSE);
	delay(3);

	//初始化资源
	dc_connect(DVI_VIN,CLOSE);
	dc_force(DVI_VIN, 0.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V); 

	dc_connect(OVI_EN,CLOSE);
	dc_force(OVI_EN, 0.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);

	dc_connect(DVI_VOUT,CLOSE);
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);

	delay(3);

	//os_vin
	dc_force(DVI_VIN, -200.0 uA, -2.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3);
	dc_measure(DVI_VIN, MEASURE_VOLTAGE, vin, 20, NO_DIFF_RANGE, 200);
	dc_force(DVI_VIN, 0.0 uA, 0.0 V, RANGE_2_MA, RANGE_5_V); 
	delay(3);

    //os_en
	dc_force(OVI_EN,-200.0 uA, -2.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);
	dc_measure(OVI_EN, MEASURE_VOLTAGE, en, 20, NO_DIFF_RANGE, 200);
	dc_force(OVI_EN, 0.0 uA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3);

	//os_vout
	dc_force(DVI_VOUT,-200.0 uA, -2.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3);
	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, vout, 20, NO_DIFF_RANGE, 200);
	dc_force(DVI_VOUT, 0.0 uA, 0.0 V, RANGE_2_MA, RANGE_5_V); 
	delay(3);

	//power down
	power_down();
	relay_connect(Relay_20BankGnd,OPEN);
	relay_connect(KCvin,OPEN);
	relay_connect(KCvout,OPEN);
	delay(3);

	//datalog
	data_log(func, 0, vin, POWER_UNIT, ours->os_fail);
	data_log(func, 1, en, POWER_UNIT, ours->os_fail);
	data_log(func, 2, vout, POWER_UNIT, ours->os_fail);

}
