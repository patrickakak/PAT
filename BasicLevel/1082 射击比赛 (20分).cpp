#include <iostream>
using namespace std;
int main() {
	int n, id, x, y, maxid, maxdis = 0, minid, mindis = 10000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> x >> y;
		int dis = x * x + y * y;
		if (dis > maxdis) maxid = id;
		if (dis < mindis) minid = id;
		maxdis = max(maxdis, dis);
		mindis = min(mindis, dis);
	}
	printf("%04d %04d", minid, maxid);
	return 0;
}
