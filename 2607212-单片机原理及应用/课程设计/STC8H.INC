;P0          DATA    080H
;SP          DATA    081H
;DPL         DATA    082H
;DPH         DATA    083H
S4CON     DATA    084H
S4BUF       DATA    085H
;PCON        DATA    087H
;TCON        DATA    088H
;TMOD        DATA    089H
;TL0         DATA    08AH
;TL1         DATA    08BH
;TH0         DATA    08CH
;TH1         DATA    08DH
AUXR        DATA    08EH
INTCLKO     DATA    08FH
;P1          DATA    090H
P1M1        DATA    091H
P1M0        DATA    092H
P0M1        DATA    093H
P0M0        DATA    094H
P2M1        DATA    095H
P2M0        DATA    096H
;SCON        DATA    098H
;SBUF        DATA    099H
S2CON       DATA    09AH
S2BUF       DATA    09BH
IRCBAND     DATA    09DH
LIRTRIM     DATA    09EH
IRTRIM      DATA    09FH
;P2          DATA    0A0H
BUSSPEED    DATA    0A1H
P_SW1       DATA    0A2H
;IE          DATA    0A8H
SADDR       DATA    0A9H
WKTCL       DATA    0AAH
WKTCH       DATA    0ABH
S3CON       DATA    0ACH
S3BUF       DATA    0ADH
TA          DATA    0AEH
IE2         DATA    0AFH
;P3          DATA    0B0H
P3M1        DATA    0B1H
P3M0        DATA    0B2H
P4M1        DATA    0B3H
P4M0        DATA    0B4H
IP2         DATA    0B5H
IP2H        DATA    0B6H
IPH         DATA    0B7H
;IP          DATA    0B8H
SADEN       DATA    0B9H
P_SW2       DATA    0BAH
ADC_CONTR   DATA    0BCH
ADC_RES     DATA    0BDH
ADC_RESL    DATA    0BEH
P4          DATA    0C0H 
WDT_CONTR   DATA    0C1H
IAP_DATA    DATA    0C2H 
IAP_ADDRH   DATA    0C3H 
IAP_ADDRL   DATA    0C4H 
IAP_CMD     DATA    0C5H 
IAP_TRIG    DATA    0C6H 
IAP_CONTR   DATA    0C7H 
P5          DATA    0C8H 
P5M1        DATA    0C9H 
P5M0        DATA    0CAH 
P6M1        DATA    0CBH 
P6M0        DATA    0CCH 
SPSTAT      DATA    0CDH 
SPCTL       DATA    0CEH 
SPDAT       DATA    0CFH 
;PSW         DATA    0D0H 
T4T3M     DATA    0D1H 
T4H         DATA    0D2H
T4L         DATA    0D3H
T3H         DATA    0D4H
T3L         DATA    0D5H
T2H         DATA    0D6H
T2L         DATA    0D7H
USBCLK      DATA    0DCH
ADCCFG      DATA    0DEH
IP3         DATA    0DFH
;ACC         DATA    0E0H 
P7M1        DATA    0E1H
P7M0        DATA    0E2H
DPS         DATA    0E3H 
DPL1        DATA    0E4H 
DPH1        DATA    0E5H 
CMPCR1      DATA    0E6H 
CMPCR2      DATA    0E7H 
P6          DATA    0E8H 
USBDAT      DATA    0ECH
IP3H        DATA    0EEH
AUXINTIF    DATA    0EFH
;B           DATA    0F0H 
USBCON      DATA    0F4H
IAP_TPS     DATA    0F5H
P7          DATA    0F8H 
USBADR      DATA    0FCH
RSTCFG      DATA    0FFH

