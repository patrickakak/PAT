double f(int n, double a[], double x) {
	double p = a[n];
	for (int i = n; i > 0; i--)
		p = a[i-1] + p * x;
	return p;
}
