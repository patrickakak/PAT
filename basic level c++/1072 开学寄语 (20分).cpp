#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n, m, id, k, item = 0, cnt = 0;
	unordered_map<int, int> mp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		cin >> id;
		mp[id] = 1;
	}
	string name;
	for (int i = 0; i < n; i++) {
		cin >> name >> k;
		bool flag = true;
		for (int j = 0; j < k; j++) {
			cin >> id;
			if (mp[id] != 0) {
				if (flag == true) {
					flag = false;
					cout << name << ": ";
				} else printf(" ");
				printf("%04d", id);
				item++;
			}
		}
		if (flag == false) {
			cnt++;
			printf("\n");
		}
	}
	printf("%d %d", cnt, item);
	return 0;
}
