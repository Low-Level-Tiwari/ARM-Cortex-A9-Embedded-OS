#include<stdint.h>

typedef void (*entry_ptr)(void);

typedef struct __attribute__((packed)){
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t sp;
	uint32_t lr;
	uint32_t pc;
	uint32_t cpsr;
} context;



typedef struct {
	context con;
    	entry_ptr entry;
} task;

typedef enum {
    SCHEDULER_OK = 0,
    SCHEDULER_OVERFLOW
} scheduler_error;

void context_switch();
scheduler_error add_task(entry_ptr entry);
void run(void);

#define MAX_TASKS (10u)
