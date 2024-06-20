//###########################################################################
//
// FILE:	DSP281x_Ev.c
//
// TITLE:	DSP281x Event Manager Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | No change since previous version (v.58 Alpha)
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitEv: 
//---------------------------------------------------------------------------
// This function initializes to a known state.
//
void InitEv(void)
{
    //EVA模块
    EvaRegs.T1CON.bit.TMODE=1; //连续增/减模式
    EvaRegs.T1CON.bit.TPS=1; //T1CLK=HSPCLK/2=37.5MHz
    EvaRegs.T1CON.bit.TENABLE=0; //暂时禁止T1计数
    EvaRegs.T1CON.bit.TCLKS10=0; //使用内部时钟T1CLK
    EvaRegs.T1CON.bit.TECMPR=1; //使能定时器比较操作
    EvaRegs.T1PR=0x493E; //1kHz的PWM,周期为1ms
    EvaRegs.T1CNT=0;
    EvaRegs.COMCONA.bit.CENABLE=1; //使能比较单元的比较操作
    EvaRegs.COMCONA.bit.FCOMPOE=1; //全比较输出,PWM1~6引脚均由相应的比较逻辑驱动
    EvaRegs.COMCONA.bit.CLD=2;
    //死区时间为:4.27μs
    EvaRegs.DBTCONA.bit.DBT=10; //死区定时器周期,m=10
    EvaRegs.DBTCONA.bit.EDBT1=1; //死区定时器1使能位
    EvaRegs.DBTCONA.bit.DBTPS=4, //死区定时器预定标因子 Tdb=37.5MHz/16=2.34MHz
    EvaRegs.ACTRA.all=0x0666; //设定引脚PWM1~6的动作属性
    EvaRegs.CMPR1=0x41EB; //PWM1占空比初始化为10%
    EvaRegs.EVAIMRA.bit.T1PINT=1; //使能定时器T1周期中断
    EvaRegs.EVAIFRA.bit.T1PINT=1; //清除T1周期中断的标志位
    }

	
//===========================================================================
// No more.
//===========================================================================
