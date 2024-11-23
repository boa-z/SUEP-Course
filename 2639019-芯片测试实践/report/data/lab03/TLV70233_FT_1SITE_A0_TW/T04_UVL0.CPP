//==============================================================================
// T04_UVL0.cpp (User function)
// 
//    void T04_UVL0_user_init(test_function& func)
//    void T04_UVL0(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T04_UVL0.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T04_UVL0_user_init(test_function& func)
{
	T04_UVL0_params *ours;
	ours = (T04_UVL0_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T04_UVL0(test_function& func)
{
	// The two lines below must be the first two in the function.
	T04_UVL0_params *ours;
	ours = (T04_UVL0_params *)func.params;

	//定义变量
	sfloat vin_H={0}, vin_L={0}, VCCH={0}, VCCL={0}, vout={0},ven_H={0}, ven_L={0};

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

	//vin_H
	dc_force(DVI_VIN, 10.0 mA, 0.5 V, RANGE_20_MA, RANGE_5_V); 
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);

	for(VCCH[0]=0.4; VCCH[0]<4.0; VCCH[0]=VCCH[0]+0.1)
	{
				
		dc_force(DVI_VIN, 10.0 mA, VCCH, RANGE_20_MA, RANGE_5_V);
		delay(3);

		dc_measure(DVI_VOUT, MEASURE_VOLTAGE, vout, 20, NO_DIFF_RANGE, 200);

		if(vout[0]>1.5 )
		{
			vin_H[0]=VCCH[0];
			break;
		}
	}

	//vin_L
	dc_force(DVI_VIN, 10.0 mA, 4.0 V, RANGE_20_MA, RANGE_5_V); 
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);
	
	for(VCCL[0]=4.0; VCCL[0]>0.4; VCCL[0]=VCCL[0]-0.1)
	{
				
		dc_force(DVI_VIN, 10.0 mA, VCCL, RANGE_20_MA, RANGE_5_V);
		delay(3);

		dc_measure(DVI_VOUT, MEASURE_VOLTAGE, vout, 20, NO_DIFF_RANGE, 200);

		if(vout[0]<1.5)
		{
			vin_L[0]=VCCL[0];
			break;
		}
	}
		
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);
	dc_force(DVI_VIN, 10.0 mA, 0.0 V, RANGE_20_MA, RANGE_5_V); 
	delay(3);

	//ven_H
	dc_force(DVI_VIN, 10.0 mA, 3 V, RANGE_20_MA, RANGE_5_V); 
	dc_force(OVI_EN, 1.0 mA, 0.5 V, RANGE_5_MA, RANGE_5_V);
	delay(3);

	for(VCCH[0]=0.4; VCCH[0]<4.0; VCCH[0]=VCCH[0]+0.1)
	{
				
		dc_force(OVI_EN, 1.0 mA, VCCH, RANGE_5_MA, RANGE_5_V);
		delay(3);

		dc_measure(DVI_VOUT, MEASURE_VOLTAGE, vout, 20, NO_DIFF_RANGE, 200);

		if(vout[0]>1.5 )
		{
			ven_H[0]=VCCH[0];
			break;
		}
	}

	//ven_L
	dc_force(DVI_VIN, 10.0 mA, 3.0 V, RANGE_20_MA, RANGE_5_V); 
	dc_force(OVI_EN, 1.0 mA, 4.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);
	
	for(VCCL[0]=4.0; VCCL[0]>0.4; VCCL[0]=VCCL[0]-0.1)
	{
				
		dc_force(OVI_EN, 2.0 mA, VCCL, RANGE_5_MA, RANGE_5_V);
		delay(3);

		dc_measure(DVI_VOUT, MEASURE_VOLTAGE, vout, 20, NO_DIFF_RANGE, 200);

		if(vout[0]<1.5)
		{
			ven_L[0]=VCCL[0];
			break;
		}
	}
		
	dc_force(OVI_EN, 2.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);
	dc_force(DVI_VIN, 10.0 mA, 0.0 V, RANGE_20_MA, RANGE_5_V); 
	delay(3);

	//power down
	power_down();
	relay_connect(Relay_20BankGnd,OPEN);
	relay_connect(KCvin,OPEN);
	relay_connect(KCvout,OPEN);
	delay(3);

	//datalog
	data_log(func, 0,vin_H, POWER_UNIT, ours->vin_fail);
	data_log(func, 1,vin_L, POWER_UNIT, ours->vin_fail);
	data_log(func, 2,ven_H, POWER_UNIT, ours->ven_fail);
	data_log(func, 3,ven_L,POWER_UNIT, ours->ven_fail);

}
