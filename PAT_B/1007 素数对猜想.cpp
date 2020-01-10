#include <iostream>
using namespace std;
const int maxn = 100010;
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
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i <= n; i++)
		if (isPrime(i)) prime[num++] = i;
	for (int i = 1; i < num; i++)
		if (prime[i]-prime[i-1] == 2) cnt++;
	cout << cnt;
	return 0;
}
