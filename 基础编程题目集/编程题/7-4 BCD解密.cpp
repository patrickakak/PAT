
#include <cstdio>

int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int a=n/16;
  int c=a*10+n%16;
  printf("%d", c);

  return 0;
}
