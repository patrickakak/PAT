#include <string.h>
#define maxn 10010
typedef struct LargeNum {
	int d[maxn];
	int len;
} largeNum;
void print(largeNum n) {
	for (int i = n.len-1; i >= 0; i--)
		printf("%d", n.d[i]);
}
largeNum change(char s[]) {
	largeNum r;
	r.len = strlen(s);
	for (int i = r.len-1, j = 0; i >= 0; i--, j++)
		r.d[j] = s[i] - '0';
	return r;
}
largeNum multi(largeNum a, int b) {
	largeNum r;
	r.len = 0;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int tmp = a.d[i]*b+carry;
		r.d[r.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0) {
		r.d[r.len++] = carry % 10;
		carry /= 10;
	}
	return r;
}
void Print_Factorial(const int N) {
	if (N < 0) printf("Invalid input\n");
	else {
		largeNum c = change("1");
		for (int i = 1; i <= N; i++) c = multi(c, i);
		print(c);
	}
}
