;***************************************************************************
; 程序功能说明
;***************************************************************************
AUXR EQU 08EH	;特殊功能寄存器

P0M1 EQU 093H	; P0M1.n,P0M0.n     =00--->Standard,    01--->push-pull
P0M0 EQU 094H	;                   =10--->pure input,  11--->open drain
P1M1 EQU 091H	; P1M1.n,P1M0.n     =00--->Standard,    01--->push-pull
P1M0 EQU 092H	;                   =10--->pure input,  11--->open drain
P2M1 EQU 095H	; P2M1.n,P2M0.n     =00--->Standard,    01--->push-pull
P2M0 EQU 096H	;                   =10--->pure input,  11--->open drain
P3M1 EQU 0B1H	; P3M1.n,P3M0.n     =00--->Standard,    01--->push-pull
P3M0 EQU 0B2H	;                   =10--->pure input,  11--->open drain
P4M1 EQU 0B3H	; P4M1.n,P4M0.n     =00--->Standard,    01--->push-pull
P4M0 EQU 0B4H	;                   =10--->pure input,  11--->open drain
P5M1 EQU 0C9H	; P5M1.n,P5M0.n     =00--->Standard,    01--->push-pull
P5M0 EQU 0CAH	;                   =10--->pure input,  11--->open drain
P6M1 EQU 0CBH	; P6M1.n,P6M0.n     =00--->Standard,    01--->push-pull
P6M0 EQU 0CCH	;                   =10--->pure input,  11--->open drain
P7M1 EQU 0E1H	; P7M1.n,P6M0.n     =00--->Standard,    01--->push-pull
P7M0 EQU 0E2H	;                   =10--->pure input,  11--->open drain

;IO口定义
P4 EQU 0C0H
P5 EQU 0C8H
P6 EQU 0E8H
P7 EQU 0F8H



;===========================================================================
; IO口定义
;===========================================================================
;;LCD1602的数据口选择P0口
;;LCD1602的3个控制线的IO口定义
;LCD1602_DAT EQU P0
;LCD1602_E   BIT P2.7
;LCD1602_RW  BIT P2.5
;LCD1602_RS  BIT P2.6

;;DHT11传感器IO口定义
;INT_DHT11 BIT P2.0

;LCD1602的数据口选择P0口
;LCD1602的3个控制线的IO口定义
LCD1602_DAT EQU P7
LCD1602_E   BIT P6.5
LCD1602_RW  BIT P6.6
LCD1602_RS  BIT P6.7

;DHT11传感器IO口定义
INT_DHT11 BIT P4.3



;===========================================================================
; 变量定义
;===========================================================================
;DHT11变量定义
TEMP_HL  	EQU 60H	;温度的低位存放单元
TEMP_HH		EQU 61H	;温度的高位存放单元
TEMP_LL  	EQU 62H	;温度的低位存放单元
TEMP_LH		EQU 63H	;温度的高位存放单元

DUTY_HL 	EQU 64H	;湿度的低位存放单元
DUTY_HM		EQU 65H	;湿度的高位存放单元
DUTY_HH		EQU 66H	;湿度的高位存放单元
DUTY_LL 	EQU 67H	;湿度的低位存放单元
DUTY_LH		EQU 68H	;湿度的高位存放单元

DHT_CHACK	EQU 69H	;校验位    存放单元
JDE_SHOW	EQU 6AH	;显示切换判断变量定义
	


;*******************************************************************
;**************** 主函数 *******************************************
;*******************************************************************
ORG	000H
LJMP MAIN	;主函数
ORG	030H

