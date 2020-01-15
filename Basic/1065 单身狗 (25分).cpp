#include <iostream>
#include <vector>
#include <set>
using namespace std;
int couple[100000];
int main() {
	vector<int> couple(100000, -1);
	int n, a, b, m, id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		couple[a] = b; couple[b] = a;
	}
	cin >> m;
	set<int> s;
	for (int i = 0; i < m; i++) {
		cin >> id;
		s.insert(id);
	}
	vector<int> single;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (couple[*it] != -1 && s.find(couple[*it]) == s.end())
			couple[*it] = -1;
		if (couple[*it] == -1)
			single.push_back(*it);
	}
	cout << single.size() << endl;
	for (int i = 0; i < single.size(); i++) {
		if (i != 0) cout << ' ';
		printf("%05d", single[i]);
	}
	return 0;
}
