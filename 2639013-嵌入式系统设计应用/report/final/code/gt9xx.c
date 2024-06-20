/**
  ******************************************************************************
  * @file    gt5xx.c

  * @brief   i2c电容屏驱动函数gt9157芯片
  ******************************************************************************

  ******************************************************************************
  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./touch/gt9xx.h"
#include "./touch/bsp_i2c_touch.h"
#include "./lcd/bsp_nt35510_lcd.h"
#include "./touch/palette.h"

// 邪恶之源
// extern char input_touch;
char input_touch_temp;

// 请给出修改以下代码的建议，如何修改代码使得 input_touch_temp 的值仅在每个区域被触摸后离开屏幕时才会被赋值？


// 4.5寸屏GT5688驱动配置
const uint8_t CTP_CFG_GT5688[] = {
    0x96, 0xE0, 0x01, 0x56, 0x03, 0x05, 0x35, 0x00, 0x01, 0x00,
    0x00, 0x05, 0x50, 0x3C, 0x53, 0x11, 0x00, 0x00, 0x22, 0x22,
    0x14, 0x18, 0x1A, 0x1D, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x53, 0x00, 0x14, 0x00, 0x00, 0x84, 0x00, 0x00,
    0x3C, 0x19, 0x19, 0x64, 0x1E, 0x28, 0x88, 0x29, 0x0A, 0x2D,
    0x2F, 0x29, 0x0C, 0x20, 0x33, 0x60, 0x13, 0x02, 0x24, 0x00,
    0x00, 0x20, 0x3C, 0xC0, 0x14, 0x02, 0x00, 0x00, 0x54, 0xAC,
    0x24, 0x9C, 0x29, 0x8C, 0x2D, 0x80, 0x32, 0x77, 0x37, 0x6E,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x50, 0x3C,
    0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x02, 0x14, 0x14, 0x03,
    0x04, 0x00, 0x21, 0x64, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x32, 0x20, 0x50, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0D, 0x06, 0x0C, 0x05, 0x0B, 0x04, 0x0A, 0x03, 0x09, 0x02,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x05, 0x1E, 0x00, 0x02,
    0x2A, 0x1E, 0x19, 0x14, 0x02, 0x00, 0x03, 0x0A, 0x05, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x86,
    0x22, 0x03, 0x00, 0x00, 0x33, 0x00, 0x0F, 0x00, 0x00, 0x00,
    0x50, 0x3C, 0x50, 0x00, 0x00, 0x00, 0x1A, 0x64, 0x01

};

// GT9147配置参数表
// 第一个字节为版本号(0X60),必须保证新的版本号大于等于GT9147内部
// flash原有版本号,才会更新配置.
const u8 CTP_CFG_GT9147[] =
    {
        0x99, 0xE0, 0x01, 0x20, 0x03, 0x05, 0x34, 0x00, 0x02,
        0x08, 0x1E, 0x08, 0x50, 0x3C, 0x0F, 0x05, 0x00, 0x00,
        0xFF, 0x67, 0x02, 0x02, 0x00, 0x18, 0x1A, 0x1E, 0x14,
        0x88, 0x28, 0x0A, 0x55, 0x57, 0xD3, 0x07, 0x03, 0x00,
        0x00, 0x42, 0x32, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x32, 0x00, 0x00, 0x2A, 0x4B, 0x78, 0x94,
        0xD5, 0x02, 0x07, 0x00, 0x00, 0x04, 0x88, 0x4E, 0x00,
        0x7E, 0x56, 0x00, 0x76, 0x5E, 0x00, 0x6E, 0x68, 0x00,
        0x67, 0x72, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0F, 0x0F, 0x03, 0x06, 0x10, 0x42, 0xF8, 0x0F, 0x14,
        0x00, 0x00, 0x00, 0x00, 0x1A, 0x18, 0x16, 0x14, 0x12,
        0x10, 0x0E, 0x0C, 0x0A, 0x08, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x04, 0x05, 0x06, 0x08, 0x0A, 0x0C, 0x1D, 0x1E, 0x1F,
        0x20, 0x22, 0x24, 0x28, 0x29, 0xFF, 0xFF, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0x37, 0x01
        //	0x99,0XE0,0X01,0X20,0X03,0X05,0X35,0X00,0X02,0X08,
        //	0X1E,0X08,0X50,0X3C,0X0F,0X05,0X00,0X00,0XFF,0X67,
        //	0X50,0X00,0X00,0X18,0X1A,0X1E,0X14,0X89,0X28,0X0A,
        //	0X30,0X2E,0XBB,0X0A,0X03,0X00,0X00,0X02,0X33,0X1D,
        //	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X32,0X00,0X00,
        //	0X2A,0X1C,0X5A,0X94,0XC5,0X02,0X07,0X00,0X00,0X00,
        //	0XB5,0X1F,0X00,0X90,0X28,0X00,0X77,0X32,0X00,0X62,
        //	0X3F,0X00,0X52,0X50,0X00,0X52,0X00,0X00,0X00,0X00,
        //	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        //	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,
        //	0X0F,0X03,0X06,0X10,0X42,0XF8,0X0F,0X14,0X00,0X00,
        //	0X00,0X00,0X1A,0X18,0X16,0X14,0X12,0X10,0X0E,0X0C,
        //	0X0A,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        //	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        //	0X00,0X00,0X29,0X28,0X24,0X22,0X20,0X1F,0X1E,0X1D,
        //	0X0E,0X0C,0X0A,0X08,0X06,0X05,0X04,0X02,0X00,0XFF,
        //	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        //	0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
        //	0XFF,0XFF,0XFF,0XFF,
};

const uint8_t CTP_CFG_GT917S[] = {
    0x84, 0x20, 0x03, 0xE0, 0x01, 0x05, 0x05, 0x00, 0x00, 0x40,
    0x00, 0x0F, 0x78, 0x64, 0x53, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x23, 0x17, 0x19, 0x1D, 0x0F, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x51, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x32, 0x00, 0x00, 0x50, 0x38, 0x28, 0x8A, 0x20, 0x11, 0x37,
    0x39, 0xA2, 0x07, 0x38, 0x6D, 0x28, 0x11, 0x03, 0x24, 0x00,
    0x01, 0x28, 0x50, 0xC0, 0x94, 0x02, 0x00, 0x00, 0x53, 0xB8,
    0x2E, 0xA2, 0x35, 0x8F, 0x3B, 0x80, 0x42, 0x75, 0x49, 0x6B,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x4C, 0x3C,
    0xFF, 0xFF, 0x07, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x73,
    0x50, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1D, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x15, 0x14,
    0x13, 0x12, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x05, 0x00, 0x00, 0x0F,
    0x00, 0x00, 0x00, 0x80, 0x46, 0x08, 0x96, 0x50, 0x32, 0x0A,
    0x0A, 0x64, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x32, 0x03, 0x0C, 0x08, 0x23, 0x00, 0x14, 0x23, 0x00, 0x28,
    0x46, 0x30, 0x3C, 0xD0, 0x07, 0x50, 0x70, 0xB0, 0x01};

TOUCH_IC touchIC = GT917S;

const TOUCH_PARAM_TypeDef touch_param[1] =
    {
        /* GT917S,4.3寸屏 */
        {
            .max_width = 800,
            .max_height = 480,
            .config_reg_addr = 0x8050,
        },
};

