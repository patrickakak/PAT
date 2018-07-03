// Non-recursive binary tree InOrderTraversal
void InOrderTraversal( BinTree BT )
{
	BinTree T = BT;
	Stack S = CreateStack(MaxSize);		// Create and initialize stack

	// If T is not NULL or there is(are) element(s) inside the stack, 
	// go on with the loop, i.e. if T is NULL and stack is empty, 
	// it ends(or never enter the loop)

	while (T || !IsEmpty(S)) {
		// If T is not NULL
		while (T) {		// Go left and push treenodes into stack along the way
			Push(S, T);
			T = T->Left;
		}
		// If stack is not empty
		if (!IsEmpty(S)) {
			T = Pop(S);		// Pop a treenode out
			printf("%5d", T->Data);		// Access data in treenode
			T = T->Right;	// Turn to right subtree
		}
	}
}

