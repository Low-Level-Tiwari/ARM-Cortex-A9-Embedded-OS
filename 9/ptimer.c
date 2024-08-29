#include "ptimer.h"
#include "irq.h"
#include "uart_pl011.h"
#include "systime.h"

static ptimer* pt_regs;
uint32_t c = 0;
#define WRITE32(x, y) (*(volatile uint32_t*)&x = y )

void ptimer_isr()
{
	WRITE32(pt_regs->ISR, ISR_CLEAR);
	c++;
	if(c==3000){
		systime_tick();
		c=0;
	}
}

uint32_t timer_value(uint16_t n)
{
	double period = n*0.001;
	uint32_t val = (period * refclock ) - 1;
	val *= 3;
	return val;
}

timer_error ptimer_init(uint16_t n)
{
    	uint32_t result;
   	asm ("mrc p15, #4, %0, c15, c0, #0" : "=r" (result));
	pt_regs = (ptimer*)(result + PTIMER_OFFSET);
	uint32_t val = timer_value(n);
	WRITE32(pt_regs->LR, val);
	(void)irq_register_isr(29u,ptimer_isr);
	
        uint32_t cr = AUTO_RELOAD | IRQ_ENABLE | PTIMER_ENABLE;
	WRITE32(pt_regs->CR, cr);

	return PTIMER_OK; 
}

