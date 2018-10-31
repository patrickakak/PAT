/* Your function will be put here */
#define ERROR NULL
typedef enum { false, true } bool;
typedef struct StackRecord *PtrToStack;
typedef PtrToStack Stack;
struct StackRecord {
	ElementType Data[Max_Expr];
	int         Top;
};

Stack CreateStack()
{
	Stack S;

	S = (Stack) malloc(sizeof(struct StackRecord));
	if (!S) return ERROR;
	S->Top = -1;
	return S;
}

bool Push( Stack S, ElementType X )
{
	if (S->Top == Max_Expr-1) return false;

	S->Data[++S->Top] = X;
	return true;
}

ElementType Pop( Stack S )
{
	if (S->Top == -1) return Infinity;
	return S->Data[S->Top--];
}

bool IsOperator( int ch )
{
	if (strchr("+-*/", ch)) return true;
	return false;
}

bool IsValidInput( int ch )
{
	if (strchr("+-*/ .0123456789", ch)) return true;
	return false;
}

ElementType EvalPostfix( char *expr )
{
	ElementType X, v1, v2, v;
	char *t = expr, *front = expr;
	Stack S;
	int i, flag = 0;

	// If expression string is empty, return Infinity
	if (expr[0] == '\0') return Infinity;

	if ((expr[0] == '.' || expr[0] == '-') && expr[1] == '\0') return Infinity;

	// If input is only one float number, print it directly
	for (i = 1; expr[i]; i++)
		if (expr[i] != '.' && !isdigit(expr[i]))
			flag = 1;
	if (flag == 0) return atof(expr);

	S = CreateStack();

	while (*t) {
		// Check the validity of input characters
		if (!IsValidInput(*t)) return Infinity;

		// Last input character must be a valid operator
		if (*(t+1)=='\0' && !IsOperator(*t)) return Infinity;

		switch (*t) {
		case ' ':
			// Space as seperator
			if (sscanf(front, "%lf", &X)) Push(S, X);
			front = t + 1;
			break;
		case '+':
			if (*(front+1) != '\0' && *(front+1) != ' ') break;
			v2 = Pop(S);
			v1 = Pop(S);
			if (v1 == Infinity || v2 == Infinity) return Infinity;
			v = v1 + v2;
			Push(S, v);
			break;
		case '-':
			if (*(front+1) != '\0' && *(front+1) != ' ') break;
			v2 = Pop(S);
			v1 = Pop(S);
			if (v1 == Infinity || v2 == Infinity) return Infinity;
			v = v1 - v2;
			Push(S, v);
			break;
		case '*':
			v2 = Pop(S);
			v1 = Pop(S);
			if (v1 == Infinity || v2 == Infinity) return Infinity;
			v = v1 * v2;
			Push(S, v);
			break;
		case '/':
			v2 = Pop(S);
			v1 = Pop(S);
			if (v1 == Infinity || v2 == Infinity || fabs(v2) < 0.000000001)
				return Infinity;
			v = v1 / v2;
			Push(S, v);
			break;
		case '.':
			if (*(t+1) != '\0' && !isdigit(*(t+1))) return Infinity;
		}
		t++;
	}
	// Take the last number in stack
	v = Pop(S);
	if (S->Top != -1) return Infinity;

	return v;
}

