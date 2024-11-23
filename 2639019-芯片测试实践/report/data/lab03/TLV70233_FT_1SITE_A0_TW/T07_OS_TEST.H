//==============================================================================
// T07_OS_TEST.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void T07_OS_TEST_user_init(test_function& func);

// ***********************************************************

void initialize_T07_OS_TEST(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	T07_OS_TEST_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_T07_OS_TEST(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
