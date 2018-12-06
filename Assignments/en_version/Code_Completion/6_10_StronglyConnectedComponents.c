/**
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

void DFS(Graph G, Vertex V, Stack S, bool onStack[], int ids[],
		int low[], int *ptrId, void (*visit)(Vertex V))
{
	PtrToVNode W;
	Vertex X;

	Push(S, V);
	onStack[V] = true;
	ids[V] = low[V] = (*ptrId)++;

	for (W = G->Array[V]; W; W = W->Next) {
		if (ids[W->Vert] == -1)
			DFS(G, W->Vert, S, onStack, ids, low, ptrId, visit);
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
	int i, ids[MaxVertices], low[MaxVertices];
	bool onStack[MaxVertices];
	Stack S = CreateStack(G->NumOfVertices);
	int id = 0;

	// Init visited[], ids[], low[], onStack[]
	for (i = 0; i < G->NumOfVertices; i++) {
		ids[i] = -1; low[i] = -1;
		onStack[i] = false;
	}

	for (i = 0; i < G->NumOfVertices; i++) {
		// If vertex i is unvisited
		if (ids[i] == -1) {
			DFS(G, i, S, onStack, ids, low, &id, visit);
		}
	}
}

