#ifndef MACRO_DEFINITION_H_
#define MACRO_DEFINITION_H_
#include "DSP281x_Device.h"

#define LED1_ON  GpioDataRegs.GPFCLEAR.bit.GPIOF11=1
#define LED1_OFF GpioDataRegs.GPFSET.bit.GPIOF11=1
#define LED2_ON  GpioDataRegs.GPFCLEAR.bit.GPIOF8=1
#define LED2_OFF GpioDataRegs.GPFSET.bit.GPIOF8=1
#define LED3_ON  GpioDataRegs.GPFCLEAR.bit.GPIOF10=1
#define LED3_OFF GpioDataRegs.GPFSET.bit.GPIOF10=1
#define LED4_ON  GpioDataRegs.GPFCLEAR.bit.GPIOF9=1
#define LED4_OFF GpioDataRegs.GPFSET.bit.GPIOF9=1
#define LEDSD_1_ON  GpioMuxRegs.GPBMUX.all = 0x0000

#define DY1_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB8=1
#define DY2_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB9=1
#define DY3_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB10=1
#define DY4_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB11=1
#define DY5_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB12=1
#define DY6_ON  GpioDataRegs.GPBCLEAR.bit.GPIOB13=1

#define DY1_OFF GpioDataRegs.GPBSET.bit.GPIOB8=1
#define DY2_OFF GpioDataRegs.GPBSET.bit.GPIOB9=1
#define DY3_OFF GpioDataRegs.GPBSET.bit.GPIOB10=1
#define DY4_OFF GpioDataRegs.GPBSET.bit.GPIOB11=1
#define DY5_OFF GpioDataRegs.GPBSET.bit.GPIOB12=1
#define DY6_OFF GpioDataRegs.GPBSET.bit.GPIOB13=1

#define DPX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB0=1 // 小数点亮暗
#define CX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB1=1
#define DX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB2=1
#define EX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB3=1
#define GX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB4=1
#define BX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB5=1
#define AX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB6=1
#define FX_ON GpioDataRegs.GPBCLEAR.bit.GPIOB7=1

#define DPX_OFF  GpioDataRegs.GPBSET.bit.GPIOB0=1
#define CX_OFF  GpioDataRegs.GPBSET.bit.GPIOB1=1
#define DX_OFF  GpioDataRegs.GPBSET.bit.GPIOB2=1
#define EX_OFF  GpioDataRegs.GPBSET.bit.GPIOB3=1
#define GX_OFF  GpioDataRegs.GPBSET.bit.GPIOB4=1
#define BX_OFF  GpioDataRegs.GPBSET.bit.GPIOB5=1
#define AX_OFF  GpioDataRegs.GPBSET.bit.GPIOB6=1
#define FX_OFF  GpioDataRegs.GPBSET.bit.GPIOB7=1

#endif /* MACRO_DEFINITION_H_ */
