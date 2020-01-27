#include <iostream>
#include <vector>
using namespace std;
int main() {
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		vector<int> v(n);
		bool res = true;
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[j]);
			for (int t = 0; t < j; t++)
				if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
					res = false;
					break;
				}
		}
		printf("%s\n", res == true ? "YES" : "NO");
	}
	return 0;
}
