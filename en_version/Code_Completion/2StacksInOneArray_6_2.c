Stack CreateStack( int MaxElements )
{
	Stack S;

	S = (Stack) malloc(sizeof(struct StackRecord));
	S->Capacity = MaxElements;
	S->Top1 = -1;
	S->Top2 = MaxElements;
	S->Array = (ElementType *) malloc(MaxElements * sizeof(ElementType));
	return S;
}

int IsEmpty( Stack S, int Stacknum )
{
	if (Stacknum == 1) { if (S->Top1 == -1) return 1; else return 0; } 
	else { if (S->Top2 == S->Capacity) return 1; else return 0; }
}

int IsFull( Stack S )
{
	if (S->Top2 - S->Top1 == 1) return 1;
	else return 0;
}

int Push( ElementType X, Stack S, int Stacknum )
{
	if (IsFull(S)) return 0;

	if (Stacknum == 1) S->Array[++S->Top1] = X;
	else S->Array[--S->Top2] = X;

	return 1;
}

ElementType Top_Pop( Stack S, int Stacknum )
{
	ElementType RetElem;

	if (IsEmpty(S, Stacknum)) return ERROR;

	if (Stacknum == 1) RetElem = S->Array[S->Top1--];
	else RetElem = S->Array[S->Top2++];

	return RetElem;
}
