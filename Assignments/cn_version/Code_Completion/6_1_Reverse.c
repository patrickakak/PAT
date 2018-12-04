/**
 * 6-1 Reverse linked list 
 * Sample Input:
 * 5
 * 1 3 4 5 2
 * Sample Output:
 * 1
 * 2 5 4 3 1
 */

/* L point to node 1
 * 1->3->4->5->2 ==> 2->5->4->3->1
 */
List Reverse(List L)
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

