#define RCC_BASE 0x40021000
#define RCC_AHB2EN (*((unsigned int*) (RCC_BASE + 0x4C)))
#define GPIOA_BASE 0x48000000
#define GPIOA_MODE (*((unsigned int*) (GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

volatile int counter = 0;

void longBurst( void );
void shortBurst( void );

void shortBurst( void )
{
    // Set output to 1 = LED ON
    GPIOA_ODR = 0x0020;  
    
    for( counter = 0; counter < 100000; counter++ ); // short ON delay
    
    // Set output to 0 = LED OFF
    GPIOA_ODR = 0x0000;     
    
    for( counter = 0; counter < 100000; counter++ ); // short OFF delay
}

void longBurst( void )
{
    // Set output to 1 = LED ON
    GPIOA_ODR = 0x0020;  
    
    for( counter = 0; counter < 400000; counter++ ); // long ON delay
    
    // Set output to 0 = LED OFF
    GPIOA_ODR = 0x0000;     
    
    for( counter = 0; counter < 100000; counter++ ); // short OFF delay
}


int main()
{
  // Enable the clock to GPIO Port B, bit 1
  RCC_AHB2EN |= 1;
  
  // Set the port to output, bit 10/11
  GPIOA_MODE = 0x0400;
  
  // Blink name in Morse code
  while(1)
  {  
    shortBurst(); longBurst();                  // 'A'
    shortBurst(); longBurst(); shortBurst();    // 'R'
    shortBurst(); shortBurst(); longBurst();    // 'U'
    longBurst(); shortBurst();                  // 'N'
    
  }
  return 0;
}
