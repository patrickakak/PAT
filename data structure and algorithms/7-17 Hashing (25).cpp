#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum { Empty, Taken } EntryType;

typedef struct HashEntry Cell;
struct HashEntry {
	EntryType Info;
};

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	Cell *Cells;
};

#define MAXN 100000

int NextPrime(int N);
HashTable CreateTable(int TableSize);
void DestroyTable(HashTable H);
int Hash(int Key, int P);
Position Find(HashTable H, ElementType Key);
Position Insert(HashTable H, ElementType Key);

int main()
{
	int M, N, i, Pos, flag = 0;
	HashTable H;
	ElementType Key;

	scanf("%d %d", &M, &N);		/* M<=10000, N<=M */

	H = CreateTable(M);
	for (i = 0; i < N; i++) {
		scanf("%d", &Key);
		Pos = Insert(H, Key);

		if (!flag) flag = 1;
		else printf(" ");

		if (Pos >= 0) printf("%d", Pos);
		else putchar('-');
	}
	putchar('\n');

	DestroyTable(H);

	return 0;
}

HashTable CreateTable(int TblSize)
{
	HashTable H;
	int i;

	H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TblSize);
	H->Cells = (Cell *) malloc(sizeof(Cell) * H->TableSize);

	for (i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
}

int NextPrime(int N)
{
	int i, p;

	if (N == 2 || N == 1) return 2;

	p = (N%2) ? N : N+1;
	while (1) {
		for (i = 3; i*i <= p; i++)
			if (!(p%i)) break;
		if (i*i > p) break;
		else p += 2;
	}
	return p;
}

void DestroyTable(HashTable H)
{
	free(H->Cells);
	free(H);
}

int Hash(int Key, int P)
{
	return Key % P;
}

/* Quadratic probing (with positive increments only) */
Position Find(HashTable H, ElementType Key)
{
	int i, j;
	Position CurrentPos, NewPos;
	bool visited[MAXN];

	for (i = 0; i < H->TableSize; i++)
		visited[i] = false;

	NewPos = CurrentPos = Hash(Key, H->TableSize);
	for (j = 1; H->Cells[NewPos].Info != Empty; j++) {
		NewPos = CurrentPos + j*j;
		if (NewPos >= H->TableSize)
			NewPos = NewPos % H->TableSize;

		if (!visited[NewPos])   /* It's impossible to insert the number */
			visited[NewPos] = true;
		else return -1;
	}
	return NewPos;
}

Position Insert(HashTable H, ElementType Key)
{
	Position Pos;

	Pos = Find(H, Key);
	if (Pos >= 0)
		H->Cells[Pos].Info = Taken;
	return Pos;
}
