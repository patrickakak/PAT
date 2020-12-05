#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father(10010), visit(10010);
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
	int n, k, bid, t, q, a, b;
	cin >> n;
	for (int i = 0; i < 10010; i++) father[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &k, &bid);
		visit[bid] = 1;
		for (int j = 1; j < k; j++) {
			scanf("%d", &t);
			visit[t] = 1;
			Union(bid, t);
		}
	}
	int treeCnt = 0, birdCnt = 0;
	for (int i = 0; i < 10010; i++) {
		if (visit[i] == 1) birdCnt++;
		if (visit[i] && father[i] == i) treeCnt++;
	}
	printf("%d %d\n", treeCnt, birdCnt);
	cin >> q;
	while (q--) {
		scanf("%d%d", &a, &b);
		if (find(a) == find(b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
