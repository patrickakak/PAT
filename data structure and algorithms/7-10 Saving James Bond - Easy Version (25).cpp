#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define Diameter 15
#define O2B 50
#define MAXN 100
#define YES 1
#define NO 0
typedef struct {
	int x, y;
} Coordinates;
typedef int Vertex;
void InitVisited(int N);
void Save007(int N, int D);
bool FirstJump(int D, Vertex V);
int DFS(Vertex V, int N, int D);
bool IsSafe(Vertex V, int D);
bool Jump(Vertex V, Vertex W, int D);

Coordinates Crocs[MAXN];
bool visited[MAXN];
int main() {
	int N, D, i;	/* D: One step wide of James */
	scanf("%d %d", &N, &D);
	for (i = 0; i < N; i++)
		scanf("%d %d", &Crocs[i].x, &Crocs[i].y);
	Save007(N, D);
	return 0;
}
void InitVisited(int N) {
	for (int i = 0; i < N; i++)
		visited[i] = false;
}
void Save007(int N, int D) {
	int answer = NO;
	Vertex V;
	InitVisited(N);
	for (V = 0; V < N; V++)
		if (FirstJump(D, V)) {
			answer = DFS(V, N, D);
			if (answer == YES) break;
		}
	if (answer == YES) puts("Yes");
	else puts("No");
}
bool FirstJump(int D, Vertex V) {
	return ((float)D + Diameter/2) * ((float)D + Diameter/2) >= Crocs[V].x*Crocs[V].x + Crocs[V].y*Crocs[V].y;
}
int DFS(Vertex V, int N, int D) {
	int answer = NO;
	Vertex W;
	visited[V] = true;
	if (IsSafe(V, D))
		answer = YES;
	else
		for (W = 0; W < N; W++)
			if (!visited[W] && Jump(V, W, D)) {
				answer = DFS(W, N, D);
				if (answer == YES) break;
			}
	return answer;
}
bool IsSafe(Vertex V, int D) {
	int AbsX, AbsY;
	AbsX = Crocs[V].x > 0 ? Crocs[V].x : -Crocs[V].x;
	AbsY = Crocs[V].y > 0 ? Crocs[V].y : -Crocs[V].y;
	return AbsX+D >= O2B || AbsY+D >= O2B;
}
bool Jump(Vertex V, Vertex W, int D) {
	return D*D >= (Crocs[V].x - Crocs[W].x)*(Crocs[V].x - Crocs[W].x) + (Crocs[V].y - Crocs[W].y)*(Crocs[V].y - Crocs[W].y);
}
