/* Sample Input:
 * 5 7 5
 * 1 2 3 4 5 6 7
 * 3 2 1 7 5 6 4
 * 7 6 5 4 3 2 1
 * 5 6 4 3 7 2 1
 * 1 7 6 5 4 3 2
 * --------------
 * Sample Output:
 * YES
 * NO
 * NO
 * YES
 * NO
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
#define YES 1
#define NO 0
typedef int ItemType;
typedef struct SNode *PtrToSNode;
struct SNode {
	int Top, Max;
	ItemType *pData;
};
typedef PtrToSNode Stack;

Stack CreatS(int MaxSize);
bool IsFullS(Stack S);
bool IsEmptyS(Stack S);
bool Push(Stack S, ItemType item);
ItemType Pop(Stack S);
void DestroyS(Stack S);
int Judge(Stack S, int N);
ItemType Max2(ItemType a, ItemType b);
int CntS(Stack S);
void MakeEmpty(Stack S);

int main()
{
	Stack S;
	int M, N, K, i; 	/* M: max capacity of stack; N: length; K: lines */

	scanf("%d %d %d", &M, &N, &K);
	S = CreatS(M);
	for (i = 0; i < K; i++)
		if (Judge(S, N) == YES) printf("YES\n");
		else printf("NO\n");
	DestroyS(S);
	return 0;
}

int Judge(Stack S, int N)
{
	int i, j, flag=0; 	/* flag to indicate whether it's a wrong sequence*/
	ItemType x, max=0, last=0; 	/* last and max to store last element 
								   and the biggest one so far respectively */

	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		if (flag || (x-max > S->Max)) {
			flag = 1;
			continue;
		}
		/* x>last or x<last */
		if (x > last) {
			if (x-max+CntS(S) > S->Max) {
				flag = 1;
				continue;
			}
			if (x > max)
				for (j=max+1; j<x; j++)
					Push(S, j);
		} else
			if (Pop(S) != x) {
				flag = 1;
				continue;
			}
		last = x; max = Max2(max, x);
	}
	MakeEmpty(S); 	/* Don't forget to reset stack */
	if (flag) return 0; else return 1;
}

int CntS(Stack S)
{
	return S->Top+1;
}

ItemType Max2(ItemType a, ItemType b)
{
	return a > b ? a : b;
}

Stack CreatS(int MaxSize)
{
	Stack S;
	S = (Stack) malloc(sizeof(struct SNode));
	S->pData = (ItemType *) malloc(MaxSize*sizeof(ItemType));
	S->Top = -1;
	S->Max = MaxSize;
	return S;
}

void DestroyS(Stack S)
{
	free(S->pData);
	free(S);
}

bool IsFullS(Stack S)
{
	return (S->Top+1 == S->Max);
}

bool IsEmptyS(Stack S)
{
	return (S->Top == -1);
}

bool Push(Stack S, ItemType item)
{
	if (IsFullS(S)) return false;
	S->pData[++S->Top] = item;
	return true;
}

ItemType Pop(Stack S)
{
	if (IsEmptyS(S)) return ERROR;
	return S->pData[S->Top--];
}

void MakeEmpty(Stack S)
{
	S->Top = -1;
}

