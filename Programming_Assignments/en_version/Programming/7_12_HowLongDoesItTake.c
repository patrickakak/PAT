/**
 * Sample Input1:
 * 9 12
 * 0 1 6
 * 0 2 4
 * 0 3 5
 * 1 4 1
 * 2 4 1
 * 3 5 2
 * 5 4 0
 * 4 6 9
 * 4 7 7
 * 5 7 4
 * 6 8 2
 * 7 8 4
 * Sample Output1:
 * 18
 * ---------------
 * Sample Input2:
 * 4 5
 * 0 1 1
 * 0 2 2
 * 2 1 3
 * 1 3 4
 * 3 2 5
 * Sample Output2:
 * Impossible
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 100
#define ERROR -1

typedef int Vertex;
typedef int WeightType;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
typedef int DataType;
typedef struct VNode {
	PtrToAdjVNode FirstEdge;
	DataType Earliest;
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

typedef int Position;
typedef Vertex ElemType;
typedef struct QNode *PtrToQNode;
struct QNode {
	Position Front, Rear;
	ElemType Elems[MAXN];
};
typedef PtrToQNode Queue;

LGraph CreatGraph(int VertexNum);
LGraph BuildGraph();
void DestroyGraph(LGraph Graph);
void InsertEdge(LGraph Graph, Edge E);
Queue CreatQueue();
void DestroyQueue(Queue Q);
bool IsEmptyQ(Queue Q);
bool IsFullQ(Queue Q);
ElemType Dequeue(Queue Q);
bool Enqueue(Queue Q, ElemType X);
bool TopSort(LGraph Graph);

int main()
{
	LGraph Graph;
	Vertex V;
	int Max;

	Graph = BuildGraph();
	
	/* To check if the scheduling is possible(i.e. is it a DAG?) */
	if (TopSort(Graph) == false)
		puts("Impossible");
	else {
		for (Max = 0, V = 0; V < Graph->Nv; V++)	/* Multiple ends */
			if (Max  < Graph->G[V].Earliest)
				Max = Graph->G[V].Earliest;
		printf("%d\n", Max);
	}

	DestroyGraph(Graph);
	return 0;
}

bool TopSort(LGraph Graph)
{
	int Indegree[MAXN], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreatQueue(Graph->Nv);

	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;

	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;

	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);

	cnt = 0;
	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		cnt++;
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (Graph->G[W->AdjV].Earliest < Graph->G[V].Earliest+W->Weight)
				Graph->G[W->AdjV].Earliest = Graph->G[V].Earliest+W->Weight;
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
		}
	}
	DestroyQueue(Q);
	if (cnt != Graph->Nv) return false;
	else return true;
}

LGraph CreatGraph(int VertexNum)
{
	LGraph Graph;
	Vertex V;

	Graph = (LGraph) malloc(sizeof(*Graph));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++) {
		Graph->G[V].Earliest = 0;
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}

LGraph BuildGraph()
{
	LGraph Graph;
	int Nv;
	Edge E;
	Vertex V;

	scanf("%d", &Nv);
	Graph = CreatGraph(Nv);
	scanf("%d", &Graph->Ne);
	if (Graph->Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (V = 0; V < Graph->Ne; V++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
		free(E);
	}
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
}

Queue CreatQueue()
{
	Queue Q;

	Q = (Queue) malloc(sizeof(*Q));
	Q->Front = Q->Rear = 0;
	return Q;
}

void DestroyQueue(Queue Q)
{
	free(Q);
}

bool IsEmptyQ(Queue Q)
{
	return Q->Front == Q->Rear;
}

bool IsFullQ(Queue Q)
{
	return (Q->Rear+1)%MAXN == Q->Front;
}

bool Enqueue(Queue Q, ElemType X)
{
	if (IsFullQ(Q))
		return false;
	Q->Rear = (Q->Rear+1)%MAXN;
	Q->Elems[Q->Rear] = X;
	return true;
}

ElemType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q))
		return ERROR;
	Q->Front = (Q->Front+1)%MAXN;
	return Q->Elems[Q->Front];
}

