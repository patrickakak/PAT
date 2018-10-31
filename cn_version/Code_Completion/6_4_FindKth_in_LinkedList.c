ElementType FindKth(List L, int K)
{
	int i;
	PtrToLNode tmp;

	for (i = 1, tmp = L; tmp != NULL && i < K; tmp = tmp->Next, i++)
		continue;

	if (i == K && tmp) return tmp->Data;
	else return ERROR;
}
