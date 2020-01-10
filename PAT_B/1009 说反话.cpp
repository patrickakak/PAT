#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<string> z;
	string w;
	while (cin >> w) z.push(w);
	while (!z.empty()) {
		cout << z.top();
		z.pop();
		if (z.size() != 0) cout << ' ';
	}
	return 0;
}
