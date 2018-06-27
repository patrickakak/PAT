// Non-recursive binary tree InOrderTraversal
void InOrderTraversal( BinTree BT )
{
	BinTree T = BT;
	Stack S = CreateStack(MaxSize);		// Create and initialize stack
	while (T || !IsEmpty(S)) {
		while (T) {		// Go left and push treenodes into stack along the way
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);		// Pop a treenode out
			printf("%5d", T->Data);		// Access data in treenode
			T = T->Right;	// Turn to right subtree
		}
	}
}

