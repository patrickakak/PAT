/* Sample Input:
 * 10
 * 1 2 3 4 5 6 7 8 9 0
 * Sample Output:
 * 6 3 8 1 5 7 9 0 2 4
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef int ElemType;
int LevelOrderCBST[MAX], j=0;

int compar(const void *pA, const void *pB);
void InorderSort(int Root, int N, ElemType A[]);

int main()
{
	int N, i, flag=0;
	ElemType A[MAX];

	/***********************************************************
	 *               6                        0
	 *             /   \                    /   \
	 *            3     8                  1     2
	 *           / \   / \               /  \   /  \
	 *          1   5 7   9             3    4 5    6
	 *         / \  /                  / \   /
	 *        0   2 4                 7   8 9
	 ***********************************************************/
	scanf("%d", &N); 	/* N is positve guranteed */
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	/* Inorder traversal of CBST is a incremental sequence */
	qsort(A, N, sizeof(ElemType), compar);
	InorderSort(0, N, A);
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
	return *(ElemType *)pA - *(ElemType *)pB;
}

/* Inorder traversal: extract the data inside array A (which have been 
 * re-arranged using qsort), fill them into LevelOrderCBST array
 *   
 * In complete binary tree (CBST), 2i+1 and 2i+2 is the left and right 
 * child of the i node respectively (array begins with index zero) */
void InorderSort(int Root, int N, ElemType A[])
{
	if (Root < N) {
		InorderSort(2*Root+1, N, A);
		LevelOrderCBST[Root] = A[j++];
		InorderSort(2*Root+2, N, A);
	}
}

