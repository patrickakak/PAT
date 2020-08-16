#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct person {
	int come, time;
} p[10010];
bool cmp(person &p1, person &p2) {
	return p1.come < p2.come;
}
int n, k, cnt, total;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int hh, ss, mm, tt;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
		int sum = hh*60*60 + mm*60 + ss;
		if (sum > 17*60*60) continue;
		p[++cnt].time = tt * 60;
		p[cnt].come = sum;
	}
	sort(p+1, p+1+cnt, cmp);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= k; ++i) q.push(8*60*60);
	for (int i = 1; i <= cnt; ++i)
		if (q.top() <= p[i].come) {
			q.push(p[i].come + p[i].time);
			q.pop();
		} else {
			total += q.top() - p[i].come;
			q.push(q.top() + p[i].time);
			q.pop();
		}
	(!cnt) ? printf("0.0\n") : printf("%.1lf", 1.0*total/60/cnt);
	return 0;
}
