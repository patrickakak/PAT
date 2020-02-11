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
Stack CreateStack(int Size) {
	Stack S = (Stack) malloc(sizeof(struct SNode));
	S->Data = (ElementType *) malloc(Size * sizeof(ElementType));
	S->Top = -1;
	S->StackSize = Size;
	return S;
}
void DestroyStack(Stack S) {
	free(S->Data);
	free(S);
}
bool IsFullS(Stack S) {
	return (S->Top == S->StackSize-1);
}
bool Push(Stack S, ElementType X) {
	if (IsFullS(S)) return false;
	else {
		S->Data[++S->Top] = X;
		return true;
	}
}
bool IsEmptyS(Stack S) {
	return (S->Top == -1);
}
ElementType Pop(Stack S) {
	if (IsEmptyS(S)) return ERROR;
	else return (S->Data[(S->Top)--]);
}
void DFS(Graph G, Vertex V, Stack S, bool visited[]) {
	visited[V] = true;
	for (PtrToVNode W = G->Array[V]; W; W = W->Next)
		if (!visited[W->Vert])
			DFS(G, W->Vert, S, visited);
	Push(S, V);
}
Graph CreateGraph(int VertexNum) {
	Graph gr = (Graph) malloc(sizeof(struct GNode));
	gr->NumOfVertices = VertexNum;
	gr->NumOfEdges = 0;
	gr->Array = (PtrToVNode *) malloc(gr->NumOfVertices * sizeof(PtrToVNode));
	for (Vertex V = 0; V < gr->NumOfVertices; V++)
		gr->Array[V] = NULL;
	return gr;
}
void InsertEdge(Graph gr, Edge E) {
	PtrToVNode NewNode = (PtrToVNode) malloc(sizeof(struct VNode));
	NewNode->Vert = E->V2;
	NewNode->Next = gr->Array[E->V1];
	gr->Array[E->V1] = NewNode;
}
Graph TransposeGraph(Graph G) {
	Graph TG = CreateGraph(G->NumOfVertices);
	TG->NumOfEdges = G->NumOfEdges;
	Edge E = (Edge) malloc(sizeof(struct ENode));
	for (Vertex V = 0; V < G->NumOfVertices; V++) {
		PtrToVNode W = G->Array[V];
		while (W) {
			E->V1 = W->Vert; E->V2 = V;
			InsertEdge(TG, E);
			W = W->Next;
		}
	}
	free(E);
	return TG;
}
void printSCCs(Graph TG, Vertex X, bool visited[], void (*visit)(Vertex V)) {
	visited[X] = true;
	(*visit)(X);
	for (PtrToVNode W = TG->Array[X]; W; W = W->Next)
		if (!visited[W->Vert])
			printSCCs(TG, W->Vert, visited, visit);
}
void InitVisited(bool visited[], int N) {
	for (int i = 0; i < N; i++) visited[i] = false;
}
void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)) {
	bool visited[MaxVertices];
	Stack S = CreateStack(G->NumOfVertices);
	InitVisited(visited, G->NumOfVertices);
	for (Vertex V = 0; V < G->NumOfVertices; V++)
		if (!visited[V])
			DFS(G, V, S, visited);
	Graph TG = TransposeGraph(G);
	InitVisited(visited, TG->NumOfVertices);
	while (!IsEmptyS(S)) {
		Vertex X = Pop(S);
		if (!visited[X]) {
			printSCCs(TG, X, visited, visit);
			putchar('\n');
		}
	}
	DestroyStack(S);
}
