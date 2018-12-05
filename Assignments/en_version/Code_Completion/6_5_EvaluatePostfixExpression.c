/**
 * Sample Input1:
 * 11 -2 5.5 * + 23 7 / -
 * Sample Output1:
 * -3.285714
 * -----------------------
 * Sample Input2:
 * 11 -2 5.5 * + 23 0 / -
 * Sample Output2:
 * ERROR
 * -----------------------
 * Sample Input3:
 * 11 -2 5.5 * + 23 7 / - *
 * Sample Output3:
 * ERROR
 */
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#define ERROR NULL
#define err Infinity
typedef enum { operand, operator } type;
typedef struct StackRecord *PtrToStack;
typedef PtrToStack Stack;
struct StackRecord {
	ElementType Data[Max_Expr];
	int Top;
};

Stack CreateStack()
{
	Stack S;

	S = (Stack) malloc(sizeof(struct StackRecord));
	if (!S) return ERROR;
	S->Top = -1;
	return S;
}

void DestroyStack(Stack S)
{
	free(S);
}

bool IsFullS(Stack S)
{
	return S->Top == Max_Expr-1;
}

bool Push( Stack S, ElementType X )
{
	if (IsFullS(S)) return false;

	S->Data[++S->Top] = X;

	return true;
}

bool IsEmptyS(Stack S)
{
	return S->Top == -1;
}

ElementType Pop( Stack S )
{
	if (IsEmptyS(S))
		return err;
	return S->Data[S->Top--];
}

type GetOperandOrOperator(char *expr, char s[Max_Expr])
{
	int i;
	type typ;

	for (i = 0; *expr && !isspace(*expr); expr++, i++)
        s[i] = *expr;
	s[i] = '\0';

	if (s[0]=='-' && (isdigit(s[1]) || s[1]=='.'))
		typ = operand;
	else if (s[0]=='+' && (isdigit(s[1]) || s[1]=='.'))
		typ = operand;
	else if (s[0]=='.')
		typ = operand;
	else if (isdigit(s[0]))
		typ = operand;
	else
		typ = operator;
	return typ;
}

ElementType EvalPostfix(char *expr)
{
	char s[Max_Expr];
	type tp;
	Stack S = CreateStack();
	ElementType X, v1, v2, v;

	while (*expr) {
		tp = GetOperandOrOperator(expr, s);
		expr += strlen(s);
		if (*expr) expr += 1;
		if (tp == operand) {
			X = atof(s);
			Push(S, X);
		} else {
			v2 = Pop(S); v1 = Pop(S);
			if (v2 == err || v1 == err)
				return Infinity;
			switch (s[0]) {
			case '+':
				v = v1 + v2;
				Push(S, v);
				break;
			case '-':
				v = v1 - v2;
				Push(S, v);
				break;
			case '*':
				v = v1 * v2;
				Push(S, v);
				break;
			case '/':
				if (v2 == 0.0f) return Infinity;
				v = v1 / v2;
				Push(S, v);
				break;
			}
		}
	}
	v  = Pop(S);
	if (S->Top != -1) return Infinity;
	else return v;
}

