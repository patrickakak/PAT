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

MaxHeap Create(int MaxSize);
void Insert(MaxHeap H, ElementType item);
int IsFull(MaxHeap H);
int IsEmpty(MaxHeap H);
void BuildMaxHeap(int arr[], int N);	// T = O(N)

int main()
{
	MaxHeap H;
	int N, i;

	scanf("%d", &N);
	H = Create(N);
	for (i = 1; i <= N; i++)
		scanf("%d", &H->Elements[i]);

	BuildMaxHeap(H->Elements, N);
	
	return 0;
}

MaxHeap Create(int MaxSize)
{
	MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *) malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;	// Set a sentinel
	return H;
}

void Insert(MaxHeap H, ElementType item)
{
	/* Insert item into MaxHeap, H->Elements[0] has been set */
	int i;

	if (IsFull(H)) {
		printf("MaxHeap is full!\n");
		return;
	}
	i = ++H->Size;	// i point to the last element of the MaxHeap

	/* If parent node is smaller, drag it down along the path to the root */

	for (; H->Elements[i/2] < item; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = item;
}

int IsFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}

ElementType DeleteMax(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, temp;

	if (IsEmpty(H)) {
		printf("MaxHeap is empty!\n");
		return ERROR;
	}
	MaxItem = H->Elements[1];	// Get the max value to return

	/* Get the last element to replace the first valid node (Element[1]) */

	temp = H->Elements[H->Size--];

	/* 'Parent*2 <= H->Size' to find out if there is a left child,
	 * 'Parent=Child' to jump into the larger child's position */

	for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && 
				(H->Elements[Child] < H->Elements[Child+1]))
			Child++;	// Child point to the larger one of two children
		if (temp >= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

int IsEmpty(MaxHeap H)
{
	return H->Size == 0;
}

/* We can get T = O(N) rather by using Insert function to get T = O(NlogN) */
void BuildMaxHeap(int arr[], int N)
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

