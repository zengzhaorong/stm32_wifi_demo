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
#include "config.h"

extern unsigned char ring_buf[512];
extern struct ringbuffer wifi_ringbuf;

int main(void)
{

	delay_init();	    	 //?������o����y3?��??��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����??NVIC?D??��?����2:2???��??��??��??��?2???����|��??��??
	uart_init(115200);	 //��??��3?��??��?a115200

	wifi_init();
	proto_init();

	wifi_config_AP_mode(WIFI_AP_SSID, WIFI_AP_PWD);

	wifi_config_tcp_server(TCP_SERVER_IP, TCP_SERVER_PORT);

	wifi_set_AT(AT_GET_LOCAL_IP, strlen(AT_GET_LOCAL_IP), NULL, 0);

	while(1)
	{

		proto_server_handel(&wifi_ringbuf);

	}	 
}

