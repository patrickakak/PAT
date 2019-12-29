
#include <cstdio>
// #include <windows.h>

bool hashTbl[1005]={false};

int main()
{
  //freopen("tst.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int left=n;
  int cnt=0;
  int flag=0;
  while (1) {
    for (int i=1; i<=n; i++) {
      if (hashTbl[i]==true) {
        continue;
      }
      cnt++;
      if (cnt==3) {
        left--;
        //Sleep(1000);
        //printf("left=%d\n", left);
        cnt=0;
        hashTbl[i]=true;
      }
      if (left==1) {
        flag=1;
        break;
      }
    }
    if (flag==1) {
      break;
    }
  }
  for (int i=1; i<=n; i++) {
    if (hashTbl[i]==false) {
      printf("%d", i);
      break;
    }
  }

  return 0;
}

