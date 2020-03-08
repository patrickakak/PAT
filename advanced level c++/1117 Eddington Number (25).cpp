#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, index = 1;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend()-1);
	while (index < v[index]) index++;
	printf("%d", index-1);
	return 0;
}
