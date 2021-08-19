#include "binaryWatch.h"


int main(void)
{
    uint32_t time=0;

    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;

    RCC->CSR |= 1<<RCC_CSR_RTCEN_Pos;

    GPIOA->MODER |= ((1<<(7*2))|(1<<(8*2+1)));//sets 14 and 16 bit to 1
    GPIOA->MODER &= ~((1<<(7*2+1))|(1<<(8*2+1)));//sets 15 adn 17 bit to 0
    GPIOA->ODR |= (1 << 7);
    GPIOA->ODR &= ~(1 << 8);

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



