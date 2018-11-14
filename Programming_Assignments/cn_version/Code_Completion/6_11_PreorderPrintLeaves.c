void PreorderPrintLeaves( BinTree BT )
{
	if (BT) {
		if (!BT->Left && !BT->Right)
			printf(" %c", BT->Data);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}

