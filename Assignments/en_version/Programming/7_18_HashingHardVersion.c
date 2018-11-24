/**
 * Sample Input:
 * 11
 * 33 1 13 12 34 38 27 22 32 -1 21
 * Sample Output:
 * 1 13 12 21 33 34 38 27 22 32
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

typedef int Index;
typedef int KeyType;

typedef int Vertex;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	PtrToAdjVNode Next;
};
typedef struct VNode {
	PtrToAdjVNode FirstEdge;
} AdjList[MAXN];
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

#define MinData -1000
typedef struct {
	Vertex V;
	KeyType Value;
} Pair;
typedef Pair ElementType;

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
	ElementType Elems[MAXN+1];
	int Size;
};

/**
 * Adjacent List Graph related functions: 
 */
LGraph CreateGraph(int VertexNum);
LGraph BuildGraph(KeyType A[], MinHeap H, int Indegree[], int N);
void DestroyGraph(LGraph LG);
void InsertEdge(LGraph LG, Edge E);

/**
 * Minimum Heap related functions:
 */
MinHeap CreateHeap();
void DestroyHeap(MinHeap H);
void InsertMinHeap(MinHeap H, ElementType X);
ElementType DeleteMin(MinHeap H);
void PercUp(MinHeap H, int p);
void PercDown(MinHeap H, int p);
bool IsEmptyHeap(MinHeap H);

/**
 * Core functions:
 */
void ReadInput(KeyType A[], int N);
void InitIndegreeArr(int Indegree[], int N);
int TopSort(LGraph LG, MinHeap H, int Indeg[], KeyType A[], KeyType TopOrder[]);
void Output(KeyType TopOrder[], int N);
Index Hash(KeyType Key, int N);

int main()
{
	KeyType A[MAXN], TopOrder[MAXN];
	int N, count, Indegree[MAXN];
	LGraph LG;
	MinHeap H;
 
	scanf("%d", &N);	/* N > 0 */
	ReadInput(A, N);	/* Read input */
	
	InitIndegreeArr(Indegree, N);	/* Init indegree array */
	
	H = CreateHeap();
	LG = BuildGraph(A, H, Indegree, N);
	
	count = TopSort(LG, H, Indegree, A, TopOrder);
	Output(TopOrder, count);

	DestroyGraph(LG); DestroyHeap(H);

	return 0;
}

void ReadInput(KeyType A[], int N)
{
	int i;

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
}

void InitIndegreeArr(int Indegree[], int N)
{
	int i;

	for (i = 0; i < N; i++)
		Indegree[i] = 0;
}

LGraph BuildGraph(KeyType A[], MinHeap H, int Indegree[], int N)
{
	LGraph LG;
	int i, j;
	Index Pos, ActualPos;
	Edge E;
	Pair pair;

	LG = CreateGraph(N);
	for (i = 0; i < N; i++) {
		if (A[i] < 0)
			continue;
		Pos = Hash(A[i], N);
		if (Pos == i) {
			pair.Value = A[i]; pair.V = i;
			InsertMinHeap(H, pair);
		} else {
			if (Pos > i) ActualPos = i + N;
			else ActualPos = i;
			E = (Edge) malloc(sizeof(*E));	/* Insert an edge */
			for (j = Pos; j < ActualPos; j++) {
				E->V1 = j%N; E->V2 = i;
				InsertEdge(LG, E);
				Indegree[i]++;
			}
			free(E);
		}
	}
	return LG;
}

int TopSort(LGraph LG, MinHeap H, int Indeg[], KeyType A[], KeyType TopOrder[])
{
	Vertex V;
	PtrToAdjVNode W;
	Pair Out, In;
	int cnt = 0;

	while (!IsEmptyHeap(H)) {
		Out = DeleteMin(H);
		V = Out.V;
		TopOrder[cnt++] = Out.Value;
		for (W = LG->G[V].FirstEdge; W; W = W->Next)
			if (--Indeg[W->AdjV] == 0) {
				In.V = W->AdjV;
				In.Value = A[W->AdjV];
				InsertMinHeap(H, In);
			}
	}
	return cnt;
}

void Output(KeyType TopOrder[], int N)
{
	int i;

	printf("%d", TopOrder[0]);
	for (i = 1; i < N; i++)
		printf(" %d", TopOrder[i]);
	putchar('\n');
}

Index Hash(KeyType Key, int N)
{
	return Key % N;
}

LGraph CreateGraph(int VertexNum)
{
	LGraph LG;
	Vertex V;

	LG = (LGraph) malloc(sizeof(*LG));
	LG->Nv = VertexNum;
	LG->Ne = 0;
	for (V = 0; V < LG->Nv; V++)
		LG->G[V].FirstEdge = NULL;
	return LG;
}

void DestroyGraph(LGraph LG)
{
	Vertex V;
	PtrToAdjVNode T, t;

	for (V = 0; V < LG->Nv; V++) {
		T = LG->G[V].FirstEdge;
		while (T) {
			t = T->Next;
			free(T);
			T = t;
		}
	}
	free(LG);
}

void InsertEdge(LGraph LG, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V2;
	NewNode->Next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = NewNode;
}

MinHeap CreateHeap()
{
	MinHeap H;
	Pair pair;

	H = (MinHeap) malloc(sizeof(*H));
	H->Size = 0;

	pair.V = -1;
	pair.Value = MinData;
	H->Elems[0] = pair;

	return H;
}

void DestroyHeap(MinHeap H)
{
	free(H);
}

void InsertMinHeap(MinHeap H, ElementType X)
{
	int p;

	p = ++H->Size;
	H->Elems[p] = X;
	PercUp(H, p);
}

ElementType DeleteMin(MinHeap H)
{
	ElementType MinItem;

	MinItem = H->Elems[1];
	H->Elems[1] = H->Elems[H->Size--];
	PercDown(H, 1);

	return MinItem;
}

void PercUp(MinHeap H, int p)
{
	int i;
	ElementType X;

	for (i=p, X=H->Elems[p]; H->Elems[i/2].Value > X.Value; i /= 2)
		H->Elems[i] = H->Elems[i/2];
	H->Elems[i] = X;
}

void PercDown(MinHeap H, int p)
{
	int Parent, Child;
	ElementType Tmp = H->Elems[p];

	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && 
				(H->Elems[Child].Value > H->Elems[Child+1].Value))
			Child++;
		if (Tmp.Value <= H->Elems[Child].Value) break;
		else H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

bool IsEmptyHeap(MinHeap H)
{
	return H->Size == 0;
}

