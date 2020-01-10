#include <iostream>
#include <vector>
using namespace std;

const int maxn = 110000;
int prime[maxn], num = 0;
bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}

int main()
{
	int m, n, cnt = 0;
	cin >> m >> n;
	for (int i = 2; i < maxn; i++)
		if (isPrime(i))
			prime[num++] = i;
	for (int i = m-1; i < n; i++) {
		cnt++;
		cout << prime[i];
		if (cnt%10 != 0 && i != n-1) cout << ' ';
		else cout << endl;
	}
	return 0;
}
