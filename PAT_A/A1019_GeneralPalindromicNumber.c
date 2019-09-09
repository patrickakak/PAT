/**
 * Sample input1:
 * 27 2
 * Sample output1:
 * Yes
 * 1 1 0 1 1
 * --------------
 * Sample input2:
 * 121 5
 * Sample output2:
 * No
 * 4 4 1
 */
#include <stdio.h>


int isPalindrom(int no[], int N)
{
	int i, j;

	for (i=0,j=N-1; i < j; i++,j--)
		if (no[i] != no[j])
			break;
	if (i >= j) return 1;
	else return 0;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, base, r, i, no[35], count=0;

	scanf("%d %d", &N, &base);
	do {
		r = N % base;
		no[count++] = r;
		N /= base;
	} while (N);

	if (isPalindrom(no, count))
		printf("Yes\n");
	else
		printf("No\n");

	for (i = count-1; i > 0; i--)
		printf("%d ", no[i]);
	printf("%d\n", no[i]);

	return 0;
}

