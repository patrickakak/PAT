#include <stdio.h>

#define R 15		/* Radius of the island circle */
#define M2B 50		/* Maximum length to the bank */
#define MAX 100		/* Maximum number of crocdiles */

typedef struct Coord_st {
	int x, y;
} Coordinate;

int FirstJump( int step, Coordinate c );
int Within1Step( int step, Coordinate c1, Coordinate c2 );
int Jump2Bank( int step, Coordinate c );
int DFS( int step, Coordinate *croc, int cur, int *visited, int n );

int main() 
{
	int n, i, step, flag = 0, visited[MAX] = {0};	/* flag to indicate done finding path */
	Coordinate croc[MAX];	/* To store the coordinates of crodiles */

	scanf("%d%d", &n, &step);

	/* Can reach bank directly */
	if (step >= M2B - R) { printf("Yes\n"); return 0; }

	for (i = 0; i < n; ++i) scanf("%d%d", &croc[i].x, &croc[i].y);

	for (i = 0; i < n; ++i)
		/* Traverse all the crocs that can be jumped onto from the island */
		if (!visited[i] && FirstJump(step, croc[i])) {
			visited[i] = 1;
			if (DFS(step, croc, i, visited, n)) {	/* Begin DFS in the current coordinate */
				printf("Yes\n");
				flag = 1;
				break;
			}
		}
	if (!flag) printf("No\n");

	return 0;
}

/* Whether James can jump onto a crocdile's head in one step from the island? */
int FirstJump( int step, Coordinate c )
{
	return (R + step) * (R + step) >= (c.x * c.x + c.y * c.y);
}

/* Whether there's a change to jump onto another crocdile? */
int Within1Step( int step, Coordinate c1, Coordinate c2 )
{
	return step * step >= 
		(c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

/* If James can jump to bank in current position? */
int Jump2Bank( int step, Coordinate c )
{
	return c.x <= -M2B + step || c.x >= M2B - step 
		|| c.y >= M2B - step || c.y <= -M2B + step;
}

/* Depth first seaching recursively, return 1 if the path is found */
int DFS( int step, Coordinate *croc, int cur, int *visited, int n )
{
	int i;

	if (Jump2Bank(step, croc[cur])) return 1;

	for (i = 0; i < n; ++i)
		if (!visited[i] && Within1Step(step, croc[cur], croc[i])) {
			visited[i] = 1;
			if (DFS(step, croc, i, visited, n)) return 1;
		}
	return 0;
}


