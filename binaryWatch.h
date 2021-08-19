#ifndef _VVC_BINARYWATCH_H
#define _VVC_BINARYWATCH_H

#include <stdint.h>
#include "stm32l031xx.h"

#define LED_PIN_7    (7u)
#define LED_PIN_8    (8u)
#define LED_PIN_9    (9u)
#define LED_PIN_10   (10u)
#define LED_PIN_11   (11u)
#define LED_PIN_12   (12u)

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


static void led_test(void);

static void time_to_binary(uint8_t hours,uint8_t minutes,uint8_t sec);




#endif
