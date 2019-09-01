/**
 * Sample input1:
 * 50 1300 12 8
 * 6.00 1250
 * 7.00 600
 * 7.00 150
 * 7.10 0
 * 7.20 200
 * 7.50 400
 * 7.30 1000
 * 6.85 300
 * Sample output1:
 * 749.17
 * ---------------
 * Sample input2:
 * 50 1300 12 2
 * 7.10 0
 * 7.00 600
 * Sample output2:
 * The maximum travel distance = 1200.00
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
#define maxn 510
struct Station {
	double price; // unit price
	double dis;
} st[maxn];

bool cmp(Station a, Station b)
{
	return a.dis < b.dis;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	double Cmax, D, Davg;

	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	st[n].price = 0;
	st[n].dis = D;
	sort(st, st + n, cmp);
	if (st[0].dis != 0)
		printf("The maximum travel distance = 0.00\n");
	else {
		int now = 0;
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		while (now < n) {
			int k = -1;
			double priceMin = INF;
			for (int i = now+1; i<=n && st[i].dis-st[now].dis<=MAX; i++)
				if (st[i].price < priceMin) {
					priceMin = st[i].price;
					k = i;
					if (priceMin < st[now].price)
						break;
				}
			if (k == -1) break;
			double need = (st[k].dis - st[now].dis) / Davg;
			if (priceMin < st[now].price) {
				if (nowTank < need) {
					ans += (need - nowTank) * st[now].price;
					nowTank = 0;
				} else
					nowTank -= need;
			} else {
				ans += (Cmax - nowTank) * st[now].price;
				nowTank = Cmax - need;
			}
			now = k;
		}
		if (now == n)
			printf("%.2f\n", ans);
		else
			printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
	}

	return 0;
}


