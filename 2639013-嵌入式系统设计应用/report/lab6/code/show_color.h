#include "stm32f4xx.h"
#include "./lcd/bsp_nt35510_lcd.h"

#define BUTTON_WIDTH 190
#define BUTTON_HEIGHT 150

#define BUTTON_NUM 2

typedef struct
{
    uint16_t start_x;   // 按键的x起始坐标
    uint16_t start_y;   // 按键的y起始坐标
    uint16_t end_x;     // 按键的x结束坐标
    uint16_t end_y;     // 按键的y结束坐标
    uint32_t para;      // 颜色按钮中表示选择的颜色
    uint8_t touch_flag; // 按键按下的标志
    char *text;         // 显示文字的内容
    uint32_t text_color; // 显示文字的颜色

    void (*draw_btn)(void *btn);    // 按键描绘函数
    void (*btn_command)(void *btn); // 按键功能执行函数，例如显示文字

} Touch_Button;

void Show_Color_Init(uint8_t LCD_Mode);
void Touch_Button_Init(void);
void Touch_Button_Down(uint16_t x, uint16_t y);
