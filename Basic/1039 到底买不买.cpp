#include <iostream>
using namespace std;
int amt[260];
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
		amt[a[i]]++;
	int res = 0;
	for (int i = 0; i < b.length(); i++)
		if (amt[b[i]] > 0) amt[b[i]]--;
		else res++;
	if (res != 0) cout << "No " << res;
	else cout << "Yes " << a.length() - b.length();
	return 0;
}
