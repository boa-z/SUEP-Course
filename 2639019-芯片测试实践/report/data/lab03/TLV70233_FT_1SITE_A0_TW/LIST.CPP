//==============================================================================
// LIST.CPP
//==============================================================================
#include "asl.h"
#include "function.h"

// There are five elements in each structure for each array position
// as shown below :-
/*
typedef struct	{
		// First, a name that is displayed on the list of functions screen
	char		*name;
		// Next the development number;
	unsigned long develop_no;
		// Next, the name of the actual function.
	void far	(*address)(test_function& func);
		// Next, the parameter setup section of the function
	void far	(*setup)(test_function& func,char **function_name,char *heading_line);
		// Next, the default initialization of the parameters (and various
		// memory requirements.
	void far	(*initialize)(short entry,test_function& func,char **function_name);
		// Lastly, the size of the block of parameters
	short			sizeof_param_block;
				} test_descriptions;
*/

//{ASL_CREATE BEGIN_TEST_LIST_INIT

test_descriptions g_test_list[] =
{
	{ "T01_OS",0L,T01_OS,setup_T01_OS,initialize_T01_OS,sizeof(T01_OS_params) },
	{ "T02_current_test",0L,T02_current_test,setup_T02_current_test,initialize_T02_current_test,sizeof(T02_current_test_params) },
	{ "T03_VOLTAGE",0L,T03_VOLTAGE,setup_T03_VOLTAGE,initialize_T03_VOLTAGE,sizeof(T03_VOLTAGE_params) },
	{ "T04_UVL0",0L,T04_UVL0,setup_T04_UVL0,initialize_T04_UVL0,sizeof(T04_UVL0_params) },
	{ "T05_Ilimit_Ishort",0L,T05_Ilimit_Ishort,setup_T05_Ilimit_Ishort,initialize_T05_Ilimit_Ishort,sizeof(T05_Ilimit_Ishort_params) },
	{ "T06_TIME",0L,T06_TIME,setup_T06_TIME,initialize_T06_TIME,sizeof(T06_TIME_params) },
	{ "T07_OS_TEST",0L,T07_OS_TEST,setup_T07_OS_TEST,initialize_T07_OS_TEST,sizeof(T07_OS_TEST_params) },
	{ NULL,NULL }
};
// ASL_CREATE END_TEST_LIST_INIT}