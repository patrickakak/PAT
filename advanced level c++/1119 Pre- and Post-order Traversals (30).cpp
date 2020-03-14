#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in, post;
bool isunique = true;
void inOrder(int prel, int prer, int postl, int postr) {
	if (prel > prer) return;
	int i = prel+1;
	while (i <= prer && pre[i] != post[postr-1]) i++;
	if (prer > prel && i-prel < 2) isunique = false;
	inOrder(prel+1, i-1, postl, postl+(i-prel-1)-1);
	in.push_back(pre[prel]);
	inOrder(i, prer, postl+(i-prel-1), postr-1);
}
int main() {
	int n;
	cin >> n;
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	inOrder(0, n-1, 0, n-1);
	printf("%s\n", isunique ? "Yes" : "No");
	for (int i = 0; i < in.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");
	return 0;
}
