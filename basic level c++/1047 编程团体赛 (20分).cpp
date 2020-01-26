#include <iostream>
#include <algorithm>
using namespace std;
int team[10010];
int main() {
	int n, tid, id, score;
	cin >> n;
	for (int i = 0; i<n; i++) {
		scanf("%d-%d %d", &tid, &id, &score);
		team[tid] += score;
	}
	int p = max_element(team, team + 10010) - team;
	cout << p << ' ' << team[p];
	return 0;
}
