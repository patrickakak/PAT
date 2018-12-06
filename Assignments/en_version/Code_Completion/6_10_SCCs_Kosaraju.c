/**
 * 6-10: Find the strongly connected components in a digraph (Kosaraju's algo)
 * (Note: Worst time complexity: T = O(V+E))
 *
 * Sample Input:
 * 4 5
 * 0 1
 * 1 2
 * 2 0
 * 3 1
 * 3 2
 * Sample Output:
 * 3
 * 1 2 0
 *
 * (Note: The output order does not matter. That is, a solution like)
 * 0 1 2
 * 3
 * is also considered correct.
 */
#include <stdbool.h>
#define ERROR -1
typedef Vertex ElementType;
typedef int Position;
typedef struct SNode *Stack;
struct SNode {
	ElementType *Data;
	Position Top;
	int StackSize;
};
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
struct ENode {
	Vertex V1, V2;
};

Stack CreateStack(int Size)
{
	Stack S;

	S = (Stack) malloc(sizeof(struct SNode));
	S->Data = (ElementType *) malloc(Size * sizeof(ElementType));
	S->Top = -1;
	S->StackSize = Size;
	return S;
}

void DestroyStack(Stack S)
{
	free(S->Data);
	free(S);
}

bool IsFullS(Stack S)
{
	return (S->Top == S->StackSize-1);
}

bool Push(Stack S, ElementType X)
{
	if (IsFullS(S))
		return false;
	else {
		S->Data[++S->Top] = X;
		return true;
	}
}

bool IsEmptyS(Stack S)
{
	return (S->Top == -1);
}

ElementType Pop(Stack S)
{
	if (IsEmptyS(S))
		return ERROR;
	else
		return (S->Data[(S->Top)--]);
}

void DFS(Graph G, Vertex V, Stack S, bool visited[])
{
	PtrToVNode W;

	visited[V] = true;
	for (W = G->Array[V]; W; W = W->Next)
		if (!visited[W->Vert])
			DFS(G, W->Vert, S, visited);
	Push(S, V);
}

Graph CreateGraph(int VertexNum)
{
	Graph gr;
	Vertex V;

	gr = (Graph) malloc(sizeof(struct GNode));
	gr->NumOfVertices = VertexNum;
	gr->NumOfEdges = 0;
	gr->Array = (PtrToVNode *) malloc(gr->NumOfVertices * sizeof(PtrToVNode));
	for (V = 0; V < gr->NumOfVertices; V++)
		gr->Array[V] = NULL;

	return gr;
}

void InsertEdge(Graph gr, Edge E)
{
	PtrToVNode NewNode;

	NewNode = (PtrToVNode) malloc(sizeof(struct VNode));
	NewNode->Vert = E->V2;
	NewNode->Next = gr->Array[E->V1];
	gr->Array[E->V1] = NewNode;
}

Graph TransposeGraph(Graph G)
{
	Graph TG;
	Edge E;
	Vertex V;
	PtrToVNode W;

	TG = CreateGraph(G->NumOfVertices);
	TG->NumOfEdges = G->NumOfEdges;
	E = (Edge) malloc(sizeof(struct ENode));
	for (V = 0; V < G->NumOfVertices; V++) {
		W = G->Array[V];
		while (W) {
			E->V1 = W->Vert; E->V2 = V;
			InsertEdge(TG, E);
			W = W->Next;
		}
	}
	free(E);
	return TG;
}

void printSCCs(Graph TG, Vertex X, bool visited[], void (*visit)(Vertex V))
{
	PtrToVNode W;

	visited[X] = true;
	(*visit)(X);
	for (W = TG->Array[X]; W; W = W->Next)
		if (!visited[W->Vert])
			printSCCs(TG, W->Vert, visited, visit);
}

void InitVisited(bool visited[], int N)
{
	int i;

	for (i = 0; i < N; i++)
		visited[i] = false;
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V))
{
	bool visited[MaxVertices];
	Stack S;
	Graph TG;
	Vertex V, X;

	S = CreateStack(G->NumOfVertices);
	InitVisited(visited, G->NumOfVertices);
	
	/* Push nodes into stack in DFS sequence: make timestamp */
	for (V = 0; V < G->NumOfVertices; V++)
		if (!visited[V])
			DFS(G, V, S, visited);

	/* Reverse directions of all arcs to obtain the transpose graph
	 *  Original Graph:               Transpose Graph:
	 *   --------                        --------
	 * 0 |  1   |->||                  0 |  2   |->||
	 *   --------                        --------  -------
	 * 1 |  2   |->||                  1 |  0   |->|  3  |->||
	 *   --------                        --------  -------
	 * 2 |  0   |->||                  2 |  1   |->|  3  |->||
	 *   --------  --------              --------  -------
	 * 3 |  1   |->|  2   |->||        3 | null |
	 *   --------  --------              --------
	 */
	TG = TransposeGraph(G);
	InitVisited(visited, TG->NumOfVertices);

	/* One by one pop a vertex from S while S is not empty. Let the popped 
	 * vertex be 'v'. Take v as source and do DFS (call DFSUtil(v)). The DFS 
	 * starting from v prints strongly connected component of v.
	 */
	while (!IsEmptyS(S)) {
		X = Pop(S);
		if (!visited[X]) {
			printSCCs(TG, X, visited, visit);
			putchar('\n');
		}
	}
	DestroyStack(S);
}

