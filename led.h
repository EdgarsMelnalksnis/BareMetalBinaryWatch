#ifndef _VVC_LED_H
#define _VVC_LED_H

#include <stdint.h>

inline static void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
inline static void led_test(void);
inline static void time_to_binary(uint8_t hours,uint8_t minute,uint8_t sec);




#endif
