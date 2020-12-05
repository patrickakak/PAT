#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		vector<int> v(n);
		for (int j = 0; j < n; j++) scanf("%d", &v[j]);
		int now = 1;
		stack<int> s;
		for (int j = 0; j < n; j++) {
			int flag = 0;
			if (v[j] == now) now++;
			else flag = 1;
			while (!s.empty() && s.top() == now) {
				s.pop();
				now++;
			}
			if (flag == 1) s.push(v[j]);
			if (s.size() > m) break;
		}
		printf("%s\n", now > n ? "YES" : "NO");
	}
	return 0;
}
