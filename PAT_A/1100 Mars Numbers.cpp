
#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

string ge[15] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string shi[15] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string num2str[170];
map<string, int> mp;

string getMarsNum(int n)
{
	string ret;
	int q = n/13, r = n%13;
	if (q != 0) ret += shi[q];
	if (q != 0 && r == 0) ;
	else if (q == 0) ret += ge[r];
	else {
		ret += " ";
		ret += ge[r];
	}
	return ret;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	string tmp;

	for (int i = 0; i < 169; i++) {
		tmp = getMarsNum(i);
		num2str[i] = tmp;
		mp.insert(make_pair(tmp, i));
	}
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, tmp);
		if (isalpha(tmp[0])) cout << mp[tmp] << endl;
		else cout << num2str[stoi(tmp)] << endl;
	}

	return 0;
}

