//==============================================================================
// DLLMAIN.CPP
//==============================================================================

#include "asl.h"

#define NUM_OF_SLOTS 23

// ********************************************************************
// Function prototypes for local functions within DLLMAIN.CPP
BOOL InitializeProcessData (void);
BOOL UninitializeProcessData (void);

// ********************************************************************
// Process global data - this data is shared between all threads in the process
extern short g_test_descr_n;
extern unsigned short *g_pBoard_count;
extern board_desc **g_pBoard_descs;

FUNCTION_LIBRARY_EXPORT_INFO g_fle;

extern void initialize_required_board_configs(void);

// Turn off "warning C4101: xxx : unreferenced local variable" for dwThreadId and hThread
#pragma warning (disable : 4101)

// ********************************************************************
BOOL APIENTRY DllMain( HINSTANCE hInstDll, DWORD dwReason, LPVOID lpReserved )
{
	HANDLE hThread;
	DWORD dwThreadId;
	BOOL bReturnStatus = TRUE;

	switch (dwReason)
	{
		// The DLL is being mapped into the process's address space
		case DLL_PROCESS_ATTACH:
			break;

		// A thread is being created - not all threads may come here
		case DLL_THREAD_ATTACH:
			break;

		// A thread is exiting cleaning - not being terminated
		case DLL_THREAD_DETACH:
			break;

		// The DLL is being unmapped from the process's address space
		// Process must exit cleanly to come here - can't terminate
		case DLL_PROCESS_DETACH:
			UninitializeProcessData();
			break;
	}
	return (bReturnStatus);
}
// Set this warning back to default to be safe
#pragma warning (default : 4101)

