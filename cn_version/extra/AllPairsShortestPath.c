/* Adjacency matrix: All pairs shortest paths problem (APSP)
 *
 * Critical implementatons (same as V * single source shortest path problem):
 *     a. To get minimun dist value among the uncollected 
 *     b. Update dist[w] (w is a vertex affected by v)
 * ----------------------- Method 1 ------------------------------------------
 *   Scan all the uncollected vertices, in this way, Ta=O(|V|^3), Tb=O(|E||V|), 
 * suit for sparse graph (i.e. E = O(|V|^2)). Total T = O(|V|^3 + |E||V|)
 *
 * ----------------------- Method 2 ------------------------------------------
 *   Also, one can implement function FindMinDist() by using MinHeap, 
 * Ta=O(|V|^2 * log|V|), Tb=O(|V||E|log|V|), suit for sparse graph, 
 * Total T = O(|V|*(|V|+|E|)log|V|) 
 *
 * ----------------------- Method 3 ------------------------------------------
 * Floyd algorithm with elegancy, suit for dense graph, and T = O(|V|^3)
 * Initiaization: for (each v in G) ,set D[v][v] = 0, D[i][j] = INFINITY 
 * if there's no path between i->j;
 */
bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
	Vertex i, j, k;

	/* Initialization */
	for (i = 0; i < Graph->Nv; i++)
		for (j = 0; j < Graph->Nv; j++) {
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}

	for (k = 0; k < Graph->Nv; k++)
		for (i = 0; i < Graph->Nv; i++)
			for (j = 0; j < Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0)	/* Negative-cost cycle is found */
						return false;	/* Can't handle properly, return error */
					path[i][j] = k;
				}
	return true;	/* Execute the algorithm properly, return true */
}

