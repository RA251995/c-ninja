MEMORY
{
    RAM : ORIGIN = 0x80000000, LENGTH = 4k
}

SECTIONS
{
    .text : {
        *(.init*)
        *(.text*)
    } > RAM
}

PROVIDE(_STACK_TOP_ = ORIGIN(RAM) + LENGTH(RAM) + 4);