static void Delay(__IO uint32_t nCount) // 简单的延时函数
{
  for (; nCount != 0; nCount--)
    ;
}

/**
 * @brief   使用IIC进行数据传输
 * @param
 *		@arg i2c_msg:数据传输结构体
 *		@arg num:数据传输结构体的个数
 * @retval  正常完成的传输结构个数，若不正常，返回0xff
 */
static int I2C_Transfer(struct i2c_msg *msgs, int num)
{
  int im = 0;
  int ret = 0;

  GTP_DEBUG_FUNC();

  for (im = 0; ret == 0 && im != num; im++)
  {
    if ((msgs[im].flags & I2C_M_RD)) // 根据flag判断是读数据还是写数据
    {
      ret = I2C_ReadBytes(msgs[im].addr, msgs[im].buf, msgs[im].len); // IIC读取数据
    }
    else
    {
      ret = I2C_WriteBytes(msgs[im].addr, msgs[im].buf, msgs[im].len); // IIC写入数据
    }
  }

  if (ret)
    return ret;

  return im; // 正常完成的传输结构个数
}

/**
 * @brief   从IIC设备中读取数据
 * @param
 *		@arg client_addr:设备地址
 *		@arg  buf[0~1]: 读取数据寄存器的起始地址
 *		@arg buf[2~len-1]: 存储读出来数据的缓冲buffer
 *		@arg len:    GTP_ADDR_LENGTH + read bytes count（寄存器地址长度+读取的数据字节数）
 * @retval  i2c_msgs传输结构体的个数，2为成功，其它为失败
 */
