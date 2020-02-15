#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node { int v1, v2, w; };
vector<node> edge;
int n, m, father[1010];
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
bool cmp(node &a, node &b) { return a.w < b.w; }
int main() {
	for (int i = 0; i < 1010; i++) father[i] = i;
	cin >> n >> m;
	int a, b, w, totwt = 0, ecnt = 0;
	while (m--) {
		cin >> a >> b >> w;
		edge.push_back(node{a, b, w});
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < edge.size(); i++)
		if (find(edge[i].v1) != find(edge[i].v2)) {
			Union(edge[i].v1, edge[i].v2);
			totwt += edge[i].w;
			ecnt++;
		}
	if (ecnt != n-1) printf("-1");
	else printf("%d", totwt);
	return 0;
}
