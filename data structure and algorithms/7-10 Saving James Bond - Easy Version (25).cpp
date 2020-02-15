#include <iostream>
#include <cmath>
using namespace std;
struct node {
	double x, y;
} c[110];
int n;
double d;
bool visit[110];
bool firJump(int v) { return (d + 7.5) * (d + 7.5) >= c[v].x * c[v].x + c[v].y * c[v].y; }
bool jump(int a, int b) { return d * d >= pow(c[a].x-c[b].x, 2) + pow(c[a].y-c[b].y, 2); }
bool isSafe(int v) { return (fabs(c[v].x) + d >= 50) || (fabs(c[v].y) + d >= 50); }
bool dfs(int v) {
	visit[v] = true;
	if (isSafe(v)) return true;
	for (int i = 0; i < n; i++)
		if (!visit[i] && jump(v, i) && dfs(i) == true)
			return true;
	return false;
}
int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) cin >> c[i].x >> c[i].y;
	bool ans = false;
	for (int i = 0; i < n; i++)
		if (!visit[i] && firJump(i)) {
			ans = dfs(i);
			if (ans == true) break;
		}
	if (ans == true) printf("Yes");
	else printf("No");
	return 0;
}
