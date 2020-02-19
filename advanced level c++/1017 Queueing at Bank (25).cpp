#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int come, time;
} tmpcustomer;
bool cmp(node a, node b) { return a.come < b.come; }
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<node> custom;
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, time;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
		int cometime = hh * 3600 + mm * 60 + ss;
		if (cometime > 61200) continue;
		tmpcustomer = {cometime, time * 60};
		custom.push_back(tmpcustomer);
	}
	sort(custom.begin(), custom.end(), cmp);
	vector<int> window(k, 28800);
	double result = 0.0;
	for (int i = 0; i < custom.size(); i++) {
		int tmpindex = 0, minfinish = window[0];
		for (int j = 1; j < k; j++)
			if (minfinish > window[j]) {
				minfinish = window[j];
				tmpindex = j;
			}
		if (window[tmpindex] <= custom[i].come)
			window[tmpindex] = custom[i].come + custom[i].time;
		else {
			result += (window[tmpindex] - custom[i].come);
			window[tmpindex] += custom[i].time;
		}
	}
	if (custom.size() == 0) printf("0.0");
	else printf("%.1f", result / 60.0 / custom.size());
	return 0;
}
