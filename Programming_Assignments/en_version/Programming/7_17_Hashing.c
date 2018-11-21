/**
 * Sample Input:
 * 4 4
 * 10 6 4 15
 * Sample Output:
 * 0 1 4 -
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell;
struct HashEntry {
	ElementType Data;
	EntryType Info;
};

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	Cell *Cells;
};

#define MAXN 100000
bool visited[MAXN];

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

	freopen("data.txt", "r", stdin);
	scanf("%d %d", &M, &N);		// M<=10000, N<=M

	H = CreateTable(M);
	for (i = 0; i < N; i++) {
		scanf("%d", &Key);
		Pos = Insert(H, Key);
		if (!flag) flag = 1;
		else printf(" ");
		if (Pos >= 0)
			printf("%d", Pos);
		else printf("-");
	}
	putchar('\n');
	DestroyTable(H);
	return 0;
}

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell *) malloc(sizeof(Cell) * H->TableSize);

	for (i = 0; i < H->TableSize; i++) {
		H->Cells[i].Data = 0;
		H->Cells[i].Info = Empty;
	}
	return H;
}

int NextPrime(int N)
{
	int i, p = (N%2) ? N+2 : N+1;

	if (N == 1) return 2;

	while (1) {
		for (i = 3; i*i <= p; i+=2)
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

Position Find(HashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int i, CNum = 1;

	for (i = 0; i < H->TableSize; i++)
		visited[i] = false;
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key) {
		NewPos = CurrentPos + (CNum)*(CNum);
		if (NewPos >= H->TableSize)
			NewPos = NewPos % H->TableSize;
		if (!visited[NewPos])
			visited[NewPos] = true;
		else return -1;
		++CNum;
	}
	return NewPos;
}

Position Insert(HashTable H, ElementType Key)
{
	Position Pos;

	Pos = Find(H, Key);
	if (Pos == -1)
		return -1;
	else {
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return Pos;
	}
}

