/* Sample Input1:
 * 8
 * A 1 2
 * B 3 4
 * C 5 -
 * D - -
 * E 6 -
 * G 7 -
 * F - -
 * H - -
 * 8
 * G - 4
 * B 7 6
 * F - -
 * A 5 1
 * H - -
 * C 0 -
 * D - -
 * E 2 -
 * Sample Output1:
 * Yes
 * -------------------
 * Sample Input2:
 * 8
 * B 5 7
 * F - -
 * A 0 3
 * C 6 -
 * H - -
 * D - -
 * G 4 -
 * E 1 -
 * 8
 * D 6 -
 * B 5 -
 * E - -
 * H - -
 * C 0 2
 * G - 3
 * F - -
 * A 1 4
 * Sample Output2:
 * No
 */
#include <stdio.h>
#include <stdlib.h>

#define Null -1
#define MaxSize 10
typedef char ElementType;
typedef int Tree;
struct TNode {
	ElementType Data;
	Tree Left, Right;
} T1[MaxSize], T2[MaxSize];

Tree BuildTree(struct TNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}

Tree BuildTree(struct TNode T[])
{
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
			} else
				T[i].Left = Null;

			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			} else
				T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (!check[i]) break; 	/* To find out root */
		Root = i;
	}
	return Root;
}

/* A recursive function */
int Isomorphic(Tree R1, Tree R2)
{
	if (R1==Null && R2==Null) 	/* Both empty */
		return 1;
	if ((R1==Null && R2!=Null) || (R2==Null && R1!=Null))
		return 0; 	/* One of them is empty */
	if (T1[R1].Data != T2[R2].Data)
		return 0; 	/* Roots are different */
	/* Both have no left subtree */
	if (T1[R1].Left==Null && T2[R2].Left==Null)
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if ((T1[R1].Left!=Null && T2[R2].Left!=Null) 
			&& (T1[T1[R1].Left].Data==T2[T2[R2].Left].Data))
		/* No need to swap the left and the right */
		return (Isomorphic(T1[R1].Left, T2[R2].Left) 
				&& Isomorphic(T1[R1].Right, T2[R2].Right));
	else 	/* Need to swap the left and the right */
		return (Isomorphic(T1[R1].Left, T2[R2].Right) 
				&& Isomorphic(T1[R1].Right, T2[R2].Left));
}

