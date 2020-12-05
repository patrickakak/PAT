#include <iostream>
using namespace std;
int main() {
	int pa, pb, t, cnt = 0;
	cin >> pa >> pb;
	for (int i = 0; i < 3; i++) {
		cin >> t;
		if (t == 0) cnt++;
	}
	if (pa > pb && cnt >= 1) cout << "The winner is a: " << pa << " + " << cnt;
	else cout << "The winner is b: "<< pb << " + " << 3-cnt;
	return 0;
}
