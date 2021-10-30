1.  With counter a signed integer, injecting 0x7FFFFFFF and stepping once, the counter goes to \
    a) 0x80000000 in the Locals window.\
    b) 0x80000000 in the Registers window.\
    c) The N and V flags are set in the APSR register, indicating that the resulting value is negative and a signed overflow. 
    
2.  With counter a signed integer, injecting 0xFFFFFFFF and stepping once, the counter rolls over to \
    a) 0x00000000 in the Locals window.\
    b) The Z and C flags are set in the APSR register, indicating that the resulting value is zero and the carry flag.     
    
3 and 4.  With counter an unsigned integer, the behaviour remains the same as in 1 and 2.  This isn't what I expected,
          but I suspect the hardware behaves the same, regardless of the software interpretation.
		  
5.  With the counter variable outside of main:
	a)  The counter variable has global scope.\
	b)  It is not visible in the locals view.\
	c)  We have to track counter in the register view.\
	d)  The address of counter is 0x20000000. 
	
6.  Pointer manipulation:
	a)  The value of counter at the end of the program is 4.\
	b)  We have incremented the quantity at the address of counter.
	
7.  IAR version:
	a)  Address is the same, 0x20000000.\
 	b)  The counter is modified and therefore must be stored in RAM.\
	c)  The value of counter at the end of the program is 4.
	
	
		  
		  
