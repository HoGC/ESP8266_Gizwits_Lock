/*
 * lock driver
 * Author: HoGC 
 */

#ifndef _LOCK_H_
#define _LOCK_H_

#include "driver/gpio_key.h"
#include "user_interface.h"
#include "gizwits_product.h"

#define LOCK_GPIO 	D3      //舵机引脚
#define LOCK_FLASH  250

void ICACHE_FLASH_ATTR lock_init(void);

void ICACHE_FLASH_ATTR set_angle_max(u8 angle);

void ICACHE_FLASH_ATTR set_angle_min(u8 angle);

void ICACHE_FLASH_ATTR set_open_time(u8 time);

void ICACHE_FLASH_ATTR lock_open(void);

void ICACHE_FLASH_ATTR lock_close(void);

#endif /* _LOCK_H_ */
