#include <iostream>
using namespace std;
int h[10010], a[100010], n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		h[a[i]]++;
	}
	for (int i = 0; i < n; i++)
		if (h[a[i]] == 1) {
			printf("%d", a[i]);
			return 0;
		}
	printf("None");
	return 0;
}
