
#include <cstdio>
#include <stack>
using namespace std;

const int maxn=1010;
int out_seq[maxn];
stack<int> st;

int main()
{
	//freopen("tst.txt", "r", stdin);
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for (int i=0; i<k; i++) {
		while (!st.empty()) st.pop();
		for (int j=0; j<n; j++) {
			scanf("%d", out_seq+j);
		}
		int index=0;
		for (int j=1; j<=n; j++) {
			st.push(j);
			if (st.size()>m) {
				break;
			}
			while (!st.empty() && st.top()==out_seq[index]) {
				st.pop();
				index++;
			}
		}
		if (st.empty()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

