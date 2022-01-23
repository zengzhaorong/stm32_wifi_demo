#include <stdio.h>
#include <string.h>
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "ringbuffer.h"
#include "cJSON.h"
#include "wifi_esp8266.h"
#include "protocol.h"

extern unsigned char ring_buf[512];
extern struct ringbuffer wifi_ringbuf;

/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
 int main(void)
 {		
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200

	wifi_init();
	proto_init();

	 wifi_config_AP_mode("hello-esp8266", "88888888");
	 wifi_config_tcp_server("192.168.1.101", 9100);

	 wifi_set_AT(AT_GET_LOCAL_IP, strlen(AT_GET_LOCAL_IP), NULL, 0);

 	while(1)
	{
		
		proto_server_handel(&wifi_ringbuf);

	}	 
 }

