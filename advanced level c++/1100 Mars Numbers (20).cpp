#include <iostream>
#include <unordered_map>
using namespace std;
string a[] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string b[] = {"####","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int main() {
	int n;
	scanf("%d\n", &n);
	unordered_map<string, int> m2e;
	unordered_map<int, string> e2m;
	for (int i = 0; i < 169; i++) {
		string s;
		if (i/13 != 0) s += b[i/13];
		if (i%13 != 0) {
			if (i/13 != 0) s += " ";
			s += a[i%13];
		}
		e2m[i] = s, m2e[s] = i;
		if (i == 0) {
			e2m[0] = "tret";
			m2e["tret"] = 0;
		}
	}
	while (n--) {
		string s;
		getline(cin, s);
		if (isdigit(s[0])) printf("%s\n", e2m[stoi(s)].c_str());
		else printf("%d\n", m2e[s]);
	}
	return 0;
}
