#include "DSP28_Device.h"

void InitSysCtrl(void)
{
   Uint16 i;
   EALLOW;

// 对于TMX产品，为了能够使得片内RAM模块M0/M1/L0/L1LH0能够获得最好的性能，控制寄存器的位
// 必须使能，这些位在设备硬件仿真寄存器内。TMX是TI的试验型产品
   DevEmuRegs.M0RAMDFT = 0x0300;
   DevEmuRegs.M1RAMDFT = 0x0300;
   DevEmuRegs.L0RAMDFT = 0x0300;
   DevEmuRegs.L1RAMDFT = 0x0300;
   DevEmuRegs.H0RAMDFT = 0x0300;
   
           
// 禁止看门狗模块
   SysCtrlRegs.WDCR= 0x0068;

// 初始化PLL模块
   SysCtrlRegs.PLLCR = 0xA;  //如果外部晶振为30M，则SYSCLKOUT=30*10/2=150MHz
// 延时，使得PLL模块能够完成初始化操作
   for(i= 0; i< 5000; i++){}
       
// 高速时钟预定标器和低速时钟预定标器，产生高速外设时钟HSPCLK和低速外设时钟LSPCLK
   SysCtrlRegs.HISPCP.all = 0x0001; // HSPCLK=150/2=75MHz
   SysCtrlRegs.LOSPCP.all = 0x0002; // LSPCLK=150/4=37.5MHz

// 对工程中使用到的外设进行时钟使能
// SysCtrlRegs.PCLKCR.bit.EVAENCLK=1;
// SysCtrlRegs.PCLKCR.bit.EVBENCLK=1;
// SysCtrlRegs.PCLKCR.bit.SCIENCLKA=1;
// SysCtrlRegs.PCLKCR.bit.SCIENCLKB=1;
   EDIS;
}