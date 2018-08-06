#include <stdio.h>
#include <stdlib.h>

// Tail recursion
Position Find(ElementType X, BinTree BST)
{
	if (!BST) return NULL;	// Empty tree
	if (X > BST->Data)
		return Find(X, BST->Right);		// Continue seeking in right subtree
	else if (X < BST->Data)
		return Find(X, BST->Left);	// Continue seeking in left subtree
	else	// X == BST->Data
		return BST;		// Seeking done, return the position
}

// Loop
Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)	// Keep seeking in right subtree
			BST = BST->Right;
		else if (X < BST->Data)		// ... in left subtree
			BST = BST->Left;
		else
			return BST;
	}
	return NULL;
}

// Recursive method
Position FindMin(BinTree BST)
{
	if (!BST) return NULL;	// Empty binary search tree, return NULL
	else if (!BST->Left)
		return BST;		// Find the leftest leaf node and return it
	else
		return FindMin(BST->Left); // Keep seeking in the left subtree
}

// Loop method
Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right)	// Keep seeking the rightest leaf node
			BST = BST->Right;
	return BST;
}

