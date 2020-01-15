#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
	int n, m, tmp, k;
	cin >> n >> m;
	vector<set<char>> right(m);
	vector<int> tot(m), wrongCnt(m);
	char c;
	for (int i = 0; i < m; i++) {
		cin >> tot[i] >> tmp >> k;
		for (int j = 0; j < k; j++) {
			cin >> c;
			right[i].insert(c);
		}
	}
	for (int i = 0; i < n; i++) {
		int score = 0;
		scanf("\n");
		for (int j = 0; j < m; j++) {
			if (j != 0) scanf(" ");
			scanf("(%d", &k);
			set<char> st;
			for (int l = 0; l < k; l++) {
				cin >> c;
				st.insert(c);
			}
			scanf(")");
			if (st == right[j]) score += tot[j];
			else wrongCnt[j]++;
		}
		cout << score << endl;
	}
	int p = max_element(wrongCnt.begin(), wrongCnt.end()) - wrongCnt.begin();
	int maxWrongCnt = wrongCnt[p];
	if (maxWrongCnt == 0) cout << "Too simple";
	else {
		cout << maxWrongCnt;
		for (int i = 0; i < m; i++)
			if (wrongCnt[i] == maxWrongCnt)
				cout << ' ' << i + 1;
	}
	return 0;
}
