/** 
 * 6-9 Traverse the binary tree:
 *               A
 *              / \
 *             B   C
 *            / \  / \
 *           D  F  G  I
 *             /    \
 *            E      H
 * Sample Output:
 * Inorder: D B E F A G H C I
 * Preorder: A B D F E C G H I
 * Postorder: D E F B H G I C A
 * Levelorder: A B C D F G I E H
 */
void InorderTraversal(BinTree BT)
{
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT)
{
	if (BT) {
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT)
{
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

void LevelorderTraversal(BinTree BT)
{
	if (!BT) return;
	
	const int SIZE = 16;
	BinTree BTmp, BTQueue[SIZE];
	int front = 0, rear = 0;
	rear = (rear + 1)%SIZE;
	BTQueue[rear] = BT;
	
	/* If a binary tree queue is not full and is not empty */
	while (front != rear) {
		if ((rear + 1)%SIZE == front) {
			printf("Full Queue");
			return;
		}
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

