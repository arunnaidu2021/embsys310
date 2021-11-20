Assignment 4 Questions

1a.  Writing to the bit banding address creates the following assembly instructions:\
*((unsigned int*)(0x42000000+(0x2104C *32) + (0*4))) = 0x1;
   0x800'00ac: 0x2001         MOVS      R0, #1
   0x800'00ae: 0x4912         LDR.N     R1, [PC, #0x48]         ; 0x4242'0980
   0x800'00b0: 0x6008         STR       R0, [R1]
   
1b.  Writing the the RCC_AHB2ENR register without bit banding creates the following.  This is a read modify write cycle.\
  RCC_AHB2EN |= 1;
   0x800'00ac: 0x4813         LDR.N     R0, [PC, #0x4c]         ; RCC_AHB2ENR
   0x800'00ae: 0x6801         LDR       R1, [R0]
   0x800'00b0: 0xf051 0x0101  ORRS.W    R1, R1, #1
   0x800'00b4: 0x6001         STR       R1, [R0]
   
   
   
