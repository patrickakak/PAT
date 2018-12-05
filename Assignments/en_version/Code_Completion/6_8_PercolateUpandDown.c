/**
 * 6-8: Write the routines to do a "percolate up" and a "percolate down" 
 * in a binary min-heap.
 *
 * Sample Input:
 * 9
 * 1 10
 * 1 5
 * 1 2
 * 0
 * 1 9
 * 1 1
 * 1 4
 * 0
 * 0
 * Sample Output:
 * 2 1 4 
 * Inside H: 5 10 9
 */
/* Parameter int p is the position of the element */
void PercolateUp(int p, PriorityQueue H)
{
	int i;
	ElementType Tmp;

	for (i=p, Tmp=H->Elements[p]; H->Elements[i/2] > Tmp; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = Tmp;
}

void PercolateDown(int p, PriorityQueue H)
{
	ElementType Tmp = H->Elements[p];
	int Parent, Child;

	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] > H->Elements[Child+1]))
			Child++;
		if (Tmp <= H->Elements[Child])
			break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}

