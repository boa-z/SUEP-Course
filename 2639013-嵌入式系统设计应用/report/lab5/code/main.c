/**
  ******************************************************************************
  * @file    main.c

  * @brief   按键扫描+串口输出+LCD液晶显示
	* @键盘C1-C4接PB4——PB7,R1-R4接PB0——PB3
  ******************************************************************************

  ******************************************************************************
  */

#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./led/bsp_led.h"
#include "./lcd/bsp_nt35510_lcd.h"

static void LCD_Test(void);
static void Delay(__IO uint32_t nCount);
void Printf_Charater(void);
uint16_t Key_scan(void);

/**
 * @brief  主函数
 * @param  无
 * @retval 无
 */
int key_value = 0;
int main(void)
{
	LED_GPIO_Config();
	GPIO_Configuration();
	NT35510_Init(); // LCD 初始化

	Debug_USART_Config();

	printf("\r\n ********** 按键扫描+串口输出+LCD液晶显示*********** \r\n");
	printf("\r\n 本程序不支持中文 \r\n");

	// 其中0、3、5、6 模式适合从左至右显示文字，
	// 不推荐使用其它模式显示文字	其它模式显示文字会有镜像效果
	// 其中 6 模式为大部分液晶例程的默认显示方向
	NT35510_GramScan(6);

	while (1)
	{
		LCD_Test(); // LCD
		Key_scan(); // 按键扫描
		// printf("%d\r\n",key_value);
		Delay(0x22FFFF);
	}
}

