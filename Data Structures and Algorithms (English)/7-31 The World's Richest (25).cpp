#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	char name[10];
	int age, net;
};
bool cmp(node a, node b) {
	if (a.net != b.net) return a.net > b.net;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	int n, k, m, amin, amax;
	scanf("%d%d", &n, &k);
	vector<node> v(n);
	for (int i = 0; i < n; i++)
		scanf("%s%d%d", v[i].name, &v[i].age, &v[i].net);
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (v[j].age >= amin && v[j].age <= amax) {
				printf("%s %d %d\n", v[j].name, v[j].age, v[j].net);
				cnt++;
			}
			if (cnt == m) break;
		}
		if (cnt == 0) printf("None\n");
	}
	return 0;
}
