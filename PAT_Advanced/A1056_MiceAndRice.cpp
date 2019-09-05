/**
 * Sample input:
 * 11 3
 * 25 18 0 46 37 3 19 22 57 56 10
 * 6 0 8 7 10 5 9 1 4 2 3
 * --------------------------
 * Sample output:
 * 5 5 5 2 5 5 5 3 1 3 5
 */
#include <cstdio>
#include <queue>
using namespace std;

#define maxn 1010
struct Mouse {
	int weight;
	int r;
} mice[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int np, ng, order;

	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++)
		scanf("%d", &mice[i].weight);
	queue<int> q;
	for (int i = 0; i < np; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int tmp = np, group; 	// tmp: # of mice in current round
	while (q.size() != 1) {
		if (tmp % ng == 0) group = tmp / ng;
		else group = tmp / ng + 1;
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (i * ng + j >= tmp) break; 	// last group is less than ng
				int front = q.front();
				if (mice[front].weight > mice[k].weight)
					k = front;
				mice[front].r = group + 1;
				q.pop();
			}
			q.push(k);
		}
		tmp = group;
	}
	mice[q.front()].r = 1;
	for (int i = 0; i < np; i++) {
		if (i > 0) printf(" ");
		printf("%d", mice[i].r);
	}

	return 0;
}


