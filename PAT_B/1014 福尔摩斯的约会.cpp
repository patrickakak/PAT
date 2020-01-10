#include <iostream>
#include <cctype>
using namespace std;
string days[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int i = 0, j = 0;
	while (i < a.length() && i < b.length()) {
		if (a[i] == b[i] && a[i]>='A' && a[i]<='G') {
			cout << days[a[i]-'A'] << ' ';
			break;
		}
		i++;
	}
	i += 1;
	while (i < a.length() && i < b.length()) {
		if (a[i] == b[i] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N'))) {
			printf("%02d:", isdigit(a[i]) ? a[i] - '0' : a[i] - 'A' + 10);
			break;
		}
		i++;
	}
	while (j < c.length() && j < d.length()) {
		if (c[j] == d[j] && isalpha(c[j])) {
			printf("%02d", j);
			break;
		}
		j++;
	}
	return 0;
}
