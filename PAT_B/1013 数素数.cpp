#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int m, n, cnt = 0;
	cin >> m >> n;
	vector<int> v;
	for (int num = 2; cnt < n; num++)
		if (isPrime(num)) {
			cnt++;
			if (cnt >= m) v.push_back(num);
		}
	for (int i = 0, cnt = 0; i < v.size(); i++) {
		cnt++;
		cout << v[i];
		if (cnt%10 != 0 && i != v.size()-1) cout << ' ';
		else cout << endl;
	}
	return 0;
}
