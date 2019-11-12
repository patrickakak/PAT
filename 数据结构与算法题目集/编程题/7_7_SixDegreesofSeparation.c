/**
 * Sample Input:
 * 10 9
 * 1 2
 * 2 3
 * 3 4
 * 4 5
 * 5 6
 * 6 7
 * 7 8
 * 8 9
 * 9 10
 * --------------
 * Sample Output:
 * 1: 70.00%
 * 2: 80.00%
 * 3: 90.00%
 * 4: 100.00%
 * 5: 100.00%
 * 6: 100.00%
 * 7: 100.00%
 * 8: 90.00%
 * 9: 80.00%
 * 10: 70.00%
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Vertex;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	PtrToAdjVNode Next;
};

#define MaxVertexNum 10000
typedef struct VNode *PtrToVNode;
typedef struct VNode {
	PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;		/* Number of vertices and edges */
	AdjList G;
};
typedef PtrToGNode Graph;
typedef Graph LGraph;

typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
};
typedef PtrToENode Edge;

#define ERROR -1
typedef int Position;
typedef Vertex ElemType;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElemType *Data;
	Position Front, Rear;
	int MaxQSize;
};
typedef PtrToQNode Queue;

/**
 * Graph related functions:
 */
Graph CreatGraph(int VertexNum);
void DestroyGraph(Graph graph);
void InsertEdge(Graph graph, Edge E);
Graph BuildGraph();

/**
 * Queue related functions: 
 */
Queue CreatQ(int QSize);
void DestroyQ(Queue Q);
bool IsFullQ(Queue Q);
bool IsEmptyQ(Queue Q);
bool Enqueue(Queue Q, ElemType X);
ElemType Dequeue(Queue Q);

/**
 * Core algorithm functions:
 */
void InitVisited(int N);
void SDS(Graph graph);

bool visited[MaxVertexNum];		/* Global array to help BFS algorithm */

int main()
{
	/**
	 * In this case: MAXN = 10000, so (N + 2*2E <= N^2), 
	 * we use graph adjacency list implementation instead 
	 */
	LGraph graph;

	graph = BuildGraph();
	SDS(graph); 	/* Six degrees of separation algorithm */
	DestroyGraph(graph);

	return 0;
}

void InitVisited(int N)
{
	int i;

	for (i = 0; i < N; i++)
		visited[i] = false;
}

int BFS(Graph graph, Vertex S)
{
	/* last and tail to indicate the last vertex of last level 
	 * and the tail of enqueue vertex respectively */
	int count, level, last, tail;
	Vertex V, W;
	Queue Q;
	PtrToAdjVNode T;

	InitVisited(graph->Nv);
	Q = CreatQ(MaxVertexNum);

	visited[S] = true;
	count = 1; level = 0; last = S;
	Enqueue(Q, S);

	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		for (T = graph->G[V].FirstEdge; T; T = T->Next) {
			W = T->AdjV;
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(Q, W);
				count++;
				tail = W;
			}
		}
		/* V equals to last to indidate vertices in last level 
		 * has been already handled */
		if (V == last) { level++; last = tail; }
		if (level == 6) break;
	}
	DestroyQ(Q);
	return count;
}

void SDS(Graph graph)
{
	Vertex V;
	int count;

	for (V = 0; V < graph->Nv; V++) {
		count = BFS(graph, V);
		printf("%d: %.2f%%\n", V+1, (double)100*count/graph->Nv);
	}
}

Graph CreatGraph(int VertexNum)
{
	Graph graph;
	Vertex V;

	graph = (Graph) malloc(sizeof(*graph));
	graph->Nv = VertexNum;
	graph->Ne = 0;

	for (V = 0; V < graph->Nv; V++)
		graph->G[V].FirstEdge = (PtrToAdjVNode)0;

	return graph;
}

void DestroyGraph(Graph graph)
{
	Vertex V;
	PtrToAdjVNode T, tmp;

	for (V = 0; V < graph->Nv; V++) {
		T = graph->G[V].FirstEdge;
		while (T) {
			tmp = T->Next;
			free(T);
			T = tmp;
		}
	}
	free(graph);
}

void InsertEdge(Graph graph, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V2;
	NewNode->Next = graph->G[E->V1].FirstEdge;
	graph->G[E->V1].FirstEdge = NewNode;

	/* Undirected Graphs, need to insert edge<V2, V1> also */

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V1;
	NewNode->Next = graph->G[E->V2].FirstEdge;
	graph->G[E->V2].FirstEdge = NewNode;
}

Graph BuildGraph()
{
	Graph graph;
	int Nv, i;
	Edge E;

	scanf("%d", &Nv);	/* 1<Nv<=10000 */
	graph = CreatGraph(Nv);
	scanf("%d", &graph->Ne);	/* Ne<=33*N */
	if (graph->Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (i = 0; i < graph->Ne; i++) {
			scanf("%d %d", &E->V1, &E->V2);
			E->V1--; E->V2--;
			InsertEdge(graph, E);
		}
		free(E);
	}
	return graph;
}

Queue CreatQ(int QSize)
{
	Queue Q = (Queue) malloc(sizeof(*Q));
	Q->Data = (ElemType *) malloc(QSize * sizeof(ElemType));
	Q->Front = Q->Rear = 0;
	Q->MaxQSize = QSize;
	return Q;
}

void DestroyQ(Queue Q)
{
	free(Q->Data);
	free(Q);
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
	if (IsFullQ(Q))
		return false;
	Q->Rear = (Q->Rear+1)%Q->MaxQSize;
	Q->Data[Q->Rear] = X;
	return true;
}

ElemType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q))
		return ERROR;
	Q->Front = (Q->Front+1)%Q->MaxQSize;
	return Q->Data[Q->Front];
}

