/**
 * Sample Input:
 * 5
 * Push 1 1
 * Pop 2
 * Push 2 11
 * Push 1 2
 * Push 2 12
 * Pop 1
 * Push 2 13
 * Push 2 14
 * Push 1 3
 * Pop 2
 * End
 * --------------
 * Sample Output:
 * Stack 2 is Empty!
 * Stack 1 is Full!
 * Pop from Stack 1: 1
 * Pop from Stack 2: 13 12 11
 */
Stack CreateStack(int MaxElements)
{
	Stack S;

	S = (Stack) malloc(sizeof(struct StackRecord));
	S->Capacity = MaxElements;
	S->Top1 = -1;
	S->Top2 = MaxElements;
	S->Array = (ElementType *) malloc(S->Capacity * sizeof(ElementType));
	
	return S;
}

/* Stacknum is the index of a stack which is either 1 or 2 */
int IsEmpty(Stack S, int Stacknum)
{
	switch (Stacknum) {
	case 1:
		if (S->Top1 == -1) return 1;
		else return 0;
	case 2:
		if (S->Top2 == S->Capacity) return 1;
		else return 0;
	}
}

int IsFull(Stack S)
{
	if (S->Top2 - S->Top1 == 1)
		return 1;
	else
		return 0;
}

int Push(ElementType X, Stack S, int Stacknum)
{
	if (IsFull(S)) return 0;

	if (Stacknum == 1)
		S->Array[++S->Top1] = X;
	else
		S->Array[--S->Top2] = X;
	return 1;
}

/* Top_Pop must return ERROR which is defined by the judge program */
ElementType Top_Pop(Stack S, int Stacknum)
{
	ElementType RetElem;

	if (IsEmpty(S, Stacknum)) return ERROR;

	if (Stacknum == 1)
		RetElem = S->Array[S->Top1--];
	else
		RetElem = S->Array[S->Top2++];
	return RetElem;
}

