#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n, p, t;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		unordered_map<char, int> um;
		for (int j = 0; j < s.length(); j++) {
			um[s[j]]++;
			if (s[j] == 'P') p = j;
			if (s[j] == 'T') t = j;
		}
		if (um['P']==1 && um['T']==1 && um.size()==3 && t-p!=1 && p*(t-p-1)==s.length()-1-t)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
