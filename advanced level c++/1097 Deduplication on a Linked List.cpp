
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100010;
struct Node {
	int addr, data, next;
	int order, flag;
} node[maxn];
bool isExist[maxn]={false};
Node lst1[maxn], lst2[maxn];

bool cmp(Node a, Node b)
{
	if (a.flag!=b.flag) return a.flag>b.flag;
	return a.order<b.order;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int fir, n;
	scanf("%d%d", &fir, &n);
	int addr, data, next;
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].addr=addr;
		node[addr].data=data;
		node[addr].next=next;
	}
	int sum=0, cnt1=0, cnt2=0;
	for (int p=fir; p!=-1; p=node[p].next) {
		node[p].flag=1;
		node[p].order=sum++;
		int v=abs(node[p].data);
		if (isExist[v]) {
			lst2[cnt2++]=node[p];
		} else {
			lst1[cnt1++]=node[p];
			isExist[v]=true;
		}
	}
	for (int i=0; i<cnt1; i++) {
		printf("%05d %d ", lst1[i].addr, lst1[i].data);
		if (i<cnt1-1) printf("%05d\n", lst1[i+1].addr);
		else printf("-1\n");
	}
	for (int i=0; i<cnt2; i++) {
		printf("%05d %d ", lst2[i].addr, lst2[i].data);
		if (i<cnt2-1) printf("%05d\n", lst2[i+1].addr);
		else printf("-1\n");
	}
	return 0;
}

