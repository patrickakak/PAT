/**
 * Sample Input:
 * 6
 * 12 2 4 87 10 2
 * 4
 * 2 12 87 5
 * ----------------------
 * Sample Output:
 * 2 is found and deleted.
 * 12 is found and deleted.
 * 87 is found and deleted.
 * Finding Error: 5 is not in.
 * 5 is inserted as the last element.
 * Wrong Position for Insertion
 * Wrong Position for Deletion
 * 10 4 2 5 
 */
List MakeEmpty()
{
	List L;

	L = (List) malloc(sizeof(struct LNode));
	L->Next = NULL;
	return L;
}

Position Find(List L, ElementType X)
{
	PtrToLNode T = L->Next;

	while (T && T->Data != X)
		T = T->Next;

	if (T) return T;
	else return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
	PtrToLNode T, PNewNode;

	PNewNode = (PtrToLNode) malloc(sizeof(struct LNode));
	PNewNode->Data = X;
	PNewNode->Next = NULL;

	/* Check if P is valid */
	T = L;
	while (T && T->Next != P)
		T = T->Next;
	if (T) {	/* If P is valid */
		PNewNode->Next = T->Next; T->Next = PNewNode;
		return true;
	} else {
		free(PNewNode); 
		printf("Wrong Position for Insertion\n");
		return false;
	}
}

bool Delete(List L, Position P)
{
	PtrToLNode T;

	if (!P) return false;

	/* Check if P is valid */
	T = L;
	while (T && T->Next != P)
		T = T->Next;

	/* If P is valid */
	if (T) {
		T->Next = P->Next; free(P); 
		return true;
	} else {
		printf("Wrong Position for Deletion\n");
		return false;
	}
}

