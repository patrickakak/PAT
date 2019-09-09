/**
 * Sample input1:
 * 3 12300 12358.9
 * Sample output1:
 * YES 0.123*10^5
 * --------------
 * Sample input2:
 * 3 120 128
 * Sample output2:
 * NO 0.120*10^3 0.128*10^3
 */
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int n;
string deal(string s, int &e)
{
	int k = 0;

	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());
	// delete '0' and '.' in string s
	if (s[0] == '.') {		// less than 1: 0.xxxx
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--;
		}
	} else {				// larger than 1: xxx.xxxx
		while (k < (int)s.length() && s[k] != '.') {
			k++;
			e++;
		}
		if (k < (int)s.length())
			s.erase(s.begin() + k);
	}
	if (s.length() == 0)	// get rid of strings like 000.000
		e = 0;
	k = 0;
	string res;
	int num = 0;
	while (num < n) {
		if (k < (int)s.length())
			res += s[k++];
		else
			res += '0';		// add effective digits
		num++;
	}
	return res;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if (s3 == s4 && e1 == e2)
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	else
		cout << "NO 0." << s3 << "*10^" << e1 
			<< " 0." << s4 << "*10^" << e2 << endl;
	return 0;
}


