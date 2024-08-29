#include "tasks.h"
#include "uart_pl011.h"
#include "systime.h"


void job0(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 0... systime ");
    uart_write_uint(start);
    uart_write("\n");

    uint32_t j,i=0;
    while(i<100000)
    {
	    j=0;
	    while(j<10000)j++;
	    i++;
    } 
    
    uart_write_uint(i);
    uart_putchar(',');
    uart_write_uint(j);
    uart_write("\n");
    uart_write("Exiting job 0... systime ");
    start = get_systime();
    uart_write_uint(start);
    uart_write("\n");
}

void job1(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 1... systime ");
    uart_write_uint(start);
    uart_write("\n");
    
    uint32_t j,i=0;
    while(i<100000)
    {
	    j=0;
	    while(j<10000)j++;
	    i++;
    } 
    
    uart_write_uint(i);
    uart_putchar(',');
    uart_write_uint(j);
    uart_write("\n");

    uart_write("Exiting job 1...systime ");
    start = get_systime();
    uart_write_uint(start);
    uart_write("\n");
}

void job2(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 2... systime ");
    uart_write_uint(start);
    uart_write("\n");
    
    uint32_t j,i=0;
    while(i<100000)
    {
	    j=0;
	    while(j<10000)j++;
	    i++;
    } 
    
    uart_write_uint(i);
    uart_putchar(',');
    uart_write_uint(j);
    uart_write("\n");

    uart_write("Exiting job 2...systime ");
    start = get_systime();
    uart_write_uint(start);
    uart_write("\n");
}

void job3(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 3... systime ");
    uart_write_uint(start);
    uart_write("\n");
    
    uint32_t j,i=0;
    while(i<100000)
    {
	    j=0;
	    while(j<10000)j++;
	    i++;
    } 
    
    uart_write_uint(i);
    uart_putchar(',');
    uart_write_uint(j);
    uart_write("\n");

    uart_write("Exiting job 3...systime ");
    start = get_systime();
    uart_write_uint(start);
    uart_write("\n");
}