static int32_t GTP_I2C_Read(uint8_t client_addr, uint8_t *buf, int32_t len)
{
  struct i2c_msg msgs[2];
  int32_t ret = -1;
  int32_t retries = 0;

  GTP_DEBUG_FUNC();
  /*一个读数据的过程可以分为两个传输过程:
   * 1. IIC  写入 要读取的寄存器地址
   * 2. IIC  读取  数据
   * */

  msgs[0].flags = !I2C_M_RD;     // 写入
  msgs[0].addr = client_addr;    // IIC设备地址
  msgs[0].len = GTP_ADDR_LENGTH; // 寄存器地址为2字节(即写入两字节的数据)
  msgs[0].buf = &buf[0];         // buf[0~1]存储的是要读取的寄存器地址

  msgs[1].flags = I2C_M_RD;            // 读取
  msgs[1].addr = client_addr;          // IIC设备地址
  msgs[1].len = len - GTP_ADDR_LENGTH; // 要读取的数据长度
  msgs[1].buf = &buf[GTP_ADDR_LENGTH]; // buf[GTP_ADDR_LENGTH]之后的缓冲区存储读出的数据

  while (retries < 5)
  {
    ret = I2C_Transfer(msgs, 2); // 调用IIC数据传输过程函数，有2个传输过程
    if (ret == 2)
      break;
    retries++;
  }
  if ((retries >= 5))
  {
    GTP_ERROR("I2C Read: 0x%04X, %d bytes failed, errcode: %d! Process reset.", (((uint16_t)(buf[0] << 8)) | buf[1]), len - 2, ret);
  }
  return ret;
}

/**
 * @brief   向IIC设备写入数据
 * @param
 *		@arg client_addr:设备地址
 *		@arg  buf[0~1]: 要写入的数据寄存器的起始地址
 *		@arg buf[2~len-1]: 要写入的数据
 *		@arg len:    GTP_ADDR_LENGTH + write bytes count（寄存器地址长度+写入的数据字节数）
 * @retval  i2c_msgs传输结构体的个数，1为成功，其它为失败
 */
static int32_t GTP_I2C_Write(uint8_t client_addr, uint8_t *buf, int32_t len)
{
  struct i2c_msg msg;
  int32_t ret = -1;
  int32_t retries = 0;

  GTP_DEBUG_FUNC();
  /*一个写数据的过程只需要一个传输过程:
   * 1. IIC连续 写入 数据寄存器地址及数据
   * */
  msg.flags = !I2C_M_RD;  // 写入
  msg.addr = client_addr; // 从设备地址
  msg.len = len;          // 长度直接等于(寄存器地址长度+写入的数据字节数)
  msg.buf = buf;          // 直接连续写入缓冲区中的数据(包括了寄存器地址)

  while (retries < 5)
  {
    ret = I2C_Transfer(&msg, 1); // 调用IIC数据传输过程函数，1个传输过程
    if (ret == 1)
      break;
    retries++;
  }
  if ((retries >= 5))
  {

    GTP_ERROR("I2C Write: 0x%04X, %d bytes failed, errcode: %d! Process reset.", (((uint16_t)(buf[0] << 8)) | buf[1]), len - 2, ret);
  }
  return ret;
}

