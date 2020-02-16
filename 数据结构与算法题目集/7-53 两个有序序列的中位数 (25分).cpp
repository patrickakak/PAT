#include <iostream>
#include <algorithm>
using namespace std;  
int n, a[200010];    
int main() {  
	scanf("%d", &n);  
	for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
	sort(a, a + 2*n);  
	printf("%d\n", a[n-1]);  
	return 0;  
}
