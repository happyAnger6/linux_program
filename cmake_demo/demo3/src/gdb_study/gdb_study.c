#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10

typedef struct tagVd
{
	int a[10];
	char b[100];
}VD_S;

typedef struct tagVdInfo{
	int a;
	VD_S vds[10];	
}VD_INFO_S;

int initvds(VD_S *pVd, int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		pVd->a[0] = i;
		pVd->b[0] = 'A' + i;
		pVd->b[1] = 'B' + i;
		pVd++;
	}	
}

int f2(int *pa)
{
	int i = 5;
	for(i = 5; i < 10; i++)
	{
		pa[i] = i+10;
	}
}

int f1(int *pa)
{
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		pa[i] = i+5;
	}
	f2(pa);
}

int main()
{
	int i = 0;
	int a[] = {1, 3, 5, 7, 9};
	int *p = a;

	VD_INFO_S vdinfos;
	memset(&vdinfos, 0 ,sizeof(VD_INFO_S));

	initvds(vdinfos.vds, 10);

	int *pa = malloc(sizeof(int)*ARRAY_SIZE);
	for(i = 0; i <ARRAY_SIZE; i++)
	{
		pa[i] = i;
	}

	f1(pa);
	return 0;
}
