typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
	ElementType Data;
	AVLTree Left; 	/* Point to left subtree */
	AVLTree Right; 	/* Point to right subtree */
	int Height; 	/* Height of tree */
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

/* A must have a left childnode B: single left rotation of A and B, update 
 * height of both tree and return root node B then */
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = 1 + Max(GetHeight(A->Left), GetHeight(A->Right));
	B->Height = 1 + Max(GetHeight(B->Left), A->Height);
	return B;
}

/* A must have childnode B (left) and C (right):
 * do single rotation twice and return root C */
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	/* Single right rotation of B and C, return C */
	A->Left = SingleRightRotation(A->Left);
	/* Single left rotation of A and C, return C */
	return SingleLeftRotation(A);
}

/*************************************************************************/
/* Implementation of single left rotation and double right left rotation */
/*************************************************************************/

/* Insert X into AVL tree and return the re-arranged AVL tree */
AVLTree Insert(AVLTree T, ElementType X)
{
	if (!T) { 	/* Create a new node if empty */
		T = (AVLTree) malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	} else if (X < T->Data) {
		/* Insert it into left subtree of T */
		T->Left = Insert(T->Left, X);
		/* Need left rotation? */
		if (GetHeight(T->Left)-GetHeight(T->Right) == 2) {
			if (X < T->Left->Data) 
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	} else if (X > T->Data) {
		/* Insert it into right subtree of T */
		T->Right = Insert(T->Right, X);
		/* Need right rotation? */
		if (GetHeight(T->Left)-GetHeight(T->Right) == -2) {
			if (X > T->Right->Data)
				T = SingleRightRotation(T);
			else 
				T = DoubleRightLeftRotation(T);
		}
	}
	/* else X == T->Data, no need do insertion */

	/* Update height of AVL tree */
	T->Height = 1 + Max(GetHeight(T->Left), GetHeight(T->Right));

	return T;
}

