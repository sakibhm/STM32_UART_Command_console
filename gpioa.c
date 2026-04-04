#include "stm.h"
#include "gpioa.h"

void GPIOA_PA9_MODER_AF(void)
{
    GPIOA_MODER &= ~(0b11<<18);
    GPIOA_MODER |=  (0b10<<18);
}

void GPIOA_PA10_MODER_AF(void)
{
    GPIOA_MODER &= ~(0b11<<20);
    GPIOA_MODER |=  (0b10<<20);
}

void GPIOA_PA9_AF7(void)
{
    GPIOA_AFRH &= ~(0b1111<<(9-8)*4);
    GPIOA_AFRH |=  (0b0111<<(9-8)*4);
}

void GPIOA_PA10_AF7(void)
{
    GPIOA_AFRH &= ~(0b1111<<(10-8)*4);
    GPIOA_AFRH |=  (0b0111<<(10-8)*4);
}

void GPIOA_PA5_MODER_ODR(void)
{
    GPIOA_MODER &= ~(0b11<<10);
    GPIOA_MODER |=  (0b01<<10);
    

}