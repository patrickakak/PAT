#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 63
#define MAXM 1000
#define MIN -65535
typedef char ElemType;
typedef int WeightType;
typedef struct TNode *PtrToTNode;
typedef PtrToTNode Tree;
struct TNode {
	Tree Left, Right;
	WeightType weight;
};
typedef Tree HuffmanTree;
typedef Tree ItemType;
typedef struct HNode *PtrToHNode;
struct HNode {
	ItemType *pItems;
	int size;
	int capacity;
};
typedef PtrToHNode Heap;
typedef Heap MinHeap;
void DestroyHeap(Heap H) {
	free(H->pItems[0]);
	free(H->pItems);
	free(H);
}
PtrToTNode MakeNode(WeightType w) {
	ItemType New = (ItemType) malloc(sizeof(*New));
	New->Left = New->Right = NULL;
	New->weight = w;
	return New;
}
Heap CreatHeap(int N) {
	Heap H = (Heap) malloc(sizeof(*H));
	H->pItems = (ItemType *) malloc((N+1)*sizeof(*H->pItems));
	H->size = 0;
	H->capacity = N;
	H->pItems[0] = MakeNode(MIN);	/* Set a setinel */
	return H;
}
void PercUp(Heap H, int p) {
	int i;
	ItemType tmp;
	for (i=p, tmp=H->pItems[p]; H->pItems[i/2]->weight > tmp->weight; i/=2)
		H->pItems[i] = H->pItems[i/2];
	H->pItems[i] = tmp;
}
void PercDown(Heap H, int p) {
	int Parent, Child;
	ItemType tmp = H->pItems[p];
	for (Parent = p; 2 * Parent <= H->size; Parent = Child) {
		Child = 2 * Parent;
		if (Child != H->size && H->pItems[Child]->weight > H->pItems[Child+1]->weight)
			Child++;
		if (tmp->weight > H->pItems[Child]->weight) H->pItems[Parent] = H->pItems[Child];
		else break;
	}
	H->pItems[Parent] = tmp;
}
void InsertHeap(Heap H, ItemType it) {
	H->pItems[++H->size] = it;
	PercUp(H, H->size);
}
ItemType DelHeapItem(Heap H) {
	ItemType it = H->pItems[1];
	H->pItems[1] = H->pItems[H->size--];
	PercDown(H, 1);
	return it;
}
Heap BuildHeap(WeightType f[], int N) {
	Heap H;
	int i;
	H = CreatHeap(N);
	for (i = 0; i < N; i++) {
		H->pItems[i+1] = MakeNode(f[i]);	/* Index begins with one */
		H->size++;
	}
	for (i = H->size/2; i > 0; i--)
		PercDown(H, i);
	return H;
}
HuffmanTree Huffman(MinHeap H, int N) {
	int i;
	HuffmanTree HT;
	ItemType it, L, R;
	for (i = 0; i < N-1; i++) {
		L = DelHeapItem(H);
		R = DelHeapItem(H);
		it = MakeNode(L->weight + R->weight);
		it->Left = L;
		it->Right = R;
		InsertHeap(H, it);
	}
	HT = DelHeapItem(H);
	return HT;
}
int WPL(Tree T, int Depth) {
	int lw, rw;
	if (!T->Left && !T->Right) return Depth*T->weight;
	else {
		if (T->Left) lw = WPL(T->Left, Depth+1);
		if (T->Right) rw = WPL(T->Right, Depth+1);
		return lw+rw;
	}
}
void DestroyTree(Tree T) {
	if (T) {
		DestroyTree(T->Left);
		DestroyTree(T->Right);
		free(T);
	}
}
bool Judge(WeightType CodeLen, int N, ElemType c[], WeightType f[]) {
	ElemType ch;
	char code[MAXN+1];
	Tree T, pT;
	int i, j, k, flag = 0;
	WeightType w;
	bool ret;
	T = MakeNode(0);
	for (i = 0; i < N; i++) {
		scanf("%c %s\n", &ch, code);		
		if (strlen(code) > N-1 || flag) {
			flag = 1; continue;
		}
		for (j = 0; j < N && c[j] != ch; j++) ;
		w = f[j];
		pT = T;
		for (k = 0; code[k]; k++)
			switch (code[k]) {
			case '0':
				if (!pT->Left) pT->Left = MakeNode(0);
				else if (pT->Left->weight != 0) goto END;
				pT = pT->Left;
				break;
			case '1':
				if (!pT->Right) pT->Right = MakeNode(0);
				else if (pT->Right->weight != 0) goto END;
				pT = pT->Right;
				break;
			}
END:
		if (!pT->Left && !pT->Right) pT->weight = w;
		else flag = 1;
	}
	if (!flag && CodeLen == WPL(T, 0)) ret = true;
	else ret = false;
	DestroyTree(T);
	return ret;
}
int main() {
	int N, M, i;
	ElemType c[MAXN];
	WeightType CodeLen, f[MAXN];
	HuffmanTree HT;
	MinHeap H;
	scanf("%d\n", &N);
	for (i = 0; i < N-1; i++)
		scanf("%c %d ", &c[i], &f[i]);
	scanf("%c %d\n", &c[i], &f[i]);
	H = BuildHeap(f, N);
	HT = Huffman(H, N);
	CodeLen = WPL(HT, 0);
	scanf("%d\n", &M);
	for (i = 0; i < M; i++)
		if (Judge(CodeLen, N, c, f)) puts("Yes");
		else puts("No");
	DestroyTree(HT);
	DestroyHeap(H);
	return 0;
}
