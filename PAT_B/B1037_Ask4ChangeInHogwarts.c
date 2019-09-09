/**
 * Sample input1:
 * 10.16.27 14.1.28
 * Sample output1:
 * 3.2.1
 * ----------------
 * Sample input2:
 * 14.1.28 10.16.27
 * Sample output2:
 * -3.2.1
 */
#include <stdio.h>

#define G2S 17
#define S2K 29

typedef struct {
	int G, S, K;
} change;

change getChange(change bill, change have)
{
	int diff, m1, m2, flag=0;
	change ret;

	m1 = bill.G*G2S*S2K + bill.S*S2K + bill.K;
	m2 = have.G*G2S*S2K + have.S*S2K + have.K;
	if (m1 > m2) {
		flag = 1;
		diff = m1 - m2;
	} else
		diff = m2 - m1;

	ret.G = diff / S2K / G2S;
	diff = diff - ret.G*G2S*S2K;
	ret.S = diff / S2K;
	diff = diff - ret.S*S2K;
	ret.K = diff;
	if (flag)
		ret.G = -ret.G;
	return ret;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	change bill, have, ret;

	scanf("%d.%d.%d %d.%d.%d",
			&bill.G, &bill.S, &bill.K, &have.G, &have.S, &have.K);

	ret = getChange(bill, have);
	printf("%d.%d.%d\n", ret.G, ret.S, ret.K);

	return 0;
}

