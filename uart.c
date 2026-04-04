#include "stm.h"
#include "uart.h"

void USART1_CR1_UE_ENABLE(void)
{
    USART1_CR1 |= (1<<13);//enables uart

}

void USART1_CR1_RX_ENABLE(void)
{
    USART1_CR1 |= (1<<2);//enables RX
}

void USART1_CR1_TX_ENABLE(void)
{
    USART1_CR1 |= (1<<3);//enables TX
}

void USART1_BRR(void)
{
    USART1_BRR = 1667 ; //Baud rate = clk speed/baud rate.
}


void USART1_WaitTxe(void)
{
    while( !(USART1_SR & (1<<7) ) );
}

void USART1_WaitRxne(void)
{
    while( !(USART1_SR & (1<<5) ) );
}