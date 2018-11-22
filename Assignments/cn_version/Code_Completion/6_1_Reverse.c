// PTA--Data Structures and Algorithms (Chinese version)
// 6-1 Reverse linked list

// L point to node 1
// 1->3->4->5->2 ==> 2->5->4->3->1
List Reverse( List L )
{
	PtrToNode RemainL = NULL, NewL = NULL;

	while (L) {
		RemainL = L->Next;
		L->Next = NewL;
		NewL = L;
		L = RemainL;
	}
	return NewL;
}

