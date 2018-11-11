/**
 * Adjacency matrix: All pairs shortest paths problem (APSP)
 ***********************************************************************************
 * [Sparse Graph algorithm]:
 * -------- Method 1 (same as V size the single source shortest path problem) ------
 *   One can implement function FindMinDist() by using MinHeap, 
 * Ta=O(|V|^2 * log|V|), Tb=O(|V||E|log|V|), Total T = O(|V|*(|V|+|E|)log|V|) 
 *
 ***********************************************************************************
 * [Dense Graph algorithms] (i.e. E = O(|V|^2)):
 * -------- Method 2 (same as V size the single source shortest path problem) ------
 *   Scan all the uncollected vertices, in this way, Ta=O(|V|^3), Tb=O(|E||V|), 
 * Total T = Ta + Tb = O(|V|^3 + |E||V|)
 *
 * ------------------------ Method 3 (exactly T=O(|V|^3)) --------------------------
 *   Floyd algorithm with elegancy, 
 * Initiaization: for (each v in G), set D[v][v] = 0, D[i][j] = INFINITY 
 **********************************************************************************
 */
bool Floyd(MGraph Graph, WeightType D[][MaxNv], Vertex path[][MaxNv])
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
					/* Negative-cost cycle is found */
					if (i == j && D[i][j] < 0)
						return false;	/* Can't handle properly */
					path[i][j] = k;
				}
	return true;	/* Execute the algorithm properly */
}

