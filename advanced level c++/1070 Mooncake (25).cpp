#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct mooncake {
	double amt, per, tot;
};
bool cmp(mooncake &a, mooncake &b) {
	return a.per > b.per;
}
int main() {
	int n, d;
	cin >> n >> d;
	vector<mooncake> a(n);
	for (int i = 0; i < n; i++) scanf("%lf", &a[i].amt);
	for (int i = 0; i < n; i++) scanf("%lf", &a[i].tot);
	for (int i = 0; i < n; i++) a[i].per = a[i].tot / a[i].amt;
	sort(a.begin(), a.end(), cmp);
	double res = 0;
	for (int i = 0; i < n; i++)
		if (a[i].amt <= d) {
			d -= a[i].amt;
			res += a[i].tot;
		} else {
			res += a[i].per * d;
			break;
		}
	printf("%.2f", res);
	return 0;
}
