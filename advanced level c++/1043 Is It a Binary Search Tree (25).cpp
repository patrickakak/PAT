#include <iostream>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void postOrder(int prel, int prer) {
	if (prel > prer) return ;
	int i = prel + 1, j = prer;
	if (!isMirror) {
		while (i <= prer && pre[prel] > pre[i]) i++;
		while (j > prel && pre[prel] <= pre[j]) j--;
	} else {
		while (i <= prer && pre[prel] <= pre[i]) i++;
		while (j > prel && pre[prel] > pre[j]) j--;
	}
	if (i-j != 1) return ;
	postOrder(prel+1, j);
	postOrder(i, prer);
	post.push_back(pre[prel]);
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	postOrder(0, n - 1);
	if (post.size() != n) {
		isMirror = true;
		post.clear();
		postOrder(0, n-1);
	}
	if (post.size() == n) {
		printf("YES\n%d", post[0]);
		for (int i = 1; i < n; i++) printf(" %d", post[i]);
	} else printf("NO");
	return 0;
}
