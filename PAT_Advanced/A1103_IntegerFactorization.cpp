/**
 * Sample input1:
 * 169 5 2
 * Sample output1:
 * 169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
 * ---------------------------------
 * Sample input2:
 * 169 167 3
 * Sample output2:
 * Impossible
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, ans, tmp;

int power(int x)
{
	int ans = 1;
	for (int i = 0; i < p; i++)
		ans *= x;
	return ans;
}

void init()
{
	int i = 0, tmp = 0;
	while (tmp <= n) {
		fac.push_back(tmp);
		tmp = power(++i);
	}
}

void DFS(int index, int nowK, int sum, int facSum)
{
	if (sum == n && nowK == k) {
		if (facSum > maxFacSum) {
			ans = tmp;
			maxFacSum=facSum;
		}
		return;
	}
	if (sum > n || nowK > k) return;
	if (index-1 >= 0) {
		tmp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		tmp.pop_back();
		DFS(index-1, nowK, sum, facSum);
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size()-1, 0, 0, 0);
	if (maxFacSum == -1) printf("Impossible\n");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < (int)ans.size(); i++)
			printf(" + %d^%d", ans[i], p);
	}

	return 0;
}


