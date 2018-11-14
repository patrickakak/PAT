/* Adjacency list implementation: TopSort algorithm */

/* TopSort graph, the index of vertices will be stored into TopOrader[] array */
bool TopSort(LGraph Graph, Vertex TopOrder[])
{
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue(Graph->Nv);

	/* Initialize Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;

	/* Traverse graph to get Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;

	/* Enqueue vertices with 0 indegree */
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);

	/* TopSort begins */
	cnt = 0; 
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);		/* Dequeue a vertex with 0 indegree */
		TopOrder[cnt++] = V;	/* Store it in TopOrder[] array */
		/* For each vertices next to V */
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
	}

	if (cnt != Graph->Nv) return false;	/* There's a cycle in graph */ 
	else return true;
}

