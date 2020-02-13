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
bool IsFullH(Heap H) {
	return H->size == MAXSIZE;
}
void PercUp(Heap H, int p) {
	ElemType x = H->pData[p];
	for (; H->pData[p/2] > x; p /= 2)
		H->pData[p] = H->pData[p/2];
	H->pData[p] = x;
}
Heap CreatH(int MaxSize) {
	MinHeap H = (Heap) malloc(sizeof(struct HNode));
	H->pData = (ElemType *) malloc((MaxSize + 1)*sizeof(ElemType));
	H->size = 0;
	H->pData[0] = MIN;
	return H;
}
void PathUpToR(Heap H, int p) {
	printf("%d", H->pData[p]);
	while (p > 1) {
		p /= 2;
		printf(" %d", H->pData[p]);
	}
	putchar('\n');
}
bool InsertH(Heap H, ElemType x) {
	if (IsFullH(H)) {
		puts("Full Heap!");
		return false;
	}
	int p = ++H->size;
	H->pData[p] = x;
	PercUp(H, p);
	return true;
}
void DestroyH(Heap H) {
	free(H->pData);
	free(H);
}
int main() {
	int N, M, p;
	ElemType x;
	scanf("%d %d", &N, &M);
	MinHeap H = CreatH(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		InsertH(H, x);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &p);
		PathUpToR(H, p);
	}
	DestroyH(H);
	return 0;
}
