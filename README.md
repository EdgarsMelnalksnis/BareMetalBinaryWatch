# BareMetalBinaryWatch
In this project I will follow STM32 Bare Metal Programming tutorial (https://vivonomicon.com/2018/04/02/bare-metal-stm32-programming-part-1-hello-arm/) and adapt it to my MCU (STM32L031K6)
ToDo:
1)Write function that takes time as argument and displays it on binary watch;
2)Configure RTC to track time;
3)Write better make file;
4)Configure sleep mode and interrupts to improve current consumption;

Debbuging with GDB: 
1.in console write st-util;
2.in second terminal, write gdb xxxx.elf (newer versions don`t need arm-none-eabi-gdb);
3.in gdb write: target extended-remote :4242
4.(gdb)load
5.(gdb) continue (starts program execution)
(gdb) info registers prints registers
(gdb) p /t TIM3->CCMR1 prints register value in binary
