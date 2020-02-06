#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int find(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA != faB) father[faA] = faB;
}
int main() {
	int n, k, t, cnt = 0;
	int hobby[1001] = {0};
	scanf("%d", &n);
	father.resize(n + 1), isRoot.resize(n + 1);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			if (hobby[t] == 0) hobby[t] = i;
			Union(i, hobby[t]);
		}
	}
	for (int i = 1; i <= n; i++) isRoot[find(i)]++;
	for (int i = 1; i <= n; i++)
		if (isRoot[i] != 0) cnt++;
	printf("%d\n", cnt);
	sort(isRoot.rbegin(), isRoot.rend());
	for (int i = 0; i < cnt; i++) {
		if (i != 0) printf(" ");
		printf("%d", isRoot[i]);
	}
	return 0;
}