;===================================================================
MAIN:
	;上电，IO口初始化
	MOV A,#00H
    MOV P0M1,A	;准双向IO口
    MOV P0M0,A
    MOV P1M1,A 	;准双向IO口
    MOV P1M0,A
    MOV P2M1,A	;准双向IO口
    MOV P2M0,A
    MOV P3M1,A	;准双向IO口
    MOV P3M0,A
    MOV P4M1,A	;准双向IO口
    MOV P4M0,A
    MOV P5M1,A	;准双向IO口
    MOV P5M0,A
    MOV P6M1,A	;准双向IO口
    MOV P6M0,A
    MOV P7M1,A	;准双向IO口
    MOV P7M0,A
	CLR P1.0	;按键公共端置0
	
	;LCD1602初始化
	LCALL INIT_1602		;调用初始化子函数
	LCALL DELAY_50MS	;延时等待10MS，让初始化完成
	
	;********************************************************
	;LOOP循环
	LOOP0:
		MOV A,JDE_SHOW
		CJNE A,#0,LOOP1		;2位精度
		LCALL LCD1602_SHOW0	;LCD1602显示数据
	LOOP1:
		MOV A,JDE_SHOW
		CJNE A,#1,LOOP2		;1位精度
		LCALL LCD1602_SHOW1	;LCD1602显示数据
	LOOP2:
		MOV A,JDE_SHOW
		CJNE A,#2,LOOP3		;0位精度
		LCALL LCD1602_SHOW2	;LCD1602显示数据
	
	;********************************************************
	;按键检测
	LOOP3:
		LCALL JDE_P13	;2位小数显示精度
		LCALL JDE_P14	;1位小数显示精度
		LCALL JDE_P15	;0位小数显示精度
	
	;********************************************************
	;读取温湿度数据
	LOOP4:
		CLR EA				;关闭总中断
		
		;起始信号
		SETB  INT_DHT11		;拉高
		LCALL DHT_DEL_1MS	;主机拉低总线1ms
		CLR   INT_DHT11		;拉低
		LCALL DHT_DEL_20MS	;主机拉低总线至少18ms
		SETB  INT_DHT11		;拉高
		LCALL DHT_DEL_40US	;主机拉高总线20~40us
		
		;判断启始信号是否OK？
		JB INT_DHT11,DHT_LAE0	;如果为高电平，则退出
		JNB INT_DHT11,$			;等待数据线被拉高
		JB  INT_DHT11,$			;等待数据线被拉低
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 72H,A				;保存温度数据【整数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 73H,A				;保存温度数据【小数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 70H,A				;保存湿度数据【整数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 71H,A				;保存湿度数据【小数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 74H,A				;保存校验位
		
		
		;【计算温度值】
		MOV A,70H
		MOV B,#10
		DIV AB
		MOV TEMP_HH,A	;湿度的十位
		MOV TEMP_HL,B	;湿度的个位
		
		MOV A,71H
		MOV B,#10
		DIV AB
		MOV TEMP_LH,A	;湿度的十位
		MOV TEMP_LL,B	;湿度的个位
		
		;【计算湿度值】
		MOV A,72H
		MOV B,#100		;除以100
		DIV AB
		MOV DUTY_HH,A	;温度的十位
		MOV A,B
		MOV B,#10		;除以10
		DIV AB
		MOV DUTY_HM,A	;温度的十位
		MOV DUTY_HL,B	;温度的个位
		
		MOV A,73H
		MOV B,#10
		DIV AB
		MOV DUTY_LH,A		;温度的十位
		MOV DUTY_LL,B		;温度的个位
		
		;数据线未被拉低【退出】
		DHT_LAE0:
			CLR EA				;关闭总中断
			LCALL DELAY_50MS	;等待50MS
			LCALL DELAY_50MS	;等待50MS
	
	
	;********************************************************
	;读取温湿度数据
	LOOP5:
		CLR EA				;关闭总中断
		
		;起始信号
		SETB  INT_DHT11		;拉高
		LCALL DHT_DEL_1MS	;主机拉低总线1ms
		CLR   INT_DHT11		;拉低
		LCALL DHT_DEL_20MS	;主机拉低总线至少18ms
		SETB  INT_DHT11		;拉高
		LCALL DHT_DEL_40US	;主机拉高总线20~40us
		
		;判断启始信号是否OK？
		JB INT_DHT11,DHT_LAE1	;如果为高电平，则退出
		JNB INT_DHT11,$			;等待数据线被拉高
		JB  INT_DHT11,$			;等待数据线被拉低
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 72H,A				;保存温度数据【整数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 73H,A				;保存温度数据【小数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 70H,A				;保存湿度数据【整数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 71H,A				;保存湿度数据【小数】
		
		LCALL READ_BYTE_DHT11	;读取数据
		MOV 74H,A				;保存校验位
		
		
		;【计算温度值】
		MOV A,70H
		MOV B,#10
		DIV AB
		MOV TEMP_HH,A	;湿度的十位
		MOV TEMP_HL,B	;湿度的个位
		
		MOV A,71H
		MOV B,#10
		DIV AB
		MOV TEMP_LH,A	;湿度的十位
		MOV TEMP_LL,B	;湿度的个位
		
		;【计算湿度值】
		MOV A,72H
		MOV B,#100		;除以100
		DIV AB
		MOV DUTY_HH,A	;温度的十位
		MOV A,B
		MOV B,#10		;除以10
		DIV AB
		MOV DUTY_HM,A	;温度的十位
		MOV DUTY_HL,B	;温度的个位
		
		MOV A,73H
		MOV B,#10
		DIV AB
		MOV DUTY_LH,A		;温度的十位
		MOV DUTY_LL,B		;温度的个位
		
		;数据线未被拉低【退出】
		DHT_LAE1:
			CLR EA				;关闭总中断
			LCALL DELAY_50MS	;等待50MS
			LCALL DELAY_50MS	;等待50MS
			LJMP LOOP0



