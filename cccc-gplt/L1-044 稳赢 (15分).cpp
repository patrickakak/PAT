#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	string s;
	while (cin >> s) {
		if (s == "End") break;
		if (cnt == n) {
			cout << s << endl;
			cnt = 0;
		} else {
			cnt++;
			if (s == "ChuiZi") printf("Bu\n");
			else if (s == "JianDao") printf("ChuiZi\n");
			else printf("JianDao\n");
		}
	}
	return 0;
}
