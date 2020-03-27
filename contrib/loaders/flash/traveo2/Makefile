ifeq (x$(TARGET),x)
$(error TARGET variable not defined!)
endif

APPLICATION := $(TARGET)
CPU_FLAGS   := -mthumb -mcpu=cortex-m0plus -msoft-float
include $(TARGET).mk

LDSCRIPT  ?= flm/flm_linker_script.ld

OUT_DIR   :=  out
VERBOSE_BUILD ?= 0

CROSS_COMPILE ?= arm-none-eabi-

CC_SRC := $(APPLICATION).c flm/FlashDev.c
AS_SRC    :=

CC       := $(CROSS_COMPILE)gcc
AS       := $(CROSS_COMPILE)gcc -x assembler-with-cpp
LD       := $(CROSS_COMPILE)ld
SIZE     := $(CROSS_COMPILE)size
READELF  := $(CROSS_COMPILE)readelf
OBJCOPY  := $(CROSS_COMPILE)objcopy
OBJDUMP  := $(CROSS_COMPILE)objdump
STRIP    := $(CROSS_COMPILE)strip

CC_OBJ   := $(CC_SRC:.c=.o)
AS_OBJ   := $(AS_SRC:.s=.o)
OBJ      := $(CC_OBJ) $(AS_OBJ)
DEPFILES := $(OBJ:.o=.d)

BUILD_DATE := $(shell LC_ALL=C date "+%D %H:%M")
OUT_DIR    ?= out/

##############################################################################################################################
# Debug/Release options
##############################################################################################################################
OPTFLAGS := -Os
GLOBAL_DEFS += -DNDEBUG 
##############################################################################################################################
# Warning options
##############################################################################################################################
CC_WARN := -Wall -Wextra -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-return-type -Wno-maybe-uninitialized \
			-Wno-comment -Wno-unused-parameter -Wno-expansion-to-defined

##############################################################################################################################
# Code generation options
##############################################################################################################################
CMN_CODEGEN := -ffunction-sections -fdata-sections -fsingle-precision-constant -ffast-math -fmerge-all-constants \
			   -fstrict-overflow -fno-math-errno -fvisibility=hidden -frename-registers -fpeel-loops -fsection-anchors

CC_CODEGEN  := $(CMN_CODEGEN)

##############################################################################################################################
# Complete command lines
##############################################################################################################################
CFLAGS      := -std=c11   $(CC_WARN)  $(CC_CODEGEN)  $(CPU_FLAGS) $(OPTFLAGS) $(INCLPATHS) $(GLOBAL_DEFS)
LDFLAGS     := $(CPU_FLAGS) $(OPTFLAGS) $(GLOBAL_DEFS) -T$(LDSCRIPT) -Wl,--gc-sections,--warn-common,--nmagic \
			--specs=nano.specs --specs=nosys.specs

CFLAGS  += -fpic -msingle-pic-base -mpic-data-is-text-relative -mpic-register=r9 -fno-common -fomit-frame-pointer -fwhole-program -static

##############################################################################################################################
# Build recipes
##############################################################################################################################
.PHONY: all clean

all: $(OUT_DIR)/$(APPLICATION).elf
ifeq ($(VERBOSE_BUILD), 1)
	@echo
	@echo ------------------ Functions ------------------
	@$(READELF) -s $(OUT_DIR)/$(APPLICATION).elf | grep FUNC | sort -k 3,3 -r -n | head -n 5 | awk '{printf " %-36.36s %-8.8s\n", $$8, $$3}'
	@echo ------------------ Variables ------------------
	@$(READELF) -s $(OUT_DIR)/$(APPLICATION).elf | grep OBJECT | sort -k 3,3 -r -n | head -n 5 | awk '{printf " %-36.36s %s\n", $$8, $$3}'
	@echo -----------------------------------------------
endif
	@$(SIZE) $(OUT_DIR)/$(APPLICATION).elf | tail -n 1 | awk '{printf "\nFlash: %8.8s\nRAM:   %8.8s\n\n", $$1+$$2, $$2+$$3}'
	@$(OBJDUMP) -DlS $(OUT_DIR)/$(APPLICATION).elf > $(OUT_DIR)/$(APPLICATION).s

clean:
	@echo Cleaning up...
	@find -L  -type f -name "*.[od]" -delete
	@rm -f $(OUT_DIR)/$(APPLICATION).s $(OUT_DIR)/$(APPLICATION).elf

$(OUT_DIR)/$(APPLICATION).elf:$(OBJ)
	@echo [$(TARGET): ld ] $(APPLICATION).elf
	@mkdir -p $(OUT_DIR)
	@$(CC) $(LDFLAGS) $(OBJ) -o $(OUT_DIR)/$(APPLICATION).elf
	@$(STRIP) --strip-debug $(OUT_DIR)/$(APPLICATION).elf
	@find -L  -type f -name "*.[od]" -delete

%.o:%.c
	@echo [$(TARGET): gcc] `basename $*.c`
	@$(CC) $(CFLAGS) -MMD -c $*.c -o $*.o

%.o:%.s
	@echo [$(TARGET): as ] `basename $*.s`
	@$(AS) $(CFLAGS) -MMD -c $*.s -o $*.o

-include $(DEPFILES)
