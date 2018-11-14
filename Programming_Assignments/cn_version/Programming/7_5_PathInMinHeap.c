/* Sample Input:
 * 5 3
 * 46 23 26 24 10
 * 5 4 3
 * Sample Output:
 * 24 23 10
 * 46 23 10
 * 26 10
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000
#define MIN -65535
typedef int ElemType;
typedef struct HNode *PtrToHNode;
struct HNode {
	ElemType *pData;
	int size;
};
typedef PtrToHNode Heap;
typedef Heap MinHeap;

Heap CreatH(int MaxSize);
void PercUp(Heap H, int p);
bool InsertH(Heap H, ElemType x);
void PathUpToR(Heap H, int p);
bool IsFullH(Heap H);
void DestroyH(Heap H);

int main()
{
	int N, M, i, p;
	MinHeap H;
	ElemType x;

	scanf("%d %d", &N, &M);
	H = CreatH(N);	/* Create and initialize MinHeap */
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		InsertH(H, x);	/* Insert one node at a time to build a MinHeap */
	}
	for (i = 0; i < M; i++) {
		scanf("%d", &p);
		PathUpToR(H, p);	/* Print nodes from position p to root */
	}
	DestroyH(H);
	return 0;
}

bool InsertH(Heap H, ElemType x)
{
	int p;

	if (IsFullH(H)) {
		puts("Full Heap!");
		return false;
	}
	p = ++H->size;
	H->pData[p] = x;
	PercUp(H, p);
	return true;
}

bool IsFullH(Heap H)
{
	return H->size == MAXSIZE;
}

void PercUp(Heap H, int p)
{
	ElemType x = H->pData[p];
	for (; H->pData[p/2] > x; p /= 2)
		H->pData[p] = H->pData[p/2];
	H->pData[p] = x;
}

Heap CreatH(int MaxSize)
{
	MinHeap H = (Heap) malloc(sizeof(struct HNode));
	H->pData = (ElemType *) malloc((MaxSize + 1)*sizeof(ElemType));
	H->size = 0;
	H->pData[0] = MIN;
	return H;
}

void PathUpToR(Heap H, int p)
{
	printf("%d", H->pData[p]);
	while (p > 1) {
		p /= 2;
		printf(" %d", H->pData[p]);
	}
	putchar('\n');
}

void DestroyH(Heap H)
{
	free(H->pData);
	free(H);
}

