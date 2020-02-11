#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int sum = 0, cnt = 0;
void factorization(int i, int n) {
	if (sum > n) return;
	if (sum == n) {
		cout << n << "=";
		for (int i = 0; i < v.size(); i++) {
			if (i != 0) printf("+");
			printf("%d", v[i]);
		}
		if (++cnt % 4 == 0 || v[v.size()-1] == n) cout << endl;
		else cout << ";";
		return;
	}
	for (int j = i; j <= n; j++) {
		sum += j;
		v.push_back(j);
		factorization(j, n);
		sum -= j;
		v.pop_back();
	}
}
int main() {
	int n;
	cin >> n;
	factorization(1, n);
	return 0;
}
