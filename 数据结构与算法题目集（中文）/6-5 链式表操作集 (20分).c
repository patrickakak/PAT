Position Find(List L, ElementType X) {
	Position tmp = L;
	while (tmp && tmp->Data != X)
		tmp = tmp->Next;
	if (tmp) return tmp;
	else return ERROR;
}
List Insert(List L, ElementType X, Position P) {
	PtrToLNode PNewLNode = (PtrToLNode) malloc(sizeof(struct LNode));
	PNewLNode->Data = X;
	PNewLNode->Next = NULL;
	if (L == P) {
		PNewLNode->Next = P;
		L = PNewLNode;
		return L;
	}
	PtrToLNode Tmp = L;
	while (Tmp && P != Tmp->Next) Tmp = Tmp->Next;
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
List Delete(List L, Position P) {
	if (!P || !L) return ERROR;
	if (L == P) {
		PtrToLNode tmp = L;
		L = L->Next;
		free(tmp);
		return L;
	}
	PtrToLNode T = L;
	while (T && P != T->Next) T = T->Next;
	if (T) {
		PtrToLNode tmp = P;
		T->Next = tmp->Next;
		free(tmp);
		return L;
	} else {
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
}
