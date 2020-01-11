#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	string name, birth, young, old, maxbir = "1814/09/06", minbir = "2014/09/06";
	for (int i = 0; i < n; i++) {
		cin >> name >> birth;
		if (birth < "1814/09/06" || birth > "2014/09/06") continue;
		cnt++;
		if (maxbir < birth) {
			maxbir = birth;
			young = name;
		}
		if (minbir > birth) {
			minbir = birth;
			old = name;
		}
	}
	if (cnt != 0) cout << cnt << ' ' << old << ' ' << young;
	else cout << 0;
	return 0;
}
