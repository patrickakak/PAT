#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[110], nums[110];
bool cmp(int a, int b) { return a > b; }
int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		nums[i] = n;
		while (n != 1) {
			if (n > 1 && n <= 100) cnt[n]++;
			if (n % 2 != 0) n = 3 * n + 1;
			n /= 2;
		}
	}
	vector<int> v;
	for (int i = 0; i < k; i++)
		if (cnt[nums[i]] == 1) v.push_back(nums[i]);
	sort(begin(v), end(v), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size()-1) cout << ' ';
	}
	return 0;
}
