/**
 * Adjacency list implementation: TopSort algorithm 
 * (could be used to dectect DAG(i.e. directed acyclic graph))
 */

/* TopSort graph, indexes of vertices will be stored into TopOrader[] array */
bool TopSort(LGraph Graph, Vertex TopOrder[])
{
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue(Graph->Nv);

	for (V = 0; V < Graph->Nv; V++)		/* Initialize Indegree[] */
		Indegree[V] = 0;

	for (V = 0; V < Graph->Nv; V++)		/* Traverse graph to get Indegree[] */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;

	for (V = 0; V < Graph->Nv; V++)		/* Enqueue vertices with 0 indegree */
		if (Indegree[V] == 0)
			Enqueue(Q, V);

	cnt = 0;	/* TopSort begins */
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);		/* Dequeue a vertex with 0 indegree */
		TopOrder[cnt++] = V;	/* Store it in TopOrder[] array */
		/* For each vertices next to V */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
	}

	if (cnt != Graph->Nv) return false;		/* There's a cycle in graph */
	else return true;
}

