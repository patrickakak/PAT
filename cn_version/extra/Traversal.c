typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

// Binary tree preorder traversal
void PreOrderTraversal( BinTree BT )
{
	// If BT is empty, do nothing
	if (BT) {
		printf("%d", BT->Data);	// Visit data in root node
		PreOrderTraversal(BT->Left);	// PreOrderTraversal recursively
		PreOrderTraversal(BT->Right);
	}
}

void InOrderTraversal( BinTree BT )
{
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

void PostOrderTraversal( BinTree BT )
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

