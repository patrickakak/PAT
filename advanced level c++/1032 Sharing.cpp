
#include <iostream>
#include <cstdio>
using namespace std;

struct node {
	char ch;
	int flag, next;
} nodes[100005];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int fir, sec, n, addr, next;
	char ch;
	scanf("%d%d%d", &fir, &sec, &n);
	for (int i=0; i<n; i++) {
		scanf("%d %c %d", &addr, &ch, &next);
		nodes[addr].ch=tolower(ch);
		nodes[addr].next=next;
	}
	int p=fir;
	while (p!=-1) {
		nodes[p].flag++;
		p=nodes[p].next;
	}
	p=sec;
	while (p!=-1) {
		if (nodes[p].flag==1) {
			break;
		}
		p=nodes[p].next;
	}
	if (p==-1) {
		printf("-1");
	} else {
		printf("%05d", p);
	}

	return 0;
}


