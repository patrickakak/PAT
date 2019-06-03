/**
 * 6-9: Get the height of a binary tree
 *               A
 *              / \
 *             B   C
 *            / \  / \
 *           D  F  G  I
 *             /    \
 *            E      H
 * Sample Output:
 * 4
 */
int GetHeight(BinTree BT)
{
	int HL, HR, MaxH;

	if (BT) {
		HL = GetHeight(BT->Left);	/* To get the depth of left subtree */
		HR = GetHeight(BT->Right);	/* To get the depth of right one */
		MaxH = HL > HR ? HL : HR;	/* Take the bigger one */
		return (MaxH + 1);	/* Return depth of subtree */
	} else 
		return 0;	/* Empty subtree is depth of 0 */
}

