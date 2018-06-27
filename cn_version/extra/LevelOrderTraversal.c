// LevelOrderTraversal
void LevelOrderTraversal( BinTree BT )
{
	Queue Q;
	BinTree T;

	if (!BT) return;	// If it's an empty tree
	Q = CreateQueue(MaxSize);	// Create and initialize queue
	EnQueue(Q, BT);
	while (!IsEmpetyQ(Q)) {
		T = DeQueue(Q);
		printf("d\n", T->Data);
		if (T->Left) EnQueue(T->Left);
		if (T->Right) EnQueue(T->Right);
	}
}

