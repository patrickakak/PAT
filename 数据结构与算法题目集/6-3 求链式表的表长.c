/**
 * Sample Input:
 * 1 3 4 5 2 -1
 * Sample Output:
 * 5
 */
int Length(List L)
{
	int count = 0;
	PtrToLNode tmp = L;
	
	while (tmp) {
		tmp = tmp->Next;
		count++;
	}
	return count;
}

