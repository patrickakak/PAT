/**
 * Sample input:
 * 3 20
 * 18 15 10
 * 75 72 45
 * -----------
 * Sample output:
 * 94.50
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake {
	double store;
	double sell;
	double price;
} cake[1010];

bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	double D;

	scanf("%d%lf", &n, &D);
	for (int i = 0; i < n; i++)
		scanf("%lf", &cake[i].store);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake, cake + n, cmp);

	double ans = 0;
	for (int i = 0; i < n; i++)
		if (cake[i].store <= D) {
			D -= cake[i].store;
			ans += cake[i].sell;
		} else {
			ans += cake[i].price * D;
			break;
		}
	printf("%.2f\n", ans);

	return 0;
}


