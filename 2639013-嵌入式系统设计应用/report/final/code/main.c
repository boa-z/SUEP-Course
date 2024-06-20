/**
  ******************************************************************************
  * @file    main.c

  * @brief   电容触摸屏-触摸画板
  ******************************************************************************

  ******************************************************************************
  */

#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./led/bsp_led.h"
#include "./lcd/bsp_nt35510_lcd.h"
#include "./touch/gt9xx.h"
// #include "./touch/palette.h"
#include <stdio.h>
#include <string.h>

static void Calculator_UI(void);
static void Delay(__IO uint32_t nCount);
static void Calculate(void);
void Printf_Charater(void);
uint16_t Key_scan(void);

char input_value;
int key_value = 0;
double num = 0.0;
double result = 0.0;
int flag_num = 0;  // 0: waiting for first number, 1: waiting for second number
int flag_calc = 0; // 0: +, 1: -, 2: *, 3: /
// 添加一个列表用于存储输入的数字和操作符
char input_sequence[100] = "";
char display_buffer[100] = "";

// extern char input_value;
extern volatile int InterruptTouchFlag;

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

    // 其中0、3、5、6 模式适合从左至右显示文字，
    // 不推荐使用其它模式显示文字	其它模式显示文字会有镜像效果
    // 其中 6 模式为大部分液晶例程的默认显示方向
    NT35510_GramScan(3);

    /* 设定好液晶扫描方向后，再初始化触摸屏，触摸屏会根据液晶的扫描方向输出匹配的触摸坐标 */
    /* 每次修改液晶扫描方向后，应重新调用一次GTP_Init_Panel函数更新触摸配置 */
    GTP_Init_Panel();

    printf("\r\n ********** 计算器程序 *********** \r\n");

    // 绘制计算界面
    Calculator_UI();

    // 提示获取输入值
    printf("Enter a digit or an operator (+, -, *, /): ");

    while (1)
    {
        // 如何修改下面的代码，使得触摸中断输入和键盘输入同时生效

        while (InterruptTouchFlag == 1)
        {
            input_value = Get_Input_Touch();
            // 进行计算
            Calculate();
            InterruptTouchFlag = 0;
            printf("一次触摸中断已经完成，标志位被清零，等待下一次中断产生\n");
            // NT35510_ClearLine(LINE(1)); /* 清除单行文字 */
            // NT35510_ClearLine(LINE(2)); /* 清除单行文字 */
        }

        

        // 显示实际数字

        // sprintf(display_buffer, "Input sequence: %c", input_sequence);
        // NT35510_DispStringLine_EN(LINE(1), display_buffer); /* 显示单行文字 */
        // 将 input_sequence 显示到 LCD
        NT35510_DispStringLine_EN(LINE(1), input_sequence); /* 显示单行文字 */

        // 显示计算结果

        sprintf(display_buffer, "Result: %.2lf", result);
        NT35510_DispStringLine_EN(LINE(2), display_buffer); /* 显示单行文字 */
    }
}

void Calculator_UI(void)
{
    LCD_SetFont(&Font16x32);
    LCD_SetColors(RED, WHITE);
    NT35510_Clear(0, 0, LCD_X_LENGTH, LCD_Y_LENGTH); /* 清屏，显示全白 */
                                                     /*3模式之下，第1行*/
    NT35510_DrawRectangle(0, 100, 150, 90, 0);
    NT35510_DrawRectangle(160, 100, 150, 90, 0);
    NT35510_DrawRectangle(320, 100, 150, 90, 0);
    NT35510_DrawRectangle(480, 100, 150, 90, 0);
    NT35510_DrawRectangle(640, 100, 150, 90, 0);

    NT35510_DispString_EN(0, 100, "1");
    NT35510_DispString_EN(160, 100, "2");
    NT35510_DispString_EN(320, 100, "3");
    NT35510_DispString_EN(480, 100, "4");
    NT35510_DispString_EN(640, 100, "5");

    /*3模式之下，第2行*/
    NT35510_DrawRectangle(0, 200, 150, 90, 0);
    NT35510_DrawRectangle(160, 200, 150, 90, 0);
    NT35510_DrawRectangle(320, 200, 150, 90, 0);
    NT35510_DrawRectangle(480, 200, 150, 90, 0);
    NT35510_DrawRectangle(640, 200, 150, 90, 0);

    NT35510_DispString_EN(0, 200, "6");
    NT35510_DispString_EN(160, 200, "7");
    NT35510_DispString_EN(320, 200, "8");
    NT35510_DispString_EN(480, 200, "9");
    NT35510_DispString_EN(640, 200, "0");

    /*3模式之下，第3行*/
    NT35510_DrawRectangle(0, 300, 150, 90, 0);
    NT35510_DrawRectangle(160, 300, 150, 90, 0);
    NT35510_DrawRectangle(320, 300, 150, 90, 0);
    NT35510_DrawRectangle(480, 300, 150, 90, 0);
    NT35510_DrawRectangle(640, 300, 150, 90, 0);

    NT35510_DispString_EN(0, 300, "+");
    NT35510_DispString_EN(160, 300, "-");
    NT35510_DispString_EN(320, 300, "*");
    NT35510_DispString_EN(480, 300, "/");
    NT35510_DispString_EN(640, 300, "=");

    Delay(0x2FFFFFF);
}

void Delay(__IO uint32_t nCount)
{
    for (; nCount != 0; nCount--)
        ;
}

void Calculate()
{

    // 显示当前输入的数字
    printf("Current input_value: %c\n", input_value);

    // 将输入的数字或操作符添加到 input_sequence
    int length = strlen(input_sequence);
    input_sequence[length] = input_value;
    input_sequence[length + 1] = '\0';

    // 清除旧的输入序列在 LCD 上的显示
    NT35510_ClearLine(LINE(1));
    // 显示输入序列
    printf("Input sequence: %s\n", input_sequence); // 显示输入序列

    if (input_value >= '0' && input_value <= '9')
    {
        // input_value is a digit
        double digit = input_value - '0'; // Convert char to double
        num = num * 10 + digit;
        printf("Current number: %.0lf\n", num);
        printf("Current flag_num: %d\n", flag_num);
        printf("Current result: %.2lf\n", result);
    }
    else if (input_value == '+' || input_value == '-' || input_value == '*' || input_value == '/')
    {
        // input_value is an operator
        if (flag_num == 0)
        {
            // First number input_value
            result = num;
            num = 0.0;
            flag_num = 1;
        }
        // Second number input_value
        switch (input_value)
        {
        case '+':
            flag_calc = 0;
            break;
        case '-':
            flag_calc = 1;
            break;
        case '*':
            flag_calc = 2;
            break;
        case '/':
            flag_calc = 3;
            break;
        }
        printf("Current flag_calc: %d\n", flag_calc);
    }
    else if (input_value == '=')
    {
        // 提前清除显示 result 的这一行的文字
        NT35510_ClearLine(LINE(2)); /* 清除单行文字 */
        // Calculate
        switch (flag_calc)
        {
        case 0:
            result += num;
            break;
        case 1:
            result -= num;
            break;
        case 2:
            result *= num;
            break;
        case 3:
            result /= num;
            break;
        }
        printf("Result: %.2lf\n", result);
        num = 0.0;
        flag_num = 0;
        flag_calc = 0;
        input_sequence[0] = '\0'; // 清空输入列表
    }
    else
    {
        printf("\n Invalid input_value\n");
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

/*********************************************END OF FILE**********************/
