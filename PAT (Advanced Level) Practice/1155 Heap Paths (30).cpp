#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int a[1010], n, isMin = 1, isMax = 1;
void dfs(int idx) {
	v.push_back(a[idx]);
	if (2 * idx > n) {	
		for (int i = 0; i < v.size(); i++)
			printf("%d%s", v[i], i != v.size()-1 ? " " : "\n");
		v.pop_back();
		return;
	}
	if (2 * idx + 1 <= n) dfs(2 * idx + 1);
	if (2 * idx <= n) dfs(2 * idx);
	v.pop_back();
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (a[i/2] > a[i]) isMin = 0;
		if (a[i/2] < a[i]) isMax = 0;
	}
	if (isMin == 1) printf("Min Heap");
	else printf("%s", isMax == 1 ? "Max Heap" : "Not Heap"); 
	return 0;
}
