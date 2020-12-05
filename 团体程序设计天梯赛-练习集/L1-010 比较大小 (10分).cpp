#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> v(3);
	for (int i = 0; i < 3; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++) {
		if (i != 0) printf("->");
		printf("%d", v[i]);
	}
	return 0;
}
