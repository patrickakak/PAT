/* Your function will be put here */
static PtrToNode MakeNode(int Coef, int Exp)
{
	PtrToNode pNewNode;

	pNewNode = (PtrToNode) malloc(sizeof(struct Node));
	pNewNode->Coefficient = Coef;
	pNewNode->Exponent = Exp;
	pNewNode->Next = NULL;
	
	return pNewNode;
}

static void Attach(int Coef, int Exp, Polynomial *pRear)
{
	PtrToNode pNewNode;

	pNewNode = MakeNode(Coef, Exp);
	(*pRear)->Next = pNewNode;
	(*pRear) = pNewNode;
}

static int Compare(int a, int b)
{
	return a > b ? 1 : a == b ? 0 : -1;
}

Polynomial Add(Polynomial a, Polynomial b)
{
	Polynomial front, rear;
	PtrToNode P1, P2;
	int sum;

	rear = (Polynomial) malloc(sizeof(struct Node));	/* Sum Polynomial */
	rear->Next = NULL;
	front = rear;
	P1 = a->Next; P2 = b->Next;
	while (P1 && P2)
		switch (Compare(P1->Exponent, P2->Exponent)) {
		case 1:
			Attach(P1->Coefficient, P1->Exponent, &rear);
			P1 = P1->Next;
			break;
		case 0:
			sum = P1->Coefficient + P2->Coefficient;
			if (sum) Attach(sum, P1->Exponent, &rear);
			P1 = P1->Next; P2 = P2->Next;
			break;
		case -1:
			Attach(P2->Coefficient, P2->Exponent, &rear);
			P2 = P2->Next;
			break;
		}

	for (; P1; P1 = P1->Next) Attach(P1->Coefficient, P1->Exponent, &rear);
	for (; P2; P2 = P2->Next) Attach(P2->Coefficient, P2->Exponent, &rear);

	return front;
}

