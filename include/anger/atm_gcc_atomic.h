#ifndef _ANGER_ATM_GCC_ATOMIC_H
#define _ANGER_ATM_GCC_ATOMIC_H

#define anger_atm_no_barrier_store(p, value) \
	(__atomic_store_n((p), (intptr_t)(value), __ATOMIC_RELAXED))

#endif
