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

#define MinData -1
#define MaxHeapSize MAXN*MAXN
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

// Graph related functions:
LGraph CreatGraph(int VertexNum);
void InsertEdge(LGraph LG, Edge E);
LGraph BuildGraph(int Nv, int Ne);
void DestroyGraph(LGraph LG);
// void InitPathAndDist(int N);

// Heap related functions:
Heap CreatHeap();
void DestroyHeap(Heap H);
Heap BuildHeap();
bool InsertHeap(Heap H, ElemType X);
bool IsFullH(Heap H);
bool IsEmptyH(Heap H);
void PercUp(MinHeap H, int p);
void PercDown(MinHeap H, int p);
ElemType DeleteMin(MinHeap H);

// Core functions:
void TraverlingPlan(LGraph LG);
void Dijkstra(LGraph LG, Vertex S);

// Global variables:
int N, M, S, D; // 2<=N<=500
LGraph LG;	// Solution guaranteed
bool collected[MAXN];
int dist[MAXN];
Vertex path[MAXN];
int cost[MAXN];

int main()
{
	freopen("data.txt", "r", stdin);
	scanf("%d %d %d %d", &N, &M, &S, &D);

	LG = BuildGraph(N, M);
	TraverlingPlan(LG);
	DestroyGraph(LG);

	return 0;
}

void TraverlingPlan(LGraph LG)
{
	Dijkstra(LG, S);
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
	return H->Size == 10000;
}

void PercDown(MinHeap H, int p)
{
	ElemType Tmp = H->Elems[p];
	int Parent, Child;

	for (Parent = p; 2*Parent <= H->Size; Parent = Child) {
		Child = 2 * Parent;
		// Find the child with smaller dist
		if (Child != H->Size && H->Elems[Child+1].dist < H->Elems[Child].dist)
			Child++;
		if (Tmp.dist <= H->Elems[Child].dist)
			break;
		else
			H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

/*
   Heap BuildHeap()
   {
   MinHeap H;
   int i;

   H = CreatHeap(LG->Nv);
   for (i = 0; i < LG->Nv; i++) {
   H->Elems[i+1].v = i;
   H->Elems[i+1].dist = dist[i];
   H->Size++;
   }
   for (i = H->Size/2; i > 0; i--)
   PercDown(H, i);
   return H;
   }
   */

void Dijkstra(LGraph LG, Vertex S)
{
	Vertex V;
	PtrToAdjVNode W;
	MinHeap H;
	Pair pair;

	// Initialize path[] and dist[]
	for (V = 0; V < LG->Nv; V++) {
		path[V] = -1;
		dist[V] = INFINITY;
		cost[V] = INFINITY;
		collected[V] = false;
	}
	// Initialize dist[S]=0 and adjacent vertices of S
	dist[S] = 0;
	cost[S] = 0;
	/*
	   collected[S] = true;
	   for (T = LG->G[S].FirstEdge; T; T = T->Next) {
	   dist[T->AdjV] = T->Weight.dist;
	   path[T->AdjV] = S;
	   }
	   */
	// Build a MinHeap (dist[] as key)
	// H = BuildHeap();
	H = CreatHeap();
	pair.v = S;
	pair.dist = dist[S];
	InsertHeap(H, pair);
	Pair kk;
	while (!IsEmptyH(H)) {
		// V = DeleteMin(H).v;
		kk = DeleteMin(H);
		// printf("v=%d, dist=%d\n", kk.v, kk.dist);
		V = kk.v;
		if (collected[V])
			continue;
		// printf("V=%d\n", V);
		collected[V] = true;
		/*
		// ----------------------
		Vertex v;
		printf("dist:");
		for (v=0; v<LG->Nv; v++)
		if (dist[v] == INFINITY) printf("  ∞");
		else printf(" %2d", dist[v]);
		putchar('\n');
		printf("path:");
		for (v=0; v<LG->Nv; v++)
		printf(" %2d", path[v]);
		putchar('\n');
		printf("cost:");
		for (v=0; v<LG->Nv; v++)
		if (cost[v] == INFINITY) printf("  ∞");
		else printf(" %2d", cost[v]);
		putchar('\n');
		// ----------------------
		*/
		for (W = LG->G[V].FirstEdge; W; W = W->Next)
			if (!collected[W->AdjV]) {
				if (dist[W->AdjV] > dist[V]+W->Weight.dist) {
					dist[W->AdjV] = dist[V]+W->Weight.dist;
					cost[W->AdjV] = cost[V]+W->Weight.cost;
					// Update dist[W->AdjV] in MinHeap and re-arrange heap
					pair.v = W->AdjV;
					pair.dist = dist[W->AdjV];
					InsertHeap(H, pair);
					path[W->AdjV] = V;
				} else if (dist[W->AdjV] == dist[V]+W->Weight.dist 
						&& cost[W->AdjV] > cost[V]+W->Weight.cost) {
					cost[W->AdjV] = cost[V]+W->Weight.cost;
					path[W->AdjV] = V;
				}
			}
	}
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

LGraph BuildGraph(int Nv, int Ne)
{
	LGraph LG;
	Edge E;
	int i;

	LG = CreatGraph(Nv);
	if (Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (i = 0; i < Ne; i++) {
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

