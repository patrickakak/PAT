#include <iostream>
#include <set>
using namespace std;
int main() {
	int n, tmp;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		auto it = s.upper_bound(tmp);
		if (it != s.end()) s.erase(it);
		s.insert(tmp);
	}
	printf("%d\n", s.size());
	return 0;
}
