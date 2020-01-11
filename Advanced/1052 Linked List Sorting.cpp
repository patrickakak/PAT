
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100005;
struct node {
	int addr, key, next;
	int flag;
} nodes[maxn];

bool cmp(node a, node b)
{
	if (a.flag!=b.flag) return a.flag>b.flag;
	else return a.key<b.key;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, fir, addr, key, next;
	scanf("%d %d", &n, &fir);
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		nodes[addr].addr=addr;
		nodes[addr].key=key;
		nodes[addr].next=next;
	}
	int cnt=0, p=fir;
	while (p!=-1) {
		nodes[p].flag++;
		p=nodes[p].next;
		cnt++;
	}
	if (cnt==0) {
		printf("0 -1");
		return 0;
	}
	sort(nodes, nodes+maxn, cmp);
	printf("%d %05d\n", cnt, nodes[0].addr);
	for (int i=0; i<cnt; i++) {
		printf("%05d %d ", nodes[i].addr, nodes[i].key);
		if (i < cnt-1)
			printf("%05d\n", nodes[i+1].addr);
		else printf("-1");
	}

	return 0;
}

