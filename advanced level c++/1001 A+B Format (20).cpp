#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if (sum < 0) printf("-");
	string s = to_string(abs(sum));
	for (int i = 0; i < s.length(); i++) {
		if ((s.length()-1-i+1) % 3 == 0 && i != s.length()-1 && i != 0) printf(",");
		printf("%c", s[i]);
	}
	return 0;
}
