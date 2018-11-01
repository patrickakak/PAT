/* Sample Input:
 * 7
 * A 1 B 1 C 1 D 3 E 3 F 6 G 6
 * 4
 * A 00000
 * B 00001
 * C 0001
 * D 001
 * E 01
 * F 10
 * G 11
 * A 01010
 * B 01011
 * C 0100
 * D 011
 * E 10
 * F 11
 * G 00
 * A 000
 * B 001
 * C 010
 * D 011
 * E 100
 * F 101
 * G 110
 * A 00000
 * B 00001
 * C 0001
 * D 001
 * E 00
 * F 10
 * G 11
 * Sample Output:
 * Yes
 * Yes
 * No
 * No
 */
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
struct TNode {	/* Tree node struct */
	Tree Left, Right;
	WeightType weight;
};
typedef Tree HuffmanTree;

typedef Tree ItemType;
typedef struct HNode *PtrToHNode;
struct HNode {	/* Heap node struct */
	ItemType *pItems;
	int size;
	int capacity;
};
typedef PtrToHNode Heap;
typedef Heap MinHeap;

HuffmanTree Huffman(MinHeap H, int N);
PtrToTNode MakeNode(WeightType w);
void InsertHeap(Heap H, ItemType it);
void PercUp(Heap H, int p);
ItemType DelHeapItem(Heap H);
void PercDown(Heap H, int p);
Heap CreatHeap(int N);
Heap BuildHeap(WeightType f[], int N);
WeightType WPL(Tree T, int Depth);
void DestroyTree(Tree T);
bool Judge(int CodeLen, int N, ElemType c[], WeightType f[]);
void DestroyHeap(Heap H);

int main()
{
	int N, M, i;	/* 2<=N<=63, M<=1000 */
	ElemType c[MAXN];
	WeightType CodeLen, f[MAXN];
	HuffmanTree HT;
	MinHeap H;

	scanf("%d\n", &N);
	for (i = 0; i < N-1; i++)
		scanf("%c %d ", &c[i], &f[i]);
	scanf("%c %d\n", &c[i], &f[i]);
	
	H = BuildHeap(f, N);	/* Start to build a huffman tree */
	HT = Huffman(H, N);
	CodeLen = WPL(HT, 0);	/* Calculate the smallest WPL */
	DestroyTree(HT);

	scanf("%d\n", &M);
	for (i = 0; i < M; i++)
		if (Judge(CodeLen, N, c, f)) puts("Yes");
		else puts("No");

	DestroyHeap(H);
	return 0;
}

void DestroyHeap(Heap H)
{
	free(H->pItems[0]);		/* Don't forget to free setinel */
	free(H->pItems);
	free(H);
}

bool Judge(int CodeLen, int N, ElemType c[], WeightType f[])
{
	ElemType ch;
	char code[MAXN+1];
	Tree T, pT;
	int i, j, k, flag = 0;
	WeightType w;
	bool ret;

	T = MakeNode(0);
	for (i = 0; i < N; i++) {
		scanf("%c %s\n", &ch, code);

		/* The length of string (like 00101) must be less than or equal with
		 * N-1 (which is the length of a list that a tree may collapse into) */
		
		if (strlen(code) > N-1 || flag)
			continue;
		for (j = 0; j < N && c[j] != ch; j++) ;
		w = f[j];	/* Find matching f[j] */

		pT = T;
		for (k = 0; code[k]; k++)
			switch (code[k]) {
			case '0':
				if (!pT->Left) pT->Left = MakeNode(0);
				/* To check whether we've encountered a leaf node */
				else if (pT->Left->weight != 0) { flag = 1; break; }
				pT = pT->Left;
				break;
			case '1':
				if (!pT->Right) pT->Right = MakeNode(0);
				else if (pT->Right->weight != 0) { flag = 1; break; }
				pT = pT->Right;
				break;
			}
		/* Assign weight value to a leaf node */
		if (!pT->Left && !pT->Right) pT->weight = w;
		/* It's not a leaf node, which indicates the current node must be
		 * precode of another node */
		else flag = 1;
	}
	if (!flag && CodeLen == WPL(T, 0)) ret = true;
	else ret = false;
	
	DestroyTree(T);
	return ret;
}

void DestroyTree(Tree T)
{
	if (T) {
		DestroyTree(T->Left);
		DestroyTree(T->Right);
		free(T);
	}
}

/* Tree T might not be a huffman tree, so we need to add if statement */
int WPL(Tree T, int Depth)
{
	int lw, rw;
	if (!T->Left && !T->Right)
		return Depth*T->weight;
	else {
		if (T->Left) lw = WPL(T->Left, Depth+1);
		if (T->Right) rw = WPL(T->Right, Depth+1);
		return lw+rw;
	}
}

Heap BuildHeap(WeightType f[], int N)
{
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

Heap CreatHeap(int N)
{
	Heap H = (Heap) malloc(sizeof(*H));
	H->pItems = (ItemType *) malloc((N+1)*sizeof(*H->pItems));
	H->size = 0;
	H->capacity = N;
	H->pItems[0] = MakeNode(MIN);	/* Set a setinel */
	return H;
}

HuffmanTree Huffman(MinHeap H, int N)
{
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

PtrToTNode MakeNode(WeightType w)
{
	ItemType New = (ItemType) malloc(sizeof(*New));
	New->Left = New->Right = NULL;
	New->weight = w;
	return New;
}

void InsertHeap(Heap H, ItemType it)
{
	H->pItems[++H->size] = it;
	PercUp(H, H->size);
}

void PercUp(Heap H, int p)
{
	int i;
	ItemType tmp;

	for (i=p, tmp=H->pItems[p]; H->pItems[i/2]->weight > tmp->weight; i/=2)
		H->pItems[i] = H->pItems[i/2];
	H->pItems[i] = tmp;
}

ItemType DelHeapItem(Heap H)
{
	ItemType it = H->pItems[1];
	H->pItems[1] = H->pItems[H->size--];
	PercDown(H, 1);
	return it;
}

void PercDown(Heap H, int p)
{
	int Parent, Child;
	ItemType tmp = H->pItems[p];

	for (Parent = p; 2 * Parent <= H->size; Parent = Child) {
		Child = 2 * Parent;
		if (Child != H->size && 
				H->pItems[Child]->weight > H->pItems[Child+1]->weight)
			Child++;
		if (tmp->weight > H->pItems[Child]->weight)
			H->pItems[Parent] = H->pItems[Child];
		else break;
	}
	H->pItems[Parent] = tmp;
}

