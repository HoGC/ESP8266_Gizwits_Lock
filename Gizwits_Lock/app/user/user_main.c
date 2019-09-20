/*
 * Author: HoGC 
 */
#include "ets_sys.h"
#include "osapi.h"
#include "user_interface.h"
#include "gagent_soc.h"
#include "user_devicefind.h"
#include "user_webserver.h"
#include "gizwits_product.h"
#include "driver/lock.h"
#include "driver/gpio_key.h"
#if ESP_PLATFORM
#include "user_esp_platform.h"
#endif

#ifdef SERVER_SSL_ENABLE
#include "ssl/cert.h"
#include "ssl/private_key.h"
#else
#ifdef CLIENT_SSL_ENABLE
unsigned char *default_certificate;
unsigned int default_certificate_len = 0;
unsigned char *default_private_key;
unsigned int default_private_key_len = 0;
#endif
#endif


//按键回调
LOCAL void ICACHE_FLASH_ATTR key_cb(void)
{   
    //进入配网模式
    gizwitsSetMode(WIFI_AIRLINK_MODE);
    //点亮8266 LED
    gpio_wirte(D4,0);
}


LOCAL void ICACHE_FLASH_ATTR keyInit(void)
{
	//设置按键数量
	set_key_num(1);
	//长按、短按的按键回调
	key_add(D2, key_cb, NULL);
}

uint32_t ICACHE_FLASH_ATTR user_rf_cal_sector_set()
{
    return 636;
}

void ICACHE_FLASH_ATTR user_init(void)
{
    wifi_station_set_auto_connect(1);
    wifi_set_sleep_type(NONE_SLEEP_T);
    espconn_tcp_set_max_con(10);
	uart_init(115200, 115200);
	os_delay_us(60000);

    //LED gpio初始化
    gpio_out_init(D4,1);

    //机智云初始化
    gizwitsInit();

    //按键初始化
    keyInit();
    power_key_init(key_cb);

    lock_init();
}
