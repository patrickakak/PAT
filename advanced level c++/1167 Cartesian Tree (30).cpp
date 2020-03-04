#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int> mp;
vector<int> in;
void inorder(int inl, int inr, int num) {
	if (inl>inr) return;
	int minp=min_element(in.begin()+inl, in.begin()+inr+1)-(in.begin()+inl);
	int minn=in[inl+minp];
	mp[minn]=num;
	inorder(inl, inl+minp-1, 2*num);
	inorder(inl+minp+1, inr, 2*num+1);
}
bool cmp(int a, int b) {
	return mp[a]<mp[b];
}
int main() {
	//【题意】：Cartesian二叉树中序为原序列，且为最小堆，输出层序
	//【分析】：递归，中序的根是最小值
	//sort下先，
	int n;
	cin >>n;
	in.resize(n);
	for (int i=0; i<n; i++) scanf("%d", &in[i]);
	inorder(0, n-1, 1);
	sort(in.begin(), in.end(), cmp);
	for (int i=0; i<n; i++) {
		if (i!=0) printf(" ");
		printf("%d", in[i]);
	}
	return 0;
}
