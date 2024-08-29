#include<stdint.h>

typedef void (*entry_ptr)(void);

typedef struct {
    entry_ptr entry;
    uint32_t period;
    uint32_t last_run;
} task;

typedef enum {
    SCHEDULER_OK = 0,
    SCHEDULER_OVERFLOW
} scheduler_error;


scheduler_error add_task(entry_ptr entry, uint32_t period);
void run(void);

#define MAX_TASKS (10u)
