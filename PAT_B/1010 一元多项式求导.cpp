#include <iostream>
using namespace std;
int main() {
	int c, e, flag = 0;
	while (cin >> c >> e)
		if (e != 0) {
			if (flag) cout << ' ';
			cout << c * e << ' ' << e - 1;
			flag = 1;
		}
	if (flag == 0) cout << "0 0";
	return 0;
}
