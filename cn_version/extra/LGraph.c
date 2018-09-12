#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10

typedef int Vertex; 	/* Using the index of vertex to represent a vertex */
typedef int WeightType;
typedef char DataType;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV; 		/* Index of adjacent node */
	WeightType Weight;	/* Weight */
	PtrToAdjVNode Next;
};

typedef struct VNode {
	PtrToAdjVNode FirstEdge;
	DataType Data; 	/* To store the data of vertex */
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;		/* Number of vertex */
	int Ne;		/* Number of edge   */
	AdjList G;	/* Adjacent List    */
};
typedef PtrToGNode LGraph;	/* Adjacent Graph */

typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;		/* Directed edge <V1, V2> */
	WeightType Weight;	/* Weight */
};
typedef PtrToENode Edge;

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();

int main()
{
	LGraph Graph;

	Graph = BuildGraph();

	return 0;
}

LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/* Notes: the index of vertex from 0 To (Graph->Nv-1) by default */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;	    // Or INFINITY

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/***** Insert an edge <V1, V2> *****/
	/* Make new adjacent node for V2 */
	NewNode = (PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;

	/* Insert V2 into the header of V1 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/***** If it's an undirected graph, need to insert edge<V2, V1> also *****/
	/* Make new adjacent node for V1 */
	NewNode = (PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;

	/* Insert V1 into the header of V2 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		E = (Edge) malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	/* If there's a need to read the data of vertex */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->G[V].Data));

	return Graph;
}

