/**
 * Sample input:
 * 7 4 20
 * 20 25 25 30
 * 00002 2 12
 * 00007 4 17
 * 00005 1 19
 * 00007 2 25
 * 00005 1 20
 * 00002 2 2
 * 00005 1 15
 * 00001 1 18
 * 00004 3 25
 * 00002 2 25
 * 00005 3 22
 * 00006 4 -1
 * 00001 2 18
 * 00002 1 20
 * 00004 1 15
 * 00002 4 18
 * 00001 3 4
 * 00001 4 2
 * 00005 2 -1
 * 00004 2 0
 * ---------------------
 * Sample output:
 * 1 00002 63 20 25 - 18
 * 2 00005 42 20 0 22 -
 * 2 00007 42 - 25 - 17
 * 2 00001 42 18 18 4 2
 * 5 00004 40 15 0 25 -
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
//#include <windows.h>
using namespace std;

#define maxn 10010
struct User {
	int id;
	int score[10];
	int total;
	int solve;	// perfectly solved problem
	bool pass;	// have been submitted
} user[maxn];

bool cmp(User a, User b)
{
	if (a.pass != b.pass) return a.pass;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.solve != b.solve) return a.solve > b.solve;
	else return a.id < b.id;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	int N, K, M;	// #user, problem, submission
	int p[10];		// full mark

	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= K; i++)
		scanf("%d", &p[i]);

	int uid, pid, score;
	// user_id problem_id partial_score_obtained
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			user[i].score[j] = -1;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &uid, &pid, &score);
		user[uid].id = uid;
		if (score > user[uid].score[pid]) {
			if (user[uid].score[pid] == -1)
				user[uid].total += score;
			else
				user[uid].total += score - user[uid].score[pid];
			user[uid].score[pid] = score;
			if (score == p[pid])
				user[uid].solve++;
		}
		if (score == -1 && user[uid].score[pid]==-1)
			user[uid].score[pid] = 0;
		if (score > -1)
			user[uid].pass = true;
	}
	sort(user+1, user+1+N, cmp);
	int r = 1;
	for (int i = 1; i <= N; i++) {
		if (user[i].pass == false)
			continue;
		if (i > 1 && user[i].total != user[i-1].total)
			r = i;
		printf("%d %05d %d", r, user[i].id, user[i].total);
		for (int j = 1; j <= K; j++)
			if (user[i].score[j] == -1)
				printf(" -");
			else
				printf(" %d", user[i].score[j]);
		printf("\n");
	}

	return 0;
}


