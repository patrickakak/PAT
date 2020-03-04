#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <math.h>
#define maxsize 10000
using namespace std;
struct Node {
	string add, next;
	int v;
};
int n;
string firstL1, firstL2;
unordered_map<string, Node> l;
vector<Node> l1, l2, out;
void comu(vector<Node> a, vector<Node> b) {
	int j = b.size() - 1;
	for (int i = 0; i < b.size(); i++, j--) {
		if (i >= j) break;
		swap(b[i], b[j]);
	}
	for (int i = a.size() - 1; i >= 0; i--) {
		j = i + 1;
		if (j <= (2 * b.size())) {
			out.push_back(b[b.size() - 1]);
			b.pop_back();
		}
		out.push_back(a[i]);
	}
}
int main() {
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> firstL1 >> firstL2 >> n;
	string a, b;
	int v;
	Node tmpNode;
	for (int i = 0; i < n; i++) {
		cin >> tmpNode.add >> tmpNode.v >> tmpNode.next;
		l.insert(make_pair(tmpNode.add, tmpNode));
	}
	a = firstL1;
	while (l.find(a) != l.end()) {
		tmpNode = l.find(a)->second;
		l1.push_back(tmpNode);
		if (tmpNode.next == "-1")
			break;
		a = tmpNode.next;
	}
	a = firstL2;
	while (l.find(a) != l.end()) {
		tmpNode = l.find(a)->second;
		l2.push_back(tmpNode);
		if (tmpNode.next == "-1")
			break;
		a = tmpNode.next;
	}
	int s1 = l1.size(), s2 = l2.size();
	if (s1 >= (2 * s2))
		comu(l1, l2);
	else
		comu(l2, l1);
	for (int i = out.size() - 1; i >= 1; i--)
		cout << out[i].add << " " << out[i].v << " " << out[i - 1].add << endl;
	cout << out[0].add << " " << out[0].v << " " << -1 << endl;
	return 0;
}
