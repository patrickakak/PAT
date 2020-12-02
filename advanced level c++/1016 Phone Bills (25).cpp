#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string nm;
	int flag, MM, tm, dd, hh, mm;
};
bool cmp(node &a, node &b) {
	return a.nm != b.nm ? a.nm < b.nm : a.tm < b.tm;
}
int rate[25], n;
double bill(node &call) {
	double total = rate[call.hh]*call.mm + rate[24]*60*call.dd;
	for (int i = 0; i < call.hh; i++) total += rate[i]*60;
	return total/100.0;
}
int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	scanf("%d", &n);
	vector<node> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].nm;
		scanf("%d:%d:%d:%d", &data[i].MM, &data[i].dd, &data[i].hh, &data[i].mm);
		string tmp;
		cin >> tmp;
		data[i].flag = (tmp == "on-line") ? 1 : 0;
		data[i].tm = data[i].dd*24*60 + data[i].hh*60 + data[i].mm;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<node>> custom;
	for (int i = 1; i < n; i++)
		if (data[i].nm==data[i-1].nm && data[i-1].flag==1 && data[i].flag==0) {
			custom[data[i-1].nm].push_back(data[i-1]);
			custom[data[i].nm].push_back(data[i]);
		}
	for (auto it : custom) {
		vector<node> t = it.second;
		printf("%s %02d\n", it.first.c_str(), t[0].MM);
		double total = 0.0;
		for (int i = 1; i < t.size(); i += 2) {
			double cost = bill(t[i]) - bill(t[i-1]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", t[i-1].dd, t[i-1].hh, t[i-1].mm, t[i].dd, t[i].hh, t[i].mm, t[i].tm-t[i-1].tm, cost);
			total += cost;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
