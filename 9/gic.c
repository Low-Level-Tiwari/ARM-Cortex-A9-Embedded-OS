#include "gic.h"

#define WRITE32(x, y) (*(volatile uint32_t*)&x = y )


static gic_dist_registers* gic_dregs;
static gic_cpu_registers* gic_cregs;

void gic_init(){

    	uint32_t result;
   	asm ("mrc p15, #4, %0, c15, c0, #0" : "=r" (result));
	gic_dregs = (gic_dist_registers*)((result + GIC_DIST_OFFSET));
	gic_cregs = (gic_cpu_registers*)((result + GIC_CPU_OFFSET));

	WRITE32(gic_cregs->CPMR, 0xFFFF);
	WRITE32(gic_cregs->CICR, CICR_ENABLE);
	gic_dregs = (gic_dist_registers*)((result + GIC_DIST_OFFSET));
	WRITE32(gic_dregs->DICR, DICR_ENABLE);

}

void gic_enable_interrupt(uint16_t number){
	
	uint8_t reg = number/32;
	uint8_t bit = number%32;
	uint32_t reg_val = gic_dregs->DISER[reg];
	reg_val |= (1u << bit);
	WRITE32(gic_dregs->DISER[reg],reg_val);


	reg = number/4;
	bit = (number%4)*8;
	reg_val = gic_dregs->DIPTRW[reg];
	reg_val |= (1u << bit);
	WRITE32(gic_dregs->DIPTRW[reg],reg_val);
}

uint16_t gic_acknowledge_interrupt(){
	return gic_cregs->CIAR & CIAR_ID_MASK;
}

void gic_end_interrupt(uint16_t n){
	WRITE32(gic_cregs->CEOIR, (n&CEOIR_ID_MASK));
}
