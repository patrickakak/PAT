#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Null -1
#define MaxSize 10
typedef char ElementType;
typedef int Tree;
struct TNode {
	ElementType Data;
	Tree Left, Right;
} T1[MaxSize], T2[MaxSize];
Tree BuildTree(struct TNode T[]) {
	int i, N, Root=Null, check[MaxSize];
	char cl, cr;
	scanf("%d\n", &N);
	if (N) {
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			scanf("%c %c %c", &T[i].Data, &cl, &cr);
			getc(stdin);
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			} else T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			} else T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i]) break;
		Root = i;
	}
	return Root;
}
bool Isomorphic(Tree R1, Tree R2) {
	if (R1==Null && R2==Null)
		return true;
	if ((R1==Null && R2!=Null) || (R2==Null && R1!=Null))
		return false;
	if (T1[R1].Data != T2[R2].Data)
		return false;
	if (T1[R1].Left==Null && T2[R2].Left==Null)
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (T1[R1].Left!=Null && T2[R2].Left!=Null && T1[T1[R1].Left].Data==T2[T2[R2].Left].Data)
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}
int main() {
	Tree R1 = BuildTree(T1);
	Tree R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
