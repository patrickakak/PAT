/* Your function will be put here */

// The function Reverse is supposed to return the reverse linked list of L,
// with a dummy header. 

// A nonrecursive procedure to reverse a singly linked list in O(N) time 
// using constant extra space
List Reverse( List L )
{
	List R, S, T, ReversedL = NULL;

	// Start to reverse the list without header
	T = L->Next;
	while (T) {
		R = T->Next;
		T->Next = ReversedL;
		ReversedL = T;
		T = R;
	}
	L->Next = ReversedL;	// Add dummy header
	return L;
}

