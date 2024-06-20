#include "DSP281x_Device.h"   // DSP281x Headerfile Include File
#include "DSP281x_Examples.h" // DSP281x Examples Include File

// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped to a load and
// run address using the linker cmd file.

#pragma CODE_SECTION(InitFlash, "ramfuncs");

//---------------------------------------------------------------------------
// InitSysCtrl:
//---------------------------------------------------------------------------
// This function initializes the System Control registers to a known state.
// - Disables the watchdog
// - Set the PLLCR for proper SYSCLKOUT frequency
// - Set the pre-scaler for the high and low frequency peripheral clocks
// - Enable the clocks to the peripherals

void InitSysCtrl(void)
{
   Uint16 i;
   EALLOW;
   SysCtrlRegs.WDCR = 0x0068;
   // Disable the watchdog
   DisableDog();

   // Initialize the PLLCR to 0xA
   InitPll(0xA);

   // Initialize the peripheral clocks
   InitPeripheralClocks();

   SysCtrlRegs.PLLCR.all = 0xA;
   for (i = 0; i < 5000; i++)
   {
   }
   SysCtrlRegs.HISPCP.all = 0x0001;
   SysCtrlRegs.LOSPCP.all = 0x0002;
   SysCtrlRegs.PCLKCR.bit.EVAENCLK = 1;
   SysCtrlRegs.PCLKCR.bit.EVBENCLK = 1;
   EDIS;
}

//---------------------------------------------------------------------------
// 以下省略