#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		int flag = 0, index = 0;
		stack<int> s;
		vector<int> v(n);
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);
		for (int i = 1; i <= n; i++) {
			s.push(i);
			if (s.size() > m) flag = 1;
			while (!s.empty() && s.top() == v[index]) {
				s.pop();
				index++;
			}
		}
		if (index < n) flag = 1;
		if (flag == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
