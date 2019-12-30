
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100010;
struct node {
	int addr, data, next;
	int order, flag;
} nodes[maxn];

bool cmp(node a, node b)
{
	if (a.flag!=b.flag) return a.flag>b.flag;
	else return a.order<b.order;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int fir, n, k;
	scanf("%d%d%d", &fir, &n, &k);
	int addr, data, next;
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		nodes[addr].addr=addr;
		nodes[addr].data=data;
		nodes[addr].next=next;
	}
	int cnt=0;
	for (int p=fir; p!=-1; p=nodes[p].next) {
		nodes[p].order=cnt++;
		nodes[p].flag=1;
	}
	sort(nodes, nodes+maxn, cmp);
	n=cnt;
	for (int i=0; i<n/k; i++) {
		for (int j=(i+1)*k-1; j>i*k; j--) {
			printf("%05d %d %05d\n", nodes[j].addr, nodes[j].data, nodes[j-1].addr);
		}
		printf("%05d %d ", nodes[i*k].addr, nodes[i*k].data);
		if (i < n/k-1) printf("%05d\n", nodes[(i+2)*k-1].addr);
		else {
			if (n%k==0) printf("-1\n");
			else {
				printf("%05d\n", nodes[(i+1)*k].addr);
				for (int j=n/k*k; j<n; j++) {
					printf("%05d %d ", nodes[j].addr, nodes[j].data);
					if (j<n-1) printf("%05d\n", nodes[j+1].addr);
					else printf("-1\n");
				}
			}
		}
	}
	return 0;
}
