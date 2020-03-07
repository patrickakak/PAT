#include <iostream>
#include <vector>
using namespace std;
double a[1010];
int main() {
	int k1, k2, e, cnt = 0;
	double c;
	cin >> k1;
	for (int i=0; i<k1; i++) {
		scanf("%d%lf", &e, &c);
		a[e] += c;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		scanf("%d%lf", &e, &c);
		a[e] += c;
	}
	vector<pair<int, double>> v;
	for (int i = 1009; i >= 0; i--)
		if (a[i] != 0) {
			cnt++;
			v.push_back({i, a[i]});
		}
	printf("%d", cnt);
	for (int i = 0; i < v.size(); i++)
		printf(" %d %.1f", v[i].first, v[i].second);
	return 0;
}
