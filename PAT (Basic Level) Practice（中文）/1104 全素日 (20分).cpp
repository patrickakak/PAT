#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	long long n;
	scanf("%lld", &n);
	string s = to_string(n);
	s.insert(0, 8-s.length(), '0');
	int flag = 0;
	while (s.length() > 0) {
		long long tmp = stoll(s);
		if (isprime(tmp)) cout << s << " Yes" << endl;
		else {
			cout << s << " No" << endl;
			flag = 1;
		}
		s.erase(0, 1);
	}
	if (flag == 0) printf("All Prime!\n");
	return 0;
}
