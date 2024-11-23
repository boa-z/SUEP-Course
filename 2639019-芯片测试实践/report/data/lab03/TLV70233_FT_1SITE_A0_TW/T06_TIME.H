//==============================================================================
// T06_TIME.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void T06_TIME_user_init(test_function& func);

// ***********************************************************

void initialize_T06_TIME(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	T06_TIME_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_T06_TIME(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
