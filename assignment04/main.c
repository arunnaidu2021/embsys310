#include "stack.h"
#include<stdio.h>


int main()
{
  // Contains tests for stack function  
  
  //***********************************
  // test initialize
  stackInit();  
  
 //***********************************
  // test push
  if( pushStack( 47 ) )
     printf("Stack full\n");
  if( pushStack( 4 ) )
     printf("Stack full\n");
  if( pushStack( 7 ) )
     printf("Stack full\n");
  
  // test is full
  if( pushStack( 47 ) )
     printf("Stack full\n");

   
  //***********************************
  // test pop
    printf( "%d\n", popStack() );
    printf( "%d\n", popStack() );
    printf( "%d\n", popStack() );
    
    
  //***********************************
  // test isempty
  if (popStack() == 1)
      printf("Stack empty\n");
  
  //***********************************
  // test error
  return 0;
}
