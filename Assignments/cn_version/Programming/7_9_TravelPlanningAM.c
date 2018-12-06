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

#define MaxVertexNum 500
#define INFINITY 65535
#define ERROR -1
struct DNode {
	int dist, cost;
};
typedef struct DNode WeightType;

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

void InsertEdge(MGraph Graph, Edge E);
MGraph CreatGraph(int VertexNum);
MGraph BuildGrpah(Vertex *AddrS, Vertex *AddrD);
void TravelPlan(MGraph Graph, Vertex S, Vertex D);
void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S);

int main()
{
	MGraph Graph;
	Vertex S, D;
	
	Graph = BuildGrpah(&S, &D);
	TravelPlan(Graph, S, D);

	return 0;
}

MGraph CreatGraph(int VertexNum)
{
	MGraph Graph;
	Vertex V, W;
	
	Graph = (MGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	
	for (V = 0 ; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++) {
			Graph->G[V][W].dist = INFINITY;
			Graph->G[V][W].cost = INFINITY;
		}
	return Graph;
}

MGraph BuildGrpah(Vertex *AddrS, Vertex *AddrD)
{
	int N, i;
	MGraph Graph;
	Edge E;
	
	scanf("%d", &N);
	Graph = CreatGraph(N);
	scanf("%d", &Graph->Ne);
	scanf("%d %d", AddrS, AddrD);
	if (Graph->Ne) {
		E = (Edge) malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d %d", &E->V1, &E->V2, 
					&E->Weight.dist, &E->Weight.cost);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2].dist = E->Weight.dist;
	Graph->G[E->V1][E->V2].cost = E->Weight.cost;

	Graph->G[E->V2][E->V1].dist = E->Weight.dist;
	Graph->G[E->V2][E->V1].cost = E->Weight.cost;
}

/* Single-source shortest problem with a little modification */
void TravelPlan(MGraph Graph, Vertex S, Vertex D)
{
	int cost[MaxVertexNum], dist[MaxVertexNum];

	Dijkstra(Graph, dist, cost, S);
	printf("%d %d\n", dist[D], cost[D]);
}

Vertex FindMinDist(MGraph Graph, int dist[], bool collected[])
{
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY) return MinV;
	else return ERROR;
}

void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V].dist;
		cost[V] = Graph->G[S][V].cost;
		collected[V] = false;
	}
	dist[S] = 0;
	collected[S] = true;
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR)
			break;
		collected[V] = true;
		for (W = 0; W < Graph->Nv; W++)
			if (collected[W] == false && Graph->G[V][W].dist < INFINITY) {
				if (dist[V] + Graph->G[V][W].dist < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W].dist;
					cost[W] = cost[V] + Graph->G[V][W].cost;
				} else if ((dist[V] + Graph->G[V][W].dist == dist[W]) 
						&& (cost[V] + Graph->G[V][W].cost < cost[W]))
					cost[W] = cost[V] + Graph->G[V][W].cost;
			}
	}
}

