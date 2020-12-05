#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	double amt;
	vector<int> child;
};
vector<node> v;
double p, r, ans = 0;
void dfs(int idx, int depth) {
	if (v[idx].child.size() == 0) {
		ans += v[idx].amt * pow(1 + r, depth);
		return ;
	}
	for (int i = 0; i < v[idx].child.size(); i++)
		dfs(v[idx].child[i], depth + 1);
}
int main() {
	int n, k, c;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) scanf("%lf", &v[i].amt);
		else
			for (int j = 0; j < k; j++) {
				scanf("%d", &c);
				v[i].child.push_back(c);
			}
	}
	dfs(0, 0);
	printf("%.1f", ans * p);
	return 0;
}
