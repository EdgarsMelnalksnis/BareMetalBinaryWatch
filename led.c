#include "led.h"
#include "stm32l031xx.h"

inline static void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode)
{
    GPIOA->MODER |= ((1<<(gpio_anode*2))|(1<<(gpio_cathode*2)));
    GPIOA->MODER &= ~((1<<(gpio_anode*2+1))|(1<<(gpio_cathode*2+1)));
    GPIOA->ODR |= (1 << gpio_anode);
    GPIOA->ODR &= ~(1 << gpio_cathode);
    GPIOA->MODER |= ((1<<(gpio_anode*2))|(1<<(gpio_cathode*2)));
    GPIOA->MODER |=((1<<(gpio_anode*2+1))|(1<<(gpio_cathode*2+1)));

}
inline static void led_test(void)
{
    blink_led(LED_CTRL_0,LED_CTRL_1);
    blink_led(LED_CTRL_0,LED_CTRL_2);
    blink_led(LED_CTRL_0,LED_CTRL_3);
    blink_led(LED_CTRL_0,LED_CTRL_4);
    blink_led(LED_CTRL_0,LED_CTRL_5);
    blink_led(LED_CTRL_1,LED_CTRL_2);
    blink_led(LED_CTRL_1,LED_CTRL_3);
    blink_led(LED_CTRL_1,LED_CTRL_4);
    blink_led(LED_CTRL_1,LED_CTRL_5);
    blink_led(LED_CTRL_2,LED_CTRL_3);
    blink_led(LED_CTRL_2,LED_CTRL_4);
    blink_led(LED_CTRL_2,LED_CTRL_5);
    blink_led(LED_CTRL_3,LED_CTRL_4);
    blink_led(LED_CTRL_3,LED_CTRL_5);
    blink_led(LED_CTRL_4,LED_CTRL_5);
    blink_led(LED_CTRL_1,LED_CTRL_0);
    blink_led(LED_CTRL_2,LED_CTRL_0);
    blink_led(LED_CTRL_3,LED_CTRL_0);
    blink_led(LED_CTRL_2,LED_CTRL_1);
    blink_led(LED_CTRL_5,LED_CTRL_0);
    blink_led(LED_CTRL_4,LED_CTRL_0);
}
static void time_to_binary(uint8_t hours,uint8_t minutes,uint8_t sec)
{
}
