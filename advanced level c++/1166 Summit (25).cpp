#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int e[210][210];
int main() {
	//【题意】：给n个首脑排座（1-n），根据m条关系，理想情况下邀请
	//每一个人都是所有人的直接朋友，k种安排
	//如果每个人都是每个人的直接朋友，没有遗漏，ok
	//如果每个人都是直接朋友，且还有其他head可邀，打印最小index
	//如果area不理想, help
	//【分析】：
	int n, m, k;
	cin >>n >>m;
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a][b]=e[b][a]=1;
	}
	cin >> k;
	for (int i=1; i<=k; i++) {
		int l, fir;
		scanf("%d%d", &l, &fir);
		set<int> st;
		vector<bool> vis(n+1, false);
		st.insert(fir);
		vis[fir]=true;
		bool help=false;
		for (int j=0; j<l-1; j++) {
			int tmp;
			scanf("%d", &tmp);
			vis[tmp]=true;
			int flag=1;//flag=1表示集合内相互都是直接朋友
			for (auto it=st.begin(); it!=st.end(); it++) {
				int id=*it;
				if (e[id][tmp]==0) {
					flag=0;
					break;
				}
			}
			if (flag==1) {
				st.insert(tmp);
			} else {
				help=true;
			}
		}
		if (help==true) {
			printf("Area %d needs help.\n", i);
			continue;
		}
		int invite=-1;
		for (int j=1; j<=n; j++) {
			if (!vis[j]) {
				int flag=1;
				for (auto it : st) {
					if (e[it][j]==0) {
						flag=0;
						break;
					}
				}
				if (flag==1) {
					invite=j;
					break;
				}
			}
		}
		if (invite==-1) printf("Area %d is OK.\n", i);
		else {
			printf("Area %d may invite more people, such as %d.\n", i, invite);
		}
	}
	return 0;
}
