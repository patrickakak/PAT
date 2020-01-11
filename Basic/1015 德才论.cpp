#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Stu {
	int id, sum, de, cai, flag;
} stu[maxn];
int num = 0;
bool cmp(Stu a, Stu b) {
	if (a.flag != b.flag) return a.flag < b.flag;
	else if (a.sum != b.sum) return a.sum > b.sum;
	else if (a.de != b.de) return a.de > b.de;
	else return a.id < b.id;
}
int main() {
	int n, l, h;
	cin >> n >> l >> h;
	Stu t;
	for (int i = 0; i < n; i++) {
		cin >> t.id >> t.de >> t.cai;
		if (t.de >= l && t.cai >= l) {
			t.sum = t.de + t.cai;
			if (t.de >= h && t.cai >= h) t.flag = 1;
			else if (t.de >= h && t.cai < h) t.flag = 2;
			else if (t.de >= t.cai) t.flag = 3;
			else t.flag = 4;
			stu[num++] = t;
		}
	}
	sort(stu, stu + num, cmp);
	cout << num << endl;
	for (int i = 0; i < num; i++)
		printf("%08d %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	return 0;
}
