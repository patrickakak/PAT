#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct node {
	int val, flg;
	vector<int> pupil;
};
vector<node> v(100010);
double z, r, sum = 0;
void dfs(int u, int depth) {
	if (v[u].flg == 1)
		sum += v[u].val * pow(1-r/100, depth);
	for (int i = 0; i < v[u].pupil.size(); i++)
		dfs(v[u].pupil[i], depth+1);
}
int main() {
	int n, k, tmp;
	cin >> n >> z >> r;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &tmp);
			v[i] = {tmp, 1};
		} else
			for (int j = 0; j < k; j++) {
				scanf("%d", &tmp);
				v[i].pupil.push_back(tmp);
			}
	}
	dfs(0, 0);
	printf("%d\n", (int)(sum*z));
	return 0;
}
