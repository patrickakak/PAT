#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
	string uni;
	int tws, ns;
};
bool cmp(node &a, node &b) {
	if (a.tws != b.tws) return a.tws > b.tws;
	else if (a.ns != b.ns) return a.ns < b.ns;
	else return a.uni < b.uni;
}
int main() {
	int n;
	scanf("%d", &n);
	unordered_map<string, int> cnt;
	unordered_map<string, double> sum;
	for (int i = 0; i < n; i++) {
		string id, uni;
		cin >> id;
		double score;
		scanf("%lf", &score);
		cin >> uni;
		for (int j = 0; j < uni.length(); j++) uni[j] = tolower(uni[j]);
		if (id[0] == 'B') score /= 1.5;
		else if (id[0] == 'T') score *= 1.5;
		sum[uni] += score;
		cnt[uni]++;
	}
	vector<node> v;
	for (auto it : cnt)
		v.push_back(node{it.first, (int)sum[it.first], cnt[it.first]});
	sort(v.begin(), v.end(), cmp);
	int r = 0, pres = -1;
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		if (pres != v[i].tws) r = i + 1;
		pres = v[i].tws;
		printf("%d %s %d %d\n", r, v[i].uni.c_str(), v[i].tws, v[i].ns);
	}
	return 0;
}
