#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> v;
void upAdjust(int low, int high) {
	int i = high, j = i/2;
	while (j > 0) {
		if (v[j] > v[i]) swap(v[i], v[j]);
		else break;
		i = j, j = i/2;
	}
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	v.resize(n+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		upAdjust(1, i);
	}
	unordered_map<int, int> mp;
	for (int i = 1; i <= n; i++) mp[v[i]] = i;
	getchar();
	string s;
	bool flg;
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		if (s.find("root") != string::npos) {
			sscanf(s.c_str(), "%d is the root", &a);
			flg = (mp[a] == 1);
		} else if (s.find("siblings") != string::npos) {
			sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
			flg = ((mp[a] > 1 && mp[b] > 1) && (mp[a]/2 == mp[b]/2));
		} else if (s.find("parent") != string::npos) {
			sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
			flg = (mp[a] != 0 && mp[b]/2 == mp[a]);
		} else if (s.find("child") != string::npos) {
			sscanf(s.c_str(), "%d is a child of %d", &a, &b);
			flg = (mp[b] != 0 && (mp[b]*2 == mp[a] || mp[b]*2+1 == mp[a]));
		}
		printf("%s\n", flg ? "T" : "F");
	}
	return 0;
}
