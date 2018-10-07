/* Adjacency list: unweighted single-source shortest path problem */

/* Initialize array dist[] and path[] as -1 firstly */
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreateQueue(Graph->Nv);
	dist[S] = 0;	/* Initialize source */
	Enqueue(Q, S);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (dist[W->AdjV] == -1) {	/* If W->AdjV has not been visited */
				dist[W->AdjV] = dist[V] + 1;	/* Update the distance from W->AdjV to S */
				path[W->AdjV] = V;	/* Record V in path of S to W->AdjV */
				Enqueue(Q, W->AdjV);
			}
	}
}

