/**
 * Sample input:
 * 10 1.80 1.00
 * 3 2 3 5
 * 1 9
 * 1 4
 * 1 7
 * 0 7
 * 2 6 1
 * 1 8
 * 0 9
 * 0 4
 * 0 3
 * --------------
 * Sample output:
 * 42.4
 */
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
struct Node {
	double data;
	vector<int> child;
} node[maxn];
int n;
double p, r, ans = 0;

void DFS(int index, int depth)
{
	if (node[index].child.size() == 0) {
		ans += node[index].data * pow(1+r, depth);
		return;
	}
	for (int i = 0; i < node[index].child.size(); i++)
		DFS(node[index].child[i], depth+1);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int k, child;

	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0)
			scanf("%lf", &node[i].data);
		else
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
	}
	DFS(0, 0);
	printf("%.1f\n", p * ans);

	return 0;
}



