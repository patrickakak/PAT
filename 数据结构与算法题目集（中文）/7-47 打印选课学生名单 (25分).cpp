#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, k, num, t;
	scanf("%d%d", &n, &k);
	vector<string> v[2501];
	string name;
	for (int i = 0; i < n; i++) {
		cin >> name >> num;
		for (int j = 0; j < num; j++) {
			scanf("%d", &t);
			v[t].push_back(name);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++)
			printf("%s\n", v[i][j].c_str());
	}
	return 0;
}
