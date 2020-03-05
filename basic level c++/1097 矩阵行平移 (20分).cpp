#include <iostream>
#include <vector>
using namespace std;
int m[110][110], m2[110][110];
vector<int> ans;
int main() {
	int n, k, x, cnt = 1;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &m[i][j]);
	for (int i = 1; i <= n; i++)
		if (i % 2 == 1) {
			int j;
			for (j = 1; j <= cnt; j++) m2[i][j] = x;
			for (; j <= n; j++) m2[i][j] = m[i][j-cnt];
			if (cnt == k) cnt = 1;
			else cnt++;
		} else
			for (int j = 1; j <= n; j++) m2[i][j] = m[i][j];
	for (int j = 1; j <= n; j++) {
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += m2[i][j];
		ans.push_back(sum);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
