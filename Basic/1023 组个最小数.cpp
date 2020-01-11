#include <iostream>
using namespace std;
int main() {
	int n, cnt[10] = {0};
	for (int i = 0; i < 10; i++) {
		cin >> n;
		cnt[i] = n;
	}
	for (int i = 1; i < 10; i++)
		if (cnt[i] != 0) {
			cout << i;
			cnt[i]--;
			break;
		}
	for (int i = 0; i < 10; i++)
		if (cnt[i] != 0)
			for (int j = 0; j < cnt[i]; j++) cout << i;
	return 0;
}
