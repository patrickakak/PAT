/**
 * 6-16: Find the weighted shortest distances, but also count the number of 
 * different minimum paths from any vertex to a given source vertex in a 
 * digraph. It is guaranteed that all the weights are positive.
 * ------------------------------------------------------------------------
 * Sample Input:
 * 8 11
 * 0 4 5
 * 0 7 10
 * 1 7 30
 * 3 0 40
 * 3 1 20
 * 3 2 100
 * 3 7 70
 * 4 7 5
 * 6 2 1
 * 7 5 3
 * 7 2 50
 * 3
 * -----------------------
 * Sample Output:
 * 40 20 100 0 45 53 -1 50 
 * 1 1 4 1 1 3 0 3 
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

void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	for (V = 0; V < Graph->Nv; V++) {
		collected[V] = false;
		dist[V] = Graph->G[S][V];
		if (Graph->G[S][V] < INFINITY)
			count[V] = 1;
		else
			count[V] = 0;
	}

	dist[S] = 0; count[S] = 1;
	collected[S] = true;
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;
		collected[V] = true;

		for (W = 0; W < Graph->Nv; W++)
			if (!collected[W] && Graph->G[V][W] < INFINITY) {
				if (dist[W] > dist[V] + Graph->G[V][W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					count[W] = count[V];
				} else if (dist[W] == dist[V] + Graph->G[V][W])
					count[W] += count[V];
			}
	}
	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] == INFINITY) dist[V] = -1;
}

