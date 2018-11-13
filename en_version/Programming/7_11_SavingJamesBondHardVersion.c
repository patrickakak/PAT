/**
 * Sample Input1:
 * 17 15
 * 10 -21
 * 10 21
 * -40 10
 * 30 -50
 * 20 40
 * 35 10
 * 0 -10
 * -25 22
 * 40 -40
 * -30 30
 * -10 22
 * 0 11
 * 25 21
 * 25 10
 * 10 10
 * 10 35
 * -30 10
 * Sample Output1:
 * 4
 * 0 11
 * 10 21
 * 10 35
 * --------------
 * Sample Input2:
 * 4 13
 * -12 12
 * 12 12
 * -12 -12
 * 12 -12
 * Sample Output2:
 * 0
 *  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define R 7.5
#define MAXN 100
#define TAKEN 1
#define INFINITY 65535
#define HalfSquareSide 50
#define ERROR -1

typedef struct {
	int x, y;
} Coordinates;

typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	WeightType G[MAXN][MAXN];
};
typedef PtrToGNode MGraph;
typedef int Vertex;

typedef int Position;
typedef Vertex ElemType;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElemType Elems[MAXN];
	Position Front, Rear;
};
typedef PtrToQNode Queue;

typedef struct SNode *PtrToSNode;
struct SNode {
	ElemType Elems[MAXN];
	int Top;
};
typedef PtrToSNode Stack;

typedef struct {
	Vertex Start, End;
} Pair;

/**
 * Graph related functions:
 */
MGraph CreatGraph(int VertexNum);
void DestroyGraph(MGraph MG);
bool Jump(Vertex V, Vertex W, int D);
MGraph BuildGraph();

/**
 * Queue related functions:
 */
Queue CreatQueue();
void DestroyQueue(Queue Q);
bool IsFullQ(Queue Q);
bool IsEmptyQ(Queue Q);
bool Enqueue(Queue Q, ElemType X);
ElemType Dequeue(Queue Q);

/**
 * Stack related functions:
 */
Stack CreatStack();
void DestroyStack(Stack S);
bool IsFullS(Stack S);
bool IsEmptyS(Stack S);
bool Push(Stack S, ElemType X);
ElemType Pop(Stack S);

/**
 * Core functions:
 */
bool IsSafe(Vertex V, int D);
void Save007(MGraph MG);
void InitPath(int N);
void InitDist(int N);
void Unweighted(MGraph MG, Vertex S);
void PrintPath(Vertex Path[], Vertex V);
void UpdatePair(Pair *pPiar, Vertex V, Vertex W, int *pMinDist);

/**
 * Global variables:
 */
int N, D, dist[MAXN], ShotestDist[MAXN];
Coordinates Crocs[MAXN];
MGraph MG;
Vertex path[MAXN], ShotestPath[MAXN];

int main()
{
	Vertex V;

	scanf("%d %d", &N, &D);

	if (R + D >= HalfSquareSide) {	/* Can reach bank directly */
		puts("1");
		return 0;
	}

	for (V = 0; V < N; V++)
		scanf("%d %d", &Crocs[V].x, &Crocs[V].y);

	MG = BuildGraph();	/* Build a unweighted and undirected graph */

	Save007(MG);

	DestroyGraph(MG);

	return 0;
}

bool FirstJump(Vertex V, int D)
{
	return (D+R)*(D+R) >= Crocs[V].x*Crocs[V].x + Crocs[V].y*Crocs[V].y;
}

void Unweighted(MGraph MG, Vertex S)
{
	Queue Q;
	Vertex V, W;

	Q = CreatQueue(MG->Nv);
	dist[S] = 0;
	Enqueue(Q, S);

	while (!IsEmptyQ(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < MG->Nv; W++)
			if (MG->G[V][W] < INFINITY && dist[W] == INFINITY) {
				dist[W] = dist[V]+1;
				path[W] = V;
				Enqueue(Q, W);
			}
	}
	DestroyQueue(Q);
}

void PrintPath(Vertex Path[], Vertex V)
{
	if (Path[V] != -1)
		PrintPath(Path, Path[V]);
	printf("%d %d\n", Crocs[V].x, Crocs[V].y);
}

/* Update first vertex V and the last vertex W of the shotest path */

