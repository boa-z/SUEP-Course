//==============================================================================
// T03_VOLTAGE.cpp (User function)
// 
//    void T03_VOLTAGE_user_init(test_function& func)
//    void T03_VOLTAGE(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T03_VOLTAGE.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T03_VOLTAGE_user_init(test_function& func)
{
	T03_VOLTAGE_params *ours;
	ours = (T03_VOLTAGE_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T03_VOLTAGE(test_function& func)
{
	// The two lines below must be the first two in the function.
	T03_VOLTAGE_params *ours;
	ours = (T03_VOLTAGE_params *)func.params;

	//定义变量
    sfloat VOUT={0}, V_VOUT={0}, V_VIN={0}, Vdropout={0}, V1={0}, V2={0}, LNR={0}, V3={0}, V4={0}, LDR={0};
	sfloat I_VOUT={0},VIN={0};

	//闭合继电器
	relay_connect(Relay_20BankGnd,CLOSE);
	relay_connect(KCvin,CLOSE);
	relay_connect(KCvout,CLOSE);
	delay(3);

	//初始化资源
	dc_connect(DVI_VIN,CLOSE);
	dc_force(DVI_VIN, 10.0 mA, 0.0 V, RANGE_20_MA, RANGE_10_V); 

	dc_connect(OVI_EN,CLOSE);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);

	dc_connect(DVI_VOUT,CLOSE);
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_2_MA, RANGE_10_V);

	delay(3);



	//VOUT**********
	dc_force(DVI_VIN, 10.0 mA, 5.0 V, RANGE_20_MA, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);

	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, VOUT, 20, NO_DIFF_RANGE, 200);
	
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_20_MA, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);
	dc_force(DVI_VIN, 10.0 mA, 0.0 V, RANGE_20_MA, RANGE_10_V);
	delay(3);




	//Vdropout**********
	dc_force(DVI_VIN, 500.0 mA, 3.234 V, RANGE_2_A, RANGE_5_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_force(DVI_VOUT, -300.0 mA, -5.0 V, RANGE_2_A, RANGE_10_V);
    delay(3); 

	dc_measure(DVI_VIN, MEASURE_VOLTAGE, V_VIN, 20, NO_DIFF_RANGE, 200);
	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, V_VOUT, 20, NO_DIFF_RANGE, 200);

    Vdropout[0]=V_VIN[0]-V_VOUT[0];

	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_20_MA, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);
	dc_force(DVI_VIN, 300.0 mA, 0.0 V, RANGE_2_A, RANGE_10_V);
	delay(3);



	//LNR
	dc_force(DVI_VIN, 300.0 mA,3.8 V, RANGE_2_A, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, V1, 20, NO_DIFF_RANGE, 200);

	dc_force(DVI_VIN, 300.0 mA,5.5 V, RANGE_2_A, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, V2, 20, NO_DIFF_RANGE, 200);

	LNR[0]=fabs(V2[0]-V1[0])/VOUT[0];


	//LDR
	dc_force(DVI_VIN, 500.0 mA,5.0 V, RANGE_2_A, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, V3, 20, NO_DIFF_RANGE, 200);

	dc_force(DVI_VOUT, -300.0 mA, -5.0 V, RANGE_2_A, RANGE_10_V);
    delay(3); 

	dc_measure(DVI_VOUT, MEASURE_VOLTAGE, V4, 20, NO_DIFF_RANGE, 200);

	LDR[0]=fabs(V3[0]-V4[0])/VOUT[0];



	//power down
	power_down();
	relay_connect(Relay_20BankGnd,OPEN);
	relay_connect(KCvin,OPEN);
	relay_connect(KCvout,OPEN);
	delay(3);

	//datalog
	data_log(func, 0, VOUT, POWER_UNIT, ours->VOLTAGE_fail);
	data_log(func, 1, Vdropout, POWER_MILLI, ours->VOLTAGE_fail);
	data_log(func, 2, LNR, POWER_UNIT, ours->LNR_fail);
	data_log(func, 3, LDR, POWER_UNIT, ours->LDR_fail);

}