P07        BIT     P0.7
P06        BIT     P0.6
P05        BIT     P0.5
P04        BIT     P0.4
P03        BIT     P0.3
P02        BIT     P0.2
P01        BIT     P0.1
P00        BIT     P0.0
P17        BIT     P1.7
P16        BIT     P1.6
P15        BIT     P1.5
P14        BIT     P1.4
P13        BIT     P1.3
P12        BIT     P1.2
P11        BIT     P1.1
P10        BIT     P1.0
P27        BIT     P2.7
P26        BIT     P2.6
P25        BIT     P2.5
P24        BIT     P2.4
P23        BIT     P2.3
P22        BIT     P2.2
P21        BIT     P2.1
P20        BIT     P2.0
P37        BIT     P3.7
P36        BIT     P3.6
P35        BIT     P3.5
P34        BIT     P3.4
P33        BIT     P3.3
P32        BIT     P3.2
P31        BIT     P3.1
P30        BIT     P3.0
P47        BIT     P4.7
P46        BIT     P4.6
P45        BIT     P4.5
P44        BIT     P4.4
P43        BIT     P4.3
P42        BIT     P4.2
P41        BIT     P4.1
P40        BIT     P4.0
P57        BIT     P5.7
P56        BIT     P5.6
P55        BIT     P5.5
P54        BIT     P5.4
P53        BIT     P5.3
P52        BIT     P5.2
P51        BIT     P5.1
P50        BIT     P5.0
P67        BIT     P6.7
P66        BIT     P6.6
P65        BIT     P6.5
P64        BIT     P6.4
P63        BIT     P6.3
P62        BIT     P6.2
P61        BIT     P6.1
P60        BIT     P6.0
P77        BIT     P7.7
P76        BIT     P7.6
P75        BIT     P7.5
P74        BIT     P7.4
P73        BIT     P7.3
P72        BIT     P7.2
P71        BIT     P7.1
P70        BIT     P7.0

;IT0        BIT     TCON.0
;IE0        BIT     TCON.1
;IT1        BIT     TCON.2
;IE1        BIT     TCON.3
;TR0        BIT     TCON.4
;TF0        BIT     TCON.5
;TR1        BIT     TCON.6
;TF1        BIT     TCON.7

;RI         BIT     SCON.0
;TI         BIT     SCON.1
;RB8        BIT     SCON.2
;TB8        BIT     SCON.3
;REN        BIT     SCON.4
;SM2        BIT     SCON.5
;SM1        BIT     SCON.6
;SM0        BIT     SCON.7

;EX0        BIT     IE.0
;ET0        BIT     IE.1
;EX1        BIT     IE.2
;ET1        BIT     IE.3
;ES         BIT     IE.4
;EADC       BIT     IE.5
;ELVD       BIT     IE.6
;EA         BIT     IE.7

;PX0        BIT     IP.0
;PT0        BIT     IP.1
;PX1        BIT     IP.2
;PT1        BIT     IP.3
;PS         BIT     IP.4
;PADC       BIT     IP.5
;PLVD       BIT     IP.6

;P          BIT     PSW.0
;OV         BIT     PSW.2
;RS0        BIT     PSW.3
;RS1        BIT     PSW.4
;F0         BIT     PSW.5
;AC         BIT     PSW.6
;CY         BIT     PSW.7

;INT4       BIT     P3.0
;INT0       BIT     P3.2
;INT1       BIT     P3.3
;T0         BIT     P3.4
;T1         BIT     P3.5
;INT2       BIT     P3.6
;INT3       BIT     P3.7


CLKSEL      EQU     0FE00H
CLKDIV      EQU     0FE01H
HIRCCR      EQU     0FE02H
XOSCCR      EQU     0FE03H
IRC32KCR    EQU     0FE04H
MCLKOCR     EQU     0FE05H
IRCDB       EQU     0FE06H
IRC48MCR    EQU     0FE07H
X32KCR      EQU     0FE08H

