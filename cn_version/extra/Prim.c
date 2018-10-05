/* Adjacency matrix implementation: 
 *   Prim minimum spanning tree algorithm (suit for dense graph, T=O(|V|^2)) */

/* Return the vertex of minimum dist[V] among uncollected vertices */
Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];	/* Update minimum distance */
			MinV = V;	/* Update vertex */
		}
	if (MinDist < INFINITY)
		return MinV;
	else return ERROR;	/* If no such vertex, return -1 as a mark */
}

/* To Generate MST as Graph implemented in adjacency list and return 
 * the total weight */
int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	/* Initialization: set source vertex as v0 by default */
	for (V = 0; V < Graph->Nv; V++) {
		/* If there's no direct path from vertex V to W, 
		 * then define Graph->G[V][W] as INFINITY */
		dist[V] = Graph->G[0][V];
		parent[V] = 0;	/* Set all the parent vertices as 0 */
	}
	TotalWeight = 0;
	VCount = 0;		/* Vertices counter */
	/* Create a graph with all vertices but no edges (by using adjacency list 
	 * to generate MST) */
	MST = CreateGraph(Graph->Nv);
	E = (Edge) malloc(sizeof(struct ENode));

	dist[0] = 0;	/* Recruit source vertex into MST */
	VCount++;
	parent[0] = -1;		/* To indicate root */

	while (1) {
		/* V with the minimum dist[V] among uncollected vertices */
		V = FindMinDist(Graph, dist);
		if (V == ERROR)	break;	/* V doesn't exist */

		/* Recruit V and edge <parent[V], V> into MST */
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for (W = 0; W < Graph->Nv; W++)		/* for each vertex W in graph */
			/* If W is uncollected and also next to V */
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)
				/* If the recruitment of V can diminish dist[W] */
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];	/* Update dist[W] */
					parent[W] = V;	/* Update tree */
				}
	}
	if (VCount < Graph->Nv)		/* Vertices in MST is less than V */
		TotalWeight = ERROR;
	return TotalWeight;	 /* End of Prim, return minimum total wieght or error */
}

