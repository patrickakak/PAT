#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e6

typedef enum { false, true } bool;
typedef struct StackRecord *PtrToStack;
typedef PtrToStack Stack;
struct StackRecord {
	ElementType *PData;
	int          Top;
	int          Max;
};

Stack CreateStack( int MaxElem );
bool Push( Stack S, ElementType X );
ElementType Pop( Stack S );
void MakeEmpty( Stack S );
int StackCellsCnt( Stack S );

int main()
{
	int M, N, K, i, j, Max, Tmp;
	bool flag;	// To indicate whether it's a wrong sequence
	ElementType X;
	Stack S;

	scanf("%d%d%d", &M, &N, &K);
	S = CreateStack(M);

	while (K > 0 && K--) {
		flag = true;
		Max = Tmp = 0;
		for (i = 1; i <= N; i++) {
			scanf("%d", &X);

			// Impossible for M capacity stack
			if (i == 1 && X > M) { flag = false; continue; }

			if (X > Tmp) {
				// To judge if the latter one is qualified
				if (X-Max+StackCellsCnt(S) > M) { flag = false; continue; }
				if (X > Max) {
					for (j = Max+1; j < X; j++)
						Push(S, j);
					Max = X;	// To restore the maximum value of former sequence
				}
			} else {
				if (Pop(S) != X) { flag = false; continue; }
			}
			Tmp = X;	// Restore the last X
		}
		if (flag) puts("YES");
		else puts("NO");
		MakeEmpty(S);	// Make stack empty in case that there's still members inside
	}
	return 0;
}

Stack CreateStack( int MaxElem )
{
	Stack S;

	S = (Stack) malloc(sizeof(struct StackRecord));
	S->PData = (ElementType *) malloc(MaxElem * sizeof(ElementType));
	S->Top = -1;
	S->Max = MaxElem;
	return S;
}

bool Push( Stack S, ElementType X )
{
	if (S->Top == S->Max-1) return false;
	S->PData[++S->Top] = X;
	return true;
}

ElementType Pop( Stack S )
{
	if (S->Top == -1) return ERROR;
	return S->PData[S->Top--];
}

int StackCellsCnt( Stack S )
{
	return S->Top + 1;
}

void MakeEmpty( Stack S )
{
	S->Top = -1;
}

