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

void Visit(Vertex V)
{
	printf("Visiting vertex#%d\n", V);
}

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2), traverse every node and its neighbor 
 */

/* visited[] is a global array, initialized to be false */
void DFS_m(MGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	Vertex W;

	Visit(V);
	visited[V] = true;

	for (W = 0; W < Graph->Nv; W++)
		if (!visited[W] && Graph->G[V][W] != INFINITY)
			DFS_m(Graph, W, Visit);
}

/**
 * Graph adjacency list implementation (directed graph): 
 * T = O(N+E), traverse every vertex and edge 
 */

void DFS_l(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	PtrToAdjVNode W;

	Visit(V);	/* Visit vertex V */
	visited[V] = true;
	
	for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!Visited[W->AdjV])
			DFS_l(Graph, W->AdjV, Visit);		/* Visit it recursively */
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
 * In this case, a inexistent edge is marked as INFINITY when initialized: */
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
	visited[S] = true;
	Enqueue(Q, S);

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
	DestroyQueue(Q);
}

/**
 * Graph adjacency list implememtation (directed graph): 
 * T = O(N+E): Same as DBS_l
 */

void BFS_l(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;
	PtrToAdjVNode T;

	Q = CreatQueue(MaxSize);
	Visit(S);
	visited[S] = true;
	Enqueue(Q, S);

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (T = Graph->G[V].FirstEdge; T; T = T->Next) {
			W = T->AdjV;
			if (!visited[W]) {
				Visit(W);
				visited[W] = true;
				Enqueue(Q, W);
			}
		}
	}
	DestroyQueue(Q);
}

/* List all components in a graph wheather it's strongly connected or not */
void ListComponents(Graph G)
{
	for (each V in G)
		if (!visited[V])
			DFS(V); 	/* or BFS(V) */
}

