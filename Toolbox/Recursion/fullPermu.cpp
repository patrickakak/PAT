/**
 * Full permutation by using recursion implementation
 */
#include <cstdio>
#include <cstring>


#define maxn 100
bool hashTbl[maxn] = {false};
char result[maxn];
void getPermu(int index, int n, char A[])
{
	if (index == n) {
		for (int i = 0; i < n; i++)
			printf("%c", result[i]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
		if (hashTbl[i] == false) {
			result[index] = A[i];
			hashTbl[i] = true;
			getPermu(index+1, n, A);
			hashTbl[i] = false;
		}
}

int main()
{
	char s[100] = "abcd";

	int len = strlen(s);
	getPermu(0, len, s);

	return 0;
}

