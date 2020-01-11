#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b, ra, rb;
	char da, db;
	cin >> a >> da >> b >> db;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == da) ra += da;
	for (int j = 0; j < b.length(); j++)
		if (b[j] == db) rb += db;
	int x = 0, y = 0;
	if (ra != "") x = stoi(ra);
	if (rb != "") y = stoi(rb);
	cout << x + y;
	return 0;
}
