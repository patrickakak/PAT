
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  //freopen("tst.txt", "r", stdin);
  int n, k;
  int a[105];
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i=0; i<k; i++) {
    for (int j=0; j<n-i-1; j++) {
      if (a[j+1]<a[j]) {
        swap(a[j], a[j+1]);
      }
    }
  }
  for (int i=0; i<n; i++) {
    if (i>0) printf(" ");
    printf("%d", a[i]);
  }

  return 0;
}

