#include <iostream>
using namespace std;
int main() {
	int m, n, k;
	cin >> m;
	while (m--) {
		cin >> k;
		for (n = 1; n < 10; n++) {
			int mul = n * k * k;
			string smul = to_string(mul), sk = to_string(k);
			string smulend = smul.substr(smul.length() - sk.length());
			if (smulend == sk) {
				printf("%d %d\n", n, mul);
				break;
			}
		}
		if (n == 10) printf("No\n");
	}
	return 0;
}
