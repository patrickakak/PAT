#include <stdio.h>
#include <stdlib.h>

#define MaxData 1e3
#define ERROR -1

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
	ElementType *Elements;
	int Size;
	int Capacity;
};

MaxHeap Create( int MaxSize );
void PercolateUp( int p, MaxHeap H );
void PercolateDown( int p, MaxHeap H );
void Insert( MaxHeap H, ElementType item );
int IsFull( MaxHeap H );
int IsEmpty( MaxHeap H );
void BuildMaxHeap( int arr[], int N );	// T = O(N)

int main()
{
	MaxHeap H;
	int N, i;

	scanf("%d", &N);
	H = Create(N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &H->Elements[i]);
		H->Size++;
	}

	BuildMaxHeap(H->Elements, N);
	
	return 0;
}

MaxHeap Create( int MaxSize )
{
	MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *) malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;	// Set a sentinel
	return H;
}

void Insert( MaxHeap H, ElementType item )
{
	/* Insert item into MaxHeap, H->Elements[0] has been set */
	int p;

	if (IsFull(H)) { printf("MaxHeap is full!\n"); return; }
	p = ++H->Size;	// p point to the last element of the MaxHeap
	H->Elements[p] = item;

	PercolateUp(p, H);
}

int IsFull( MaxHeap H )
{
	return H->Size == H->Capacity;
}

ElementType DeleteMax( MaxHeap H )
{
	int Parent, Child;
	ElementType MaxItem, temp;

	if (IsEmpty(H)) { printf("MaxHeap is empty!\n"); return ERROR; }
	MaxItem = H->Elements[1];	// Get the max value to return
	H->Elements[1] = H->Elements[H->Size--];
	PercolateDown(1, H);
	return MaxItem;
}

int IsEmpty( MaxHeap H )
{
	return H->Size == 0;
}

/* We can get T = O(N) rather by using Insert function to get T = O(NlogN) */
void BuildMaxHeap( int arr[], int N )
{
	int i, Parent, Child, temp;

	/* Build a MaxHeap in this way, in the worst case, the time that we need 
	 * to move elements of Heap equals to the sum of every node heights:
	 *     eg. X = [log2N], (full binary tree)
	 *     2^0 + 2^1*(X-1) + 2^2*(X-2) + ... + 2^(X-1) * (X-(X-1))
	 *   = (2^0 + 2^1 + 2^2 + ... + 2^X-1)*X - (2^1 + 2^2*2 + 2^3*3 + ... + 2^(X-1) * (X-1))
	 *   = 2^(X+1) - X -2 = 2N - log2N -2 (i.e. T = O(N))
	 */
	for (i = N/2; i > 0; i--) {
		temp = arr[i];
		for (Parent = i; Parent*2 <= N; Parent = Child) {
			Child = Parent * 2;
			if ((Child != N) && (arr[Child] < arr[Child+1]))
				Child++;
			if (temp >= arr[Child]) break;
			else arr[Parent] = arr[Child];
		}
		arr[Parent] = temp;
	}
}

void PercolateUp( int p, MaxHeap H )
{
	int i;
	ElementType Tmp;

	/* If parent node is smaller, drag it down along the path to the root */

	for (i=p, Tmp=H->Elements[p]; H->Elements[i/2] < Tmp; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = Tmp;
}

void PercolateDown( int p, MaxHeap H )
{
	ElementType Tmp = H->Elements[p];
	int Parent, Child;

	/* 'Parent*2 <= H->Size' to find out if there is a left child,
	 * 'Parent=Child' to jump into the larger child's position */

	for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child = Parent*2) && (H->Elements[Child] < H->Elements[Child+1]))
			Child++;	// Child point to the larger one of two children
		if (Tmp >= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}

