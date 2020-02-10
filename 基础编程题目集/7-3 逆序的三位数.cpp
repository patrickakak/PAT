#include<iostream>
using namespace std;
int main(){
	int a, bai, shi, ge, t;
	scanf("%d", &a);
	ge = a / 100;
	t = a % 100;
	shi = t / 10;
	bai = t % 10;
	printf("%d", bai * 100 + shi * 10 + ge);
}
