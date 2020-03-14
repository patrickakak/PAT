#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int prel, int prer, int inl, int inr) {
	if (inl > inr || flag == true) return;
	int i = inl;
	while (i <= inr && in[i] != pre[prel]) i++;
	postOrder(prel+1, prel+(i-inl), inl, i-1);
	postOrder(prel+(i-inl)+1, prer, i+1, inr);
	if (flag == false) {
		printf("%d", pre[prel]);
		flag = true;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	postOrder(0, n-1, 0, n-1);
	return 0;
}
