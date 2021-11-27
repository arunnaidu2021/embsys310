/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping chars
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm  // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  swaps chars
C Prototype     : int swapCharsAsm(char1, char2)
                : swap Char1 and Char2
Parameters      : R0 R1 char val
Return value    : R0  return comparison result
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0,R1,LR}        // save the input arguments and return address
    MOV R2, R1            // Move contents of Reg1 to Reg2        
    MOV R1, R0           // Move contents of Reg0 to Reg1
    MOV R0, R2          // Move contents of Reg2 to Reg0
    CMP R0, R1          // Compare the two values 
    BX LR               // return (with comparison result in R0)

    END
    
    
    
    
    
//    LDR R0,=myCstr      // load (global) address of address of string into R0
//    LDR R0,[R0]         // load address of string into R0
//    BL  PrintString     // call PrintString to print the string