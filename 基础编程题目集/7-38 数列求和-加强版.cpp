
#include <cstdio>
#include <stack>
using namespace std;

stack<int> st;
int main()
{
  //freopen("tst.txt", "r", stdin);
  int a, n;
  scanf("%d%d", &a, &n);
  int carry=0;
  for (int i=0; i<n; i++) {
    int t=(n-i)*a+carry;
    st.push(t%10);
    carry=t/10;
  }
  if (n==0) {
    printf("0");
    return 0;
  }
  if (carry!=0) st.push(carry);
  while (!st.empty()) {
    int t=st.top();
    st.pop();
    printf("%d", t);
  }

  return 0;
}

