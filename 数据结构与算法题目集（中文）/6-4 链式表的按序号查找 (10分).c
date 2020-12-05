ElementType FindKth(List L, int K) {
	int i = 1;
	PtrToLNode tmp = L;
	for ( ; tmp!=NULL && i<K; tmp=tmp->Next, i++) continue;
	if (i == K && tmp) return tmp->Data;
	else return ERROR;
}
