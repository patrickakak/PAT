#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n, p, t;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		unordered_map<char, int> m;
		for (int i = 0; i < s.length(); i++) {
			m[s[i]]++;
			if (s[i] == 'P') p = i;
			if (s[i] == 'T') t = i;
		}
		if (m['P']==1 && m['T']==1 && m.size()==3 && t-p!=1 && p*(t-p-1)==s.length()-1-t) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
