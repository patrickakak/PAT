/**
 * 6-17: Find the weighted shortest distances from any vertex to a given 
 * source vertex in a digraph. If there is more than one minimum path from 
 * v to w, a path with the fewest number of edges is chosen. It is guaranteed 
 * that all the weights are positive and such a path is unique for any vertex.
 * ---------------------------------------------------------------------------
 * Sample Input:
 * 8 11
 * 0 4 5
 * 0 7 10
 * 1 7 40
 * 3 0 40
 * 3 1 20
 * 3 2 100
 * 3 7 70
 * 4 7 5
 * 6 2 1
 * 7 5 3
 * 7 2 50
 * 3
 * Sample Output:
 * 40 20 100 0 45 53 -1 50 
 * 3 3 3 -1 0 7 -1 0 
 */
#define ERROR -1
#define MaxHeapSize MaxVertexNum*MaxVertexNum
#define MinData -1
typedef struct {
	Vertex v;
	int dis;
} Pair;
typedef Pair ElementType;

typedef struct HNode *PtrToHNode;
typedef PtrToHNode Heap;
typedef Heap MinHeap;
struct HNode {
	ElementType Elems[MaxHeapSize];
	int Size;
};

Heap CreatHeap()
{
	MinHeap H;

	H = (Heap) malloc(sizeof(*H));
	H->Elems[0].v = -1;
	H->Elems[0].dis = MinData;
	H->Size = 0;

	return H;
}

void DestroyHeap(Heap H)
{
	free(H);
}

void PercUp(MinHeap H, int p)
{
	int i;
	ElementType Tmp;

	for (i=p, Tmp=H->Elems[p]; H->Elems[i/2].dis > Tmp.dis; i /= 2)
		H->Elems[i] = H->Elems[i/2];
	H->Elems[i] = Tmp;
}

bool IsEmptyH(Heap H)
{
	return H->Size == 0;
}

bool IsFullH(Heap H)
{
	return H->Size+1 == MaxHeapSize;
}

bool InsertHeap(Heap H, ElementType X)
{
	int p;

	if (IsFullH(H))
		return false;
	p = ++H->Size;
	H->Elems[p] = X;
	PercUp(H, p);
	return true;
}

void PercDown(MinHeap H, int p)
{
	int Parent, Child;
	ElementType Tmp = H->Elems[p];

	for (Parent = p; 2*Parent <= H->Size; Parent = Child) {
		Child = 2 * Parent;
		if (Child!=H->Size && H->Elems[Child+1].dis<H->Elems[Child].dis)
			Child++;
		if (Tmp.dis <= H->Elems[Child].dis)
			break;
		else
			H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

ElementType DeleteMin(MinHeap H)
{
	Pair err = {-1, INFINITY};
	ElementType MinItem;

	if (IsEmptyH(H))
		return err;
	MinItem = H->Elems[1];
	H->Elems[1] = H->Elems[H->Size--];
	PercDown(H, 1);

	return MinItem;
}

void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;
	MinHeap H;
	Pair pair;

	/* When using min-heap and insert source vertex into it first, then we
	 * should initialize dist[] as INFINITY, otherwise 
	 * "dist[W] > dist[V]+weight<v,w>" will be skipped.
	 */ 
	for (V = 0; V < Graph->Nv; V++) {
		collected[V] = false;
		dist[V] = INFINITY;
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
	}

	H = CreatHeap();
	dist[S] = 0;
	pair.v = S; pair.dis = dist[S];
	InsertHeap(H, pair);

	while (!IsEmptyH(H)) {
		V = DeleteMin(H).v;
		if (collected[V]) continue;
		collected[V] = true;

		for (W = 0; W < Graph->Nv; W++)
			if (!collected[W] && Graph->G[V][W] < INFINITY)
				if (dist[W] > dist[V] + Graph->G[V][W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;
					pair.v = W; pair.dis = dist[W];
					InsertHeap(H, pair);
				}
	}
	DestroyHeap(H);
	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] == INFINITY) dist[V] = -1;
}

