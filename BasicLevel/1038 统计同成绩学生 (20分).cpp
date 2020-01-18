#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k, t;
	scanf("%d", &n);
	vector<int> v(110);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v[t]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &t);
		if (i != 0) printf(" ");
		printf("%d", v[t]);
	}
	return 0;
}
