#include <stdio.h>
#include <stdlib.h>

#define EMPTY NULL
#define SIZE 5

typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	BinTree Left, Right;
	ElementType Data;
};

Position Find(ElementType X, BinTree BST);	/* Tail recursion */
Position IterFind(ElementType X, BinTree BST);	/* Loop way */
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);

int main()
{
	int i;
	BinTree BST;
	ElementType Arr[SIZE] = {4, 5, 2, 1, 7};

	for (BST=NULL, i=0; i < SIZE; i++)
		BST = Insert(Arr[i], BST);

	return 0;
}

Position Find(ElementType X, BinTree BST)
{
	if (!BST) return EMPTY;		// Empty Tree
	if (X < BST->Data)
		return Find(X, BST->Left);	// Continue seeking in right subtree
	else if (X > BST->Data)
		return Find(X, BST->Right);		// ... in left subtree
	else	// X == BST->Data
		return BST;		// Seeking done, return the position
}

/* Tail recursion can always be transformed into loop way */
Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X < BST->Data)	// Keep seeking in right subtree
			BST = BST->Left;
		else if (X > BST->Data)		// ... in left subtree
			BST = BST->Right;
		else
			return BST;
	}
	return EMPTY;
}

Position FindMin(BinTree BST)
{
	if (!BST) return EMPTY;		// Empty binary search tree, return NULL
	if (!BST->Left)
		return BST;		// Find the leftest leaf node and return it
	else
		return FindMin(BST->Left);	// Keep seeking in the left subtree
}

Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right)	// Keep seeking the rightest leaf node
			BST = BST->Right;
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {		// If empty tree, generate a node
		BST = (BinTree) malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else	// Start to find out the position to insert
		if (X < BST->Data)	// Insert into left subtree recursively
			BST->Left = Insert(X, BST->Left);
		else if (X > BST->Data)		// ... right subtree recursively
			BST->Right = Insert(X, BST->Right);

	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;

	if (!BST) printf("Couldn't find the element!\n");
	else if (X < BST->Data)		// Left subtree deletion recursively
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)		// Right subtree deletion recursively
		BST->Right = Delete(X, BST->Right);
	else	// Find the node
		if (BST->Left && BST->Right) {	// The node has two children
			Tmp = FindMin(BST->Right);	// Find the minimum of right-subtree
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right); // Delete the minimum in the right subtree
		} else {	// There is only one child or no child at all of this node
			Tmp = BST;
			if (!BST->Left)		// There's right child or no child
				BST = BST->Right;
			else if (!BST->Right)	// There's left child or no child
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}
