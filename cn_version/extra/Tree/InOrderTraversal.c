// Non-recursive binary tree InOrderTraversal
// Brief algorithm:
//   1. Encounter a node, push it into the stack and 
//      go through its left subtree
//   2. After the left subtree has been traversed, 
//      pop the node out and access it
//   3. Then traverse the right subtree of the node 
//      by its right pointer(InOrderTraversal)
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
			// printf("%5d", T->Data); // PreOrderTraversal accessing
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

// Non-recursive postOrder traversal
void PostOrderTraversal( BinTree BT )
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);
	Stack S2 = CreatStack(MaxSize);

	// PostOrder: Left -> Right -> Root (Root -> Right -> Left)
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			// printf("%d", T->Data);
			Push(S2, T);
			T = T->Right;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Left;
		}
	}

	while (!IsEmpty(S2)) { T = Pop(S2); printf("%d", T->Data); }
}
