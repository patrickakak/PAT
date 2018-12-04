/**
 * Sample Input:
 * 6
 * 12 2 4 87 10 2
 * 4
 * 2 12 87 5
 * Sample Output:
 * -------------------------------
 * 2 is found and deleted.
 * 12 is found and deleted.
 * 87 is found and deleted.
 * Finding Error: 5 is not in.
 * 5 is inserted as the last element.
 * Wrong Position for Insertion
 * Wrong Position for Deletion
 * 10 4 2 5 
 */
Position Find(List L, ElementType X)
{
	Position tmp = L;

	while (tmp && tmp->Data != X)
		tmp = tmp->Next;
	
	if (tmp) return tmp;
	else return ERROR;
}

List Insert(List L, ElementType X, Position P)
{
	PtrToLNode Tmp, PNewLNode;

	/* Create a new node and initialize it */
	PNewLNode = (PtrToLNode) malloc(sizeof(struct LNode));
	PNewLNode->Data = X;
	PNewLNode->Next = NULL;

	/* If P points to header node, different handling */
	if (L == P) { PNewLNode->Next = P; L = PNewLNode; return L; }

	/* If P is not same with L, find out whether P is valid */
	Tmp = L;
	while (Tmp && P != Tmp->Next)
		Tmp = Tmp->Next;

	/* If Tmp is not null, then P is valid */
	if (Tmp) {
		PNewLNode->Next = Tmp->Next;
		Tmp->Next = PNewLNode;
		return L;
	} else {
		free(PNewLNode);
		printf("Wrong Position for Insertion\n");
		return ERROR;
	}
}

List Delete(List L, Position P)
{
	PtrToLNode T, tmp;

	/* If P is NULL or list is empty, return ERROR */
	if (!P || !L) return ERROR;

	/* If P points to the header node */
	if (L == P) {
		tmp = L; L = L->Next; free(tmp);
		return L;
	}
	/* If list is not empty, find out whether P is valid */
	T = L;
	while (T && P != T->Next)
		T = T->Next;

	/* If T != NULL, then P is valid, and T points to the previous node of P */
	if (T) {
		tmp = P; T->Next = tmp->Next; free(tmp);
		return L;
	} else {
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
}

