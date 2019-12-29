
#include <cstdio>
#include <algorithm>
using namespace std;

struct Fraction {
  int up, down;
};

int gcd(int a, int b)
{
  return !b ? a : gcd(b, a%b);
}

Fraction reduce(Fraction f)
{
  if (f.down<0) {
    f.up=-f.up;
    f.down=-f.down;
  }
  int d=gcd(abs(f.up), f.down);
  f.up/=d;
  f.down/=d;
  return f;
}

Fraction add(Fraction a, Fraction b)
{
  Fraction f;
  f.up=a.up*b.down+a.down*b.up;
  f.down=a.down*b.down;
  return reduce(f);
}

Fraction divide(Fraction a, Fraction b)
{
  Fraction f;
  f.up=a.up*b.down;
  f.down=a.down*b.up;
  return reduce(f);
}

int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  Fraction sum, t;
  sum.up=0, sum.down=1;
  for (int i=0; i<n; i++) {
    scanf("%d/%d", &t.up, &t.down);
    sum=add(sum, t);
    if (i!=n-1) {
      getchar();
    }
  }
  //if (sum%n==0) printf("%d", sum/n);
  Fraction b;
  b.up=n, b.down=1;
  Fraction f=divide(sum, b);
  if (f.down==1) printf("%d", f.up);
  else printf("%d/%d", f.up, f.down);

  return 0;
}

