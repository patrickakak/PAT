/**
 * Graph is just a tool to facilitate problem-solving, don't bother to use
 * adjacency matrix or list implementation eclusively!
 */

/**
 * Sample Input1:
 * 14 20
 * 25 -15
 * -25 28
 * 8 49
 * 29 15
 * -35 -2
 * 5 28
 * 27 -29
 * -8 -28
 * -20 -35
 * -25 -20
 * -13 29
 * -30 15
 * -35 40
 * 12 12
 * Sample Output1:
 * Yes
 * ---------------
 * Sample Input2:
 * 4 13
 * -12 12
 * 12 12
 * -12 -12
 * 12 -12
 * Sample Output2:
 * No
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define Diameter 15		/* Diameter of central island disk */
#define O2B 50	/* Distance from coordinate origin to bank */
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

/**
 * Global variables:
 * */
Coordinates Crocs[MAXN];
bool visited[MAXN];

int main()
{
	int N, D, i;	/* D: One step wide of James */

	scanf("%d %d", &N, &D);

	for (i = 0; i < N; i++)
		scanf("%d %d", &Crocs[i].x, &Crocs[i].y);

	Save007(N, D);

	return 0;
}

void InitVisited(int N)
{
	int i;

	for (i = 0; i < N; i++)
		visited[i] = false;
}

void Save007(int N, int D)
{
	int answer = NO;
	Vertex V;

	InitVisited(N);

	/* Traverse all the crocs that can be jumped onto from the island */
	
	for (V = 0; V < N; V++)
		if (FirstJump(D, V)) {
			answer = DFS(V, N, D);
			if (answer == YES) break;
		}

	if (answer == YES) puts("Yes");
	else puts("No");
}

/**
 * Whether James can jump onto a crocdile's head in one step from the island? 
 */
bool FirstJump(int D, Vertex V)
{
	return ((float)D + Diameter/2) * ((float)D + Diameter/2) 
		>= Crocs[V].x*Crocs[V].x + Crocs[V].y*Crocs[V].y;
}

/**
 * Depth first seaching recursively, return YES if the path is found
 * (Unlike BFS, DFS to offer only special solution to the question) 
 */
int DFS(Vertex V, int N, int D)
{
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

/**
 * Whether James can jump to bank directly? 
 */
bool IsSafe(Vertex V, int D)
{
	int AbsX, AbsY;

	AbsX = Crocs[V].x > 0 ? Crocs[V].x : -Crocs[V].x;
	AbsY = Crocs[V].y > 0 ? Crocs[V].y : -Crocs[V].y;

	return AbsX+D >= O2B || AbsY+D >= O2B;
}

/**
 * Whether there's a change to jump onto another crocdile? 
 */
bool Jump(Vertex V, Vertex W, int D)
{
	return D*D >= (Crocs[V].x - Crocs[W].x)*(Crocs[V].x - Crocs[W].x) 
		+ (Crocs[V].y - Crocs[W].y)*(Crocs[V].y - Crocs[W].y);
}

