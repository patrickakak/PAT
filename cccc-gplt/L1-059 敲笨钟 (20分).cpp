#include <iostream>
using namespace std;
int main() {
	int n;
	string s;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int flg = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ',' && j-3 >= 0 && s.substr(j-3, 3) == "ong") flg++;
			if (s[j] == '.' && j-3 >= 0 && s.substr(j-3, 3) == "ong") flg++;
		}
		if (flg != 2) printf("Skipped\n");
		else {
			int bcnt = 0, j = s.length()-1;
			for (; j >= 0; j--)
				if (s[j] == ' ') {
					bcnt++;	
					if (bcnt == 3) break;
				}
			s.replace(s.begin()+j, s.end(), " qiao ben zhong.");
			cout << s << endl;
		}
	}
	return 0;
}
