/**
 * Sample input:
 * 5 7 5
 * 1 2 3 4 5 6 7
 * 3 2 1 7 5 6 4
 * 7 6 5 4 3 2 1
 * 5 6 4 3 7 2 1
 * 1 7 6 5 4 3 2
 * -------------
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

#define maxn 1010
int arr[maxn];
stack<int> s;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int m, n, k;

	scanf("%d%d%d", &m, &n, &k);
	for (int i=0; i<k; i++) {
		while (!s.empty())	// clear stack once again
			s.pop();
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j]);
		bool flag = true;	// To indicate validity of the sequence
		int current = 0;	// point to next element in to-be-checked sequence
		for (int j = 1; j <= n; j++) {
			s.push(j);
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


