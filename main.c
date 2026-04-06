#include "stm.h"
#include "string.h"
#include "stdint.h"
#include "rcc.h"
#include "gpioa.h"
#include "led.h"
#include "uart.h"

/*typedef struct{
    char* name;
    char* desc;
} command;

command commands[] = {
    {">led on","-turns on the LED"},
    {">led off","-turns off the LED"},
    {">help","-shows list of all commands"}
};*/

void print_cmd(void)
{
    typedef struct{
    char* name;
    char* desc;
} command;

command commands[] = {
    {">led on","-turns on the LED"},
    {">led off","-turns off the LED"},
    {">help","-shows list of all commands"}
};
    int c= 0;
    while(c <3 )
    {
        int n = 0;
        while(commands[c].name[n] != '\0')
        {
        USART1_WaitTxe();
        USART1_DR = commands[c].name[n];    //prints the name of command
        n++;
        }

        int z = 0;
        while(commands[c].desc[z] != '\0')
        {
        USART1_WaitTxe();
        USART1_DR = commands[c].desc[z];    //prints the description
        z++;
        }

        c++;

        USART1_WaitTxe();
        USART1_DR = '\r';

        USART1_WaitTxe();
        USART1_DR = '\n';
    }
    
}



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

        if(data == '\r')
        {
            USART1_WaitTxe();
            USART1_DR = '\r';

            USART1_WaitTxe();
            USART1_DR = '\n';

        }
        else
        {USART1_WaitTxe();
         USART1_DR = data;
        }


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
            else if(strcmp(buffer,"help") == 0)
            {
               print_cmd();
               
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
                USART1_WaitTxe();
                USART1_DR = '\r';

                USART1_WaitTxe();
                USART1_DR = '\n';

            }
        }

    }
    
}