#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 64
typedef char ElementType;
typedef int WeightType;
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	WeightType Weight;
	HuffmanTree Left, Right;
};

#define MinData -1
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
	HuffmanTree Data;
	int Size;
	int Capacity;
};

MinHeap CreateMinHeap( int MaxSize );
MinHeap ReadData( int N, ElementType c[], WeightType f[], MinHeap H );
HuffmanTree Huffman( MinHeap H );
MinHeap BuildMinHeap( int N, ElementType c[], WeightType f[] );
HuffmanTree DeleteMin( MinHeap H );
void MinHeapInsert( MinHeap H, HuffmanTree T );
int WPL( HuffmanTree T, int Depth );
bool Judge( int N, int CodeLen, ElementType *c, WeightType *f );
HuffmanTree CreateHuffmanTree();
void DeleteTree( HuffmanTree T );
void PercolateUp( int p, MinHeap H );
void PercolateDown( int p, MinHeap H );

int main()
{
	ElementType c[MAXN];
	WeightType f[MAXN];
	int N, CodeLen, i, n;
	MinHeap H;
	HuffmanTree T;

	/*
	 * -----------------------------------------
	 * | INPUT:                      | OUTPUT: |
	 * -----------------------------------------
	 * | 7                           | Yes     |
	 * | A 1 B 1 C 1 D 3 E 3 F 6 G 6 | Yes     |
	 * | 4                           | No      |
	 * | A 00000                     | No      |
	 * | B 00001                     |         |
	 * | C 0001                      |         |
	 * | D 001                       |         |
	 * | E 01                        |         |
	 * | F 10                        |         |
	 * | G 11                        |         |
	 * | A 01010                     |         |
	 * | B 01011                     |         |
	 * | C 0100                      |         |
	 * | D 011                       |         |
	 * | E 10                        |         |
	 * | F 11                        |         |
	 * | G 00                        |         |
	 * | A 000                       |         |
	 * | B 001                       |         |
	 * | C 010                       |         |
	 * | D 011                       |         |
	 * | E 100                       |         |
	 * | F 101                       |         |
	 * | G 110                       |         |
	 * | A 00000                     |         |
	 * | B 00001                     |         |
	 * | C 0001                      |         |
	 * | D 001                       |         |
	 * | E 00                        |         |
	 * | F 10                        |         |
	 * | G 11                        |         |
	 * -----------------------------------------
	 */

	scanf("%d\n", &N);
	H = BuildMinHeap(N, c, f);

	T = Huffman(H);
	CodeLen = WPL(T, 0);	/* Calculate the smallest WPL */

	scanf("%d", &n);	/* Judge codes */
	getchar();
	for (i = 0; i < n; i++)
		if (Judge(N, CodeLen, c, f)) printf("Yes\n");
		else printf("No\n");

	return 0;
}

MinHeap CreateMinHeap( int MaxSize )
{
	MinHeap H = (MinHeap) malloc(sizeof(struct HeapStruct));
	H->Data = (HuffmanTree) malloc((MaxSize+1) * sizeof(struct TreeNode));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0].Weight = MinData;
	return H;
}

MinHeap ReadData( int N, ElementType c[], WeightType f[], MinHeap H )
{
	int i;

	for (i = 0; i < N; i++) {
		scanf("%c %d", &c[i], &f[i]);
		if (i != N-1) getchar();
		++H->Size;
		H->Data[i+1].Weight = f[i];
		H->Data[i+1].Left = H->Data[i+1].Right = NULL;
	}
	return H;
}

void MinHeapInsert( MinHeap H, HuffmanTree T )
{
	int p;

	p = ++H->Size;
	H->Data[p] = *T;
	PercolateUp(p, H);
}

HuffmanTree Huffman( MinHeap H )
{
	int i;
	HuffmanTree T;

	for (i = 1; i < H->Capacity; i++) {
		T = (HuffmanTree) malloc(sizeof(struct TreeNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		MinHeapInsert(H, T);
	}
	T = DeleteMin(H);
	return T;
}

HuffmanTree DeleteMin( MinHeap H )
{
	HuffmanTree MinItem;

	MinItem = (HuffmanTree) malloc(sizeof(struct TreeNode));
	*MinItem = H->Data[1];
	H->Data[1] = H->Data[H->Size--];
	PercolateDown(1, H);
	return MinItem;
}

MinHeap BuildMinHeap( int N, ElementType c[], WeightType f[] )
{
	int i;
	MinHeap H;

	H = CreateMinHeap(N);
	H = ReadData(N, c, f, H);
	
	for (i = H->Size/2; i > 0; i--)
		PercolateDown(i, H);
	return H;
}

int WPL( HuffmanTree T, int Depth )
{
	int rw = 0, lw = 0;
	
	if (!T->Left && !T->Right)
		return (Depth * T->Weight);
	else {
		if (T->Left) lw = WPL(T->Left, Depth+1);
		if (T->Right) rw = WPL(T->Right, Depth+1);
		return lw + rw;
	}
}

bool Judge( int N, int CodeLen, ElementType c[], WeightType f[] )
{
	char ch, s[MAXN];
	int i, j, k, CurWeight;
	bool flag = true, ReadOnly = false;
	HuffmanTree T, pT;

	T = CreateHuffmanTree();
	for (i = 0; i < N; i++) {
		scanf("%c %s", &ch, s);
		getchar();
		
		if (ReadOnly) continue;
		
		/* The length of string (like 00101) must be less than or equal with
		 * N-1 (which is the length of a list that a tree may collapse into) */
		if ((int)strlen(s) > N-1) {
			flag = false;
			ReadOnly = true;
			continue;
		}
		
		for (j = 0; j < N && ch != c[j]; j++) ;
		CurWeight = f[j];
		
		pT = T;
		for (k = 0; k < (int)strlen(s); k++) {
			switch (s[k]) {
			case '0': 
				if (!pT->Left) pT->Left = CreateHuffmanTree();
				/* To check whether we've encountered a leaf node */
				else if (pT->Left->Weight != 0) { flag = false; break; }
				pT = pT->Left;
				break;
			default:
				if (!pT->Right) pT->Right = CreateHuffmanTree();
				else if (pT->Right->Weight != 0) { flag = false; break; }
				pT = pT->Right;
			}
		}
		/* Assign weight value to a leaf node */
		if (!pT->Left && !pT->Right) pT->Weight = CurWeight;
		/* It's not a leaf node, which indicates the current node must be
		 * precode of another node */
		else flag = false;
	}
	
	if (flag && CodeLen == WPL(T, 0)) return true;
	DeleteTree(T);
	return false;
}

HuffmanTree CreateHuffmanTree()
{
	HuffmanTree T = (HuffmanTree) malloc(sizeof(struct TreeNode));
	T->Weight = 0;
	T->Left = T->Right = NULL;
	return T;
}

void DeleteTree( HuffmanTree T )
{
	if (T) { DeleteTree(T->Left); DeleteTree(T->Right); free(T); }
}

void PercolateUp( int p, MinHeap H )
{
	int i;
	struct TreeNode Tmp;

	for (i=p, Tmp=H->Data[p]; H->Data[i/2].Weight > Tmp.Weight; i /= 2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = Tmp;
}

void PercolateDown( int p, MinHeap H )
{
	struct TreeNode Tmp = H->Data[p];
	int Parent, Child;

	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) 
				&& (H->Data[Child].Weight > H->Data[Child+1].Weight))
			Child++;
		if (Tmp.Weight <= H->Data[Child].Weight) break;
		else H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = Tmp;
}

