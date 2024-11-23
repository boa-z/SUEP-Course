#include "asl.h"

// {ASL_CREATE BEGIN ALLOC_BRD_CFG
#define NUM_OF_SLOTS 22
unsigned short g_slots_n = NUM_OF_SLOTS;
unsigned short *g_pBoard_count = NULL;		// number of boards needed by each function
board_desc **g_pBoard_descs = NULL;

#define NUM_OF_FUNCTIONS_IN_LIST 7

short g_test_descr_n=NUM_OF_FUNCTIONS_IN_LIST;

// ASL_CREATE END ALLOC_BRD_CFG}

void initialize_required_board_configs (void)
{
	unsigned short num_boards;
	short func_i;

	// Allocate the array to contain the number of boards used by each function
	g_pBoard_count = new unsigned short[g_test_descr_n];

	g_pBoard_descs = (board_desc**)new short*[g_test_descr_n];

	// {ASL_CREATE BEGIN BOARD_INIT

	// Boards required by function[0] : T01_OS
	func_i = 0;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[1] : T02_current_test
	func_i = 1;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[2] : T03_VOLTAGE
	func_i = 2;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[3] : T04_UVL0
	func_i = 3;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[4] : T05_Ilimit_Ishort
	func_i = 4;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[5] : T06_TIME
	func_i = 5;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	// Boards required by function[6] : T07_OS_TEST
	func_i = 6;
	num_boards = 6;
	g_pBoard_count[func_i] = num_boards;
	g_pBoard_descs[func_i] = new board_desc[num_boards];

	g_pBoard_descs[func_i][0].slot_num = 1 - 1;
	g_pBoard_descs[func_i][0].board_type = OV2_CARD;
	g_pBoard_descs[func_i][0].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][1].slot_num = 6 - 1;
	g_pBoard_descs[func_i][1].board_type = TMU_CARD;
	g_pBoard_descs[func_i][1].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][2].slot_num = 9 - 1;
	g_pBoard_descs[func_i][2].board_type = DVI_CARD;
	g_pBoard_descs[func_i][2].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][3].slot_num = 11 - 1;
	g_pBoard_descs[func_i][3].board_type = DVI_CARD;
	g_pBoard_descs[func_i][3].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][4].slot_num = 13 - 1;
	g_pBoard_descs[func_i][4].board_type = DVI_CARD;
	g_pBoard_descs[func_i][4].share_type = DEDICATED_BOARD;


	g_pBoard_descs[func_i][5].slot_num = 20 - 1;
	g_pBoard_descs[func_i][5].board_type = MUX_CARD;
	g_pBoard_descs[func_i][5].share_type = DEDICATED_BOARD;


	//  ASL_CREATE END BOARD_INIT}

}
