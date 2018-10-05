/* Adjacency list: Kruskal algorithm to generate minimum spinning tree */

/*-------------------- Start of Union-Find definition --------------------*/
typedef Vertex ElementType;	/* element type can be represented as non-negtive integer */
typedef Vertex SetName;		/* Set index of root node as the name of a set */
typedef ElementType SetType[MaxVertexNum];	/* Indices of Set elements begin with 0 */

/* Initialize vertices Set */
void InitializeVSet(SetType S, int N)
{
	ElementType X;

	for (X = 0; X < N; X++) S[X] = -1;
}

/* Roo1 and Root2 represent different root node of different sets by default */
void Union(SetType S, SetName Root1, SetName Root2)
{
	/* Small Set absorbed into a bigger one Guaranteed */
	if ( S[Root2] < S[Root1] ) {	/* If Set2 is larger */
		S[Root2] += S[Root1];	/* Merge Set1 into Set2 */
		S[Root1] = Root2;
	} else {	/* If set1 is larger */
		S[Root1] += S[Root2];	/* Merge Set2 into Set1 */
		S[Root2] = Root1;
	}
}

/* Initialize elements in Set as -1 */
SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0)	/* Find the root of Set */
		return X;
	else
		return S[X] = Find(S, S[X]);	/* Path compression */
}

/* To check the edge (V1-V2) can cause a cycle in current MST */
bool CheckCycle(SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;

	Root1 = Find(VSet, V1);		/* To get the root of set of V1 */
	Root2 = Find(VSet, V2);		/* To get the root of set of V2 */

	if (Root1 == Root2)		/* If V1 and V2 are in one Set already, don't take this edge */
		return false;
	else {	/* If the edge is collectable, merge the sets of V1 and V2 */
		Union(VSet, Root1, Root2);
		return true;
	}
}
/*-------------------- End of Union-Find definition --------------------*/

/*-------------------- MinHeap of edges definition --------------------*/
void PercDown(Edge ESet, int p, int N)
{
	int Parent, Child;
	struct ENode X;

	X = ESet[p];	/* Get the value in root node */
	for (Parent=p; (Parent*2+1) < N; Parent=Child) {
		Child = Parent * 2 + 1;
		if ((Child != N-1) && (ESet[Child].Weight > ESet[Child+1].Weight))
			Child++;
		if (X.Weight <= ESet[Child].Weight) break; /* Find the right position */
		else  /* Percolate X down */
			ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}

/* Save edges into ESet, and initialize it as Min-heap */
void InitializeESet(LGraph Graph, Edge ESet)
{
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	/* Save edges into ESet */
	ECount = 0;
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W=W->Next)
			/* To avoid saving edges repeatedly, and only to save edge that is V1<V2 */
			if (V < W->AdjV) {
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	/* initialize it as Min-heap */
	for (ECount = Graph->Ne/2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);
}

/* Given current size of Min-heap, get the edge with smallest weight and rearrange it */
int GetEdge(Edge ESet, int CurrentSize)
{
	Swap(&ESet[0], &ESet[CurrentSize-1]);
	PercDown(ESet, 0, CurrentSize-1);

	return CurrentSize-1;	/* Return the positon of minimum edge */
}
/*-------------------- MinHeap of edges definition --------------------*/

/* Saving MST as a graph implemented by adjacency list and return the total weight */
int Kruskal(LGraph Graph, LGraph MST)
{
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;	/* Vertices array */
	Edge ESet;		/* Edges array */

	InitializeVSet(VSet, Graph->Nv);	/* Initialize vertices Union-Find set */
	ESet = (Edge) malloc(sizeof(struct ENode) * Graph->Ne);
	InitializeESet(Graph, ESet);	/* Initialize the Min-heap of edges */

	/* Create a graph including all vertices but no edges 
	 * (To use adjacency list version graph) */
	MST = CreateGraph(Graph->Nv);
	TotalWeight = 0;	/* Initialize total weight */
	ECount = 0;			/* Initialize vertices counter */

	NextEdge = Graph->Ne;	/* The original scale of edges Set */
	/* When edges collected are not enough to from a tree */
	while (ECount < Graph->Nv-1) {
		/* To get the position of minimum edge from Edge-Set */
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge < 0)	/* Empty edge set */
			break;
		/* If no cycle is formed when this edge is added 
		 * (i.e. they don't belong to the same Set) */
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) {
			/* Insert such edge into MST */
			InsertEdge(MST, ESet+NextEdge);
			TotalWeight += ESet[NextEdge].Weight;	/* Total weight */
			ECount++;	/* Edge counter */
		}
	}
	if (ECount < Graph->Nv-1)
		TotalWeight = -1; /* Set error mark to indicate no such spinning tree */

	return TotalWeight;
}

