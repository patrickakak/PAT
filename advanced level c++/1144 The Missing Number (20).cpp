#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n, a, num = 1;
	cin >> n;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		m[a]++;
	}
	while (m[num] != 0)
		num++;
	printf("%d", num);
	return 0;
}
