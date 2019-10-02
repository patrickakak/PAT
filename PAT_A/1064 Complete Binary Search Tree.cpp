/**
 * Sample input:
 * 10
 * 1 2 3 4 5 6 7 8 9 0
 * --------------------
 * Sample output:
 * 6 3 8 1 5 7 9 0 2 4
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int n, number[maxn], CBT[maxn], index = 0;
void inOrder(int root)
{
	if (root > n) return;
	inOrder(root * 2);
	CBT[root] = number[index++];
	inOrder(root*2 + 1);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);
	sort(number, number+n);
	inOrder(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", CBT[i]);
		if (i < n) printf(" ");
	}

	return 0;
}



