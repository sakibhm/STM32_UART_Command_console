#include "stm.h"
#include "rcc.h"

void AHB1_CLK_ENABLE(void)
{
    RCC_AHB1ENR |= (1 << 0); // clock enable for GPIOA
}

void APB2_CLK_ENABLE(void)
{
    RCC_APB2ENR |= (1 << 4); // clock enable for USART1
}

