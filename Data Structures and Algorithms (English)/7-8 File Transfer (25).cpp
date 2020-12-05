#include <iostream>
using namespace std;
int n, father[10010];
int find(int x) {
	int a = x;
	while (father[x] != x) x = father[x];
	while (father[a] != a) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA != faB) father[faA] = faB;
}
void check() {
	int a, b;
	cin >> a >> b;
	if (find(a) == find(b)) printf("yes\n");
	else printf("no\n");
}
void connect() {
	int a, b;
	cin >> a >> b;
	Union(a, b);
}
void stop() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (father[i] == i) cnt++;
	if (cnt == 1) printf("The network is connected.");
	else printf("There are %d components.", cnt);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) father[i] = i;
	char c;
	while (cin >> c)
		switch (c) {
		case 'C': check();   break;
		case 'I': connect(); break;
		case 'S': stop();    break;
		}
	return 0;
}
