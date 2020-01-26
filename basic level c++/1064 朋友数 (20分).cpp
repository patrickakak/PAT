#include <iostream>
#include <set>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sum = 0;
		for (int j = 0; j < s.length(); j++)
			sum += s[j] - '0';
		st.insert(sum);
	}
	cout << st.size() << endl;
	for (auto it = st.begin(); it != st.end(); it++) {
		if (it != st.begin()) cout << ' ';
		cout << *it;
	}
	return 0;
}
