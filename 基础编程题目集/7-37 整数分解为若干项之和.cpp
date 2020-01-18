
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int sum=0, cnt=0;
void factorization(int i, int n)
{
  if (sum==n) {
    cnt++;
    cout << n << "=";
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end()-1; it++) {
      cout << *it << "+";
    }
    cout << *it;
    if (cnt%4==0 || v[v.size()-1]==n) {
      cout << endl;
    } else {
      cout << ";";
    }
    return;
  }
  if (sum>n) return;
  // j starts from i to make sure sequence in incresing order
  for (int j=i; j<=n; j++) {
    sum+=j;
    v.push_back(j);
    factorization(j, n);
    sum-=j;
    v.pop_back();
  }
}

int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  cin >> n;
  factorization(1, n);

  return 0;
}



