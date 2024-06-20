/**
  ******************************************************************************
  * @file    main.c

  * @brief   ���ݴ�����-��������
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
// ���һ���б����ڴ洢��������ֺͲ�����
char input_sequence[100] = "";
char display_buffer[100] = "";

// extern char input_value;
extern volatile int InterruptTouchFlag;

/**
 * @brief  ������
 * @param  ��
 * @retval ��
 */

int main(void)
{
    LED_GPIO_Config();
    NT35510_Init(); // LCD ��ʼ��
    Debug_USART_Config();

    // ����0��3��5��6 ģʽ�ʺϴ���������ʾ���֣�
    // ���Ƽ�ʹ������ģʽ��ʾ����	����ģʽ��ʾ���ֻ��о���Ч��
    // ���� 6 ģʽΪ�󲿷�Һ�����̵�Ĭ����ʾ����
    NT35510_GramScan(3);

    /* �趨��Һ��ɨ�跽����ٳ�ʼ���������������������Һ����ɨ�跽�����ƥ��Ĵ������� */
    /* ÿ���޸�Һ��ɨ�跽���Ӧ���µ���һ��GTP_Init_Panel�������´������� */
    GTP_Init_Panel();

    printf("\r\n ********** ���������� *********** \r\n");

    // ���Ƽ������
    Calculator_UI();

    // ��ʾ��ȡ����ֵ
    printf("Enter a digit or an operator (+, -, *, /): ");

    while (1)
    {
        // ����޸�����Ĵ��룬ʹ�ô����ж�����ͼ�������ͬʱ��Ч

        while (InterruptTouchFlag == 1)
        {
            input_value = Get_Input_Touch();
            // ���м���
            Calculate();
            InterruptTouchFlag = 0;
            printf("һ�δ����ж��Ѿ���ɣ���־λ�����㣬�ȴ���һ���жϲ���\n");
            // NT35510_ClearLine(LINE(1)); /* ����������� */
            // NT35510_ClearLine(LINE(2)); /* ����������� */
        }

        

        // ��ʾʵ������

        // sprintf(display_buffer, "Input sequence: %c", input_sequence);
        // NT35510_DispStringLine_EN(LINE(1), display_buffer); /* ��ʾ�������� */
        // �� input_sequence ��ʾ�� LCD
        NT35510_DispStringLine_EN(LINE(1), input_sequence); /* ��ʾ�������� */

        // ��ʾ������

        sprintf(display_buffer, "Result: %.2lf", result);
        NT35510_DispStringLine_EN(LINE(2), display_buffer); /* ��ʾ�������� */
    }
}

void Calculator_UI(void)
{
    LCD_SetFont(&Font16x32);
    LCD_SetColors(RED, WHITE);
    NT35510_Clear(0, 0, LCD_X_LENGTH, LCD_Y_LENGTH); /* ��������ʾȫ�� */
                                                     /*3ģʽ֮�£���1��*/
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

    /*3ģʽ֮�£���2��*/
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

    /*3ģʽ֮�£���3��*/
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

    // ��ʾ��ǰ���������
    printf("Current input_value: %c\n", input_value);

    // ����������ֻ��������ӵ� input_sequence
    int length = strlen(input_sequence);
    input_sequence[length] = input_value;
    input_sequence[length + 1] = '\0';

    // ����ɵ����������� LCD �ϵ���ʾ
    NT35510_ClearLine(LINE(1));
    // ��ʾ��������
    printf("Input sequence: %s\n", input_sequence); // ��ʾ��������

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
        // ��ǰ�����ʾ result ����һ�е�����
        NT35510_ClearLine(LINE(2)); /* ����������� */
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
        input_sequence[0] = '\0'; // ��������б�
    }
    else
    {
        printf("\n Invalid input_value\n");
    }
}

