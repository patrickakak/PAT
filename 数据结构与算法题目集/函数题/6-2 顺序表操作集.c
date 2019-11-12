/**
 * Sample Input:
 * 6
 * 1 2 3 4 5 6
 * 3
 * 6 5 1
 * 2
 * -1 6
 * ----------------------------------
 * Sample Output:
 * FULL Insertion Error: 6 is not in.
 * Finding Error: 6 is not in.
 * 5 is at position 0.
 * 1 is at position 4.
 * POSITION -1 EMPTY Deletion Error.
 * FULL Insertion Error: 0 is not in.
 * POSITION 6 EMPTY Deletion Error.
 * FULL Insertion Error: 0 is not in.
 */

List MakeEmpty()
{
	List L;

	L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

Position Find(List L, ElementType X)
{
	Position Pos = 0;

	if (L->Last == -1) return ERROR;

	while (Pos<=L->Last && L->Data[Pos]!=X)
		Pos++;

	if (Pos > L->Last) return ERROR;
	else return Pos;
}

bool Insert(List L, ElementType X, Position P)
{
	int i;

	if (L->Last == MAXSIZE-1) {
		printf("FULL");
		return false;
	}
	if (P < 0 || P > L->Last+1) {
		printf("ILLEGAL POSITION");
		return false;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i];
	L->Data[P] = X;
	L->Last++;
	return true;
}

bool Delete(List L, Position P)
{
	int i;

	if (P < 0 || P > L->Last) {
		printf("POSITION %d EMPTY", P);
		return false;
	}

	for (i = P; i <= L->Last-1; i++)
		L->Data[i] = L->Data[i+1];
	L->Last--;
	return true;
}

