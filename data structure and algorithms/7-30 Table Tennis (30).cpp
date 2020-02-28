#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct person {
	int arrive, start, time;
	bool vip;
} tmpperson;
struct tblnode {
	int end = 8 * 3600, num;
	bool vip;
};
bool cmp1(person a, person b) { return a.arrive < b.arrive; }
bool cmp2(person a, person b) { return a.start < b.start; }
vector<person> player;
vector<tblnode> tbl;
void alloctbl(int personid, int tblid) {
	if (player[personid].arrive <= tbl[tblid].end) player[personid].start = tbl[tblid].end;
	else player[personid].start = player[personid].arrive;
	tbl[tblid].end = player[personid].start + player[personid].time;
	tbl[tblid].num++;
}
int findnextvip(int vipid) {
	vipid++;
	while (vipid < player.size() && player[vipid].vip == false) vipid++;
	return vipid;
}
int main() {
	int n, k, m, viptbl;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int h, m, s, tmptime, flag;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &tmptime, &flag);
		tmpperson.arrive = h * 3600 + m * 60 + s;
		tmpperson.start = 21 * 3600;
		if (tmpperson.arrive >= 21 * 3600) continue;
		tmpperson.time = tmptime <= 120 ? tmptime * 60 : 7200;
		tmpperson.vip = ((flag == 1) ? true : false);
		player.push_back(tmpperson);
	}
	scanf("%d%d", &k, &m);
	tbl.resize(k + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d", &viptbl);
		tbl[viptbl].vip = true;
	}
	sort(player.begin(), player.end(), cmp1);
	int i = 0, vipid = -1;
	vipid = findnextvip(vipid);
	while (i < player.size()) {
		int index = -1, minendtime = 999999999;
		for (int j = 1; j <= k; j++)
			if (tbl[j].end < minendtime) {
				minendtime = tbl[j].end;
				index = j;
			}
		if (tbl[index].end >= 21 * 3600) break;
		if (player[i].vip == true && i < vipid) {
			i++;
			continue;
		}
		if (tbl[index].vip == true) {
			if (player[i].vip == true) {
				alloctbl(i, index);
				if (vipid == i) vipid = findnextvip(vipid);
				i++;
			} else {
				if (vipid < player.size() && player[vipid].arrive <= tbl[index].end) {
					alloctbl(vipid, index);
					vipid = findnextvip(vipid);
				} else {
					alloctbl(i, index);
					i++;
				}
			}
		} else {
			if (player[i].vip == false) {
				alloctbl(i, index);
				i++;
			} else {
				int vipindex = -1, minvipendtime = 999999999;
				for (int j = 1; j <= k; j++)
					if (tbl[j].vip == true && tbl[j].end < minvipendtime) {
						minvipendtime = tbl[j].end;
						vipindex = j;
					}
				if (vipindex != -1 && player[i].arrive >= tbl[vipindex].end) {
					alloctbl(i, vipindex);
					if (vipid == i) vipid = findnextvip(vipid);
					i++;
				} else {
					alloctbl(i, index);
					if(vipid == i) vipid = findnextvip(vipid);
					i++;
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmp2);
	for (i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
		printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
		printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
		printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
	}
	for (int i = 1; i <= k; i++) {
		if (i != 1) printf(" ");
		printf("%d", tbl[i].num);
	}
	return 0;
}
