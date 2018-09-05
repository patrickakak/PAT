/* Your function will be put here */
void PercolateUp( int p, PriorityQueue H )
{
	int i;
	ElementType Tmp;

	for (i=p, Tmp=H->Elements[p]; H->Elements[i/2] > Tmp; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = Tmp;
}

void PercolateDown( int p, PriorityQueue H )
{
	ElementType Tmp = H->Elements[p];
	int Parent, Child;

	for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child = Parent*2) && (H->Elements[Child] > H->Elements[Child+1]))
			Child++;
		if (Tmp <= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}


