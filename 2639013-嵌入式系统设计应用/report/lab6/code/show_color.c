#include "./touch/show_color.h"
#include "./touch/gt9xx.h"
#include "./lcd/bsp_nt35510_lcd.h"

/*按钮结构体数组*/
Touch_Button button[BUTTON_NUM];

static void Show_Color_Button(void *btn);
static void Draw_Color_Button(void *btn);

static void Delay(__IO uint32_t nCount) // 简单的延时函数
{
    for (; nCount != 0; nCount--)
        ;
}

// Show_Color 初始化
void Show_Color_Init(uint8_t LCD_Mode)
{
    uint8_t i;

    NT35510_GramScan(LCD_Mode);
    Touch_Button_Init();

    /* 整屏清为白色 */
    LCD_SetBackColor(WHITE);
    NT35510_Clear(0, 0, LCD_X_LENGTH, LCD_Y_LENGTH);

    /* 初始化按钮 */
    Touch_Button_Init();

    /* 画按钮 */
    for (i = 0; i < BUTTON_NUM; i++)
    {
        button[i].draw_btn(&button[i]);
    }
}

// Touch_Button_Init 初始化按钮参数

void Touch_Button_Init(void)
{
    button[0].start_x = 200;
    button[0].start_y = 50;
    button[0].end_x = 600;
    button[0].end_y = 150;
    button[0].touch_flag = 0;
    button[0].draw_btn = Draw_Color_Button;
    button[0].btn_command = Show_Color_Button;
    button[0].text = "I am red";
    button[0].text_color = RED;

    button[1].start_x = 200;
    button[1].start_y = 200;
    button[1].end_x = 600;
    button[1].end_y = 300;
    button[1].touch_flag = 0;
    button[1].draw_btn = Draw_Color_Button;
    button[1].btn_command = Show_Color_Button;
    button[1].text = "I am blue";
    button[1].text_color = BLUE;
}

/**
 * @brief  Touch_Button_Down 按键被按下时调用的函数，由触摸屏调用
 * @param  x 触摸位置的x坐标
 * @param  y 触摸位置的y坐标
 * @retval 无
 */
void Touch_Button_Down(uint16_t x, uint16_t y)
{
    uint8_t i;

    for (i = 0; i < BUTTON_NUM; i++)
    {
        /* 触摸到了按钮 */
        if ((x >= button[i].start_x) && (x <= button[i].end_x) && (y >= button[i].start_y) && (y <= button[i].end_y))
        {
            if (button[i].touch_flag == 0) /*原本的状态为没有按下，则更新状态*/
            {
                button[i].touch_flag = 1;          /* 记录按下标志 */
                button[i].btn_command(&button[i]); /*显示文字*/
                button[i].draw_btn(&button[i]);    /*重绘按钮*/
            }
        }
        else if (button[i].touch_flag == 1)
        {
            button[i].touch_flag = 0;          /* 清除按下标志 */
            button[i].btn_command(&button[i]); /*显示文字*/
            button[i].draw_btn(&button[i]);    /*重绘按钮*/
        }
    }
}

/**
 * @brief  Print_Color 显示颜色,由按钮调用,在按钮上显示颜色对应的文字
    当触摸到红色框(按钮)时显示: I am red;
    当触摸到蓝色框(按钮)时显示: I am blue;
    当触摸其他位置时显示: I am white;
 */

static void Show_Color_Button(void *btn)
{
    Touch_Button *button = (Touch_Button *)btn;
    LCD_SetFont(&Font16x32);
    LCD_SetBackColor(BLACK);

    if (button->touch_flag == 1)
    {
        LCD_SetTextColor(button->text_color);
        NT35510_DispString_EN(button->start_x, button->start_y, button->text);
        NT35510_DispStringLine_EN(LINE(10), button->text);
        Delay(0x05FFFFF);
        NT35510_Clear(button->start_x, button->start_y, button->end_x - button->start_x, button->end_y - button->start_y);
    }
    else
    {
        // 文字提醒，颜色选择黑色，显示在白色背景上，位置在屏幕底部
        LCD_SetTextColor(WHITE);
        NT35510_DispString_EN(220, 400, "I am white");
        Delay(0x05FFFFF);
        NT35510_Clear(220, 400, 300, 40);
    }
}

/**
 * @brief  Draw_Color_Button 颜色按钮的描绘函数
 * @param  btn Touch_Button 类型的按键参数
 * @retval 无
 */
static void Draw_Color_Button(void *btn)
{
    Touch_Button *button = (Touch_Button *)btn;

    /*按钮边框*/
    LCD_SetColors(button->text_color, YELLOW);
    NT35510_DrawRectangle(button->start_x,
                          button->start_y,
                          button->end_x - button->start_x,
                          button->end_y - button->start_y, 0);
}
