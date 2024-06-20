ORG 0000H
AJMP MAIN
ORG 000BH
LJMP TIME

;主程序
ORG 0030H
MAIN:  
    JNB P3.3,$ ;等待run信号
    MOV SP,#60H ;设置堆栈指针
    MOV TMOD,#01H ;设置T0方式1定时模式

    ;定时50ms的初值计算：(2^16-X)×1us=50ms=50 000us 使用十六位进行计时
    ;X=65 536-50 000=15 536=3C B0H
    MOV TH0,#3CH
    MOV TL0,#0B0H
    MOV R0,#10 ;设置内循环次数为10
    MOV R1,#20 ;设置外循环次数为20
    SETB ET0 ;允许T0中断
    SETB EA ;打开中断允许总开关
    SETB TR0 ;启动T0计数

LOOP:
    AJMP LOOP

TIME:
    ;重新赋值
    MOV TH0,#3CH
    MOV TL0,#0B0H
    DJNZ R0,EXIT ;循环不到10次重复定时
    MOV R0,#10
    CPL P0.0 ;P0.0状态取反
    DJNZ R1,EXIT ;循环不到20次重复定时
    MOV R1,#20
    CPL P0.1 ;P0.1状态取反

EXIT:
    RETI ;返回中断点

END ;汇编结束