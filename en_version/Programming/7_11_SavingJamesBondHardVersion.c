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

// Functions:
MGraph CreatGraph(int VertexNum);
void DestroyGraph(MGraph MG);
bool Jump(Vertex V, Vertex W, int D);
MGraph BuildGraph();
Queue CreatQueue();
void DestroyQueue(Queue Q);
bool IsFullQ(Queue Q);
bool IsEmptyQ(Queue Q);
bool Enqueue(Queue Q, ElemType X);
ElemType Dequeue(Queue Q);
Stack CreatStack();
void DestroyStack(Stack S);
bool IsFullS(Stack S);
bool IsEmptyS(Stack S);
bool Push(Stack S, ElemType X);
ElemType Pop(Stack S);

bool IsSafe(Vertex V, int D);
void Save007(MGraph MG);
void InitPath(int N);
void InitDist(int N);
void Unweighted(MGraph MG, Vertex S);
void PrintPath(Vertex Path[], Vertex V);

// Global variables:
int N, D;
Coordinates Crocs[MAXN];
MGraph MG;
Vertex path[MAXN], ShotestPath[MAXN];
int dist[MAXN], ShotestDist[MAXN];
bool collected[MAXN];

int main()
{
	int i;

	// freopen("data.txt", "r", stdin);
	scanf("%d %d", &N, &D);

	if (R + D >= HalfSquareSide) {
		printf("1\n");
		return 0;
	}

	for (i = 0; i < N; i++)
		scanf("%d %d", &Crocs[i].x, &Crocs[i].y);
	MG = BuildGraph();
	/*
	//-------------------------
	int v, w;
	for (v=0; v<MG->Nv; v++) {
		for (w=0; w<MG->Nv; w++)
			if (MG->G[v][w] == INFINITY) printf(" ∞");
			else printf(" %d", MG->G[v][w]);
		putchar('\n');
	}
	//-------------------------
	*/
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
		for (W = 0; W<MG->Nv; W++) {
			if (MG->G[V][W] < INFINITY) {
				if (dist[W] == INFINITY) { // Unvisited
					dist[W] = dist[V]+1;
					path[W] = V;
					Enqueue(Q, W);
				}
			}
		}
	}
	DestroyQueue(Q);
}

void PrintPath(Vertex Path[], Vertex V)
{
	if (Path[V] == -1) {
		printf("%d %d\n", Crocs[V].x, Crocs[V].y);
	} else {
		PrintPath(Path, Path[V]);
		printf("%d %d\n", Crocs[V].x, Crocs[V].y);
	}
}

void Save007(MGraph MG)
{
	Vertex V, W;
	Stack Jar;
	int i, MinDist = INFINITY;
	Vertex Start = -1, End = -1;

	Jar = CreatStack();
	for (V = 0; V < MG->Nv; V++)
		if (IsSafe(V, D))
			Push(Jar, V);
	//////////////////
	/*
	   int k;
	   for (k=0; k<=Jar->Top; k++) {
	   printf("Jar->Elems[%d]=%d\n", k, Jar->Elems[k]);
	   }
	   */
	//////////////////
	for (V = 0; V < MG->Nv; V++) {
		if (FirstJump(V, D)) {
			/////////////////////////
			// printf("1stV=%d\n", V);
			////////////////////////
			InitPath(MG->Nv); InitDist(MG->Nv);
			Unweighted(MG, V);
			/*
			/////////////////////////
			int k;
			printf("dist:");
			for (k=0; k<MG->Nv; k++)
				if (dist[k] < INFINITY) printf(" %2d", dist[k]);
				else printf("  ∞");
			putchar('\n');
			printf("path:");
			for (k=0; k<MG->Nv; k++)
				printf(" %2d", path[k]);
			putchar('\n');
			////////////////////////
			*/
			for (i = 0; i <= Jar->Top; i++) {
				W = Jar->Elems[i];
				if (dist[W] < INFINITY) {
					if (MinDist > dist[W]) {
						MinDist = dist[W];
						Start = V;
						// SavePathAndDistAndCurrentW();
						memcpy(ShotestPath, path, MAXN);
						memcpy(ShotestDist, dist, MAXN);
						End = W;
					} else if (MinDist == dist[W]) {
						// If Firstep(CurV) < Firstep(Start)
						if (Crocs[V].x*Crocs[V].x + Crocs[V].y*Crocs[V].y 
								< Crocs[Start].x*Crocs[Start].x 
								+ Crocs[Start].y*Crocs[Start].y) {
							Start = V;
							// SavePathAndDistAndCurrentW();
							memcpy(ShotestPath, path, MAXN);
							memcpy(ShotestDist, dist, MAXN);
							End = W;
						}
					}
				}
			}
		}
	}
	DestroyStack(Jar);
	if (Start == -1) {
		printf("0\n");
	} else {
		printf("%d\n", ShotestDist[End]+2);
		PrintPath(ShotestPath, End);
	}
}

MGraph CreatGraph(int VertexNum)
{
	MGraph MG;
	Vertex V, W;

	MG = (MGraph) malloc(sizeof(*MG));
	MG->Nv = VertexNum;
	MG->Ne = 0;

	for (V = 0; V < MG->Nv; V++) {
		for (W = 0; W < MG->Nv; W++) {
			MG->G[V][W] = INFINITY;
		}
	}
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
	for (V = 0; V < MG->Nv; V++) {
		for (W = 0; W != V && W < MG->Nv; W++) {
			if (Jump(V, W, D)) {
				MG->G[V][W] = TAKEN;
				MG->G[W][V] = TAKEN;
			}
		}
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

