#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
struct node {
	string f, l;
};
vector<node> nm(100010);
int sex[100010], father[100010];
unordered_map<string, int> id;
bool vis[100010];
bool f(int id1, int id2) {
	fill(vis, vis+100010, false);
	unordered_set<int> s1, s2;
	int cnt = 1, k = id1;
	while (k != -1) {
		vis[k] = true;
		if (cnt < 5) s1.insert(k);
		if (k == id2) return false;
		k = father[k];
		cnt++;
	}
	k = id2, cnt = 1;
	while (k != -1) {
		if (cnt < 5) s2.insert(k);
		if (vis[k]) {
			if (s1.count(k)) return false;
		}
		k = father[k];
		cnt++;
	}
	return true;
}
int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) father[i] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> nm[i].f >> nm[i].l;
		int len = nm[i].l.length();
		if (nm[i].l[len-1] == 'm' || nm[i].l[len-1] == 'n') sex[i] = 1;
		else sex[i] = 0;
		id[nm[i].f] = i;
	}
	for (int i = 1; i <= n; i++) {
		string lst = nm[i].l;
		int len = lst.length();
		if (lst[len-1] == 'n') father[i] = id[lst.substr(0, len-4)];
		else if (lst[len-1] == 'r') father[i] = id[lst.substr(0, len-7)];
	}
	cin >> m;
	string a, b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		if (id[a] == 0 || id[c] == 0) printf("NA\n");
		else {
			int id1 = id[a], id2 = id[c];
			if (sex[id1] == sex[id2]) printf("Whatever\n");
			else printf("%s\n", f(id1, id2) == true ? "Yes" : "No");
		}
	}
	return 0;
}
