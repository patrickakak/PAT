
#include <cstdio>
#include <queue>
using namespace std;

const int maxn=1010;
struct mice {
	int wt, rank;
} mice[maxn];
queue<int> q;
int out_seq[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int np, ng;
	scanf("%d%d", &np, &ng);
	for (int i=0; i<np; i++) {
		scanf("%d", &mice[i].wt);
	}
	int order;
	for (int i=0; i<np; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int num=np, group;
	while (q.size() > 1) {
		if (num % ng == 0) group = num / ng;
		else group = num/ng + 1;
		int index=0;
		for (int i=0; i<group; i++) {
			int k=q.front();
			for (int j=0; j<ng; j++) {
				if (q.empty()) break;
				int front=q.front();
				if (mice[k].wt < mice[front].wt) {
					k=front;
				}
				mice[front].rank=group+1;
				q.pop();
			}
			out_seq[index++]=k;
		}
		num=group;
		for (int i=0; i<index; i++) {
			q.push(out_seq[i]);
		}
	}
	mice[q.front()].rank=1;
	for (int i=0; i<np; i++) {
		printf("%d", mice[i].rank);
		if (i < np-1) printf(" ");
	}

	return 0;
}

