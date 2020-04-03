#define ERROR -1
Vertex FindMinDist(MGraph Graph, int dist[], bool collected[]) {
	Vertex MinV;
	int MinDist = INFINITY;
	for (Vertex V = 0; V < Graph->Nv; V++)
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY) return MinV;
	else return ERROR;
}
void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S) {
	bool collected[MaxVertexNum];
	for (Vertex V = 0; V < Graph->Nv; V++) {
		collected[V] = false;
		dist[V] = Graph->G[S][V];
		if (Graph->G[S][V] < INFINITY) count[V] = 1;
		else count[V] = 0;
	}
	dist[S] = 0; count[S] = 1;
	collected[S] = true;
	while (1) {
		Vertex V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;
		collected[V] = true;
		for (Vertex W = 0; W < Graph->Nv; W++)
			if (!collected[W] && Graph->G[V][W] < INFINITY) {
				if (dist[W] > dist[V] + Graph->G[V][W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					count[W] = count[V];
				} else if (dist[W] == dist[V] + Graph->G[V][W])
					count[W] += count[V];
			}
	}
	for (Vertex V = 0; V < Graph->Nv; V++)
		if (dist[V] == INFINITY) dist[V] = -1;
}