P0PU        EQU     0FE10H
P1PU        EQU     0FE11H
P2PU        EQU     0FE12H
P3PU        EQU     0FE13H
P4PU        EQU     0FE14H
P5PU        EQU     0FE15H
P6PU        EQU     0FE16H
P7PU        EQU     0FE17H
P0NCS       EQU     0FE18H
P1NCS       EQU     0FE19H
P2NCS       EQU     0FE1AH
P3NCS       EQU     0FE1BH
P4NCS       EQU     0FE1CH
P5NCS       EQU     0FE1DH
P6NCS       EQU     0FE1EH
P7NCS       EQU     0FE1FH
P0SR        EQU     0FE20H
P1SR        EQU     0FE21H
P2SR        EQU     0FE22H
P3SR        EQU     0FE23H
P4SR        EQU     0FE24H
P5SR        EQU     0FE25H
P6SR        EQU     0FE26H
P7SR        EQU     0FE27H
P0DR        EQU     0FE28H
P1DR        EQU     0FE29H
P2DR        EQU     0FE2AH
P3DR        EQU     0FE2BH
P4DR        EQU     0FE2CH
P5DR        EQU     0FE2DH
P6DR        EQU     0FE2EH
P7DR        EQU     0FE2FH
P0IE        EQU     0FE30H
P1IE        EQU     0FE31H
P2IE        EQU     0FE32H
P3IE        EQU     0FE33H
P4IE        EQU     0FE34H
P5IE        EQU     0FE35H
P6IE        EQU     0FE36H
P7IE        EQU     0FE37H

LCMIFCFG    EQU     0FE50H
LCMIFCFG2   EQU     0FE51H
LCMIFCR     EQU     0FE52H
LCMIFSTA    EQU     0FE53H
LCMIFDATL   EQU     0FE54H
LCMIFDATH   EQU     0FE55H

RTCCR       EQU     0FE60H
RTCCFG      EQU     0FE61H
RTCIEN      EQU     0FE62H
RTCIF       EQU     0FE63H
ALAHOUR     EQU     0FE64H
ALAMIN      EQU     0FE65H
ALASEC      EQU     0FE66H
ALASSEC     EQU     0FE67H
INIYEAR     EQU     0FE68H
INIMONTH    EQU     0FE69H
INIDAY      EQU     0FE6AH
INIHOUR     EQU     0FE6BH
INIMIN      EQU     0FE6CH
INISEC      EQU     0FE6DH
INISSEC     EQU     0FE6EH
YEAR        EQU     0FE70H
MONTH       EQU     0FE71H
DAY         EQU     0FE72H
HOUR        EQU     0FE73H
MIN         EQU     0FE74H
SEC         EQU     0FE75H
SSEC        EQU     0FE76H

I2CCFG      EQU     0FE80H
I2CMSCR     EQU     0FE81H
I2CMSST     EQU     0FE82H
I2CSLCR     EQU     0FE83H
I2CSLST     EQU     0FE84H
I2CSLADR    EQU     0FE85H
I2CTXD      EQU     0FE86H
I2CRXD      EQU     0FE87H
I2CMSAUX    EQU     0FE88H

RSTFLAG     EQU     0FE99H

TM2PS       EQU     0FEA2H
TM3PS       EQU     0FEA3H
TM4PS       EQU     0FEA4H
ADCTIM      EQU     0FEA8H
T3T4PS      EQU     0FEACH
ADCEXCFG    EQU     0FEADH
CMPEXCFG    EQU     0FEAEH


