#include "main.h"

int main(void)
{
    /* Enable the GPIOA peripheral in 'IOPENR'*/
    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;


    /*Configure GPIO pin : */

    GPIOA->MODER |= (1<<16u);
    GPIOA->MODER &= ~(1<<17u);
    GPIOA->MODER |= (1<<14u);
    GPIOA->MODER &= ~(1<<15u);
    GPIOA->MODER |= (1<<26u);
    GPIOA->MODER &= ~(1<<27u);

    GPIOA->ODR |= (1 << LED_PIN_7);
    GPIOA->ODR &= ~(1 << LED_PIN_8);

    while (1)
    {

        GPIOA->ODR ^= (1 << LED_PIN_7);
        GPIOA->ODR ^= (1 << LED_PIN_8);
    }

}


