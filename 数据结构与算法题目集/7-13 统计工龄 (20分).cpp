#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int age, h[51] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &age);
		h[age]++;
	}
	for (int i = 0; i < 51; i++)
		if (h[i] != 0) printf("%d:%d\n", i, h[i]);
	return 0;
}
