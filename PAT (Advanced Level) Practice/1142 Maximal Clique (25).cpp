#include <iostream>
#include <vector>
using namespace std;
int main() {
	int nv, ne, m, ta, tb, k, e[210][210] = {0};
	scanf("%d %d", &nv, &ne);
	for (int i = 0; i < ne; i++) {
		scanf("%d %d", &ta, &tb);
		e[ta][tb] = e[tb][ta] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		vector<int> v(k);
		int h[210] = {0}, isClique = 1, isMax = 1;
		for (int j = 0; j < k; j++) {
			scanf("%d", &v[j]);
			h[v[j]] = 1;
		}
		for (int j = 0; j < k; j++) {
			if (isClique == 0) break;
			for (int l = j + 1; l < k; l++)
				if (e[v[j]][v[l]] == 0) {
					isClique = 0;
					printf("Not a Clique\n");
					break;
				}
		}
		if (!isClique) continue;
		for (int j = 1; j <= nv; j++) {
			if (h[j] == 0)
				for (int l = 0; l < k; l++) {
					if (e[v[l]][j] == 0) break;
					if (l == k-1) isMax = 0;
				}
			if (isMax == 0) {
				printf("Not Maximal\n");
				break;
			}
		}
		if (isMax == 1) printf("Yes\n");
	}
	return 0;
}
