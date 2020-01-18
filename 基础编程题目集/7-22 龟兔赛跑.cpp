
#include <cstdio>

int main()
{
  //freopen("tst.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  int turtle=0, hare=0;
  int timer=0;
  int rest=0;
  while (t--) {
    if (timer==10 && rest<=0) {
      if (hare>turtle) {
        rest=30;
      }
      timer=0;
    }
    turtle+=3;
    if (rest<=0) {
      hare+=9;
      timer++;
    } else {
      rest--;
    }
  }
  if (turtle>hare) printf("@_@ %d", turtle);
  else if (turtle<hare) printf("^_^ %d", hare);
  else printf("-_- %d", turtle);

  return 0;
}
