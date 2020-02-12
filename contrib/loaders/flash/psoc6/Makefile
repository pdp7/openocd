BIN2C = ../../../../src/helper/bin2char.sh

CROSS_COMPILE ?= arm-none-eabi-

CC=$(CROSS_COMPILE)gcc
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

CFLAGS =  -c -mthumb -mcpu=cortex-m0plus -Os

all: psoc6_write.inc psoc62m_write.inc tv2_write.inc

.PHONY: clean

.INTERMEDIATE: psoc6_write.o psoc62m_write.o tv2_write.o

tv2_write.o: psoc6_write.c
	$(CC) $(CFLAGS) -DMXS40_VARIANT=MXS40_VARIANT_TRAVEO_II -Wall -Wextra -Wa,-adhln=$*.lst $< -o $@

psoc6_write.o: psoc6_write.c
	$(CC) $(CFLAGS) -DMXS40_VARIANT=MXS40_VARIANT_PSOC6A_BLE -Wall -Wextra -Wa,-adhln=$*.lst $< -o $@

psoc62m_write.o: psoc6_write.c
	$(CC) $(CFLAGS) -DMXS40_VARIANT=MXS40_VARIANT_PSOC6A_2M -Wall -Wextra -Wa,-adhln=$*.lst $< -o $@

%.bin: %.o
	$(OBJCOPY) -Obinary $< $@

%.inc: %.bin
	$(BIN2C) < $< > $@

clean:
	-rm -f *.o *.lst *.bin *.inc
