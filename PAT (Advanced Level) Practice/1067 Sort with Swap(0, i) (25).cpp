#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		while (p[0] != 0) {
			swap(p[0], p[p[0]]);
			cnt++;
		}
		if (p[i] != i) {
			swap(p[i], p[0]);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
