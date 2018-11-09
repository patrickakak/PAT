typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int Nv; 	/* Number of visitation */
};

/* Binary tree preorder traversal (recursive) */
void PreOrderTraversal(BinTree BT)
{
	/* If BT is empty, do nothing */
	if (BT) {
		printf("%d", BT->Data); 	/* Visit the node */
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

/* Inorder traversal (recursive) */
void InOrderTraversal(BinTree BT)
{
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

/* Postorder traversal (recursive) */
void PostOrderTraversal(BinTree BT)
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

/* Non-recursive binary tree traversals
 * Brief algorithm:
 *   1. Encounter a node, push it into the stack and 
 *      go through its left subtree
 *   2. After the left subtree has been traversed, 
 *      pop the node out and access it
 *   3. Then traverse the right subtree of the node 
 *      by its right pointer(InOrderTraversal)
 */
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	/* If T is not NULL or there is(are) element(s) inside the stack, 
	 * go on with the loop, i.e. if T is NULL and stack is empty, 
	 * it ends(or never enter the loop)
	 */
	while (T || !IsEmpty(S)) {
		while (T) { 	/* Find the leftest node */
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S); 	/* Second time to visit it */
			printf("%5d", T->Data);
			T = T->Right; 	/* Reset root and do the same */
		}
	}
}

/* Non-recursive preorder traversals */
void PreOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T); 	/* First time to visit it */
			printf("%5d", T->Data);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Right;
		}
	}
}

/* Non-recursive postorder traversals */
void PostOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	while (T || !IsEmpty(S)) {
		while (T) {
			T->Nv = 1;
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S); T->Nv++;
			if (!T->Right)
				T->Nv++; 	/* If the right subtree is NULL */
			if (T->Nv == 3) {
				printf("%5d", T->Data);
				T = NULL;
			} else {
				Push(S, T);
				T = T->Right;
			}
		}
	}
}

