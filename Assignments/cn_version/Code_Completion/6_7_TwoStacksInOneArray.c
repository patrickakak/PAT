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
 * --------------------
 * Sample Output:
 * Stack 2 Empty
 * Stack 2 is Empty!
 * Stack Full
 * Stack 1 is Full!
 * Pop from Stack 1: 1
 * Pop from Stack 2: 13 12 11
 */
Stack CreateStack(int StackSize)
{
	Stack S;

	S = (Stack) malloc(sizeof(struct SNode));
	S->Data = (ElementType *) malloc(StackSize * sizeof(ElementType));
	S->Top1 = -1;
	S->Top2 = StackSize;
	S->MaxSize = StackSize;
	return S;
}

bool Push(Stack S, ElementType X, int Tag)
{
	if (S->Top2 - S->Top1 == 1 ) {
		printf("Stack Full\n");
		return false;
	}
	if (Tag != 1 && Tag != 2) return false;

	if (Tag == 1) S->Data[++S->Top1] = X;
	else S->Data[--S->Top2] = X;
	return true;
}

ElementType Pop(Stack S, int Tag)
{
	ElementType RetElem;

	if (Tag != 1 && Tag != 2) return ERROR;

	if ((Tag==1 && S->Top1==-1) || (Tag==2 && S->Top2==S->MaxSize)) {
		printf("Stack %d Empty\n", Tag);
		return ERROR;
	}
	if (Tag == 1) RetElem = S->Data[S->Top1--];
	else RetElem = S->Data[S->Top2++];

	return RetElem;
}

