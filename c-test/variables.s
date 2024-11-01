	.file	"variables.c"
	.option nopic
	.attribute arch, "rv32i1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	global_initialized_integer
	.section	.sdata,"aw"
	.align	2
	.type	global_initialized_integer, @object
	.size	global_initialized_integer, 4
global_initialized_integer:
	.word	123456789
	.globl	global_uninitialized_char
	.section	.sbss,"aw",@nobits
	.type	global_uninitialized_char, @object
	.size	global_uninitialized_char, 1
global_uninitialized_char:
	.zero	1
	.text
	.align	2
	.globl	_start
	.type	_start, @function
_start:
	addi	sp,sp,-48
	sw	s0,44(sp)
	addi	s0,sp,48
	li	a5,97
	sb	a5,-17(s0)
	lui	a5,%hi(global_initialized_integer)
	lw	a5,%lo(global_initialized_integer)(a5)
	sw	a5,-24(s0)
	lui	a5,%hi(.LC0)
	lw	a5,%lo(.LC0)(a5)
	sw	a5,-28(s0)
	lui	a5,%hi(.LC1)
	lw	a4,%lo(.LC1)(a5)
	lw	a5,%lo(.LC1+4)(a5)
	sw	a4,-40(s0)
	sw	a5,-36(s0)
	lui	a5,%hi(global_uninitialized_char)
	lbu	a4,-17(s0)
	sb	a4,%lo(global_uninitialized_char)(a5)
	lui	a5,%hi(global_uninitialized_char)
	li	a4,2
	sb	a4,%lo(global_uninitialized_char)(a5)
	nop
	mv	a0,a5
	lw	s0,44(sp)
	addi	sp,sp,48
	jr	ra
	.size	_start, .-_start
	.section	.sdata
	.align	2
	.type	static_integer.0, @object
	.size	static_integer.0, 4
static_integer.0:
	.word	987654321
	.section	.rodata
	.align	2
.LC0:
	.word	1067282596
	.align	3
.LC1:
	.word	-687194767
	.word	1070428323
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0"
