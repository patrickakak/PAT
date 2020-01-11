/**
 * Sample input:
 * 00100 6 4
 * 00000 4 99999
 * 00100 1 12309
 * 68237 6 -1
 * 33218 3 00000
 * 99999 5 68237
 * 12309 2 33218
 * -------------
 * Sample output:
 * 00000 4 33218
 * 33218 3 12309
 * 12309 2 00100
 * 00100 1 99999
 * 99999 5 68237
 * 68237 6 -1
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100100
struct Node {
	int addr, data, next;
	int order;
} node[maxn];

bool cmp(Node a, Node b)
{
	return a.order < b.order;
}

void init()
{
	for (int i = 0; i < maxn; i++)
		node[i].order = maxn;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int begin, n, K, addr;

	init();
	scanf("%d%d%d", &begin, &n, &K);
	for (int i = 0; i < n; i++) {
		scanf("%d", &addr);
		scanf("%d%d", &node[addr].data, &node[addr].next);
		node[addr].addr = addr;
	}
	int p = begin, count = 0;
	while (p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	for (int i = 0; i < n/K; i++) {
		for (int j = (i+1)*K - 1; j > i*K; j--)
			printf("%05d %d %05d\n", node[j].addr, node[j].data, node[j-1].addr);
		printf("%05d %d ", node[i*K].addr, node[i*K].data);
		if (i < n/K-1)
			printf("%05d\n", node[(i+2)*K-1].addr);
		else {
			if (n % K == 0)
				printf("-1\n");
			else {
				printf("%05d\n", node[(i+1)*K].addr);
				for (int i = n/K * K; i < n; i++) {
					printf("%05d %d ", node[i].addr, node[i].data);
					if (i < n-1) printf("%05d\n", node[i+1].addr);
					else printf("-1\n");
				}
			}
		}
	}

	return 0;
}


