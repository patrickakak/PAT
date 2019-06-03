/**
 * Sample Input:
 * 5
 * L 1234567890 myQQ@qq.com
 * N 1234567890 myQQ@qq.com
 * N 1234567890 myQQ@qq.com
 * L 1234567890 myQQ@qq
 * L 1234567890 myQQ@qq.com
 * -------------------------
 * Smaple Output:
 * ERROR: Not Exist
 * New: OK
 * ERROR: Exist
 * ERROR: Wrong PW
 * Login: OK
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define KEYLENGTH 10
#define PWLENGTH 16

typedef unsigned int Index;
typedef char KeyType[KEYLENGTH+1];
typedef char PWType[PWLENGTH+1];
typedef struct LNode *PtrToLNode;
struct LNode {
	KeyType Key;
	PWType PW;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	List Heads;
};

int NextPrime(int N);
HashTable CreateTable(int TblSize);
void DestroyTable(HashTable H);
void Login(HashTable H, KeyType Key, PWType PW);
Index Hash(KeyType Key, int Size);
Position Find(HashTable H, KeyType Key);
void Insert(HashTable H, KeyType Key, PWType PW);
void Apply(HashTable H, KeyType Key, PWType PW);

int main()
{
	int N, i;
	char Op;
	KeyType Key;
	PWType PW;
	HashTable H;

	scanf("%d\n", &N);
	H = CreateTable(N);
	
	for (i = 0; i < N; i++) {
		scanf("%c %s %s\n", &Op, Key, PW);
		switch (Op) {
		case 'L':
			Login(H, Key, PW);
			break;
		case 'N':
			Apply(H, Key, PW);
			break;
		}
	}
	DestroyTable(H);
	return 0;
}

void Apply(HashTable H, KeyType Key, PWType PW)
{
	Position P;

	P = Find(H, Key);
	if (P)
		puts("ERROR: Exist");
	else {
		Insert(H, Key, PW);
		puts("New: OK");
	}
}

void Insert(HashTable H, KeyType Key, PWType PW)
{
	Position NewCell;
	Index Pos;

	NewCell = (Position) malloc(sizeof(struct LNode));
	strcpy(NewCell->Key, Key);
	strcpy(NewCell->PW, PW);

	Pos = Hash(Key, H->TableSize);
	NewCell->Next = H->Heads[Pos].Next;
	H->Heads[Pos].Next = NewCell;
}

void Login(HashTable H, KeyType Key, PWType PW)
{
	Position P;

	P = Find(H, Key);
	if (!P)
		puts("ERROR: Not Exist");
	else {
		if (strcmp(PW, P->PW))
			puts("ERROR: Wrong PW");
		else
			puts("Login: OK");
	}
}

Index Hash(KeyType Key, int Size)
{
	int i;
	Index Pos = 0;

	for (i = 0; Key[i]; i++)
		Pos = (Pos<<4) + Key[i];
	return Pos % Size;
}

Position Find(HashTable H, KeyType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(Key, H->TableSize);

	P = H->Heads[Pos].Next;
	while (P && strcmp(P->Key, Key))
		P = P->Next;
	return P;
}

int NextPrime(int N)
{
	int i, p;

	if (N == 1 || N == 2) return 2;
	p = (N%2) ? N : N+1;
	while (1) {
		for (i = 3; i*i <= p; i++)
			if (!(p%i)) break;
		if (i*i > p) break;
		else p += 2;
	}
	return p;
}

HashTable CreateTable(int TblSize)
{
	HashTable H;
	int i;

	H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TblSize);
	H->Heads = (List) malloc(H->TableSize * sizeof(struct LNode));

	for (i = 0; i < H->TableSize; i++) {
		H->Heads[i].Key[0] = '\0';
		H->Heads[i].PW[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	return H;
}

void DestroyTable(HashTable H)
{
	int i;
	Position P, Tmp;

	for (i = 0; i < H->TableSize; i++) {
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);
	free(H);
}

