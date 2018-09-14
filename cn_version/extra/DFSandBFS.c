/* Depth First Search: 
 *   Adjacent List: T = O(N+E), Adjacent Matrix: T = O(N^2) i
 */
void DFS( Vertex V )
{
	visited[V] = true;

	for (W: every nearby node of V)
		if (!visited[W])
			DFS(W);
}

/* Breadth First Search: 
 *   Adjacent List: T = O(N+E), Adjacent Matrix: T = O(N^2) 
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

