#ifndef _VVC_LED_H
#define _VVC_LED_H

#include <stdint.h>

#include "config.h"


typedef struct
{
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
}Time;


void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
void led_test(void);
void set_time(uint8_t hours,uint8_t min,uint8_t sec,Time *time_struct);
void time_to_binary(Time);




#endif
