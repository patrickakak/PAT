/* Sample Input:
 * 10
 * 1 2 3 4 5 6 7 8 9 0
 * Sample Output:
 * 6 3 8 1 5 7 9 0 2 4
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1000

int LevelOrderArr[MaxSize];
int j = 0;

int compare(const void *pA, const void *pB);
void SortByInorder(int root, int N, int arr[]);

int main()
{
	int N, i = 0, flag = 1, arr[MaxSize];

	/* ---------------------------------------------
	 * | INPUT               | OUTPUT              |
	 * ---------------------------------------------
	 * | 10                  |                     |
	 * | 1 2 3 4 5 6 7 8 9 0 | 6 3 8 1 5 7 9 0 2 4 |
	 * ---------------------------------------------
	 *                    6
	 *                  /   \
	 *                 3     8
	 *                / \   / \
	 *               1   5 7   9
	 *              / \  /
	 *             0   2 4
	 */
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	/* Inorder traversal of CBST is a incremental sequence */
	qsort(arr, N, sizeof(int), compare);
	/* Match levelorderArr with inorder sequence in arr */
	SortByInorder(1, N, arr);
	for (i = 1; i <= N; i++) { 	/* Begins with index one */
		if (flag) flag = 0;
		else putchar(' ');
		printf("%d", LevelOrderArr[i]);
	}
	putchar('\n');

	return 0;
}

int compare(const void *pA, const void *pB)
{
	return *(int *)pA - *(int *)pB;
}

/* Inorder traversal: extract the data inside arr (which have been sorted 
 * out when using function qsort), fill them into LevelOrderArr.
 *   
 * Cause in complete binary tree, 2i and 2i+1 is the left and the right child 
 * of the i node respectively (array begins with index 1) */
void SortByInorder(int root, int N, int arr[])
{
	if (root <= N) {
		SortByInorder(root<<1, N, arr);
		LevelOrderArr[root] = arr[j++];
		SortByInorder((root<<1)+1, N, arr);
	}
}

