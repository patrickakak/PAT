Stack CreateStack( int MaxSize )
{
	Stack S;

	S = (Stack) malloc(sizeof(struct SNode));
	S->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	S->Top1 = -1;
	S->Top2 = MaxSize;
	S->MaxSize = MaxSize;
	return S;
}

bool Push( Stack S, ElementType X, int Tag )
{
	if (S->Top2 - S->Top1 == 1 ) { printf("Stack Full\n"); return false; }
	if (Tag != 1 && Tag != 2) return false;

	if (Tag == 1) S->Data[++S->Top1] = X;
	else S->Data[--S->Top2] = X;

	return true;
}

ElementType Pop( Stack S, int Tag )
{
	ElementType RetElem;

	if (Tag != 1 && Tag != 2) return ERROR;

	if ((Tag == 1 && S->Top1 == -1) || (Tag == 2 && S->Top2 == S->MaxSize)) {
		printf("Stack %d Empty\n", Tag);
		return ERROR;
	}

	if (Tag == 1) RetElem = S->Data[S->Top1--];
	else RetElem = S->Data[S->Top2++];

	return RetElem;
}

