#include <iostream>
using namespace std;
const int maxn = 55;
int gender[maxn];
bool hashTbl[maxn] = {false};
string s[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> gender[i] >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = n-1; j >= i; j--)
			if (hashTbl[j] == false && gender[i]+gender[j] == 1) {
				cout << s[i] << " " << s[j] << endl;
				hashTbl[i] = hashTbl[j] = true;
				break;
			}
	return 0;
}
