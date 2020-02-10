#include <iostream>
#include <algorithm>
using namespace std;
struct contacts {
	string name, birth, gender, fixed, mobile;
} c[15];
int main() {
	int n, k, id;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> c[i].name >> c[i].birth >> c[i].gender;
		cin >> c[i].fixed >> c[i].mobile;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> id;
		if (id >= n || id < 0) cout << "Not Found" << endl;
		else {
			cout << c[id].name << " " << c[id].fixed << " " << c[id].mobile;
			cout << " " << c[id].gender << " " << c[id].birth << endl;
		}
	}
	return 0;
}
