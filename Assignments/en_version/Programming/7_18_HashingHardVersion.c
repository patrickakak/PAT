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

typedef int Index;
typedef int KeyType;

#define MinData -1000
typedef struct {
	Vertex V;
	int Value;
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

// global variables:
KeyType A[MAXN];

Index Hash(KeyType Key, int N);

int main()
{
	int N, i, j;
	Index Pos, ActualPos;
	//KeyType Key;
	int Indegree[MAXN];
	LGraph LG;
	MinHeap Hp;
	Edge E;
	Pair pair;

	freopen("data.txt", "r", stdin);
	scanf("%d", &N);

	// Read input
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	// Init indegree array
	for (i = 0; i < N; i++) {
		Indegree[i] = 0;
	}

	Hp = CreateHeap();
	LG = CreateGraph(N);
	for (i = 0; i < N; i++) {
		if (A[i] == -1)
			continue;
		Pos = Hash(A[i], N);
		if (i == Pos) {
			pair.Value = A[i];
			pair.V = i;
			InsertMinHeap(Hp, pair);
		} else {
			if (Pos > i) ActualPos = i + N;
			else ActualPos = i;
			// InsertEdge
			E = (Edge) malloc(sizeof(*E));
			for (j = Pos; j < ActualPos; j++) {
				E->V1 = j%N;
				E->V2 = i;
				InsertEdge(LG, E);
				Indegree[i]++;
			}
			free(E);
		}
	}
	Vertex V;
	PtrToAdjVNode W;
	int TopOrder[MAXN];
	Pair Out, In;
	int cnt = 0;
	while (!IsEmptyHeap(Hp)) {
		Out = DeleteMin(Hp);
		V = Out.V;
		TopOrder[cnt++] = Out.Value;
		for (W = LG->G[V].FirstEdge; W; W = W->Next) {
			if (--Indegree[W->AdjV] == 0) {
				In.V = W->AdjV;
				In.Value = A[W->AdjV];
				InsertMinHeap(Hp, In);
			}
		}
	}
	printf("%d", TopOrder[0]);
	for (i = 1; i < cnt; i++) {
		printf(" %d", TopOrder[i]);
	}
	putchar('\n');
	/*
	//------------------
	int v;
	for (v=0; v<LG->Nv; v++) {
		printf("Indegree[%d]=%d\n", v, Indegree[v]);
	}
	//------------------
	*/
	/*
	//---------------------
	int v;
	PtrToAdjVNode w;
	for (v=0; v<LG->Nv; v++) {
		w = LG->G[v].FirstEdge;
		while (w) {
			printf(" #V%d->#V%d, (%d->%d)", v, w->AdjV, A[v], A[w->AdjV]);
			w = w->Next;
		}
		putchar('\n');
	}
	//---------------------
	*/
	DestroyGraph(LG);
	return 0;
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

void InsertMinHeap(MinHeap Hp, ElementType X)
{
	int p;

	p = ++Hp->Size;
	Hp->Elems[p] = X;
	PercUp(Hp, p);
}

ElementType DeleteMin(MinHeap Hp)
{
	ElementType MinItem;

	MinItem = Hp->Elems[1];
	Hp->Elems[1] = Hp->Elems[Hp->Size--];
	PercDown(Hp, 1);

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
		if (Tmp.Value <= H->Elems[Child].Value)
			break;
		else H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

bool IsEmptyHeap(MinHeap H)
{
	return H->Size == 0;
}

