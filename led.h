#ifndef _VVC_LED_H
#define _VVC_LED_H

#include <stdint.h>

inline void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
inline void led_test(void);
inline void time_to_binary(uint8_t hours,uint8_t minute,uint8_t sec);




#endif
