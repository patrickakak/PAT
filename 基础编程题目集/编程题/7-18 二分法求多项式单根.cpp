
#include <cstdio>
#include <cmath>

double a3, a2, a1, a0;
double a, b;
double eps=0.001;

double cal(double x)
{
  return a3*pow(x, 3)+a2*pow(x, 2)+a1*pow(x, 1)+a0;
}

double root(double a, double b)
{
  if (b-a<eps) {
    return (a+b)/2;
  }
  double x=cal(a);// y=cal(b);
  double mid=(a+b)/2;
  double tmp = cal(mid);
  if (tmp==0) return mid;
  else if (tmp*x>0) {
    return root(mid, b);
  } else return root(a, mid);
}

int main()
{
  //freopen("tst.txt", "r", stdin);

  scanf("%lf%lf%lf%lf", &a3, &a2, &a1, &a0);
  scanf("%lf%lf", &a, &b);
  printf("%.2f", root(a, b));

  return 0;
}
