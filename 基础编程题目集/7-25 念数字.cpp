
#include <cstdio>
#include <iostream>
using namespace std;

char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
  //freopen("tst.txt", "r", stdin);
  string s;
  cin >> s;
  int l=0;
  int len=s.length();
  if (s[0]=='-') {
    cout << "fu ";
    l=1;
  }
  for (int i=l; i<len; i++) {
    int tmp=s[i]-'0';
    if (i!=l)
      cout << " ";
    cout << num[tmp];
  }

  return 0;
}

