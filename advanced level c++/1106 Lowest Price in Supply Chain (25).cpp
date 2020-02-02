#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100000], d(100000);
int dmin = 0x3fffffff;
void dfs(int index, int depth) {
	if (v[index].size() == 0) {
		d[depth]++;
		if (dmin > depth) dmin = depth;
		return ;
	}
	for (int i = 0; i < v[index].size(); i++)
		dfs(v[index][i], depth + 1);
}
int main() {
	int n, k, t;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			v[i].push_back(t);
		}
	}
	dfs(0, 0);
	printf("%.4f %d", p * pow(1 + r/100, dmin), d[dmin]);
	return 0;
}
