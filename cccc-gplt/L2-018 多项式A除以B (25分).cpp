#include <iostream>
#include <cmath>
using namespace std;
double a[100010], b[100010], q[100010];
int main() {
	int n, e, c, maxe1, maxe2, qcnt = 0, rcnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &e, &c);
		a[e] = c;
		if (i == 0) maxe1 = e;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &e, &c);
		b[e] = c;
		if (i == 0) maxe2 = e;
	}
	for (int i = maxe1; i >= 0; i--) {
		int d = i-maxe2;
		if (d < 0) break;
		q[d] = a[i] / b[maxe2];
		for (int j = maxe2; j >= 0; j--) a[j+d] = a[j+d] - b[j]*q[d];
	}
	for (int i = maxe1; i >= 0; i--) {
		if (fabs(a[i]) >= 0.05) rcnt++;
		if (fabs(q[i]) >= 0.05) qcnt++;
	}
	if (qcnt == 0) printf("0 0 0.0\n");
	else {
		printf("%d", qcnt);
		for (int i = maxe1; i >= 0; i--)
			if (fabs(q[i]) >= 0.05) printf(" %d %.1f", i, q[i]);
		printf("\n");
	}
	if (rcnt == 0) printf("0 0 0.0\n");
	else {
		printf("%d", rcnt);
		for (int i = maxe1; i >= 0; i--)
			if (fabs(a[i]) >= 0.05) printf(" %d %.1f", i, a[i]);
	}
	return 0;
}
