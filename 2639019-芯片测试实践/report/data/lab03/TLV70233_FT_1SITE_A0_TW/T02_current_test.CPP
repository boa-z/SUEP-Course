//==============================================================================
// T02_current_test.cpp (User function)
// 
//    void T02_current_test_user_init(test_function& func)
//    void T02_current_test(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T02_current_test.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T02_current_test_user_init(test_function& func)
{
	T02_current_test_params *ours;
	ours = (T02_current_test_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T02_current_test(test_function& func)
{
	// The two lines below must be the first two in the function.
	T02_current_test_params *ours;
	ours = (T02_current_test_params *)func.params;

	//定义变量
	sfloat iq_noload={0},iq_load={0},Ivin={0},Ivout={0},ishdn={0},ileckage={0};

	//闭合继电器
	relay_connect(Relay_20BankGnd,CLOSE);
	relay_connect(KCvin,CLOSE);
	relay_connect(KCvout,CLOSE);
	delay(3);

	//初始化资源
	dc_connect(DVI_VIN,CLOSE);
	dc_force(DVI_VIN, 300.0 mA, 0.0 V, RANGE_2_A, RANGE_5_V); 

	dc_connect(OVI_EN,CLOSE);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);

	dc_connect(DVI_VOUT,CLOSE);
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);

	delay(3);

	//iq_noload**********
	dc_force(DVI_VIN, 300.0 mA, 5.0 V, RANGE_2_A, RANGE_5_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 
	
	dc_force(DVI_VIN, 1.0 mA, 5.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3);

	dc_measure(DVI_VIN, MEASURE_CURRENT, iq_noload, 20, NO_DIFF_RANGE, 200);
	
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	dc_force(DVI_VIN, 1.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3); 

	//iq_load**********

/*	relay_connect(KCvin,OPEN);
	relay_connect(KCvout,OPEN);
	delay(3);
	
	dc_force(DVI_VIN, 300.0 mA, 5.0 V, RANGE_2_A, RANGE_5_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_force(DVI_VOUT, -300.0 mA, -5.0 V, RANGE_2_A, RANGE_5_V);
	delay(3); 

	dc_measure(DVI_VIN, MEASURE_CURRENT, Ivin, 20, NO_DIFF_RANGE, 200);
	dc_measure(DVI_VOUT, MEASURE_CURRENT, Ivout, 20, NO_DIFF_RANGE, 200);
	
	dc_force(DVI_VOUT, 0.0 mA, -5.0 V, RANGE_2_A, RANGE_5_V);
	delay(3); 

	iq_load[0]=Ivin[0]+Ivout[0];

	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	dc_force(DVI_VIN, 300.0 mA, 0.0 V, RANGE_2_A, RANGE_5_V);
	delay(3); 
*/

	//ishdn**********
	relay_connect(KCvin,CLOSE);
	relay_connect(KCvout,CLOSE);
	delay(3);
	dc_connect(DVI_VOUT,OPEN);
	delay(3);


	dc_force(DVI_VIN, 1.0 mA, 5.0 V, RANGE_2_MA, RANGE_10_V);
	delay(3);

	dc_measure(DVI_VIN, MEASURE_CURRENT, ishdn, 20, NO_DIFF_RANGE, 200);

	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	dc_force(DVI_VIN, 1.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3);

	//ileckage**********

	dc_force(DVI_VIN, 1.0 mA, 5.0 V, RANGE_2_MA, RANGE_10_V);
	dc_force(OVI_EN, 0.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3);

	dc_measure(DVI_VIN, MEASURE_CURRENT, ileckage, 20, NO_DIFF_RANGE, 200);

	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 
	dc_force(DVI_VIN, 1.0 mA, 0.0 V, RANGE_2_MA, RANGE_5_V);
	delay(3); 

	//power down
	power_down();
	relay_connect(Relay_20BankGnd,OPEN);
	relay_connect(KCvin,OPEN);
	relay_connect(KCvout,OPEN);
	delay(3);

	//datalog
	data_log(func, 0,iq_noload, POWER_MICRO, ours->iq_fail);
	//data_log(func, 1,iq_load, POWER_MICRO, ours->iq_fail);
	data_log(func, 2,ishdn, POWER_MICRO, ours->ishan_fail);
	data_log(func, 3,ileckage,POWER_MICRO, ours->ileckage_fail);

}
