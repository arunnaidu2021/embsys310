1.  With counter a signed integer, injecting 0x7FFFFFFF and stepping once, the counter goes to \
    a) 0x80000000 in the Locals window.\
    b) 0x  in the Registers window.\
    c) The N and V flags are set in the APSR register, indicating that the resulting value is negative and a signed overflow. 
    
2.  With counter a signed integer, injecting 0xFFFFFFFF and stepping once, the counter rolls over to \
    a) 0x00000000 in the Locals window.\
    b) The Z and C flags are set in the APSR register, indicating that the resulting value is zero and the carry flag.     
    
2.  With counter an unsigned integer,
    
