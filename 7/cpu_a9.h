
#include <stdint.h>

inline void cpu_enable_interrupts() {
    asm ("cpsie if");
}

