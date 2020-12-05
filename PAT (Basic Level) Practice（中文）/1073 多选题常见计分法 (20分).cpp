#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, num, maxn = -1, wt[] = {1,2,4,8,16};
	char ch;
	cin >> n >> m;
	vector<double> full(m);
	vector<int> totOpt(m), rightOpt(m), rightWt(m);
	for (int i = 0; i < m; i++) {
		scanf("%lf%d%d", &full[i], &totOpt[i], &rightOpt[i]);
		for (int j = 0; j < rightOpt[i]; j++) {
			cin >> ch;
			rightWt[i] += wt[ch-'a'];
		}
	}
	vector<vector<int>> stu(n, vector<int>(m)), cnt(m, vector<int>(5));
	for (int i = 0; i < n; i++) {
		double totScore = 0;
		for (int j = 0; j < m; j++) {
			cin.get();
			scanf("(%d", &num);
			for (int k = 0; k < num; k++) {
				cin >> ch;
				stu[i][j] += wt[ch-'a'];
			}
			scanf(")");
			int e = stu[i][j] ^ rightWt[j];
			if (e == 0) totScore += full[j];
			else {
				if ((e | rightWt[j]) == rightWt[j]) totScore += full[j]/2;
				for (int k = 0; k < totOpt[j]; k++)
					if (e & wt[k]) cnt[j][k]++;
			}
		}
		printf("%.1f\n", totScore);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < totOpt[i]; j++)
			maxn = max(maxn, cnt[i][j]);
	if (maxn == 0) printf("Too simple\n");
	else
		for (int i = 0; i < m; i++)
			for (int j = 0; j < totOpt[i]; j++)
				if (cnt[i][j] == maxn) printf("%d %d-%c\n", maxn, i+1, j+'a');
	return 0;
}
