// 仅修改部分

// INT1.7
interrupt void TINT0_ISR(void) // CPU-Timer 0
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code

  CpuTimer0.InterruptCount++;
  if (CpuTimer0.InterruptCount == 1)
  {
    LED1_ON;
    LED4_OFF;
  }
  if (CpuTimer0.InterruptCount == 2)
  {
    LED1_OFF;
    LED2_ON;
  }
  if (CpuTimer0.InterruptCount == 3)
  {
    LED2_OFF;
    LED3_ON;
  }
  if (CpuTimer0.InterruptCount == 4)
  {
    LED3_OFF;
    LED4_ON;
    CpuTimer0.InterruptCount = 0;
  }

  CpuTimer0Regs.TCR.bit.TIF = 1;   // 清除定时器中断标志位
  PieCtrlRegs.PIEACK.bit.ACK1 = 1; // 响应同组其他中断
  EINT;                            // 开全局中断
}