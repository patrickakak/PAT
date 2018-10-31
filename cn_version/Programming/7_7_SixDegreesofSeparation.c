#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define Limit 6
#define MaxVertexNum 10001

typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef int Vertex;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef Vertex ElementType;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElementType Data[MaxVertexNum];
	int Front, Rear;
};
typedef PtrToQNode Queue;

MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();
Queue CreatQueue();
int IsFullQ(Queue Q);
void Enqueue(Queue Q, ElementType Item);
int IsEmptyQ(Queue Q);
ElementType Dequeue(Queue Q);
void SDS(MGraph Graph);
int BFS(MGraph Graph, Vertex V, bool visited[]);

int main()
{
	MGraph Graph;

	Graph = BuildGraph();

	SDS(Graph);

	return 0;
}

void SDS(MGraph Graph)
{
	Vertex V;
	int count;
	bool visited[MaxVertexNum];

	for (V = 1; V <= Graph->Nv; V++) {
		memset(visited+1, false, Graph->Nv);
		count = BFS(Graph, V, visited);
		printf("%d: %.2f%%\n", V, 100*(double)count/Graph->Nv);
	}
}

int BFS(MGraph Graph, Vertex V, bool visited[])
{
	Vertex W;
	int count, level, last, tail;
	Queue Q;

	visited[V] = true;
	count = 1;
	level = 0;
	last = V;
	Q = CreatQueue();
	Enqueue(Q, V);
	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		for (W = 1; W <= Graph->Nv; W++)
			if (!visited[W] && Graph->G[V][W]) {
				visited[W] = true;
				Enqueue(Q, W);
				count++;
				tail = W;
			}
		/* When the last layer handling of BFS is finished */
		if (V == last) { level++; last = tail; }
		if (level == Limit) break;
	}
	return count;
}

MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/* Notes: the index of vertex from 1 To (Graph->Nv) by default */
	for (V = 1; V <= Graph->Nv; V++)
		for (W = 1; W <= Graph->Nv; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* Undirected Graphs, need to insert edge<V2, V1> also */
	Graph->G[E->V1][E->V2] = 1;
	Graph->G[E->V2][E->V1] = 1;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	scanf("%d", &Graph->Ne);
	if (Graph->Ne) {
		E = (Edge) malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

Queue CreatQueue()
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = 0;
	return Q;
}

int IsFullQ(Queue Q)
{
	return (Q->Rear + 1) % MaxVertexNum == Q->Front;
}

void Enqueue(Queue Q, ElementType Item)
{
	if (IsFullQ(Q)) { printf("Queue full!\n"); return; }
	Q->Rear = (Q->Rear + 1) % MaxVertexNum;
	Q->Data[Q->Rear] = Item;
}

int IsEmptyQ(Queue Q)
{
	return Q->Front == Q->Rear;
}

ElementType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) { printf("Queue empty!\n"); return -1; }
	Q->Front = (Q->Front + 1) % MaxVertexNum;
	return Q->Data[Q->Front];
}

