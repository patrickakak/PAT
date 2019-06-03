/**
 * Sample Input1:
 * 5
 * -2
 * +3
 * -4
 * +5
 * +4
 * Sample Output1:
 * 1 4
 * --------------
 * Sample Input2:
 * 6
 * +6
 * +3
 * +1
 * -5
 * -2
 * +4
 * Sample Output2:
 * 1 5
 * --------------
 * Sample Input3:
 * 5
 * -2
 * -3
 * -4
 * -5
 * -1
 * Sample Output3:
 * No Solution
 */
#include <stdio.h>
#include <stdbool.h>

#define MAXN 100
bool werewolf[MAXN+1], liar[MAXN+1];
int statements[MAXN+1];
bool set[MAXN+1];

void InitArr(bool werewolf[], bool liar[], int N);

int main()
{
	int N, i, j, k;
	int Possible;
	int err1, err2;
	int GoodLiarCnt;

	// 读取人数和各自陈述
	scanf("%d", &N);
	for (k = 1; k <= N; ++k) {
		scanf("%d", &statements[k]);
	}
	InitArr(werewolf, liar, N);
	// (i, j) 表示两个狼人，剩余N-2都是好人
	for (i = 1; i <= N; i++) {
		for (j=i+1; j <= N; j++) {
			// 狼人数组初始化都是好人
			Possible = 0;
			err1 = 0; err2 = 0;
			InitArr(werewolf, liar, N);
			werewolf[i] = true; werewolf[j] = true;
			// 狼人中一人撒谎，一人讲真话，说谎人数组初始化为0
			// 当i撒谎，j说真话
			liar[i] = true;
			if (statements[i] < 0) {
				if (werewolf[-statements[i]] == true)
					err1 = 1;
			} else {
				if (werewolf[statements[i]] == false)
					err1 = 1;
			}
			if (statements[j] < 0) {
				if (werewolf[-statements[j]] == false)
					err1 = 1;
			} else {
				if (werewolf[statements[j]] == true)
					err1 = 1;
			}
			// 如果出错
			if (err1) ;
			else {
				// 验证好人们的陈述（其中有一人是说谎者）
				GoodLiarCnt = 0;
				for (k = 1; k <= N; k++) {
					if (k == i || k == j) continue;
					if (statements[k] < 0) {
						if (werewolf[-statements[k]] == false)
							GoodLiarCnt++;
					} else {
						if (werewolf[statements[k]] == true)
							GoodLiarCnt++;
					}
				}
				// 恰好只有个好人是说谎者，说明这个组合是正确的
				if (GoodLiarCnt == 1) {
					Possible = 1;
					goto End;
				} else {
					Possible = 0;
				}
			}
			// 当i说真话，j撒谎
			liar[i] = false; liar[j] = true;
			if (statements[j] < 0) {
				if (werewolf[-statements[j]] == true)
					err2 = 1;
			} else {
				if (werewolf[statements[j]] == false)
					err2 = 1;
			}
			if (statements[i] < 0) {
				if (werewolf[-statements[i]] == false)
					err2 = 1;
			} else {
				if (werewolf[statements[i]] == true)
					err2 = 1; // 正确
			}
			if (err2) ;
			else {
				// 验证好人们的陈述（其中有一人是说谎者）
				GoodLiarCnt = 0;
				for (k = 1; k <= N; k++) {
					if (k == i || k == j) continue;
					if (statements[k] < 0) {
						if (werewolf[-statements[k]] == false)
							GoodLiarCnt++;
					} else {
						if (werewolf[statements[k]] == true)
							GoodLiarCnt++;
					}
				}
				// 恰好只有个好人是说谎者，说明这个组合是正确的
				if (GoodLiarCnt == 1) {
					Possible = 1;
					goto End;
				}
			}
		}
		//if (Possible) break;
	}
End:
	if (!Possible) {
		printf("No Solution\n");
	} else {
		// Print werewolves' number
		printf("%d %d\n", i, j);
	}
	return 0;
}

void InitArr(bool werewolf[], bool liar[], int N)
{
	int i;
	for (i = 1; i <= N; i++) {
		werewolf[i] = false;
		liar[i] = false;
	}
}

