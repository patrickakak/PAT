/**
 * Unweighted single-source shortest path problem (SSSP)
 * (quite resembles breadth first search algorithm), T = O(|V|+|E|)
 *
 * Psudocode for SSSP problem:
 * Initialize array dist[] and path[] as -1 firstly 
 * */
void Unweighted(Vertex S)
{
	Enqueue(S, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W: each adjacent node of V)
			if (dist[W] == -1) {
				dist[W] = dist[V]+1;
				path[W] = V;
				Enqueue(W, Q);
			}
	}
}

/**
 * Adjacency list implementation:
 */
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
			/* If the adjacent vertex has not been visited */
			if (dist[W->AdjV] == -1) {
				/* Update the distance from W->AdjV to S */
				dist[W->AdjV] = dist[V] + 1;
				path[W->AdjV] = V;	/* Record V in the path of S to W->AdjV */
				Enqueue(Q, W->AdjV);
			}
	}
}

/**
 * Adjacency matrix implementation:
 */
void Unweighted(MGraph Graph, int dist[], int path[], Vertex S)
{
	Queue Q;
	Vertex V;

	Q = CreateQueue(Graph->Nv);
	dist[S] = 0;	/* Initialize source */
	Enqueue(Q, S);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < Graph->Nv; W++)
			if (dist[W] == -1) {
				dist[W] = dist[V] + 1;
				path[W] = V;
				Enqueue(Q, W);
			}
	}
}

