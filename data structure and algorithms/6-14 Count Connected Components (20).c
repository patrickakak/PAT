void DFS(LGraph Graph, Vertex V, bool visited[]) {
	visited[V] = true;
	for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!visited[W->AdjV])
			DFS(Graph, W->AdjV, visited);
}
int CountConnectedComponents(LGraph Graph) {
	int count, V;
	bool visited[MaxVertexNum];
	for (V = 0; V < Graph->Nv; V++) visited[V] = false;
	for (count = 0, V = 0; V < Graph->Nv; V++)
		if (!visited[V]) {
			DFS(Graph, V, visited);
			count++;
		}
	return count;
}
