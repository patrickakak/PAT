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
#define MaxCrocs 100	/* Maximun number of crocdiles */

#define YES 1
#define NO 0

typedef struct coordinate_st Vertex;
struct coordinate_st {
	float x, y;
};

void Save007(Vertex Crocs[], int N, float D);
bool FirstJump(float D, Vertex V);
bool IsSafe(Vertex V, float D);
int DFS(int curVert, Vertex Crocs[], int N, float D, bool visited[]);
bool Jump(Vertex cur, Vertex nearby, float D);
void InitVisited(bool visited[], int N);

int main()
{
	int N, i;
	float D;	/* One step wide of James */
	Vertex Crocs[MaxCrocs];

	scanf("%d %f", &N, &D);

	if (D + Diameter/2 >= O2B) {	/* Can reach bank directly */
		printf("Yes\n");
		exit(EXIT_SUCCESS);
	}
	for (i = 0; i < N; i++)
		scanf("%f %f", &Crocs[i].x, &Crocs[i].y);

	Save007(Crocs, N, D);
	return 0;
}

void InitVisited(bool visited[], int N)
{
	int i;

	for (i = 0; i < N; i++)
		visited[i] = false;
}

/* List components in the graph */

void Save007(Vertex Crocs[], int N, float D)
{
	int i, answer = NO;
	bool visited[MaxCrocs];

	InitVisited(visited, N);

	/* Traverse all the crocs that can be jumped onto from the island */
	
	for (i = 0; i < N; i++)
		if (FirstJump(D, Crocs[i])) {
			answer = DFS(i, Crocs, N, D, visited);
			if (answer == YES) break;
		}

	if (answer == YES) printf("Yes\n");
	else printf("No\n");
}

/* Whether James can jump onto a crocdile's head in one step from the island? */

bool FirstJump(float D, Vertex V)
{
	return (Diameter+D) * (Diameter+D) >= V.x*V.x + V.y*V.y;
}

/* Depth first seaching recursively, return YES if the path is found
 * (Unlike BFS, DFS to offer only special solution to the question) */

int DFS(int curVertIndex, Vertex Crocs[], int N, float D, bool visited[])
{
	int i, answer = NO;
	Vertex W;

	visited[curVertIndex] = true;
	if (IsSafe(Crocs[curVertIndex], D))
		answer = YES;
	else
		for (i = 0; i < N; i++) {
			W = Crocs[i];
			if (!visited[i] && Jump(Crocs[curVertIndex], W, D)) {
				answer = DFS(i, Crocs, N, D, visited);
				if (answer == YES) break;
			}
		}
	return answer;
}

/* If James can jump to bank in current position? */

bool IsSafe(Vertex V, float D)
{
	int AbsX, AbsY;

	AbsX = V.x > 0 ? V.x : -V.x;
	AbsY = V.y > 0 ? V.y : -V.y;

	return AbsX+D >= O2B || AbsY+D >= O2B;
}

/* Whether there's a change to jump onto another crocdile? */

bool Jump(Vertex V, Vertex W, float D)
{
	return D*D >= (V.x - W.x)*(V.x - W.x) + (V.y - W.y)*(V.y - W.y);
}

