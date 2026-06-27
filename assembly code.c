     9: void main() 
    10: { 
    11:         unsigned char count=0; 
    12:         P3 = 0xFF; 
C:0x0800    75B0FF   MOV      P3(0xB0),#0xFF
    13:         while(1) 
    14:         { 
    15:                 for(count=0;count<=15;count++) 
C:0x0803    E4       CLR      A
C:0x0804    FB       MOV      R3,A
    16:                 { 
    17:                         P3 = count; 
C:0x0805    8BB0     MOV      P3(0xB0),R3
    18:                   delay(20000); 
C:0x0807    7F20     MOV      R7,#0x20
C:0x0809    7E4E     MOV      R6,#0x4E
C:0x080B    120814   LCALL    delay(C:0814)
    19:                 } 
C:0x080E    0B       INC      R3
C:0x080F    BB10F3   CJNE     R3,#0x10,C:0805
C:0x0812    80EF     SJMP     C:0803
     3: void delay(unsigned int k) 
     4: { 
     5:         unsigned int i; 
     6:         for(i=0;i<=k;i++); 
C:0x0814    E4       CLR      A
C:0x0815    FD       MOV      R5,A
C:0x0816    FC       MOV      R4,A
C:0x0817    D3       SETB     C
C:0x0818    ED       MOV      A,R5
C:0x0819    9F       SUBB     A,R7
C:0x081A    EC       MOV      A,R4
C:0x081B    9E       SUBB     A,R6
C:0x081C    5007     JNC      C:0825
C:0x081E    0D       INC      R5
C:0x081F    BD0001   CJNE     R5,#0x00,C:0823
C:0x0822    0C       INC      R4
C:0x0823    80F2     SJMP     C:0817
     7: } 
C:0x0825    22       RET      
C:0x0826    787F     MOV      R0,#0x7F
C:0x0828    E4       CLR      A
C:0x0829    F6       MOV      @R0,A
C:0x082A    D8FD     DJNZ     R0,C:0829
C:0x082C    758107   MOV      SP(0x81),#0x07
C:0x082F    020800   LJMP     main(C:0800)
