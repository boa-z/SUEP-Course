#include "My_Main_Declaration.h"

void main(void)
{
    InitSysCtrl(); // 初始化系统函数
    DINT;
    IER = 0x0000;
    IFR = 0x0000;
    InitPieCtrl();                            // 初始化 PIE 控制寄存器
    InitPieVectTable();                       // 初始化 PIE 中断向量表
    InitPeripherals();                        // 初始化 CPU定时器模块
    Init_Gpio();                              // 初始化 GPIO
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;        // 使能PIE 模块中的CPU定时器0的中断
    IER |= M_INT1;                            // 开 CPU中断1
    EINT;                                     // 使能全局中断
    ERTM;                                     // 使能实时中断
    ConfigCpuTimer(&CpuTimer0, 150, 1000000); // 配置CPU定时器0的周期为 1s
    StartCpuTimer0();                         // 启动CPU定时器0
    for (;;)
    {
    }
}