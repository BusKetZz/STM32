ENTRY(reset_handler)

MEMORY
{
	FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
	SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

__max_heap_size = 0x400;
__max_stack_size = 0x200;



SECTIONS
{
	.text:
	{
		*(.isr_vector)
		*(.text)
		*(.rodata)
		_etext = .;
	}> FLASH

	.data:
	{
		_sdata = .;
		*(.data)
		_edata = .;
	}> SRAM AT> FLASH

	.bss:
	{
		_sbss = .;
		*(.bss)
		_ebss = .;
	}> SRAM
}

