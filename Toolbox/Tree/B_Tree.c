/*****************************************************
 *       IMPLEMENTATION OF B-TREE
 ****************************************************/

#define M 3

typedef int keyType;
typedef struct node *ptrToNode;
struct node {
	int n; 	/* n < M No. of keys in node will always less than order of B tree */
	keyType keys[M-1]; 	/*array of keys*/
	struct node *p[M]; 	/* (n+1 pointers will be in use) */
} *root = NULL;

