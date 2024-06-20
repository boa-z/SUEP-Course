/**
  ******************************************************************************
  * @file    main.c

  * @brief   串口使用，串口接收数据指令控制RGB彩色灯。
  ******************************************************************************

  ******************************************************************************
  */

#include "stm32f4xx.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_usart.h"
#include "./beep/bsp_beep.h"
#include <stdio.h>

static void Show_Message(void);

void Delay(__IO u32 nCount);

/**
 * @brief  主函数
 * @param  无
 * @retval 无
 */

int main(void)
{
  char ch;
  int num;

  /* 初始化RGB彩灯 */
  LED_GPIO_Config();

  /* 初始化USART 配置模式为 115200 8-N-1 */
  USARTx_Config();

  /* 打印指令输入提示信息 */
  Show_Message();
  BEEP_GPIO_Config();

  while (1)
  {
    /* 获取字符指令 */
    printf("Enter a digit character: \n");
    ch = getchar();
    printf("接收到字符：%c\n", ch);
    /* 判断收到的字符（int类型）是奇数还是偶数，奇数BEEP响一声，偶数BEEP响两声 */

    num = 0;
    while (ch >= '0' && ch <= '9')
    {
      num = num * 10 + ch - '0';
      ch = getchar();
    }
    printf("The number is: %d\n", num);

    // Check if the number is even or odd
    switch (num % 2)
    {
    case 0:
      printf("%d is even.\n", num);
      BEEP(ON);
      Delay(0x0FFFFF);
      BEEP(OFF);

      break;
    case 1:
      printf("%d is odd.\n", num);
      BEEP(ON);
      Delay(0x0FFFFF);
      BEEP(OFF);
      BEEP(ON);
      Delay(0x0FFFFF);
      BEEP(OFF);
      break;

    default:
      printf("Invalid input.\n");
      break;
    }
  }
}

/**
 * @brief  打印指令输入提示信息
 * @param  无
 * @retval 无
 */
static void Show_Message(void)
{
  printf("\r\n   这是一个通过串口通信指令控制蜂鸣器实验 \n");
  printf("使用  USART1  参数为：%d 8-N-1 \n", USARTx_BAUDRATE);
  printf("请输入数字字符，奇数响一声，偶数响两声 \n");
}
void Delay(__IO uint32_t nCount) // 简单的延时函数
{
  for (; nCount != 0; nCount--)
    ;
}
/*********************************************END OF FILE**********************/
