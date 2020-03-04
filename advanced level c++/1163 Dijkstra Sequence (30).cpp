#include <iostream>
using namespace std;
const int inf=0x2fffffff;
const int maxn=1005;
int d[maxn],s[maxn],G[maxn][maxn];
bool visit[maxn];
int main() {
	int n,m,a,b,c,k;
	scanf("%d %d\n", &n, &m);
	fill(G[0], G[0]+maxn*maxn, inf);
	while (m--) {
		scanf("%d %d %d\n",&a,&b,&c);
		G[a][b]=G[b][a]=c;
	}
	scanf("%d\n",&k);
	while (k--) {
		m=n;
		for (int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		bool f=true;
		int start=s[1];
		fill(visit,visit+maxn,false);
		fill(d,d+maxn,inf);
		d[start]=0;
		for(int i=1;i<=n;i++){
			int u = -1, minn = inf;
			for (int j = 1; j <= n; j++) {
				if (!visit[j] && d[j] < minn) {
					u = j;
					minn = d[j];
				}
			}
			if (u == -1 || d[u] != d[s[i]]){
				f=false;
				continue;
			}
			u = s[i];
			visit[u]=true;
			for (int v=1;v<=n;v++){
				if(!visit[v] && G[u][v]!=inf && G[u][v]+d[u]<d[v]){
					d[v]=G[u][v]+d[u];
				}
			}
		}
		if(!f)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
