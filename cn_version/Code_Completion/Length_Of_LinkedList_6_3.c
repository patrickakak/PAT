int Length(List L)
{
	int count = 0;
	PtrToLNode tmp = L;
	
	while (tmp) { tmp = tmp->Next; count++; }
	return count;
}
