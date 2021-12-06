#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

volatile int counter=0;

void main(void)
{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x4800000
    // Address offset: 0x00
    // Set bit[10:11] to 0x01 / To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit to 1 --> 0x0020; // Turn LED ON
    // Set bit to 0 --> 0x0000; // Turn LED OFF
    
    while(1)  // slow blink loop
    {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(1000000);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }    
}