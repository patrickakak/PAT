/* Queue data structure (FIFO, n = MaxSize-1 to indicate full queue) */

// defile ERROR, ElementType here
typedef struct QNode *Queue;
struct QNode {
	ElementType *pData;
	int          front; // front: index of a cell in front of the 1st cell
	int          rear;  // rear: index of last cell
};

Queue CreatQueue(int MaxSize)
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->pData = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	Q->front = Q->rear = 0;
	return Q;
}

// You can input MaxSize in main function
int IsFullQ(Queue Q, int MaxSize)
{
	return ((Q->rear+1)%MaxSize == Q->front);
}

void AddQ(Queue Q, ElementType item)
{
	if (IsFullQ(Q)) {
		printf("Queue full!\n");
		return;
	}
	Q->rear = (Q->rear+1)%MaxSize;
	Q->Data[Q->rear] = item;
}

int IsEmptyQ(Queue Q)
{
	return (Q->front == Q->rear);
}

ElementType DeleteQ(Queue Q)
{
	if (IsEmptyQ(Q)) {
		printf("Queue empty!\n");
		return ERROR; // Need to define ERROR
	}
	Q->front = (Q->front+1)%MaxSize;
	return Q->Data[Q->front];
}

