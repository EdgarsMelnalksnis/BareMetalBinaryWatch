#include "stm32l031xx.h"
#include "led.h"
#include "config.h"

int main(void)
{
    uint32_t time=0;

    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;

    RCC->CSR |= 1 << RCC_CSR_RTCEN_Pos;

    GPIOA->MODER |= (1<<GPIO_7_MODER_POS_0)|(1<<GPIO_8_MODER_POS_0);
    GPIOA->MODER &= ~((1<<GPIO_7_MODER_POS_1)|(1<<GPIO_8_MODER_POS_1));
    GPIOA->ODR |= (1 << LED_CTRL_0 );
    GPIOA->ODR &= ~(1 << LED_CTRL_1 );

while(1)
{
    time=RTC->TR;
    if(time % 2 == 0)
        {
            GPIOA->ODR ^= (1 << 8);
        }
        //led_test();

    }

}



