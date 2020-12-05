#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	vector<int> couple(100000, -1), single;
	int n, a, b, m, id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		couple[a] = b, couple[b] = a;
	}
	cin >> m;
	set<int> s;
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		s.insert(id);
	}
	for (auto it : s) {
		if (couple[it] != -1 && s.find(couple[it]) == s.end()) couple[it] = -1;
		if (couple[it] == -1) single.push_back(it);
	}
	printf("%d\n", single.size());
	for (int i = 0; i < single.size(); i++) {
		if (i != 0) printf(" ");
		printf("%05d", single[i]);
	}
	return 0;
}
