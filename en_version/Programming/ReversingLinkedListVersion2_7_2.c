#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
typedef struct LNode *PtrToLNode;
struct LNode {
	int addr;
	int data;
	int next;
};

typedef struct LNode ElementType;
typedef struct LinkedList *List;
struct LinkedList {
	int firAddr;
	int cnt;
	ElementType *pData;
};

List MakeList();
void ReadInput(List L, int N);
void PrintList(List L);
int CntList(List L);
int ReverseK(List H, int K);

int main()
{
	List L;
	int firAddr, N, K, times, new, last, fir, flag=0;

	scanf("%d %d %d", &firAddr, &N, &K);
	L = MakeList();
	L->firAddr = firAddr;

	ReadInput(L, N);
	L->cnt = CntList(L);
	times = L->cnt/K;
	while (times--) {
		new = ReverseK(L, K);
		if (!flag) {
			fir = new;
			flag = 1;
		} else
			L->pData[last].next = new;
		last = L->firAddr;
		L->firAddr = L->pData[last].next;
	}
	L->firAddr = fir;
	PrintList(L);
	return 0;
}

List MakeList()
{
	List L = (List) malloc(sizeof(struct LNode));
	L->firAddr = -1;
	L->pData = (ElementType *) malloc(MAXN*sizeof(struct LNode));
	return L;
}

void ReadInput(List L, int N)
{
	int addr;

	while (N--) {
		scanf("%d", &addr);
		scanf("%d %d", &L->pData[addr].data, &L->pData[addr].next);
		L->pData[addr].addr = addr;
	}
}

void PrintList(List L)
{
	int i;

    for (i = L->firAddr; i != -1; i = L->pData[i].next)
    	if (L->pData[i].next == -1)
			printf("%05d %d -1\n", L->pData[i].addr, L->pData[i].data);
		else
			printf("%05d %d %05d\n",
					L->pData[i].addr, L->pData[i].data, L->pData[i].next);
}

int CntList(List L)
{
	int cnt, t;
	for (t=L->firAddr, cnt=0; t != -1; cnt++, t=L->pData[t].next) ;
	return cnt;
}

int ReverseK(List L, int K)
{
	int cnt, new, old, tmp;

	cnt = 1;
	new = L->firAddr;
	old = L->pData[new].next;
	while (cnt < K) {
		tmp = L->pData[old].next;
		L->pData[old].next = new;
		new = old;
		old = tmp;
		cnt++;
	}
	L->pData[L->firAddr].next = old;
	return new;
}

