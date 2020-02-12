#include <iostream>
using namespace std;
struct node {
	string c;
	int l, r;
} t1[15], t2[15];
int n1, n2, h1[15], h2[15];
int build(node t[], int h[], int n) {
	string c, l, r;
	for (int i = 0; i < n; i++) {
		cin >> c >> l >> r;
		t[i].c = c;
		if (l == "-") t[i].l = -1;
		else {
			t[i].l = stoi(l);
			h[stoi(l)] = 1;
		}
		if (r=="-") t[i].r = -1;
		else {
			t[i].r = stoi(r);
			h[stoi(r)] = 1;
		}
	}
	int root = 0;
	while (root < n && h[root] == 1) root++;
	return root;
}
bool isomorphic(int r1, int r2) {
	if (r1 == -1 && r2 == -1) return true;
	if ((r1 != -1 && r2 == -1) || (r1 == -1 && r2 != -1)) return false;
	if (t1[r1].c != t2[r2].c) return false;
	if (t1[r1].l == -1 && t2[r2].l == -1) return isomorphic(t1[r1].r, t2[r2].r);
	if (t1[r1].l != -1 && t2[r2].l != -1 && t1[t1[r1].l].c == t2[t2[r2].l].c)
		return isomorphic(t1[r1].l, t2[r2].l) && isomorphic(t1[r1].r, t2[r2].r);
	else
		return isomorphic(t1[r1].l, t2[r2].r) && isomorphic(t1[r1].r, t2[r2].l);
}
int main() {
	cin >> n1;
	int r1 = build(t1, h1, n1);
	cin >> n2;
	int r2 = build(t2, h2, n2);
	if (n1 != n2) printf("No");
	else if (n1 == 0 && n2 == 0) printf("Yes");
	else {
		if (isomorphic(r1, r2)) printf("Yes");
		else printf("No");
	}
	return 0;
}
