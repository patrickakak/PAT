#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}
int main() {
	int n, sum = 0;
	cin >> n;
	pair<string, int> p[10010];
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		sum += p[i].second;
	}
	sum /= 2*n;
	for (int i = 0; i < n; i++)
		p[i].second = abs(p[i].second - sum);
	sort(p, p+n, cmp);
	printf("%d %s\n", sum, p[0].first.c_str());
	return 0;
}
