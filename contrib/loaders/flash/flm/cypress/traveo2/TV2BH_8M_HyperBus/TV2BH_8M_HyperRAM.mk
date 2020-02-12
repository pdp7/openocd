APPLICATION := TV2BH_8M_HyperRAM
CPU_FLAGS   := -mthumb -mcpu=cortex-m0plus -msoft-float
GLOBAL_DEFS := -DCY_USE_PSVP=1 -DCYT4BFCCHE -Dtviibh8m -DHYPER_RAM
#GLOBAL_DEFS := -DCY_USE_PSVP=0 -DCYT4BF8CES -Dtviibh8m -DHYPER_RAM

DEBUG         := 0
VERBOSE_BUILD := 1

INCLPATHS := \
	-I. \
	-I./system \
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
	-I./tviibh8m \
	-I./tviibh8m/src \
	-I./tviibh8m/src/system \
	-I./tviibh8m/src/drivers \
	-I./tviibh8m/src/drivers/sysclk \
	-I./tviibh8m/src/drivers/smif \
	-I./tviibh8m/src/mw/reghc \
	-I./tviibh8m/hdr \
	-I./tviibh8m/hdr/ip \
	-I./tviibh8m/hdr/mcureg


CC_SRC    := \
	./hyperbus.c \
	./common/src/drivers/gpio/cy_gpio.c \
	./system/system_tviibh8m_cm0plus.c \
	./common/src/drivers/syswdt/cy_syswdt.c \
	./tviibh8m/src/drivers/smif/cy_smif_hb_flash.c \
	./tviibh8m/src/drivers/smif/cy_smif.c \
	./tviibh8m/src/drivers/sysreg/cy_sysreg.c \
	./tviibh8m/src/mw/reghc/cy_reghc.c


AS_SRC    :=

LDSCRIPT  := \
		  ./linker_initonly.ld

OUT_DIR   := ../../../../../../../flm/cypress/traveo2/
