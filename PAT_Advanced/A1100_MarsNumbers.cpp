/**
 * Sample input:
 * 4
 * 29
 * 5
 * elo nov
 * tam
 * ------------
 * Sample output:
 * hel mar
 * may
 * 115
 * 13
 */
#include <cstdio>
#include <map>  // red-black tree
#include <iostream>
#include <string>
using namespace std;

// 0~12 in martian radix
string unit[13] = {"tret", "jan", "feb", "mar", "apr", "may", 
                   "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string ten[13] = {"tret", "tam", "hel", "maa", "huh", "tou", 
                  "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string num2Str[170];
map<string, int> str2Num;

void init()
{
	for (int i = 0; i < 13; i++) {
		num2Str[i] = unit[i];
		str2Num[unit[i]] = i;
		num2Str[i*13] = ten[i];
		str2Num[ten[i]] = i * 13;
	}
	for (int i = 1; i < 13; i++)
		for (int j = 1; j < 13; j++) {
			string str = ten[i] + " " + unit[j];
			num2Str[i*13 + j] = str;
			str2Num[str] = i*13 + j;
		}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int T;

	init();
	scanf("%d%*c", &T);
	while (T--) {
		string str;
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			int num = 0;
			for (int i = 0; i < (int)str.length(); i++)
				num = num*10 + (str[i]-'0');
			cout << num2Str[num] << endl;
		} else {
			string s1, s2;
			int k = str.find(' ');
			if (k != -1) {
				s1 = str.substr(0, k);
				s2 = str.substr(k+1, str.length()+1);
				cout << str2Num[s1] + str2Num[s2] << endl;
			} else
				cout << str2Num[str] << endl;
		}
	}

	return 0;
}