PWMA_ETRPS  EQU     0FEB0H
PWMA_ENO    EQU     0FEB1H
PWMA_PS     EQU     0FEB2H
PWMA_IOAUX  EQU     0FEB3H
PWMB_ETRPS  EQU     0FEB4H
PWMB_ENO    EQU     0FEB5H
PWMB_PS     EQU     0FEB6H
PWMB_IOAUX  EQU     0FEB7H
PWMA_CR1    EQU     0FEC0H
PWMA_CR2    EQU     0FEC1H
PWMA_SMCR   EQU     0FEC2H
PWMA_ETR    EQU     0FEC3H
PWMA_IER    EQU     0FEC4H
PWMA_SR1    EQU     0FEC5H
PWMA_SR2    EQU     0FEC6H
PWMA_EGR    EQU     0FEC7H
PWMA_CCMR1  EQU     0FEC8H
PWMA_CCMR2  EQU     0FEC9H
PWMA_CCMR3  EQU     0FECAH
PWMA_CCMR4  EQU     0FECBH
PWMA_CCER1  EQU     0FECCH
PWMA_CCER2  EQU     0FECDH
PWMA_CNTRH  EQU     0FECEH
PWMA_CNTRL  EQU     0FECFH
PWMA_PSCRH  EQU     0FED0H
PWMA_PSCRL  EQU     0FED1H
PWMA_ARRH   EQU     0FED2H
PWMA_ARRL   EQU     0FED3H
PWMA_RCR    EQU     0FED4H
PWMA_CCR1H  EQU     0FED5H
PWMA_CCR1L  EQU     0FED6H
PWMA_CCR2H  EQU     0FED7H
PWMA_CCR2L  EQU     0FED8H
PWMA_CCR3H  EQU     0FED9H
PWMA_CCR3L  EQU     0FEDAH
PWMA_CCR4H  EQU     0FEDBH
PWMA_CCR4L  EQU     0FEDCH
PWMA_BKR    EQU     0FEDDH
PWMA_DTR    EQU     0FEDEH
PWMA_OISR   EQU     0FEDFH
PWMB_CR1    EQU     0FEE0H
PWMB_CR2    EQU     0FEE1H
PWMB_SMCR   EQU     0FEE2H
PWMB_ETR    EQU     0FEE3H
PWMB_IER    EQU     0FEE4H
PWMB_SR1    EQU     0FEE5H
PWMB_SR2    EQU     0FEE6H
PWMB_EGR    EQU     0FEE7H
PWMB_CCMR1  EQU     0FEE8H
PWMB_CCMR2  EQU     0FEE9H
PWMB_CCMR3  EQU     0FEEAH
PWMB_CCMR4  EQU     0FEEBH
PWMB_CCER1  EQU     0FEECH
PWMB_CCER2  EQU     0FEEDH
PWMB_CNTRH  EQU     0FEEEH
PWMB_CNTRL  EQU     0FEEFH
PWMB_PSCRH  EQU     0FEF0H
PWMB_PSCRL  EQU     0FEF1H
PWMB_ARRH   EQU     0FEF2H
PWMB_ARRL   EQU     0FEF3H
PWMB_RCR    EQU     0FEF4H
PWMB_CCR1H  EQU     0FEF5H
PWMB_CCR1L  EQU     0FEF6H
PWMB_CCR2H  EQU     0FEF7H
PWMB_CCR2L  EQU     0FEF8H
PWMB_CCR3H  EQU     0FEF9H
PWMB_CCR3L  EQU     0FEFAH
PWMB_CCR4H  EQU     0FEFBH
PWMB_CCR4L  EQU     0FEFCH
PWMB_CCR5H  EQU     0FEF5H
PWMB_CCR5L  EQU     0FEF6H
PWMB_CCR6H  EQU     0FEF7H
PWMB_CCR6L  EQU     0FEF8H
PWMB_CCR7H  EQU     0FEF9H
PWMB_CCR7L  EQU     0FEFAH
PWMB_CCR8H  EQU     0FEFBH
PWMB_CCR8L  EQU     0FEFCH
PWMB_BKR    EQU     0FEFDH
PWMB_DTR    EQU     0FEFEH
PWMB_OISR   EQU     0FEFFH

