TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-

OBJCOPY           = $(TOOLCHAIN_PREFIX)objcopy
LD                = $(TOOLCHAIN_PREFIX)ld
AS                = $(TOOLCHAIN_PREFIX)as
GCC               = $(TOOLCHAIN_PREFIX)gcc

all:
	$(GCC) -O0 -ggdb -nostdlib -nostartfiles -ffreestanding -march=rv32i1 -mabi=ilp32 \
	-Wl,-Tmain.ld main.c start.S -o main.elf
	$(OBJCOPY) -O binary main.elf main.bin

run:
	qemu-system-riscv32 -M virt -nographic -bios none -kernel main.bin

.PHONY: clean
clean:
	rm -rf *.elf *.bin
