#include <iostream>
using namespace std;
int main() {
	string num;
	cin >> num;
	double factor;
	int left, len = num.length();
	int length = len;
	if (num[0] == '-') {
		factor = 1.5;
		left = 1;
		length--;
	} else {
		factor = 1.0;
		left = 0;
	}
	int cnt = 0;
	for (int i = left; i < len; i++)
		if (num[i] == '2') cnt++;
	int t = num[len-1] - '0';
	if (t%2 == 0) factor *= 2.0;
	printf("%.2f%%\n", 100*factor*cnt/length);
	return 0;
}
