ARCH = arm
CREATE_UIMG = ../utils/mkimage
CREATE_SD_CARD = ../utils/create-sd.sh
ENTRY_ADDR = 0x60000000
LOAD_ADDR  = 0x60000000
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
ELF2BIN = arm-none-eabi-objcopy
CFLAGS = -r -nostartfiles -g -Wall 
#LDFLAGS = -T link.ld -L /lib/gcc-cross/arm-linux-gnueabihf/13/ /lib/gcc-cross/arm-linux-gnueabihf/13/libgcc.a 
LDFLAGS = -T link.ld 


all:startup.bin bare-arm.uimg sdcard.img link.ld

startup.bin:startup.s cstart.c uart_pl011.c
	$(AS) -o startup.o startup.s
	$(CC) $(CFLAGS) -o uart.o uart_pl011.c -lgcc -lm 
	$(CC) $(CFLAGS) -o cstart.o cstart.c uart.o 
	$(LD) $(LDFLAGS) startup.o cstart.o -o startup.elf
	$(ELF2BIN) -O binary startup.elf startup.bin

bare-arm.uimg:startup.bin
	$(CREATE_UIMG) -A $(ARCH) -C none -T kernel -a $(LOAD_ADDR) -e $(ENTRY_ADDR) -d $^ $@

sdcard.img:bare-arm.uimg
	$(CREATE_SD_CARD) $@ $^

clean:
	rm -f uart.o cstart.o startup.elf startup.o startup.bin sdcard.img bare-arm.uimg
	rm -rf tmp
