/**
 * Sample Input:
 * 6 15
 * 1 2 5
 * 1 3 3
 * 1 4 7
 * 1 5 4
 * 1 6 2
 * 2 3 4
 * 2 4 6
 * 2 5 2
 * 2 6 6
 * 3 4 6
 * 3 5 1
 * 3 6 1
 * 4 5 10
 * 4 6 8
 * 5 6 3
 * Sample Output:
 * 12
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000
typedef int Vertex;
typedef int WeightType;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
typedef struct VNode {
	PtrToAdjVNode FirstEdge;
} AdjList[MAXN];

typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

typedef Vertex ElementType;
typedef Vertex SetName;
typedef ElementType SetType[MAXN];

/**
 * Graph related functions:
 */
LGraph CreatGraph(int VertexNum);
void DestroyGraph(LGraph Graph);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph(int *AddrN, int *AddrM);

/**
 * MinHeap related functions:
 */
void PercDown(Edge ESet, int p, int N);
void Swap(Edge E1, Edge E2);
void InitializeESet(Edge ESet, LGraph Graph);
int GetEdge(Edge ESet, int CurrentSize);

/**
 * Union-Find related functions:
 */
void InitializeVSet(SetType S, int N);
void Union(SetType S, SetName Root1, SetName Root2);
SetName Find(SetType S, Vertex X);
bool CheckCycle(SetType VSet, Vertex V1, Vertex V2);

/**
 * Core functions:
 */
WeightType Kruskal(LGraph Graph, LGraph *pMST);

int main()
{
	int N, M;	/* 0<N<=1000, M<=3N */
	LGraph Graph, MST;
	WeightType TotalWeight;

	Graph = BuildGraph(&N, &M);

	TotalWeight = Kruskal(Graph, &MST);
	printf("%d\n", TotalWeight);

	DestroyGraph(Graph);
	DestroyGraph(MST);
	
	return 0;
}

/*-------------------- Graph definition --------------------*/
void InitializeVSet(SetType S, int N)
{
	ElementType X;

	for (X = 0; X < N; X++) S[X] = -1;
}

void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

SetName Find(SetType S, Vertex X)
{
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;

	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);

	if (Root1 == Root2)
		return false;
	else {
		Union(VSet, Root1, Root2);
		return true;
	}
}
/*-------------------- End of Union-Find definition --------------------*/

/*-------------------- MinHeap of edges definition --------------------*/
void PercDown(Edge ESet, int p, int N)
{
	int Parent, Child;
	struct ENode X;

	X = ESet[p];
	for (Parent = p; 2*Parent <= N; Parent = Child) {
		Child = 2 * Parent;
		if (Child!=N && ESet[Child].Weight>ESet[Child+1].Weight)
			Child++;
		if (X.Weight <= ESet[Child].Weight)
			break;
		else
			ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}

void Swap(Edge E1, Edge E2)
{
	struct ENode X;

	X = *E1; *E1 = *E2; *E2 = X;
}

void InitializeESet(Edge ESet, LGraph Graph)
{
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	ECount = 1;
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (V < W->AdjV) {
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}

	for (ECount = Graph->Ne/2; ECount > 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);
}

int GetEdge(Edge ESet, int CurrentSize)
{
	Swap(&ESet[1], &ESet[CurrentSize]);
	PercDown(ESet, 1, CurrentSize-1);

	return CurrentSize;
}
/*-------------------- MinHeap of edges definition --------------------*/

WeightType Kruskal(LGraph Graph, LGraph *pMST)
{
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;
	Edge ESet;

	InitializeVSet(VSet, Graph->Nv);
	ESet = (Edge) malloc((Graph->Ne+1) * sizeof(struct ENode));
	InitializeESet(ESet, Graph);

	*pMST = CreatGraph(Graph->Nv);
	TotalWeight = 0;
	ECount = 0;

	NextEdge = Graph->Ne;
	while (ECount < Graph->Nv-1) {
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge == 0)
			break;
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) {
			InsertEdge(*pMST, ESet+NextEdge);
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		}
		NextEdge--;
	}
	free(ESet);

	if (ECount != Graph->Nv-1)
		TotalWeight = -1;
	return TotalWeight;
}

/*-------------------- Graph definition --------------------*/
LGraph CreatGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph) malloc(sizeof(*Graph));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}

void DestroyGraph(LGraph Graph)
{
	Vertex V;
	PtrToAdjVNode T, t;

	for (V = 0; V < Graph->Nv; V++) {
		T = Graph->G[V].FirstEdge;
		while (T) {
			t = T->Next;
			free(T);
			T = t;
		}
	}
	free(Graph);
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(int *AddrN, int *AddrM)
{
	LGraph Graph;
	int Nv;
	Edge E;
	Vertex V;

	scanf("%d", &Nv);
	Graph = CreatGraph(Nv);
	scanf("%d", &Graph->Ne);
	*AddrN = Nv;
	*AddrM = Graph->Ne;
	if (Graph->Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (V = 0; V < Graph->Ne; V++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--; E->V2--;
			InsertEdge(Graph, E);
		}
		free(E);
	}
	return Graph;
}
/*-------------------- Graph definition --------------------*/

