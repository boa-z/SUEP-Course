//==============================================================================
// FUNCTION.H 
//==============================================================================

#pragma pack( push, 1 )
// ********************************************************************
// Next a structure holding all the parameters for each individual test
// function.


typedef struct
{
	float		os_fail;
} T01_OS_params;


typedef struct
{
	float		iq_fail;
	float		ishan_fail;
	float		ileckage_fail;
} T02_current_test_params;


typedef struct
{
	float		VOLTAGE_fail;
	float		LNR_fail;
	float		LDR_fail;
} T03_VOLTAGE_params;


typedef struct
{
	float		vin_fail;
	float		ven_fail;
} T04_UVL0_params;


typedef struct
{
	float		Ilimit_fail;
	float		Ishort_fail;
} T05_Ilimit_Ishort_params;


typedef struct
{
	float		Tstartup_fail;
} T06_TIME_params;


typedef struct
{
	float		os_fail;
} T07_OS_TEST_params;


// ********************************************************************
// Now pre-define the routines used in program development

/////////// T01_OS /////////////////////////////////////////////////////////
void T01_OS(test_function &func);
void initialize_T01_OS(short test_entry, test_function &func, char **func_name);
void setup_T01_OS(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T02_current_test ///////////////////////////////////////////////
void T02_current_test(test_function &func);
void initialize_T02_current_test(short test_entry, test_function &func, char **func_name);
void setup_T02_current_test(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T03_VOLTAGE ////////////////////////////////////////////////////
void T03_VOLTAGE(test_function &func);
void initialize_T03_VOLTAGE(short test_entry, test_function &func, char **func_name);
void setup_T03_VOLTAGE(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T04_UVL0 ///////////////////////////////////////////////////////
void T04_UVL0(test_function &func);
void initialize_T04_UVL0(short test_entry, test_function &func, char **func_name);
void setup_T04_UVL0(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T05_Ilimit_Ishort //////////////////////////////////////////////
void T05_Ilimit_Ishort(test_function &func);
void initialize_T05_Ilimit_Ishort(short test_entry, test_function &func, char **func_name);
void setup_T05_Ilimit_Ishort(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T06_TIME ///////////////////////////////////////////////////////
void T06_TIME(test_function &func);
void initialize_T06_TIME(short test_entry, test_function &func, char **func_name);
void setup_T06_TIME(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);


/////////// T07_OS_TEST ////////////////////////////////////////////////////
void T07_OS_TEST(test_function &func);
void initialize_T07_OS_TEST(short test_entry, test_function &func, char **func_name);
void setup_T07_OS_TEST(test_function &func, char **function_name, char *heading_line, unsigned short *want_print, char manual_setup);



#pragma pack( pop )
#include "USER.H"