
#include <cstdio>
#include <cmath>

struct Complex {
  double a, b;
};

void show(Complex c1, Complex c2, char op)
{
  printf("(%.1f", c1.a);
  if (c1.b>=0) {
    printf("+");
  }
  printf("%.1fi) %c (%.1f", c1.b, op, c2.a);
  if (c2.b>=0) {
    printf("+");
  }
  printf("%.1fi) = ", c2.b);
  Complex c;
  switch (op) {
  case '+':
    c.a=c1.a+c2.a;
    c.b=c1.b+c2.b;
    break;
  case '-':
    c.a=c1.a-c2.a;
    c.b=c1.b-c2.b;
    break;
  case '*':
    c.a=c1.a*c2.a-c1.b*c2.b;
    c.b=c1.a*c2.b+c2.a*c1.b;
    break;
  case '/':
    c.a=(c1.a*c2.a+c1.b*c2.b)/(c2.a*c2.a+c2.b*c2.b);
    c.b=(-c1.a*c2.b+c2.a*c1.b)/(c2.a*c2.a+c2.b*c2.b);
    break;
  }
  if (fabs(c.a)<0.1 && fabs(c.b)<0.1) printf("0.0\n");
  else if (fabs(c.a)<0.1) {
    printf("%.1fi\n", c.b);
  } else if (fabs(c.b)<0.1) {
    printf("%.1f\n", c.a);
  } else {
    printf("%.1f", c.a);
    if (c.b>0) {
      printf("+");
    }
    printf("%.1fi\n", c.b);
  }
}

int main()
{
  //freopen("tst.txt", "r", stdin);
  Complex c1, c2;
  scanf("%lf%lf%lf%lf", &c1.a, &c1.b, &c2.a, &c2.b);
  show(c1, c2, '+');
  show(c1, c2, '-');
  show(c1, c2, '*');
  show(c1, c2, '/');

  return 0;
}

