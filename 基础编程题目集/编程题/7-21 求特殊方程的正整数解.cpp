
#include <cstdio>


int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int cnt=0;
  for (int x=1; 2*x*x<=n; x++) {
    for (int y=x; x*x+y*y<=n; y++) {
      if (x*x+y*y==n) {
        printf("%d %d\n", x, y);
        cnt++;
      }
    }
  }
  if (cnt==0) printf("No Solution");

  return 0;
}
