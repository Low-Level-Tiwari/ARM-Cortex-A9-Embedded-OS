#include <stdint.h>
#include <stdbool.h>
#include "uart_pl011.h"

char buf[64];
uint8_t buf_idx = 0u;

bool cmp(char* s, char* d)
{
	while(*s && *d)if(*s++ != *d++) return 1;
	if(*s || *d) return 1;return 0;
}

static void parse_cmd(void) {
    if (!cmp("help", buf)) {
        uart_write("\n help      ->   Help menu");
        uart_write("\n sysinfo   ->   System Information");
    } else if (!cmp("uname", buf)) {
        uart_write("\n OS:		Bare-Metal Os v0.1");
        uart_write("\n Board:		ARM Versatile Express V2P-CA 9x4");
        uart_write("\n CPU:		ARM Cortex-A9 mpCore");
        uart_write("\n Memory:	2G DDR2");
    } else if (!cmp("quit", buf)) {
	uart_putchar(3);
    } else {
	    uart_write("\n Unknown Command");
    }
}

 
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
	
        while (1) {
            char c = 'a';
            uart_write("\n|---> ");
	    while(c != '\r')
	    {
		    while(uart_getchar(&c) != UART_OK) ;
                    if (c == '\r') {
                    	    buf[buf_idx % 64] = '\0';
                    	    buf_idx = 0u;
                            parse_cmd();
                    }
		    else {
			    uart_putchar(c);
                    	    buf[buf_idx % 64] = c;
                    	    buf_idx++;
		    }
            }
	}
	
        return 0;
}
