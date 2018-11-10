#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define RoI 15	/* Radius of central island */
#define D2B 50	/* Distance from coordinate origin to bank */
#define MaxCrocs 100	/* Maximun number of crocdiles */

#define YES 1
#define NO 0

typedef struct coordinate_st Vertex;
struct coordinate_st {
	int x, y;
};

void Save007(Vertex Crocs[], int N, int step);
int FirstJump(int step, Vertex V);
int IsSafe(Vertex V, int step);
int DFS(int curVert, Vertex Crocs[], int N, int step, bool visited[]);
int Jump(Vertex cur, Vertex nearby, int step);

int main()
{
	int N, step, i;
	Vertex Crocs[MaxCrocs];

	scanf("%d %d", &N, &step);

	if (step+RoI >= D2B) {	/* Can reach bank directly */
		printf("Yes\n");
		exit(EXIT_SUCCESS);
	}
	for (i = 0; i < N; i++)
		scanf("%d %d", &Crocs[i].x, &Crocs[i].y);

	Save007(Crocs, N, step);
	return 0;
}

/* List components in the graph */
void Save007(Vertex Crocs[], int N, int step)
{
	int i, answer;
	bool visited[MaxCrocs];

	memset(visited, false, sizeof(visited));
	/* Traverse all the crocs that can be jumped onto from the island */
	for (i = 0; i < N; i++)
		if (!visited[i] && FirstJump(step, Crocs[i])) {
			answer = DFS(i, Crocs, N, step, visited);
			if (answer == YES) break;
		}

	if (answer == YES) printf("Yes\n");
	else printf("No\n");
}

/* Whether James can jump onto a crocdile's head in one step from the island? */
int FirstJump(int step, Vertex V)
{
	return (RoI + step)*(RoI + step) >= (V.x * V.x)+(V.y * V.y);
}

/* Depth first seaching recursively, return YES if the path is found */
int DFS(int curVertIndex, Vertex Crocs[], int N, int step, bool visited[])
{
	int i, answer = NO;
	Vertex W;

	visited[curVertIndex] = true;
	if (IsSafe(Crocs[curVertIndex], step)) answer = YES;
	else
		for (i = 0; i < N; i++) {
			W = Crocs[i];
			if (!visited[i] && Jump(Crocs[curVertIndex], W, step)) {
				answer = DFS(i, Crocs, N, step, visited);
				if (answer == YES) break;
			}
		}
	return answer;
}

/* If James can jump to bank in current position? */
int IsSafe(Vertex V, int step)
{
	int AbsX, AbsY;

	AbsX = V.x > 0 ? V.x : -V.x;
	AbsY = V.y > 0 ? V.y : -V.y;

	return AbsX+step >= D2B || AbsY+step >= D2B;
}

/* Whether there's a change to jump onto another crocdile? */
int Jump(Vertex cur, Vertex nearby, int step)
{
	return step*step >= (cur.x - nearby.x)*(cur.x - nearby.x) 
		+ (cur.y - nearby.y)*(cur.y - nearby.y);
}

