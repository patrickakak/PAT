#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string a[105];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n-1-i; j++)
			if (a[j] > a[j+1])
				swap(a[j], a[j+1]);
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}
