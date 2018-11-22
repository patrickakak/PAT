/* Sample Input1:
 * 5
 * 88 70 61 96 120
 * Sample Output1:
 * 70
 * ----------------
 * Sample Input2:
 * 7
 * 88 70 61 96 120 90 65
 * Sample Output2:
 * 88
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *PtrToTNode;
typedef PtrToTNode AVLTree;
typedef int ElemType;
struct TNode {
	ElemType v;
	AVLTree Left, Right;
	int Height;
};

AVLTree InsertAVL(AVLTree T, ElemType V);
AVLTree NewNode(ElemType V);
AVLTree SingleLeftRotation(AVLTree A); 	/* Left-Left rotation */
AVLTree SingleRightRotation(AVLTree A); 	/* Right-Right rotation */
AVLTree DoubleLeftRightRotation(AVLTree A); 	/* Left-Right rotation */
AVLTree DoubleRightLeftRotation(AVLTree A); 	/* Right-Left rotation */
int GetHeight(AVLTree A);
int Max(int a, int b);

int main()
{
	int N, i;
	ElemType x;
	AVLTree T = NULL;

	scanf("%d", &N); 	/* N is positive guaranteed */
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		T = InsertAVL(T, x);
	}
	printf("%d\n", T->v);
	return 0;
}

AVLTree InsertAVL(AVLTree T, ElemType V)
{
	if (!T) T = NewNode(V);
	else if (V < T->v) {
		T->Left = InsertAVL(T->Left, V);

		/* Self-balancing after completing a insertation, cause 'X < T->v'
		 * last time, so if the tree gets unbalanced, it must be the Left
		 * subtree which is relatively taller */

		if (GetHeight(T->Left)-GetHeight(T->Right) == 2) {
			if (V < T->Left->v)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	} else if (V > T->v) {
		T->Right = InsertAVL(T->Right, V);
		if (GetHeight(T->Right)-GetHeight(T->Left) == 2) {
			if (V > T->Right->v)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	/* Update height of AVL tree so we don't need to use the 
	 * recursive version of GetHeight() function */

	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

AVLTree NewNode(ElemType V)
{
	AVLTree T = (AVLTree) malloc(sizeof(struct TNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->Height = 0;
	return T;
}

int GetHeight(AVLTree A)
{
	if (!A) return 0;
	else return A->Height;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

