#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	map<int, int> m, pos;
	for (int i = 0; i < s.length(); i++)
		m[s[i]-'0']++;
	printf("int[] arr = new int[]{");
	vector<int> v;
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		if (it != m.rbegin()) printf(",");
		printf("%d", it->first);
		pos[it->first] = v.size();
		v.push_back(it->first);
	}
	printf("};\nint[] index = new int[]{");
	for (int i = 0; i < s.length(); i++) {
		if (i != 0) printf(",");
		printf("%d", pos[s[i]-'0']);
	}
	printf("};\n");
	return 0;
}
