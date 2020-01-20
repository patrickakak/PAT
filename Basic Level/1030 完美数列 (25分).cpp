#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	long n, p;
	cin >> n >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int len = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + len; j < n; j++)
			if (v[j] <= v[i] * p) len++;
			else break;
	cout << len;
	return 0;
}
