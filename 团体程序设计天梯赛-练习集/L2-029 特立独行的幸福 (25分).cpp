#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
vector<int> h(10010), cnt(10010, 1);
bool isprime(int n) {
	if (n < 2) return false;
	int sqr = sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	int a, b;
	cin >> a >> b;
	map<int, int> m;
	for (int i = a; i <= b; i++) {
		int tmp = i;
		fill(h.begin(), h.end(), 0);
		while (1) {
			string s = to_string(tmp);
			int sum = 0;
			for (int j = 0; j < s.length(); j++)
				sum += (s[j]-'0') * (s[j]-'0');
			if (sum == 1) {
				m[i] = 1;
				break;
			} else {
				if (h[sum] == 1) break;
				h[sum] = 1;
			}
			tmp = sum;
		}
	}
	for (auto i : m) {
		int tmp = i.first;
		fill(h.begin(), h.end(), 0);
		while (1) {
			string s = to_string(tmp);
			int sum = 0;
			for (int j = 0; j < s.length(); j++)
				sum += (s[j]-'0') * (s[j]-'0');
			if (sum == 1) {
				if (isprime(i.first)) cnt[i.first] *= 2;
				break;
			} else {
				if (h[sum] == 1) break;
				h[sum] = 1;
				if (m.find(sum) != m.end()) m.erase(sum);
				cnt[i.first]++;
			}
			tmp = sum;
		}
	}
	if (m.size() == 0) printf("SAD\n");
	else for (auto i : m) printf("%d %d\n", i.first, cnt[i.first]);
	return 0;
}
