void MySort(ElementType A[], int N) {
	int u = 0, v = 0, w = 0;
	for (int i = 0; i < N; i++)
		switch (A[i]) {
		case true : u++; break;
		case false: v++; break;
		case maybe: w++; break;
		}
	for (int i = 0; i < v; i++) A[i] = false;
	for (int i = 0; i < w; i++) A[i+v] = maybe;
	for (int i = 0; i < u; i++) A[i+v+w] = true;
}
