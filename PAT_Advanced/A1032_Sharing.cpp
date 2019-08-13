/**
 * Sample input1:
 * 11111 22222 9
 * 67890 i 00002
 * 00010 a 12345
 * 00003 g -1
 * 12345 D 67890
 * 00002 n 00003
 * 22222 B 23456
 * 11111 L 00001
 * 23456 e 67890
 * 00001 o 00010
 * Sample output1:
 * 67890
 * ---------------
 * Sample input2:
 * 00001 00002 4
 * 00001 a 10001
 * 10001 s -1
 * 00002 a 10002
 * 10002 t -1
 * Sample output2:
 * -1
 */
#include <cstdio>
#include <cstring>

const int maxn = 100010;
struct NODE {
	char data;
	int next;
	bool flag;
} node[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int s1, s2, n, p;
	int address, next;
	char data;
	
	for (int i = 0; i < maxn; i++)
		node[i].flag = false;
	
	scanf("%d%d%d", &s1, &s2, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	
	for (p = s1; p != -1; p = node[p].next)
		node[p].flag = true;

	for (p = s2; p != -1; p = node[p].next)
		if (node[p].flag == true)
			break;
	if (p != -1)
		printf("%05d\n", p);
	else
		printf("-1\n");

	return 0;
}


