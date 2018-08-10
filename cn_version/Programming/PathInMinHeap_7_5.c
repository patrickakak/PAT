#include <stdio.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

void Create();
void Insert(int X);

int main()
{
	int n, m, x, i, j;

	scanf("%d %d", &n, &m);
	Create();	// Initialize MinHeap
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		Insert(x);	// Insert a node at a time to build a min-heap
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j > 1) {		// Output value of node along the path to the root
			j /= 2;
			printf(" %d", H[j]);
		}
		putchar('\n');
	}
	return 0;
}

void Create()
{
	size = 0;
	H[0] = MINH;	// Set a sentinel
}

void Insert(int X)
{
	int i;

	for (i = ++size; H[i/2] > X; i /= 2)
		H[i] = H[i/2];
	H[i] = X;
}

