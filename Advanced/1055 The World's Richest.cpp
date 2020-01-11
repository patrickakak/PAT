/**
 * Sample input:
 * 12 4
 * Zoe_Bill 35 2333
 * Bob_Volk 24 5888
 * Anny_Cin 95 999999
 * Williams 30 -22
 * Cindy 76 76000
 * Alice 18 88888
 * Joe_Mike 32 3222
 * Michael 5 300000
 * Rosemary 40 5888
 * Dobby 24 5888
 * Billy 24 5888
 * Nobody 5 0
 * 4 15 45
 * 4 30 35
 * 4 5 95
 * 1 45 50
 * --------------
 * Sample output:
 * Case #1:
 * Alice 18 88888
 * Billy 24 5888
 * Bob_Volk 24 5888
 * Dobby 24 5888
 * Case #2:
 * Joe_Mike 32 3222
 * Zoe_Bill 35 2333
 * Williams 30 -22
 * Case #3:
 * Anny_Cin 95 999999
 * Michael 5 300000
 * Alice 18 88888
 * Cindy 76 76000
 * Case #4:
 * None
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>
// #include <windows.h>		// Sleep(1000)
using namespace std;

#define maxn 100010
struct Rich {
	char name[10];
	int age;
	int net;
} rich[maxn];

bool cmp(Rich a, Rich b)
{
	if (a.net != b.net) return a.net > b.net;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%s%d%d", rich[i].name, &rich[i].age, &rich[i].net);
	sort(rich, rich+N, cmp);
	int M, Amin, Amax;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i+1);
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (rich[j].age >= Amin && rich[j].age <= Amax) {
				printf("%s %d %d\n", rich[j].name, rich[j].age, rich[j].net);
				cnt++;
			}
			if (cnt==M) break;
		}
		if (cnt == 0) printf("None\n");
	}
	return 0;
}


