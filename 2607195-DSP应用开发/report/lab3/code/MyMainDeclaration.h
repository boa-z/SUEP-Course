#include "My_Main_Declaration.h"

void main(void)
{
    InitSysCtrl();//初始化系统函数
    DINT;//关总中断
    IER=0x0000;//禁止CPU中断
    IFR=0x0000;//清除CPU中断标志
    InitPieCtrl();//初始化PIE控制寄存器
    InitPieVectTable(); //初始化PIE中断向量表
    Init_Gpio();//初始化GPIO口
    while(1)
    {
        LED1_ON;
        delay(10);
        LED1_OFF;
        LED2_ON;
        delay(10);
        LED2_OFF;
        LED3_ON;
        delay(30);
        LED3_OFF;
        LED4_ON;
        delay(10);
        LED4_OFF;
    }
}