#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known state.
//
void InitGpio(void)
{
     EALLOW;
     // 将GPIO中和PWM相关的引脚设置为PWM功能
     GpioMuxRegs.GPAMUX.bit.PWM1_GPIOA0=1;     //设置PWM1引脚
     GpioMuxRegs.GPAMUX.bit.PWM2_GPIOA1=1;     //设置PWM2引脚

     GpioMuxRegs.GPAMUX.bit.PWM3_GPIOA2=1;     //设置PWM3引脚
     GpioMuxRegs.GPAMUX.bit.PWM4_GPIOA3=1;     //设置PWM4引脚

     GpioMuxRegs.GPAMUX.bit.PWM5_GPIOA4=1;     //设置PWM5引脚
     GpioMuxRegs.GPAMUX.bit.PWM6_GPIOA5=1;     //设置PWM6引脚

     GpioMuxRegs.GPDMUX.bit.T3CTRIP_PDPB_GPIOD5 = 0; //设置为ISO3082_1的选通引脚
     GpioMuxRegs.GPDDIR.bit.GPIOD5 = 1;  //设置为输出引脚

     GpioMuxRegs.GPDMUX.bit.T4CTRIP_SOCB_GPIOD6 = 0; //设置为ISO3082_2的选通引脚
     GpioMuxRegs.GPDDIR.bit.GPIOD6 = 1; //设置为输出引脚

     GpioMuxRegs.GPFMUX.bit.SCITXDA_GPIOF4 = 1;  //设置为SCIA的发送引脚
	 GpioMuxRegs.GPFMUX.bit.SCIRXDA_GPIOF5 = 1;  //设置为SCIA的接收引脚

     GpioMuxRegs.GPGMUX.bit.SCITXDB_GPIOG4 = 1;  //设置为SCIB的发送引脚
	 GpioMuxRegs.GPGMUX.bit.SCIRXDB_GPIOG5 = 1;  //设置为SCIB的接收引脚

     GpioMuxRegs.GPFMUX.bit.XF_GPIOF14=0;      //设置为I/O口
     GpioMuxRegs.GPFDIR.bit.GPIOF14=0;         //方向为输入  作为启动的外置按键接口

     GpioMuxRegs.GPEMUX.bit.XINT1_XBIO_GPIOE0=0; //设置为I/0口
	 GpioMuxRegs.GPEDIR.bit.GPIOE0=0;           //方向为输入 作为停止的外置按键接口

	 GpioMuxRegs.GPEMUX.bit.XNMI_XINT13_GPIOE2 = 0; //设置为I/0口
	 GpioMuxRegs.GPEDIR.bit.GPIOE2 = 0;             //方向为输入 作为指令增加的外置按键接口

	 GpioMuxRegs.GPEMUX.bit.XINT2_ADCSOC_GPIOE1 = 0; //设置为I/0口
	 GpioMuxRegs.GPEDIR.bit.GPIOE1 = 0;          //方向为输入 作为指令减少的外置按键接口

	 GpioMuxRegs.GPFMUX.bit.MCLKXA_GPIOF8=0;      //设置为I/O口
     GpioMuxRegs.GPFDIR.bit.GPIOF8=1;             //方向为输出
     // GpioMuxRegS.GPADIR.all=0xFFFF;
     GpioMuxRegs.GPFMUX.bit.MCLKRA_GPIOF9=0;      //设置为I/O口
     GpioMuxRegs.GPFDIR.bit.GPIOF9=1; 
     
     //这边是我自己因为调试四个LED灯设置的，原来的程序是没有下面两个引脚的设置的
     GpioMuxRegs.GPFMUX.bit.MFSXA_GPIOF10=0;      //设置为I/O口
     GpioMuxRegs.GPFDIR.bit.GPIOF10=1;             //方向为输出
     // GpioMuxRegS.GPADIR.all=0xFFFF;
     GpioMuxRegs.GPFMUX.bit.MFSRA_GPIOF11=0;      //设置为I/O口
     GpioMuxRegs.GPFDIR.bit.GPIOF11=1;
     //上面本来是没有的

     GpioMuxRegs.GPBMUX.all = 0x0000;            //GPIOB口设置为输出通用IO口，数码管显示使用
     GpioMuxRegs.GPBDIR.all = 0xffff;

	 GpioMuxRegs.GPAMUX.bit.T2PWM_GPIOA7=0;    //继电器给0导通
     GpioMuxRegs.GPADIR.bit.GPIOA7=1;
     GpioDataRegs.GPADAT.bit.GPIOA7=0;
    
     GpioMuxRegs.GPAMUX.bit.CAP1Q1_GPIOA8=0;   //风扇直接给0；
     GpioMuxRegs.GPADIR.bit.GPIOA8=1;
     GpioDataRegs.GPADAT.bit.GPIOA8=0;
     
	 GpioMuxRegs.GPAMUX.bit.C1TRIP_GPIOA13=0;  //SBY置零，互感器的控制端口
     GpioMuxRegs.GPADIR.bit.GPIOA13=1;
     GpioDataRegs.GPADAT.bit.GPIOA13=0;
     EDIS;
}