PtrToNode MakeNode() {
	PtrToNode P = (PtrToNode) malloc(sizeof(struct Node));
	if (!P) return NULL;
	P->Element = ERROR;
	P->Last = P->Next = NULL;
	return P;
}
Deque CreateDeque() {
	Deque D = (Deque) malloc(sizeof(struct DequeRecord));
	D->Front = MakeNode();
	D->Rear = D->Front;
	return D;
}
int Push(ElementType X, Deque D) {
	PtrToNode P = MakeNode();
	if (!P) return 0;
	P->Element = X;
	P->Last = D->Front;
	P->Next = D->Front->Next;
	if (D->Front == D->Rear) D->Rear = P;
	else D->Front->Next->Last = P;
	D->Front->Next = P;
	return 1;
}
ElementType Pop(Deque D) {
	if (D->Front == D->Rear) return ERROR;
	PtrToNode PTmp = D->Front->Next;
	ElementType RetElem = PTmp->Element;
	D->Front->Next = PTmp->Next;
	if (D->Rear == PTmp) D->Rear = D->Front;
	free(PTmp);
	return RetElem;
}
int Inject(ElementType X, Deque D) {
	PtrToNode P = MakeNode();
	if (!P) return 0;
	P->Element = X;
	P->Last = D->Rear;
	D->Rear->Next = P;
	D->Rear = P;
	return 1;
}
ElementType Eject(Deque D) {
	if (D->Front == D->Rear) return ERROR;
	PtrToNode PTmp = D->Rear;
	ElementType RetElem = PTmp->Element;
	D->Rear = PTmp->Last;
	free(PTmp);
	return RetElem;
}
