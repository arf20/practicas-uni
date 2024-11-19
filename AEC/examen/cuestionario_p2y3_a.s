.data
    x: .word 0,1,2,3,4,5,6,7,8,9
       .word 10,11,12,13,14,15
    a: .word 0,1,2,3,4,5,6,7,8,9
       .word 10,11,12,13,14,15
    ; Vector y
    ; 16 elementos son 64 bytes.
    y: .space 64

; El código
.text

start:
    add r4,r0,#64 ; 16*4
    add r5,r0,a
    add r2,r0,y
    add r1,r0,x

loop:
    lw r3, 0(r1)
    lw r6, 0(r5)
    add r5, r5, #4
    sub r4, r4, #4
    add r7, r6, #8
    add r1, r1, #4
    add r6, r3, r6
    add r3, r3, #1
    subi r7, r6, #8
    sw 0(r2), r6
    add r2, r2, #4
    add r7, r7, r2
    bnez r4,loop
    trap #0 ; Fin de programa

