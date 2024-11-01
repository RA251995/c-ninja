    .text
    .align 2
    .globl __mulsi3
    .type __mulsi3, @function
__mulsi3:
    addi sp, sp, -48
    sw ra, 44(sp)
    sw s0, 40(sp)

    mv t0, a0
    mv t1, a1
    addi t2, zero, 0

loop:
    add t2, t2, t0
    addi t1, t1, -1
    bnez t1, loop

    mv a0, t2

    lw s0, 40(sp)
    lw ra, 44(sp)
    addi sp, sp, 48
    jr ra
    .size __mulsi3, .-__mulsi3
