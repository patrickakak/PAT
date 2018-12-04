/* Your function will be put here */
static PtrToNode MakeNode()
{
	PtrToNode NewNode;

	NewNode = (PtrToNode) malloc(sizeof(struct Node));
	NewNode->Next = NULL;
	
	return NewNode;
}

static void Attach(int Coef, int Exp, Polynomial *pRear)
{
	PtrToNode NewNode;

	NewNode = MakeNode();
	NewNode->Coefficient = Coef;
	NewNode->Exponent = Exp;
	
	(*pRear)->Next = NewNode;
	(*pRear) = NewNode;
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

	rear = MakeNode(); 	/* Sum Polynomial */
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

