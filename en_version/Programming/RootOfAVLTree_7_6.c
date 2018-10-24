#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TreeNode *AVLTree;
struct TreeNode {
	ElementType v;
	AVLTree Left, Right;
};

AVLTree Insert(AVLTree T, ElementType X);	/* Insert a node recursively */
int GetHeight(AVLTree T);
AVLTree LLRotation(AVLTree T);	/* Left-Left rotation */
AVLTree LRRotation(AVLTree T);	/* Left-Right rotation */
AVLTree RRRotation(AVLTree T);	/* Right-Right rotation */
AVLTree RLRotation(AVLTree T);	/* Right-Left rotation */

int main()
{
	ElementType X;
	int N, i;
	AVLTree T = NULL;

	/**
	 *  ----------------------------------
	 * | INPUT                 |   OUTPUT |
	 *  ----------------------------------
	 * | 5                     |          |
	 * | 88 70 61 96 120       |    70    |
	 * | 7                     |          |
	 * | 88 70 61 96 120 90 65 |    88    |
	 *  ----------------------------------
	 */
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		T = Insert(T, X);
	}
	printf("%d\n", T->v);

	return 0;
}

AVLTree Insert(AVLTree T, ElementType X)
{
	if (!T) {
		T = (AVLTree) malloc(sizeof(struct TreeNode));
		T->v = X;
		T->Left = T->Right = NULL;
	} else
		if (X < T->v) {
			T->Left = Insert(T->Left, X);

			/* Self-balancing after completing a insertation, cause 'X < T->v'
			 * last time, so if the tree gets unbalanced, it must be the Left
			 * subtree which is relatively taller */

			if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
				if (X < T->Left->v) T = LLRotation(T);
				else T = LRRotation(T);
		} else if (X > T->v) {
			T->Right = Insert(T->Right, X);
			if (GetHeight(T->Right) - GetHeight(T->Left) == 2)
				if (X > T->Right->v) T = RRRotation(T);
				else T = RLRotation(T);
		}
	return T;
}

int GetHeight(AVLTree T)
{
	int HL, HR, MaxH;

	if (T) {
		HL = GetHeight(T->Left);
		HR = GetHeight(T->Right);
		MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	} else
		return 0;
}

AVLTree LLRotation(AVLTree T)
{
	AVLTree Parent = T->Left;
	T->Left = Parent->Right;
	Parent->Right = T;
	return Parent;
}

AVLTree LRRotation(AVLTree T)
{
	AVLTree Parent, LChild, RChild; /* LChild, RChild to store childs of new parent temporarily */

	Parent = T->Left->Right;
	LChild = Parent->Left;
	RChild = Parent->Right;
	Parent->Right = T;
	Parent->Left = T->Left;
	T->Left->Right = LChild;
	T->Left = RChild;

	return Parent;
}

AVLTree RRRotation(AVLTree T)
{
	AVLTree Parent = T->Right;
	T->Right = Parent->Left;
	Parent->Left = T;
	return Parent;
}

AVLTree RLRotation(AVLTree T)
{
	AVLTree Parent, LChild, RChild;

	Parent = T->Right->Left;
	LChild = Parent->Left;
	RChild = Parent->Right;
	Parent->Left = T;
	Parent->Right = T->Right;
	T->Right->Left = RChild;
	T->Right = LChild;

	return Parent;
}

