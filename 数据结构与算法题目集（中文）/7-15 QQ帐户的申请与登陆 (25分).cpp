#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node { string acc, pwd; };
int index = 1;
vector<node> v(1);
int main() {
	int n;
	cin >> n;
	string c, acc, pwd;
	unordered_map<string, int> m;
	for (int i = 0; i < n; i++) {
		cin >> c >> acc >> pwd;
		int id = m[acc];
		if (c == "L") {
			if (id == 0) printf("ERROR: Account Not Exist\n");
			else {
				if (v[id].pwd == pwd) printf("Log in Successful\n");
				else printf("ERROR: Wrong Password\n");
			}
		} else if (c == "R") {
			if (m[acc] != 0) printf("ERROR: Account Number Already Exists\n");
			else {
				v.push_back(node{acc, pwd});
				m[acc] = index++;
				printf("Register Successful\n");
			}
		}
	}
	return 0;
}
