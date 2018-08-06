#include <stdio.h>
#include <stdlib.h>

// Tail recursion
Position Find(ElementType X, BinTree BST)
{
	if (!BST) return NULL;	// Empty tree
	if (X > BST->Data)
		return Find(X, BST->Right);	// Continue seeking in right subtree
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

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {		// If empty tree, generate a node
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else	// Start to find out the position to insert
		if (X < BST->Data)	// Insert into left subtree recursively
			BST->Left = Insert(X, BST->Left);
		else (X > BST->Data)	// ... right subtree recursively
			BST->Right = Insert(X, BST->Right);

	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;

	if (!BST) printf("Couldn't find the element\n");
	else if (X < BST->Data)	 // Left subtree deletion recursively
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)		// Right subtree deletion recursively
		BST->Right = Delete(X, BST->Right);
	else	// Find the node
		if (BST->Left && BST->Right) { // The node has two children
			Tmp = FindMin(BST->Right);	// Find the minimum in right subtree to replace the node
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right); // Delete the minimum in the right subtree
		} else {	// There is only one child or no child at all of this node
			Tmp = BST;
			if (!BST->Left)		// There's right child or no child
				BST = BST->Right;
			else if (!BST->Right) // There's left child or no child
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}

