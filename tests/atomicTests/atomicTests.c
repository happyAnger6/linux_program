#include <anger/atm_gcc_atomic.h>

int main()
{
	int *p = NULL, a = 10;
	anger_atm_no_barrier_store(&p, &a);

	printf("%d\r\n", *p);
	return 0;
}

