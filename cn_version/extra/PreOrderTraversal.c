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
	if (BT) {
		printf("%d", BT->Data);	// Visit data in root node
		PreOrderTraversal(BT->Left);	// PreOrderTraversal recursively
		PreOrderTraversal(BT->Right);
	}
}

