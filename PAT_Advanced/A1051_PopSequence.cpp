/**
 * Sample input:
 * 5 7 5
 * 1 2 3 4 5 6 7
 * 3 2 1 7 5 6 4
 * 7 6 5 4 3 2 1
 * 5 6 4 3 7 2 1
 * 1 7 6 5 4 3 2
 * --------------
 * Sample output:
 * YES
 * NO
 * NO
 * YES
 * NO
 */
#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];
stack<int> s;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int m, n, k;	// m: max capacity

	scanf("%d%d%d", &m, &n, &k);
	while (k--) {
		while (!s.empty())
			s.pop();
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		int current = 1;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			s.push(i);
			if ((int)s.size() > m) {
				flag = false;
				break;
			}
			while (!s.empty() && s.top() == arr[current]) {
				s.pop();
				current++;
			}
		}
		if (s.empty() && flag == true) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}


