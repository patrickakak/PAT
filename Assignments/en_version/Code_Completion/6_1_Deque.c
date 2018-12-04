/* Your function will be put here */
PtrToNode MakeNode()
{
	PtrToNode P;

	P = (PtrToNode) malloc(sizeof(struct Node));
	if (!P) return NULL;
	
	P->Element = ERROR;
	P->Last = P->Next = NULL;
	return P;
}

Deque CreateDeque()
{
	Deque D;

	/* Create a dummy header */
	D = (Deque) malloc(sizeof(struct DequeRecord));
	D->Front = MakeNode();
	D->Rear = D->Front;
	return D;
}

int Push(ElementType X, Deque D)
{
	PtrToNode P;

	if (!(P = MakeNode())) return 0;
	P->Element = X;
	P->Last = D->Front;
	P->Next = D->Front->Next;

	/* Only need 1 time Rear adjustment for push operation */
	if (D->Front == D->Rear)
		D->Rear = P;
	else
		D->Front->Next->Last = P;
	D->Front->Next = P;
	return 1;
}

ElementType Pop(Deque D)
{
	PtrToNode PTmp;
	ElementType RetElem;

	if (D->Front == D->Rear)
		return ERROR;

	PTmp = D->Front->Next;
	RetElem = PTmp->Element;
	D->Front->Next = PTmp->Next;

	/* If there's only one item, pointer Rear need special handling */
	if (D->Rear == PTmp)
		D->Rear = D->Front;
	free(PTmp);

	return RetElem;
}

int Inject(ElementType X, Deque D)
{
	PtrToNode P;

	if (!(P = MakeNode())) return 0;
	P->Element = X;
	
	/* Linking doubly list */
	D->Rear->Next = P;
	P->Last = D->Rear;
	D->Rear = P;
	return 1;
}

ElementType Eject(Deque D)
{
	PtrToNode PTmp;
	ElementType RetElem;

	if (D->Front == D->Rear)
		return ERROR;

	PTmp = D->Rear;
	RetElem = PTmp->Element;
	D->Rear = PTmp->Last;

	free(PTmp);
	return RetElem;
}

