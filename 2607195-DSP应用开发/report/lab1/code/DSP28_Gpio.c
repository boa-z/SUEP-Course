#include "DSP28_Device.h"
void InitGpio(void)
{
    EALLOW;
    GpioMuxRegs.GPAMUX.bit.PWM1_GPIOA0 = 0;
    GpioMuxRegs.GPAMUX.bit.PWM2_GPIOA1 = 0;
    GpioMuxRegs.GPAMUX.bit.PWM3_GPIOA2 = 0;
    GpioMuxRegs.GPAMUX.bit.PWM4_GPIOA3 = 0;
    GpioMuxRegs.GPAMUX.bit.PWM5_GPIOA4 = 0;
    GpioMuxRegs.GPAMUX.bit.PWM6_GPIOA5 = 0;
    // equel to: GpioMuxRegs.GPAMUX.all = 0;
    GpioMuxRegs.GPADIR.bit.GPIOA0 = 1;
    GpioMuxRegs.GPADIR.bit.GPIOA1 = 1;
    GpioMuxRegs.GPADIR.bit.GPIOA2 = 1;
    GpioMuxRegs.GPADIR.bit.GPIOA3 = 1;
    GpioMuxRegs.GPADIR.bit.GPIOA4 = 1;
    GpioMuxRegs.GPADIR.bit.GPIOA5 = 1;
    // equel to: GpioMuxRegs.GPADIR.all = 0x003F;
    EDIS;
}