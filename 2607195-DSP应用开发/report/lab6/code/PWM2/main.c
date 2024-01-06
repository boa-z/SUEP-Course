#include "DSP281x_Device.h"
#include "DSP281x_GlobalPrototypes.h"

Uint32 intcount; // 中断次数统计变量
int increase;    // 占空比变化方向标志,此为增加标志
int decrease;    // 占空比变化方向标志,此为减少标志
void main(void)
{
    InitSysCtrl();
    DINT;
    IER = 0x0000;       // //初始化系统函数
    IFR = 0x0000;       // 禁止CPU中断
    InitPieCtrl();      // 清除CPU中断标志.
    InitPieVectTable(); // 初始化PIE中断向量表

    InitGpio();                        // 初始化GPIO口
    InitEv();                          // 初始化EV
    PieCtrlRegs.PIEIER2.bit.INTx4 = 1; // 使能PIE中断,T1定时器中断位于INT2.4

    intcount = 0; // T1定时器周期中断计数器
    increase = 0; // 占空比逐渐变小的变化趋势标志位
    decrease = 1; // 占空比逐渐变大的变化趋势标志位
    // EvaRegs.EVAIMRA.bit.T1PINT=1; //使能定时器T1周期中断

    IER |= M_INT2; // 开CPU中断
    EINT;          // 开全局中断
    ERTM;          // 开实时中断
    // EvaRegs.EVAIMRA.bit.T1PINT=1; //使能定时器T1周期中断
    EvaRegs.T1CON.bit.TENABLE = 1; // 使能定时器T1计数操作

    while (1)
    {
    }
}
