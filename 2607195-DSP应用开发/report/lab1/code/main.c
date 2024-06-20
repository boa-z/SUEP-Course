# include "DSP28_Device.h"
# include "DSP28_GlobalPrototypes.h"
void delay_loop(void);
# define LED1 GpioDataRegs.GPADAT.bit.GPIOA0
# define LED2 GpioDataRegs.GPADAT.bit.GPIOA1
# define LED3 GpioDataRegs.GPADAT.bit.GPIOA2
# define LED4 GpioDataRegs.GPADAT.bit.GPIOA3
# define LED5 GpioDataRegs.GPADAT.bit.GPIOA4
# define LED6 GpioDataRegs.GPADAT.bit.GPIOA5
void main(void)
{
    int kk = 0;
    InitSysCtrl();
    DINT;
    IER = 0x0000;
    IFR = 0x0000;
    InitPieCtrl();
    InitPieVectTable();
    InitGpio();
    while(1)
    {
        LED1 = 1;
        LED2 = 0;
        LED3 = 1;
        LED4 = 0;
        LED5 = 1;
        LED6 = 0;
        for(kk = 0; kk < 100; kk++)
        {
            delay_loop();
        }
        LED1 = 0;
        LED2 = 1;
        LED3 = 0;
        LED4 = 1;
        LED5 = 0;
        LED6 = 1;
        for(kk = 0; kk < 100; kk++)
        {
            delay_loop();
        }
    }
}
void delay_loop()
{
    short i;
    for(i = 0; i < 30000; i++){}
}