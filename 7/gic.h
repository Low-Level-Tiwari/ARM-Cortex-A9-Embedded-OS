
#include<stdint.h>
#include "cpu_a9.h"

typedef volatile struct __attribute((packed)){
	uint32_t DICR;
	const uint32_t DTYPER;
	const uint32_t DIIDR;
	uint32_t resv0[29];
	uint32_t DIGR[32];
	uint32_t DISER[32];
	uint32_t DICER[32];
	uint32_t DISPR[32];
	uint32_t DICPR[32];
	uint32_t DABR[32];
	uint32_t resv1[32];
	uint32_t DIPR[255];
	uint32_t resv2;
	const uint32_t DIPTRO[8];
	uint32_t DIPTRW[246];
	uint32_t resv3;
	uint32_t DICFR[64];
} gic_dist_registers;	



typedef volatile struct __attribute((packed)){

	uint32_t CICR;
	uint32_t CPMR;
	uint32_t CBPR;
	const uint32_t CIAR;
	uint32_t CEOIR;
	const uint32_t CRPR;
	const uint32_t CHPIR;
	uint32_t CABPR;
	const uint32_t CAIAR;
	uint32_t CAEOIR;
	const uint32_t CAHPIR;


} gic_cpu_registers;



void gic_init();
void gic_enable_interrupt(uint16_t number);

uint16_t gic_acknowledge_interrupt();
void gic_end_interrupt(uint16_t number);


#define CICR_ENABLE 	1u 
#define DICR_ENABLE	1u
#define CIAR_ID_MASK	(0x3FFu)
#define CEOIR_ID_MASK	(0x3FFu)

#define GIC_CPU_OFFSET  (0x100u)
#define GIC_DIST_OFFSET  (0x1000u)

