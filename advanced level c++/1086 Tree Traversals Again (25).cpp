#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> pre, in, post;
void postOrder(int prel, int prer, int inl, int inr) {
	if (inl > inr) return;
	int i = inl;
	while (i <= inr && in[i] != pre[prel]) i++;
	postOrder(prel+1, prel+(i-inl), inl, i-1);
	postOrder(prel+1+(i-inl), prer, i+1, inr);
	post.push_back(pre[prel]);
}
int main() {
	int n, index;
	cin >> n;
	string s;
	stack<int> st;
	while (cin >> s)
		if (s.length() == 4) {
			cin >> index;
			pre.push_back(index);
			st.push(index);
		} else {
			in.push_back(st.top());
			st.pop();
		}
	postOrder(0, n-1, 0, n-1);
	for (int i = 0; i < post.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", post[i]);
	}
	return 0;
}
