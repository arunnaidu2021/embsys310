#include "stack.h"
#define STACK_SIZE 3

// allocate stack space
int Stack[STACK_SIZE];

// Pointer to push and pop elements
int *PushPopPtr;



// Initialize stack
void stackInit( void )
{
  PushPopPtr = Stack;
  for( int i = 0; i < STACK_SIZE; i++ )
    Stack[i] = '\0';
}

int pushStack( int data )
{
  if( PushPopPtr > (&Stack[0] + ((STACK_SIZE-1)*4)) ) //check if stack is full
    return 1;
  
  *PushPopPtr = data;  // Push data
  
  PushPopPtr++; // increment pointer
  return 0;
}

int popStack( void )
{
  if( PushPopPtr == Stack ) // check if stack is empty
    return 1;
  
  PushPopPtr--;  // decrement pointer
  return *PushPopPtr;
}

