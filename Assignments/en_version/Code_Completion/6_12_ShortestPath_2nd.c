/**
 * 6-12: Find the weighted shortest distances from any vertex to a 
 * given source vertex in a digraph. It is guaranteed that all the 
 * weights are positive.
 *
 * Sample Input:
 * 7 9
 * 0 1 1
 * 0 5 1
 * 0 6 1
 * 5 3 1
 * 2 1 2
 * 2 6 3
 * 6 4 4
 * 4 5 5
 * 6 5 12
 * 2
 * Sample Output:
 * -1 2 0 13 7 12 3 
 */
#define ERROR -1

Vertex FindMinDist(MGraph Graph, int dist[], bool collected[])
{
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY)
		return MinV;
	else
		return ERROR;
}

void ShortestDist(MGraph Graph, int dist[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		collected[V] = false;
	}

	dist[S] = 0; collected[S] = true;
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;
		collected[V] = true;

		for (W = 0; W < Graph->Nv; W++)
			if (!collected[W] && Graph->G[V][W] < INFINITY)
				if (dist[W] > dist[V] + Graph->G[V][W])
					dist[W] = dist[V] + Graph->G[V][W];
	}
	/* The shortest distance from V to the source S is supposed to be stored 
	 * in dist[V]. If V cannot be reached from S, store -1 instead.
	 */
	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] == INFINITY) dist[V] = -1;
}