BOOL InitializeProcessData(void)
{
	BOOL iret;
	int function_no, num_params, param_no, num_sub_tests, sub_test_no;
	FUNCTION_PARAM_DATA param;
	dlog_test dt_data;
	iret = g_fle.SetLibraryDevNum (0);
	iret = g_fle.SetFunctionsN (g_test_descr_n);

	// *** Information for Function 1
	function_no = 0;
	num_params = 1;
	num_sub_tests = 3;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T01_OS");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)5);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("os_fail");
	iret = param.SetCLangName("os_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"os_vin");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"os_en");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 3data
	sub_test_no = 2;
	strcpy(dt_data.test_name,"os_vout");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 2
	function_no = 1;
	num_params = 3;
	num_sub_tests = 4;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T02_current_test");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)6);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("iq_fail");
	iret = param.SetCLangName("iq_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 2
	iret = param.Value().SetValue((float)7);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("ishan_fail");
	iret = param.SetCLangName("ishan_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 3
	iret = param.Value().SetValue((float)8);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("ileckage_fail");
	iret = param.SetCLangName("ileckage_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"iq_noload");
	dt_data.power = 6;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)5.000000e-005;
	dt_data.f_max_limit_val[1] = (float)5.000000e-005;
	dt_data.f_max_limit_val[2] = (float)5.000000e-005;
	dt_data.f_max_limit_val[3] = (float)5.000000e-005;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)2.000000e-005;
	dt_data.f_min_limit_val[1] = (float)2.000000e-005;
	dt_data.f_min_limit_val[2] = (float)2.000000e-005;
	dt_data.f_min_limit_val[3] = (float)2.000000e-005;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"iq_load");
	dt_data.power = 6;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)5.000000e-004;
	dt_data.f_max_limit_val[1] = (float)5.000000e-004;
	dt_data.f_max_limit_val[2] = (float)5.000000e-004;
	dt_data.f_max_limit_val[3] = (float)5.000000e-004;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)2.000000e-004;
	dt_data.f_min_limit_val[1] = (float)2.000000e-004;
	dt_data.f_min_limit_val[2] = (float)2.000000e-004;
	dt_data.f_min_limit_val[3] = (float)2.000000e-004;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 3data
	sub_test_no = 2;
	strcpy(dt_data.test_name,"ishan");
	dt_data.power = 6;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)2.000000e-006;
	dt_data.f_max_limit_val[1] = (float)2.000000e-006;
	dt_data.f_max_limit_val[2] = (float)2.000000e-006;
	dt_data.f_max_limit_val[3] = (float)2.000000e-006;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)0.000000e+000;
	dt_data.f_min_limit_val[1] = (float)0.000000e+000;
	dt_data.f_min_limit_val[2] = (float)0.000000e+000;
	dt_data.f_min_limit_val[3] = (float)0.000000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 4data
	sub_test_no = 3;
	strcpy(dt_data.test_name,"ileckage");
	dt_data.power = 6;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)2.000000e-006;
	dt_data.f_max_limit_val[1] = (float)2.000000e-006;
	dt_data.f_max_limit_val[2] = (float)2.000000e-006;
	dt_data.f_max_limit_val[3] = (float)2.000000e-006;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)0.000000e+000;
	dt_data.f_min_limit_val[1] = (float)0.000000e+000;
	dt_data.f_min_limit_val[2] = (float)0.000000e+000;
	dt_data.f_min_limit_val[3] = (float)0.000000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 3
	function_no = 2;
	num_params = 3;
	num_sub_tests = 4;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T03_VOLTAGE");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)9);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("VOLTAGE_fail");
	iret = param.SetCLangName("VOLTAGE_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 2
	iret = param.Value().SetValue((float)10);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("LNR_fail");
	iret = param.SetCLangName("LNR_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 3
	iret = param.Value().SetValue((float)11);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("LDR-fail");
	iret = param.SetCLangName("LDR-fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"vout");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)3.366000e+000;
	dt_data.f_max_limit_val[1] = (float)3.366000e+000;
	dt_data.f_max_limit_val[2] = (float)3.366000e+000;
	dt_data.f_max_limit_val[3] = (float)3.366000e+000;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)3.234000e+000;
	dt_data.f_min_limit_val[1] = (float)3.234000e+000;
	dt_data.f_min_limit_val[2] = (float)3.234000e+000;
	dt_data.f_min_limit_val[3] = (float)3.234000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"vdropout");
	dt_data.power = 5;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)5.000000e-001;
	dt_data.f_max_limit_val[1] = (float)5.000000e-001;
	dt_data.f_max_limit_val[2] = (float)5.000000e-001;
	dt_data.f_max_limit_val[3] = (float)5.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)2.000000e-001;
	dt_data.f_min_limit_val[1] = (float)2.000000e-001;
	dt_data.f_min_limit_val[2] = (float)2.000000e-001;
	dt_data.f_min_limit_val[3] = (float)2.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 3data
	sub_test_no = 2;
	strcpy(dt_data.test_name,"LNR");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)1.000000e+000;
	dt_data.f_max_limit_val[1] = (float)1.000000e+000;
	dt_data.f_max_limit_val[2] = (float)1.000000e+000;
	dt_data.f_max_limit_val[3] = (float)1.000000e+000;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[1] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[2] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[3] = (float)-1.000000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"%");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 4data
	sub_test_no = 3;
	strcpy(dt_data.test_name,"LDR");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)1.000000e+000;
	dt_data.f_max_limit_val[1] = (float)1.000000e+000;
	dt_data.f_max_limit_val[2] = (float)1.000000e+000;
	dt_data.f_max_limit_val[3] = (float)1.000000e+000;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[1] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[2] = (float)-1.000000e+000;
	dt_data.f_min_limit_val[3] = (float)-1.000000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"%");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 4
	function_no = 3;
	num_params = 2;
	num_sub_tests = 4;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T04_UVL0");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)12);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("vin_fail");
	iret = param.SetCLangName("vin_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 2
	iret = param.Value().SetValue((float)13);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("ven_fail");
	iret = param.SetCLangName("ven_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"vin_H");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)2.100000e+000;
	dt_data.f_max_limit_val[1] = (float)2.100000e+000;
	dt_data.f_max_limit_val[2] = (float)2.100000e+000;
	dt_data.f_max_limit_val[3] = (float)2.100000e+000;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)1.800000e+000;
	dt_data.f_min_limit_val[1] = (float)1.800000e+000;
	dt_data.f_min_limit_val[2] = (float)1.800000e+000;
	dt_data.f_min_limit_val[3] = (float)1.800000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"vin_L");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)2.000000e+000;
	dt_data.f_max_limit_val[1] = (float)2.000000e+000;
	dt_data.f_max_limit_val[2] = (float)2.000000e+000;
	dt_data.f_max_limit_val[3] = (float)2.000000e+000;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)1.700000e+000;
	dt_data.f_min_limit_val[1] = (float)1.700000e+000;
	dt_data.f_min_limit_val[2] = (float)1.700000e+000;
	dt_data.f_min_limit_val[3] = (float)1.700000e+000;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 3data
	sub_test_no = 2;
	strcpy(dt_data.test_name,"ven_H");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)9.000000e-001;
	dt_data.f_max_limit_val[1] = (float)9.000000e-001;
	dt_data.f_max_limit_val[2] = (float)9.000000e-001;
	dt_data.f_max_limit_val[3] = (float)9.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)5.000000e-001;
	dt_data.f_min_limit_val[1] = (float)5.000000e-001;
	dt_data.f_min_limit_val[2] = (float)5.000000e-001;
	dt_data.f_min_limit_val[3] = (float)5.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 4data
	sub_test_no = 3;
	strcpy(dt_data.test_name,"ven_L");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)8.000000e-001;
	dt_data.f_max_limit_val[1] = (float)8.000000e-001;
	dt_data.f_max_limit_val[2] = (float)8.000000e-001;
	dt_data.f_max_limit_val[3] = (float)8.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)4.000000e-001;
	dt_data.f_min_limit_val[1] = (float)4.000000e-001;
	dt_data.f_min_limit_val[2] = (float)4.000000e-001;
	dt_data.f_min_limit_val[3] = (float)4.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 5
	function_no = 4;
	num_params = 2;
	num_sub_tests = 2;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T05_Ilimit_Ishort");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)14);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("Ilimit_fail");
	iret = param.SetCLangName("Ilimit_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	// *** Definition of param 2
	iret = param.Value().SetValue((float)15);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("Ishort_fail");
	iret = param.SetCLangName("Ishort_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"Ilimit");
	dt_data.power = 5;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)8.600000e-001;
	dt_data.f_max_limit_val[1] = (float)8.600000e-001;
	dt_data.f_max_limit_val[2] = (float)8.600000e-001;
	dt_data.f_max_limit_val[3] = (float)8.600000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)3.200000e-001;
	dt_data.f_min_limit_val[1] = (float)3.200000e-001;
	dt_data.f_min_limit_val[2] = (float)3.200000e-001;
	dt_data.f_min_limit_val[3] = (float)3.200000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"Ishort");
	dt_data.power = 5;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)8.600000e-001;
	dt_data.f_max_limit_val[1] = (float)8.600000e-001;
	dt_data.f_max_limit_val[2] = (float)8.600000e-001;
	dt_data.f_max_limit_val[3] = (float)8.600000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)3.200000e-001;
	dt_data.f_min_limit_val[1] = (float)3.200000e-001;
	dt_data.f_min_limit_val[2] = (float)3.200000e-001;
	dt_data.f_min_limit_val[3] = (float)3.200000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"A");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 6
	function_no = 5;
	num_params = 1;
	num_sub_tests = 1;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T06_TIME");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)16);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("Tstartup_fail");
	iret = param.SetCLangName("Tstartup_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"Tstartup");
	dt_data.power = 6;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)2.000000e-004;
	dt_data.f_max_limit_val[1] = (float)2.000000e-004;
	dt_data.f_max_limit_val[2] = (float)2.000000e-004;
	dt_data.f_max_limit_val[3] = (float)2.000000e-004;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)5.000000e-005;
	dt_data.f_min_limit_val[1] = (float)5.000000e-005;
	dt_data.f_min_limit_val[2] = (float)5.000000e-005;
	dt_data.f_min_limit_val[3] = (float)5.000000e-005;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"S");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// *** Information for Function 7
	function_no = 6;
	num_params = 1;
	num_sub_tests = 3;
	param_no = 0;
	iret = g_fle.SetFunctionDevNum (function_no,0L);
	iret = g_fle.SetFunctionName (function_no,"T07_OS_TEST");
	iret = g_fle.SetParamsN (function_no, num_params);
	iret = g_fle.SetSubTestsN (function_no, num_sub_tests);

	// *** Definition of param 1
	iret = param.Value().SetValue((float)17);
	iret = param.SetMultiplier(1.0);
	iret = param.Value ().m_power = 4;
	iret = param.SetUnitsString("");
	iret = param.SetUserInterfaceName("os_fail");
	iret = param.SetCLangName("os_fail");
	iret = g_fle.SetParamData(function_no,param_no++,param);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 1data
	sub_test_no = 0;
	strcpy(dt_data.test_name,"os_vin");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 2data
	sub_test_no = 1;
	strcpy(dt_data.test_name,"os_en");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	memset(&dt_data,0,sizeof(dlog_test));
	// *** Sub-test 3data
	sub_test_no = 2;
	strcpy(dt_data.test_name,"os_vout");
	dt_data.power = 4;
	dt_data.max_limit_active = TRUE;
	dt_data.f_max_limit_val[0] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[1] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[2] = (float)-2.000000e-001;
	dt_data.f_max_limit_val[3] = (float)-2.000000e-001;
	dt_data.min_limit_active = TRUE;
	dt_data.f_min_limit_val[0] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[1] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[2] = (float)-8.000000e-001;
	dt_data.f_min_limit_val[3] = (float)-8.000000e-001;
	strcpy(dt_data.pretest_comment,"");
	strcpy(dt_data.units,"V");
	strcpy(dt_data.note,"");

	iret = g_fle.SetSubTestData(function_no,sub_test_no,&dt_data);

	// Board info for functions
	initialize_required_board_configs();

	return TRUE;
}

BOOL UninitializeProcessData(void)
{
	short func;

	// For each function in this library, delete the board descriptors
	// then delete the array of pointers to those descriptors
	if (g_pBoard_descs)
	{
		for (func=0; func<g_test_descr_n; func++)
		{
			delete [] g_pBoard_descs[func];
		}
		delete [] g_pBoard_descs;
	}

	// Delete array containing the number of boards needed by each function.
	if (g_pBoard_count)
		delete [] g_pBoard_count;

	return TRUE;
}
