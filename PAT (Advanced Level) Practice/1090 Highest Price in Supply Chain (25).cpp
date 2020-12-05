#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	vector<int> child;
};
int dmax = 0;
vector<int> d(100000);
vector<node> v;
void dfs(int index, int depth) {
	if (v[index].child.size() == 0) {
		if (depth > dmax) dmax = depth;
		d[depth]++;
		return ;
	}
	for (int i = 0; i < v[index].child.size(); i++)
		dfs(v[index].child[i], depth + 1);
}
int main() {
	int n, t, root;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t == -1) root = i;
		else v[t].child.push_back(i);
	}
	dfs(root, 0);
	printf("%.2f %d", p * pow(1 + r/100, dmax), d[dmax]);
	return 0;
}
