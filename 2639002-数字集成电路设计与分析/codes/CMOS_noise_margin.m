clear;clc;close all;
KR=0:0.001:12;
n_sample=length(KR);
% VDD=3.3;
% VTN=0.75;
% VTP=-0.75;
VDD=2.5;
VTN=0.5;
VTP=-0.5;

VIL=2*sqrt(KR)*(VDD-VTN+VTP)./((KR-1).*sqrt(KR+3))-(VDD-KR*VTN+VTP)./(KR-1);

VOH=((KR+1).*VIL+VDD-KR*VTN-VTP)/2;

VIH=2*KR*(VDD-VTN+VTP)./((KR-1).*sqrt(1+3*KR))-(VDD-KR*VTN+VTP)./(KR-1);

VOL=((KR+1).*VIH-VDD-KR*VTN-VTP)./(2*KR);

NML=VIL-VOL;

NMH=VOH-VIH;

figure(1);
plot(KR,NML,'r','DisplayName','NM_L');hold on;
plot(KR,NMH,'b','DisplayName','NM_H');
grid on;
xlabel('K_R=0:0.001:12');
ylabel('Noinse Margin');
title('CMOS 噪声容限');
xlim([min(KR) max(KR)]);
ylim([min([min(NML) min(NMH)]) max([max(NML) max(NMH)])]);
legend;
