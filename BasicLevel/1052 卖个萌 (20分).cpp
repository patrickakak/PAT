#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<vector<string>> v;
	for (int i = 0; i < 3; i++) {
		string s;
		getline(cin, s);
		vector<string> row;
		for (int j = 0, k = 0; j < s.length(); j++)
			if (s[j] == '[')
				for (int k = j + 1; k < s.length(); k++)
					if (s[k] == ']') {
						row.push_back(s.substr(j+1, k-j-1));
						break;
					}
		v.push_back(row);
	}
	int n, a, b, c, d, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e;
		if (a>v[0].size() || b>v[1].size() || c>v[2].size() || d>v[1].size() || e>v[0].size() || a<1 || b<1 || c<1 || d<1 || e<1) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << v[0][a-1] << '(' << v[1][b-1] << v[2][c-1] << v[1][d-1] << ')' << v[0][e-1] << endl;
	}
	return 0;
}
