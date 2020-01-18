
#include <cstdio>

int main()
{
  //freopen("tst.txt", "r", stdin);
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a==b) printf("C");
  else if (a==c) printf("B");
  else printf("A");

  return 0;
}
