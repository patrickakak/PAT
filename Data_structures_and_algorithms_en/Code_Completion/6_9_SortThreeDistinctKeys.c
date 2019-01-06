/**
 * Sample Input:
 * 6
 * 2 2 0 1 0 0
 * ------------------
 * Sample Output:
 * false in A[0]-A[0]
 * maybe in A[1]-A[2]
 * true in A[3]-A[5]
 */
void MySort(ElementType A[], int N)
{
	int i, u, v, w;

	u = v = w = 0;
	for (i = 0; i < N; i++)
		switch (A[i]) {
		case true : u++; break;
		case false: v++; break;
		case maybe: w++; break;
		}

	for (i = 0; i < v; i++)
		A[i] = false;
	for (i = 0; i < w; i++)
		A[i+v] = maybe;
	for (i = 0; i < u; i++)
		A[i+v+w] = true;
}