// 判断触摸屏是否有按在指定区域
char Botton_Determination(uint16_t input_x, uint16_t input_y)
{
  // char input_touch_temp;
  if (input_x < 160 && input_y < 200 && input_x > 0 && input_y > 100)
  {
    input_touch_temp = '1';
    // printf("input: 1\n");
    // LCD_SetTextColor(BLUE);
    // NT35510_DispString_EN(25, 25, "1");
    // Delay(0x05FFFFF);
    // NT35510_Clear(25, 25, 190, 90);
  }
  else if (input_x < 320 && input_y < 200 && input_x > 160 && input_y > 100)
  {
    input_touch_temp = '2';
  }
  else if (input_x < 480 && input_y < 200 && input_x > 320 && input_y > 100)
  {
    input_touch_temp = '3';
  }
  else if (input_x < 640 && input_y < 200 && input_x > 480 && input_y > 100)
  {
    input_touch_temp = '4';
  }
  else if (input_x < 800 && input_y < 200 && input_x > 640 && input_y > 100)
  {
    input_touch_temp = '5';
  }
  else if (input_x < 160 && input_y < 300 && input_x > 0 && input_y > 200)
  {
    input_touch_temp = '6';
  }
  else if (input_x < 320 && input_y < 300 && input_x > 160 && input_y > 200)
  {
    input_touch_temp = '7';
  }
  else if (input_x < 480 && input_y < 300 && input_x > 320 && input_y > 200)
  {
    input_touch_temp = '8';
  }
  else if (input_x < 640 && input_y < 300 && input_x > 480 && input_y > 200)
  {
    input_touch_temp = '9';
  }
  else if (input_x < 800 && input_y < 300 && input_x > 640 && input_y > 200)
  {
    input_touch_temp = '0';
  }
  else if (input_x < 160 && input_y < 400 && input_x > 0 && input_y > 300)
  {
    input_touch_temp = '+';
  }
  else if (input_x < 320 && input_y < 400 && input_x > 160 && input_y > 300)
  {
    input_touch_temp = '-';
  }
  else if (input_x < 480 && input_y < 400 && input_x > 320 && input_y > 300)
  {
    input_touch_temp = '*';
  }
  else if (input_x < 640 && input_y < 400 && input_x > 480 && input_y > 300)
  {
    input_touch_temp = '/';
  }
  else if (input_x < 800 && input_y < 400 && input_x > 640 && input_y > 300)
  {
    input_touch_temp = '=';
  }
  else
  {
    LCD_SetTextColor(BLACK);
    NT35510_DispString_EN(220, 400, "I am white");
    Delay(0x05FFFFF);
    NT35510_Clear(220, 400, 300, 40);
  }
  // input_touch = input_touch_temp;
  return input_touch_temp;
}

/**
 * @brief   触屏处理函数，轮询或者在触摸中断调用
 * @param 无
 * @retval 无
 */
