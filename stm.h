#ifndef STM32
#define STM32

#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)
#define RCC_APB2ENR   (*(volatile unsigned int*)0x40023844)

#define GPIOA_MODER   (*(volatile unsigned int*)0x40020000)
#define GPIOA_AFRH    (*(volatile unsigned int*)0x40020024)
#define GPIOA_ODR     (*(volatile unsigned int*)0x40020014)

#define USART1_SR     (*(volatile unsigned int*)0x40011000)
#define USART1_DR     (*(volatile unsigned int*)0x40011004)
#define USART1_BRR    (*(volatile unsigned int*)0x40011008)
#define USART1_CR1    (*(volatile unsigned int*)0x4001100C)


#endif
