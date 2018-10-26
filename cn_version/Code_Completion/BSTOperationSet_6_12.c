#define EMPTY NULL

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) {
		BST = (BinTree) malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else if (X < BST->Data)
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
	/* BST->Data equals to X */
	else if (BST->Left && BST->Right) {
		Tmp = FindMax(BST->Left); 	/* Or FindMin(BST->Right) */
		BST->Data = Tmp->Data;
		/* Or BST->Right = Delete(BST->Right, BST->Data) */
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
	while (BST)
		if (X < BST->Data)
			BST = BST->Left;
		else if (X > BST->Data)
			BST = BST->Right;
		else
			return BST;
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

