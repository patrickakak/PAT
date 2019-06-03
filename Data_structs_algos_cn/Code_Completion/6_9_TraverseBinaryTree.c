/** 
 * 6-9 Traverse the binary tree:
 *               A
 *              / \
 *             B   C
 *            / \  / \
 *           D  F  G  I
 *             /    \
 *            E      H
 * Sample Output:
 * Inorder: D B E F A G H C I
 * Preorder: A B D F E C G H I
 * Postorder: D E F B H G I C A
 * Levelorder: A B C D F G I E H
 */
void InorderTraversal(BinTree BT)
{
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT)
{
	if (BT) {
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT)
{
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

#include <stdbool.h>
#define ERROR NULL
typedef BinTree DataType;
typedef struct QueueRecord *PtrToQueueRecord;
typedef PtrToQueueRecord Que;
struct QueueRecord {
	DataType *Data;
	int Front, Rear;
	int MaxSize;
};

Que CreateQueue(int QSize)
{
	Que Q;

	Q = (Que) malloc(sizeof(struct QueueRecord));
	Q->Data = (DataType *) malloc(QSize * sizeof(DataType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = QSize;
	return Q;
}

void DestroyQueue(Que Q)
{
	free(Q->Data);
	free(Q);
}

bool IsFullQ(Que Q)
{
	return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool Enqueue(Que Q, DataType X)
{
	if (IsFullQ(Q)) {
		printf("Full queue");
		return false;
	} else {
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool IsEmptyQ(Que Q)
{
	return (Q->Front == Q->Rear);
}

DataType Dequeue(Que Q)
{
	if (IsEmptyQ(Q)) {
		printf("Empty queue");
		return ERROR;
	} else  {
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

void LevelorderTraversal(BinTree BT)
{
	DataType T;
	Que Q;
	const int QSize = 16;

	if (!BT) return;

	Q = CreateQueue(QSize);
	Enqueue(Q, BT);
	while (!IsEmptyQ(Q)) {
		T = Dequeue(Q);
		printf(" %c", T->Data);
		if (T->Left)
			Enqueue(Q, T->Left);
		if (T->Right)
			Enqueue(Q, T->Right);
	}
	DestroyQueue(Q);
}


