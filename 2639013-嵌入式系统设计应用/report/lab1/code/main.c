/**
  ******************************************************************************
  * @file    main.c

  * @brief   控制多彩流水灯
  ******************************************************************************

  ******************************************************************************
  */
#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./beep/bsp_beep.h"
int a;
void Delay(__IO u32 nCount);

/**
 * @brief  主函数
 * @param  无
 * @retval 无
 */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();
	/* 蜂鸣器 端口初始化 */
	BEEP_GPIO_Config();

	/* 控制LED灯 */

	LED1(ON); // 亮
	Delay(0xFFFFFF);
	LED1(OFF); // 灭

	LED2(ON); // 亮
	Delay(0xFFFFFF);
	LED2(OFF); // 灭

	LED3(ON); // 亮
	Delay(0xFFFFFF);
	LED3(OFF); // 灭

	LED_PURPLE;
	Delay(0xFFFFFF);

	LED_WHITE;
	Delay(0xFFFFFF);

	LED_RGBOFF
	Delay(0xFFFFFF);

	BEEP(ON);
	Delay(0xFFFFFF);
	BEEP(OFF);

	//************way_1***********/
	for (a = 0; a < 3; a++)
	{
		LED_RED;
		Delay(0xFFFFFF);

		LED_YELLOW;
		BEEP(ON);
		Delay(0xFFFFFF);
		BEEP(OFF);

		LED_GREEN;
		Delay(0xFFFFFF);
	}
	LED_RGBOFF;
	// BEEP(ON);
	// Delay(0xFFFFFF);
	// BEEP(OFF);

	//*********way_2**********/

	for (a = 0; a < 3; a++)
	{

		// red:

		LED1_ON;
		LED2_OFF;
		LED3_OFF
		Delay(0xFFFFFF);

		// yellow:

		LED1_ON;
		LED2_ON;
		LED3_OFF
		BEEP(ON);
		Delay(0xFFFFFF);
		BEEP(OFF);

		// green:

		LED1_OFF;
		LED2_ON;
		LED3_OFF
		Delay(0xFFFFFF);
	}
	LED_RGBOFF;
	// BEEP(ON);
	// Delay(0xFFFFFF);
	// BEEP(OFF);
	// // BEEP_OFF;

	//***********way_3*************//

	for (a = 0; a < 3; a++)
	{

		// 红
		LED1(ON);  // 亮
		LED2(OFF); // 灭
		LED3(OFF); // 灭
		Delay(0xFFFFFF);
		LED1(OFF); // 灭
		LED2(OFF); // 灭
		LED3(OFF); // 灭

		// 黄
		LED1(ON);  // 亮
		LED2(ON);  // 亮
		LED3(OFF); // 灭
		BEEP(ON);
		Delay(0xFFFFFF);
		LED1(OFF); // 灭
		LED2(OFF); // 灭
		LED3(OFF); // 灭
		BEEP(OFF);

		// 绿
		LED1(OFF); // 灭
		LED2(ON);  // 亮
		LED3(OFF); // 灭
		Delay(0xFFFFFF);
		LED1(OFF); // 灭
		LED2(OFF); // 灭
		LED3(OFF); // 灭
	}
	LED_RGBOFF;
	// BEEP(ON);
	// Delay(0xFFFFFF);
	// BEEP(OFF);
	// // BEEP_OFF;
}

void Delay(__IO uint32_t nCount) // 简单的延时函数
{
	for (; nCount != 0; nCount--)
		;
}
/*********************************************END OF FILE**********************/
