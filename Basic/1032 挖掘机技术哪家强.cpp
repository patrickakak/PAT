#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, id, score, tot[maxn] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> score;
		tot[id] += score;
	}
	int p = max_element(tot, tot + maxn) - tot;
	cout << p << ' ' << tot[p];
	return 0;
}
