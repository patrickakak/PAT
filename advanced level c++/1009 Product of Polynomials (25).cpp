#include <iostream>
#include <vector>
using namespace std;
double a[1010], b[2020];
int main() {
	int k1, k2, e, cnt = 0;
	double c;
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		scanf("%d%lf", &e, &c);
		a[e] += c;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		scanf("%d%lf", &e, &c);
		for (int j = 0; j < 1010; j++)
			if (a[j] != 0) {
				b[e+j] += a[j] * c;
			}
	}
	vector<pair<int, double>> v;
	for (int i = 2019; i >= 0; i--)
		if (b[i] != 0) {
			cnt++;
			v.push_back({i, b[i]});
		}
	printf("%d", cnt);
	for (int i = 0; i < v.size(); i++)
		printf(" %d %.1f", v[i].first, v[i].second);
	return 0;
}
