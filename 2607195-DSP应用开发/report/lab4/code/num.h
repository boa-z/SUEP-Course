#ifndef SHOW_NUM_H_
#define SHOW_NUM_H_

#include"Macro_definition.h"

void show_num0(void)
{
    AX_ON;
    BX_ON;
    CX_ON;
    DX_ON;
    EX_ON;
    FX_ON;
    GX_OFF;
}

void show_num1(void)
{
    AX_OFF;
    BX_ON;
    CX_ON;
    DX_OFF;
    EX_OFF;
    FX_OFF;
    GX_OFF;
}

void show_num2(void)
{
    AX_ON;
    BX_ON;
    CX_OFF;
    DX_ON;
    EX_ON;
    FX_OFF;
    GX_ON;
}

void show_num3(void)
{
    AX_ON;
    BX_ON;
    CX_ON;
    DX_ON;
    EX_OFF;
    FX_OFF;
    GX_ON;
}

void show_num4(void)
{
    AX_OFF;
    BX_ON;
    CX_ON;
    DX_OFF;
    EX_OFF;
    FX_ON;
    GX_ON;
}

void show_num5(void)
{
    AX_ON;
    BX_OFF;
    CX_ON;
    DX_ON;
    EX_OFF;
    FX_ON;
    GX_ON;
}

void show_num6(void)
{
    AX_ON;
    BX_OFF;
    CX_ON;
    DX_ON;
    EX_ON;
    FX_ON;
    GX_ON;
}

void show_num7(void)
{
    AX_ON;
    BX_ON;
    CX_ON;
    DX_OFF;
    EX_OFF;
    FX_OFF;
    GX_OFF;
}

void show_num8(void)
{
    AX_ON;
    BX_ON;
    CX_ON;
    DX_ON;
    EX_ON;
    FX_ON;
    GX_ON;
}

void show_num9(void)
{
    AX_ON;
    BX_ON;
    CX_ON;
    DX_ON;
    EX_OFF;
    FX_ON;
    GX_ON;
}


void show_num_init(void)
{
    DPX_OFF;
    CX_OFF;
    DX_OFF;
    EX_OFF;
    GX_OFF;
    BX_OFF;
    AX_OFF;
    FX_OFF;
}

void order_open(void)
{
    DY1_ON;
    DY1_OFF;
    DY2_ON;
    DY2_OFF;
    DY3_ON;
    DY3_OFF;
    DY4_ON;
    DY4_OFF;
    DY5_ON;
    DY5_OFF;
    DY6_ON;
    DY6_OFF;
}


#endif /* SHOW_NUM_H_ */
