int Length(List L) {
	int count = 0;
	PtrToLNode t = L;
	while (t) {
		t = t->Next;
		count++;
	}
	return count;
}
