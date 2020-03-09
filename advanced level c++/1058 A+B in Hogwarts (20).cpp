#include <iostream>
using namespace std;
int main() {
	long long g1, g2, s1, s2, k1, k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
	long long sum = g1*17*29 + s1*29 + k1 + g2*17*29 + s2*29 + k2;
	printf("%lld.%lld.%lld", sum/29/17, sum/29%17, sum%29);
	return 0;
}
