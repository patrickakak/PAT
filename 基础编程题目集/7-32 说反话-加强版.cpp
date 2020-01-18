
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
  //freopen("tst.txt", "r", stdin);
  string s;
  getline(cin, s);
  while (s[0] && s[0]==' ') {
    s.erase(s.begin(), s.begin()+1);
  }
  reverse(s.begin(), s.end());
  while (s[0] && s[0]==' ') {
    s.erase(s.begin(), s.begin()+1);
  }
  int len=s.length();
  //cout << "s=" << s << "..." << endl;
  int flag=0;
  int cnt=0;
  int left=0;
  for (int i=0; i<len; i++) {
    if (cnt==0) {
      left=i;
    }
    if (s[i]!=' ') {
      cnt++;
    }
    if (s[i]==' ' && cnt!=0) {
      reverse(s.begin()+left, s.begin()+i);
      if (flag==0) {
        flag=1;
      } else {
        cout << " ";
      }
      cout << s.substr(left, i-left);
      cnt=0;
    }
  }
  reverse(s.begin()+left, s.end());
  if (left!=0)
    cout << " ";
  cout << s.substr(left);

  return 0;
}

