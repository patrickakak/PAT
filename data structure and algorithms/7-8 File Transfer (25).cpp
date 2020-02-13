#include <stdio.h>
#define MaxSize 10000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}
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
