#include <stdio.h>
#include <stdlib.h>

#include <anger/list.h>


typedef struct _test_list{
	int data;
	LIST_HEAD_S stNode;
}TEST_LIST_S;

LIST_HEAD(g_stTestList);

int main()
{
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		TEST_LIST_S *pNew = (TEST_LIST_S *)malloc(sizeof(TEST_LIST_S));
		pNew->data = i;
		list_add(&pNew->stNode, &g_stTestList);
	}

	TEST_LIST_S *pEntry;
	list_for_each_entry(pEntry, &g_stTestList, stNode)
	{
		printf("data:%d\r\n", pEntry->data);
	}	
	
}
