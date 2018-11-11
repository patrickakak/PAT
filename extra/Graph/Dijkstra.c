/**
 * Adjacency matrix: weighted single source shortest path problem 
 *
 * Return the minimum element of array dist (among uncollected vertices)
 *
 * Critical implementatons:
 *     a. To get minimun dist value among the uncollected 
 *     b. Update dist[w] (w is a vertex affected by v)
 * ----------------------- Method 1 ------------------------------------------
 *   Scan all the uncollected vertices, in this way, Ta=O(|V|^2), Tb=O(|E|), 
 *   suit for dense graph (i.e. E = O(|V|^2)). Total T = O(|V|^2 + |E|)
 *
 * ----------------------- Method 2 ------------------------------------------
 *   Also, one can implement function FindMinDist() by using MinHeap, 
 *   Ta=O(|V|log|V|), Tb=O(|E|log|V|), suit for sparse graph, 
 *   Total T = O((|V|+|E|)log|V|) ~ O(|E|log|V|) 
 */
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
	else
		return ERROR;	/* If no such vertex, return ERROR */
}

/**
 * Dijkstra's algorithm solves the single-source shortest path problem 
 * with non-negative edge weight. 
 */
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
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;	/* If no such V, end algorithm */
		collected[V] = true;	/* To collect V */

		for (W = 0; W < Graph->Nv; W++)		/* For each W in graph */
			/* If W is a vertex next to V and which is uncollected */
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				/* If a negative weighted edge is found */
				if (Graph->G[V][W] < 0)
					return false;	/* Can't handle it properly, return error */
				/* If colloecting V can diminish dist[W] */
				if (dist[V]+Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V]+Graph->G[V][W];	/* Update dist[W] */
					path[W] = V;	/* Update path of S to W */
				}
			}
	}
	return true;	/* End of algorithm, data handled properly */
}