uint16_t Key_scan(void)
{
	// 第一行置1，其它行置为0；这时哪一列为1，则代表哪一列被按下
	GPIO_SetBits(L1_PORT, L1_PIN);
	GPIO_ResetBits(L2_PORT, L2_PIN);
	GPIO_ResetBits(L3_PORT, L3_PIN);
	GPIO_ResetBits(L4_PORT, L4_PIN);

	if (R1_PORT->IDR & R1_PIN) // 判断第一列是否被按下
	{
		while (R1_PORT->IDR & R1_PIN)
			; // 判断第一列是否已经弹起
		key_value = '0';
		printf("%c\r\n", key_value);
	}
	if (R2_PORT->IDR & R2_PIN) // 判断第二列是否被按下
	{
		while (R2_PORT->IDR & R2_PIN)
			; // 判断第二列是否已经弹起
		key_value = '1';
		printf("%c\r\n", key_value);
	}
	if (R3_PORT->IDR & R3_PIN) // 判断第三列是否已经弹起
	{
		while (R3_PORT->IDR & R3_PIN)
			; // 判断第三列是否已经弹起
		key_value = '2';
		printf("%c\r\n", key_value);
	}
	if (R4_PORT->IDR & R4_PIN) // 判断第四列是否已经弹起
	{
		while (R4_PORT->IDR & R4_PIN)
			; // 判断第四列是否已经弹起
		key_value = '3';
		printf("%c\r\n", key_value);
	}
	// 第二行置1，其它行置为0；这时哪一列为1，则代表哪一列被按下
	GPIO_SetBits(L2_PORT, L2_PIN);
	GPIO_ResetBits(L1_PORT, L1_PIN);
	GPIO_ResetBits(L3_PORT, L3_PIN);
	GPIO_ResetBits(L4_PORT, L4_PIN);

	if (R1_PORT->IDR & R1_PIN) // 判断第一列是否被按下
	{
		while (R1_PORT->IDR & R1_PIN)
			; // 判断第一列是否已经弹起
		key_value = '4';
		printf("%c\r\n", key_value);
	}
	if (R2_PORT->IDR & R2_PIN) // 判断第二列是否被按下
	{
		while (R2_PORT->IDR & R2_PIN)
			; // 判断第二列是否已经弹起
		key_value = '5';
		printf("%c\r\n", key_value);
	}
	if (R3_PORT->IDR & R3_PIN) // 判断第三列是否已经弹起
	{
		while (R3_PORT->IDR & R3_PIN)
			; // 判断第三列是否已经弹起
		key_value = '6';
		printf("%c\r\n", key_value);
	}
	if (R4_PORT->IDR & R4_PIN) // 判断第四列是否已经弹起
	{
		while (R4_PORT->IDR & R4_PIN)
			; // 判断第四列是否已经弹起
		key_value = '7';
		printf("%c\r\n", key_value);
	}

	// 第三行置1，其它行置为0；这时哪一列为1，则代表哪一列被按下
	GPIO_SetBits(L3_PORT, L3_PIN);
	GPIO_ResetBits(L1_PORT, L1_PIN);
	GPIO_ResetBits(L2_PORT, L2_PIN);
	GPIO_ResetBits(L4_PORT, L4_PIN);

	if (R1_PORT->IDR & R1_PIN) // 判断第一列是否被按下
	{
		while (R1_PORT->IDR & R1_PIN)
			; // 判断第一列是否已经弹起
		key_value = '8';
		printf("%c\r\n", key_value);
	}
	if (R2_PORT->IDR & R2_PIN) // 判断第二列是否被按下
	{
		while (R2_PORT->IDR & R2_PIN)
			; // 判断第二列是否已经弹起
		key_value = '9';
		printf("%c\r\n", key_value);
	}
	if (R3_PORT->IDR & R3_PIN) // 判断第三列是否已经弹起
	{
		while (R3_PORT->IDR & R3_PIN)
			; // 判断第三列是否已经弹起
		key_value = '+';
		printf("%c\r\n", key_value);
	}
	if (R4_PORT->IDR & R4_PIN) // 判断第四列是否已经弹起
	{
		while (R4_PORT->IDR & R4_PIN)
			; // 判断第四列是否已经弹起
		key_value = '-';
		printf("%c\r\n", key_value);
	}

	// 第四行置1，其它行置为0；这时哪一列为1，则代表哪一列被按下
	GPIO_SetBits(L4_PORT, L4_PIN);
	GPIO_ResetBits(L1_PORT, L1_PIN);
	GPIO_ResetBits(L2_PORT, L2_PIN);
	GPIO_ResetBits(L3_PORT, L3_PIN);

	if (R1_PORT->IDR & R1_PIN) // 判断第一列是否被按下
	{
		while (R1_PORT->IDR & R1_PIN)
			; // 判断第一列是否已经弹起
		key_value = '*';
		printf("%c\r\n", key_value);
	}
	if (R2_PORT->IDR & R2_PIN) // 判断第二列是否被按下
	{
		while (R2_PORT->IDR & R2_PIN)
			; // 判断第二列是否已经弹起
		key_value = '/';
		printf("%c\r\n", key_value);
	}
	if (R3_PORT->IDR & R3_PIN) // 判断第三列是否已经弹起
	{
		while (R3_PORT->IDR & R3_PIN)
			; // 判断第三列是否已经弹起
		key_value = '=';
		printf("%c\r\n", key_value);
	}
	if (R4_PORT->IDR & R4_PIN) // 判断第四列是否已经弹起
	{
		while (R4_PORT->IDR & R4_PIN)
			; // 判断第四列是否已经弹起
		key_value = '(';
		printf("%c\r\n", key_value);
	}

	return key_value;
}

/*用于测试各种液晶的函数*/
void LCD_Test(void)
{
	/*演示显示变量*/
	char dispBuff[100];

	NT35510_ClearLine(LINE(7)); /* 清除单行文字 */
	sprintf(dispBuff, "Key sequence number:%c", key_value);
	NT35510_DispStringLine_EN(LINE(7), dispBuff); /* 显示单行文字 */
}

/**
 * @brief  简单延时函数
 * @param  nCount ：延时计数值
 * @retval 无
 */
static void Delay(__IO uint32_t nCount)
{
	for (; nCount != 0; nCount--)
		;
}

/*********************************************END OF FILE**********************/