P0INTE      EQU     0FD00H
P1INTE      EQU     0FD01H
P2INTE      EQU     0FD02H
P3INTE      EQU     0FD03H
P4INTE      EQU     0FD04H
P5INTE      EQU     0FD05H
P6INTE      EQU     0FD06H
P7INTE      EQU     0FD07H
P0INTF      EQU     0FD10H
P1INTF      EQU     0FD11H
P2INTF      EQU     0FD12H
P3INTF      EQU     0FD13H
P4INTF      EQU     0FD14H
P5INTF      EQU     0FD15H
P6INTF      EQU     0FD16H
P7INTF      EQU     0FD17H
P0IM0       EQU     0FD20H
P1IM0       EQU     0FD21H
P2IM0       EQU     0FD22H
P3IM0       EQU     0FD23H
P4IM0       EQU     0FD24H
P5IM0       EQU     0FD25H
P6IM0       EQU     0FD26H
P7IM0       EQU     0FD27H
P0IM1       EQU     0FD30H
P1IM1       EQU     0FD31H
P2IM1       EQU     0FD32H
P3IM1       EQU     0FD33H
P4IM1       EQU     0FD34H
P5IM1       EQU     0FD35H
P6IM1       EQU     0FD36H
P7IM1       EQU     0FD37H
P0WKUE      EQU     0FD40H
P1WKUE      EQU     0FD41H
P2WKUE      EQU     0FD42H
P3WKUE      EQU     0FD43H
P4WKUE      EQU     0FD44H
P5WKUE      EQU     0FD45H
P6WKUE      EQU     0FD46H
P7WKUE      EQU     0FD47H
                    
PIN_IP      EQU     0FD60H
PIN_IPH     EQU     0FD61H


CHIPID      EQU     0FDE0H

CHIPID0     EQU     0FDE0H
CHIPID1     EQU     0FDE1H
CHIPID2     EQU     0FDE2H
CHIPID3     EQU     0FDE3H
CHIPID4     EQU     0FDE4H
CHIPID5     EQU     0FDE5H
CHIPID6     EQU     0FDE6H
CHIPID7     EQU     0FDE7H
CHIPID8     EQU     0FDE8H
CHIPID9     EQU     0FDE9H
CHIPID10    EQU     0FDEAH
CHIPID11    EQU     0FDEBH
CHIPID12    EQU     0FDECH
CHIPID13    EQU     0FDEDH
CHIPID14    EQU     0FDEEH
CHIPID15    EQU     0FDEFH
CHIPID16    EQU     0FDF0H
CHIPID17    EQU     0FDF1H
CHIPID18    EQU     0FDF2H
CHIPID19    EQU     0FDF3H
CHIPID20    EQU     0FDF4H
CHIPID21    EQU     0FDF5H
CHIPID22    EQU     0FDF6H
CHIPID23    EQU     0FDF7H
CHIPID24    EQU     0FDF8H
CHIPID25    EQU     0FDF9H
CHIPID26    EQU     0FDFAH
CHIPID27    EQU     0FDFBH
CHIPID28    EQU     0FDFCH
CHIPID29    EQU     0FDFDH
CHIPID30    EQU     0FDFEH
CHIPID31    EQU     0FDFFH


DMA_M2M_CFG     EQU     0FA00H
DMA_M2M_CR      EQU     0FA01H
DMA_M2M_STA     EQU     0FA02H
DMA_M2M_AMT     EQU     0FA03H
DMA_M2M_DONE    EQU     0FA04H
DMA_M2M_TXAH    EQU     0FA05H
DMA_M2M_TXAL    EQU     0FA06H
DMA_M2M_RXAH    EQU     0FA07H
DMA_M2M_RXAL    EQU     0FA08H
                      
DMA_ADC_CFG     EQU     0FA10H
DMA_ADC_CR      EQU     0FA11H
DMA_ADC_STA     EQU     0FA12H
DMA_ADC_RXAH    EQU     0FA17H
DMA_ADC_RXAL    EQU     0FA18H
DMA_ADC_CFG2    EQU     0FA19H
DMA_ADC_CHSW0   EQU     0FA1AH
DMA_ADC_CHSW1   EQU     0FA1BH
                      
DMA_SPI_CFG     EQU     0FA20H
DMA_SPI_CR      EQU     0FA21H
DMA_SPI_STA     EQU     0FA22H
DMA_SPI_AMT     EQU     0FA23H
DMA_SPI_DONE    EQU     0FA24H
DMA_SPI_TXAH    EQU     0FA25H
DMA_SPI_TXAL    EQU     0FA26H
DMA_SPI_RXAH    EQU     0FA27H
DMA_SPI_RXAL    EQU     0FA28H
DMA_SPI_CFG2    EQU     0FA29H
                      
