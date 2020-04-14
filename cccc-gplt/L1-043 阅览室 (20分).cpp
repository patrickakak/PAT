#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct node {
	int start, end, tm;
};
vector<node> v(1010, {-1,-1,0});
int main() {
	int n, day = 0, cnt = 0, sum = 0, id, h, m;
	char c;
	cin >> n;
	while (day < n) {
		scanf("%d %c %d:%d", &id, &c, &h, &m);
		if (id == 0) {
			day++;
			if (cnt == 0) printf("0 0\n");
			else printf("%d %d\n", cnt, (int)round(1.0*sum/cnt));
			sum = cnt = 0;
			continue;
		}
		if (c == 'S') v[id].start = h * 60 + m;
		else {
			v[id].end = h * 60 + m;
			if (v[id].start != -1) {
				cnt++;
				v[id].tm += v[id].end - v[id].start;
				sum += v[id].end - v[id].start;
				v[id].start = -1;
			}
		}
	}
	return 0;
}
