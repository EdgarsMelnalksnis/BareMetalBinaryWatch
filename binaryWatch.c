#include "binaryWatch.h"

inline static void blink_led(uint8_t gpio_anode,uint8_t gpio_cathode)
{
    GPIOA->MODER |= ((1<<(gpio_anode*2))|(1<<(gpio_cathode*2)));//sets 14 and 16 bit to 1
    GPIOA->MODER &= ~((1<<(gpio_anode*2+1))|(1<<(gpio_cathode*2+1)));//sets 15 adn 17 bit to 0
    GPIOA->ODR |= (1 << gpio_anode);
    GPIOA->ODR &= ~(1 << gpio_cathode);
    GPIOA->MODER |= ((1<<(gpio_anode*2))|(1<<(gpio_cathode*2)));//sets 14 and 16 bit to 1
    GPIOA->MODER |=((1<<(gpio_anode*2+1))|(1<<(gpio_cathode*2+1)));

}
inline static void led_test(void)
{
    blink_led(LED_PIN_7,LED_PIN_8);
    blink_led(LED_PIN_7,LED_PIN_9);
    blink_led(LED_PIN_7,LED_PIN_10);
    blink_led(LED_PIN_7,LED_PIN_11);
    blink_led(LED_PIN_7,LED_PIN_12);
    blink_led(LED_PIN_8,LED_PIN_9);
    blink_led(LED_PIN_8,LED_PIN_10);
    blink_led(LED_PIN_8,LED_PIN_11);
    blink_led(LED_PIN_8,LED_PIN_12);
    blink_led(LED_PIN_9,LED_PIN_10);
    blink_led(LED_PIN_9,LED_PIN_11);
    blink_led(LED_PIN_9,LED_PIN_12);
    blink_led(LED_PIN_10,LED_PIN_11);
    blink_led(LED_PIN_10,LED_PIN_12);
    blink_led(LED_PIN_11,LED_PIN_12);
    blink_led(LED_PIN_8,LED_PIN_7);
    blink_led(LED_PIN_9,LED_PIN_7);
    blink_led(LED_PIN_10,LED_PIN_7);
    blink_led(LED_PIN_9,LED_PIN_8);
    blink_led(LED_PIN_12,LED_PIN_7);
    blink_led(LED_PIN_11,LED_PIN_7);
}
static void time_to_binary(uint8_t hours,uint8_t minutes,uint8_t sec)
{
}
