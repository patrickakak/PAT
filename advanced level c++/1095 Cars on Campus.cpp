/**
 * Sample input:
 * 16 7
 * JH007BD 18:00:01 in
 * ZD00001 11:30:08 out
 * DB8888A 13:00:00 out
 * ZA3Q625 23:59:50 out
 * ZA133CH 10:23:00 in
 * ZD00001 04:09:59 in
 * JH007BD 05:09:59 in
 * ZA3Q625 11:42:01 out
 * JH007BD 05:10:33 in
 * ZA3Q625 06:30:50 in
 * JH007BD 12:23:42 out
 * ZA3Q625 23:55:00 in
 * JH007BD 12:24:23 out
 * ZA133CH 17:11:22 out
 * JH007BD 18:07:01 out
 * DB8888A 06:30:50 in
 * 05:10:00
 * 06:30:50
 * 11:00:00
 * 12:23:42
 * 14:00:00
 * 18:00:00
 * 23:59:00
 * --------------------
 * Sample output:
 * 1
 * 4
 * 5
 * 2
 * 1
 * 0
 * 1
 * JH007BD ZD00001 07:20:09
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>
// #include <windows.h>
using namespace std;

#define maxn 10010
struct Car {
	char plate[10];
	int sec;
	bool status;	// true-in, false-out
} all[maxn], valid[maxn];

int num = 0;		// valid num
map<string, int> parkTime;

int time2Sec(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

bool cmp(Car a, Car b)
{
	int x = strcmp(a.plate, b.plate);
	if (x != 0) return x < 0;
	else return a.sec < b.sec;
}

bool cmpTime(Car a, Car b)
{
	return a.sec < b.sec;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n, k, hh, mm, ss;
	char line[10];

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d %s", all[i].plate, &hh, &mm, &ss, line);
		all[i].sec = time2Sec(hh, mm, ss);
		if (!strcmp(line, "in")) all[i].status = true;
		else all[i].status = false;
	}
	sort(all, all + n, cmp);
	// get valid records
	int maxTime = -1;
	for (int i = 0; i < n-1; )
		if (!strcmp(all[i].plate, all[i+1].plate) 
				&& all[i].status == true && all[i+1].status == false) {
			valid[num++] = all[i];
			valid[num++] = all[i+1];
			// record maxtime
			int inTime = all[i+1].sec - all[i].sec;
			if (parkTime.count(all[i].plate) == 0)
				parkTime[all[i].plate] = 0;
			parkTime[all[i].plate] += inTime;
			maxTime=max(maxTime, parkTime[all[i].plate]);
			i += 2;
		} else
			i++;
	// ouput answer of query
	sort(valid, valid + num, cmpTime);
	int now = 0, numCar = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = time2Sec(hh, mm, ss);
		while (now < num && valid[now].sec <= time) {
			if (valid[now].status == true) numCar++;
			else numCar--;
			now++;
		}
		printf("%d\n", numCar);
	}
	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); it++)
		if (it->second == maxTime)
			printf("%s ", it->first.c_str());
	printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);

	return 0;
}


