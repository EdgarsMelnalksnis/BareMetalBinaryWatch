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

typedef struct
{
    uint8_t anode;
    uint8_t cathode;
}Led;

void blink_led_struct(Led);
void bcd_to_display(uint32_t,Led *);
void led_test_array(Led *);
void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
void led_test(void);
void set_time(uint8_t hours,uint8_t min,uint8_t sec,Time *time_struct);
void time_to_binary(Time);




#endif
