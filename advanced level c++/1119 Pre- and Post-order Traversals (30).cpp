#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preL, int preR, int postLeft, int postRight) {
	if (preL == preR) {
		in.push_back(pre[preL]);
		return;
	}
	if (pre[preL] == post[postRight]) {
		int i = preL + 1;
		while (i <= preR && pre[i] != post[postRight-1]) i++;
		if (i - preL > 1) getIn(preL + 1, i - 1, postLeft, postLeft + (i - preL - 1) - 1);
		else unique = false;
		in.push_back(post[postRight]);
		getIn(i, preR, postLeft + (i - preL - 1), postRight - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	getIn(0, n-1, 0, n-1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}
