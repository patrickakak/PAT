#include <iostream>
#include <vector>
using namespace std;
int main() {
	int k, n;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		vector<int> v(n);
		bool flag = true;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			for (int j = 0; j < i; j++)
				if (v[i] == v[j] || abs(v[i]-v[j]) == abs(i-j)) {
					flag = false;
					break;
				}
		}
		printf("%s\n", flag == true ? "YES" : "NO");
	}
	return 0;
}
