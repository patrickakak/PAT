/**
 * Sample Input:
 * 1 3 4 5 2 -1
 * 6
 * 3 6 1 5 4 2
 * Sample Output:
 * 4 NA 1 2 5 3 
 */
ElementType FindKth(List L, int K)
{
	int i;
	PtrToLNode tmp;

	for (i=1, tmp=L; tmp!=NULL && i<K; tmp=tmp->Next, i++)
		continue;

	if (i == K && tmp) return tmp->Data;
	else return ERROR;
}

