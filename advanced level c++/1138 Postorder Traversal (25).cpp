#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int root, int start, int end) {
	if (start > end || flag == true) return;
	int i = start;
	while (i <= end && in[i] != pre[root]) i++;
	postOrder(root + 1, start, i - 1);
	postOrder(root + i - start + 1, i + 1, end);
	if (flag == false) {
		printf("%d", pre[root]);
		flag = true;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	postOrder(0, 0, n - 1);
	return 0;
}
