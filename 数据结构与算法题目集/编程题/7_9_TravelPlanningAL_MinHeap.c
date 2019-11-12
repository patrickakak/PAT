/**
 * Sample Input:
 * 4 5 0 3
 * 0 1 1 20
 * 1 3 2 30
 * 0 3 4 10
 * 0 2 2 20
 * 2 3 1 20
 * Sample Output:
 * 3 40
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 65535
#define MAXN 500
typedef int Vertex;
typedef struct {
	int dist, cost;
} WeightType;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
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

/* The nuber of vertices in MinHeap can be larger than MAXN 
 * because we insert v regardless of old v may is in there */
#define MaxHeapSize MAXN*MAXN
#define MinData -1
typedef struct {
	Vertex v;
	int dist;
} Pair;
typedef Pair ElemType;

typedef struct HNode *PtrToHNode;
struct HNode {
	ElemType Elems[MaxHeapSize];
	int Size;
};
typedef PtrToHNode Heap;
typedef Heap MinHeap;

/**
 * Assistant functions: 
 */
LGraph CreatGraph(int VertexNum);
void InsertEdge(LGraph LG, Edge E);
LGraph BuildGraph(Vertex *pS, Vertex *pD);
void DestroyGraph(LGraph LG);
Heap CreatHeap();
void DestroyHeap(Heap H);
Heap BuildHeap();
bool InsertHeap(Heap H, ElemType X);
bool IsFullH(Heap H);
bool IsEmptyH(Heap H);
void PercUp(MinHeap H, int p);
void PercDown(MinHeap H, int p);
ElemType DeleteMin(MinHeap H);

/**
 * Core functions: 
 */
void TravelPlan(LGraph LG, Vertex S, Vertex D);
void Dijkstra(LGraph LG, int dist[], int cost[], Vertex S);

int main()
{
	LGraph LG;	/* Solution guaranteed */
	Vertex S, D;

	LG = BuildGraph(&S, &D);

	TravelPlan(LG, S, D);

	DestroyGraph(LG);

	return 0;
}

void TravelPlan(LGraph LG, Vertex S, Vertex D)
{
	int cost[MAXN], dist[MAXN];

	Dijkstra(LG, dist, cost, S);
	printf("%d %d\n", dist[D], cost[D]);
}

Heap CreatHeap()
{
	MinHeap H;

	H = (Heap) malloc(sizeof(*H));
	H->Elems[0].v = -1;
	H->Elems[0].dist = MinData;
	H->Size = 0;

	return H;
}

void DestroyHeap(Heap H)
{
	free(H);
}

void PercUp(MinHeap H, int p)
{
	int i;
	ElemType Tmp;

	for (i=p, Tmp=H->Elems[p]; H->Elems[i/2].dist > Tmp.dist; i /= 2)
		H->Elems[i] = H->Elems[i/2];
	H->Elems[i] = Tmp;
}

bool InsertHeap(Heap H, ElemType X)
{
	int p;

	if (IsFullH(H))
		return false;
	p = ++H->Size;
	H->Elems[p] = X;
	PercUp(H, p);
	return true;
}

ElemType DeleteMin(MinHeap H)
{
	Pair ERROR = {-1, INFINITY};
	ElemType MinItem;

	if (IsEmptyH(H))
		return ERROR;
	MinItem = H->Elems[1];
	H->Elems[1] = H->Elems[H->Size--];
	PercDown(H, 1);

	return MinItem;
}

bool IsEmptyH(Heap H)
{
	return H->Size == 0;
}

bool IsFullH(Heap H)
{
	return H->Size+1 == MaxHeapSize;
}

void PercDown(MinHeap H, int p)
{
	int Parent, Child;
	ElemType Tmp = H->Elems[p];

	for (Parent = p; 2*Parent <= H->Size; Parent = Child) {
		Child = 2 * Parent;
		if (Child!=H->Size && H->Elems[Child+1].dist<H->Elems[Child].dist)
			Child++;
		if (Tmp.dist <= H->Elems[Child].dist)
			break;
		else
			H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

void Dijkstra(LGraph LG, int dist[], int cost[], Vertex S)
{
	bool collected[MAXN];
	Vertex V;
	PtrToAdjVNode W;
	MinHeap H;
	Pair pair;

	/* Initialize path[], dist[], cost[] and collected[] */
	for (V = 0; V < LG->Nv; V++) {
		dist[V] = cost[V] = INFINITY;
		collected[V] = false;
	}
	/* Initialize dist[S]=0 and insert it into MinHeap */
	H = CreatHeap();	/* Create a MinHeap (dist[] as key) */
	dist[S] = cost[S] = 0;
	pair.v = S; pair.dist = dist[S];
	InsertHeap(H, pair);

	/**
	 * Distance is used as first item of pair as first item is by default 
	 * used to compare two pairs, second item v is used to indicate visitation.
	 *
	 * If dist[v] > dist[u]+weight(u, v), update cost[w] and dist[w] in 
	 * MinHeap heap, because of we insert a pair insted of a vertex, we can 
	 * insert v into the MinHeap (Even if v is already there)
	 */
	while (!IsEmptyH(H)) {

		V = DeleteMin(H).v;
		if (collected[V]) continue;
		collected[V] = true;

		for (W = LG->G[V].FirstEdge; W; W = W->Next)
			if (!collected[W->AdjV]) {
				if (dist[W->AdjV] > dist[V]+W->Weight.dist) {
					dist[W->AdjV] = dist[V]+W->Weight.dist;
					cost[W->AdjV] = cost[V]+W->Weight.cost;
					pair.v = W->AdjV; pair.dist = dist[W->AdjV];
					InsertHeap(H, pair);
				} else if (dist[W->AdjV] == dist[V]+W->Weight.dist 
						&& cost[W->AdjV] > cost[V]+W->Weight.cost)
					cost[W->AdjV] = cost[V] + W->Weight.cost;
			}
	}
	DestroyHeap(H);
}

LGraph CreatGraph(int VertexNum)
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

void InsertEdge(LGraph LG, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = LG->G[E->V2].FirstEdge;
	LG->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(Vertex *pS, Vertex *pD)
{
	LGraph LG;
	Edge E;
	int Nv, i;

	scanf("%d", &Nv);
	LG = CreatGraph(Nv);
	scanf("%d", &LG->Ne);
	scanf("%d %d", pS, pD);
	if (LG->Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (i = 0; i < LG->Ne; i++) {
			scanf("%d %d %d %d", &E->V1, &E->V2, 
					&E->Weight.dist, &E->Weight.cost);
			InsertEdge(LG, E);
		}
		free(E);
	}
	return LG;
}

void DestroyGraph(LGraph LG)
{
	Vertex V;
	PtrToAdjVNode T, tmp;

	for (V = 0; V < LG->Nv; V++) {
		T = LG->G[V].FirstEdge;
		while (T) {
			tmp = T->Next;
			free(T);
			T = tmp;
		}
	}
	free(LG);
}

