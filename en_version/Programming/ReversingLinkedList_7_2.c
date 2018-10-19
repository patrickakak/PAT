/* Sample Input:
 * 00100 6 4
 * 00000 4 99999
 * 00100 1 12309
 * 68237 6 -1
 * 33218 3 00000
 * 99999 5 68237
 * 12309 2 33218
 * Sample Output:
 * 00000 4 33218
 * 33218 3 12309
 * 12309 2 00100
 * 00100 1 99999
 * 99999 5 68237
 * 68237 6 -1
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
#define MAXSIZE 100000

struct LNode {
	int Addr;	// The position of the node
	int Data;
	int Next;	// The position of the next node
};

typedef struct ListRecord *List;
struct ListRecord {
	int          FirAddr;	// First address
	struct LNode Arr[MAXSIZE];	// Array to store List nodes
	int          Last;	// The total number of nodes
};

List CreateList();
void PrintList(List L);
List ReverseK(List L, int K); // Reverse the links of every K elements on L
int FindPos(List L, int Current, int K);
int CountList(List L);

int main()
{
	List L;
	int FirstAddr, N, K, i;
	struct LNode Tmp;

	// The address of the first node, the total number of nodes, 
	// the length of the sublist to be reversed stored
	scanf("%d %d %d", &FirstAddr, &N, &K);
	L = CreateList();
	L->FirAddr = FirstAddr;

	// Read the input and store them into array
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &Tmp.Addr, &Tmp.Data, &Tmp.Next);
		L->Arr[Tmp.Addr] = Tmp;
	}

	// Get the actual number of list nodes
	L->Last = CountList(L);

	// Reverse and print list afterwards
	L = ReverseK(L, K);
	PrintList(L);

	return 0;
}

int CountList(List L)
{
	int i, t;
	for (t = L->FirAddr, i = 0; t != -1; i++, t = L->Arr[t].Next)
		continue;
	return i;
}

List ReverseK(List L, int K)
{
	int i, j;
	int Times, W, T, P, R;
	int N = -1, flag = 0;
	
	if (K > L->Last) return ERROR;	// Invalid K
	if (K == 1) return L;		// Same as the original list

	Times = L->Last / K;
	W = L->Last;
	T = P = L->FirAddr;
	for (i = 0; i < Times; i++) {
		for (j = 0; j < K; j++) {
			R = L->Arr[T].Next;
			L->Arr[T].Next = N;
			N = T;
			T = R;
		}
		W -= K; 	// Check if there's a need for subsequent reverse
		
		if (W/K < 1) 	// Don't need to reverse
			L->Arr[P].Next = R;
		else { 	// Still got sublist to be reversed
			L->Arr[P].Next = FindPos(L, R, K);
			P = R;
		}
		// First time handling
		if (flag == 0) {
			L->FirAddr = N;
			flag = 1;
		}
	}
	return L;
}

int FindPos(List L, int Current, int K)
{
	int i, index;
	
	// K nodes, K-1 times searching
	for (index = Current, i = 1; i < K; i++)
		index = L->Arr[index].Next;

	return index;
}

List CreateList()
{
	List L;

	L = (List) malloc(sizeof(struct ListRecord));
	L->FirAddr = -1;
	L->Last = -1;
	return L;
}

void PrintList(List L)
{
	int i, t;

	for (t=L->FirAddr, i=0; i < L->Last && t != -1; i++, t=L->Arr[t].Next)
		if (L->Arr[t].Next == -1)
			printf("%05d %d -1\n", L->Arr[t].Addr, L->Arr[t].Data);
		else
			printf("%05d %d %05d\n", 
					L->Arr[t].Addr, L->Arr[t].Data, L->Arr[t].Next);
}

