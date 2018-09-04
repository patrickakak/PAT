#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Limit 6
#define MaxVertexNum 10001
bool visited[MaxVertexNum];
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
void BFS(Vertex V, MGraph Graph);

int main()
{
	MGraph G;
	Vertex V;

	G = BuildGraph();
	for (V = 1; V <= G->Nv; V++)
		BFS(V, G);

	return 0;
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
	if (Graph->Ne != 0) {
		E = (Edge) malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d", &E->V1, &E->V2);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

void BFS(Vertex V, MGraph Graph)
{
	Queue Q;
	Vertex CurV, W, Last;
	int i, Cnt = 1, Magnitude = 0; 	// 'Magnitude' to indicate the range of BFS
	double ratio;

	for (i = 1; i <= Graph->Nv; i++) visited[i] = false;
	visited[V] = true;
	Q = CreatQueue();
	Enqueue(Q, V);
	Last = Q->Data[Q->Rear];
	while (!IsEmptyQ(Q)) {
		CurV = Dequeue(Q);
		for (W = 1; W <= Graph->Nv; W++) {
			if (Graph->G[CurV][W] && !visited[W]) {
				visited[W] = true;
				Cnt++;
				Enqueue(Q, W);
			}
		}
		/* When the last layer handling of BFS is finished */
		if (CurV == Last) {
			Last = Q->Data[Q->Rear];
			Magnitude++;
			if (Magnitude >= Limit) break;
		}
	}
	ratio = (double)Cnt / Graph->Nv;
	ratio *= 100;
	printf("%d: %.2lf%%\n", V, ratio);
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
	if (IsFullQ(Q)) {
		printf("Queue full!\n");
		return;
	}
	Q->Rear = (Q->Rear + 1) % MaxVertexNum;
	Q->Data[Q->Rear] = Item;
}

int IsEmptyQ(Queue Q)
{
	return (Q->Front == Q->Rear);
}

ElementType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) {
		printf("Queue empty!\n");
		return -1;
	}
	Q->Front = (Q->Front + 1) % MaxVertexNum;
	return Q->Data[Q->Front];
}

