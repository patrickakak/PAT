/**
 * 6-11: Print leaves node in preorder traversal
 *               A
 *              / \
 *             B   C
 *            / \  / \
 *           D  F  G  I
 *             /    \
 *            E      H
 * --------------------------------------
 * Sample Output:
 * Leaf nodes are: D E H I
 */
void PreorderPrintLeaves(BinTree BT)
{
	if (BT) {
		if (!BT->Left && !BT->Right)
			printf(" %c", BT->Data);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}

