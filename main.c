#include "stm32l031xx.h"
#include "led.h"
#include "config.h"

uint8_t button_flag;


void EXTI2_3_IRQ_handler(void)
{
    if(EXTI -> PR & (1<<BUTTON))
    {
        EXTI->PR |= ( 1 << BUTTON);
        button_flag=1;
    }

}


int main(void)
{
    uint32_t bcd_time=0;
    uint32_t del_cntr=0;
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

    GPIOA -> MODER &=~ (1<<5|1<<4);//GPIOA input mode
    GPIOA -> PUPDR |= (1<<5);//GPIOA2 pulldown

    RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    SYSCFG -> EXTICR[(BUTTON/4)] &=~ ((0xF << (BUTTON % 4) * 4 ));
    SYSCFG -> EXTICR[(BUTTON/4)] &=~ ((0x0 << (BUTTON % 4) * 4 ));    EXTI -> IMR |=(1 << BUTTON);
    EXTI -> RTSR |= (1 << BUTTON);
    EXTI -> FTSR &= ~(1 << BUTTON);
    NVIC_SetPriority(EXTI2_3_IRQn,0x03);
    NVIC_EnableIRQ(EXTI2_3_IRQn);

    while(1)
    {
        bcd_time = RTC -> TR;
        bcd_to_display(bcd_time,led_array);
        if(button_flag || del_cntr)
        {
            button_flag=0;
                led_test();
            del_cntr++;
            if(del_cntr>1000)
            {
                del_cntr=0;
            }
        }
    }
}
