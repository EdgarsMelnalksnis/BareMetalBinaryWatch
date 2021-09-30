#include "stm32l031xx.h"
#include "led.h"
#include "config.h"

int main(void)
{
    uint32_t dummy_del=0;
    uint32_t bcd_time=0;
    Time time;
    time.sec=0;
    time.min=0;
    time.hours=0;
    Led led_array[21]={{LED_CTRL_3,LED_CTRL_0},
        {LED_CTRL_2,LED_CTRL_1},
        {LED_CTRL_5,LED_CTRL_0},
        {LED_CTRL_4,LED_CTRL_0},
        {LED_CTRL_4,LED_CTRL_5},
        {LED_CTRL_1,LED_CTRL_0},
        {LED_CTRL_2,LED_CTRL_0},
        {LED_CTRL_2,LED_CTRL_4},
        {LED_CTRL_2,LED_CTRL_5},
        {LED_CTRL_3,LED_CTRL_4},
        {LED_CTRL_3,LED_CTRL_5},
        {LED_CTRL_1,LED_CTRL_4},
        {LED_CTRL_1,LED_CTRL_5},
        {LED_CTRL_2,LED_CTRL_3},
        {LED_CTRL_0,LED_CTRL_4},
        {LED_CTRL_0,LED_CTRL_5},
        {LED_CTRL_1,LED_CTRL_2},
        {LED_CTRL_1,LED_CTRL_3},
        {LED_CTRL_0,LED_CTRL_1},
        {LED_CTRL_0,LED_CTRL_2},
        {LED_CTRL_0,LED_CTRL_3}};

    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;
    RCC->CSR |= (1<<0);//LSI on
    while(RCC->CSR & 1<<1)
    {
        //wait for LSI ready
    }
    RCC->APB1ENR |= (1<<28);//PWREN 
    PWR->CR |= (1<<8);//DBP
    RCC->CSR |= (1<<17);//LSI as internal clock source
    RCC->CSR |= (1 << 18);//enable RTC

    //led_test_array(led_array);

    while(1)
    {
        time.sec=RTC -> TR;
        bcd_time = RTC -> TR;
        bcd_to_display(bcd_time,led_array);
        //dummy_del++;
       // if(time.sec & 1 )
       // {
        //    blink_led_struct(led_array[0]);
       // }
    }
}