void UpdatePair(Pair *pPair, Vertex V, Vertex W, int *pMinDist)
{
	if (*pMinDist > dist[W]) {
		*pMinDist = dist[W];
		pPair->Start = V; pPair->End = W;

		/* Save path[], dist[] array and current W 
		 * (parameter three is of type size_t) */

		memcpy(ShotestPath, path, MG->Nv*sizeof(int));
		memcpy(ShotestDist, dist, MG->Nv*sizeof(int));
	}
	/* Same shotest length path is found */
	else if (*pMinDist == dist[W] && 
			Crocs[V].x * Crocs[V].x + Crocs[V].y * Crocs[V].y 
			< Crocs[pPair->Start].x * Crocs[pPair->Start].x
			+ Crocs[pPair->Start].y * Crocs[pPair->Start].y) {
		pPair->Start = V;
		pPair->End = W;
		memcpy(ShotestPath, path, MG->Nv*sizeof(int));
		memcpy(ShotestDist, dist, MG->Nv*sizeof(int));
	}
}

void Save007(MGraph MG)
{
	Vertex V, W;
	Stack Jar;
	int i, MinDist = INFINITY;
	Pair pair;

	pair.Start = pair.End = -1;
	Jar = CreatStack();
	/* Find those vertices that can reach bank directly */
	for (V = 0; V < MG->Nv; V++)
		if (IsSafe(V, D))
			Push(Jar, V);

	for (V = 0; V < MG->Nv; V++)
		if (FirstJump(V, D)) {
			InitPath(MG->Nv); InitDist(MG->Nv);
			/**
			 * If vertex V can be firstjumped, then use BFS algorithm to get 
			 * minimal dist[] of a (connected or not) graph (SSSP problem) 
			 */
			Unweighted(MG, V);
			/**
			 * To see whether we can reach those vertices in Jar container,
			 * if so, then we find a shotest way out, don't forget to update 
			 * until we find the path with minimal-wide first step 
			 */
			for (i = 0; i <= Jar->Top; i++) {
				W = Jar->Elems[i];
				if (dist[W] < INFINITY)
					UpdatePair(&pair, V, W, &MinDist);
			}
		}
	DestroyStack(Jar);
	if (pair.Start == -1)
		puts("0");
	else {
		/* Plus two steps of first and last jump */
		printf("%d\n", ShotestDist[pair.End]+2);
		PrintPath(ShotestPath, pair.End);
	}
}

MGraph CreatGraph(int VertexNum)
{
	MGraph MG;
	Vertex V, W;

	MG = (MGraph) malloc(sizeof(*MG));
	MG->Nv = VertexNum;
	MG->Ne = 0;

	for (V = 0; V < MG->Nv; V++)
		for (W = 0; W < MG->Nv; W++)
			MG->G[V][W] = INFINITY;
	return MG;
}

void DestroyGraph(MGraph MG)
{
	free(MG);
}

bool Jump(Vertex V, Vertex W, int D)
{
	return D*D >= (Crocs[V].x-Crocs[W].x)*(Crocs[V].x-Crocs[W].x) 
		+ (Crocs[V].y-Crocs[W].y)*(Crocs[V].y-Crocs[W].y);
}

MGraph BuildGraph()
{
	MGraph MG;
	Vertex V, W;

	MG = CreatGraph(N);
	for (V = 0; V < MG->Nv; V++)
		for (W = 0; W != V && W < MG->Nv; W++)
			if (Jump(V, W, D)) {
				MG->G[V][W] = TAKEN;
				MG->G[W][V] = TAKEN;
			}
	return MG;
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

bool IsFullQ(Queue Q)
{
	return (Q->Rear+1)%MAXN == Q->Front;
}

bool IsEmptyQ(Queue Q)
{
	return (Q->Front == Q->Rear);
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

void InitPath(int N)
{
	int i;

	for (i = 0; i < N; i++)
		path[i] = -1;
}

void InitDist(int N)
{
	int i;

	for (i = 0; i < N; i++)
		dist[i] = INFINITY;
}

Stack CreatStack()
{
	Stack S;

	S = (Stack) malloc(sizeof(*S));
	S->Top = -1;
	return S;
}

void DestroyStack(Stack S)
{
	free(S);
}

bool IsFullS(Stack S)
{
	return S->Top+1 == MAXN;
}

bool IsEmptyS(Stack S)
{
	return S->Top == -1;
}

bool Push(Stack S, ElemType X)
{
	if (IsFullS(S))
		return false;
	S->Elems[++S->Top] = X;
	return true;
}

ElemType Pop(Stack S)
{
	if (IsEmptyS(S))
		return ERROR;
	return S->Elems[S->Top--];
}

bool IsSafe(Vertex V, int D)
{
	int AbsX, AbsY;

	AbsX = Crocs[V].x > 0 ? Crocs[V].x : -Crocs[V].x;
	AbsY = Crocs[V].y > 0 ? Crocs[V].y : -Crocs[V].y;

	return (AbsX+D)>=HalfSquareSide || (AbsY+D)>=HalfSquareSide;
}

