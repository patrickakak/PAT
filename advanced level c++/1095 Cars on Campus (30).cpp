#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
struct node {
	char id[10];
	int time, flag;
};
bool cmp1(node a, node b) { return strcmp(a.id, b.id) != 0 ? strcmp(a.id, b.id) < 0 : a.time < b.time; }
bool cmp2(node a, node b) { return a.time < b.time; }
int main() {
	int n, k, maxtime = -1, tmpindex = 0;
	scanf("%d%d\n", &n, &k);
	vector<node> rec(n), car;
	for (int i = 0; i < n; i++) {
		char tmp[5];
		int h, m, s;
		scanf("%s %d:%d:%d %s\n", rec[i].id, &h, &m, &s, tmp);
		int tmptime = h * 3600 + m * 60 + s;
		rec[i].time = tmptime;
		rec[i].flag = strcmp(tmp, "in") == 0 ? 1 : -1;
	}
	sort(rec.begin(), rec.end(), cmp1);
	map<string, int> mp;
	for (int i = 0; i < n - 1; i++)
		if (strcmp(rec[i].id, rec[i+1].id) == 0 && rec[i].flag == 1 && rec[i+1].flag == -1) {
			car.push_back(rec[i]);
			car.push_back(rec[i+1]);
			mp[rec[i].id] += (rec[i+1].time - rec[i].time);
			if (maxtime < mp[rec[i].id]) maxtime = mp[rec[i].id];
		}
	sort(car.begin(), car.end(), cmp2);
	vector<int> cnt(n);
	for (int i = 0; i < car.size(); i++)
		if (i == 0) cnt[i] += car[i].flag;
		else cnt[i] = cnt[i - 1] + car[i].flag;
	for (int i = 0; i < k; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int j, tmptime = h * 3600 + m * 60 + s;
		for (j = tmpindex; j < car.size(); j++)
			if (car[j].time > tmptime) {
				printf("%d\n", cnt[j - 1]);
				break;
			} else if (j == car.size() - 1)
				printf("%d\n", cnt[j]);
		tmpindex = j;
	}
	for (auto it = mp.begin(); it != mp.end(); it++)
		if (it->second == maxtime) printf("%s ", it->first.c_str());
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
	return 0;
}
