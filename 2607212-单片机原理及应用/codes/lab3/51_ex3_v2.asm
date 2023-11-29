ORG		0000H
		AJMP		MAIN
		ORG		0003H
		LJMP		EX00
		;主程序
		ORG		0030H
MAIN:  
		MOV		SP,#60H			;设置堆栈指针
		SETB		IT0				;设置边沿触发
		SETB		EX0				;允许外部中断0中断
		SETB		EA				;打开中断允许总开关
		JNB			P3.3,$			;等待run信号
		SETB		P2.2				;使能74HC573
		MOV		P0,#0FEH		;点亮D1
LpLED:
		LCALL		DL200ms
		MOV		A,P0			;读取P0口状态至A中
		RL			A				;循环右移
		MOV		P0,A			;将循环右移的结果反还给P0口
		SJMP		LpLED

		;延时子程序, 延时200ms
		;1Tm=12/fosc=12/(12MHz)=1us
DL200ms:
		MOV		R6,#200			;外循环，实现200ms时延，指令周期：1Tm
									;(R6)←200，R6为外循环计数器
DL1ms:
		MOV		R7,#200			;内循环，实现1ms时延，指令周期：1Tm
									;(R7)←200，R7为内循环计数器
DL5us:
		NOP						;空操作，指令周期：1Tm
		NOP						;空操作，指令周期：1Tm
		NOP						;空操作，指令周期：1Tm
		DJNZ		R7, DL5us		;内循环判断控制，指令周期：2Tm
									;(R7)←(R7)-1
									;当(R7)≠0时, 程序跳转至DL5us 
		DJNZ		R6, DL1ms		;外循环判断控制，指令周期：2Tm
									;(R6)←(R6)-1
									;当(R6)≠0时, 程序跳转至DL1ms
					RET				;子程序返回
		
		;中断子程序
EX00:
		PUSH		PSW			;保护程序状态字和工作寄存器组
		PUSH		ACC			;保护累加器
		;选择寄存器组1
		CLR			RS1
		SETB		RS0
BELL:
		CLR		P2.5				;蜂鸣器报警
		JNB		P3.3, BELL		;等待run信号
		;恢复现场
		SETB	P2.5				;蜂鸣器停止报警
		POP		ACC			
		POP		PSW
				RETI			;返回中断点
				
				END			;汇编结束
