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

void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	for (V = 0; V < Graph->Nv; V++) {
		collected[V] = false;
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
	}

	dist[S] = 0;
	collected[S] = true;
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;
		collected[V] = true;

		for (W = 0; W < Graph->Nv; W++)
			if (!collected[W] && Graph->G[V][W] < INFINITY)
				if (dist[W] > dist[V] + Graph->G[V][W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;
				}
	}
	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] == INFINITY) dist[V] = -1;
}

