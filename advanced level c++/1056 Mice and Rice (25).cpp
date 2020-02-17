#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse {
	int wt, rnk;
} mice[maxn];
queue<int> q;
int new_round[maxn];
int main() {
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) scanf("%d", &mice[i].wt);
	for (int i = 0; i < np; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int cnt = np, group;
	while (q.size() > 1) {
		if (cnt % ng == 0) group = cnt / ng;
		else group = cnt / ng + 1;
		int index = 0;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (q.empty()) break;
				if (mice[q.front()].wt > mice[k].wt) k = q.front();
				mice[q.front()].rnk = group + 1;
				q.pop();
			}
			new_round[index++] = k;
		}
		cnt = group;
		for (int i = 0; i < index; i++) q.push(new_round[i]);
	}
	mice[q.front()].rnk = 1;
	for (int i = 0; i < np; i++) {
		printf("%d", mice[i].rnk);
		if (i < np - 1) printf(" ");
	}
	return 0;
}
