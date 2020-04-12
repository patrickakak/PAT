#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct node {
	string id;
	int tm, flg;
};
bool cmp1(node &a, node &b) {
	return a.id != b.id ? a.id < b.id : a.tm < b.tm;
}
bool cmp2(node &a, node &b) {
	return a.tm < b.tm;
}
int main() {
	int n, k, maxtm = -1, idx = 0, h, m, s, t;
	cin >> n >> k;
	vector<node> v, car;
	for (int i = 0; i < n; i++) {
		string id, stat;
		cin >> id;
		scanf("%d:%d:%d", &h, &m, &s);
		cin >> stat;
		t = h*3600 + m*60 + s;
		if (stat == "in") v.push_back({id, t, 1});
		else v.push_back({id, t, -1});
	}
	sort(v.begin(), v.end(), cmp1);
	map<string, int> mp;
	for (int i = 0; i < n; i++)
		if (i+1 < n && v[i].id == v[i+1].id && v[i].flg == 1 && v[i+1].flg == -1) {
			car.push_back(v[i]);
			car.push_back(v[i+1]);
			mp[v[i].id] += v[i+1].tm - v[i].tm;
			if (maxtm < mp[v[i].id]) maxtm = mp[v[i].id];
		}
	sort(car.begin(), car.end(), cmp2);
	vector<int> cnt(car.size());
	for (int i = 0; i < car.size(); i++)
		if (i == 0) cnt[i] += car[i].flg;
		else cnt[i] = cnt[i - 1] + car[i].flg;
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		t = h*3600 + m*60 + s;
		int j = idx;
		for (; j < car.size(); j++)
			if (car[j].tm > t) break;
		idx = j;
		if (j-1 < 0) printf("0\n");
		else printf("%d\n", cnt[j-1]);
	}
	for (auto it : mp)
		if (it.second == maxtm) printf("%s ", it.first.c_str());
	printf("%02d:%02d:%02d", maxtm/3600, maxtm%3600/60, maxtm%60);
	return 0;
}
