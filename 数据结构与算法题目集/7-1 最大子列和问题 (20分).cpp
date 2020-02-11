#include <iostream>
using namespace std;
int a[100000];
int MaxSubseqSum(int A[], int K) {
	int ThisSum = 0, MaxSum = 0;
	for (int i = 0; i < K; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) MaxSum = ThisSum;
		else if (ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	printf("%d\n", MaxSubseqSum(a, k));
	return 0;
}
