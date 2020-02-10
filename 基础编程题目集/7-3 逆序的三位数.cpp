#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	cout << stoi(s);
	return 0;
}
