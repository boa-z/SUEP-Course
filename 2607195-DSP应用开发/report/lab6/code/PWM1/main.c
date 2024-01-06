#include "DSP281x_Device.h"
#include "DSP281x_GlobalPrototypes.h"

void main(void)
{
    InitSysCtrl();
    DINT;
    IER = 0x0000; // Disable CPU interrupts
    IFR = 0x0000; // Clear all CPU interrupt flags
    InitPieCtrl(); // Initialize the PIE control registers to their default state.
    InitPieVectTable(); // Initialize the PIE vector table with pointers to the shell Interrupt
                        // Service Routines (ISR).
    InitGpio(); // Initialize the shared GPIO pins to a known state.
    InitEv(); // Initialize the Event Manager.
    EvaRegs.T1CON.bit.TENABLE = 1; // 使能T1 计数
    EvaRegs.T2CON.bit.TENABLE = 1; // 使能T2 计数
    EvbRegs.T3CON.bit.TENABLE = 1; // 使能T3 计数
    EvbRegs.T4CON.bit.TENABLE = 1; // 使能T4 计数
    while (1)
    {
    } 
}
