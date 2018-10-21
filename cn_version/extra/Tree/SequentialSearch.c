typedef struct LNode *List;
struct LNode {
	ElementType Element[MAXSIZE];
	int Length;
};

/* With a sentinel
 * If i == 0, you find it! */
int SequentialSearch(List Tbl, int K)
{
	int i;

	Tbl->Element[0] = K:
	for (i = Tbl->Length; Tbl->Element[i] != K; i--) ;
	return i;
}

/* Without a sentinel */
int SequentialSearch(List Tbl, int K)
{
	int i;

	for (i = Tbl->Length; i > 0 && Tbl->Element[i] != K; i--) ;
	return i;
}

