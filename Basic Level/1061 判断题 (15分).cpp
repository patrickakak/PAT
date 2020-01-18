#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, t;
	cin >> n >> m;
	vector<int> tot(m), right(m);
	for (int i = 0; i < m; i++) cin >> tot[i];
	for (int i = 0; i < m; i++) cin >> right[i];
	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < m; j++) {
			cin >> t;
			if (t == right[j]) score += tot[j];
		}
		cout << score << endl;
	}
	return 0;
}
