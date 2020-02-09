int FactorialSum(List L) {
	List p = L;
	int total = 0, member, i;
	while (p) {
		member = 1;
		for (i = p->Data; i > 0; i--) member *= i;
		total += member;
		p = p->Next;
	}
	return total;
}
