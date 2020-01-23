#include <iostream>
using namespace std;
int main() {
	int cnt, start[55], end[55], scan[55];
	scanf("%d", &cnt);
	for (int i = 1; i <= 54; i++) {
		scanf("%d", &scan[i]);
		end[i] = i;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= 54; j++)
			start[j] = end[j];
		for (int k = 1; k <= 54; k++)
			end[scan[k]] = start[k];
	}
	string c = "SHCDJ";
	for (int i = 1; i <= 54; i++) {
		end[i] = end[i] - 1;
		printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
		if (i != 54) printf(" ");
	}
	return 0;
}
