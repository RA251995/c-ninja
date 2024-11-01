.section .init
.globl _start
_start:
    la sp, _STACK_TOP_
    jal main
    j .