;*******************************************************************
;**************** LCD1602子函数定义 ********************************
;*******************************************************************
;===================================================================
;LCD1602初始化
INIT_1602:			
	MOV A, #01H
	LCALL WR_CMD 			;清屏
	LCALL LCD1602_DELAY1
	
	MOV A, #38H
	LCALL WR_CMD 			;8位数据，16X2，5X7点阵
	LCALL LCD1602_DELAY1
	
	MOV A, #0CH
	LCALL WR_CMD 			;开显示，关光标，不闪烁
	LCALL LCD1602_DELAY1
	
	MOV A, #06H
	LCALL WR_CMD 			;读写字符时地址+1，整屏不移动
	LCALL LCD1602_DELAY1
	RET

;===================================================================
;LCD1602显示子函数
LCD1602_SHOW0:
	;LCD1602的第1行显示：TEMP=00.00℃
	MOV A,#080H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#081H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"E"
	LCALL WR_DAT
	
	MOV A,#082H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"M"
	LCALL WR_DAT
	
	MOV A,#083H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"P"
	LCALL WR_DAT
	
	MOV A,#084H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#085H		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HH
	LCALL WR_DAT
	
	MOV A,#086H		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HL
	LCALL WR_DAT
	
	MOV A,#087H		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"."
	LCALL WR_DAT
	
	MOV A,#088H		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_LH
	LCALL WR_DAT
	
	MOV A,#089H		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_LL
	LCALL WR_DAT
	
	MOV A,#08AH		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"'"
	LCALL WR_DAT
	
	MOV A,#08BH		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"C"
	LCALL WR_DAT
	
	MOV A,#08CH		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08DH		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08EH		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08FH		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	;LCD1602的第2行显示：DUTY=000.00%
	MOV A,#0C0H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"D"
	LCALL WR_DAT
		
	MOV A,#0C1H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"U"
	LCALL WR_DAT
	
	MOV A,#0C2H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#0C3H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"Y"
	LCALL WR_DAT
	
	MOV A,#0C4H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#0C5H		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HH
	LCALL WR_DAT
	
	MOV A,#0C6H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HM
	LCALL WR_DAT
	
	MOV A,#0C7H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HL
	LCALL WR_DAT
	
	MOV A,#0C8H		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"."
	LCALL WR_DAT
	
	MOV A,#0C9H		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_LH
	LCALL WR_DAT
	
	MOV A,#0CAH		;LCD1602第2行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_LL
	LCALL WR_DAT
	
	MOV A,#0CBH		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"%"
	LCALL WR_DAT
	
	MOV A,#0CCH		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CDH		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CEH		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CFH		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	RET

;===================================================================
;LCD1602显示子函数
LCD1602_SHOW1:
	;LCD1602的第1行显示：TEMP=00.0℃
	MOV A,#080H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#081H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"E"
	LCALL WR_DAT
	
	MOV A,#082H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"M"
	LCALL WR_DAT
	
	MOV A,#083H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"P"
	LCALL WR_DAT
	
	MOV A,#084H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#085H		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HH
	LCALL WR_DAT
	
	MOV A,#086H		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HL
	LCALL WR_DAT
	
	MOV A,#087H		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"."
	LCALL WR_DAT
	
	MOV A,#088H		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_LH
	LCALL WR_DAT
	
	MOV A,#089H		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#"'"
	LCALL WR_DAT
	
	MOV A,#08AH		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"C"
	LCALL WR_DAT
	
	MOV A,#08BH		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08CH		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08DH		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08EH		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08FH		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	;LCD1602的第2行显示：DUTY=000.0%
	MOV A,#0C0H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"D"
	LCALL WR_DAT
		
	MOV A,#0C1H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"U"
	LCALL WR_DAT
	
	MOV A,#0C2H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#0C3H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"Y"
	LCALL WR_DAT
	
	MOV A,#0C4H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#0C5H		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HH
	LCALL WR_DAT
	
	MOV A,#0C6H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HM
	LCALL WR_DAT
	
	MOV A,#0C7H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HL
	LCALL WR_DAT
	
	MOV A,#0C8H		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"."
	LCALL WR_DAT
	
	MOV A,#0C9H		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_LH
	LCALL WR_DAT
	
	MOV A,#0CAH		;LCD1602第2行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#"%"
	LCALL WR_DAT
	
	MOV A,#0CBH		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CCH		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CDH		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CEH		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CFH		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	RET

