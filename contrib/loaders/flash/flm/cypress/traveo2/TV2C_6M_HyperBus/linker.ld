EXTERN(Init)
EXTERN(UnInit)
EXTERN(EraseSector)
EXTERN(ProgramPage)
EXTERN(BlankCheck)
EXTERN(EraseChip)
EXTERN(Verify)
EXTERN(FlashDevice)

PHDRS
{
  PrgAndData PT_LOAD;
  DevDscr PT_LOAD;
}

SECTIONS
{
	PrgCode :
	{
		*(.text .text.*)
		*(.rodata EXCLUDE_FILE(*FlashDev.o) .rodata*)
		*(.rdata)
	} :PrgAndData

	PrgData :
	{
		QUAD(0xA5A5A5A5) /* Force this section to have PT_LOAD attribute */
		*(.data .data.*)
		*(.bss .bss.*)
		QUAD(0x5A5A5A5A) /* Force this section to have PT_LOAD attribute */
	} :PrgAndData

	DevDscr :
	{
		*(.rodata.FlashDevice)
	} :DevDscr

	/DISCARD/ :
	{
		*(.got .got*)
		*(.plt .plt*)
		*(COMMON)
		*(.init)
		*(.fini)
		*(.ARM.attributes)
		*(.comment)
	}
}
