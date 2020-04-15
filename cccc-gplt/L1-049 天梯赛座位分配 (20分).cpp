#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> m(n+1), cnt(n+1), v[110];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m[i]);
		cnt[i] = m[i] * 10;
	}
	int idx = 0, sch = n;
	while (sch)
		for (int i = 1; i <= n; i++) {
			if (cnt[i]-- > 0) idx++;
			if (cnt[i] >= 0) v[i].push_back(idx);
			if (i == n && sch == 1) idx++;
			if (cnt[i] == 0) sch--;
		}
	for (int i = 1; i <= n; i++) {
		printf("#%d\n", i);
		for (int j = 0; j < v[i].size(); j++) {
			if (j%10 != 0) printf(" ");
			printf("%d", v[i][j]);
			if ((j+1)%10 == 0) printf("\n");
		}
	}
	return 0;
}
