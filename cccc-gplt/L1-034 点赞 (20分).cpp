#include <iostream>
#include <set>
using namespace std;
struct node {
	int v, cnt;
	bool operator < (const node &a) const {
		return cnt != a.cnt ? cnt > a.cnt : v > a.v;
	}
};
int main() {
	int n, k, tmp, h[1010] = {0};
	cin >> n;
	set<node> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			auto it = s.find({tmp, h[tmp]});
			if (it != s.end()) s.erase(it);
			s.insert({tmp, ++h[tmp]});
		}
	}
	printf("%d %d\n", s.begin()->v, s.begin()->cnt);
	return 0;
}
