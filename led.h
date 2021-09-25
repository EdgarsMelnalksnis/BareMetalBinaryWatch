#ifndef _VVC_LED_H
#define _VVC_LED_H

#include <stdint.h>

#include "config.h"

int var1;

typedef struct
{
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
}Time;


void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
void led_test(void);
//void time_to_binary(Time);




#endif
