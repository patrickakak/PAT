#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 10
bool visited[MAXN];
typedef int WeightType;
WeightType G[MAXN][MAXN];	/* Matrix Graph */

void ReadData(int Ne);
void DFS(int i, int Ne);		/* Depth First Search   */
void BFS(int i, int Ne);		/* Breadth First Search */

int main()
{
	int Nv, Ne, i;

	scanf("%d %d", &Nv, &Ne);
	ReadData(Ne);

	memset(visited, false, sizeof(visited));	/* Initialize array visited */
	for (i = 0; i < Nv; i++)	/* DFS output */
		if (!visited[i]) {
			printf("{");
			DFS(i, Nv);
			printf(" }\n");
		}
	memset(visited, false, sizeof(visited));
	for (i = 0; i < Nv; i++)	/* BFS output */
		if (!visited[i]) {
			printf("{");
			BFS(i, Nv);
			printf(" }\n");
		}
	return 0;
}

void ReadData(int Ne)
{
	int i, x, y;

	for (i = 0; i < Ne; i++) {
		scanf("%d %d", &x, &y);
		G[x][y] = G[y][x] = 1;
	}
}

/* Adjacent Matrix: T = O(N^2), Adjacent List: T = O(N+E) */
void DFS(int i, int Nv)
{
	int j;

	visited[i] = true;
	printf(" %d", i);
	for (j = 0; j < Nv; j++)
		if (!visited[j] && G[i][j])
			DFS(j, Nv);
}

/* Same with DFS algorithm */
void BFS(int i, int Nv)
{
	int queue[MAXN], rear, front, v, j;

	rear = front = -1;
	visited[i] = true;
	queue[++rear] = i;
	while (front < rear) {
		v = queue[++front];
		printf(" %d", v);
		for (j = 0; j < Nv; j++)
			if (!visited[j] && G[v][j]) {
				visited[j] = true;
				queue[++rear] = j;
			}
	}
}

