#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	int leftindex = 0, rightindex = n - 1, sum = -1, tmp = 0, tmpindex = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		tmp += v[i];
		if (tmp < 0) {
			tmp = 0;
			tmpindex = i + 1;
		} else if (tmp > sum) {
			sum = tmp;
			leftindex = tmpindex;
			rightindex = i;
		}
	}
	if (sum < 0) sum = 0;
	printf("%d %d %d", sum, v[leftindex], v[rightindex]);
	return 0;
}
