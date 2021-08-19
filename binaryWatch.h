#ifndef _VVC_BINARYWATCH_H
#define _VVC_BINARYWATCH_H

#include <stdint.h>
#include "stm32l031xx.h"

#define LED_CTRL_0    (7u)
#define LED_CTRL_1    (8u)
#define LED_CTRL_2   (9u)
#define LED_CTRL_3   (10u)
#define LED_CTRL_4   (11u)
#define LED_CTRL_5   (12u)

#define GPIO_7_MODER_POS_0 (14u)
#define GPIO_7_MODER_POS_1 (15u)
#define GPIO_8_MODER_POS_0 (16u)
#define GPIO_8_MODER_POS_1 (17u)
#define GPIO_9_MODER_POS_0 (18u)
#define GPIO_9_MODER_POS_1 (19u)
#define GPIO_10_MODER_POS_0 (20u)
#define GPIO_10_MODER_POS_1 (21u)
#define GPIO_11_MODER_POS_0 (22u)
#define GPIO_11_MODER_POS_1 (23u)
#define GPIO_12_MODER_POS_0 (24u)
#define GPIO_12_MODER_POS_1 (25u)


inline static void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode);
inline static void led_test(void);
inline static void time_to_binary(uint8_t hours,uint8_t minute,uint8_t sec);




#endif