DMA_UR1T_CFG    EQU     0FA30H
DMA_UR1T_CR     EQU     0FA31H
DMA_UR1T_STA    EQU     0FA32H
DMA_UR1T_AMT    EQU     0FA33H
DMA_UR1T_DONE   EQU     0FA34H
DMA_UR1T_TXAH   EQU     0FA35H
DMA_UR1T_TXAL   EQU     0FA36H
DMA_UR1R_CFG    EQU     0FA38H
DMA_UR1R_CR     EQU     0FA39H
DMA_UR1R_STA    EQU     0FA3AH
DMA_UR1R_AMT    EQU     0FA3BH
DMA_UR1R_DONE   EQU     0FA3CH
DMA_UR1R_RXAH   EQU     0FA3DH
DMA_UR1R_RXAL   EQU     0FA3EH
                      
DMA_UR2T_CFG    EQU     0FA40H
DMA_UR2T_CR     EQU     0FA41H
DMA_UR2T_STA    EQU     0FA42H
DMA_UR2T_AMT    EQU     0FA43H
DMA_UR2T_DONE   EQU     0FA44H
DMA_UR2T_TXAH   EQU     0FA45H
DMA_UR2T_TXAL   EQU     0FA46H
DMA_UR2R_CFG    EQU     0FA48H
DMA_UR2R_CR     EQU     0FA49H
DMA_UR2R_STA    EQU     0FA4AH
DMA_UR2R_AMT    EQU     0FA4BH
DMA_UR2R_DONE   EQU     0FA4CH
DMA_UR2R_RXAH   EQU     0FA4DH
DMA_UR2R_RXAL   EQU     0FA4EH
                      
DMA_UR3T_CFG    EQU     0FA50H
DMA_UR3T_CR     EQU     0FA51H
DMA_UR3T_STA    EQU     0FA52H
DMA_UR3T_AMT    EQU     0FA53H
DMA_UR3T_DONE   EQU     0FA54H
DMA_UR3T_TXAH   EQU     0FA55H
DMA_UR3T_TXAL   EQU     0FA56H
DMA_UR3R_CFG    EQU     0FA58H
DMA_UR3R_CR     EQU     0FA59H
DMA_UR3R_STA    EQU     0FA5AH
DMA_UR3R_AMT    EQU     0FA5BH
DMA_UR3R_DONE   EQU     0FA5CH
DMA_UR3R_RXAH   EQU     0FA5DH
DMA_UR3R_RXAL   EQU     0FA5EH
                      
DMA_UR4T_CFG    EQU     0FA60H
DMA_UR4T_CR     EQU     0FA61H
DMA_UR4T_STA    EQU     0FA62H
DMA_UR4T_AMT    EQU     0FA63H
DMA_UR4T_DONE   EQU     0FA64H
DMA_UR4T_TXAH   EQU     0FA65H
DMA_UR4T_TXAL   EQU     0FA66H
DMA_UR4R_CFG    EQU     0FA68H
DMA_UR4R_CR     EQU     0FA69H
DMA_UR4R_STA    EQU     0FA6AH
DMA_UR4R_AMT    EQU     0FA6BH
DMA_UR4R_DONE   EQU     0FA6CH
DMA_UR4R_RXAH   EQU     0FA6DH
DMA_UR4R_RXAL   EQU     0FA6EH
                      
DMA_LCM_CFG     EQU     0FA70H
DMA_LCM_CR      EQU     0FA71H
DMA_LCM_STA     EQU     0FA72H
DMA_LCM_AMT     EQU     0FA73H
DMA_LCM_DONE    EQU     0FA74H
DMA_LCM_TXAH    EQU     0FA75H
DMA_LCM_TXAL    EQU     0FA76H
DMA_LCM_RXAH    EQU     0FA77H
DMA_LCM_RXAL    EQU     0FA78H

