#include <iostream>
using namespace std;
int main() {
	string pwd, tmp;
	int n, cnt = 0;
	cin >> pwd >> n;
	getchar();
	while (getline(cin, tmp)) {
		if (tmp == "#") break;
		cnt++;
		if (cnt <= n && tmp == pwd) {
			cout << "Welcome in";
			break;
		} else if (cnt <= n && tmp != pwd) {
			cout << "Wrong password: " << tmp << endl;
			if (cnt == n) {
				cout << "Account locked";
				break;
			}
		}
	}
	return 0;
}
