//==============================================================================
// T04_UVL0.h 
//==============================================================================

#include "asl.h"
#include "function.h"

void T04_UVL0_user_init(test_function& func);

// ***********************************************************

void initialize_T04_UVL0(short test_entry,test_function& func,char **function_name)
{
	func.dlog->set_datalog_inactive();

	T04_UVL0_user_init(func);

	func.dlog->test_offset = test_entry + 1;
}

// ***********************************************************

void setup_T04_UVL0(test_function &func,char **function_name,char *heading_line,unsigned short *want_print,char manual_setup)
{
}

// ***********************************************************
