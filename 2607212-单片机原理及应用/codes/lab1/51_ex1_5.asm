ORG 0000H
AJMP MAIN
ORG 0030H

MAIN: MOV P0, #00H ; 初始化P0口为0
    MOV R0, #00H ; 初始化R0为0

WAIT: JNB P3.3, WAIT ; 等待RUN按键按下
    ACALL DELAY ; 消抖
    JNB P3.3, WAIT ; 再次检测RUN按键是否按下

    INC R0 ; R0加1
    MOV A, R0 ; 将R0的值移动到累加器A中
    ANL A, #0FH ; 只保留A中的低4位
    MOV P0, A ; 将A的值输出到P0口

    SJMP WAIT ; 跳转到WAIT标签处，等待下一次按键

DELAY: MOV R2, #0FFH ; 延时循环计数器
DELAY1: DJNZ R2, DELAY1 ; 延时循环
    RET ; 返回

END