ARCH = arm
CREATE_UIMG = ../utils/mkimage
CREATE_SD_CARD = ../utils/create-sd.sh
ENTRY_ADDR = 0x60000000
LOAD_ADDR  = 0x60000000
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
ELF2BIN = arm-none-eabi-objcopy
CFLAGS = -r -nostartfiles -g -Wall -mthumb -mcpu=cortex-a9  
LDFLAGS = -T link.ld  


all:startup.bin bare-arm.uimg sdcard.img link.ld

startup.bin:startup.s cstart.c uart_pl011.c
	$(AS) -o startup.o startup.s
	$(CC) $(CFLAGS) -o gic.o gic.c 
	$(CC) $(CFLAGS) -o irq.o irq.c 
	$(CC) $(CFLAGS) -o systime.o systime.c 
	$(CC) $(CFLAGS) -o ptimer.o ptimer.c systime.o 
	$(CC) $(CFLAGS) -o uart.o uart_pl011.c irq.o -lgcc -lm 
	$(CC) $(CFLAGS) -o tasks.o tasks.c 
	$(CC) $(CFLAGS) -o scheduler.o scheduler.c -lgcc 
	$(CC) $(CFLAGS) -o cstart.o cstart.c uart.o gic.o ptimer.o tasks.o scheduler.o -lgcc
	$(LD) $(LDFLAGS) startup.o cstart.o -o startup.elf 
	$(ELF2BIN) -O binary startup.elf startup.bin

bare-arm.uimg:startup.bin
	$(CREATE_UIMG) -A $(ARCH) -C none -T kernel -a $(LOAD_ADDR) -e $(ENTRY_ADDR) -d $^ $@

sdcard.img:bare-arm.uimg
	$(CREATE_SD_CARD) $@ $^

clean:
	rm -f tasks.o scheduler.o systime.o ptimer.o irq.o gic.o uart.o cstart.o startup.elf startup.o startup.bin sdcard.img bare-arm.uimg
	rm -rf tmp
