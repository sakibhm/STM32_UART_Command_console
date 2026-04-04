#include "stm.h"
#include "string.h"
#include "stdint.h"
#include "rcc.h"
#include "gpioa.h"
#include "led.h"
#include "uart.h"

int main (void)
{
    AHB1_CLK_ENABLE();  //AHB1 ENABLED
    APB2_CLK_ENABLE();  //APB2 ENABLED

    GPIOA_PA9_MODER_AF();   //SET PA9 TO AF MODE
    GPIOA_PA9_AF7();        //CONNECT PA9 TO AF7

    GPIOA_PA10_MODER_AF();  //SET PA10 TO AF MODE
    GPIOA_PA10_AF7();       //CONNECT PA10 TO AF7

    GPIOA_PA5_MODER_ODR();  //SET PA5 TO ODR MODE

    USART1_CR1_UE_ENABLE();
    USART1_CR1_TX_ENABLE();
    USART1_CR1_RX_ENABLE();

    USART1_SET_BRR(1667);

    char buffer[20];
    int index = 0;

    while(1)
    {
        USART1_WaitRxne();
        char data = USART1_DR;

        if(index < 19)
        {
            buffer[index] = data;
            index ++;
        }

        if(data == '\r' || data == '\n')
        {
            buffer[index-1] = '\0';
            index = 0;

            if(strcmp(buffer,"led on") == 0)
            {
                LED_ON();
            }
            else if(strcmp(buffer,"led off") == 0)
            {
                LED_OFF();

            }
            else
            {
                char print[] = "Unknown Command";
                int j = 0;
                
                while(print[j] != '\0')
                {
                    USART1_WaitTxe();
                    USART1_DR = print[j];
                    j ++;
                }
            }
        }

    }
    



}