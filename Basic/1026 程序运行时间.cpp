/**
 * Sample Input:
 * 123 4577973
 * --------------
 * Sample Output:
 * 12:42:59
 */
#include <stdio.h>
#include <math.h>

#define CLK_TCK 100

int main()
{
	// freopen("test.txt", "r", stdin);
	int C1, C2, diff;
	double hr, min, sec;

	scanf("%d%d", &C1, &C2);
	diff = C2 - C1;

	hr = (double)diff/3600/CLK_TCK;
	min = (hr-(int)hr) * 60;
	sec = (min-(int)min) * 60;

	printf("%02d:%02d:%02d\n", (int)hr, (int)min, (int)round(sec));

	return 0;
}

