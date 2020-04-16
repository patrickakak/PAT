#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int idx, v;
};
vector<node> lev;
vector<int> in, pre;
void preOrder(int idx, int prel, int prer, int inl, int inr) {
	if (inl > inr) return;
	lev.push_back({idx, pre[prel]});
	int i = inl;
	while (i <= inr && in[i] != pre[prel]) i++;
	preOrder(idx*2, prel+(i-inl)+1, prer, i+1, inr);
	preOrder(idx*2+1, prel+1, prel+(i-inl), inl, i-1);
}
bool cmp(node &a, node &b) {
	return a.idx < b.idx;
}
int main() {
	int n;
	cin >> n;
	in.resize(n), pre.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	preOrder(1, 0, n-1, 0, n-1);
	sort(lev.begin(), lev.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", lev[i].v);
	}
	return 0;
}
