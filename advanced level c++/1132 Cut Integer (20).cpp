#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string z;
	while (n--) {
		cin >> z;
		int a = stoi(z.substr(0, z.length()/2));
		int b = stoi(z.substr(z.length()/2));
		if (a == 0 || b == 0) printf("No\n");
		else if (stoi(z) % (a * b) == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
