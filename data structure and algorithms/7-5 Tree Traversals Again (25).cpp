#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> pre, in, post;
void postorder(int root, int start, int end) {
	if (start > end) return;
	int i = start;
	while (i <= end && in[i] != pre[root]) i++;
	postorder(root + 1, start, i - 1);
	postorder(root + i - start + 1, i + 1, end);
	post.push_back(pre[root]);
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
	postorder(0, 0, n - 1);
	for (int i = 0; i < post.size(); i++) {
		if (i != 0) cout << ' ';
		cout << post[i];
	}
	return 0;
}
