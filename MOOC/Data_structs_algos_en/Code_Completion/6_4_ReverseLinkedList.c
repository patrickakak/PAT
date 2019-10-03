/**
 * Sample Input:
 * 5
 * 1 3 4 5 2
 * Sample Output:
 * 2 5 4 3 1
 * 2 5 4 3 1
 */

/* The function Reverse is supposed to return the reverse linked list of L,
 * with a dummy header. 

 * A nonrecursive procedure to reverse a singly linked list in O(N) time 
 * using constant extra space
 */
List Reverse(List L)
{
	List R, T, ReversedL = NULL;

	/* Start to reverse the list without head node */
	T = L->Next;
	while (T) {
		R = T->Next; 	/* Remaining nodes */
		T->Next = ReversedL; 	/* Build new linked list */
		ReversedL = T; 	/* New linked list grows */
		T = R; 	/* Traverse */
	}
	L->Next = ReversedL;	/* Add dummy head node */
	return L;
}

