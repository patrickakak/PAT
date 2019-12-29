
#include <cstdio>

int main()
{
  //freopen("tst.txt", "r", stdin);

  int n;
  scanf("%d", &n);
  int f, y;
  int flag=0;
  for (f=0; f<100; f++) {
    for (y=0; y<100; y++) {
      if (100*f+y-n==200*y+2*f) {
        flag=1;
        break;
      }
    }
    if (flag==1)
      break;
  }
  if (flag==1) printf("%d.%d", y, f);
  else printf("No Solution");

  return 0;
}
