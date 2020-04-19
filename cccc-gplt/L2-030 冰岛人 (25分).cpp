#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
struct node {
	string f, l;
};
vector<node> nm(100010);
int sex[100010], father[100010], vis[100010];
unordered_map<string, int> getid;
bool f(int a, int b) {
	fill(vis, vis+100010, 0);
	unordered_set<int> s;
	for (int p=a, cnt=1; p != -1; p=father[p], cnt++) {
		vis[p] = 1;
		if (cnt < 5) s.insert(p);
	}
	for (int p=b, cnt=1; p != -1; p=father[p], cnt++) {
		if (vis[p] && cnt < 5) return false;
		if (s.count(p)) return false;
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
		getid[nm[i].f] = i;
	}
	for (int i = 1; i <= n; i++) {
		string lst = nm[i].l;
		int len = lst.length();
		if (lst[len-1] == 'n') father[i] = getid[lst.substr(0, len-4)];
		else if (lst[len-1] == 'r') father[i] = getid[lst.substr(0, len-7)];
	}
	cin >> m;
	string a, b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		if (getid[a] == 0 || getid[c] == 0) printf("NA\n");
		else {
			int id1 = getid[a], id2 = getid[c];
			if (sex[id1] == sex[id2]) printf("Whatever\n");
			else printf("%s\n", f(id1, id2) == true ? "Yes" : "No");
		}
	}
	return 0;
}
