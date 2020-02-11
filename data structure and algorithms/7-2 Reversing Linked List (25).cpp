#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int first, n, k, addr, cnt = 0, data[maxn], next[maxn], list[maxn];
	cin >> first >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> addr;
		cin >> data[addr] >> next[addr];
	}
	while (first != -1) {
		list[cnt++] = first;
		first = next[first];
	}
	for (int i = 0; i < cnt - cnt%k; i += k)
		reverse(begin(list) + i, begin(list) + i + k);
	for (int i = 0; i < cnt - 1; i++)
		printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
	printf("%05d %d -1", list[cnt - 1], data[list[cnt - 1]]);
	return 0;
}
