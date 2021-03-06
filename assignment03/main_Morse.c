#define RCC_BASE 0x40021000
#define RCC_AHB2EN (*((unsigned int*) (RCC_BASE + 0x4C)))
#define GPIOB_BASE 0x48000400
#define GPIOB_MODE (*((unsigned int*) (GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*) (GPIOB_BASE + 0x14)))

volatile int counter = 0;

void longBurst( void );
void shortBurst( void );

void shortBurst( void )
{
    // Set output to 1 = LED ON
    GPIOB_ODR = 0x4000;  
    
    for( counter = 0; counter < 100000; counter++ ); // short ON delay
    
    // Set output to 0 = LED OFF
    GPIOB_ODR = 0x0000;     
    
    for( counter = 0; counter < 100000; counter++ ); // short OFF delay
}

void longBurst( void )
{
    // Set output to 1 = LED ON
    GPIOB_ODR = 0x4000;  
    
    for( counter = 0; counter < 400000; counter++ ); // long ON delay
    
    // Set output to 0 = LED OFF
    GPIOB_ODR = 0x0000;     
    
    for( counter = 0; counter < 100000; counter++ ); // short OFF delay
}


int main()
{
  // Enable the clock to GPIO Port B
  RCC_AHB2EN ^= 1 << 1;
  
  // Set the port to output
  GPIOB_MODE  = 0x10000000;
  
  // Blink name in Morse code
  while(1)
  {  
    shortBurst(); longBurst();                  // 'A'
    shortBurst(); longBurst(); shortBurst();     // 'R'
    shortBurst(); shortBurst(); longBurst();    // 'U'
    longBurst(); shortBurst();                  // 'N'
    
  }
  return 0;
}
