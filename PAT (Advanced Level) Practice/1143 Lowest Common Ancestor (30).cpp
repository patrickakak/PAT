#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int m, n, u, v, a;
	scanf("%d %d", &m, &n);
	vector<int> pre(n);
	unordered_map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		mp[pre[i]] = true;
	}
	while (m--) {
		scanf("%d %d", &u, &v);
		for (int j = 0; j < n; j++) {
			a = pre[j];
			if ((a >= u && a <= v) || (a >= v && a <= u)) break;
		} 
		if (mp[u] == false && mp[v] == false) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (mp[u] == false || mp[v] == false) printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
		else if (a == u || a == v) printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}