;===================================================================
;LCD1602显示子函数
LCD1602_SHOW2:
	;LCD1602的第1行显示：TEMP=00℃
	MOV A,#080H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#081H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"E"
	LCALL WR_DAT
	
	MOV A,#082H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"M"
	LCALL WR_DAT
	
	MOV A,#083H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"P"
	LCALL WR_DAT
	
	MOV A,#084H		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#085H		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HH
	LCALL WR_DAT
	
	MOV A,#086H		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,TEMP_HL
	LCALL WR_DAT
	
	MOV A,#087H		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"'"
	LCALL WR_DAT
	
	MOV A,#088H		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#"C"
	LCALL WR_DAT
	
	MOV A,#089H		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08AH		;LCD1602第1行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08BH		;LCD1602第1行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08CH		;LCD1602第1行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08DH		;LCD1602第1行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08EH		;LCD1602第1行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#08FH		;LCD1602第1行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	;LCD1602的第2行显示：DUTY=000%
	MOV A,#0C0H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"D"
	LCALL WR_DAT
		
	MOV A,#0C1H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"U"
	LCALL WR_DAT
	
	MOV A,#0C2H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"T"
	LCALL WR_DAT
	
	MOV A,#0C3H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"Y"
	LCALL WR_DAT
	
	MOV A,#0C4H		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#"="
	LCALL WR_DAT
	
	MOV A,#0C5H		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HH
	LCALL WR_DAT
	
	MOV A,#0C6H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HM
	LCALL WR_DAT
	
	MOV A,#0C7H		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#"0"
	ADD A,DUTY_HL
	LCALL WR_DAT
	
	MOV A,#0C8H		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#"%"
	LCALL WR_DAT
	
	MOV A,#0C9H		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CAH		;LCD1602第2行，第10个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CBH		;LCD1602第2行，第5个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CCH		;LCD1602第2行，第6个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CDH		;LCD1602第2行，第7个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CEH		;LCD1602第2行，第8个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	
	MOV A,#0CFH		;LCD1602第2行，第9个位置
	LCALL WR_CMD	;写地址
	MOV A,#" "
	LCALL WR_DAT
	RET

;===================================================================
;写入控制命令
WR_CMD: 			
	MOV LCD1602_DAT,A
	LCALL LCD1602_DELAY
	CLR LCD1602_RS 	
	LCALL LCD1602_DELAY
	CLR LCD1602_RW
	LCALL LCD1602_DELAY
	CLR LCD1602_E
	LCALL LCD1602_DELAY
	SETB LCD1602_E
	LCALL LCD1602_DELAY1
	RET

;===================================================================
;写入数据
WR_DAT:		
	MOV LCD1602_DAT,A
	LCALL LCD1602_DELAY
	SETB LCD1602_RS 
	LCALL LCD1602_DELAY
	CLR LCD1602_RW
	LCALL LCD1602_DELAY
	CLR LCD1602_E
	LCALL LCD1602_DELAY
	SETB LCD1602_E
	LCALL LCD1602_DELAY1
	RET


;*******************************************************************
;**************** 独立按键 *****************************************
;*******************************************************************
;===================================================================
;2位小数显示精度
JDE_P13:
	JB P1.3,P13_OUT		;按键按下判断，等于1则跳转
	LCALL DELAY_50MS	;延时消抖
	JB P1.3,P13_OUT		;按键按下判断，等于1则跳转
	JNB P1.3,$			;等待按键松手
	MOV JDE_SHOW,#0		;显示2位小数
P13_OUT:
	RET	

;===================================================================
;1位小数显示精度
JDE_P14:
	JB P1.4,P14_OUT		;按键按下判断，等于1则跳转
	LCALL DELAY_50MS	;延时消抖
	JB P1.4,P14_OUT		;按键按下判断，等于1则跳转
	JNB P1.4,$			;等待按键松手
	MOV JDE_SHOW,#1		;显示1位小数
