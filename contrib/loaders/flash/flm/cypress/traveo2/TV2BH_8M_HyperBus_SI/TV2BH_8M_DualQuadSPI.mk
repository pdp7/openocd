APPLICATION := TV2BH_8M_DualQuadSPI_SI
CPU_FLAGS   := -mthumb -mcpu=cortex-m0plus -msoft-float
GLOBAL_DEFS := -DCY_USE_PSVP=0 -DCYT4BF8CDE -Dtviibh8m -DDUAL_QUAD_SPI

DEBUG         := 0
VERBOSE_BUILD := 1

INCLPATHS := \
	-I.													 \
	-I./src												 \
	-I./src/common										 \
	-I./src/common/src									 \
	-I./src/common/src/drivers							 \
	-I./src/common/src/drivers/ipc						 \
	-I./src/common/src/drivers/syslib					 \
	-I./src/common/src/drivers/gpio						 \
	-I./src/common/src/drivers/syswdt					 \
	-I./src/common/src/drivers/sysint					 \
	-I./src/common/src/drivers/syspm					 \
	-I./src/common/src/drivers/systick					 \
	-I./src/common/hdr									 \
	-I./src/common/hdr/cmsis							 \
	-I./src/common/hdr/cmsis/include					 \
	-I./src/tviibh8m									 \
	-I./src/tviibh8m/src								 \
	-I./src/tviibh8m/src/system							 \
	-I./src/tviibh8m/src/drivers						 \
	-I./src/tviibh8m/src/drivers/sysclk					 \
	-I./src/tviibh8m/src/drivers/smif					 \
	-I./src/tviibh8m/src/drivers/sysreg					 \
	-I./src/tviibh8m/src/mw								 \
	-I./src/tviibh8m/src/mw/reghc						 \
	-I./src/tviibh8m/src/mw/smif_mem					 \
	-I./src/tviibh8m/hdr								 \
	-I./src/tviibh8m/hdr/ip								 \
	-I./src/tviibh8m/hdr/mcureg							 \



CC_SRC    := \
	./src/common/src/drivers/ipc/cy_ipc_config.c		 \
	./src/common/src/drivers/ipc/cy_ipc_sema.c			 \
	./src/common/src/drivers/ipc/cy_ipc_drv.c			 \
	./src/common/src/drivers/ipc/cy_ipc_pipe.c			 \
	./src/common/src/drivers/syslib/cy_syslib.c			 \
	./src/common/src/drivers/gpio/cy_gpio.c				 \
	./src/common/src/drivers/syswdt/cy_syswdt.c			 \
	./src/common/src/drivers/sysint/cy_sysint.c			 \
	./src/common/src/drivers/syspm/cy_syspm.c			 \
	./src/common/src/drivers/systick/cy_systick.c		 \
	./src/tviibh8m/src/system/system_tviibh8m_cm0plus.c	 \
	./src/tviibh8m/src/drivers/sysclk/cy_sysclk.c		 \
	./src/tviibh8m/src/drivers/smif/cy_smif_memslot.c	 \
	./src/tviibh8m/src/drivers/smif/cy_smif.c			 \
	./src/tviibh8m/src/drivers/sysreg/cy_sysreg.c		 \
	./src/tviibh8m/src/mw/reghc/cy_reghc.c				 \
	./src/tviibh8m/src/mw/smif_mem/cy_smif_s25fl.c		 \
	./src/tviibh8m/src/mw/smif_mem/cy_smif_hb_flash.c	 \
	./FlashDev.c										 \
	./dualquadspi.c										 \



AS_SRC    :=

LDSCRIPT  := \
		  ./linker.ld

OUT_DIR   := ../../../../../../../flm/cypress/traveo2/
