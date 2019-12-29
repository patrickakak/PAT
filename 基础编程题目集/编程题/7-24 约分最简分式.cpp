
#include <cstdio>

struct Fraction {
  int up, down;
};

int gcd(int a, int b)
{
  return b==0 ? a : gcd(b, a%b);
}

Fraction reduction(Fraction f)
{
  int d=gcd(f.up, f.down);
  f.up/=d;
  f.down/=d;
  return f;
}

int main()
{
  //freopen("tst.txt", "r", stdin);
  Fraction f;
  scanf("%d/%d", &f.up, &f.down);
  f=reduction(f);
  printf("%d/%d", f.up, f.down);

  return 0;
}

