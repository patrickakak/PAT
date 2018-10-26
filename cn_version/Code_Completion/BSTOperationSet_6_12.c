/* Sapmle Input:
 * 10
 * 5 8 6 2 4 1 0 10 9 7
 * 5
 * 6 3 10 0 5
 * 5
 * 5 7 0 10 3
 * Sample Output:
 * Preorder: 5 2 1 0 4 8 6 7 10 9
 * 6 is found
 * 3 is not found
 * 10 is found
 * 10 is the largest key
 * 0 is found
 * 0 is the smallest key
 * 5 is found
 * Not Found
 * Inorder: 1 2 4 6 8 9
 */
#define EMPTY NULL

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) {
		BST = (BinTree) malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else
		if (X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);

	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;

	if (!BST) printf("Not Found\n");
	else if (X < BST->Data)
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)
		BST->Right = Delete(BST->Right, X);
	else
		if (BST->Left && BST->Right) {
			Tmp = FindMax(BST->Left);
			BST->Data = Tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		} else {
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	while (BST) {
		if (X < BST->Data)
			BST = BST->Left;
		else if (X > BST->Data)
			BST = BST->Right;
		else
			return BST;
	}
	return EMPTY;
}

Position FindMin(BinTree BST)
{
	if (!BST)
		return EMPTY;
	if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}

