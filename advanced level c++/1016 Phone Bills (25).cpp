#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string name;
	int status, month, time, day, hr, mm;
};
bool cmp(node &a, node &b) {
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate) {
	double total = rate[call.hr]*call.mm + rate[24]*60*call.day;
	for (int i = 0; i < call.hr; i++) total += rate[i]*60;
	return total/100.0;
}
int main() {
	int rate[25] = {0}, n;
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	scanf("%d", &n);
	vector<node> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hr, &data[i].mm);
		string tmp;
		cin >> tmp;
		data[i].status = (tmp == "on-line") ? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hr * 60 + data[i].mm;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<node>> custom;
	for (int i = 1; i < n; i++)
		if (data[i].name == data[i-1].name && data[i-1].status == 1 && data[i].status == 0) {
			custom[data[i-1].name].push_back(data[i-1]);
			custom[data[i].name].push_back(data[i]);
		}
	for (auto it : custom) {
		vector<node> tmp = it.second;
		cout << it.first;
		printf(" %02d\n", tmp[0].month);
		double total = 0.0;
		for (int i = 1; i < tmp.size(); i += 2) {
			double t = billFromZero(tmp[i], rate) - billFromZero(tmp[i-1], rate);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", tmp[i-1].day, tmp[i-1].hr, tmp[i-1].mm, tmp[i].day, tmp[i].hr, tmp[i].mm, tmp[i].time - tmp[i-1].time, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
