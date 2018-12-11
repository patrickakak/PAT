/**
 * Find the Kth largest number in an array S[]
 */

void Swap(ElementType *X, ElementType *Y)
{
	ElementType tmp;

	tmp = *X; *X = *Y; *Y = tmp;
}

/* Find Kth in S[Left]~S[Right]: (0 < K <= Right-Left+1) */
ElementType FindKthLargest(ElementType S[], int K, int Left, int Right)
{
	ElementType e = S[Left];
	int L = Left, R = Right;

	while (1) {
		while (Left <= Right && e <= S[Left])
			Left++;
		while (Left < Right && e > S[Right])
			Right--;
		if (Left < Right)
			Swap(&S[Left], &S[Right]);
		else
			break;
	}
	Swap(&S[Left-1], &S[L]);
	if (Left-L-1 >= K)
		return FindKthLargest(S, K, L, Left-2);
	else if (Left-L-1 < K-1)
		return FindKthLargest(S, K-(Left-L-1)-1, Left, R);
	else
		return e;
}

ElementType Median(ElementType S[], int N)
{
	return FindKthLargest(S, (N+1)/2, 0, N-1);
}

