/**
 * Sample input1:
 * 10
 * 3 1 2 8 7 5 9 4 6 0
 * 1 2 3 7 8 5 9 4 6 0
 * Sample output1:
 * Insertion Sort
 * 1 2 3 5 7 8 9 4 6 0
 * --------------------
 * Sample input2:
 * 10
 * 3 1 2 8 7 5 9 4 6 0
 * 6 4 5 1 0 3 2 7 8 9
 * Sample output2:
 * Heap Sort
 * 5 4 3 1 0 2 6 7 8 9
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 111;
int origin[N], tmpOri[N], changed[N];
int n;

bool isSame(int A[], int B[])
{
	for (int i = 1; i <= n; i++)
		if (A[i] != B[i]) return false;
	return true;
}

void show(int A[])
{
	for (int i = 1; i <= n; i++) {
		printf("%d", A[i]);
		if (i < n) printf(" ");
	}
	printf("\n");
}

bool insertSort()
{
	bool flag = false;
	for (int i = 2; i <= n; i++) {
		if (i != 2 && isSame(tmpOri, changed))
			flag = true;
		sort(tmpOri, tmpOri + i + 1);
		if (flag == true) return true;
	}
	return false;
}

void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while (j <= high) {
		if (j+1 <= high && tmpOri[j+1] > tmpOri[j])
			j++;
		if (tmpOri[j] > tmpOri[i]) {
			swap(tmpOri[j], tmpOri[i]);
			i = j;
			j = i * 2;
		} else
			break;
	}
}

void heapSort()
{
	bool flag = false;
	for (int i = n/2; i >= 1; i--)
		downAdjust(i, n);
	for (int i = n; i > 1; i--) {
		if (i != n && isSame(tmpOri, changed))
			flag = true;
		swap(tmpOri[i], tmpOri[1]);
		downAdjust(1, i-1);
		if (flag == true) return ;
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &origin[i]);
		tmpOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &changed[i]);
	if (insertSort())
		printf("Insertion Sort\n");
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++)
			tmpOri[i] = origin[i];
		heapSort();
	}
	show(tmpOri);

	return 0;
}


