#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitEv: 
//---------------------------------------------------------------------------
// This function initializes to a known state.
//
void InitEv(void)
{
    //EVA 模块
    EvaRegs.T1CON.bit.TMODE = 2; // 连续增模式
    EvaRegs.T1CON.bit.TPS = 1; // T1CLK = HSPCLK/2 = 37.5 MHz
    EvaRegs.T1CON.bit.TENABLE = 0; // 暂时禁止T1 计数
    EvaRegs.T1CON.bit.TCLKS10 = 0; // 使用内部时钟T1CLK
    EvaRegs.T1CON.bit.TECMPR = 1; // 使能定时器比较操作
    EvaRegs.T2CON.bit.TMODE = 2; // 连续增模式
    EvaRegs.T2CON.bit.TPS = 1; // T2CLK = HSPCLK/2 = 37.5 MHz
    EvaRegs.T2CON.bit.TENABLE = 0; // 暂时禁止T2 计数
    EvaRegs.T2CON.bit.TCLKS10 = 0; // 使用内部时钟T2CLK
    EvaRegs.T2CON.bit.TECMPR = 1; // 使能定时器比较操作
    EvaRegs.GPTCONA.bit.TCMPOE = 1; // 定时器比较输出 T1PWM_TICMPR 和 T2PWM_T2CMPR
                                    // 由各自的定时器比较逻辑驱动
    EvaRegs.GPTCONA.bit.T1PIN = 1; // 低电平有效
    EvaRegs.GPTCONA.bit.T2PIN = 2; // 高电平有效
    EvaRegs.T1PR = 0x927B; // 1 kHz 的 PWM，周期为 1 ms
    EvaRegs.T1CMPR = 0x3A98; // 占空比为40号，低电平有效
    EvaRegs.T1CNT = 0;
    EvaRegs.T2PR = 0x927B; // 1 kHz 的 PWM，周期为 1 ms
    EvaRegs.T2CMPR = 0x57E4; // 占空比为40%，高电平有效
    EvaRegs.T2CNT = 0;
    EvaRegs.COMCONA.bit.CENABLE = 1; // 使能比较单元的比较操作
    EvaRegs.COMCONA.bit.FCOMPOE = 1; // 全比较输出，PW1~6引脚均由相应的比较逻辑驱动
    EvaRegs.COMCONA.bit.CLD = 2; 
    // 死区时间为：4.27 us
    EvaRegs.DBTCONA.bit.DBT = 10; // 死区定时器周期，m=10
    EvaRegs.DBTCONA.bit.EDBT1 = 1; // 死区定时器1使能位
    EvaRegs.DBTCONA.bit.EDBT2 = 1; // 死区定时器2使能位
    EvaRegs.DBTCONA.bit.EDBT3 = 1; // 死区定时器3使能位
    EvaRegs.DBTCONA.bit.DBTPS = 4; // 死区定时器预定标因子 Ta =37.5 MHz/16=2.34 MHz
    EvaRegs.ACTRA.all = 0x0999; // 设定引脚PWM1~6 的动作属性
    EvaRegs.CMPR1 = 0x3A98; // PWM1 占空比为40%
    EvaRegs.CMPR2 = 0x3A98; // PWM3 占空比为40名
    EvaRegs.CMPR3 = 0x3A98; // PWM5占空比为40号
    //EVB 模块
    EvbRegs.T3CON.bit.TMODE = 1; // 连续增/减模式
    EvbRegs.T3CON.bit.TPS = 1; // T3CLK = HSPCLK/2 = 37.5 MHz
    EvbRegs.T3CON.bit.TENABLE = 0; // 暂时禁止T3 计数
    EvbRegs.T3CON.bit.TCLKS10 = 0; // 使用内部时钟 T3CLK
    EvbRegs.T3CON.bit.TECMPR = 1; // 使能定时器比较操作
    EvbRegs.T4CON.bit.TMODE = 1; // 连续增/减模式
    EvbRegs.T4CON.bit.TPS = 1; // T4CLK = HSPCLK/2 = 37.5 MHz
    EvbRegs.T4CON.bit.TENABLE = 0; // 暂时禁止T4 计数
    EvbRegs.T4CON.bit.TCLKS10 = 0; // 使用内部时钟 T4CLK
    EvbRegs.T4CON.bit.TECMPR = 1; // 使能定时器比较操作
    EvbRegs.GPTCONB.bit.TCMPOE = 1; // 定时器比较输出 T3PWM_TBOMPR 和 T4PWM_T4CMPR
                                     // 由各自的定时器比较逻辑驱动
    EvbRegs.GPTCONB.bit.T3PIN = 1; // 低电平有效
    EvbRegs.GPTCONB.bit.T4PIN = 2; // 高电平有效
    EvbRegs.T3PR = 0x493E; // 1 kHz 的PWM，周期为 1 ms
    EvbRegs.T3CMPR = 0x1D4C; // 占空比40%，低电平有效
    EvbRegs.T3CNT = 0;
    EvbRegs.T4PR = 0x493E; // 1 kHz 的PWM，周期为1ms
    EvbRegs.T4CMPR = 0x2BF2; // 占空比为40%，高电平有效
    EvbRegs.T4CNT = 0;
    EvbRegs.COMCONB.bit.CENABLE = 1; // 使能比较单元的比较操作
    EvbRegs.COMCONB.bit.FCOMPOE = 1; // 全比较输出，PW7~12引脚均由相应的比较逻辑驱动
    EvbRegs.COMCONB.bit.CLD = 2;
    // 死区时间为：4.27ps
    EvbRegs.DBTCONB.bit.DBT = 10; // 死区定时器周期，m=10
    EvbRegs.DBTCONB.bit.EDBT1 = 1; // 死区定时器1使能位
    EvbRegs.DBTCONB.bit.EDBT2 = 1; // 死区定时器2使能位
    EvbRegs.DBTCONB.bit.EDBT3 = 1; // 死区定时器3使能位
    EvbRegs.DBTCONB.bit.DBTPS = 4; // 死区定时器预定标因子 Ta=37.5 Miz/16=2.34 MHz
    EvbRegs.ACTRB.all = 0x0999; // 设定引脚 PWM7~12的动作属性
    EvbRegs.CMPR4 = 0x1D4C; // PWM7 占空比为40%
    EvbRegs.CMPR5 = 0x1D4C; // PWM9 占空比力40%
    EvbRegs.CMPR6 = 0x1D4C; // PWM11 占空比为40%
}	
	
//===========================================================================
// No more.
//===========================================================================
