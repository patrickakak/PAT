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
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int Indegree[MaxVertexNum], cnt;
	Queue Q = CreateQueue(MaxVertexNum);
	for (Vertex V = 0; V < Graph->Nv; V++) Indegree[V] = 0;
	for (Vertex V = 0; V < Graph->Nv; V++)
		for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;

	for (Vertex V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);

	cnt = 0;
	while (!IsEmpty(Q)) {
		Vertex V = Dequeue(Q);
		TopOrder[cnt++] = V;
		for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
	}
	DestroyQueue(Q);
	if (cnt != Graph->Nv) return false;
	else return true;
}
