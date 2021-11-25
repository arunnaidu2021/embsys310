#include<stdio.h>
int x; 
int y;

void swap_pointer(int *xpoint, int *ypoint);

void swap_pointer(int *xpoint, int *ypoint)
{
  int temp;
  temp = *xpoint;
  *xpoint = *ypoint;
  *ypoint = temp;
  
}

void main(void)
{
  x = 11;
  y = 15;
  
  printf( "x = %d\ty = %d\n", x, y );
  
  swap_pointer(&x, &y);
  
  printf( "x = %d\ty = %d\n", x, y );
}

