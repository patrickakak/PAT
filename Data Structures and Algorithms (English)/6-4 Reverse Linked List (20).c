List Reverse(List L) {
	List R, ReversedL = NULL, T = L->Next;
	while (T) {
		R = T->Next;
		T->Next = ReversedL;
		ReversedL = T;
		T = R;
	}
	L->Next = ReversedL;
	return L;
}
