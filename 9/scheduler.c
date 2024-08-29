#include <stddef.h>
#include <stdint.h>
#include "scheduler.h"
#include "systime.h"

static task task_list[MAX_TASKS] = {0};
static uint8_t task_index = 0;
uint8_t switching = 0;


void context_switch()
{
	if(switching)
	{
		
	}
}


scheduler_error add_task(entry_ptr entry)
{
	if (task_index >= MAX_TASKS) return SCHEDULER_OVERFLOW;
    	
	task_list[task_index].con.r0=1;
	task_list[task_index].con.r1=1;
	task_list[task_index].con.r2=1;
	task_list[task_index].con.r3=1;
	task_list[task_index].con.r4=1;
	task_list[task_index].con.r5=1;
	task_list[task_index].con.r6=1;
	task_list[task_index].con.r7=1;
	task_list[task_index].con.r8=1;
	task_list[task_index].con.r9=1;
	task_list[task_index].con.r10=1;
	task_list[task_index].con.r11=1;
	task_list[task_index].con.sp=1;
	task_list[task_index].con.lr=1;
	task_list[task_index].con.pc=1;
	task_list[task_index].con.cpsr=1;
        task_list[task_index].entry = entry;
    	
	task_index++;
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
			
			switching = 1;
                	job->entry();
			switching = 0;

            	}
        }
}

