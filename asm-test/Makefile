#
# Copyright 2023 inpyjama.com. All Rights Reserved.
# Author: Piyush Itankar <piyush@inpyjama.com>
#

TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-

OBJCOPY           = $(TOOLCHAIN_PREFIX)objcopy
LD                = $(TOOLCHAIN_PREFIX)ld
AS                = $(TOOLCHAIN_PREFIX)as
GCC               = $(TOOLCHAIN_PREFIX)gcc

all: main.s
	$(GCC)  -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tmain.ld main.s -o main.elf
	$(OBJCOPY) -O binary main.elf main.bin
	xxd -e -c 4 -g 4 main.bin

debug:
	qemu-system-riscv32 -S -M virt -bios none -kernel main.elf -gdb tcp::1234

gdb:
	gdb-multiarch main.elf \
	-ex "target remote localhost:1234" \
	-ex "break entry" -ex "continue" \
	-q

gdb_tui:
	gdb-multiarch main.elf \
	-ex "target remote localhost:1234" \
	-ex "tui new-layout custom {-horizontal src 1 asm 1} 1 status 0 regs 1 cmd 1" \
	-ex "tui enable" -ex "layout custom" \
	-ex "break entry" -ex "continue" \
	-q

.PHONY: clean
clean:
	rm -rf *.o *.elf *.bin *.out .gdb_history
