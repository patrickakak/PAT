#include <iostream>
using namespace std;
int main() {
	string a, b, ra, rb;
	char da, db;
	cin >> a >> da >> b >> db;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == da) ra += da;
	for (int j = 0; j < b.length(); j++)
		if (b[j] == db) rb += db;
	int pa = 0, pb = 0;
	if (ra != "") pa = stoi(ra);
	if (rb != "") pb = stoi(rb);
	cout << pa + pb;
	return 0;
}
