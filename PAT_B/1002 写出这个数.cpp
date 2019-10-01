/**
 * Sample input:
 * 1234567890987654321123456789
 * -------------------
 * Sample output:
 * yi san wu
 */
#include <cstdio>

char pinyin[11][5] = {"ling", "yi", "er", "san", "si", 
                      "wu", "liu", "qi", "ba", "jiu", "shi"};

int main()
{
	// freopen("test.txt", "r", stdin);
	char n[120];
	int r, i = 0, sum = 0, count = 0, arr[120];

	scanf("%s", n);
	while (n[i]) {
		sum += n[i] - '0';
		i++;
	}
	do {
		r = sum % 10;
		arr[count++] = r;
		sum /= 10;
	} while (sum);

	for (i = count-1; i > 0; i--)
		printf("%s ", pinyin[arr[i]]);
	printf("%s", pinyin[arr[0]]);

	return 0;
}

