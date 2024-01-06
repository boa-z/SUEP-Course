#include "DSP281x_Device.h"   // DSP281x Headerfile Include File
#include "DSP281x_Examples.h" // DSP281x Examples Include File
#include "My_Main_Declaration.h"

// INT2.4
//extern Uint32 intcount;//中断次数统计变量
//extern int increase; //占空比变化方向标志,此为增加标志
//extern int decrease; //占空比变化方向标志,此为减少标志
void delay_ms(int time_ms)
{
    unsigned long a,b,c;
    for(a=0;a<time_ms;a++)
    {
        for(b=0;b<1000;b++)
        {
            for(c=0;c<15;c++)
            {}}}}

interrupt void T1PINT_ISR(void) //通用定时器T1的周期中断
{

    extern Uint32 intcount;//中断次数统计变量
    extern int increase; //占空比变化方向标志,此为增加标志
    extern int decrease; //占空比变化方向标志,此为减少标志
    int i;
    for(intcount=0;intcount<1001;intcount++)
    {
        delay_ms(1);


     //中断计数器计数

    if(intcount>=1000) //当时间到达1s时
    {
        if((increase==1)&&(decrease==0)) //如果占空比越来越小
        {
            EvaRegs.CMPR1=EvaRegs.CMPR1+938;
            if(EvaRegs.CMPR1>=0x41EB)
            {
                EvaRegs.CMPR1=0x41EB; //占空比到达最小的10%时,改变变化的方向
                increase=0;
                decrease=1;
                //delay_ms(100);
                //0x41EB
            }
        }
        if((increase==0)&&(decrease==1)) //如果占空比越来越大
        {
            EvaRegs.CMPR1=EvaRegs.CMPR1-938;
            if(EvaRegs.CMPR1<=0x0753)
            {
                EvaRegs.CMPR1=0x0753; //占空比到达最大的90%时,改变变化的方向
                increase=1;
                decrease=0;
                //delay_ms(100);
                //
            }
        }
        intcount=0;
//        i=0;
    }

PieCtrlRegs.PIEACK.all=PIEACK_GROUP1; //响应同组其他中断,PIEACK_GROUP1的
//值为0x0001
EvaRegs.EVAIFRA.bit.T1PINT=1; //清除中断标志位
EINT; //开全局中断
}
}

