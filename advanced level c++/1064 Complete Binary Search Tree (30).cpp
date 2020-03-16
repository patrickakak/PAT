#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt = 0;
vector<int> in, cbt;
void inOrder(int idx) {
	if (idx >= n) return;
	inOrder(2 * idx + 1);
	cbt[idx] = in[cnt++];
	inOrder(2 * idx + 2);
}
int main() {
	cin >> n;
	in.resize(n), cbt.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	inOrder(0);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", cbt[i]);
	}
	return 0;
}
