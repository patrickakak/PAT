#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, id, score;
	vector<int> v(maxn);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> score;
		v[id] += score;
	}
	int p = max_element(v.begin(), v.end()) - v.begin();
	cout << p << ' ' << v[p];
	return 0;
}
