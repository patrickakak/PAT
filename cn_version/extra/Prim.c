/* Adjacency matrix: Prim minimum spanning tree algorithm */

/* Return the index of minimum dist value among uncollected vertices */
Vertex FindMinDIst(MGraph Graph, WeightType dist[])
{
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY)
		return MinV;
	else return ERROR;
}

/* Save MST as Graph implemented by adjacency list, return the total weight */
int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	for (V = 0; V < Graph->Nv; V++) {	/* Initialization */
		/* Assume that Graph->[V][W]=INFINITY by default at the beginning */
		dist[V] = Graph->G[0][V];
		parent[V] = 0;	/* Set parent vertex as 0 */
	}
	TotalWeight = 0;	/* Initialize total weight */
	VCount = 0;		/* Initialize vertices counter */
	/* Create a graph including all vertices but no edges 
	 * (To use adjacency list version graph) */
	MST = CreateGraph(Graph->Nv);
	E = (Edge) malloc(sizeof(struct ENode));	/* Create a new empty ENode */

	dist[0] = 0;	/* Save source into MST */
	VCount++;
	parent[0] = -1;		/* Current root is 0 */

	while (1) {
		V = FindMinDist(Graph, dist);
		/* V = the minimum dist value among uncollected vertices */
		if (V == ERROR)		/* V doesn't exist */
			break;

		/* Save V and corresponding edge<parent[V], V> into MST */
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for (W = 0; W < Graph->Nv; W++)		/* for each vertex W */
			/* If W is next to V and also uncollected */
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)
				/* If pick V can diminish dist[W] */
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];	/* Update dist[W] */
					parent[W] = V;	/* Update tree */
				}
	}
	if (VCount < Graph->Nv)		/* Vertices in MST is less than V */
		TotalWeight = ERROR;
	return TotalWeight;	 /* End of algorithm, return minimum total wieght or error */
}

