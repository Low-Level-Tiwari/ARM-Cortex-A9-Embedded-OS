#include <stdint.h>
#include <stdbool.h>
#include "uart_pl011.h"
#include "gic.h"
#include "ptimer.h"
#include "tasks.h"
#include "scheduler.h"

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
	gic_enable_interrupt(37u);	// UART Interrupt Enable
	gic_enable_interrupt(29u);	// Private Timer Interrupt Enable
	cpu_enable_interrupts();	// GIC Interrupt Enable
        uart_write("\n|---> ");
        
	if(ptimer_init(1u) != PTIMER_OK){
		uart_write("Failed Timer\n");
	}


	(void)add_task(&job0,5000u);
	(void)add_task(&job1,2000u);
	
	run();
while(1){}
        return 0;
}
