#include <iostream>
#include <queue>
using namespace std;
struct node {
	char c;
	int f;
	node *l, *r;
};
struct cmp {
	bool operator () (node *&a, node *&b) {
		return a->f > b->f;
	}
};
node *make(char c, int f, node *l, node *r) {
	node *t = new node();
	*t = node{c, f, l, r};
	return t;
}
int n, m, f[80];
char c[80];
priority_queue<node*, vector<node*>, cmp> q;
node *huffman() {
	for (int i = 0; i < n-1; i++) {
		node *l = q.top(); q.pop();
		node *r = q.top(); q.pop();
		node *root = make('x', l->f + r->f, l, r);
		q.push(root);
	}
	return q.top();
}
int getwpl(node *root, int depth) {
	if (root == NULL) return 0;
	if (root->l == NULL && root->r == NULL) return depth * root->f;
	return getwpl(root->l, depth + 1) + getwpl(root->r, depth + 1);
}
bool judge(int wpl) {
	char ch;
	string code;
	int flag = 0;
	node *t = make('x', 0, NULL, NULL);
	for (int i = 1; i <= n; i++) {
		cin >> ch >> code;
		if (code.length() >= n || flag == 1 || ch != c[i]) {
			flag = 1; continue;
		}
		int w = f[i];
		node *pt = t;
		for (int j = 0; j < code.length(); j++) {
			switch (code[j]) {
			case '0':
				if (!pt->l) pt->l = make('x', 0, NULL, NULL);
				else if (pt->l->f != 0) goto END;
				pt = pt->l;
				break;
			case '1':
				if (!pt->r) pt->r = make('x', 0, NULL, NULL);
				else if (pt->r->f != 0) goto END;
				pt = pt->r;
				break;
			}
		}
END:
		if (!pt->l && !pt->r) pt->f = w;
		else flag = 1;
	}
	bool ret;
	if (!flag && wpl == getwpl(t, 0)) ret = true;
	else ret = false;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> f[i];
		node *t = make(c[i], f[i], NULL, NULL);
		q.push(t);
	}
	node *root = huffman();
	int wpl = getwpl(root, 0);
	cin >> m;
	while (m--)
		if (judge(wpl)) printf("Yes\n");
		else printf("No\n");
	return 0;
}
