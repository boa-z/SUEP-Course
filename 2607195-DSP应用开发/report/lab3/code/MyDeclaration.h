#include "My_Declaration.h"

//=================================================================
//初始化Gpio口
//=================================================================
void Init_Gpio(void)
{
    EALLOW;
    GpioMuxRegs.GPFMUX.bit.MFSRA_GPIOF11=0; //设置为通用I/O口
    GpioMuxRegs.GPFDIR.bit.GPIOF11=1;       //IO口方向为输出
    GpioMuxRegs.GPFMUX.bit.MCLKXA_GPIOF8=0; //设置为通用I/O口
    GpioMuxRegs.GPFDIR.bit.GPIOF8=1;        //IO口方向为输出
    GpioMuxRegs.GPFMUX.bit.MFSXA_GPIOF10=0; //设置为通用I/O口
    GpioMuxRegs.GPFDIR.bit.GPIOF10=1;       //IO口方向为输出
    GpioMuxRegs.GPFMUX.bit.MCLKRA_GPIOF9=0; //设置为通用I/O口
    GpioMuxRegs.GPFDIR.bit.GPIOF9=1;        //IO口方向为输出

    EDIS;
}