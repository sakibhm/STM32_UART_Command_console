#ifndef uart_HG
#define uart_HG
#include <stdint.h>
void USART1_CR1_UE_ENABLE(void);
void USART1_CR1_TX_ENABLE(void);
void USART1_CR1_RX_ENABLE(void);
void USART1_SET_BRR(uint16_t BAUD);

void USART1_WaitTxe(void);
void USART1_WaitRxne(void);
 
#endif