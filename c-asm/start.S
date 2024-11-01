.section .init
.globl _start
_start:
    la sp, _STACK_TOP_
    addi x10, x0, 5
    addi x11, x0, 7 
    jal add_nums_in_c
    add x12, x0, x10
    j .
    