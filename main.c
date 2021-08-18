#include "config.h"


int main(void)
{
    /* Enable the GPIOA peripheral in 'IOPENR'*/
    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;

    /*Configure GPIO pin : (OUTPUT is 0x01)*/
    GPIOA->MODER |= ((1<<GPIO_7_MODER_POS_0)|(1<<GPIO_8_MODER_POS_0));//sets 14 and 16 bit to 1
    GPIOA->MODER &= ~((1<<GPIO_7_MODER_POS_1)|(1<<GPIO_8_MODER_POS_1));//sets 15 adn 17 bit to 0

    GPIOA->ODR |= (1 << LED_PIN_7);
    GPIOA->ODR &= ~(1 << LED_PIN_8);

    while (1)
    {

        GPIOA->ODR ^= (1 << LED_PIN_7);
        GPIOA->ODR ^= (1 << LED_PIN_8);
    }

}

