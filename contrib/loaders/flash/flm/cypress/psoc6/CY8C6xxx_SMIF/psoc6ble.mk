APPLICATION := CY8C6xxx_SMIF
CPU_FLAGS   := -mthumb -mcpu=cortex-m0plus -msoft-float
GLOBAL_DEFS := -DCY8C6xxx_SMIF -DPSOC6_1M

DEBUG         := 0
VERBOSE_BUILD := 0

INCLPATHS := \
		  -I. \
		  -I./cy_loader \
		  -I./cy_debug \
		  -I./cy_smif \
		  -I./cy_srom \
		  -I./cy_common

CC_SRC    := \
		  ./startUp.c \
		  ./cy_loader/cy_loader_smif.c \
		  ./cy_loader/cy_loader_base.c \
		  ./cy_loader/cy_loader_flash.c \
		  ./cy_debug/cy_debug.c \
		  ./cy_smif/cy_smif_memslot.c \
		  ./cy_smif/cy_smif.c \
		  ./cy_srom/cy_srom.c \
		  ./loader.c \
		  ./FlashDev.c \
		  ./FlashPrg.c \
		  ./cy_common/cy_common.c

AS_SRC    :=

LDSCRIPT  := \
          ./linker.ld

OUT_DIR   := ../../../../../../../flm/cypress/psoc6/
