TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-

OBJCOPY           = $(TOOLCHAIN_PREFIX)objcopy
LD                = $(TOOLCHAIN_PREFIX)ld
AS                = $(TOOLCHAIN_PREFIX)as
GCC               = $(TOOLCHAIN_PREFIX)gcc

all:
	$(GCC) -O0 -ggdb -nostdlib -nostartfiles -ffreestanding -march=rv32i1 -mabi=ilp32 \
	-Wl,-Tmain.ld main.c start.S -o main.elf
	$(OBJCOPY) -O binary main.elf main.bin

debug:
	qemu-system-riscv32 -S -M virt -bios none -kernel main.elf -gdb tcp::1234

gdb:
	gdb-multiarch -q main.elf -ex "target remote localhost:1234" \
	-ex "break _start" -ex "continue"

.PHONY: clean
clean:
	rm -rf *.elf *.bin