P14_OUT:
	RET
	
;===================================================================
;0位小数显示精度
JDE_P15:
	JB P1.5,P15_OUT		;按键按下判断，等于1则跳转
	LCALL DELAY_50MS	;延时消抖
	JB P1.5,P15_OUT		;按键按下判断，等于1则跳转
	JNB P1.5,$			;等待按键松手
	MOV JDE_SHOW,#2		;显示0位小数
P15_OUT:
	RET



;*******************************************************************
;****************** DHT11子函数定义 ********************************
;*******************************************************************
;DHT11读取1个字节的数据
;入口参数：A
READ_BYTE_DHT11:
	MOV A,#0	;数据保存变量清0
	
	;【1】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GA1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GA1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【2】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GB1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GB1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【3】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GC1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GC1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【4】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GD1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GD1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【5】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GE1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GE1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【6】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GF1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GF1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【7】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GG1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GG1:
	LCALL DHT_DEL_J40US		;延时50US
	
	;【8】
	JNB INT_DHT11,$			;等待低电平过去
	LCALL DHT_DEL_J40US		;延时50US
	RL  A					;数据左移一位
	
	JNB INT_DHT11,DHT_GH1	;判断接收到的电平信号
	ORL A,#01H				;传输值为1
	JNB INT_DHT11,$			;等待低电平过去
	DHT_GH1:
	LCALL DHT_DEL_J40US		;延时50US
	RET



;*******************************************************************
;**************** 延时函数 *****************************************
;*******************************************************************
;===================================================================
;延时50毫秒子函数
DELAY_50MS:	;@11.0592MHz
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	LCALL DELAY_5MS
	RET

;===================================================================
;延时5毫秒子函数
DELAY_5MS:	;@11.0592MHz 
	LCALL DELAY_1MS
	LCALL DELAY_1MS
	LCALL DELAY_1MS
	LCALL DELAY_1MS
	LCALL DELAY_1MS
	RET

;===================================================================
;延时1毫秒子函数
DELAY_1MS:	;@11.0592MHz
	NOP
	NOP
	PUSH	30H
	PUSH	31H
	MOV		30H,#15
	MOV		31H,#88
NEXT9:
	DJNZ	31H,NEXT9
	DJNZ	30H,NEXT9
	POP		31H
	POP		30H
	RET

;===================================================================
;LCD1602延时子函数
LCD1602_DELAY1:	;@11.0592MHz
	MOV R6,#250
LCD1602_D1:
	MOV R7,#250
	DJNZ R7,$
	DJNZ R6,LCD1602_D1
	RET

;===================================================================
;LCD1602延时子函数
LCD1602_DELAY:	;@11.0592MHz
	MOV R7,#45
    DJNZ R7,$
	RET

;===================================================================
;DHT11延时40微秒子函数定义
DHT_DEL_40US:	;@11.0592MHz
	NOP
	NOP
	PUSH	30H
	MOV		30H,#144
NEXT0:
	DJNZ	30H,NEXT0
	POP		30H
	RET

;===================================================================
;DHT11延时40微秒子函数定义
DHT_DEL_J40US:	;@11.0592MHz【非常重要】
	NOP
	NOP
	PUSH	30H
	MOV		30H,#144
NEXT1:
	DJNZ	30H,NEXT1
	POP		30H
	RET



;===================================================================
;DHT11延时1毫秒子函数定义
DHT_DEL_1MS:	;@11.0592MHz
	NOP
	NOP
	PUSH	30H
	PUSH	31H
	MOV		30H,#15
	MOV		31H,#88
NEXT2:
	DJNZ	31H,NEXT2
	DJNZ	30H,NEXT2
	POP		31H
	POP		30H
	RET

;===================================================================
;DHT11延时20毫秒子函数定义
DHT_DEL_20MS:	;@11.0592MHz
	PUSH	30H
	PUSH	31H
	PUSH	32H
	MOV		30H,#2
	MOV		31H,#32
	MOV		32H,#58
DHT_DEL3:
	DJNZ	32H,DHT_DEL3
	DJNZ	31H,DHT_DEL3
	DJNZ	30H,DHT_DEL3
	POP		32H
	POP		31H
	POP		30H
	RET


;===========================================================================
;===========================================================================
END