static void Goodix_TS_Work_Func(void)
{
  uint8_t end_cmd[3] = {GTP_READ_COOR_ADDR >> 8, GTP_READ_COOR_ADDR & 0xFF, 0};
  uint8_t point_data[2 + 1 + 8 * GTP_MAX_TOUCH + 1] = {GTP_READ_COOR_ADDR >> 8, GTP_READ_COOR_ADDR & 0xFF};
  uint8_t touch_num = 0;
  uint8_t finger = 0;
  static uint16_t pre_touch = 0;
  static uint8_t pre_id[GTP_MAX_TOUCH] = {0};

  uint8_t client_addr = GTP_ADDRESS;
  uint8_t *coor_data = NULL;
  int32_t input_x = 0;
  int32_t input_y = 0;
  uint8_t id = 0;

  int32_t i = 0;
  int32_t ret = -1;

  GTP_DEBUG_FUNC();

  ret = GTP_I2C_Read(client_addr, point_data, 12); // 10字节寄存器加2字节地址
  if (ret < 0)
  {
    GTP_ERROR("I2C transfer error. errno:%d\n ", ret);

    return;
  }

  finger = point_data[GTP_ADDR_LENGTH]; // 状态寄存器数据

  if (finger == 0x00) // 没有数据，退出
  {
    return;
  }

  if ((finger & 0x80) == 0) // 判断buffer status位
  {
    goto exit_work_func; // 坐标未就绪，数据无效
  }

  touch_num = finger & 0x0f; // 坐标点数
  if (touch_num > GTP_MAX_TOUCH)
  {
    goto exit_work_func; // 大于最大支持点数，错误退出
  }

  if (touch_num > 1) // 不止一个点
  {
    uint8_t buf[8 * GTP_MAX_TOUCH] = {(GTP_READ_COOR_ADDR + 10) >> 8, (GTP_READ_COOR_ADDR + 10) & 0xff};

    ret = GTP_I2C_Read(client_addr, buf, 2 + 8 * (touch_num - 1));
    memcpy(&point_data[12], &buf[2], 8 * (touch_num - 1)); // 复制其余点数的数据到point_data
  }

  if (pre_touch > touch_num) // pre_touch>touch_num,表示有的点释放了
  {
    for (i = 0; i < pre_touch; i++) // 一个点一个点处理
    {
      uint8_t j;
      for (j = 0; j < touch_num; j++)
      {
        coor_data = &point_data[j * 8 + 3];
        id = coor_data[0] & 0x0F; // track id
        if (pre_id[i] == id)
          break;
      }
    }
  }

  if (touch_num)
  {
    for (i = 0; i < touch_num; i++) // 一个点一个点处理
    {
      coor_data = &point_data[i * 8 + 3];

      id = coor_data[0] & 0x0F; // track id
      pre_id[i] = id;

      input_x = coor_data[1] | (coor_data[2] << 8); // x坐标
      input_y = coor_data[3] | (coor_data[4] << 8); // y坐标

      {
#if 0
									/*根据扫描模式更正X/Y起始方向*/
								switch(LCD_SCAN_MODE)
								{
									case 0:case 7:
										input_y  = LCD_Y_LENGTH - input_y;
										break;
									
									case 2:case 3: 
										input_x  = LCD_X_LENGTH - input_x;
										input_y  = LCD_Y_LENGTH - input_y;
										break;
									
									case 1:case 6:
										input_x  = LCD_X_LENGTH - input_x;
										break;	
									
									default:
									break;
								}
#endif
        Botton_Determination(input_x, input_y);
      }
    }
  }

exit_work_func:
{
  ret = GTP_I2C_Write(client_addr, end_cmd, 3);
  if (ret < 0)
  {
    GTP_INFO("I2C write end_cmd error!");
  }
}
}

