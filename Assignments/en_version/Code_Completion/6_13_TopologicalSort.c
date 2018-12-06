/**
 * 6-13: find the topological order in a digraph.
 * The topological sort cannot be successful if there is a cycle in the 
 * graph -- in that case TopSort must return false; otherwise return true.
 *
 * (Notice that the topological order might not be unique, but the judge's 
 * input guarantees the uniqueness of the result.)
 * -----------------------------------------------------------------------
 * Sample Input1:
 * 5 7
 * 1 0
 * 4 3
 * 2 1
 * 2 0
 * 3 2
 * 4 1
 * 4 2
 * Sample Output1:
 * 4 3 2 1 0 
 * ----------------
 * Sample Input2:
 * 5 8
 * 0 3
 * 1 0
 * 4 3
 * 2 1
 * 2 0
 * 3 2
 * 4 1
 * 4 2
 * Sample Ouput2:
 * ERROR
 */
#define ElementType Vertex
#define ERROR -1
typedef int Position;
typedef struct QNode *Queue;
struct QNode {
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
};

Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

void DestroyQueue(Queue Q)
{
	free(Q->Data);
	free(Q);
}

bool IsFull(Queue Q)
{
	return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool Enqueue(Queue Q, ElementType X)
{
	if (IsFull(Q))
		return false;
	else {
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
}

ElementType Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		return ERROR;
	else {
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}

bool TopSort(LGraph Graph, Vertex TopOrder[])
{
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue(MaxVertexNum);

	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;

	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;

	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);

	cnt = 0;
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		TopOrder[cnt++] = V;
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
	}

	if (cnt != Graph->Nv) return false;
	else return true;
}

