/* Depth First Search (pseudocode): 
 *   Adjacent List: T = O(N+E), Adjacent Matrix: T = O(N^2)
 *   (N/E is the number of vertex/edge respectively)
 */
void DFS( Vertex V )
{
	visited[V] = true;

	for (W: every nearby node of V)
		if (!visited[W])
			DFS(W);
}

/* Matrix implememtation (directed graph): 
 * T = O(N^2), traverse every node and its neighbor 
 */
void DFS_m( MGraph Graph, Vertex V )
{
	Vertex W;
	visited[V] = true;

	for (W = 0; W < Graph->Nv; W++)
		if (!visited[W] && Graph->G[V][W])
			DFS_m(Graph, W);
}

/* List implememtation (directed graph): 
 * T = O(N+E), traverse every vertex and edge 
 */
void DFS_l( LGraph Graph, Vertex V )
{
	Vertex W;
	PtrToAdjVNode Tmp;

	visited[V] = true;
	Tmp = Graph->G[V].FirstEdge;
	while (Tmp) {
		W = Tmp->AdjV;
		if (!visited[W])
			DFS_l(Graph, W);
		Tmp = Tmp->Next;
	}
}

/* Breadth First Search (pseudocode): 
 *   Adjacent List: T = O(N+E), Adjacent Matrix: T = O(N^2) 
 *   (N/E is the number of vertex/edge respectively)
 */
void BFS( Vertex V )
{
	visited[V] = true;

	Enqueue(V, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W: every node next to V)
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(W, Q);
			}
	}
}

/* Matrix implememtation (directed graph): 
 * T = O(N^2): Same as DFS_m
 */
void BFS_m( MGraph Graph, Vertex V )
{
	Vertex W;
	visited[V] = true;

	Enqueue(V, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < Graph->Nv; W++)
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(W, Q);
			}
	}
}

/* List implememtation (directed graph): 
 * T = O(N+E): Same as DBS_l
 * */
void BFS_l( LGraph Graph, Vertex V )
{
	Vertex W;
	PtrToAdjVNode Tmp;

	visited[V] = true;
	Enqueue(V, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (Tmp = Graph->G[V].FirstEdge; Tmp; Tmp = Tmp->Next) {
			W = Tmp->AdjV;
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(W, Q);
			}
		}
	}
}

/* List all components in a graph wheather it's strongly connected or not */
void ListComponents(Graph G)
{
	for (each V in G)
		if (!visited[V])
			DFS(V);		// or BFS(V)
}

