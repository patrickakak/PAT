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
int Min(int a, int b) {
	return a < b ? a : b;
}
void Tarjan(Graph G, Vertex V, Stack S, bool onStack[], int ids[], int low[], int *id, void (*visit)(Vertex V)) {
	Push(S, V);
	onStack[V] = true;
	ids[V] = low[V] = (*id)++;
	for (PtrToVNode W = G->Array[V]; W; W = W->Next) {
		if (ids[W->Vert] == -1) Tarjan(G, W->Vert, S, onStack, ids, low, id, visit);
		if (onStack[W->Vert]) low[V] = Min(low[V], low[W->Vert]);
	}
	if (ids[V] == low[V]) {
		while (1) {
			Vertex X = Pop(S);
			(*visit)(X);
			onStack[X] = false;
			if (X == V) break;
		}
		putchar('\n');
	}
}
void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)) {
	bool onStack[MaxVertices];
	int ids[MaxVertices], low[MaxVertices], id = 0;
	Stack S = CreateStack(G->NumOfVertices);
	for (Vertex V = 0; V < G->NumOfVertices; V++) {
		ids[V] = -1;
		low[V] = -1;
		onStack[V] = false;
	}
	for (Vertex V = 0; V < G->NumOfVertices; V++)
		if (ids[V] == -1) Tarjan(G, V, S, onStack, ids, low, &id, visit);
	DestroyStack(S);
}
