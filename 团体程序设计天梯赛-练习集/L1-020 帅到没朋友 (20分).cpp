#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, bool> mp;
int father[100000], rcnt[100000];
int find(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA != faB) father[faA] = faB;
}
int main() {
	for (int i = 0; i < 100000; i++) father[i] = i;
	int n, m, k, fir, id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &k, &fir);
		mp[fir] = true;
		for (int j = 0; j < k-1; j++) {
			scanf("%d", &id);
			mp[id] = true;
			Union(fir, id);
		}
	}
	cin >> m;
	vector<int> v;
	unordered_map<int, bool> um;
	unordered_map<int, int> rootcnt;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int pid = it->first;
		rcnt[find(pid)]++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		if (mp[id] != true && um[id] == false) {
			v.push_back(id);
			um[id] = true;
		} else if (mp[id] == true) {
			int fa = find(id);
			if (rcnt[fa] == 1) {
				v.push_back(id);
				um[id] = true;
			}
		}
	}
	if (v.size() == 0) {
		printf("No one is handsome");
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) printf(" ");
		printf("%05d", v[i]);
	}
	return 0;
}
