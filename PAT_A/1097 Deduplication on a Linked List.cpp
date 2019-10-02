/**
 * Sample input:
 * 00100 5
 * 99999 -7 87654
 * 23854 -15 00000
 * 87654 15 -1
 * 00000 -15 99999
 * 00100 21 23854
 * ----------------
 * Sample output:
 * 00100 21 23854
 * 23854 -15 99999
 * 99999 -7 -1
 * 00000 -15 87654
 * 87654 15 -1
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 100005
struct Node {
	int addr, data, next;
	int order;
} node[maxn];
bool isExist[maxn] = {false};

bool cmp(Node a, Node b)
{
	return a.order < b.order;
}

void init()
{
	for (int i = 0; i < maxn; i++)
		node[i].order = 2 * maxn;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int begin, n, addr;

	init();
	scanf("%d%d", &begin, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &addr);
		scanf("%d%d", &node[addr].data, &node[addr].next);
		node[addr].addr = addr;
	}
	int countValid = 0, countRemoved = 0, p = begin;
	while (p != -1) {
		if (!isExist[abs(node[p].data)]) {
			isExist[abs(node[p].data)] = true;
			node[p].order = countValid++;
		} else
			node[p].order = maxn + countRemoved++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int count = countValid + countRemoved;
	for (int i = 0; i < count; i++)
		if (i != countValid-1 && i != count-1)
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
		else
			printf("%05d %d -1\n", node[i].addr, node[i].data);

	return 0;
}


