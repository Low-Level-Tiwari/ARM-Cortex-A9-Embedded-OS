#include "tasks.h"
#include "uart_pl011.h"
#include "systime.h"

void job0(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 0... systime ");
    uart_write_uint(start);
    uart_write("\n");
    while (start + 1000u > get_systime());
    uart_write("Exiting job 0...\n");
}

void job1(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 1... systime ");
    uart_write_uint(start);
    uart_write("\n");
    while (start + 1000u > get_systime());
    uart_write("Exiting job 1...\n");
}

void job2(void) {
    uint32_t start = get_systime();
    uart_write("Entering job 2... systime ");
    uart_write_uint(start);
    uart_write("\n");
    while(1);
}
