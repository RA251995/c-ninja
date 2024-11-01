TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-

OBJCOPY           = $(TOOLCHAIN_PREFIX)objcopy
LD                = $(TOOLCHAIN_PREFIX)ld
AS                = $(TOOLCHAIN_PREFIX)as
GCC               = $(TOOLCHAIN_PREFIX)gcc

all: asm_gen_without_m_ext
	$(GCC) -O0 -nostdlib -nostartfiles -ffreestanding -march=rv32i1 -mabi=ilp32 functions.s mul.s

asm_gen_without_m_ext:
	$(GCC) -O0 -nostdlib -nostartfiles -ffreestanding -march=rv32i1 -mabi=ilp32 -S functions.c

asm_gen_with_m_ext:
	$(GCC) -O0 -nostdlib -nostartfiles -ffreestanding -march=rv32im1 -mabi=ilp32 -S functions.c

.PHONY: clean
clean:
	rm -rf functions.s *.out
