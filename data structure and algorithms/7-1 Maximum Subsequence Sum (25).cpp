#include <iostream>
using namespace std;
typedef struct OutNode *PtrToOutNode;
struct OutNode {
	int first, last, MaxSum;
};
int a[100000];
PtrToOutNode MaxSubseqSum4(int A[], int N) {
	int ThisSum = 0, MaxSum = -1, Diff = 0;
	PtrToOutNode out = new struct OutNode;
	out->first = out->last = out->MaxSum = 0;
	for (int i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			out->last = i;
			out->first = out->last - Diff;
			Diff++;
		} else if (ThisSum < 0) {
			ThisSum = 0, Diff = 0;
		} else Diff++;
	}
	out->MaxSum = MaxSum;
	return out;
}
int main() {
	int K;
	PtrToOutNode out;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) scanf("%d", &a[i]);
	out = MaxSubseqSum4(a, K);
	if (out->MaxSum >= 0) printf("%d %d %d\n", out->MaxSum, a[out->first], a[out->last]);
	else printf("%d %d %d\n", 0, a[0], a[K-1]);
	return 0;
}
