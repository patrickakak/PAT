/**
 *       3
 *      / \
 *     5   6
 *    / \   \
 *   1   8  10
 *      /
 *     9
 * ---------------------------
 * Sample Output:
 * Level-order: 3 5 6 1 8 10 9
 */
#include <stdbool.h>
#define ERROR NULL
typedef Tree DataType;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
	DataType *Data;
	int Capacity;
	Position Front, Rear;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int QSize)
{
	Queue Q;

	Q = (Queue) malloc(sizeof(*Q));
	Q->Data = (DataType *) malloc(QSize * sizeof(DataType));
	Q->Front = Q->Rear = 0;
	Q->Capacity = QSize;
	return Q;
}

void DestroyQueue(Queue Q)
{
	free(Q->Data);
	free(Q);
}

bool IsFullQ(Queue Q)
{
	return (Q->Rear+1)%Q->Capacity == Q->Front;
}

bool IsEmptyQ(Queue Q)
{
	return Q->Front == Q->Rear;
}

bool Enqueue(Queue Q, DataType X)
{
	if (IsFullQ(Q)) return false;

	Q->Rear = (Q->Rear+1)%Q->Capacity;
	Q->Data[Q->Rear] = X;
	return true;
}

DataType Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) return ERROR;
	Q->Front = (Q->Front+1)%Q->Capacity;
	return Q->Data[Q->Front];
}

void Level_order(Tree T, void (*visit)(Tree ThisNode))
{
	Queue Q;
	DataType X;

	if (!T) return;
	Q = CreateQueue(32);
	Enqueue(Q, T);
	while (!IsEmptyQ(Q)) {
		X = Dequeue(Q);
		(*visit)(X);
		if (X->Left)
			Enqueue(Q, X->Left);
		if (X->Right)
			Enqueue(Q, X->Right);
	}
	DestroyQueue(Q);
}

