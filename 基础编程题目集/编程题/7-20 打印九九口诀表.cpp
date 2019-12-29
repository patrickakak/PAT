
#include <cstdio>


int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (j>i) continue;
      printf("%d*%d=%-4d", j, i, j*i);
    }
    printf("\n");
  }

  return 0;
}
