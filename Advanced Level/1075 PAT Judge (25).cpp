#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10010
struct User {
	int id, total, solve, score[10];
	bool pass;
} user[maxn];
bool cmp(User a, User b) {
	if (a.pass != b.pass) return a.pass;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.solve != b.solve) return a.solve > b.solve;
	else return a.id < b.id;
}
int main() {
	int N, K, M;
	int p[10];
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= K; i++)
		scanf("%d", &p[i]);
	int uid, pid, score;
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
