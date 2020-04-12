#include <iostream>
#include <set>
using namespace std;
int hit[50001];
struct node {
	int v, cnt;
	bool operator < (const node &a) const {
		return cnt != a.cnt ? cnt > a.cnt : v < a.v;
	}
	/*
	friend bool operator < (const node &a, const node &b) {
		return a.cnt != b.cnt ? a.cnt > b.cnt : a.v < b.v;
	}
	*/
};
int main() {
	int n, k, num;
	scanf("%d%d", &n, &k);
	set<node> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (i != 0) {
			printf("%d:", num);
			int j = 0;
			for (auto it = s.begin(); j < k && it != s.end(); it++) {
				printf(" %d", it->v);
				j++;
			}
			printf("\n");
		}
		auto it = s.find(node{num, hit[num]});
		if (it != s.end()) s.erase(it);
		s.insert(node{num, ++hit[num]});
	}
	return 0;
}
