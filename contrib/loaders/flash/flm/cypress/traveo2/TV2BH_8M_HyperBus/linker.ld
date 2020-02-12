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
	} :PrgAndData

	PrgData :
	{
		*(.rodata EXCLUDE_FILE(*FlashDev.o) .rodata*)
		*(.data .data.*)
		*(.bss .bss.*)
		*(.got .got*)
	} :PrgAndData

	DevDscr :
	{
		*(.rodata.FlashDevice)
	} :DevDscr

	/DISCARD/ :
	{
		*(.init)
		*(.fini)
		*(.ARM.attributes)
		*(.comment)
		*(COMMON)
	}
}
