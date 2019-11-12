/**
 * Sample Input:
 * 11 14
 * 1 2 4
 * 1 3 3
 * 2 4 5
 * 3 4 3
 * 4 5 1
 * 4 6 6
 * 5 7 5
 * 6 7 2
 * 8 3 7
 * 9 3 7
 * 9 10 6
 * 4 10 2
 * 10 6 5
 * 6 11 4
 * Sample Output:
 * 21
 * 3->4
 * 4->10
 * 6->11
 * 8->3
 * 9->3
 * 10->6
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ERROR -1
#define INFINITY 65535
#define MAXN 100
typedef int Vertex;
typedef struct {
	int duration;
	int mobility;
} WeightType;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct DNode {
	int Earliest;
	int Latest;
} DataType;
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	WeightType G[MAXN][MAXN];
	DataType Data[MAXN];
};
typedef PtrToGNode MGraph;

typedef int Position;
typedef Vertex ElemType;
typedef struct QNode *PtrToQNode;
struct QNode {
	Position Front, Rear;
	ElemType Elems[MAXN];
};
typedef PtrToQNode Queue;

MGraph BuildGraph();
void DestroyGraph(MGraph MG);
MGraph CreatGraph(int VertexNum);
void InsertEdge(MGraph MG, Edge E);

Queue CreatQueue();
void DestroyQueue(Queue Q);
bool IsEmptyQ(Queue Q);
bool IsFullQ(Queue Q);
ElemType Dequeue(Queue Q);
bool Enqueue(Queue Q, ElemType X);

bool EarliestTime(MGraph MG);
void LatestTime(MGraph MG, Vertex Endchkpoint);
Vertex GetLastCheckPoint(MGraph MG);
void PrintCritical(MGraph MG);

int main()
{
	MGraph MG;
	Vertex Endchkpoint;		/* End check point with total project time */

	MG = BuildGraph();
	if (EarliestTime(MG) == false)	/* get earliest time of every vertex */
		puts("0");
	else {
		Endchkpoint = GetLastCheckPoint(MG);
		printf("%d\n", MG->Data[Endchkpoint].Earliest);
		/**
		 * Get latest time of every vertex:
		 * (Note: there could be multiple end check-points, so we pass 
		 * Endchkpoint as parameter to set every end check point)
		 * */
		LatestTime(MG, Endchkpoint);
		PrintCritical(MG);
	}
	DestroyGraph(MG);
	return 0;
}

void PrintCritical(MGraph MG)
{
	Vertex V, W;

	for (V = 0; V < MG->Nv; V++) {
		if (MG->Data[V].Earliest != MG->Data[V].Latest)
			continue;
		/**
		 * When there're more than one critical activities start from the same
		 * vertex (i.e. check-point), output the inversed sequence of input 
		 */
		for (W = MG->Nv-1; W >= 0; W--)
			if (MG->G[V][W].duration != INFINITY 
					&& (MG->Data[W].Latest - MG->Data[V].Earliest 
						- MG->G[V][W].duration == 0))
				printf("%d->%d\n", V+1, W+1);
	}
}

void LatestTime(MGraph MG, Vertex Endchkpoint)
{
	int Outdegree[MAXN];
	Vertex V, W;
	Queue Q = CreatQueue(MG->Nv);

	for (V = 0; V < MG->Nv; V++)	/* Initialize Outdegree[] */
		Outdegree[V] = 0;
	for (V = 0; V < MG->Nv; V++)
		for (W = 0; W < MG->Nv; W++)
			if (MG->G[V][W].duration != INFINITY)
				Outdegree[V]++;

	for (V = 0; V < MG->Nv; V++)	/* Set every end check-point */
		if (Outdegree[V] == 0) {
			MG->Data[V].Latest = MG->Data[Endchkpoint].Earliest;
			Enqueue(Q, V);
		}
	/**
	 * Update V.Latest = W.Latest-E<v,w>.duration when encountering 
	 * smaller latest time and E<v,w>.mobility = V.Latest - V.Earliest;
	 */
	while (!IsEmptyQ(Q)) { 	/* Inversed topsort(from end to start) */
		W = Dequeue(Q);
		for (V = 0; V < MG->Nv; V++)
			if (MG->G[V][W].duration != INFINITY) {
				if (MG->Data[V].Latest > 
						MG->Data[W].Latest - MG->G[V][W].duration)
					MG->Data[V].Latest = 
						MG->Data[W].Latest - MG->G[V][W].duration;
				if (--Outdegree[V] == 0)
					Enqueue(Q, V);
			}
	}
	DestroyQueue(Q);
}

bool EarliestTime(MGraph MG)
{
	int Indegree[MAXN], cnt;
	Vertex V, W;
	Queue Q = CreatQueue(MG->Nv);

	for (V = 0; V < MG->Nv; V++)	/* Initialize Indegree[] */
		Indegree[V] = 0;
	for (V = 0; V < MG->Nv; V++)
		for (W = 0; W < MG->Nv; W++)
			if (MG->G[V][W].duration != INFINITY)
				Indegree[W]++;

	for (V = 0; V < MG->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);
	/**
	 * if (V.earliest + duration(V,W) > W.earliest)
	 * W.earliest = V.earliest + duration;
	 */
	cnt = 0;
	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		cnt++;
		for (W = 0; W < MG->Nv; W++)
			if (MG->G[V][W].duration != INFINITY) {
				if (MG->Data[W].Earliest < 
						MG->Data[V].Earliest + MG->G[V][W].duration)
					MG->Data[W].Earliest = 
						MG->Data[V].Earliest + MG->G[V][W].duration;
				if (--Indegree[W] == 0)
					Enqueue(Q, W);
			}
	}
	DestroyQueue(Q);
	if (cnt != MG->Nv) return false;
	else return true;
}

Vertex GetLastCheckPoint(MGraph MG)
{
	Vertex V;
	Vertex Endchkpoint = 0;

	for (V = 0; V < MG->Nv; V++)
		if (MG->Data[V].Earliest > MG->Data[Endchkpoint].Earliest)
			Endchkpoint = V;
	return Endchkpoint;
}

MGraph BuildGraph()
{
	MGraph MG;
	int Nv;
	Vertex V;
	Edge E;

	scanf("%d", &Nv);
	MG = CreatGraph(Nv);
	scanf("%d", &MG->Ne);
	if (MG->Ne) {
		E = (Edge) malloc(sizeof(*E));
		for (V = 0; V < MG->Ne; V++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight.duration);
			E->Weight.mobility = 0;
			E->V1--; E->V2--;
			InsertEdge(MG, E);
		}
		free(E);
	}
	return MG;
}

void DestroyGraph(MGraph MG)
{
	free(MG);
}

MGraph CreatGraph(int VertexNum)
{
	MGraph MG;
	Vertex V, W;

	MG = (MGraph) malloc(sizeof(*MG));
	MG->Nv = VertexNum;
	MG->Ne = 0;
	/**
	 * Earliest = Max{V.earliest+E<v,w>.duration, FormerValueOfEarliest}
	 * Initialize Earliest=0 to let it can be incremented later, and init 
	 * latest=INFINITY to let it can be decreased.
	 */
	for (V = 0; V < MG->Nv; V++) {
		MG->Data[V].Earliest = 0;
		MG->Data[V].Latest = INFINITY;
		for (W = 0; W < MG->Nv; W++) {
			MG->G[V][W].duration = INFINITY;
			MG->G[V][W].mobility = 0;
		}
	}
	return MG;
}

void InsertEdge(MGraph MG, Edge E)
{
	MG->G[E->V1][E->V2] = E->Weight;
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

