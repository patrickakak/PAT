/* Sample Input:
 * 6
 * Push 1
 * Push 2
 * Push 3
 * Pop
 * Pop
 * Push 4
 * Pop
 * Pop
 * Push 5
 * Push 6
 * Pop
 * Pop
 * Sample Output:
 * 3 4 2 6 5 1
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 30
typedef int ElemType;
struct Cell {
	ElemType Elem;
	int Nv; 	/* Number of visitation */
};
typedef struct Cell DataType;
typedef struct SNode *PtrToSNode;
struct SNode {
	int Top;
	DataType *pData;
};
typedef PtrToSNode Stack;

Stack CreatS(int Size);
void DestroyS(Stack S);
bool IsEmptyS(Stack S);
bool IsFullS(Stack S);
bool Push(Stack S, DataType item);
DataType Pop(Stack S);

int main()
{
	int N, i, flag=0; 	/* flag to control output format */
	char Op[5]; 	/* Operation of stack */
	DataType x, t;
	Stack S;

	scanf("%d", &N);
	if (!N) return 0;

	S = CreatS(MAXSIZE);
	for (i = 0; i < 2*N; i++) {
		scanf("%s", Op);
		if (!strcmp(Op, "Push")) {
			scanf("%d", &x.Elem);
			x.Nv = 1;
			Push(S, x);
		} else 	/* Either Push or Pop */
			/* Increase the visitation times of stack top element by one 
			 * in a loop, if it has been visited three times, then just 
			 * pop it out (it will be in postorder naturally) */
			while (!IsEmptyS(S) && ++S->pData[S->Top].Nv==3) {
				t = Pop(S);
				if (!flag) flag = 1; else putchar(' ');
				printf("%d", t.Elem);
			}
	}
	while (!IsEmptyS(S)) { 	/* Pop out those remaining elements */
		t = Pop(S);
		if (!flag) flag = 1; else putchar(' ');
		printf("%d", t.Elem);
	}
	DestroyS(S);
	putchar('\n');
	return 0;
}

Stack CreatS(int Size)
{
	Stack S = (Stack) malloc(sizeof(struct SNode));
	S->pData = (DataType *) malloc(Size * sizeof(DataType));
	S->Top = -1;
	return S;
}

void DestroyS(Stack S)
{
	free(S->pData);
	free(S);
}

bool IsEmptyS(Stack S)
{
	return S->Top == -1;
}

bool IsFullS(Stack S)
{
	return S->Top+1 == MAXSIZE;
}

bool Push(Stack S, DataType item)
{
	if (IsFullS(S)) return false;
	S->pData[++S->Top] = item;
	return true;
}

DataType Pop(Stack S)
{
	DataType ERROR;
	ERROR.Elem = ERROR.Nv = -1;
	if (IsEmptyS(S)) return ERROR;
	else return S->pData[S->Top--];
}

