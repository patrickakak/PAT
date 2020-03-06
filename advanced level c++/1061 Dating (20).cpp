#include <iostream>
using namespace std;
string days[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int i = 0, j = 0;
	for ( ; i < min(a.length(), b.length()); i++)
		if (a[i] == b[i] && a[i]>='A' && a[i]<='G') {
			printf("%s ", days[a[i]-'A'].c_str());
			break;
		}
	i += 1;
	for ( ; i < min(a.length(), b.length()); i++)
		if (a[i] == b[i] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N'))) {
			printf("%02d:", isdigit(a[i]) ? a[i] - '0' : a[i] - 'A' + 10);
			break;
		}
	for ( ; j < min(c.length(), d.length()); j++)
		if (c[j] == d[j] && isalpha(c[j])) {
			printf("%02d", j);
			break;
		}
	return 0;
}
