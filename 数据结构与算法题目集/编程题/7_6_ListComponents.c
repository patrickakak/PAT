/**
 * Sapmle Input:
 * 8 6
 * 0 7
 * 0 1
 * 2 0
 * 4 1
 * 2 4
 * 3 5
 * --------------
 * Sample Output:
 * { 0 1 4 2 7 }
 * { 3 5 }
 * { 6 }
 * { 0 1 2 7 4 }
 * { 3 5 }
 * { 6 }
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 10
#define INFINITY 65535
#define TAKEN 1
#define ERROR -1

typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode Graph;
typedef Graph MGraph;

typedef int Vertex;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
};
typedef PtrToENode Edge;

typedef Vertex ElemType;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElemType *Data;
	Position Front, Rear;
	int MaxQSize;
};
typedef PtrToQNode Queue;

/**
 * Building graph related functions:
 */

Graph CreatGraph(int MaxVertex);
Graph BuildGraph();
void InsertEdge(Graph graph, Edge E);
void DestroyGraph(Graph graph);
void Visit(Vertex V);

/**
 * Core handling functions:
 */
/* Depth First Search */
void DFS(Graph graph, Vertex V, void (*Visit)(Vertex));
/* Breadth First Search */
void BFS(Graph graph, Vertex S, void (*Visit)(Vertex));
void ResetVisited();
void ListComponents(Graph graph, 
		void (*Traverse)(Graph, Vertex, void (*Visit)(Vertex)));

/**
 * Queue related functions:
 */

void DestroyQ(Queue Q);
Queue CreatQ(int QSize);
bool IsFullQ(Queue Q);
bool IsEmptyQ(Queue Q);
bool Enqueue(Queue Q, ElemType X);
ElemType Dequeue(Queue Q);

/* Global variable array to indicate visitation */
bool visited[MaxVertexNum];

int main()
{
	MGraph graph;

	graph = BuildGraph();

	ListComponents(graph, DFS);
	ListComponents(graph, BFS);

	DestroyGraph(graph);
	return 0;
}

/* Initialize array visited */
void ResetVisited()
{
	int i;
	for (i = 0; i < MaxVertexNum; i++)
		visited[i] = false;
}

void ListComponents(Graph graph, 
		void (*Traverse)(Graph, Vertex, void (*Visit)(Vertex)))
{
	Vertex V;

	ResetVisited();
	for (V = 0; V < graph->Nv; V++)
		if (!visited[V]) {
			printf("{ ");
			Traverse(graph, V, Visit);
			printf("}\n");
		}
}

void Visit(Vertex V)
{
	printf("%d ", V);
}

/* Adjacent Matrix: T = O(N^2), Adjacent List: T = O(N+E) */
void DFS(Graph graph, Vertex V, void (*Visit)(Vertex))
{
	Vertex W;

	Visit(V);
	visited[V] = true;

	for (W = 0; W < graph->Nv; W++)
		if (!visited[W] && graph->G[V][W] != INFINITY)
			DFS(graph, W, Visit);
}

bool IsEdge(Graph graph, Vertex V, Vertex W)
{
	return graph->G[V][W] < INFINITY ? true : false;
}

/* Same with DFS algorithm */
void BFS(Graph graph, Vertex S, void (*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;

	Q = CreatQ(graph->Nv);
	Visit(S);
	visited[S] = true;
	Enqueue(Q, S);

	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < graph->Nv; W++)
			if (!visited[W] && IsEdge(graph, V, W)) {
				Visit(W);
				visited[W] = true;
				Enqueue(Q, W);
			}
	}
	DestroyQ(Q);
}

Graph CreatGraph(int MaxVertex)
{
	MGraph graph;
	Vertex V, W;

	graph = (MGraph) malloc(sizeof(*graph));
	graph->Nv = MaxVertex;
	graph->Ne = 0;

	for (V = 0; V < graph->Nv; V++)
		for (W = 0; W < graph->Nv; W++)
			graph->G[V][W] = INFINITY;
	return graph;
}

Graph BuildGraph()
{
	int Nv, i;
	MGraph graph;
	Edge E;

	scanf("%d", &Nv);
	graph = CreatGraph(Nv);
	scanf("%d", &graph->Ne);
	if (graph->Ne > 0) {
		E = (Edge) malloc(sizeof(*E));
		for (i = 0; i < graph->Ne; i++) {
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(graph, E);
		}
		free(E);
	}
	return graph;
}

void InsertEdge(Graph graph, Edge E)
{
	graph->G[E->V1][E->V2] = TAKEN;
	graph->G[E->V2][E->V1] = TAKEN;
}

void DestroyGraph(Graph graph)
{
	free(graph);
}

void DestroyQ(Queue Q)
{
	free(Q->Data);
	free(Q);
}

Queue CreatQ(int QSize)
{
	Queue Q = (Queue) malloc(sizeof(*Q));
	Q->Data = (ElemType *) malloc(QSize * sizeof(ElemType));
	Q->Front = Q->Rear = 0;
	Q->MaxQSize = MaxVertexNum;
	return Q;
}

bool IsFullQ(Queue Q)
{
	return (Q->Rear+1)%Q->MaxQSize == Q->Front;
}

bool IsEmptyQ(Queue Q)
{
	return Q->Front == Q->Rear;
}

bool Enqueue(Queue Q, ElemType X)
{
	if (IsFullQ(Q)) {
		puts("Full queue");
		return false;
	}
	Q->Rear = (Q->Rear+1) % Q->MaxQSize;
	Q->Data[Q->Rear] = X;
	return true;
}

ElemType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) {
		puts("Empty queue");
		return ERROR;
	}
	Q->Front = (Q->Front+1) % Q->MaxQSize;
	return Q->Data[Q->Front];
}

