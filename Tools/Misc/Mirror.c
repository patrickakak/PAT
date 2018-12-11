/* Chirality:
 *
 * Divide N elements into two parts: 0~N-M-1 and N-M~N-1.
 *
 * Elements in the same part, they go through twice mirror change, so 
 * their relative position is unchanged. However, if you see the two 
 * parts as two huge elements, both of them have only mirroed once, so 
 * the order of those two is reversed.
 */
void Swap(ElementType *X, ElementType *Y)
{
	ElementType tmp;

	tmp = *X; *X = *Y; *Y = tmp;
}

void Mirror(ElementType S[], int L, int R)
{
	int i, j;

	for (i=L, j=R; i < j; i++, j--)
		Swap(&S[i], &S[j]);
}

/* M: offset (M<N) */
void RightShift(ElementType S[], int N, int M)
{
	Mirror(S, 0, N-M-1);
	Mirror(S, N-M, N-1);
	Mirror(S, 0, N-1);
}

/* M: offset (M<N) */
void LeftShift(ElementType S[], int N, int M)
{
	Mirror(S, 0, M-1);
	Mirror(S, M, N-1);
	Mirror(S, 0, N-1);
}

