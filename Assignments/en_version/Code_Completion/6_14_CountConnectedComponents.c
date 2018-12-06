/**
 * 6-14: Count the number of connected components in a given graph.
 * ----------------------------------------------------------------
 * Sample Input:
 * 8 6
 * 0 7
 * 0 1
 * 2 0
 * 4 1
 * 2 4
 * 3 5
 * Sample Output:
 * 3
 */
void DFS(LGraph Graph, Vertex V, bool visited[])
{
	PtrToAdjVNode W;

	visited[V] = true;
	for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!visited[W->AdjV])
			DFS(Graph, W->AdjV, visited);
}

int CountConnectedComponents(LGraph Graph)
{
	int count;
	Vertex V;
	bool visited[MaxVertexNum];

	/* Initialize visited[] */
	for (V = 0; V < Graph->Nv; V++)
		visited[V] = false;

	for (count=0, V=0; V < Graph->Nv; V++)
		if (!visited[V]) {
			DFS(Graph, V, visited);
			count++;
		}
	return count;
}

