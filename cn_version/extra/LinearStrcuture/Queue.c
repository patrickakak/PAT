/* Queue data structure (FIFO, n = MaxSize-1 to indicate full queue) */

/* defile ERROR, ElementType here */
typedef struct QNode *Queue;
struct QNode {
	ElementType *pData;
	int front; 	/* front: index of a cell in front of the 1st cell */
	int rear; 	/* rear: index of last cell */
	int Max; 	/* To store the size */
};

Queue CreatQueue(int MaxSize)
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->pData = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	Q->front = Q->rear = 0;
	Q->Max = MaxSize;
	return Q;
}

/* You can input MaxSize in main function */
int IsFullQ(Queue Q)
{
	return ((Q->rear+1)%(Q->Max) == Q->front);
}

void AddQ(Queue Q, ElementType item)
{
	if (IsFullQ(Q)) {
		printf("Queue full!\n");
		return;
	}
	Q->rear = (Q->rear+1)%(Q->Max);
	Q->pData[Q->rear] = item;
}

int IsEmptyQ(Queue Q)
{
	return (Q->front == Q->rear);
}

ElementType DeleteQ(Queue Q)
{
	if (IsEmptyQ(Q)) {
		printf("Queue empty!\n");
		return ERROR; 	/* Need to define ERROR */
	}
	Q->front = (Q->front+1)%(Q->Max);
	return Q->pData[Q->front];
}

