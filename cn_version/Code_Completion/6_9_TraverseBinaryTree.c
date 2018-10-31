void InorderTraversal( BinTree BT )
{
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal( BinTree BT )
{
	if (BT) {
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal( BinTree BT )
{
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

void LevelorderTraversal( BinTree BT )
{
	if (!BT) return;
	
	const int SIZE = 16;
	BinTree BTmp, BTQueue[SIZE];
	int front = 0, rear = 0;
	rear = (rear + 1)%SIZE;
	BTQueue[rear] = BT;
	
	// If a binary tree queue is not full and is not empty
	while (front != rear) {
		if ((rear + 1)%SIZE == front) { printf("Full Queue"); return; }
		front = (front + 1)%SIZE;
		BTmp = BTQueue[front];
		printf(" %c", BTmp->Data);
		
		if (BTmp->Left) { 
			rear = (rear + 1)%SIZE;
			BTQueue[rear] = BTmp->Left;
		}
		if (BTmp->Right) {
			rear = (rear + 1)%SIZE;
			BTQueue[rear] = BTmp->Right;
		}
	}
}

