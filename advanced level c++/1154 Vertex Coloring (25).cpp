#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node { int t1, t2; };
int main() {
	int n, m, k;
	cin >> n >> m;
	vector<node> v(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &v[i].t1, &v[i].t2);
	cin >> k;
	while (k--) {
		vector<int> a(n);
		bool flag = true;
		set<int> s;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s.insert(a[i]);
		}
		for (int i = 0; i < m; i++)
			if (a[v[i].t1] == a[v[i].t2]) {
				flag = false;
				break;
			}
		if (flag) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}
