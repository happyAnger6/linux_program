#include <anger/types.h>
#include <anger/stddef.h>

#define LIST_HEAD_INIT(name) {&(name), &(name) }

#define LIST_HEAD(name) \
	LIST_HEAD_S name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(LIST_HEAD_S *pList)
{
	pList->pNext = pList;
	pList->pPrev = pList;
}

static inline void __list_add(LIST_HEAD_S *pNew,
					LIST_HEAD_S *pPrev,
					LIST_HEAD_S *pNext)
{
	pNext->pPrev = pNew;
	pNew->pNext = pNext;
	pNew->pPrev = pPrev;
	pPrev->pNext = pNew;
}

static inline void list_add(LIST_HEAD_S *pNew, LIST_HEAD_S *pHead)
{
	__list_add(pNew, pHead, pHead->pNext);
}

static inline void list_add_tail(LIST_HEAD_S *pNew, LIST_HEAD_S *pHead)
{
	__list_add(pNew, pHead->pPrev, pHead);
}

static inline void __list_del(LIST_HEAD_S *pPrev, LIST_HEAD_S *pNext)
{
	pPrev->pNext = pNext;
	pNext->pPrev = pPrev;
}

static inline void __list_del_entry(LIST_HEAD_S *pEntry)
{
	__list_del(pEntry->pPrev, pEntry->pNext);
}

static inline void list_del(LIST_HEAD_S *pEntry)
{
	__list_del(pEntry->pPrev, pEntry->pNext);
	pEntry->pNext = NULL;
	pEntry->pPrev = NULL;
}

#define list_for_each(pos, head) \
	for(pos = (head)->pNext; pos != (head); pos = pos->pNext)

#define list_for_each_prev(pos, head) \
	for(pos = (head)->pPrev; pos != (head); pos = pos->pPrev)

#define list_for_each_safe(pos, n, head) \
	for(pos = (head)->pNext, n = pos->pNext; pos != (head); \
			pos = n, n = n->pNext)

#define list_for_each_prev_safe(pos, n, head) \
	for(pos = (head)->pPrev, n = post->pPrev; pos != (head); \
			pos = n, n = n->pPrev)

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->pNext, type, member)

#define list_next_entry(pos, member) \
	list_entry((pos)->member.pNext, typeof(*(pos)), member)

#define list_for_each_entry(pos, head, member)	\
	for(pos = list_first_entry(head, typeof(*(pos)), member); \
		&pos->member != (head); \
		pos = list_next_entry(pos, member))

