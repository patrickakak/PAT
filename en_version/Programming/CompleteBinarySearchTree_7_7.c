/* Sample Input:
 * 10
 * 1 2 3 4 5 6 7 8 9 0
 * Sample Output:
 * 6 3 8 1 5 7 9 0 2 4
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int LevelOrderCBST[MAX], j=0;

int compar(const void *pA, const void *pB);
void InorderSort(int A[], int R, int N);

int main()
{
	int A[MAX], N, i, flag=0;

	/***********************************************************
	 *               6                        A[6]
	 *             /   \                    /      \
	 *            3     8                A[3]     A[8]
	 *           / \   / \               /  \     /   \
	 *          1   5 7   9           A[1]  A[5]A[7] A[9]
	 *         / \  /                 / \   /
	 *        0   2 4              A[0]A[2] A[4]
	 ***********************************************************/
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	/* Inorder traversal of CBST is a incremental sequence */
	qsort(A, N, sizeof(int), compar);
	InorderSort(A, 0, N);
	/* Match levelorderArr with inorder sequence in arr */
	for (i = 0; i < N; i++) {
		if (!flag) flag = 1;
		else putchar(' ');
		printf("%d", LevelOrderCBST[i]);
	}
	putchar('\n');
	return 0;
}

int compar(const void *pA, const void *pB)
{
	return *(int *)pA - *(int *)pB;
}

/* Inorder traversal: extract the data inside arr (which have been sorted 
 * out when using function qsort), fill them into LevelOrderArr.
 *   
 * Cause in complete binary tree, 2i and 2i+1 is the left and the right child 
 * of the i node respectively (array begins with index 1) */
void InorderSort(int A[], int R, int N)
{
	if (R < N) {
		InorderSort(A, 2*R+1, N);
		LevelOrderCBST[R] = A[j++];
		InorderSort(A, 2*R+2, N);
	}
}

