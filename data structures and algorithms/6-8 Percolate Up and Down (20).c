void PercolateUp(int p, PriorityQueue H) {
	ElementType tmp = H->Elements[p];
	int pos;
	for (pos = p; H->Elements[pos/2] > tmp; pos /= 2)
		H->Elements[pos] = H->Elements[pos/2];
	H->Elements[pos] = tmp;
}
void PercolateDown(int p, PriorityQueue H) {
	ElementType Tmp = H->Elements[p];
	int Parent, Child;
	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] > H->Elements[Child+1])) Child++;
		if (Tmp <= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}
