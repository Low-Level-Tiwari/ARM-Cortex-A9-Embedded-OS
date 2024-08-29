#include <stdint.h>
#include <stdbool.h>
#include "uart_pl011.h"
#include "gic.h"
#ifndef CPU_A9_H
void cpu_enable_interrupts();
 
int main() {
        uart_config config = {
            .data_bits = 8,
            .stop_bits = 1,
            .parity = false,
            .baudrate = 9600
        };
        uart_configure(&config);

        uart_putchar('\n');
        uart_write("UART Initializing...!\n");
        uart_write("Welcome to My Operating System\n");
	
	gic_init();
	gic_enable_interrupt(37u);
	cpu_enable_interrupts();
        uart_write("\n|---> ");
        
		
        while (1) {}
	
        return 0;
}
#endif
