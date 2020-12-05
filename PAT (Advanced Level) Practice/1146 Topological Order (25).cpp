#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, a, b, k;
	vector<int> v[1010], in(1010), ans;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int flag = 1;
		vector<int> tin = in;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			if (tin[a] != 0) flag = 0;
			for (int it : v[a]) tin[it]--;
		}
		if (flag == 0) ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
