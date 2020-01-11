#include <iostream>
#include <algorithm>
using namespace std;
char ch[] = {'B','C','J'};
int main() {
	int n, wina = 0, winb = 0, total = 0, cnta[3] = {0}, cntb[3] = {0};
	cin >> n;
	char a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 'B' && b == 'C') {
			wina++;
			cnta[0]++;
		} else if (a == 'B' && b == 'J') {
			winb++;
			cntb[2]++;
		} else if (a == 'C' && b == 'J') {
			wina++;
			cnta[1]++;
		} else if (a == 'C'&& b == 'B') {
			winb++;
			cntb[0]++;
		} else if (a == 'J' && b == 'B') {
			wina++;
			cnta[2]++;
		} else if (a == 'J' && b == 'C') {
			winb++;
			cntb[1]++;
		}
		total++;
	}
	int tie = total - wina - winb;
	cout << wina << ' ' << tie << ' ' << total-wina-tie << endl;
	cout << winb << ' ' << tie << ' ' << total-winb-tie << endl;
	cout << ch[max_element(cnta, cnta+3)-cnta] << ' ' << ch[max_element(cntb, cntb+3)-cntb];
	return 0;
}
