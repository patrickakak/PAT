/**
 * Sample input1:
 * -123456789
 * Sample output1:
 * Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
 * ----------------
 * Sample input2:
 * 100800
 * Sample output2:
 * yi Shi Wan ling ba Bai
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char num[10][5] = {"ling", "yi", "er", "san", "si", 
                   "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	// freopen("test.txt", "r", stdin);
	char str[15];
	int len, left, right;
	bool flag, isPrint;

	gets(str);
	len = strlen(str);
	left = 0;
	right = len - 1;
	if (str[0] == '-') {
		printf("Fu");
		left++;
	}
	while (left + 4 <= right)	// left and right points to the same section
		right -= 4;             // which is four-digit long
	while (left < len) {
		flag = false;	// To indicate there is no accumulated 0
		isPrint = false;	// false represents no printing in this section
		while (left <= right) {
			if (left > 0 && str[left] == '0')
				flag = true;
			else {
				if (flag == true) {
					printf(" ling");
					flag = false;
				}
				if (left > 0)
					printf(" ");
				printf("%s", num[str[left]-'0']);
				isPrint = true;
				if (left != right)
					printf(" %s", wei[right-left-1]);
			}
			left++;
		}
		if (isPrint == true && right != len-1)
			printf(" %s", wei[(len-1-right)/4+2]);
		right += 4;
	}
	return 0;
}

