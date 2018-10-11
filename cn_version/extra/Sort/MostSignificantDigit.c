/* Radix sort - Most significant digit first */

/* Assume that there are MaxDigit key and the radix is same */
#define MaxDigit 4
#define Radix 10

/* Bucket element node */
typedef struct Node *PtrToNode;
struct Node{
	int key;
	PtrToNode next;
};

/* Bucket head node */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

/* LSD=1 by default, MSD<=MaxDitit */
int GetDigit(int X, int D)
{
	int d, i;

	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

/* The core recursive function: sort the D digit of A[L]...A[R] */
void MSD(ElementType A[], int L, int R, int D)
{
	int Di, i, j;
	Bucket B;
	PtrToNode tmp, p, List = NULL; 
	if (D == 0) return;		/* Termination condition */

	for (i = 0; i < Radix; i++)		/* Initialize every bucket as empty list */
		B[i].head = B[i].tail = NULL;
	for (i = L; i <= R; i++) {	/* Store the original sequence into List in reversed order */
		tmp = (PtrToNode) malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* Distribution process */
	p = List;
	while (p) {
		Di = GetDigit(p->key, D);	/* Get the current digit of the current element */
		/* Remove from List */
		tmp = p; p = p->next;
		/* Insert into the bucket of number B[Di] */
		if (B[Di].head == NULL) B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}
	/* Collecting process */
	i = j = L;	/* index i, j to mark the left and right boundary of A[] */
	for (Di = 0; Di < Radix; Di++)	/* For every bucket */
		if (B[Di].head) {	/* Pour elements in non-empty bucket into A[] recursively */
			p = B[Di].head;
			while (p) {
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			/* Sort the data in bucket recursively, digit minus 1 */
			MSD(A, i, j-1, D-1);
			i = j;	/* The left boundary of A[] of next bucket */
		} 
}

/* Unified interface */
void MSDRadixSort(ElementType A[], int N)
{
	MSD(A, 0, N-1, MaxDigit); 
}

