#include "stm32l031xx.h"
#include "led.h"
#include "config.h"

int main(void)
{
    uint32_t dummy_del=0;
    //uint32_t time=0;
    Time time;
    time.sec=0;
    time.min=0;
    time.hours=0;
    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;

    RCC->CSR |= 1 << RCC_CSR_RTCEN_Pos;

    //GPIOA->MODER |= (1<<GPIO_7_MODER_POS_0)|(1<<GPIO_8_MODER_POS_0);
    //GPIOA->MODER &= ~((1<<GPIO_7_MODER_POS_1)|(1<<GPIO_8_MODER_POS_1));
    //GPIOA->ODR |= (1 << LED_CTRL_0 );
    //GPIOA->ODR &= ~(1 << LED_CTRL_1 );
    //time.sec=13;
    while(1)
    {
        dummy_del++;
        if(dummy_del>1000)//5000 for 1sec
        {
            dummy_del=0;
            time.sec++;
            time.min++;
            time.hours++;
            if(time.sec>59)
            {
                time.sec=0;
                //time.min++;
                if(time.min>59)
                {
                    time.min=0;
                }
                if(time.hours>24)
                {
                    time.hours=0;
                }
            }
        }
        time_to_binary(time);

    }
    while(1)
    {
        time.sec=RTC->TR;
        if(time.sec % 10 == 0)
        {
            GPIOA->ODR ^= (1 << 8);
        }


    }

}



