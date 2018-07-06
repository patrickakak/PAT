// LevelOrderTraversal
void LevelOrderTraversal( BinTree BT )
{
	Queue Q;
	BinTree T;

	if (!BT) return;	// If it's an empty tree
	Q = CreateQueue(MaxSize);	// Create and initialize queue
	EnQueue(Q, BT);
	while (!IsEmptyQ(Q)) {
		T = DeQueue(Q);
		printf("d\n", T->Data);
		if (T->Left) EnQueue(Q, T->Left);
		if (T->Right) EnQueue(Q, T->Right);
	}
}

