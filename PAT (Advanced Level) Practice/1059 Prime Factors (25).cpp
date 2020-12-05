#include <iostream>
#include <vector>
using namespace std;
struct node {
	long long p, k;
};
vector<node> v;
vector<bool> prime(50000, true);
int main() {
	for (int i = 2; i*i < 50000; i++)
		for (int j = 2; j*i < 50000; j++)
			prime[j*i] = false;
	long long n, t;
	cin >> n;
	printf("%lld=", n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	t = n;
	for (int i = 2; i*i <= n; i++)
		if (prime[i] == true && t%i == 0) {
			int cnt = 0;
			while (t%i == 0) {
				cnt++;
				t /= i;
			}
			v.push_back(node{i, cnt});
		}
	if (t != 1) v.push_back(node{t, 1});
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) printf("*");
		printf("%lld", v[i].p);
		if (v[i].k > 1) printf("^%lld", v[i].k);
	}
	return 0;
}
