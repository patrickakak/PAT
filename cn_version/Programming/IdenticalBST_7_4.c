/* Sample Input:
 * 4 2
 * 3 1 4 2
 * 3 4 1 2
 * 3 2 4 1
 * 2 1
 * 2 1
 * 1 2
 * 0
 * Sample Output:
 * Yes
 * No
 * No
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TreeNode *Tree;
struct TreeNode {
	ElementType v;
	Tree Left, Right;
	int flag;
};

Tree MakeTree(int N);
Tree NewNode(ElementType V);
Tree Insert(Tree T, ElementType V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);
static int check(Tree T, ElementType V);

int main()
{
	int N, L, i;
	Tree T;

	/* For every group of data series,
	 *     1. Readin N and L
	 *     2. Build a benchmark tree T
	 *     3. Judge following trees
	 */
	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = MakeTree(N); 	/* Make the benchmark tree */
		for (i = 0; i < L; i++) {
			if (Judge(T, N)) printf("Yes\n");
			else printf("No\n");
			ResetT(T); 	/* Clear out all the flags */
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;
}

Tree MakeTree(int N)
{
	Tree T;
	int i;
	ElementType V;

	scanf("%d", &V);
	T = NewNode(V); 	/* Build a tree with a single node */
	for (i = 1; i < N; i++) {
		scanf("%d", &V);
		T = Insert(T, V); 	/* Insert following nodes */
	}
	return T;
}

Tree NewNode(ElementType V)
{
	Tree T = (Tree) malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

Tree Insert(Tree T, ElementType V)
{
	if (!T) T = NewNode(V);
	else
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	return T;
}

/* Return: 0 - Not identical,  1 - identical trees */
static int check(Tree T, ElementType V)
{
	if (T->flag)
		if (V < T->v) return check(T->Left, V);
		else if (V > T->v) return check(T->Right, V);
		else return 0;
	else
		if (V == T->v) { 	/* If v has just been visited, set flag=1 */
			T->flag = 1;
			return 1;
		} else 	/* If the last node of v is unvisited, return 0 */
			return 0;
}

int Judge(Tree T, int N)
{
	int i, flag = 0; 	/* flag=0 to indicate so far so good */
	ElementType V;

	scanf("%d", &V);
	if (V != T->v) flag = 1; 	/* flag=1 to indicate follwing invalid readin */
	/* T->flag=1 to indicate we've already check the validity of root */
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		scanf("%d", &V);
		/* If flag=1, don't bother to check, read the rest */
		if ((!flag) && (!check(T, V))) flag = 1;
	}
	if (flag) return 0;
	else return 1;
}

void ResetT(Tree T)
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

