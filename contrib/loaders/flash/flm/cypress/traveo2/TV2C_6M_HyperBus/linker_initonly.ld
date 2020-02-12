ENTRY(Init)

PHDRS
{
  PrgAndData PT_LOAD;
}

SECTIONS
{
	PrgCode :
	{
		*(.start*)
		*(.text .text.*)
	} :PrgAndData

	PrgData :
	{
		QUAD(0xA5A5A5A5) /* Force this section to have PT_LOAD attribute */
		*(.rodata EXCLUDE_FILE(*FlashDev.o) .rodata*)
		*(.data .data.*)
		*(.bss .bss.*)
		QUAD(0xA5A5A5A5) /* Force this section to have PT_LOAD attribute */
	} :PrgAndData

	/DISCARD/ :
	{
		*(.got .got*)
		*(.rodata.FlashDevice)
		*(.init)
		*(.fini)
		*(.ARM.attributes)
		*(.comment)
		*(COMMON)
	}
}
