
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  //freopen("tst.txt", "r", stdin);
  string s;
  int n;
  //cin >> s >> n;
  getline(cin, s);
  cin >> n;
  int len=s.length();
  if (n>len) {
    n=n%len;
  }
  reverse(s.begin(), s.begin()+n);
  reverse(s.begin()+n, s.end());
  reverse(s.begin(), s.end());
  cout << s;

  return 0;
}

