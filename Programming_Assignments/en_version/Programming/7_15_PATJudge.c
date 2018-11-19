/**
 * Sample Input:
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
 * Sample Output:
 * 1 00002 63 20 25 - 18
 * 2 00005 42 20 0 22 -
 * 2 00007 42 - 25 - 17
 * 2 00001 42 18 18 4 2
 * 5 00004 40 15 0 25 -
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXK 5
#define MAXN 10000
#define MAXM 100000

struct UNode {
	int uid;	/* User id */
	int total;	/* Total score */
	int solve;	/* Number of problem(s) perfectly solved */
	bool visited;	/* To indicate whether to print this node */
	int scores[MAXK];	/* Partial score obtained for the i-th problem */
};
typedef struct UNode Users[MAXN];

void RdKthFullMark(int s[], int K);
void Output(Users users, int N, int K);
void RdSubmissions(Users users, int s[], int M);
void InitUsers(Users users, int N, int K);
int compar(const void *a, const void *b);

int main()
{
	int N, K, M, s[MAXK];
	Users users;

	scanf("%d %d %d", &N, &K, &M);

	RdKthFullMark(s, K);

	InitUsers(users, N, K);

	RdSubmissions(users, s, M);

	qsort(users, N, sizeof(struct UNode), compar);

	Output(users, N, K);

	return 0;
}

void RdKthFullMark(int s[], int K)
{
	int i;

	for (i = 0; i < K; i++)
		scanf("%d", &s[i]);
}

void RdSubmissions(Users users, int s[], int M)
{
	int uid, pid, score, i;

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &uid, &pid, &score);
		uid--; pid--;	/* Map user_id with index 1~N into 0~N-1 */

		if (users[uid].scores[pid] == -1)
			users[uid].scores[pid] = 0;
		users[uid].uid = uid;

		switch (score) {
		case -1:
			/* If it's not the first time to meet users[uid] */
			if (users[uid].total != 0)
				users[uid].visited = true;
			break;
		default:
			users[uid].visited = true;
			if (score > users[uid].scores[pid]) {	/* Update score */
				users[uid].total += score-users[uid].scores[pid];
				users[uid].scores[pid] = score;
				if (score == s[pid])
					users[uid].solve++;
			}
		}
	}
}

void Output(Users users, int N, int K)
{
	int i, j, rank, cnt;

	rank = 1; cnt = 1;
	for (i = 0; i < N; i++) {
		if (!users[i].visited)
			continue;
		if (i!=0 && users[i].total!=users[i-1].total)
			rank = cnt;
		printf("%d %05d %d", rank, users[i].uid+1, users[i].total);
		for (j = 0; j < K; j++)
			if (users[i].scores[j] == -1)
				printf(" -");
			else printf(" %d", users[i].scores[j]);
		putchar('\n');
		cnt++;
	}
}

void InitUsers(Users users, int N, int K)
{
	int i, j;

	for (i = 0; i < N; i++) {
		users[i].uid = MAXN;	/* Some students may get 0 */
		users[i].total = 0;
		users[i].solve = 0;
		users[i].visited = false;
		for (j = 0; j < K; j++)
			users[i].scores[j] = -1;
	}
}

int compar(const void *a, const void *b)
{
	struct UNode u1 = *(struct UNode *)a;
	struct UNode u2 = *(struct UNode *)b;

	if (u1.total > u2.total)
		return -1;
	else if (u1.total < u2.total)
		return 1;
	else {
		if (u1.solve > u2.solve)
			return -1;
		else if (u1.solve < u2.solve)
			return 1;
		else {
			if (u1.uid < u2.uid)
				return -1;
			else return 1;
		}
	}
}

