#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;
struct Node {
	int Coef;
	int Exp;
	PtrToNode Link;
};

/* Assistant functions */
int Compare(int a, int b);
PtrToNode MakeNode(int Coef, int Exp);
void Attach(int Coef, int Exp, PtrToNode *pRear);

/* Main feature functions */
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
Polynomial ReadPoly();

int main()
{
	Polynomial P1, P2, PMult, PAdd;

	P1 = ReadPoly();
	P2 = ReadPoly();
	PMult = Mult(P1, P2);
	PAdd = Add(P1, P2);
	PrintPoly(PMult);
	PrintPoly(PAdd);

	return 0;
}

int Compare(int a, int b)
{
	return a > b ? 1 : a == b ? 0 : -1;
}

PtrToNode MakeNode(int Coef, int Exp)
{
	PtrToNode P;
	
	P = (PtrToNode) malloc(sizeof(struct Node));
	P->Coef = Coef;
	P->Exp = Exp;
	P->Link = NULL;
	return P;
}

void Attach(int Coef, int Exp, PtrToNode *pRear)
{
	PtrToNode P;

	P = MakeNode(Coef, Exp);
	(*pRear)->Link = P;
	(*pRear) = P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, Tmp;
	int Sum;
	
	/* Using a dummy header for convenience */
	P = (Polynomial) malloc(sizeof(struct Node));
	P->Link = NULL;
	Rear = P;
	while (P1 && P2)
		switch (Compare(P1->Exp, P2->Exp)) {
		case 1:
			Attach(P1->Coef, P1->Exp, &Rear);
			P1 = P1->Link;
			break;
		case 0:
			Sum = P1->Coef + P2->Coef;
			if (Sum) Attach(Sum, P1->Exp, &Rear);

			P1 = P1->Link;
			P2 = P2->Link;
			break;
		case -1:
			Attach(P2->Coef, P2->Exp, &Rear);
			P2 = P2->Link;
			break;
		}

	/* Handle the rest of the list which is not empty */
	while (P1) { Attach(P1->Coef, P1->Exp, &Rear); P1 = P1->Link; }
	while (P2) { Attach(P2->Coef, P2->Exp, &Rear); P2 = P2->Link; }

	Tmp = P; P = P->Link; free(Tmp);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P;
	PtrToNode Rear, t1, t2, Tmp;
	int Coefficient, Exponent;

	/* If one of the polynomial list is empty */
	if (!P1 || !P2) return NULL;

	P = (Polynomial) malloc(sizeof(struct Node));
	P->Link = NULL;
	Rear = P;
	t1 = P1;
	t2 = P2;
	/* Create a polynomial list firstly */
	while (t2) {
		Attach(t1->Coef*t2->Coef, t1->Exp+t2->Exp, &Rear);
		t2 = t2->Link;
	}
	t1 = t1->Link;

	/* Add new items into polynomial P created beforehand */
	while (t1) {
		t2 = P2;
		Rear = P;
		while (t2) {
			Coefficient = t1->Coef * t2->Coef;
			Exponent = t1->Exp + t2->Exp;

			/* Find the position to insert into */
			while (Rear->Link && Rear->Link->Exp > Exponent)
				Rear = Rear->Link;
			if (Rear->Link && Rear->Link->Exp == Exponent) {
				/* Coefficient sum is not 0 */
				if (Rear->Link->Coef + Coefficient)
					Rear->Link->Coef += Coefficient;
				else {
					Tmp = Rear->Link; Rear->Link = Tmp->Link; free(Tmp);
				}
			} else {
				Tmp = MakeNode(Coefficient, Exponent);
				Tmp->Link = Rear->Link;
				Rear->Link = Tmp;
			}
			t2 = t2->Link;
		}
		t1 = t1->Link;
	}

	Tmp = P; P = P->Link; free(Tmp);
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

		printf("%d %d", T->Coef, T->Exp);
		T = T->Link;
	}
	putchar('\n');
}

Polynomial ReadPoly()
{
	int N, c, e;
	Polynomial P, Rear, t;

	scanf("%d", &N);
	P = (Polynomial) malloc(sizeof(struct Node));
	P->Link = NULL;
	Rear = P;
	while (N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = P; P = P->Link; free(t);
	return P;
}

