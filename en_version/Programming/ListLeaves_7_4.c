/* Sample Input:
 * 8
 * 1 -
 * - -
 * 0 -
 * 2 7
 * - -
 * - -
 * 5 -
 * 4 6
 * Sample Output:
 * 4 1 5
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define Null -1
#define EmptyTree -1

typedef int Tree;
struct TNode {
	Tree Left, Right;
} TreeArr[MaxSize];

typedef struct QNode *Queue;
struct QNode {
	Tree *pTArr;
	int Front, Rear;
	int Max;
};

Tree BuildTree(struct TNode TreeArr[]);
void LevelOrderListLeaves(Tree R);
Queue CreatQueue(int MaxSz);
void Enqueue(Queue Q, Tree T);
int IsFullQ(Queue Q);
Tree Dequeue(Queue Q);
int IsEmptyQ(Queue Q);

int main()
{
	Tree R;

	R = BuildTree(TreeArr);
	LevelOrderListLeaves(R);
	return 0;
}

Tree BuildTree(struct TNode TreeArr[])
{
	int i, N, Root, check[MaxSize];
	char cl, cr;

	/* Read the number of tree nodes */
	scanf("%d\n", &N);
	if (N <= 0) return EmptyTree;

	/* Array to find out root */
	for (i = 0; i < MaxSize; i++) check[i] = 0;
	for (i = 0; i < N; i++) {
		scanf("%c %c", &cl, &cr);
		getc(stdin);
		if (cl != '-') {
			TreeArr[i].Left = cl - '0'; 	/* '6'-'0' is 6 of integer */
			check[TreeArr[i].Left] = 1;
		} else 
			TreeArr[i].Left = Null;

		if (cr != '-') {
			TreeArr[i].Right = cr - '0';
			check[TreeArr[i].Right] = 1;
		} else
			TreeArr[i].Right = Null;
	}
	for (i = 0; i < N; i++)
		if (!check[i])
			break;
	return (Root = i);
}

void LevelOrderListLeaves(Tree R)
{
	Queue Q;
	Tree T;
	int flag = 1; 	/* To control output format */

	if (R == EmptyTree) return;
	Q = CreatQueue(MaxSize);
	Enqueue(Q, R);

	while (!IsEmptyQ(Q)) {
		T = Dequeue(Q);
		if (TreeArr[T].Left == Null && TreeArr[T].Right == Null) {
			if (flag) flag = 0;
			else printf(" ");
			printf("%d", T); 	/* T is the index of the tree node in array */
		}
		if (TreeArr[T].Left != Null) Enqueue(Q, TreeArr[T].Left);
		if (TreeArr[T].Right != Null) Enqueue(Q, TreeArr[T].Right);
	}
	putchar('\n');
}

Queue CreatQueue(int MaxSz)
{
	Queue Q = (Queue) malloc(sizeof(struct QNode));
	Q->pTArr = (Tree *) malloc(MaxSz * sizeof(Tree));
	Q->Front = Q->Rear = 0;
	Q->Max = MaxSz;
	return Q;
}

void Enqueue(Queue Q, Tree T)
{
	if (IsFullQ(Q)) {
		printf("Full Queue!\n");
		return;
	}
	Q->Rear = (Q->Rear+1)%(Q->Max);
	Q->pTArr[Q->Rear] = T;
}

int IsFullQ(Queue Q)
{
	return ((Q->Rear+1) % (Q->Max) == Q->Front);
}

Tree Dequeue(Queue Q)
{
	if (IsEmptyQ(Q)) {
		printf("Queue empty!\n");
		return EmptyTree;
	}
	Q->Front = (Q->Front+1) % (Q->Max);
	return Q->pTArr[Q->Front];
}

int IsEmptyQ(Queue Q)
{
	return (Q->Front == Q->Rear);
}