int32_t GTP_Init_Panel(void)
{
  int32_t ret = -1;
  GTP_DEBUG_FUNC();
  I2C_Touch_Init();
  if (ret < 0)
  {
    GTP_ERROR("I2C communication ERROR!");
    return ret;
  }
  // 获取触摸IC的型号
#if UPDATE_CONFIG
  config = (uint8_t *)malloc(GTP_CONFIG_MAX_LENGTH + GTP_ADDR_LENGTH);
  config[0] = GTP_REG_CONFIG_DATA >> 8;
  config[1] = GTP_REG_CONFIG_DATA & 0xff;
  // 根据IC的型号指向不同的配置
  if (touchIC == GT5688)
  {
    cfg_info = CTP_CFG_GT5688;                    // 指向寄存器配置
    cfg_info_len = CFG_GROUP_LEN(CTP_CFG_GT5688); // 计算配置表的大小
  }
  else if (touchIC == GT917S)
  {
    cfg_info = CTP_CFG_GT917S;                    // 指向寄存器配置
    cfg_info_len = CFG_GROUP_LEN(CTP_CFG_GT917S); // 计算配置表的大小
  }
  else
  {                                               // 默认配置为GT917S
    cfg_info = CTP_CFG_GT917S;                    // 指向寄存器配置
    cfg_info_len = CFG_GROUP_LEN(CTP_CFG_GT917S); // 计算配置表的大小
  }

  memset(&config[GTP_ADDR_LENGTH], 0, GTP_CONFIG_MAX_LENGTH);
  memcpy(&config[GTP_ADDR_LENGTH], cfg_info, cfg_info_len);
  cfg_num = cfg_info_len;
  GTP_DEBUG("cfg_info_len = %d ", cfg_info_len);
  GTP_DEBUG("cfg_num = %d ", cfg_num);
  GTP_DEBUG_ARRAY(config, 6);
  /*根据LCD的扫描方向设置分辨率*/
  config[GTP_ADDR_LENGTH + 1] = LCD_X_LENGTH & 0xFF;
  config[GTP_ADDR_LENGTH + 2] = LCD_X_LENGTH >> 8;
  config[GTP_ADDR_LENGTH + 3] = LCD_Y_LENGTH & 0xFF;
  config[GTP_ADDR_LENGTH + 4] = LCD_Y_LENGTH >> 8;
  /*根据扫描模式设置X2Y交换*/
  switch (LCD_SCAN_MODE)
  {
  case 0:
  case 2:
  case 4:
  case 6:
    config[GTP_ADDR_LENGTH + 6] |= (X2Y_LOC);
    break;

  case 1:
  case 3:
  case 5:
  case 7:
    config[GTP_ADDR_LENGTH + 6] &= ~(X2Y_LOC);
    break;
  }
  // 计算要写入checksum寄存器的值
  check_sum = 0;

  for (i = GTP_ADDR_LENGTH; i < (cfg_num + GTP_ADDR_LENGTH - 3); i += 2)
  {
    check_sum += (config[i] << 8) + config[i + 1];
  }
  check_sum = 0 - check_sum;
  GTP_DEBUG("Config checksum: 0x%04X", check_sum);
  // 更新checksum
  config[(cfg_num + GTP_ADDR_LENGTH - 3)] = (check_sum >> 8) & 0xFF;
  config[(cfg_num + GTP_ADDR_LENGTH - 2)] = check_sum & 0xFF;
  config[(cfg_num + GTP_ADDR_LENGTH - 1)] = 0x01;
  // 写入配置信息
  for (retry = 0; retry < 5; retry++)
  {
    ret = GTP_I2C_Write(GTP_ADDRESS, config, cfg_num + GTP_ADDR_LENGTH + 2);
    if (ret > 0)
    {
      break;
    }
  }
  Delay(0xfffff); // 延迟等待芯片更新
#if 1             // 读出写入的数据，检查是否正常写入
  // 检验读出的数据与写入的是否相同
  {
    uint16_t i;
    uint8_t buf[300];
    buf[0] = config[0];
    buf[1] = config[1]; // 寄存器地址

    GTP_DEBUG_FUNC();

    ret = GTP_I2C_Read(GTP_ADDRESS, buf, sizeof(buf));

    GTP_DEBUG("read ");

    GTP_DEBUG_ARRAY(buf, cfg_num);

    GTP_DEBUG("write ");

    GTP_DEBUG_ARRAY(config, cfg_num);

    // 不对比版本号
    for (i = 1; i < cfg_num + GTP_ADDR_LENGTH - 3; i++)
    {

      if (config[i] != buf[i])
      {
        GTP_ERROR("Config fail ! i = %d ", i);
        free(config);
        return -1;
      }
    }
    if (i == cfg_num + GTP_ADDR_LENGTH - 3)
      GTP_DEBUG("Config success ! i = %d ", i);
  }
#endif
  free(config);
#endif

  /*使能中断，这样才能检测触摸数据*/
  I2C_GTP_IRQEnable();

  // return input_touch;
}

// 获取 input_touch 为触摸的数字，输出为对应的数字
char Get_Input_Touch(void)
{
  printf("\nGet input_touch_temp: %c\n", input_touch_temp);
  return input_touch_temp;
}


// 检测到触摸中断时调用，
void GTP_TouchProcess(void)
{
  GTP_DEBUG_FUNC();
  Goodix_TS_Work_Func();
}
