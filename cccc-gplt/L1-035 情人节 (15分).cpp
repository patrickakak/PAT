#include <iostream>
#include <vector>
using namespace std;
int main() {
	string s;
	int cnt = 0;
	vector<string> v(1);
	while (cin >> s) {
		if (s == ".") break;
		cnt++;
		v.push_back(s);
	}
	if (cnt < 2) printf("Momo... No one is for you ...\n");
	else if (cnt < 14) printf("%s is the only one for you...\n", v[2].c_str());
	else printf("%s and %s are inviting you to dinner...\n", v[2].c_str(), v[14].c_str());
	return 0;
}
