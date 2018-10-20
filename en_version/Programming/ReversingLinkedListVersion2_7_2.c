/* Sample Input:
 * 00100 6 4
 * 00000 4 99999
 * 00100 1 12309
 * 68237 6 -1
 * 33218 3 00000
 * 99999 5 68237
 * 12309 2 33218
 * --------------
 * Sample Output:
 * 00000 4 33218
 * 33218 3 12309
 * 12309 2 00100
 * 00100 1 99999
 * 99999 5 68237
 * 68237 6 -1
 */
#include <stdio.h>
#include <stdlib.h>

typedef int AddrType, ElemType, PtrType;
struct LNode {
	AddrType addr;
	ElemType elem;
	PtrType next;
};
typedef struct LNode *PtrToLNode;

#define MAXN 100000
typedef struct LNode DataType;
struct List_st {
	AddrType fir;
	DataType *pData;
};
typedef struct List_st *List;

List CreatL();
void Readin(List L, int N);
void PrintL(List L);
int GetLLen(List L);
PtrType ReverseK(List L, int K);
void DestroyL(List L);

int main()
{
	List L;
	int N, K, lenL, time, flag=0;
	AddrType firAddr, addrH;
	PtrType new, last; 	/* last points to the last node of 
						   last group of reversed elements */

	/* freopen("test.txt", "r", stdin); */
	scanf("%d %d %d", &firAddr, &N, &K);
	L = CreatL(); L->fir = firAddr;
	Readin(L, N);

    lenL = GetLLen(L); time = lenL/K;
    if (K == 1) { PrintL(L); DestroyL(L); exit(EXIT_SUCCESS); }
	while (time--) {
		new = ReverseK(L, K);
		if (!flag) { 	/* First time handling */
			addrH = new;
			flag = 1;
		} else
			L->pData[last].next = new;
		last = L->fir;
		L->fir = L->pData[last].next; 	/* Move head */
	}
	L->fir = addrH; PrintL(L); DestroyL(L);
	return 0;
}

List CreatL()
{
	List L;
	L = (List) malloc(sizeof(struct List_st));
	L->fir = -1;
	L->pData = (DataType *) malloc(MAXN*sizeof(DataType));
	return L;
}

void Readin(List L, int N)
{
	int i;
	AddrType a;

	for (i = 0; i < N; i++) {
		scanf("%d", &a);
		scanf("%d %d", &L->pData[a].elem, &L->pData[a].next);
		L->pData[a].addr = a;
	}
}

void PrintL(List L)
{
	AddrType t;
	for (t=L->fir; t!=-1; t=L->pData[t].next)
		if (L->pData[t].next == -1)
			printf("%05d %d -1\n", t, L->pData[t].elem);
		else
			printf("%05d %d %05d\n", t, L->pData[t].elem, L->pData[t].next);
}

int GetLLen(List L)
{
	int t, len = 0;
	for (t=L->fir; t!=-1; t=L->pData[t].next) len++;
	return len;
}

PtrType ReverseK(List L, int K)
{
	PtrType new, old, tmp;

	new = L->fir; old = L->pData[new].next;
	while (--K) {
		tmp = L->pData[old].next;
		L->pData[old].next = new;
		new = old;
		old = tmp;
	}
	L->pData[L->fir].next = old;
	return new;
}

void DestroyL(List L)
{
	free(L->pData);
	free(L);
}

