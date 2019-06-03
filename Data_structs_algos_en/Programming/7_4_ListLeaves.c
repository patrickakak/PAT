/* Sample Input:
 * 8
 * 1 -
 * - -
 * 0 -
 * 2 7
 * - -
 * - -
 * 5 -
 * 4 6
 * Sample Output:
 * 4 1 5
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
#define ERROR -1
#define Null -1
typedef int Tree;
struct TNode {
	Tree Left, Right;
} T[MaxSize];

typedef Tree ElemType;
typedef struct QNode *PtrToQNode;
struct QNode {
	int Front, Rear;
	int Max;
	ElemType *pData;
};
typedef PtrToQNode Queue;

Tree BuildTree(struct TNode T[]);
void LevelOrderTraversal(Tree R);
bool Enqueue(Queue Q, ElemType item);
ElemType Dequeue(Queue Q);
bool IsFullQ(Queue Q);
bool IsEmptyQ(Queue Q);
Queue CreatQ(int Size);
void DestroyQ(Queue Q);

int main()
{
	Tree R;

	R = BuildTree(T);
	LevelOrderTraversal(R);
	return 0;
}

Tree BuildTree(struct TNode T[])
{
	int i, N, Root=Null, check[MaxSize]; 	/* check[] to find out root */
	char cl, cr;

	scanf("%d\n", &N); 	/* Read the number of tree nodes */
	if (N) {
		for (i = 0; i < MaxSize; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			scanf("%c %c", &cl, &cr); getc(stdin);

			if (cl != '-') {
				T[i].Left = cl - '0'; 	/* '6'-'0' is 6 of integer */
				check[T[i].Left] = 1;
			} else
				T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			} else
				T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i]) break;
		Root = i;
	}
	return Root;
}

void LevelOrderTraversal(Tree R)
{
	Queue Q;
	Tree t;
	int flag = 0; 	/* To control output format */

	if (R == Null) return;
	Q = CreatQ(MaxSize);
	Enqueue(Q, R);
	while (!IsEmptyQ(Q)) {
		t = Dequeue(Q);
		if (T[t].Left==Null && T[t].Right==Null) { 	/* Print leaves of tree */
			if (!flag) flag = 1;
			else printf(" ");
			printf("%d", t);
		}
		if (T[t].Left != Null) Enqueue(Q, T[t].Left);
		if (T[t].Right != Null) Enqueue(Q, T[t].Right);
	}
	DestroyQ(Q);
	putchar('\n');
}

Queue CreatQ(int Size)
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = 0;
	Q->Max = Size;
	Q->pData = (ElemType *) malloc(Size * sizeof(ElemType));
	return Q;
}

void DestroyQ(Queue Q)
{
	free(Q->pData);
	free(Q);
}

bool Enqueue(Queue Q, ElemType item)
{
	if (IsFullQ(Q)) return false;
	Q->Rear = (Q->Rear+1) % Q->Max;
	Q->pData[Q->Rear] = item;
	return true;
}

ElemType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) return ERROR;
	Q->Front = (Q->Front+1) % Q->Max;
	return Q->pData[Q->Front];
}

bool IsFullQ(Queue Q)
{
	return (Q->Rear+1)%Q->Max == Q->Front;
}

bool IsEmptyQ(Queue Q)
{
	return Q->Front == Q->Rear;
}

