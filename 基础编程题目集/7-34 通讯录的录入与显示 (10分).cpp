#include <iostream>
#include <algorithm>
using namespace std;
struct contacts {
	string nm, bir, sex, fix, mbl;
} c[15];
int main() {
	int n, k, id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i].nm >> c[i].bir >> c[i].sex;
		cin >> c[i].fix >> c[i].mbl;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> id;
		if (id >= n || id < 0) cout << "Not Found" << endl;
		else cout << c[id].nm << " " << c[id].fix << " " << c[id].mbl << " " << c[id].sex << " " << c[id].bir << endl;
	}
	return 0;
}
