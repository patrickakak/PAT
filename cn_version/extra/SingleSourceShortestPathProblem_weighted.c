/* Adjacency matrix: weighted signle source shortest path problem */

/* Return the minimum element of array dist (among uncollected vertices) */
Vertex FindMinDist(MGraph Graph, int dist[], bool collected[])
{
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		 /* If V has not been colloected and dist[V] is smaller */
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];	/* Update minimum distance */
			MinV = V;	/* Update corresponding vertex */
		}
	if (MinDist < INFINITY)		/* Find the minimum dist */
		return MinV;	/* Return the index of the vertex */
	else return ERROR;	/* If no such vertex, return ERROR */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	/* Initialization: assume that inexistent edges are represented 
	 * as INFINITY in adjacency matrix */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* To collect source firstly */
	dist[S] = 0;
	collected[S] = true;
	while (1) {
		/**/
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;	/* If no such V, end algorithm */
		collected[V] = true;	/* To collect V */
		for (W = 0; W < Graph->Nv; W++)		/* For each W in graph */
			/* If W is a vertex next to V and which is uncollected */
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)		/* If a negative weighted edge is found */
					return false;		/* Can't handle it properly, return error */
				/* If colloecting V can diminish dist[W] */
				if (dist[V]+Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V]+Graph->G[V][W];	/* Update dist[W] */
					path[W] = V;	/* Update path of S to W */
				}
			}
	}
	return true;	/* End of algorithm, data handled properly */
}


