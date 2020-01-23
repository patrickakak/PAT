#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, sum = 0, left, right, cnt, tmp;
	scanf("%d", &n);
	vector<int> dis(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		sum += tmp;
		dis[i] = sum;
	}
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d %d", &left, &right);
		if (left > right) swap(left, right);
		tmp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(tmp, sum - tmp));
	}
	return 0;
}
