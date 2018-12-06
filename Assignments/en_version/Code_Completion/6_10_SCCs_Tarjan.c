/**
 * 6-10: Find the strongly connected components in a digraph (Tarjan's algo)
 * (Note: Wrost T = O(V+E))
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

int Min(int a, int b)
{
	return a < b ? a : b;
}

/* DFS search produces a DFS tree/forest, a depth-first search begins from an 
 * arbitrary start node (and subsequent depth-first searches are conducted on 
 * any nodes that have not yet been found) 
 */
void Tarjan(Graph G, Vertex V, Stack S, bool onStack[], int ids[],
		int low[], int *id, void (*visit)(Vertex V))
{
	PtrToVNode W;
	Vertex X;

	Push(S, V);
	onStack[V] = true;
	ids[V] = low[V] = (*id)++;

	for (W = G->Array[V]; W; W = W->Next) {
		if (ids[W->Vert] == -1)
			Tarjan(G, W->Vert, S, onStack, ids, low, id, visit);
		if (onStack[W->Vert])
			low[V] = Min(low[V], low[W->Vert]);
	}

	if (ids[V] == low[V]) {
		while (1) {
			X = Pop(S);
			(*visit)(X);
			onStack[X] = false;
			if (X == V) break;
		}
		putchar('\n');
	}
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V))
{
	Vertex V;
	Stack S;
	bool onStack[MaxVertices];
	/* ids[]: timestamp of DFS visiting sequence, begin with id=0.
	 * low[]: the most dist ancestor's timestamp */
	int ids[MaxVertices], low[MaxVertices], id = 0;

	S = CreateStack(G->NumOfVertices);
	
	/* Initialize ids[], low[], onStack[] */
	for (V = 0; V < G->NumOfVertices; V++) {
		ids[V] = -1;
		low[V] = -1;
		onStack[V] = false;
	}

	/* For adjacent nodes, if vertex V is unvisited, do Tarjan's algo */
	for (V = 0; V < G->NumOfVertices; V++)
		if (ids[V] == -1)
			Tarjan(G, V, S, onStack, ids, low, &id, visit);

	DestroyStack(S);
}

