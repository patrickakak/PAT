PtrToNode MakeNode() {
	PtrToNode NewNode = (PtrToNode) malloc(sizeof(struct Node));
	NewNode->Next = NULL;
	return NewNode;
}
void Attach(int Coef, int Exp, Polynomial *pRear) {
	PtrToNode NewNode = MakeNode();
	NewNode->Coefficient = Coef;
	NewNode->Exponent = Exp;
	(*pRear)->Next = NewNode;
	(*pRear) = NewNode;
}
int Compare(int a, int b){
	return a > b ? 1 : a == b ? 0 : -1;
}
Polynomial Add(Polynomial a, Polynomial b) {
	PtrToNode P1, P2;
	Polynomial rear = MakeNode();
	Polynomial front = rear;
	P1 = a->Next; P2 = b->Next;
	int sum;
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
