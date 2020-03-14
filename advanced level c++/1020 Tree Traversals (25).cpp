#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int index, val;
};
bool cmp(node &a, node &b) {
	return a.index < b.index;
}
vector<int> post, in;
vector<node> ans;
void pre(int inl, int inr, int postl, int postr, int idx) {
	if (inl > inr) return;
	int i = inl;
	while (i <= inr && in[i] != post[postr]) i++;
	ans.push_back({idx, post[postr]});
	pre(inl, i-1, postl, postl+(i-inl)-1, 2*idx+1);
	pre(i+1, inr, postl+(i-inl), postr-1, 2*idx+2);
}
int main() {
	int n;
	scanf("%d", &n);
	post.resize(n); in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre(0, n-1, 0, n-1, 0);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i].val);
	}
	return 0;
}
