#include <iostream>
using namespace std;

int main()
{
	int n, a[3] = {0}, i = 0;
	cin >> n;
	while (n != 0) {
		a[i++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < a[2]; i++) cout << 'B';
	for (int i = 0; i < a[1]; i++) cout << 'S';
	for (int i = 0; i < a[0]; i++) cout << i+1;
	return 0;
}
