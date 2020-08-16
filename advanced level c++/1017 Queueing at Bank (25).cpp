#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int arrive, process;
};
bool cmp(node &a, node &b) {
	return a.arrive < b.arrive;
}
int main() {
	int n, k, time = 0, h, m, s, p, arrive;
	cin >> n >> k;
	vector<node> v;
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &h, &m, &s, &p);
		arrive = h*3600 + m*60 + s;
		if (arrive > 17*60*60) continue;
		v.push_back({arrive, p*60});
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < k; i++)
		q.push(8*60*60);
	for (int i = 0; i < v.size(); i++)
		if (v[i].arrive < q.top()) {
			time += q.top() - v[i].arrive;
			q.push(q.top() + v[i].process);
			q.pop();
		} else {
			q.push(v[i].arrive + v[i].process);
			q.pop();
		}
	v.size()==0 ? printf("0.0") : printf("%.1f", 1.0*time/60/v.size());
	return 0;
}
