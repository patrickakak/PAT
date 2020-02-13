#include <stdio.h>
#define MaxSize 10000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];
/* T = O(N^2) */
/*
void Find(SetType S[], ElementType X)
{
	int i;

	for (i = 0; i < MaxSize && S[i].Data != X; i++) ;
	if (i >= MaxSize) return -1;
	for (; S[i].Parent >= 0; i = S[i].Parent) ;
	return i;
}
*/

/* TSSN implimentation: two simple sometimes naive 
 * if Union(Find(2), Find(1)), ... Union(Find(n), Find(1)), then T = O(N^2))
 *
 * By default, Root1 and Root2 are different root of set respectively */
/*
void Union(SetType S, SetName Root1, SetName Root2)
{
	S[Root2] = Root1;
}
*/

/* Merge trees according to rank, 
 * in worst case, the height of tree will be H = O(logN) */
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

/* Initialize the elements in a set as -1 */
/*
SetName Find(SetType S, ElementType X)
{
	for (; S[X] >= 0; X = S[X]) ;
	return X;
}
*/

/* Path compression (refer to Ackermann Function)
 * 
 * k1Ma(M, N) <= T(M, N) <= k2Ma(M, N)
 *
 *            /  2^j                (i=1 and j>=1)
 * A(i, j) =     A(i-1, 2)          (i>=2 and j=1)
 *            \  A(i-1, A(i, j-1))  (i>=2 and j>=2)
 *
 * a(M, N) = min{ i>=1 | A(i, [M/N]) > logN } <= O(log*N) <= 4 (normally) 
 */
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0) return X;
	else return S[X] = Find(S, S[X]);
}
void Initialization(SetType S, int N) {
	for (int i = 0; i < N; i++) S[i] = -1;
}
void Input_connection(SetType S) {
	ElementType u, v;
	scanf("%d %d\n", &u, &v);
	SetName Root1 = Find(S, u-1);
	SetName Root2 = Find(S, v-1);
	if (Root1 != Root2) Union(S, Root1, Root2);
}
void Check_connection(SetType S) {
	ElementType u, v;
	scanf("%d %d", &u, &v); getchar();
	SetName Root1 = Find(S, u-1);
	SetName Root2 = Find(S, v-1);
	if (Root1 == Root2) puts("yes");
	else puts("no");
}
void Check_network(SetType S, int N) {
	int counter = 0;
	for (int i = 0; i < N; i++)
		if (S[i] < 0) counter++;
	if (counter == 1) puts("The network is connected.");
	else printf("There are %d components.\n", counter);
}
int main() {
	SetType S;
	int N;
	char in;
	scanf("%d\n", &N);
	Initialization(S, N);
	do {
		scanf("%c", &in);
		switch (in) {
		case 'I': Input_connection(S); break;
		case 'C': Check_connection(S); break;
		case 'S': Check_network(S, N); break;
		}
	} while (in != 'S');	
	return 0;
}
