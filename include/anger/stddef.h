#ifndef _ANGER_STDDEF_H
#define _ANGER_STDDEF_H

#define NULL ((void *)0)
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({ \
	void *__mptr = (void *)ptr; \
	((type *)(__mptr - offsetof(type, member))); })


#endif
