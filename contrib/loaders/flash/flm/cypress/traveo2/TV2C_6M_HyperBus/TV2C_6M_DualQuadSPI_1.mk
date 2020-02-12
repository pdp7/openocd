APPLICATION := TV2C_6M_DualQuadSPI_1
CPU_FLAGS   := -mthumb -mcpu=cortex-m0plus -msoft-float
GLOBAL_DEFS := -DCY_USE_PSVP=1 -Dtviic2d6m=1 -DTVIIC2D6M -DDUAL_QUAD_SPI -DSMIF_CH_1

DEBUG         := 0
VERBOSE_BUILD := 1

INCLPATHS := \
	-I. \
	-I./tviic2d6m \
	-I./tviic2d6m/src \
	-I./tviic2d6m/src/system \
	-I./tviic2d6m/src/drivers \
	-I./tviic2d6m/src/drivers/sysclk \
	-I./tviic2d6m/src/drivers/smif \
	-I./tviic2d6m/src/mw/smif_mem \
	-I./tviic2d6m/hdr \
	-I./tviic2d6m/hdr/ip \
	-I./tviic2d6m/hdr/mcureg \
	-I./common \
	-I./common/src \
	-I./common/src/drivers \
	-I./common/src/drivers/ipc \
	-I./common/src/drivers/syslib \
	-I./common/src/drivers/gpio \
	-I./common/src/drivers/syswdt \
	-I./common/src/drivers/sysint \
	-I./common/hdr \
	-I./common/hdr/cmsis \
	-I./common/hdr/cmsis/include \

#./tviic2d6m/src/mw/smif_mem/cy_smif_s25fl.c \
#	./tviic2d6m/src/mw/smif_mem/cy_smif_hb_flash.c \
#	./tviic2d6m/src/mw/smif_mem/cy_smif_device_common.c \
#	./tviic2d6m/src/mw/smif_mem/cy_smif_s28h.c \
#	./tviic2d6m/src/drivers/smif/cy_smif_memslot.c \
#	./tviic2d6m/src/drivers/smif/cy_smif.c \
#	./tviic2d6m/src/system/system_tviic2d6m_cm0plus.c \
#	./common/src/drivers/syslib/cy_syslib.c \
#	./common/src/drivers/gpio/cy_gpio.c \
#	./common/src/drivers/syswdt/cy_syswdt.c \

CC_SRC    := \
	./dualquadspi.c \
	./FlashDev.c \


AS_SRC    :=

LDSCRIPT  := \
				  ./linker.ld

OUT_DIR   := ../../../../../../../flm/cypress/traveo2/
