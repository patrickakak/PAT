List Reverse(List L) {
	PtrToNode RemainL, NewL = NULL;
	while (L) {
		RemainL = L->Next;
		L->Next = NewL;
		NewL = L;
		L = RemainL;
	}
	return NewL;
}
