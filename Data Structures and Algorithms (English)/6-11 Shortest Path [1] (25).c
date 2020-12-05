#define ElementType Vertex
#define ERROR -1
typedef int Position;
typedef struct QNode *Queue;
struct QNode {
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
};
Queue CreateQueue(int MaxSize) {
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}
void DestroyQueue(Queue Q) {
	free(Q->Data);
	free(Q);
}
bool IsFull(Queue Q) {
	return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}
bool Enqueue(Queue Q, ElementType X) {
	if (IsFull(Q)) return false;
	else {
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}
bool IsEmpty(Queue Q) {
	return (Q->Front == Q->Rear);
}
ElementType Dequeue(Queue Q) {
	if (IsEmpty(Q)) return ERROR;
	else {
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}
void ShortestDist(LGraph Graph, int dist[], Vertex S) {
	for (Vertex V = 0; V < Graph->Nv; V++)
		dist[V] = -1;
	Queue Q = CreateQueue(Graph->Nv);
	dist[S] = 0;
	Enqueue(Q, S);
	while (!IsEmpty(Q)) {
		Vertex V = Dequeue(Q);
		for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (dist[W->AdjV] == -1) {
				dist[W->AdjV] = dist[V] + 1;
				Enqueue(Q, W->AdjV);
			}
	}
	DestroyQueue(Q);
}
