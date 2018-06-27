// Post order traversal to get the height of binary tree
int PostOrderGetHeight( BinTree BT )
{
	int HL, HR, MaxH;
	
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);	// To get the depth of left subtree
		HR = PostOrderGetHeight(BT->Right);	// To get the depth of right one
		MaxH = HL > HR ? HL : HR;	// To take the bigger one
		return (MaxH + 1);	// Return depth of tree
	} else 
		return 0;	// Empty subtree is depth of 0
}

