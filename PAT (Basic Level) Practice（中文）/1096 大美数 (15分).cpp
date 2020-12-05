#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		int sqr = sqrt(n);
		vector<int> v;
		for (int j = 1; j <= sqr; j++)
			if (n % j == 0) {
				v.push_back(j);
				if (j * j != n) v.push_back(n/j);
			}
		int flag = 0, sz = v.size();
		for (int a = 0; a < sz-3; a++)
			for (int b = a+1; b < sz-2; b++)
				for (int c = b+1; c < sz-1; c++)
					for (int d = c+1; d < sz; d++)
						if ((v[a] + v[b] + v[c] + v[d]) % n == 0)
							flag = 1;
		printf("%s\n", flag == 1 ? "Yes" : "No");
	}
	return 0;
}
