#include "stm32l031xx.h"
#include "led.h"
#include "config.h"

int main(void)
{
    uint32_t dummy_del=0;
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

    RCC->CSR |= 1 << RCC_CSR_RTCEN_Pos;

    int i=0;
    while(1)
    {
        dummy_del++;
        if(dummy_del>1000)//5000 for 1sec
        {
            dummy_del=0;
            i++;
            if(i>21) i=0;
        }
        blink_led_struct(*(led_array+i));

    }

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
}





