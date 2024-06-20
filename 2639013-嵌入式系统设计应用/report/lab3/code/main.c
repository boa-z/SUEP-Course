/**
  ******************************************************************************
  * @file    main.c

  * @brief   液晶显示例程
  ******************************************************************************

  ******************************************************************************
  */

#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./led/bsp_led.h"
#include "./lcd/bsp_nt35510_lcd.h"

static void LCD_Test_Stu(void);
static void Delay(__IO uint32_t nCount);
void Printf_Charater(void);

/**
 * @brief  主函数
 * @param  无
 * @retval 无
 */
int main(void)
{
  LED_GPIO_Config();

  NT35510_Init(); // LCD 初始化

  Debug_USART_Config();

  printf("\r\n ********** 液晶屏英文显示程序*********** \r\n");
  printf("\r\n 本程序不支持中文，显示中文的程序请学习下一章 \r\n");

  // 其中0、3、5、6 模式适合从左至右显示文字，
  // 不推荐使用其它模式显示文字	其它模式显示文字会有镜像效果
  // 其中 6 模式为大部分液晶例程的默认显示方向
  NT35510_GramScan(6);

  while (1)
  {
    LCD_Test_Stu();
  }
}

/* 修改源程序、在 LCD 屏上分别用红色和绿色画 2个大的矩形，中间位置显示学号(2021xxxx)，画奥运五环。*/
void LCD_Test_Stu(void)
{
  // 画矩形，并排排列
  // NT35510_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全黑 */
  LCD_SetTextColor(RED);
  NT35510_DrawRectangle(50, 50, 190, 200, 1);
  LCD_SetTextColor(GREEN);
  NT35510_DrawRectangle(240, 50, 190, 200, 1);

  // 在屏幕中心显示学号
  LCD_SetTextColor(RED);
  LCD_SetFont(&Font16x32);
  NT35510_DispStringLine_EN(LINE(10), "2021xxxx");

  // 画奥运五环，使用不同颜色的空心圆环组成
  LCD_SetTextColor(BLUE);
  NT35510_DrawCircle(150, 600, 60, 0);
  LCD_SetTextColor(YELLOW);
  NT35510_DrawCircle(250, 600, 60, 0);
  LCD_SetTextColor(WHITE);
  NT35510_DrawCircle(350, 600, 60, 0);
  LCD_SetTextColor(GREEN);
  NT35510_DrawCircle(200, 700, 60, 0);
  LCD_SetTextColor(RED);
  NT35510_DrawCircle(300, 700, 60, 0);

  // 在(0,0)点偏离原点20个像素，标出原点 O 同时画出 X、Y 轴并标出原点O、X轴、Y 轴
  LCD_SetTextColor(BLUE);
  NT35510_DrawLine(20, 20, 20, 1000); // Y轴
  NT35510_DrawLine(20, 20, 1000, 20); // X轴
  LCD_SetFont(&Font8x16);
  NT35510_DispStringLine_EN(LINE(0), "O");
  NT35510_DispStringLine_EN(LINE(1), "X");
  NT35510_DispStringLine_EN(LINE(2), "Y");
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
