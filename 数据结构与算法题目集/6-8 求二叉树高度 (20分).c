int GetHeight(BinTree BT) {
	if (BT) {
		int HL = GetHeight(BT->Left);
		int HR = GetHeight(BT->Right);
		int MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	} else return 0;
}
