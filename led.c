#include "stm.h"
#include "led.h"

void LED_ON(void)
{
    GPIOA_ODR |= (1<<5);
    //led on

}

void LED_OFF(void)
{
    GPIOA_ODR &= ~(1<<5);
    //led off


}