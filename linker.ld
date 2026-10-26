ENTRY(_start)

SECTIONS {
    . = 0x0;
    . = ALIGN(4096);
    .text : { *(.text*) }

    .rodata : ALIGN(4096) { *(.rodata*) }

    .data : ALIGN(4096) { *(.data*) }

    .bss : ALIGN(4096) { *(.bss*) }
}