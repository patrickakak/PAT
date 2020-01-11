#include <iostream>
#include <string>
using namespace std;
string ss[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';
	string num = to_string(sum);
	for (int i = 0; i < num.length(); i++) {
		cout << ss[num[i] - '0'];
		if (i != num.length()-1) cout << " ";
	}
	return 0;
}
