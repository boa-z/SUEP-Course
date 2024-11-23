//==============================================================================
// T01_OS.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void T01_OS_user_init(test_function& func);

// ***********************************************************

void initialize_T01_OS(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	T01_OS_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_T01_OS(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
