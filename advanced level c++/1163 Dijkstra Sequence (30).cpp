#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <math.h>
#define maxsize 1002
#define INF 99999999
using namespace std;
int n, m, matrx[maxsize][maxsize] = {0}, d[maxsize];
bool vis[maxsize] = {false};
vector<int> now;
void check() {
	fill(d + 1, d + 1 + n, INF);
	fill(vis + 1, vis + 1 + n, false);
	d[now[0]] = 0;
	set<int> tmp;
	int index = 0;
	for (int i = 0; i < n; i++) {
		int u, mini = INF;
		for (int j = 1; j <= n; j++)
			if (vis[j] == false) {
				if (d[j] < mini) {
					mini = d[j];
					tmp.clear();
					tmp.insert(j);
				}
				else if (d[j] == mini)
					tmp.insert(j);
			}
		if (tmp.find(now[index]) != tmp.end()) {
			vis[now[index]] = true;
			u = now[index];
			tmp.clear();
		} else {
			cout << "No" << endl;
			return;
		}
		for (int j = 1; j <= n; j++)
			if (vis[j] == false && matrx[u][j] != 0 && d[j] > d[u] + matrx[u][j])
				d[j] = d[u] + matrx[u][j];
		index++;
	}
	cout << "Yes" << endl;
}
int main() {
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		matrx[a][b] = matrx[b][a] = c;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		now.clear();
		for (int j = 0; j < n; j++) {
			cin >> a;
			now.push_back(a);
		}
		check();
	}
	return 0;
}
