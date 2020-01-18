/* Sample input:
 * 4 3 4 -5 2  6 1  -2 0
 * 3 5 20  -7 4  3 1
 * Sample output:
 * 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
 * 5 20 -4 4 -5 2 9 1 -2 0
 */
#include <cstdio>
#include <cstdlib>

typedef struct Node *PtrToNode;
struct Node {
	int coef;
	int exp;
	PtrToNode link;
};
typedef PtrToNode Polynomial;

/* Assistant functions */
int Compare(int a, int b);
PtrToNode MakeNode(int c, int e);
void Attach(int c, int e, PtrToNode *pRear);

/* Main feature functions */
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
Polynomial ReadPoly();

int main()
{
	Polynomial P1, P2, PP, PS; 	/* Product and sum of P1 and P2 */

	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PS = Add(P1, P2);
	PrintPoly(PP);
	PrintPoly(PS);

	return 0;
}

int Compare(int a, int b)
{
	return a > b ? 1 : a == b ? 0 : -1;
}

PtrToNode MakeNode(int c, int e)
{
	PtrToNode P;
	
	P = (PtrToNode) malloc(sizeof(struct Node));
	P->coef = c;
	P->exp = e;
	P->link = NULL;
	return P;
}

void Attach(int c, int e, PtrToNode *pRear)
{
	PtrToNode P;

	P = MakeNode(c, e);
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, Tmp;
	int sum;
	
	/* Using a dummy header for convenience */
	P = (Polynomial) malloc(sizeof(struct Node)); P->link = NULL;
	Rear = P;
	while (P1 && P2)
		switch (Compare(P1->exp, P2->exp)) {
		case 1:
			Attach(P1->coef, P1->exp, &Rear);
			P1 = P1->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum) Attach(sum, P1->exp, &Rear);

			P1 = P1->link; P2 = P2->link;
			break;
		case -1:
			Attach(P2->coef, P2->exp, &Rear);
			P2 = P2->link;
			break;
		}

	/* Handle the rest of the list which is not empty */
	for (; P1; P1 = P1->link) Attach(P1->coef, P1->exp, &Rear);
	for (; P2; P2 = P2->link) Attach(P2->coef, P2->exp, &Rear);

	Tmp = P; P = P->link; free(Tmp);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P;
	PtrToNode Rear, t1, t2, Tmp;
	int c, e;

	/* If one of the polynomial list is empty */
	if (!P1 || !P2) return NULL;

	t1 = P1; t2 = P2;
	P = (Polynomial) malloc(sizeof(struct Node)); P->link = NULL;
	Rear = P;
	/* Create a polynomial list firstly */
	while (t2) {
		Attach(t1->coef*t2->coef, t1->exp+t2->exp, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;

	/* Add new items into polynomial P created beforehand */
	while (t1) {
		t2 = P2; Rear = P;
		while (t2) {
			c = t1->coef * t2->coef;
			e = t1->exp + t2->exp;

			/* Find the position to insert into */
			while (Rear->link && Rear->link->exp > e)
				Rear = Rear->link;
			if (Rear->link && Rear->link->exp == e) {
				/* Coefficient sum is not 0 */
				if (Rear->link->coef + c)
					Rear->link->coef += c;
				else {
					Tmp = Rear->link; Rear->link = Tmp->link; free(Tmp);
				}
			} else {
				Tmp = MakeNode(c, e);
				Tmp->link = Rear->link; Rear->link = Tmp;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}

	Tmp = P; P = P->link; free(Tmp);
	return P;
}

void PrintPoly(Polynomial P)
{
	PtrToNode T = P;
	int flag = 0;

	if (!P) { printf("0 0\n"); return; }

	while (T) {
		if (!flag) flag = 1;
		else printf(" ");

		printf("%d %d", T->coef, T->exp);
		T = T->link;
	}
	putchar('\n');
}

Polynomial ReadPoly()
{
	int N, c, e;
	Polynomial P, Rear, t;

	scanf("%d", &N);
	P = (Polynomial) malloc(sizeof(struct Node)); P->link = NULL;
	Rear = P;
	while (N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}

	t = P; P = P->link; free(t);
	return P;
}

