#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int father[10010];
int find(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA != faB) father[faA] = faB;
}
int main() {
	for (int i = 1; i <= 10000; i++) father[i] = i;
	int n, k, q, a, b, maxn = -1;
	cin >> n;
	unordered_set<int> s1, s2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		vector<int> v(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &v[j]);
			s1.insert(v[j]);
			maxn = max(maxn, v[j]);
		}
		for (int j = 0; j < k-1; j++)
			Union(v[j], v[j+1]);
	}
	for (int i = 1; i <= maxn; i++)
		s2.insert(find(i));
	printf("%d %d\n", s1.size(), s2.size());
	cin >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		printf("%s\n", find(a) == find(b) ? "Y" : "N");
	}
	return 0;
}