uint16_t Key_scan(void)
{
    // ��һ����1����������Ϊ0����ʱ��һ��Ϊ1���������һ�б�����
    GPIO_SetBits(L1_PORT, L1_PIN);
    GPIO_ResetBits(L2_PORT, L2_PIN);
    GPIO_ResetBits(L3_PORT, L3_PIN);
    GPIO_ResetBits(L4_PORT, L4_PIN);

    if (R1_PORT->IDR & R1_PIN) // �жϵ�һ���Ƿ񱻰���
    {
        while (R1_PORT->IDR & R1_PIN)
            ; // �жϵ�һ���Ƿ��Ѿ�����
        key_value = '0';
        printf("%c\r\n", key_value);
    }
    if (R2_PORT->IDR & R2_PIN) // �жϵڶ����Ƿ񱻰���
    {
        while (R2_PORT->IDR & R2_PIN)
            ; // �жϵڶ����Ƿ��Ѿ�����
        key_value = '1';
        printf("%c\r\n", key_value);
    }
    if (R3_PORT->IDR & R3_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R3_PORT->IDR & R3_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '2';
        printf("%c\r\n", key_value);
    }
    if (R4_PORT->IDR & R4_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R4_PORT->IDR & R4_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '3';
        printf("%c\r\n", key_value);
    }
    // �ڶ�����1����������Ϊ0����ʱ��һ��Ϊ1���������һ�б�����
    GPIO_SetBits(L2_PORT, L2_PIN);
    GPIO_ResetBits(L1_PORT, L1_PIN);
    GPIO_ResetBits(L3_PORT, L3_PIN);
    GPIO_ResetBits(L4_PORT, L4_PIN);

    if (R1_PORT->IDR & R1_PIN) // �жϵ�һ���Ƿ񱻰���
    {
        while (R1_PORT->IDR & R1_PIN)
            ; // �жϵ�һ���Ƿ��Ѿ�����
        key_value = '4';
        printf("%c\r\n", key_value);
    }
    if (R2_PORT->IDR & R2_PIN) // �жϵڶ����Ƿ񱻰���
    {
        while (R2_PORT->IDR & R2_PIN)
            ; // �жϵڶ����Ƿ��Ѿ�����
        key_value = '5';
        printf("%c\r\n", key_value);
    }
    if (R3_PORT->IDR & R3_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R3_PORT->IDR & R3_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '6';
        printf("%c\r\n", key_value);
    }
    if (R4_PORT->IDR & R4_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R4_PORT->IDR & R4_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '7';
        printf("%c\r\n", key_value);
    }

    // ��������1����������Ϊ0����ʱ��һ��Ϊ1���������һ�б�����
    GPIO_SetBits(L3_PORT, L3_PIN);
    GPIO_ResetBits(L1_PORT, L1_PIN);
    GPIO_ResetBits(L2_PORT, L2_PIN);
    GPIO_ResetBits(L4_PORT, L4_PIN);

    if (R1_PORT->IDR & R1_PIN) // �жϵ�һ���Ƿ񱻰���
    {
        while (R1_PORT->IDR & R1_PIN)
            ; // �жϵ�һ���Ƿ��Ѿ�����
        key_value = '8';
        printf("%c\r\n", key_value);
    }
    if (R2_PORT->IDR & R2_PIN) // �жϵڶ����Ƿ񱻰���
    {
        while (R2_PORT->IDR & R2_PIN)
            ; // �жϵڶ����Ƿ��Ѿ�����
        key_value = '9';
        printf("%c\r\n", key_value);
    }
    if (R3_PORT->IDR & R3_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R3_PORT->IDR & R3_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '+';
        printf("%c\r\n", key_value);
    }
    if (R4_PORT->IDR & R4_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R4_PORT->IDR & R4_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '-';
        printf("%c\r\n", key_value);
    }

    // ��������1����������Ϊ0����ʱ��һ��Ϊ1���������һ�б�����
    GPIO_SetBits(L4_PORT, L4_PIN);
    GPIO_ResetBits(L1_PORT, L1_PIN);
    GPIO_ResetBits(L2_PORT, L2_PIN);
    GPIO_ResetBits(L3_PORT, L3_PIN);

    if (R1_PORT->IDR & R1_PIN) // �жϵ�һ���Ƿ񱻰���
    {
        while (R1_PORT->IDR & R1_PIN)
            ; // �жϵ�һ���Ƿ��Ѿ�����
        key_value = '*';
        printf("%c\r\n", key_value);
    }
    if (R2_PORT->IDR & R2_PIN) // �жϵڶ����Ƿ񱻰���
    {
        while (R2_PORT->IDR & R2_PIN)
            ; // �жϵڶ����Ƿ��Ѿ�����
        key_value = '/';
        printf("%c\r\n", key_value);
    }
    if (R3_PORT->IDR & R3_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R3_PORT->IDR & R3_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '=';
        printf("%c\r\n", key_value);
    }
    if (R4_PORT->IDR & R4_PIN) // �жϵ������Ƿ��Ѿ�����
    {
        while (R4_PORT->IDR & R4_PIN)
            ; // �жϵ������Ƿ��Ѿ�����
        key_value = '(';
        printf("%c\r\n", key_value);
    }

    return key_value;
}

/*********************************************END OF FILE**********************/
