/**
 * Depth First Search (pseudocode): 
 *   Adjacency list: T = O(N+E), Adjacency matrix: T = O(N^2)
 *   (N/E is the number of vertex/edge respectively)
 */
void DFS(Vertex V)
{
	visited[V] = true;

	for (W: every nearby node of V)
		if (!visited[W])
			DFS(W);
}

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2), traverse every node and its neighbor 
 */
void DFS_m(MGraph Graph, Vertex V)
{
	Vertex W;
	visited[V] = true;

	for (W = 0; W < Graph->Nv; W++)
		if (!visited[W] && Graph->G[V][W])
			DFS_m(Graph, W);
}

/**
 * Graph adjacency list implementation (directed graph): 
 * T = O(N+E), traverse every vertex and edge 
 */

void Visit(Vertex V)
{
	printf("Visiting vertex#%d\n", V);
}

void DFS_l(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	PtrToAdjVNode W;

	Visit(V);	/* Visit vertex V */
	visited[V] = true;
	
	for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!Visited[W->AdjV])
			DFS(Graph, W->AdjV, Visit);		/* Visit it recursively */
}

/**
 * Breadth First Search (pseudocode): 
 *   Adjacency list: T = O(N+E), Adjacency matrix: T = O(N^2) 
 *   (N/E is the number of vertex/edge respectively)
 */
void BFS(Vertex V)
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

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2): Same as DFS_m
 */

/* IsEdge() to check whether edge<V, W> is one of the edges of Graph or not. 
 * In this case, a non-exsistent edge is marked as INFINITY: */
bool IsEdge(Mgraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

/* visited[] is a global array, initialized to be false */
void BFS_m(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;

	Q = CreatQueue(MaxSize);	/* Create a empty queue with size of MaxSize */
	Visit(S);	/* Do something with vertex S */
	visited[V] = true;
	Enqueue(Q, V);

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < Graph->Nv; W++)
			/* If W is the adjacent node of V and never visited before: */
			if (!visited[W] && IsEdge(Graph, V, W)) {
				Visit(W);
				visited[W] = true;
				Enqueue(Q, W);
			}
	}
}

/**
 * Graph adjacency list implememtation (directed graph): 
 * T = O(N+E): Same as DBS_l
 */
void BFS_l(LGraph Graph, Vertex V)
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
			DFS(V); 	/* or BFS(V) */
}

