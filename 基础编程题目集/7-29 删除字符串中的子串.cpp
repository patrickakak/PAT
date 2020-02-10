#include <iostream>
using namespace std;
int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  int len2 = s2.length();
  while (1) {
    int p = s1.find(s2);
    if (p != -1) s1.erase(p, len2);
    else break;
  }
  cout << s1;
  return 0;
}
