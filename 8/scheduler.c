#include <stddef.h>
#include <stdint.h>
#include "scheduler.h"
#include "systime.h"

static task task_list[MAX_TASKS] = {0};
static uint8_t task_index = 0;

scheduler_error add_task(entry_ptr entry, uint32_t period)
{
	if (task_index >= MAX_TASKS) return SCHEDULER_OVERFLOW;
    	
    	task job ;
        job.entry = entry;
        job.period = period;
        job.last_run = 0;
    	task_list[task_index++] = job;

   	return SCHEDULER_OK;
}

void run() 
{
	while (1) 
	{
        	for (uint8_t i = 0; i < MAX_TASKS; i++) 
		{
            		task* job = &task_list[i];
            		if (job->entry == NULL) continue;
			uint32_t time = get_systime();
            		if (job->last_run + job->period <= time) { 
               			job->last_run = get_systime();
                		job->entry();
            		}
        	}
    	}
}
