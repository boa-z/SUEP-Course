//==============================================================================
// T05_Ilimit_Ishort.cpp (User function)
// 
//    void T05_Ilimit_Ishort_user_init(test_function& func)
//    void T05_Ilimit_Ishort(test_function& func)
//
//==============================================================================

#include "asl.h"
// Disable warning C4244 "conversion from 'const double' to 'float', possible loss of data"
#pragma warning (disable : 4244)

#include "T05_Ilimit_Ishort.h"

// !!!! User #includes and externs can be placed between the comments
// !!!!

// *************************************************************************

void T05_Ilimit_Ishort_user_init(test_function& func)
{
	T05_Ilimit_Ishort_params *ours;
	ours = (T05_Ilimit_Ishort_params *)func.params;

// !!!! User initialization code below this comment (do not remove comment)

// !!!! User initialization code above this comment (do not remove comment)
}

// *************************************************************************

void T05_Ilimit_Ishort(test_function& func)
{
	// The two lines below must be the first two in the function.
	T05_Ilimit_Ishort_params *ours;
	ours = (T05_Ilimit_Ishort_params *)func.params;



	//define data
	sfloat Ilimit={0}, Ishort={0}, Iout={0}, Ivin={0};

	//闭合继电器
//	relay_connect(Relay_20BankGnd,CLOSE);
//	relay_connect(KCvin,CLOSE);
//	relay_connect(KCvout,CLOSE);
	delay(3);

	//初始化资源
	dc_connect(DVI_VIN,CLOSE);
	dc_force(DVI_VIN, 1.0 mA, 0.0 V, RANGE_2_A, RANGE_5_V);

	dc_connect(OVI_EN,CLOSE);
	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V); 

	dc_connect(DVI_VOUT,CLOSE);
	dc_force(DVI_VOUT, 0.0 mA, 0.0 V, RANGE_2_A, RANGE_5_V);

	delay(3);

	//Ilimit
	dc_force(DVI_VIN, 1.0 A, 5.0 V, RANGE_2_A, RANGE_5_V); 
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V);
	delay(3);

	for(Iout[0]=-0.01; Iout[0]>-1.0; Iout[0]=Iout[0]-0.01)
	{
				
		dc_force(DVI_VOUT, Iout[0], -5.0 V, RANGE_2_A, RANGE_5_V);
		delay(3);

		dc_measure(DVI_VIN, MEASURE_CURRENT, Ivin, 20, NO_DIFF_RANGE, 200);

		if(Ivin[0]+Iout[0]<-0.01)
		{
			Ilimit[0]=-Iout[0];
			break;
		}
	}

	dc_force(DVI_VOUT, -1.0 mA, 5.0 V, RANGE_2_A, RANGE_5_V);
	delay(10);

	//Ishort

	dc_force(DVI_VIN, 1.0 A, 5.0 V, RANGE_2_A, RANGE_10_V);
	dc_force(OVI_EN, 1.0 mA, 2.0 V, RANGE_5_MA, RANGE_5_V); 
	delay(3); 

	dc_force(DVI_VOUT, 1.0 A, 0 V, RANGE_2_A, RANGE_5_V);
	delay(3);

	dc_measure(DVI_VIN, MEASURE_CURRENT, Ishort, 20, NO_DIFF_RANGE, 200);

	dc_force(OVI_EN, 1.0 mA, 0.0 V, RANGE_5_MA, RANGE_5_V);
	dc_force(DVI_VIN, 1.0 A, 0.0 V, RANGE_2_A, RANGE_5_V);
	delay(3);

	//power down
	power_down();
	delay(3);

	//datalog
	data_log(func, 0, Ilimit, POWER_MILLI, ours->Ilimit_fail);
	data_log(func, 1, Ishort, POWER_MILLI, ours->Ishort_fail);

}
