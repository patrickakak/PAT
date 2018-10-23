/* Operation set of Binary Search Tree (BST) */
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

Position Find(BinTree BST, ElementType X);	/* Tail recursion */
Position IterFind(BinTree BST, ElementType X);	/* Iteration */
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);

int main()
{
	int i;
	BinTree BST;
	ElementType Arr[SIZE] = {4, 5, 2, 1, 7};

	for (BST=NULL, i=0; i < SIZE; i++)
		BST = Insert(BST, Arr[i]);

	for (i=SIZE-1; i >= 0; i--)
		BST = Delete(BST, Arr[i]);

	return 0;
}

Position Find(BinTree BST, ElementType X) 	/* Tail recursion */
{
	if (!BST) return EMPTY;		/* Empty Tree */
	if (X < BST->Data)
		return Find(BST->Left, X); 	/* Go seeking in right subtree */
	else if (X > BST->Data)
		return Find(BST->Right, X); 	/* Go seeking in left subtree */
	else	/* X equals BST->Data */
		return BST; 	/* Seeking done, return the position */
}

/* Tail recursion can always be transformed into loop way */
Position IterFind(BinTree BST, ElementType X)	/* Iteration */
{
	while (BST) {
		if (X < BST->Data) 	/* Go seeking in right subtree */
			BST = BST->Left;
		else if (X > BST->Data) 	/* Go seeking in left subtree */
			BST = BST->Right;
		else
			return BST;
	}
	return EMPTY;
}

/* Recursive */
Position FindMin(BinTree BST)
{
	if (!BST) return EMPTY;
	if (!BST->Left)
		return BST;		/* Find the leftest leaf node and return it */
	else
		return FindMin(BST->Left); 	/* Keep seeking in the left subtree */
}

/* No-recursive */
Position FindMax(BinTree BST)
{
	/* Keep seeking the rightest leaf node */
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) { 	/* If empty, it means we've found the place to insert */
		BST = (BinTree) malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else 	/* Keep finding... */
		if (X < BST->Data) 	/* Should be the left subtree to insert into */
			BST->Left = Insert(BST->Left, X);
		/* Should be the left subtree to insert into */
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);

	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;

	if (!BST) printf("Couldn't find the element!\n");
	else if (X < BST->Data)		/* Deletion happends in left subtree */
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)		/* Deletion happends in left subtree */
		BST->Right = Delete(BST->Right, X);
	else	/* Find it */
		/* Special handling of the node has two children by convert it into 
		 * a node with only a child or a leave node */
		if (BST->Left && BST->Right) {
			/* Or you can FindMin(BST->Right), try not to 
			 * change the feature of BST anyway */
			Tmp = FindMax(BST->Left);
			BST->Data = Tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		} else {	/* Handling of node with one or no child */
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}

