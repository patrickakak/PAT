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

enum KeyStatus { Duplicate, SearchFailure, Success, InsertIt, LessKeys };

void insert(int key)
{
	struct node *newnode;
	int upKey;
	enum KeyStatus value;

	value = ins(root, key, &upKey, &newnode);
	if (value == Duplicate)
		printf("Key already available\n");
	if (value == InsertIt) {
		struct node *uproot = root;
		root=malloc(sizeof(struct node));
		root->n = 1;
		root->keys[0] = upKey;
		root->p[0] = uproot;
		root->p[1] = newnode;
	}
}

enum KeyStatus ins( struct node *ptr, int key, int *upKey, struct node **newnode)
{
	struct node *newPtr, *lastPtr;
	int pos, i, n,splitPos;
	int newKey, lastKey;
	enum KeyStatus value;

	if (ptr == NULL) {
		*newnode = NULL;
		*upKey = key;
		return InsertIt;
	}
	n = ptr->n;
	pos = searchPos(key, ptr->keys, n);
	if (pos < n && key == ptr->keys[pos])
		return Duplicate;
	value = ins(ptr->p[pos], key, &newKey, &newPtr);
	if (value != InsertIt)
		return value;
	/* If keys in node is less than M-1 where M is order of B tree */
	if (n < M - 1) {
		pos = searchPos(newKey, ptr->keys, n);
		/* Shifting the key and pointer right for inserting the new key */
		for (i = n; i > pos; i--) {
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		/* Key is inserted at exact location */
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
		++ptr->n; 	/* incrementing the number of keys in node */
		return Success;
	}
	/* If keys in nodes are maximum and position of node to be inserted is last */
	if (pos == M - 1) {
		lastKey = newKey;
		lastPtr = newPtr;
	} else {
	/* If keys in node are maximum and position of node to be inserted is not last */
		lastKey = ptr->keys[M-2];
		lastPtr = ptr->p[M-1];
		for (i = M-2; i > pos; i--) {
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
	}
	// splitPos = (M - 1)/2;
	splitPos = M / 2;
	(*upKey) = ptr->keys[splitPos];

	(*newnode) = malloc(sizeof(struct node)); 	/* Right node after split */
	ptr->n = splitPos; /*No. of keys for left splitted node*/
	(*newnode)->n = M-1-splitPos; 	/* No. of keys for right splitted node */
	for (i = 0; i < (*newnode)->n; i++) {
		(*newnode)->p[i] = ptr->p[i + splitPos + 1];
		if (i < (*newnode)->n - 1)
			(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
		else
			(*newnode)->keys[i] = lastKey;
	}
	(*newnode)->p[(*newnode)->n] = lastPtr;
	return InsertIt;
}

